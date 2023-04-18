#include<bits/stdc++.h>
using namespace std;
char s[200005];
int main(){
	int n;
	cin>>n>>(s+1);
	int ans=0;
	for(int i=1;i<=n;i+=2){
		if(s[i]=='a'&&s[i+1]=='a'){
			s[i]='b';
			++ans;
		}
		if(s[i]=='b'&&s[i+1]=='b'){
			s[i]='a';
			++ans;
		}
	}	
	cout<<ans<<"\n";
	cout<<(s+1)<<"\n";
	return 0;
}