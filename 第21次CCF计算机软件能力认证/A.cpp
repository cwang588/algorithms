#include<bits/stdc++.h>
using namespace std;
int cnt[5];
bool check(int x){
	if(x%7==0)return true;
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		if(check(i)){
			++cnt[i%4];
			++n;
		}
	}
	for(int i=1;i<=3;++i)cout<<cnt[i]<<endl;
	cout<<cnt[0]<<endl;
	return 0;
}
