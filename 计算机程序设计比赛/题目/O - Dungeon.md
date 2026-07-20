![](assets/未命名/file-20260720193438280.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAX 200050
int p[2]={0,0};
int ans=0;

vector<long long> need,have;
struct node{
	long long b,c;
	bool operator<(const node &x) const{
		return b < x.b;
	}
	bool operator>(const node &x) const{
		return b > x.b;
	}
	bool operator<=(const node &x) const{
		return b <= x.b;
	}
	bool operator>=(const node &x) const{
		return b >= x.b;
	}
} a[2][MAX],b[MAX];
void swaps(struct node *x,struct node *y){
	struct node z;
	z=*x;
	*x=*y;
	*y=z;
	//cout<<(*x).b<<" "<<(*y).b<<endl;
}
void mod(int index,int n){
	if(a[index][n/2]<a[index][n]){
		return ;
	}else{
		swaps(&a[index][n/2],&a[index][n]);
		mod(index,n/2);
	}
}
void push(int index,struct node x){
	a[index][++p[index]]=x;
	mod(index,p[index]);
}
void repair(int index,int n){
	if(2*n>p[index]){
		return ;
	} 
	int mins;
	if(2*n+1>p[index]){
		mins=2*n;
	}else{
		mins=a[index][2*n]<a[index][2*n+1] ? 2*n : 2*n+1;
	}
	if(a[index][n]>a[index][mins]){
		swaps(&a[index][n],&a[index][mins]);
		repair(index,mins);
		return ; 
	}else{
		return ;
	}
}
void pop(int index){
	swaps(&a[index][p[index]--],&a[index][1]);
	repair(index,1);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;ans=0;p[0]=0;p[1]=0;
		have.clear();need.clear();
		cin>>n>>m;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			struct node y={
				x,0
			};
			push(0,y);
		}
		for(int i=0;i<m;i++){
			cin>>b[i].b; 
		}
		for(int i=0;i<m;i++){
			cin>>b[i].c;
			if(b[i].c!=0){
				push(1,b[i]);
			}else{
				need.push_back(b[i].b);
			}
		}
		
		while(p[0]>0&&p[1]>0){
			if(a[0][1]>=a[1][1]){
				struct node x={
					max(a[0][1].b,a[1][1].c),0
				};
				pop(0);
				push(0,x);
				pop(1);
				ans++;
			}else{
				have.push_back(a[0][1].b);
				pop(0);
			}
		}
		while(p[0]>0){
			have.push_back(a[0][1].b);
			pop(0);
		}
		while(p[1]>0){
			need.push_back(a[1][1].b);
			pop(1);
		}
		sort(need.begin(),need.end());
		sort(have.begin(),have.end());
		/*
		for(int i=0;i<have.size();i++){
			cout<<have[i]<<"\t";
		} 
		cout<<endl;
		for(int i=0;i<need.size();i++){
			cout<<need[i]<<"\t";
		} 
		cout<<endl;
		*/
		int j=0;
		for(int i=0;i<need.size();i++){
			while(j<have.size()&&have[j]<need[i]){
				j++;
			}
			if(j<have.size()&&have[j]>=need[i]){
				ans++;
				j++;
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
```

# 思路（贪心）
我们可以发现，如果 $c>0$ 每次用剑杀怪肯定是有收益的，而 $c=0$ 时每次杀怪肯定都是有亏损的。因此我们可以先收益到最大，使得所有剑的最小值都比较大，这样可以杀的怪就更多，然后就可以杀怪最大化了。

那么我们怎么要剑的最小值最大化呢？考虑贪心，如果杀同一只怪不用最小的剑，那么可能就没有最小的剑可以杀了，本来最小的剑有可能变大，但是这样后最小的剑就不会变大了，我们的期望由可能变大到不变，肯定是亏的，因此我们就每次用最小的剑去杀怪，然后继续找最小的去杀怪。

多次找到最小的值，可以用优先队列——二叉堆来实现。