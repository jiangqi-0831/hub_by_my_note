# C++ STL 标准模板库详解

## 序言

本文 STL 整理内容基于多份优质视频和纸质等资料的整理概括，所表达的名称和分类或有少许出入，重在**理解内容和思想**。代码举例部分只展示核心代码，并不完整，实际应用实现功能时请务必留意好。推荐浏览网站：[cppreference.com](https://en.cppreference.com/w/)。

STL 的使用极大地扩展了 C++ 的功能，使得我们能够编写出更加高效简洁的代码。后续随着本人学习加深，STL 知识整理会不断更新完善滴，以接轨更新的 C++ 标准，适应新的技术趋势。

推荐先理解熟悉好 **C++ 数据结构**和算法、**面向对象**与模板知识再开始本文学习~

---

## 一、STL（Standard Template Library）

### 1、STL 认识

C++ STL 是一套功能强大的标准库**通用模板类和函数的集合**，提供了一套基于模板的通用数据结构和算法，如向量、链表、队列、栈，旨在实现高效的泛型编程。

STL 的重要特点包括：

- **数据结构与算法的分离**：通过迭代器将算法与容器解耦。
- **非面向对象设计**：不依赖于继承和多态，而是通过模板和迭代器实现通用性。
- **高性能**：模板在编译时实例化，避免了运行时多态的开销，通用设计减少重复代码。
- **泛型编程**：基于模板实现，支持任意符合要求的类型（如支持拷贝、比较操作的类型）。

### 2、STL API 认识

API（Application Program Interface）即**应用程序编程接口**，指的是一系列预先定义的函数、类、方法、数据结构等，它们提供了一种方式，规定了如何使用特定软件库、操作系统或服务的功能，使得不同软件组件之间可以相互通信和交互，而**无需关心其内部实现**。

STL 的 API 是一组预定义在标准库中的模板类、函数和接口规范，通常在 `<vector>`、`<algorithm>` 等**头文件中声明**，且**实现细节对用户隐藏**，这正是 API 的特性——提供一个使用界面，而封装了内部实现。

STL 提供了 API 级别的接口，允许我们在声明相应头文件后，直接调用预定义的数据结构和算法，以实现高效且可维护的代码编写。

```cpp
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5};
    std::sort(vec.begin(), vec.end());  // 调用算法 API
    return 0;
}
```

### 3、STL 与命名空间

C++ STL 的**所有算法和容器都定义在 std 命名空间**中。因此，当我们在代码中使用 STL 容器或算法时，通常都需要在它们的名称前加上 `std::` 前缀，以指定它们属于标准命名空间，防止与用户代码或第三方库的同名符号冲突。

- 显式限定：`std::vector<int>`
- using 声明：`using std::vector;`
- 全局引入：`using namespace std;`

```cpp
#include <vector>
#include <algorithm>

// 使用 vector 和 deque 容器和 sort 算法的书写
std::vector<int> V;
std::deque<int> dq;
std::sort(V.begin(), V.end());
```

---

## 二、STL 主要组件

C++ STL 大体分为容器 Container、算法 Algorithm、迭代器 Iterator、仿函数 Functor、适配器 Adaptor，核心即前三个部件，下面分别简单介绍：

### 1、容器 Containers

容器是用来存储数据的序列即各种**数据结构**，如 list、vector、deque 和 map 等，以模板类的方式提供，支持任意数据类型，实现了**不同的存储和访问模式**。分为序列式容器 Sequence Containers 和关联式容器 Associated Containers。

#### 序列式容器

序列式容器是一类**按照元素插入顺序存储**的容器，它们维护了元素的插入顺序，但**不保证元素的排序**：

- **vector**：支持**尾部**高效插入删除的**动态单端数组**，内存空间**连续**，支持快速随机访问。
- **deque**：支持**首尾**高效插入删除的**双端队列**，内存空间不连续，支持**快速随机访问**。
- **list**：支持**任意位置**高效插入删除的**双向循环链表**，内存空间不连续，不支持随机访问。
- **forward_list**：支持**头部**高效插入删除的**单向链表**，内存空间不连续，只支持单向访问。
- **array**：C++11 新增的容器，比 vector 效率高，其**大小在编译时确定不能动态调整**，内存空间连续，支持快速随机访问。适合存储固定大小的数据集合，如配置参数或不需要动态变化的数据。

#### 关联式容器

关联式容器通过键值（key-value pairs）来存储元素，能够提供对数据的快速访问，主要分 set 集合和 map 映射这两大类，均是以**红黑树 RB-Tree** 为底层架构在插入和删除元素时会自动调整其内部结构，默认**从小到大排序**。容器类自动申请和释放内存，**无需 new/delete 操作**。

- **set**：有序键的集合，其中的元素是唯一的，类型是键值类型，即只有键没有值；**multiset** 则允许重复元素，可以包含多个相同的关键字，适合需要存储重复元素的集合。
- **map**：有序键值对的映射，每个键是唯一的，元素类型是键值对类型；**multimap** 则允许键重复，可以允许一个键对应多个值，适合需要存储重复键的场景。

关联式容器的性能优势在于它们能够提供**对数时间复杂度的搜索、插入和删除**操作。这使得 set 和 map 在处理大量数据时仍然能够保持较高的效率，且提供了对元素的有序遍历能力。

### 2、算法 Algorithms

算法是用来操作容器中的数据的**模板函数**。例如用 `sort()` 来对一个 vector 中的数据进行排序，用 `find()` 来搜索一个 list 中的对象，这些函数不依赖于特定的容器类型，而是**通过迭代器来访问容器中的元素**（不同算法对迭代器的类别有要求），使得算法可以高度通用，能够应用于多种不同的容器类型。

### 3、迭代器 Iterators

迭代器提供了对容器中对象的统一**访问方法**，连接 containers 和 algorithms，作用**类似指针但比指针更加灵活安全**，因为 STL 的每一个容器类模板中都定义了一组对应的迭代器类，被设计为只能进行有限的、安全的操作，算法函数可以访问容器中指定位置的元素，而**无需关心元素的具体类型**。

### 4、三者的协作关系

- **容器存储数据**：选择合适的容器存储数据。
- **迭代器定义访问方式**：通过迭代器指定算法操作的范围（通常通过 begin/end 一对迭代器）。
- **算法处理数据**：调用算法对容器中的数据进行处理，无需关心容器类型。

---

## 三、size_t 和 size_type 认识

### 1、size_t

size_t 是在 C/C++ 标准库中定义的一个**无符号整数类型**，它用于全局定义表示大小或者计数。这个类型是由 C 语言的 `<stddef.h>` 或 C++ 的 `<cstddef>` 头文件中定义的，并且其大小足以存储任何对象的大小，即 `sizeof` 操作符返回的值的类型。

```cpp
int arr[10];
for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
    // 使用 arr[i]
}

size_t size = sizeof(arr); // sizeof 操作符返回的值的类型是 size_t
```

在 32 位系统上，size_t 通常定义为 `unsigned int`，而在 64 位系统上，它可能定义为 `unsigned long` 或 `unsigned long long`。size_t 广泛用于**数组索引和循环计数以及标准库中的大小表示**等。

### 2、size_type

size_type 是 STL 中定义的一个**无符号整数类型**，它用于表示容器（如 vector、string 等）的大小或容量。size_type 是容器内部定义的**类型别名**，通常定义为 size_t，会根据容器的实现自动调整为合适的类型。

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
std::vector<int>::size_type size = vec.size();
for (std::vector<int>::size_type i = 0; i < vec.size(); ++i) {
    // 使用 vec[i]
}
```

在编写使用 STL 容器的代码时，**推荐使用 size_type** 而不是 size_t，以确保类型安全和最佳的代码移植性。

### 3、size_t、size_type 的使用

为了使自己的程序有很好的移植性，我们可以尽量使用 size_t 和 size_type，而不是 int、unsigned。

在用下标访问元素时，C++ STL 容器如 vector 使用 `std::vector::size_type` 作为下标类型和元素访问，而 C 风格的传统数组下标的正确类型则是 size_t，如下所示：

```cpp
std::vector<int> vec = {10, 20, 30, 40, 50};
std::vector<int>::size_type index = 2; // 使用 vector 的 size_type，下标从 0 开始

int arr[5] = {10, 20, 30, 40, 50};
size_t index = 2; // 使用 size_t，下标从 0 开始

// 访问和打印 vector 元素
std::cout << "Element at index " << index << " is " << vec[index] << std::endl;

if (index < vec.size()) { // 确保不会访问越界
    std::cout << "Accessing element at index " << index << " is safe." << std::endl;
} else {
    std::cout << "Index out of bounds." << std::endl;
}
```

---

## 四、容器

### 1、vector 详解

**数组**：在声明时就确定了大小，一旦创建就无法改变，因此不能进行越界检查否则可能导致未定义行为，不提供类型安全检查；需要程序员手动分配和释放内存；没有成员函数，不能直接进行插入、删除等操作。

**vector**：可以在运行时根据需要动态增删；自动处理内存分配和释放，无需手动 new/delete；只能存储特定类型的元素，提供类型安全；提供了一系列成员函数方便管理元素；提供了 at 成员函数进行越界检查防止未定义行为；提供迭代器来遍历元素更加安全和功能丰富。

数组直接操作内存，没有额外的封装和检查，适用于**性能敏感且大小在编译时已知的场景**，如嵌入在结构体中或作为固定大小的缓冲区；vector 适用于需要**灵活大小、自动内存管理和提供标准库成员函数支持**的场景，如动态数据集合、算法输入等。

#### （1）头文件

```cpp
#include <vector>
```

#### （2）一维初始化

```cpp
std::vector<int> a;                  // 定义了一个名为 a 的一维数组，数组存储 int 整数类型的数据
std::vector<double> b;               // 定义了一个名为 b 的一维数组，数组存储 double 双精度类型的数据
std::vector<node> c;                 // 定义了一个名为 c 的一维数组，数组存储 node 结构体类型的数据

std::vector<int> v(n);               // 定义了一个长度为 n 的数组 v，初始值默认为 0，下标范围为[0，n-1]
std::vector<int> v(n,1);             // 共 n 个元素，所有元素初始值均为 1
// 注意这样指定数组长度后的 vector 就相当于正常的数组了

std::vector<int> a = {1,2,3,4,5,6};  // 数组 a 有六个元素，数组长度为 6
std::vector<int> a{1,2,3,4,5,6};     // C++11 后序列式容器都更广泛使用，等价初始化列表
std::vector<int> b(a);               // 拷贝构造，两个数组类型必须相同，将 a 内容拷贝给 b
std::vector<int> c = a;              // 也是拷贝初始化方式，c 和 a 完全一样
```

#### （3）常用成员函数

```cpp
// 假设 V 为数组名，其有 N 个元素，代码解释后包含算法时间复杂度

V.at(size_t pos)        // 返回第 pos 个元素，并进行范围检查  O(1)
V.front()               // 返回第一个数据  O(1)
V.back()                // 返回数组中的最后一个数据  O(1)
V.data()                // 返回指向 vector 存储的元素的指针  O(1)
V.push_back(ele)        // 在尾部添加一个数据  O(1)
V.pop_back()            // 删除最后一个数据 O(1)
V.size()                // 返回实际数据个数（unsigned int类型）  O(1)
V.clear()               // 清除所有数组元素  O(N)
V.resize(n, m)          // 改变数组长度为 n，若空间增大则令新赋值为 m，如果没这后面一项就默认为 0  O(N)
V.reserve(size_t n)     // 预分配 vector 的内存容量至能容纳 n 个元素  O(1)
V.insert(it, x)         // 向任意迭代器 it 插入一个元素 x  O(N)
V.erase(first, last)    // 删除 [first,last) 的所有元素  O(N)
V.begin()               // 返回首元素的迭代器  O(1)
V.end()                 // 返回最后一个元素的后一个位置的迭代器  O(1)
V.rbegin()              // 返回末尾元素的逆向迭代器，遍历默认为逆向  O(1)
V.rend()                // 返回首元素前一个位置的逆向迭代器  O(1)
V.empty()               // 判断是否为空，若为空则返回真，反之则返回假  O(1)
```

> **tips**：`end()` 返回的是**最后一个元素的后一个位置的迭代器**，不是最后一个元素的，**所有STL容器均是如此**，`rbegin()` 和 `rend()` 返回的是逆向迭代器，**遍历方式为逆向。**

在 C++11 后可以**使用 `emplace_back` 代替 `push_back`**，都是往容器末尾添加元素但底层实现机制不同。

- **push_back()** 会先创建这个元素，然后再将这个元素**拷贝**（事后会自行销毁）或移动到容器中。
- **emplace_back()** 则直接在容器尾部使用**完美转发**创建这个元素，在构造复杂对象时效率更优。

```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec;
    std::string temp = "Hello";
    vec.push_back(temp); // 先创建临时对象，然后拷贝到容器中
    vec.push_back(std::string("World")); // 先创建临时对象，然后移动到容器中

    vec.emplace_back("Hello"); // 直接在容器尾部构造字符串
    vec.emplace_back("World"); // 直接在容器尾部构造字符串
    return 0;
}
```

这适用于所有支持动态大小的序列式容器，**`emplace_front` 同理**则是在容器头部添加一个元素。

#### （4）访问元素的主要方法

```cpp
std::vector<int> V{1,2,3,4,5};

