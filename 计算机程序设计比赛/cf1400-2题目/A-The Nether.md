![](assets/A-/file-20260723124739146.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200050
vector<int> ans;
set<int> len[MAXN];
vector<int> print;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//初始化 
		for(int i=1;i<=n;i++){
			len[i].clear();
		}
		ans.clear();
		//记录每个起点的最长长度 
		for(int i=1;i<=n;i++){
			cout<<"? "<<i<<" "<<n<<" ";
			for(int j=1;j<=n;j++){
				cout<<j<<" ";
			}
			cout<<endl;
			int x;
			cin>>x;
			if(x==-1){
				return 0;
			}
			len[x].insert(i);	
		}
		int maxlen=0;
		for(int i=n;i>0;i--){
			if(maxlen==0&&!len[i].empty()){
				maxlen=i;
				ans.push_back(*len[i].begin());
				continue;
			}
			for(int num:len[i]){
				print.clear();
				print.push_back(num);
				for(int k=0;k<ans.size();k++){
					print.push_back(ans[k]);
				}
				for(int k=i-1;k>0;k--){
					for(int m:len[k]){
						print.push_back(m);
					}
				}
				cout<<"? "<<ans[0]<<" "<<print.size()<<" ";
				for(int p:print){
					cout<<p<<" ";
				}
				cout<<endl;
				int x;
				cin>>x;
				if(x==-1){
					return 0;
				}
				if(x==maxlen){
					ans.push_back(num);
					break;
				}
			}
			
			
		}
		cout<<"! "<<maxlen<<" ";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		
		
	}
	
	
	
	return 0;
}
```

# 思路
因为没有环，所以这个路线是不可返回的，只能往前走。

可以先尝试把每个点都当作起点，然后找到最长的路径的起点。现在我们的 目标变成了寻找路线，因为我们现在已经找到路径的长度和起点了。

但是再经过n次询问后我们只剩下n次询问，那么我们若要找起点后的下一步我们肯定需要 $n-1$ 次询问，那么我们肯定要充分利用一些以前的信息，前面n次只找到了起点和路径长度，太浪费了。然后我们可以看，因为每个起点都是到终点的最长长度，那么每次找下一个点肯定是在最大长度减一的点去找。那么我们就可以把我们已经找到的路径，我们要确定的路径和剩下的长度的点放一起，如果此时的最大长度还是整个的最大长度，那么这个我们要确定点就是在最长路径里，加入。

然后我们是再每个点遍历一遍，所以刚好是2n次。