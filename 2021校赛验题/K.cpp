#include<bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	int n;
	cin>>n>>s+1;
	int ans=0;
	for(int i=1;i<=n;++i){
		if(s[i]!='.')continue;
		int cnt=0;
		if(s[i+1]==s[i-1])continue;
		bool ky1=false,ky2=true;
		if(s[i+1]=='B'){
			for(int j=i-1;j>=1;--j){
				if(s[j]!='W'){
					if(s[j]=='B')ky2=false;
					break;
				}
			}
			for(int j=i+1;j<=n;++j){
				if(s[j]=='B')++cnt;
				else{
					if(s[j]=='W')ky1=true;
					break;
				}
			}
		}
		else {
			for(int j=i+1;j<=n;++j){
				if(s[j]!='W'){
					if(s[j]=='B')ky2=false;
					break;
				}
			}
			for(int j=i-1;j>=1;--j){
				if(s[j]=='B')++cnt;
				else{
					if(s[j]=='W')ky1=true;
					break;
				}
			}
		}
		if(ky1&&ky2)ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
