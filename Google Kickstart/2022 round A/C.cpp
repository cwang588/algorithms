#include<bits/stdc++.h>
using namespace std;
char s[50005];
bool dp[50005][150],usd[150][2];
void init(){
	usd[0][0]=usd[0][1]=true;
	usd[4][0]=true;
	usd[10][0]=true;
	usd[14][0]=true;
	usd[17][0]=true;
	usd[21][0]=true;
	usd[27][0]=true;
	usd[31][0]=true;
	usd[12][1]=true;
	usd[18][1]=true;
	usd[30][1]=true;
	usd[33][1]=true;
	usd[45][1]=true;
	usd[51][1]=true;
	usd[63][1]=true;
	
}
int main(){
	init();
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		memset(dp,0,sizeof(dp));
		dp[0][0]=true;
		int n;
		cin>>n>>(s+1);
		for(int i=1;i<=n;++i){
			for(int j=0;j<=15;++j){
				if(dp[i-1][j]||dp[i-1][j+32]){
					if(s[i]=='0'){
						if((i<=4||!usd[j<<1][0])&&(i<=5||!usd[j<<1][1]))dp[i][j<<1]=true;
					}
					else if(s[i]=='1'){
						if((i<=4||!usd[j<<1|1][0])&&(i<=5||!usd[j<<1|1][1]))dp[i][j<<1|1]=true;
					}
					else{
						if((i<=4||!usd[j<<1][0])&&(i<=5||!usd[j<<1][1]))dp[i][j<<1]=true;
						if((i<=4||!usd[j<<1|1][0])&&(i<=5||!usd[j<<1|1][1]))dp[i][j<<1|1]=true;
					}
				}
			}
			for(int j=16;j<=31;++j){
				if(dp[i-1][j]||dp[i-1][j+32]){
					if(s[i]=='0'){
						if((i<=4||!usd[(j-16)<<1][0])&&(i<=5||!usd[j<<1][1]))dp[i][j<<1]=true;
					}
					else if(s[i]=='1'){
						if((i<=4||!usd[(j-16)<<1|1][0])&&(i<=5||!usd[j<<1|1][1]))dp[i][j<<1|1]=true;
					}
					else{
						if((i<=4||!usd[(j-16)<<1][0])&&(i<=5||!usd[j<<1][1]))dp[i][j<<1]=true;
						if((i<=4||!usd[(j-16)<<1|1][0])&&(i<=5||!usd[j<<1|1][1]))dp[i][j<<1|1]=true;
					}
				}
			}
//			for(int j=0;j<=63;++j)if(dp[i][j])cout<<j<<" ";
//			cout<<"\n";
		}
		bool ky=false;
		for(int i=0;i<=63;++i){
			if(dp[n][i]){
				ky=true;
				break;
			}
		}
		cout<<"Case #"<<Case<<": ";
		if(ky)cout<<"POSSIBLE\n";
		else cout<<"IMPOSSIBLE\n";
	}
	
	return 0;
}