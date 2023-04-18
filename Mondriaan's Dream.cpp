#include<bits/stdc++.h>
using namespace std;
bool usd[1<<20];
long long dp[1<<20][2];
void init(int m){
	for(int i=0;i<(1<<m);++i){
		int now=0,tmp=i;
		usd[i]=true;
		for(int j=1;j<=m,tmp;++j){
			if(tmp&1)now^=1;
			else{
				if(now){
					usd[i]=false;
					break;
				}
				now=0;
			}
			tmp>>=1;
		}
		if(now)usd[i]=false;
	//	cout<<i<<":"<<usd[i]<<"\n";
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	while(n){
		init(m);
		memset(dp,0,sizeof(dp));
		dp[(1<<m)-1][0]=1;
		for(int i=0;i<n;++i){
//			cout<<i<<"\n";
			for(int j=0;j<(1<<m);++j)dp[j][(i+1)&1]=0;
			for(int j=0;j<(1<<m);++j){
				if(!dp[j][i&1])continue;
				dp[(~j)&((1<<m)-1)][(i+1)&1]+=dp[j][i&1];
		//		cout<<j<<"->"<<((~j)&((1<<m)-1))<<"\n";
				for(int k=j;k;k=(k-1)&j){
					if(usd[k]){
	//					cout<<k<<" "<<j<<" "<<((~(k^j))&((1<<m)-1))<<"\n";
						dp[(~(k^j))&((1<<m)-1)][(i+1)&1]+=dp[j][i&1];
					//	cout<<j<<"->"<<((~(k^j))&((1<<m)-1))<<"\n";
					}
				}
			}
		}
		cout<<dp[(1<<m)-1][n&1]<<"\n";
		cin>>n>>m;
	}
	return 0;
}