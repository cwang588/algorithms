#include<bits/stdc++.h>
using namespace std;
char a[1005],b[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		if(s[0]=='?'){
			int cnt1=0,cnt2=0;
			a[1]='B';b[1]='R';
			for(int i=2;i<=n;++i){
				if(s[i-1]!='?')a[i]=b[i]=s[i-1];
				else{
					if(a[i-1]=='B')a[i]='R';
					else a[i]='B';
					if(b[i-1]=='B')b[i]='R';
					else b[i]='B';
				}
				if(a[i]==a[i-1])++cnt1;
				if(b[i]==b[i-1])++cnt2;
			}
			if(cnt1<=cnt2){
				for(int i=1;i<=n;++i)cout<<a[i];
			}
			else{
				for(int i=1;i<=n;++i)cout<<b[i];
			}
		}
		else{
			a[1]=s[0];
			for(int i=2;i<=n;++i){
				if(s[i-1]!='?')a[i]=s[i-1];
				else{
					if(a[i-1]=='B')a[i]='R';
					else a[i]='B';
				}
			}
			for(int i=1;i<=n;++i)cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
