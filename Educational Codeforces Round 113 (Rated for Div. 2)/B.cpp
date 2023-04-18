#include<bits/stdc++.h>
using namespace std;
char s[55],ans[55][55];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0;
		cin>>n>>(s+1);
		for(int i=1;i<=n;++i){
			if(s[i]=='1')continue;
			++cnt;
		}
		if(cnt==2||cnt==1){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=1;i<=n;++i){
			bool ky=false;
			for(int j=1;j<=n;++j){
				if(i==j)ans[i][j]='X';
				else if(i>j){
					if(ans[j][i]=='=')ans[i][j]=ans[j][i];
					else if(ans[j][i]=='+')ans[i][j]='-';
					else ans[i][j]='+';
				}
				else if(s[i]=='2'&&s[j]=='2'){
					if(!ky){
						ans[i][j]='+';
						ky=true;
					}
					else ans[i][j]='-';
				}
				else ans[i][j]='=';
				cout<<ans[i][j];
			}
			cout<<"\n";
		}
	}
	return 0;
}
