![](assets/未命名/file-20260723125657951.png)
# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200050
vector<int> edge[MAXN];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			edge[i].clear();
		}
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int ans=0,maxn=0;
		for(int i=1;i<=n;i++){
			if(edge[i].size()==1){
				ans++;
			}
			int count=0;
			for(int j:edge[i]){
				if(edge[j].size()==1){
					count++;
				}
			}
			maxn=maxn>count?maxn:count;
		}
		if(n==2){
			cout<<"0\n";
		}else{
			cout<<ans-maxn<<"\n";
		}
		
		
	}
	
	
	return 0;
}

```

# 思路

我们可以确定最短的直径就是2，即每个点都链接在同一点上。

那么我们要实现这个样子的话，就是要每个分支都要遍历一遍，每多一个分支，就要多操作一次。（根节点直接连接的子叶节点不需要）

所以我们就是统计树的所有分支（即子叶节点的数量），然后减去我们点中最大连接子叶节点的数量，就是我们的最小操作次数。