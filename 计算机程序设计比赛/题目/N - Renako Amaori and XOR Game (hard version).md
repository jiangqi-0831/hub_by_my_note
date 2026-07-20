![](assets/未命名/file-20260720194730284.png)

# 代码 
```
#include<bits/stdc++.h>
using namespace std;
#define MAX 200050
long long a[MAX],b[MAX],c[MAX],sum;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sum=0;
		for(int i=0;i<n;i++){
			c[i]=a[i]^b[i];
			sum=sum^c[i];
			//cout<<sum<<" "<<c[i]<<" "<<a[i]<<" "<<b[i]<<"\n"; 
		}
		if(sum==0){
			cout<<"Tie\n";
		}else{
			int k=0,max1=0;
			while(sum!=0){
				k++;
				sum/=2;
			}
			max1=1;
			max1=max1<<(k-1); 
			//cout<<k<<" "<<max1<" "; 
			for(int i=n-1;i>=0;i--){
				if((c[i]&max1)!=0){
					if(i%2==1){
						cout<<"Mai\n";
					}else{
						cout<<"Ajisai\n";
					}
					break; 
				}
				//cout<<c[i]<<" "; 
			}
		}	
	}
	return 0;
}
```

# 思路
又是XOR，