#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,s;
	cin>>x>>s;
	if(x>s)return !printf("0\n");
	int ans=1;
	bool zero=false;
	if(x==s)zero=true;
	while(s){
		if(s&1){
			if(x&1)ans<<=1;
		}
		else{
			if(x&1)return !printf("0");
		}
		x>>=1;
		s>>=1;
	}
	if(zero)--ans;
	cout<<ans<<endl; 
	return 0;
}