// 下标访问，和普通数组方法相同
for (int i = 0; i < 5; i++)
    std::cout << V[i] << " ";

// 使用到成员函数与指针算术
for (int i = 0; i < V.size(); i++)
    std::cout << *(V.begin() + i) << " ";

// 迭代器访问，类似指针操作，需要先声明迭代器变量 it
for (std::vector<int>::iterator it = V.begin(); it != V.end(); it++)
    std::cout << *it << " ";

// 使用 auto 关键字自动推导迭代器类型，简化迭代器声明
for (auto it = V.begin(); it!= V.end(); it++)
    std::cout << *it << " ";

// C++11 可用范围 for 循环简化，但只能遍历容器中的所有元素
for (auto val : V)
    std::cout << val << " ";
```

#### （5）二维初始化

定义一个第一维固定长度为 5，第二维可变化的数组如下，该数组存储的是 `vector<int>` 向量的数据类型，每个向量可以自定义长度和内容：

```cpp
std::vector <int> V[5];

V[1].push_back(2);              // 给第二个数组添加元素2
V[2].push_back(4);              // 给第三个数组添加元素4
```

再定义一个二维行列均可变长的数组，初始化如下：

```cpp
std::vector<std::vector <int>> V; // 定义了一个二维向量 V，它可以存储多个 std::vector<int> 类型的向量

