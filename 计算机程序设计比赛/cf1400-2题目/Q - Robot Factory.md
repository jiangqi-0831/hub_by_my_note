![](assets/Q%20-%20Robot%20Factory/file-20260725105553297.png)
# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1050
#define MAXM 1050
short int a[MAXN][MAXM];
bool vis[MAXN][MAXM];
vector<int> ans;
int n,m;

int bfs(int x,int y){
	int ans=0;
	if(vis[x][y]==1){
		return 0;
	} 
	vis[x][y]=1;
	if((a[x][y]&8)==0&&x-1>=0){
		ans+=bfs(x-1,y);
	} 
	if((a[x][y]&4)==0&&y+1<m){
		ans+=bfs(x,y+1);
	}
	if((a[x][y]&2)==0&&x+1<n){
		ans+=bfs(x+1,y);
	}
	if((a[x][y]&1)==0&&y-1>=0){
		ans+=bfs(x,y-1);
	}
	return ans+1;
}

int main(){

	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]!=1){
				ans.push_back(bfs(i,j));
			}
		}
	}
	
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
```
# 思路
找最大连通块吗，搜索解决。