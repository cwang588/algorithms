#include<bits/stdc++.h>
#define int long long 
using namespace std;
char s[]={')','!','@','#','$','%','^','&','*','('};
char ans[350005];
char a[10005],b[10005];
long long getnum(char x){
	for(int i=0;i<=9;++i)if(s[i]==x)return i;
	return 0;
}
void print(long long now){
	int cnt=0;
	if(!now){
		cout<<")"<<endl;
		return;
	}
	bool ky=false;
	if(now<0){
		ky=true;
		now*=-1ll;
	}
	while(now){
		ans[++cnt]=s[now%10ll];
		now/=10ll;
	}
	if(ky)cout<<'-';
	bool yd=false;
	for(int i=cnt;i>=1;--i){
		if(ans[i]!=')'){
			yd=true;
			cout<<ans[i];
		}
		else{
			if(yd)cout<<ans[i];
		}
	}
	cout<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--){
	//	string s1,s2;
		cin>>a>>b;
		long long num1=0,num2=0;
		int n=strlen(a),m=strlen(b);
		bool ky1=false,ky2=false;
		for(int i=0;i<n;++i){
			if(a[i]=='-'){
				ky1=true;
				continue;
			}
			num1=num1*10ll+getnum(a[i]);
		}
		if(ky1)num1*=-1ll;
		for(int i=0;i<m;++i){
			if(b[i]=='-'){
				ky2=true;
				continue;
			} 
			num2=num2*10ll+getnum(b[i]);
		}
		if(ky2)num2*=-1ll;
		print(num1+num2);
		print(num1-num2);
		print(num2-num1);
	}
	return 0;
}