std::vector<int> t1{1, 2, 3, 4};
std::vector<int> t2{2, 3, 4, 5};
V.push_back(t1);
V.push_back(t2);
V.push_back({3, 4, 5, 6});

/* 实际最终得到的 V 是一个包含三个 std::vector<int> 的二维向量，其中每个一维向量包含 4 个整数元素
V[0] = {1, 2, 3, 4}
V[1] = {2, 3, 4, 5}
V[2] = {3, 4, 5, 6} */
```

---

### 2、deque 详解

std::deque 支持在**两端高效地进行插入和删除**操作，结合栈和队列的特点，提供了灵活的元素管理方式。

#### （1）头文件

```cpp
#include <deque>
```

#### （2）初始化

```cpp
std::deque<int> dq1;                // 命名为 dq1，存储 int 整型数据类型
std::deque<float> dq2;              // 命名为 dq2，存储 float 浮点型数据类型
std::deque<std::string> dq3 = {"Hello", "World"}; 
std::deque<int> dq{1, 2, 3, 4, 5};
```

#### （3）常用成员函数

```cpp
//假设 dq 为 deque 双端队列的名称，其有 N 个元素，代码解释后包含算法时间复杂度

dq.push_back(x) / dq.push_front(x)          // 把 x 插入队尾/队首  O(1)
dq.back() / dq.front()                      // 返回队尾/队首元素  O(1)
dq.pop_back() / dq.pop_front()              // 删除队尾/队首元素  O(1)
dq.size()                                   // 返回 deque 的元素数量 O(1)
dq.empty()                                  // 检查容器是否为空，返回布尔值  O(1)
dq.at(pos)                                  // 返回位置 pos 的元素的引用，进行边界检查  O(1)
dq.swap(std::deque& other)                  // 交换两个 std::deque 的内容 O(1)
dq.reserve(size_t n)                        // 预分配 vector 的内存容量至能容纳 n 个元素  O(1)
dq.insert(pos, count, value)                // 在指定位置 pos 插入 count 个值为 value 的元素  O(N)
dq.erase(iterator it)                       // 删除 deque 中的某一个元素，由迭代器指定元素  O(N)
dq.erase(iterator first, iterator last)     // 删除 deque 中 [first, last) 中的元素  O(N)  
dq.clear()                                  // 清空 deque  O(N)
```

#### （4）应用场景

**作为队列使用 FIFO 先进先出：**

```cpp
std::deque<int> queue;
queue.push_back(1); // 入队
queue.push_back(2);
queue.push_back(3);
queue.pop_front();  // 出队
```

**作为栈使用 LIFO 后进先出：**

```cpp
std::deque<int> stack;
stack.push_back(1); // 入栈
stack.push_back(2);
stack.push_back(3);
stack.pop_back();   // 出栈
```

**作为双端队列使用：**

```cpp
std::deque<int> dq;
dq.push_front(1); // 在队首插入
dq.push_back(2);  // 在队尾插入
dq.pop_front();   // 从队首删除
dq.pop_back();    // 从队尾删除
```

在需要移动元素时，可以使用 `std::move` 来避免不必要的拷贝操作：

```cpp
std::deque<std::string> dq1 = {"Hello", "World"};
std::deque<std::string> dq2;
dq2.push_back(std::move(dq1[0]));
```

**容量管理：**

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};

    std::cout << "Size: " << dq.size() << std::endl; // 输出大小
    std::cout << "Empty: " << std::boolalpha << dq.empty() << std::endl; // 检查是否为空

    dq.clear(); // 清空容器
    std::cout << "Size after clear: " << dq.size() << std::endl; // 输出大小

    return 0;
}
```

