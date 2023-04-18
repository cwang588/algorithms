#include<bits/stdc++.h>
using namespace std;
bool check(int x){
	while(x){
		if(x%10==7)return false;
		if(x%10==8)return false;
		x/=10;
	}
	return true;
}
int main(){
	int ans=0;
	for(int i=1;i<=100;++i){
		if(check(i))ans+=i;
	}
	cout<<ans<<"\n";
	
	return 0;
}