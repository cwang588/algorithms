#include<bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
//	freopen("15675.in","r",stdin);
	//freopen("15675.out","w",stdout);
	cin>>(s+1);
	char t;
	cin>>t;
	int n=strlen(s+1);
	for(int i=1;i<=n;++i){
		if(s[i]==t)cout<<'#';
		else cout<<s[i];
	}
	return 0;
}
