![](assets/未命名/file-20260717162919406.png)

# 代码
## 解法一：构造
```
#include<bits/stdc++.h>
using namespace std;
long long a[200050],lowsum=0,max1=0,index=-1;
int ans[200050],print[200050],start=0,end1=0;
int pop(){
	return print[start++];
}
void push(int n){
	print[end1++]=n;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		start=0;end1=0;index=-1;max1=0;lowsum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<0){
				ans[i]=-1;
				lowsum+=-a[i];
			}else if(a[i]>0){
				ans[i]=1;
				if(lowsum-a[i]>max1){
					max1=lowsum-a[i];
					index=i;
				}
			}
		}
		if(index==-1){
			cout<<0<<"\n";
			cout<<"\n";
		}else{
			int i=index-1,j;
			while(i>0&&ans[i]==-1){
				i--;
			}
			j=i;
			while(i>0&&j>0){
				push(i);
				while(ans[j]==ans[i]&&j>0){
					j--;
				}
				i=j;
			}
			cout<<end1-start+1<<"\n";
			while(start<end1){
				cout<<pop()<<" ";
			}
			cout<<index<<"\n";
		}
		
		
	}
	
	return 0;
}
```

## 解法二：dp