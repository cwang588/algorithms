#include<bits/stdc++.h>
using namespace std;
char s[200005];
int a[6][200005];
int main(){
	int n,m;
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		if(s[i]!='a'+(i%3))++a[1][i];
		if(s[i]!='a'+(i%3+1)%3)++a[2][i];
		if(s[i]!='a'+(i%3+2)%3)++a[3][i];
		if(s[i]!='a'+(3-i%3)%3)++a[4][i];
		if(s[i]!='a'+(3-i%3+1)%3)++a[5][i];
		if(s[i]!='a'+(3-i%3+2)%3)++a[0][i];
		for(int j=0;j<6;++j)a[j][i]+=a[j][i-1];
	}
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		int ans=2147483647;
		for(int j=0;j<6;++j)ans=min(ans,a[j][r]-a[j][l-1]);
		cout<<ans<<endl;
	}
	return 0;
}
