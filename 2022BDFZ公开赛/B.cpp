#include<bits/stdc++.h>
using namespace std;
char s[100005];
long long sum[35*35];
int num[35*35];
int getid(int x,int y){
	return x*30+y;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	cin>>(s+1);
	int cnta=0,cntb=0;
	long long ans=0;
	num[0]=1;
	for(int i=1;i<=n;++i){
		if(s[i]=='a')++cnta,cnta%=30;
		else ++cntb,cntb%=30;
		for(int j=cnta;j<cnta+30;j+=2){
			for(int k=cntb;k<cntb+30;k+=3){
				int nowx=j%30,nowy=k%30;
				if(((cnta-nowx)-(cntb-nowy))%5)continue;
				int nowid=getid(nowx,nowy);
				ans+=1ll*num[nowid]*i-sum[nowid];
			}
		}
		int id=getid(cnta,cntb);
		++num[id];
		sum[id]+=i;
	}
	cout<<ans<<"\n";
	return 0;
}