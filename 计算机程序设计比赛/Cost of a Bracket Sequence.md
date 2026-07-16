![](assets/未命名/file-20260716140447559.png)

# 思路讲解
## 求出原序列的最长正规括号子序列
$$
P = \min_{i}\{perfOpen[i]+suffClose[i]\}
$$
其中$perfOpen[i]$是指在标号$i$之前左括号的个数，$suffClose[i]$是指在标号$i$之后右括号的个数,$P$为最长正规括号配对数。
### 1.证明$P \leq \min_{i}\{perfOpen[i]+suffClose[i]\}$

对于任意的下标$i$，每个配对要么左括号在$i$左侧，要么右括号在$i$右侧，或者都满足，故左边左括号的个数加上右边右括号的个数一定大于最大的配对数，即$\forall x,i$，s.t.
$$
P_x \leq prefOpen[i] + suffClose[i]     
$$

其中$P_x$为配对方式为$x$的配对数
### 2.证明$P$可以取到等号

