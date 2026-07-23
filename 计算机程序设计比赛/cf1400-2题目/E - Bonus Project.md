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

那么怎么分配呢？因为是第一个工程师先对自己去最大，那么肯定就是要后面的人干多一点事，但是又不能要后面的人干不完工作，所以就应该干事干到后面的人能接受的情况。

那么就先预处理后面能接受的最大工作，在按顺序模拟。