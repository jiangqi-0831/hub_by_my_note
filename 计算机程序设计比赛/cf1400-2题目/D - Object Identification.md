![](assets/D%20-%20Object%20Identification/file-20260723130331241.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200050
int a[MAXN],cnt[MAXN];

void solve(){
	int n,i_1=-1,i_n=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			i_1=i;
		}
		if(a[i]==n){
			i_n=i;
		}
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){
			cout<<"? "<<i<<" "<<i%n+1<<endl;
			int x;
			cin>>x;
			if(x==0){
				cout<<"! A"<<endl;
			}else{
				cout<<"! B"<<endl;
			}
			return ;
		}
	}
	int x,y;
	cout<<"? "<<i_1<<" "<<i_n<<endl;	
	cin>>x;
	cout<<"? "<<i_n<<" "<<i_1<<endl;	
	cin>>y;
	if(x==0||y==0){
		cout<<"! A"<<endl;
		return ;
	}
	if(x==y&&x>=(n-1)&&y>=(n-1)){
		cout<<"! B"<<endl;
		return ;
	}
	cout<<"! A"<<endl;
	return ;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	
	
	return 0;
} 
```
# 思路
首先我们可以发现，如果返回值是0，那么这个对象一定是A。
因此很自然的可以想到我们尽可能的要他去返回零。
我们可以发现，如果有一个点没有指向任何点，那么从这个点为起点的路径一定是0。所以可以先判断序列x是不是一个排序，若不是一个排序，那么找到他的MEX，以他为起点，任意点为终点，为零即为A，不为零即为B。

但是如果是一个排列该怎么办呢？
我们尝试询问 $(i,j)$ 与 $(j,i)$ ，如果是对象B，那么这个是无序的，返回值应该相等，但是如果是A的话，我们选取的刚好是一个环的直径，不也是相等吗？那我们就思考一下他们还有没有什么差别。

我们可以发现对象A路径最长也只能是n-1，并且如果反过来的话，经过的路径一定不会路过同一条边。因此我们就可以选取的i，j使得他的长度在B中尽可能的大，只要超过的A的最大路径，那么就是对象B。

因此我们可以选择一个 $x_i=1,x_j=n$ 的两点，而 $|x_i-x_j|\geq n-1$ 因此对象B的返回值一定会大于 $n-1$ 而对象A的返回值一定不会大于 $\lceil\frac{n}{2}\rceil$  。