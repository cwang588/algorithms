#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("1577.in","r",stdin);
//	freopen("1577.out","w",stdout);
	int Max=0;
	string tmp,ans;
	while(cin>>tmp){
		int n=tmp.length();
		bool ky=false;
		if(tmp[n-1]=='.')--n,ky=true;
		if(n>Max){
			Max=n;
			ans=tmp;
		}
		if(ky)break;
	}
	for(int i=0;i<Max;++i)cout<<ans[i];
	return 0;
}
