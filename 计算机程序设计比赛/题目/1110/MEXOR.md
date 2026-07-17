![](assets/MEXOR/file-20260717111259831.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
int len(long long n){
	int count=0;
	while(n!=0){
		n/=2;
		count++;
	}
	return count;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		long long k,k_;
		cin>>n>>k;
		k_=k^n;
		if(len(k_)>len(n-1)){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			if(k_==0){
				for(int i=0;i<n-1;i++){
					cout<<i+1<<" ";
				}
				cout<<"0"<<"\n";
			}else if(k_<=n-1){
				for(int i=0;i<n;i++){
					if(i!=k_&&i!=0){
						cout<<i<<" ";
					}
				}
				cout<<0<<" "<<k_<<"\n";
			}else if(k_>n-1){
				long long v=k_^(n-1);
				for(int i=0;i<n;i++){
					if(i!=n-1&&i!=v&&i!=0){
						cout<<i<<" ";
					}
				}
				cout<<0<<" "<<v<<" "<<n-1<<"\n";
			}
		}
	}
	return 0;
}
```

# 思路
首先补充几个位运算的知识：
1. $a \oplus b = c \iff a = b \oplus c$
2. $a \oplus b \leq a \| b$ 
3. $0 \oplus 0 = 0$

观察一下特点：
1. 若0在第i处出现，那么$f(j)=0,\forall j \in [0,i)$
2. $f(x)$随着$x$单调不减
3. $f(n-1)=n$

我们只需要所有 $f$ 的异或值，所以我们可以从后往前构造，只要能够构造出来，我们就可以让 $f$ 前面的值全部为零。

然后，我们又知道 $f$ 的值一定有 $n$ ，因此我们先把 $n$ 融入 $k$ ,得到 $k^{\prime}$ ($k^{\prime} = k \oplus n$),只需要让后面的异或值为 $k^{\prime}$ 即可。

若在二进制下 $k^{\prime}$ 的长度大于 $n-1$ 的长度，那么我从小于 $n-1$ 中如何选择，都不可能异或出长于 $n-1$ 的数，此时无解。

我们可以发现，当 $k^{\prime} \leq n-1$ 时，我们可以直接让 $f$ 取到 $k^{\prime}$ ，然后前面的取0，即可。若 $k^{\prime}$ 直接为0，那么就直接要排列最后一个数字为零即可。

若 $k^{\prime} \geq n-1$ ，那么我们不能直接选取 $k^{\prime}$ ，那么我们可以选取两个小于 $n-1$ 的数字异或得到 $k^{\prime}$ 吗？答案是可以的。因为我们令 $v=k^{\prime} \oplus (n-1)$，由于 $k^{\prime}$ 的二进制长度小于等于 $n-1$ 的，而又大于 $n-1$ ，故 $k^{\prime}$ 和 $n-1$ 的最高位相同，于是题目两个异或得到的 $v$ 就会小于 $n-1$.成功得到。

