#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int num;
		if(n%4==0){
			num=3;
			for(int i=1;i<=n/4-1;++i)num+=4;
			cout<<num<<"\n";
			cout<<"001";
			for(int i=1;i<=n/4-1;++i)cout<<"1001";	
		}
		else if(n%4==1){
			num=1;
			for(int i=1;i<=n/4;++i)num+=4;
			cout<<num<<"\n";
			cout<<"1";
			for(int i=1;i<=n/4;++i)cout<<"1001";	
		}
		else if(n%4==2){
			num=4;
			for(int i=1;i<=n/4;++i)num+=4;
			cout<<num<<"\n";
			cout<<"0001";
			for(int i=1;i<=n/4;++i)cout<<"1001";
		}
		else{
			num=2;
			for(int i=1;i<=n/4;++i)num+=4;
			cout<<num<<"\n";
			cout<<"01";
			for(int i=1;i<=n/4;++i)cout<<"1001";
		}
		cout<<endl;
	}
	return 0;
}
