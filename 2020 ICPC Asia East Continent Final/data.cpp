#include<bits/stdc++.h>
using namespace std;
int prime[]={10006699,10006603,10006463,10001701,10001707,10002661,19260817,49999,49333,98009,97007};
int gcd[]={24,1,512,243,120,125,250};
int cnt1,cnt2;
void get_next(int now){
	long long a=1ll*prime[cnt1]*gcd[now],m=1ll*prime[cnt2]*gcd[now];
	if(a>m)swap(a,m);
	cout<<a<<" "<<m<<endl;
	++cnt2;
	if(cnt2==11){
		++cnt1;
		cnt2=cnt1+1;
	}
}
int main(){
	for(int i=0;i<7;++i){
		cnt1=0;
		cnt2=1;
		string s=to_string(i+14)+".in";
		char buf[15];
		strcpy(buf,s.c_str());
		freopen(buf,"w",stdout);
		for(int j=1;j<=50;++j)get_next(i);
	}
	return 0;
}