---

### 3、list/forward_list 详解

std::list 和 std::forward_list 基于链表实现，但它们在实现和功能上有一些显著的区别。

- **std::list** 是一个双向链表，支持在任意位置高效地插入和删除元素，支持双向迭代器。
- **std::forward_list** 是一个单向链表，支持在任意位置高效地插入和删除元素，但只能单向遍历。

#### （1）头文件

```cpp
#include <list>
#include <forward_list>
```

#### （2）初始化

```cpp
std::list<int> lst1;                    // 默认构造
std::list<int> lst2 = {1, 2, 3, 4, 5};  // 使用初始化列表
std::list<int> lst3(lst2);              // 拷贝构造
std::list<int> lst4(std::move(lst2));   // 移动构造

std::forward_list<int> flst1;                
std::forward_list<int> flst2 = {1, 2, 3, 4, 5}; 
std::forward_list<int> flst3(flst2);         
std::forward_list<int> flst4(std::move(flst2)); 
```

#### （3）常用成员函数

**std::list：**

```cpp
// 假设 lst 为 std::list 的名称，其有 N 个元素

lst.push_front(x) / pop_front();           // 在头部插入元素 x /删除头部元素  O(1)
lst.push_back(x) / pop_back();             // 在尾部插入元素 x /删除尾部元素  O(1)
lst.front() / back();                      // 返回头部/尾部元素的引用  O(1)
lst.size();                                // 返回 list 的元素数量  O(1)
lst.empty();                               // 检查容器是否为空，返回布尔值  O(1)
lst.insert(iterator pos, const T& value);  // 在指定位置 pos 插入值为 value 的元素  O(1)
lst.erase(iterator it);                    // 删除由迭代器 it 指定的元素  O(1)
lst.erase(iterator first, iterator last);  // 删除范围 [first, last) 中的元素  O(N)
lst.clear();                               // 清空 list  O(N)
lst.swap(std::list& other);                // 交换两个 std::list 的内容  O(1)
lst.sort();                                // 对容器中的元素进行排序  O(N log N)
lst.unique();                              // 删除容器中相邻的重复元素  O(N)
lst.remove(val);                           // 删除容器中所有等于 val 的元素  O(N)
lst.remove_if(predicate);                  // 删除容器中满足条件的元素  O(N)
```

