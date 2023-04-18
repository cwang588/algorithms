#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[200005];
signed main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n>>s+1;
		int m=strlen(s+1);
		bool flg=false;
		for(int i=2;i<=m;i++) if(s[i]!=s[i-1]) flg=true;
		if(!flg){
			cout<<n<<"\n";
			continue;
		}
		long long ans=n*n;
		ans-=n-1;
		long long D=0,R=0;
		for(int i=2;i<=m;i++){
			if(s[i]!=s[i-1]){
				for(int j=m;j>=i;j--){
					if(s[j]=='R'){
						ans-=D;
						R++;
					}else{
						ans-=R;
						D++;
					}
				}
				break;
			}
			else ans-=n-1;
		}
		cout<<ans<<"\n";
	}
}