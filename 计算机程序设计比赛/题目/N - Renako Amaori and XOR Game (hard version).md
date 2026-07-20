![](assets/未命名/file-20260720194730284.png)

# 代码 
```
#include<bits/stdc++.h>
using namespace std;
#define MAX 200050
long long a[MAX],b[MAX],c[MAX],sum;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sum=0;
		for(int i=0;i<n;i++){
			c[i]=a[i]^b[i];
			sum=sum^c[i];
			//cout<<sum<<" "<<c[i]<<" "<<a[i]<<" "<<b[i]<<"\n"; 
		}
		if(sum==0){
			cout<<"Tie\n";
		}else{
			int k=0,max1=0;
			while(sum!=0){
				k++;
				sum/=2;
			}
			max1=1;
			max1=max1<<(k-1); 
			//cout<<k<<" "<<max1<" "; 
			for(int i=n-1;i>=0;i--){
				if((c[i]&max1)!=0){
					if(i%2==1){
						cout<<"Mai\n";
					}else{
						cout<<"Ajisai\n";
					}
					break; 
				}
				//cout<<c[i]<<" "; 
			}
		}	
	}
	return 0;
}
```

# 思路
又是XOR，那就先看看题目，然后联想一下XOR的特点吧。

我们可以发现，设初始时 Ajisai 的异或和为 $A_0$，Mai 的异或和为 $B_0$。当第 $i$ 轮发生交换时，相当于 $A$ 和 $B$ 都异或上同一个值 $di=ai⊕bi$​，因此无论怎么操作，最终两者异或和的差 $A_{final}⊕ B_{final}$​ 恒等于 $A_0⊕B_0$，记为 $X$。

如果 $X=0$，那么无论怎么玩，最终两个得分一定相同，因此结果是 **平局**。

如果 $X≠0$，则胜负只看 X 的最高二进制位 k，因为在这一位两数的得分必然不同。  
考虑每个位置 $i$，只有满足 $d_i$​ 的第 $k$ 位为 $1$ 的交换，才会翻转 Ajisai 得分在第 $k$ 位的值。换句话说，这些位置是“有效操作”，能改变最终的胜者。  
游戏按顺序从 1 到 n 进行，所以**最后一个有效操作**的玩家决定了第 kk 位的最终状态，从而决定了谁获胜。因此我们从后往前扫描，找到第一个满足 di​ 的第 $k$ 位为 1 的下标 $i$，若 $i$ 为奇数则 Ajisai 赢，若为偶数则 Mai 赢。

实现时，先求出 $X$ 的最高位掩码，再倒序遍历数组即可，总时间复杂度 $O(n)$，满足题目限制。

# 知识点XOR
