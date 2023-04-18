#include<bits/stdc++.h>
using namespace std;
string s[10005];
int main(){
//	freopen("15824.in","r",stdin);
//	freopen("15824.out","w",stdout);
	int n;
	while(cin>>n){
		if(!n)return 0;
		int m=2147483647;
		for(int i=1;i<=n;++i)cin>>s[i];
		for(int i=1;i<=n;++i)m=min(m,(int)s[i].length());
		bool ky=false;
		for(int i=m;i>=1;--i){
			bool tmp=true;
			int tt=s[1].length();
			for(int j=2;j<=n;++j){
				int t=s[j].length();
				for(int k=0;k<i;++k){
					if(s[j][t-1-k]!=s[1][tt-1-k]){
						tmp=false;
						break;
					}
				}
				if(!tmp)break;
			}
			if(tmp){
				ky=true;
				for(int j=i-1;j>=0;--j)cout<<s[1][tt-1-j];
				cout<<"\n";
				break;
			}
		} 
		if(!ky)printf("\n");
	}
	return 0;
}
