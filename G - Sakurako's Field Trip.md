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
首先，我们交换的位置是固定的，