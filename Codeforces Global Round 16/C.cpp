#include<bits/stdc++.h>
using namespace std;
bool usd[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string a,b;
		cin>>n>>a>>b;
		int cnt=0,ans=0;
		for(int i=1;i<=n;++i){
			usd[i]=false;
			if(a[i-1]!=b[i-1])ans+=2;
			else{
				if(a[i-1]=='0')++cnt;
				else;
			}
		}
		ans+=cnt;
		for(int i=1;i<=n;++i){
			if(a[i-1]=='1'&&b[i-1]=='1'){
				bool ky=false;
				if(i>=2){
					if(a[i-2]=='0'&&b[i-2]=='0'&&!usd[i-1]){
						usd[i-1]=true;
						++ans;
						ky=true;
					}
				}
				if(!ky){
					if(i<n){
						if(a[i]=='0'&&b[i]=='0'){
							usd[i+1]=true;
							++ans;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