**std::forward_list：**

```cpp
// 假设 flst 为 std::forward_list 的名称，其有 N 个元素

flst.push_front(x);                        // 在头部插入元素 x  O(1)
flst.pop_front();                          // 删除头部元素  O(1)
flst.insert_after(iterator pos, const T& value); // 在指定位置 pos 之后插入值为 value 的元素  O(1)
flst.erase_after(iterator it);             // 删除由迭代器 it 指定的元素之后的元素  O(1)
flst.front();                              // 返回头部元素的引用  O(1)
flst.size();                               // 返回 forward_list 的元素数量  O(N)
flst.empty();                              // 检查容器是否为空，返回布尔值  O(1)
flst.clear();                              // 清空 forward_list  O(N)
flst.swap(std::forward_list& other);       // 交换两个 std::forward_list 的内容  O(1)
flst.sort();                               // 对容器中的元素进行排序  O(N log N)
flst.unique();                             // 删除容器中相邻的重复元素  O(N)
flst.remove(val);                          // 删除容器中所有等于 val 的元素  O(N)
flst.remove_if(predicate);                 // 删除容器中满足条件的元素  O(N)
```

#### （4）使用示例

**std::list：**

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    // 插入和删除操作
    lst.push_front(0);
    lst.push_back(6);
    lst.pop_front();
    lst.pop_back();

    // 遍历并输出
    for (int val : lst) {
        std::cout << val << " ";
    }
    return 0;
}
```

**std::forward_list：**

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flst = {1, 2, 3, 4, 5};

    // 插入和删除操作
    flst.push_front(0);
    flst.pop_front();

    // 遍历并输出
    for (int val : flst) {
        std::cout << val << " ";
    }
    return 0;
}
```

---

### 4、map 详解

这里补充前置知识：std::pair 是 STL 中的一个简单**模板类**，定义在头文件 `<utility>` 中用于存储两个不同类型的数据，主要用在 std::map 和 std::multimap 中表示键值对。

```cpp
#include <utility> // 包含 std::pair 的定义

template <class T1, class T2>
struct pair {
    T1 first;  // 第一个数据成员
    T2 second; // 第二个数据成员
};

std::pair<int, std::string> p1(1, "apple"); // 直接构造
std::pair<int, std::string> p2 = {2, "banana"}; // 使用花括号初始化

std::cout << p1.first << " " << p1.second << std::endl; // 输出 1 apple
std::cout << p2.first << " " << p2.second << std::endl; // 输出 2 banana
```

std::map 用于存储键值对，**其每个元素都是一个 std::pair**，其中 first 是键，second 是值。

#### （1）头文件

```cpp
#include <map>
```

#### （2）初始化

map 存储键值对，两个参数**前者为键是唯一的**不能重复，后者为**值可以重复**：

```cpp
std::map<std::string, std::string> mp1;    
std::map<std::string, int> mp2;        
std::map<int, node> mp3;             
```

map 会**按照键的顺序从小到大**自动排序，因此**键的类型必须可以比较大小，支持比较操作符。**

#### （3）常用成员函数

```cpp
//假设 mp 为map映射的名称，其有 N 个元素，代码解释后包含算法时间复杂度

mp.find(key)                           // 返回键为 key 的映射的迭代器  O(log N)
mp.erase(it)                           // 删除由迭代器对应指定的键和值  O(log N)
mp.erase(key)                          // 根据映射的键删除对应的键和值  O(log N)
mp.erase(first, last)                  // 删除 [first, last) 的 M 个迭代器对应的键和值  O(M * log N)
mp.size()                              // 返回映射的键值对数目  O(1)
mp.clear()                             // 清空 map 之中的所有元素  O(N)
mp.insert(std::make_pair(key, value))  // 构造新的键值对并插入该元素  O(log N)
mp.empty()                             // 如果 map 为空，返回真，否则返回假  O(1)
mp.begin()                             // 返回指向 map 第一个元素的迭代器  O(1)
mp.end()                               // 返回指向 map 最后一个元素的下一个迭代器  O(1)
mp.rbegin()                            // 返回指向 map 最后一个元素的迭代器  O(1)
mp.rend()                              // 返回指向 map 第一个元素的上一个地址  O(1)
mp.count(key)                          // 查看键为 key 的元素是否存在，若存在则返回 1，不存在则返回 0  O(log N)
mp.lower_bound(key)                    // 返回首个键不小于 key 的迭代器，否则返回 end()  O(log N)
mp.upper_bound(key)                    // 返回首个键大于 key 的迭代器，否则返回 end()  O(log N)
```

