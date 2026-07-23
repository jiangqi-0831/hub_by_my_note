![](assets/C%20-%20Skibidi%20Table/file-20260723130038321.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
long long pow2[MAXN];
void pow2s(){
	pow2[0]=1;
	for(int i=1;i<MAXN;i++){
		pow2[i]=pow2[i-1]*2;
	}
}

int main(){
	pow2s();
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n;
		cin>>q;
		while(q--){
			string op;
			cin>>op;
			if(op=="->"){
				long long x,y,ans=0;
				cin>>x>>y;
				for(int k=n-1;k>=0;k--){
					//cout<<k<<" ";
					long long a=(x-1)/pow2[k],b=(y-1)/pow2[k];
					//cout<<a<<" "<<b<<"\n";
					if(a==0&&b==0){
						ans+=0*pow2[2*k];
					}else if(a==0&&b==1){
						ans+=3*pow2[2*k];
						y-=pow2[k];
					}else if(a==1&&b==0){
						ans+=2*pow2[2*k];
						x-=pow2[k];
					}else if(a==1&&b==1){
						ans+=1*pow2[2*k];
						x-=pow2[k];
						y-=pow2[k];
					}
				}
				cout<<ans+1<<"\n";
			}else if(op=="<-"){
				long long d,x=0,y=0;
				cin>>d;
				for(int k=n-1;k>=0;k--){
					switch((d-1)/pow2[2*k]){
						case 0:
							x+=0;
							y==0;
							break;
						case 1:
							x+=pow2[k];
							y+=pow2[k];
							break;
						case 2:
							x+=0;
							y+=pow2[k];
							break;
						case 3:
							x+=pow2[k];
							y+=0;
							break;
					}
					d = (d-1) % pow2[2*k] +1;
				}
				cout<<y+1<<" "<<x+1<<"\n";
			}else{
				cout<<"error\n";
			}
		}
		
		
		
		
		
		
	}
	
	
	
	return 0;
}
```
# 思路
其实是一个四进制编码，这个排列方法是递归。

因此每次将方阵四分块，然后去判断是在哪个分块，就加上对应分块前面点的数量，然后递归即可。

但是我们这个递归似乎不太好写，那就直接从最大 $n-1$ 遍历就行