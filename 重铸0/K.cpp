#include<bits/stdc++.h>
using namespace std;
char s[300005];
int ans[300005];
void flip(int id){
	if(s[id]=='0')s[id]='1';
	else s[id]='0';
	if(s[id+1]=='0')s[id+1]='1';
	else s[id+1]='0';
}
int main(){
	cin>>(s+1);
	int n=strlen(s+1),cnt=0;
	if(n==3){
		if(s[1]==s[2]&&s[1]==s[3])cout<<"1\n1";
		else cout<<"0\n";
		return 0;
	}
	bool ky1=false,ky2=false;
	for(int i=1;i<=n;i+=3){
		if(s[i]==s[i+1]&&s[i+1]==s[i+2]){
			if(i==1){
				if(s[3]==s[4])ans[++cnt]=2,flip(2);
				else ans[++cnt]=1,flip(1);
				continue;
			}
			else if(i==n-2){
				if(s[i-1]==s[i])ans[++cnt]=i,flip(i);
				else ans[++cnt]=i+1,flip(i+1);
				continue;
			}
			else{
				if(s[i]!=s[i-1]&&s[i+2]!=s[i+3])continue;
				else if(s[i]!=s[i-1])ans[++cnt]=i+1,flip(i+1);
				else if(s[i+2]!=s[i+3])ans[++cnt]=i,flip(i);
				else ans[++cnt]=i,flip(i);
			}
		}
		else if(s[i]==s[i+1]&&s[i+1]!=s[i+2])ans[++cnt]=i+1,flip(i+1);
		else if(s[i]!=s[i+1]&&s[i+1]==s[i+2])ans[++cnt]=i,flip(i);
		else;
	}
	cout<<cnt<<endl; 
	for(int i=1;i<=cnt;++i)cout<<ans[i]<<" ";
	return 0;
}