在 C++11 后我们可以**使用 emplace 函数平替 insert 函数用于插入新元素**，它直接在容器中构造对象，避免了额外的复制或移动操作，因此在性能上更优。emplace 通用于关联式容器 map 和 set。

#### （4）访问遍历 map

访问 map 单个元素可以直接根据**下标操作符 `[]` 根据键访问**对应的值，也可以用 **find()** 指定，其**键和值**可以分别通过其迭代器的 `it->first` 和 `it->second` 来访问：

```cpp
std::map<std::string, std::string> mp;               
mp["惠州一中"] = "深圳大学";          // 添加键值对，键为 "惠州一中"，值为 "深圳大学"
mp["abcdefg"] = "qwertyu";            // 添加键值对，键为 "abcdefg"，值为 "qwertyu"

std::map<int, std::string> mp1;
mp1[1] = "hello";
mp1[2] = "world";

std::cout << mp["惠州一中"] << std::endl;         // 输出结果为深圳大学
std::cout << mp1[1] << " " << mp[2] << std::endl; // 输出结果为 hello world

// 使用 find() 查找
std::map<std::string, std::string>::iterator it = mp.find("abcdefg");
std::cout << "键: " << it->first << std::endl;     // abcdefg
std::cout << "值: " << it->second << std::endl;    // qwertyu
```

也可以用 auto 和基于范围的 for 循环：

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> mp = {
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };
    
    // C++11 范围for循环（最简洁）
    for (const auto& pair : mp) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // 使用 auto 简化迭代器声明
    auto it = mp.find(2);
    if (it != mp.end()) {
        std::cout << "找到: " << it->first << " -> " << it->second << std::endl;
    }
    
    return 0;
}
```

用 `mp.begin()` 和 `mp.end()` 正向遍历如下：

```cpp
std::map <int, int> mp;
mp[1] = 2;
mp[2] = 3;
mp[3] = 4;
auto it = mp.begin();   // 使用 auto 简化迭代器声明
while (it != mp.end()) {
    std::cout << it->first << " " << it->second << std::endl;
    it ++;
}
```

结果为：

```
1 2
2 3
3 4
```

用 `mp.rbegin()` 和 `mp.rend()` 逆向遍历如下：

```cpp
std::map <int, int> mp;
mp[1] = 2;
mp[2] = 3;
mp[3] = 4;
auto it = mp.rbegin();
while (it != mp.rend()) {
    std::cout << it->first << " " << it->second << std::endl;
    it ++; // 反向遍历时迭代器也是从后往前递增
}
```

结果为：

```
3 4
2 3
1 2
```

也可以用智能指针进一步简化遍历步骤：

```cpp
std::map <int, int> mp;
mp[1] = 2;
mp[2] = 3;
mp[3] = 4;

for (auto i : mp)           // 循环变量 i 是一个 std::map 中每个元素的拷贝，性能较低且没 const 保护
    std::cout << i.first << " " << i.second << std::endl;

for (const auto& j : mp)    // 循环变量 j 是一个对 std::map 中每个元素的常量引用，避免了不必要的拷贝
    std::cout << j->first << " " << j->second << std::endl;
```

其结果同正向遍历结果。

#### （5）二分查找

map 的二分查找以第一个元素即键为准，通过 `lower_bound` 和 `upper_bound` 对**键进行二分查找**，返回值为 **map迭代器类型**。

```cpp
std::map <int, int> m{{1, 2}, {2, 2}, {1, 2}, {8, 2}, {6, 2}};
// 但由于 map 不允许重复的键，实际上只有键值对{1, 2}, {2, 2}, {8, 2}, {6, 2}会被存储

std::map <int, int> ::iterator it1 = m.lower_bound(2);
// it1 指向第一个键不小于 2 的元素，即键为 2 的元素，it1->first = 2
std::cout << it1->first << std::endl;                                

std::map <int, int> ::iterator it2 = m.upper_bound(2);
// it2 指向第一个键大于 2 的元素，即键为 6 的元素，it2->first = 6
std::cout << it2->first << std::endl;                                 
```

#### （6）添加元素

```cpp
std::map<std::string, std::string> mp;                     

// 方式一使用下标操作符 [] 最简单
mp["学生"] = "学习";
mp["老师"] = "教书";

// 方式二接受一个 std::pair 类型的参数，其中包含键和值
mp.insert(std::make_pair("vegetable","蔬菜"));

// 方式三直接使用 std::pair 的模板参数
mp.insert(std::pair<std::string, std::string> ("fruit","水果"));

// 方式四使用花括号 {} 直接初始化一个键值对，C++11 及以上版本支持的语法
mp.insert({"hahaha","balabala"});

