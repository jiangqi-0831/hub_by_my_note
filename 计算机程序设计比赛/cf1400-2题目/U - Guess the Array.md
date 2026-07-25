![](assets/U%20-%20Guess%20the%20Array/file-20260725103402557.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	int n;
	cin>>n;
	int s1,s2,s3,x;
	cout<<"? 1 2"<<endl;
	cin>>s1;
	cout<<"? 2 3"<<endl;
	cin>>s2;
	cout<<"? 1 3"<<endl;
	cin>>s3;
	a[1]=(s1+s3-s2)/2;
	a[2]=s1-a[1];
	a[3]=s3-a[1];
	for(int i=4;i<=n;i++){
		cout<<"? 1 "<<i<<endl;
		cin>>x;
		a[i]=x-a[1];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
```

# 思路
有n个未知数，然后我们可以询问到n个方程，那么我们只要构造出一个满秩的系数矩阵，那么就可以解出来这n个未知数。

当 $n=3$ 时，我们可以构建一个方程组：
$$
\begin{cases}
x_1 + x_2 + 0 &= a \\
x_1 + 0 + x_3 &=b\\
0 + x_2 + x_3 &=c
\end{cases}
$$
这样我们就可以解出三个未知数：
$$
\begin{cases}
x_1&=\frac{a+b-c}{2}\\
x_2&=\frac{a+c-b}{2}\\
x_3&=\frac{b+c-a}{2}
\end{cases}
$$

然后后面的就分别与 $x_1$ 进行计算就可以得到答案了。