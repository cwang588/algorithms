#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x=0;
	long long Max=0;
	for(int i=1;i*2<=n;++i){
		if(1ll*i*(n-2*i)>Max){
			Max=1ll*i*(n-2*i);
			x=i;
		}
	}
	cout<<n-x<<" "<<Max<<"\n";
	for(int i=1;i<=x;++i)cout<<"2 ";
	for(int i=1;i<=n-x*2;++i)cout<<"1 ";
	return 0;
}