for (const auto& pair : mp) {
    std::cout << pair.first << " " << pair.second << std::endl;
}
```

> **注意**：输出顺序和我插入添加元素顺序不同，实际上 map 会根据键的字典序（即字符串的字典序）对键值对进行排序，字符串的比较是**基于字符的 ASCII 值逐字符进行比较**的，而不是按照插入的顺序。

如果需要保持插入顺序，可以使用 `std::vector` 辅助：

```cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::string> mp;                     
    std::vector<std::string> order;

    mp["学生"] = "学习";
    order.push_back("学生");

    mp["老师"] = "教书";
    order.push_back("老师");

    mp.insert(std::make_pair("vegetable", "蔬菜"));
    order.push_back("vegetable");

    mp.insert(std::pair<std::string, std::string>("fruit", "水果"));
    order.push_back("fruit");

    mp.insert({"hahaha", "balabala"});      
    order.push_back("hahaha");

    for (const auto& key : order)
        std::cout << key << " : " << mp[key] << std::endl;
    return 0;
}
```

#### （7）与无序映射 unordered_map 的比较

| 特性 | map | unordered_map |
|------|-----|---------------|
| 内部实现 | 红黑树 | 哈希表 |
| 排序 | 按键从小到大自动排序 | 内部元素无序杂乱 |
| 查找/增删时间复杂度 | O(log N) | O(1) 平均 |
| 空间占用 | 较大 | 相对较低 |
| 建立耗时 | 一般 | 建立哈希表耗时较大 |

```cpp
#include <unordered_map>

std::unordered_map<int, std::string> umap1; // 默认构造
std::unordered_map<int, std::string> umap2 = {{1, "apple"}, {2, "banana"}, {3, "cherry"}}; // 使用初始化列表

// 整体添加删除等操作与 std::map 类似
```

---

### 5、set 详解

#### （1）头文件

```cpp
#include <set>
```

#### （2）初始化

```cpp
std::set<int> s1;                          // 命名为 s1，存储 int 类型的元素
std::set<char> s2 = {'a', 'b', 'c', 'd'};  // 使用初始化列表初始化 s2

std::vector<int> vec = {1, 2, 3, 4, 5};
std::set<int> s3(vec.begin(), vec.end()); // 使用范围初始化 s3
```

set 中元素是唯一的不能重复，且会对元素自动排序，排序方式由元素类型的比较操作符（如 `<`）决定。

#### （3）常用成员函数

```cpp
//假设 s 为 set 集合的名称，其有 N 个元素，代码解释后包含算法时间复杂度

s.begin()                            // 返回 set 容器的第一个元素的迭代器  O(1)
s.end()                              // 返回 set 容器的最后一个元素的下一个地址  O(1)
s.rbegin()                           // 返回逆序迭代器，指向容器元素最后一个位置  O(1)
s.rend()                             // 返回逆序迭代器，指向容器第一个元素前面的位置  O(1)
s.clear()                            // 删除 set 容器中的所有的元素,返回 unsigned int 类型  O(N)
s.empty()                            // 判断 set 容器是否为空，返回布尔值  O(1)
s.insert(value)                      // 插入一个元素 value  O(1)
s.size()                             // 返回当前set容器中的元素个数  O(1)
s.erase(key_value)                   // 删除键值key_value的值  O(1)
s.find(ele)                          // 查找 set 中的某一元素，有则返回该元素对应的迭代器，无则返回 end()  
s.count(ele)                         // 查询 ele 是否出现，返回 0 或 1  O(logN)
s.lower_bound(k)                     // 返回不小于 k 的第一个元素的迭代器  O(logN)
s.upper_bound(k)                     // 返回大于 k 的第一个元素的迭代器  O(logN)
```

#### （4）访问遍历 set

**迭代器遍历：**

```cpp
for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
    std::cout << *it << " ";
```

**智能指针遍历：**

```cpp
for (auto i : s)
    std::cout << i << std::endl;
```

**访问最后一个元素：**

```cpp
//方式一
std::cout << *s.rbegin() << std::endl;

//方式二
std::set<int>::iterator it = s.end();
it--;
std::cout << (*it) << std::endl;

//方式三
std::cout << *(--s.end()) << std::endl;
```

#### （5）重载运算符

set 默认使用 less 比较器，即**从小到大**排序，可以添加 greater 比较器等改变排序规则。

```cpp
std::set <int> s1;                  // 默认从小到大的排序
std::set <int, greater<int>> s2;    // 更改为从大到小排序
```

也可以在初始化时使用匿名函数定义比较规则：

```cpp
std::set <int, function<bool (int, int)>> s([&](int i, int j){
    return i > j;                     //自定义从大到小排序
});

for (int i = 1; i <= 10; i++)
    s.insert(i);                      //依次添加元素
for (auto x : s)
    std::cout << x << " ";                 //遍历set查看排序结果
