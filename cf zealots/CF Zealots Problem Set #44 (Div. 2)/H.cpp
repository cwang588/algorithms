#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;	
	if(n<=3){
		if(n==1)cout<<"3\n";
		if(n==2)cout<<"5\n";
		if(n==3)cout<<"7\n";
		return 0;
	}
	n-=3;
	long long ans=7+4*(n/3);
	if(n%3==1)ans+=1;
	else if(n%3==2)ans+=2;
	else;
	cout<<ans<<"\n";
	return 0;
}