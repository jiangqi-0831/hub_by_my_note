#include<bits/stdc++.h>
using namespace std;
int a[200050],min1,maxlen,len;
long long counts;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		counts=0;maxlen=0;len=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		min1=a[n-1];
		for(int i=n-2;i>=0;i--){
			if(a[i]>=min1){
				counts+=a[i]-min1;
				len++;
			}else if(a[i]<min1){
				maxlen=maxlen>len?maxlen:len;
				len=0;
			}
			min1=min1<a[i]?min1:a[i];
		}
		maxlen=maxlen>len?maxlen:len;
		cout<<counts+maxlen<<"\n";
	}
	
	return 0;
}
