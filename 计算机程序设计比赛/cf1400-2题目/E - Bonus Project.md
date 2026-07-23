![](assets/E%20-%20Bonus%20Project/file-20260723151435863.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1050
long long maxs[MAXN],a[MAXN],b[MAXN];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	maxs[n-1]=a[n-1]/b[n-1];
	for(int i=n-2;i>=0;i--){
		maxs[i]=maxs[i+1]+(a[i]/b[i]);
	}
	int res=k;
	if(res>maxs[0]){
		for(int i=0;i<n;i++){
			cout<<"0 ";
		}
		cout<<"\n";
	}else{
		for(int i=0;i<n;i++){
			int dos=max(res-maxs[i+1],(long long)0);
			cout<<dos<<" ";
			res-=dos;
		}
		cout<<"\n";
	
		
		
		
	}
	
	
	
	
	
	return 0;
}
```
# 思路
首先对于每个人而言，他们最多干的工作为 $\lfloor\frac{a_i}{b_i}\rfloor$ ，如果全部的总和都要比 $k$ 要小，那么全部不工作为最优解。

那么怎么分配呢？首先我们从正向往下去找的分配方式是很多的，那么我们就从后往前考虑。若前n-1位工程师已经分配好了，那么剩余的工作量一定要比这个工程师能接受的要小，