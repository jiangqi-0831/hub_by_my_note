![](assets/Cost%20of%20a%20Bracket%20Sequence/file-20260717171436939.png)
# 思路讲解
## 求出原序列的最长正规括号子序列
$$
P = \min_{i}\{perfOpen[i]+suffClose[i]\}
$$
其中$perfOpen[i]$是指在前$i$个左括号的个数，$suffClose[i]$是指在后$n-i$个右括号的个数,$P$为最长正规括号配对数。
### 1.证明$P \leq \min_{i}\{perfOpen[i]+suffClose[i]\}$

对于任意的下标$i$，每个配对要么左括号在$i$标左侧，要么右括号在$i$标右侧，或者都满足，故左边左括号的个数加上右边右括号的个数一定大于最大的配对数，即$\forall x,i$，s.t.
$$
P_x \leq prefOpen[i] + suffClose[i]     
$$

其中$P_x$为配对方式为$x$的配对数
### 2.证明$P$可以取到等号

那么需要证明的即是，$\exists 配对x$,s.t.
$$
P = \min_{i}\{perfOpen[i]+suffClose[i]\}
$$

我们可以按照顺序来找配对，每次把 “)” 与左侧最近的 “(” 配对，可以证明这样寻找到的配对数是最大的。那么
$$
P = totalColse - (-\min_{i}balance[i])
$$
其中$totalClose$为总共右括号的个数，$-balance[i]$为在$i$前无法配对 ")" 的个数。定义$$
balance[i] \overset{def}{=} prefOpen[i]-prefClose[i]
$$
故
$$prefOpen[i]+suffClose[i]=prefOpen[i]+(totalClose−prefClose[i])=totalClose+balance[i]$$
对等式同时取最小值，可得
$$\min_{i}​(prefOpen[i]+suffClose[i])=totalClose+\min_{i}​balance[i]$$
此时的配对方式取得最大值。


## 每次删除最多使得配对数减一

### 最多减一
### 可以做到每次都减一
我们只需要对于对最小的$i$，将他左侧“(”或者右侧的")"删去一个，那么他的最小值就为$P-1$,此时删去后的最大正规括号配对数就减少了一

## 实现方法
在代码内记录$prefOpen[i]$与$suffColse[i]$，寻找的使得之和最小的$i$，然后再在其左侧删去 "(" 和右侧删去 ")" 即可。





# 官方题解
![](assets/Cost%20of%20a%20Bracket%20Sequence/file-20260716143211657.png)