```

#### （6）与无序集合 unordered_set 的比较

| 特性 | set | unordered_set |
|------|-----|---------------|
| 内部实现 | 红黑树 | 哈希表 |
| 排序 | 自动排序（按键从小到大） | 内部元素无序杂乱 |
| 查找/增删时间复杂度 | O(log N) | O(1) 平均 |
| 空间占用 | 较大 | 相对较低 |
| 建立耗时 | 一般 | 建立哈希表耗时较大 |

---

### 6、string 详解

在 STL 中，string 被称为**字符序列容器**，它是一种特殊的容器，专门用于处理字符串，有许多成员函数和操作符重载，封装了一系列字符串相关的功能，如插入、删除、替换、查找、连接等，并支持通过下标或迭代器访问和修改字符串中的字符。

#### （1）头文件

```cpp
#include <string>
```

#### （2）初始化定义

```cpp
std::string str1;                       // 生成空字符串，长度为 0

std::string str2("123456");             // 生成 "123456" 的字符串

std::string str3("123456", 0, 3);       // 结果为 "123"，从 0 位置开始，长度为 3
 
std::string str4("123456", 5);          // 结果为 "12345"，默认从 0 位置开始，长度为 5
 
std::string str5(4, '3');               // 结果为 "3333"，构造 4 个字符 '3' 连接而成的字符串

std::string str6(str2, 2);              // 结果为 "3456"，截取从第三个元素到最后的字符串
```

#### （3）常用成员函数

```cpp
str.size() / length()   // 返回字符串的长度  O(1)
str.empty()             // 判断字符串是否为空，返回布尔值  O(1)
str.clear()             // 删除字符串中的所有字符  O(1)
str.push_back(c)        // 在字符串末尾添加一个字符 c  O(1)
str.pop_back()          // 删除字符串末尾的字符  O(1)
str.append(s)           // 在字符串末尾添加另一个字符串 s  O(n)
str += s                // 在字符串末尾添加另一个字符串 s  O(n)
str.insert(pos, s)      // 在指定位置 pos 插入另一个字符串 s  O(n)
str.erase(pos, len)     // 删除从位置 pos 开始的长度为 len 的子字符串  O(n)，其中 n 是删除的子字符串长度
str.find(s)             // 查找子字符串 s 的位置，返回找到的位置的索引，无则返回 std::string::npos  O(n)
str.rfind(s)            // 从后向前查找子字符串 s 的位置，返回找到的位置的索引，无则返回 std::string::npos  O(n)
str.find_first_of(s)    // 查找子字符串 s 中任意字符第一次出现的位置，返回找到的位置的索引，无则返回 std::string::npos  O(n)
str.find_last_of(s)     // 查找子字符串 s 中任意字符最后一次出现的位置，返回找到的位置的索引，无则返回 std::string::npos  O(n)
str.compare(s)          // 比较两个字符串，返回一个整数，表示比较结果  O(n)
str.c_str()             // 返回一个指向 C-style 字符串的指针  O(1)
str.data()              // 返回一个指向字符串数据的指针  O(1)
str.at(0)               // 通过下标访问字符串中的字符，进行边界检查  O(1)
```

#### （4）访问遍历 string

**访问单个字符：**

```cpp
std::string s = "yi sheng jun";
char ch1 = s[0];    // 访问第一个字符
char ch2 = s.at(1); // 访问第二个字符

for (int i = 0; i < s.size(); i++)
    std::cout << s[i] << " "; // 或使用 s.at(i) 访问并进行边界检查

for (auto it = s.begin(); it != s.end(); ++it)
    std::cout << *it << " ";

for (char c : s)
    std::cout << c << " ";
```

**string 数组的使用：**

```cpp
std::string fruits[3] = {"apple", "banana", "cherry"};
for (auto i : fruits)
    std::cout << i << std::endl;
```

**动态字符串数组：**

```cpp
std::vector<std::string> fruits = {"apple", "banana", "cherry"};

// 动态添加元素
fruits.push_back("date");
fruits.push_back("elderberry");

// 使用范围 for 循环遍历
for (const std::string& fruit : fruits)
    std::cout << fruit << std::endl;
```

#### （5）string 特性

std::string 支持常见的比较运算符，如 `<`, `<=`, `>=`, `>`, `==`, `!=`，按照字典顺序进行逐一比较。

- **比较规则**：比较两个字符串时，从第一个字符开始逐个比较，直到找到不相等的字符为止。
- **比较结果**：如果某个位置上的字符不相等，则根据该位置字符的 ASCII 值确定两个字符串的大小。
- **长度比较**：如果一个字符串是另一个字符串的前缀，较短的字符串被认为较小。

```cpp
std::string a = "apple";
std::string b = "banana";
std::string c = "apple";
std::string d = "app";

bool result1 = (a == c); // 结果 true
bool result2 = (a < b);  // 结果 true，因为 'a' < 'b'
bool result3 = (a < d);  // 结果 false，因为 "apple" 比 "app" 长
```

---

> **来源说明**：本文内容整理自知乎专栏文章，原文链接：[https://zhuanlan.zhihu.com/p/681276606](https://zhuanlan.zhihu.com/p/681276606)