![](assets/未命名/file-20260716151828724.png)
# 代码
```
#include<bits/stdc++.h>
using namespace std;
struct path{
	int num,step;
};
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		vector<path> event;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			int step=0;
			while(1){
				struct path node={
					a,step
				};
				event.push_back(node);
				if(a==1){
					struct path node1={
						2,step+1
					};
					event.push_back(node1);
					break;
				}
				if(a==2){
					struct path node1={
						1,step+1
					};
					event.push_back(node1);
					break;
				}
				if(a%2==0) a/=2;
				else a+=1;
				step++;
			}
		}
		sort(event.begin(),event.end(),[](path a,path b){
			return a.num<b.num;
		});
		int i=0;
		long long ans=60*n;
		while(i<event.size()){
			int count=0;
			long long length=0;
			int j=i;
			while(j<event.size()&&event[i].num==event[j].num){
				count++;
				length+=event[j].step;
				j++;
			}
			if(count==n&&length<=ans){
				ans=length;
			}
			i=j;
		}
		cout<<ans<<endl;

		
	}
	
	return 0;
}
```


# 思路讲解

很自然的可以想到，就是找到第一个所有路径的公共点，一定可以找到，因为所有的点都会进入2 1 的循环。

但是这个第一个有点不好找，那就把每个走过的节点记录下来，然后再把经过n次的节点的步数算出来，就可以寻找最小值了