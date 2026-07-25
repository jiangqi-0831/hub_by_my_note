![](assets/T%20-%20Lost%20Numbers/file-20260725104513345.png)
# 代码
```
#include<bits/stdc++.h>
using namespace std;
vector<int> p{15,42,23,14491};
int ans[7];

int ask(int i,int j){
	cout<<"? "<<i<<" "<<j<<endl;
	int x;
	cin>>x;
	return x;
}

int main(){
	int a1,a2,b1,b2;
	a1=ask(1,2);
	a2=ask(2,3);
	b1=ask(4,5);
	b2=ask(5,6);
	for(int x:p){
		if(a1%x==0&&a2%x==0&&x!=14491){
			ans[2]=x;
			ans[1]=a1/x;
			ans[3]=a2/x;
			break;
		}else if(a1%x==0&&a2%x!=0&&x!=14491){
			ans[1]=x;
			ans[2]=a1/x;
			ans[3]=a2/ans[2];
			break;
		}else if(a1%x!=0&&a2%x==0&&x!=14491){
			ans[3]=x;
			ans[2]=a2/x;
			ans[1]=a1/ans[2];
			break;
		}else if(x==14491){
			ans[1]=512/a2;
			ans[2]=a1/ans[1];
			ans[3]=a2/ans[2];
			break;
		}
	}
	
	for(int x:p){
		if(b1%x==0&&b2%x==0&&x!=14491){
			ans[5]=x;
			ans[4]=b1/x;
			ans[6]=b2/x;
			break;
		}else if(b1%x==0&&b2%x!=0&&x!=14491){
			ans[4]=x;
			ans[5]=b1/x;
			ans[6]=b2/ans[5];
			break;
		}else if(b1%x!=0&&b2%x==0&&x!=14491){
			ans[6]=x;
			ans[5]=b2/x;
			ans[4]=b1/ans[5];
			break;
		}else if(x==14491){
			ans[4]=512/b2;
			ans[5]=b1/ans[4];
			ans[6]=b2/ans[5];
			break;
		}
	}
	cout<<"! ";
	for(int i=1;i<=6;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
```


# 思路
和U题一样，先要得到其中之一，然后再推理其他的。
然后发现只能询问四次，然后任选两个时，这两个是没有互异性的，因此我们只能对两个数字多次选择。

那么我们就可以分为前后两段，可以先询问（1，2）和（2，3），只要2确定了，那么1，3也可以确定了。

然后观察给我们的数据，肯定别有心意，可以发现15 23 42都有一个别人没有的因数，分别是5 23 7.因此我们判断是否（1，2）与（2，3）是否都是其中某一个的倍数，那么答案就出来的。但是考虑极端情况，要是刚好1 2 3 都没有呢，那么剩下的都是2的倍数，并且成绩固定，那么就用总乘积来算1 3，然后2就可以出来了。