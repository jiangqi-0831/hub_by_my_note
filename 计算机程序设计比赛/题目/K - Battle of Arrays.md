![](assets/K%20-%20Battle%20of%20Arrays/file-20260718180447711.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAX 200050
long long w1[MAX],w2[MAX];
int tot1=0,tot2=0;
void repair(int i,long long *w,int *tot){
	if(2*i>*tot) return ;
	int tar=2*i;
	if(i*2+1<=*tot){
		tar = w[2*i]<w[2*i+1] ? 2*i+1 : 2*i;
	}
	if(w[tar]>w[i]){
		swap(w[tar],w[i]);
		repair(tar,w,tot);
	}
	return ;
	
}
void pop(long long *w,int *tot){
	swap(w[1],w[(*tot)--]);
	repair(1,w,tot);
}
void modify(int i,long long *w,int *tot){
	if(i==1||w[i/2]>w[i]){
		return ;
	}
	swap(w[i/2],w[i]);
	modify(i/2,w,tot);
}
void push(long long x,long long *w,int *tot){
	w[++(*tot)]=x;
	modify(*tot,w,tot);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		tot1=0;tot2=0;
		int n,m,x;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>x;
			push(x,w1,&tot1);
		}
		for(int i=0;i<m;i++){
			cin>>x;
			push(x,w2,&tot2);
		}
		int turn=1;
		while(tot1>0&&tot2>0){
			if(turn==1){
				if(w2[1]>w1[1]){
					w2[1]-=w1[1];
					repair(1,w2,&tot2);
				}else{
					pop(w2,&tot2);
				}
			}else if(turn==-1){
				if(w1[1]>w2[1]){
					w1[1]-=w2[1];
					repair(1,w1,&tot1);
				}else{
					pop(w1,&tot1);
				}
			}
			turn*=-1;
		}
		if(turn==-1){
			cout<<"Alice\n";
		}else{
			cout<<"Bob\n";
		}
	}
	
	
	return 0;
}
```
# 思路讲解
可以发现最优策略就是取最大的x去攻击对方，因此用二叉堆优先队列每次去最大值模拟即可
