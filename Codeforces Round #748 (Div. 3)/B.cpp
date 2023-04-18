#include<bits/stdc++.h>
using namespace std;
char s[25];
int pos[14];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s+1;
		int n=strlen(s+1),last=-1,ans=1000;
		for(int i=n;i>=1;--i){
			if(s[i]=='0'){
				if(last<0){
					last=i;
					continue;
				}
			}
			if(s[i]=='5'||s[i]=='0'){
				if(last>0){
					ans=min(ans,n-i-1);
					break;
				}
			}
		}
		last=-1;
		for(int i=n;i>=1;--i){
			if(s[i]=='5')last=i;
			if(s[i]=='2'||s[i]=='7'){
				if(last>0){
					ans=min(ans,n-i-1);
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}