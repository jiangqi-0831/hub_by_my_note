![](assets/R%20-%20Flamingoes%20of%20Mystery/file-20260725105149672.png)

# 代码
```
#include<bits/stdc++.h>
using namespace std;
#define MAXN 3500
int ans[MAXN];

int ask(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int x;
	cin>>x;
	return x;
}

int main(){
	int n;
	cin>>n;
	int s1,s2,s3;
	s1=ask(1,2);
	s2=ask(2,3);
	s3=ask(1,3);
	ans[1]=s3-s2;
	ans[2]=s1-ans[1];
	ans[3]=s2-ans[2];
	for(int i=3;i+1<=n;i++){
		cout<<"? "<<i<<" "<<i+1<<endl;
		int x;
		cin>>x;
		ans[i+1]=x-ans[i];
	}
	
	cout<<"! ";
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
```
# 思路
和U题一样，只不过不是任意两个，而是连续的数列和。
那么我们对于前三个构造一个这样的方程：
$$
\begin{cases}
x_1 + x_2 + 0 &= a \\
0 + x_2 + x_3 &=b\\
x_1 + x_2 + x_3 &=c
\end{cases}
$$
那么答案就是：
$$
\begin{cases}
x_1&=c-b\\
x_2&=a+b-c\\
x_3&=c-a
\end{cases}
$$

 剩下的就按照顺序，从前往后推理即可。