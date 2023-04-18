#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		long long a=0,b=0;
		for(int i=0;i<s.length();++i){
			if(i%2==0)a=a*10+s[i]-'0';
			else b=b*10+s[i]-'0';
		}
		long long ans=(a+1)*(b+1)-2;
//		if(a%2==0&&b%2==0)--ans;
		cout<<ans<<endl;
	}
	return 0;
}
