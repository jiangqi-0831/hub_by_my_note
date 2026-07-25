![](assets/G%20-%20Sakurako's%20Field%20Trip/file-20260725112942408.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200050
int a[MAXN];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n/2;i++){
			if(a[i]==a[i-1]||a[n-i+1]==a[n-i+2]){
				swap(a[i],a[n-i+1]);
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1]){
				ans++;
			}
		}
		cout<<ans<<"\n";
		
		
		
		
	}
	
	
	
	
	return 0;
}
```
# 思路
首先，我们只需要交换前n/2个，交换后面的和改变交换前面的状态是一样的。然后我们可以发现，只要有相同的，交换的收益一点会大于等于不交换的。那么我们就交换，然后最后统一遍历全部内容得到答案。