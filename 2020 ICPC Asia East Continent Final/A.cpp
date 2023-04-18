#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=1000005;
int tmpNext[N],tmplast[N],num[63],numm[63],cd0[63][N],cd1[63][N],cd2[63][N],Next[N],last[N];
int tot,totc[63],totd[63];
vector<int>pos[63];
int getid(char t){
	if(t>='A'&&t<='Z')return t-'A'+1;
	if(t>='a'&&t<='z')return t-'a'+27;
	return t-'0'+53;
}
int main(){
	//freopen("in.txt","r",stdin);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;++i){
		int nowid=getid(s[i]);
		pos[nowid].push_back(i); 
		last[i]=Next[i]=tmpNext[i]=tmplast[i]=n+1;
		++numm[nowid];
	}
	for(int i=1;i<=62;++i){
		for(int j=0;j<pos[i].size();++j){
			if(j<pos[i].size()-1)Next[pos[i][j]]=pos[i][j+1];
			if(j>0)last[pos[i][j]]=pos[i][j-1];
		}
	}
	for(int i=1;i<=62;++i)tmpNext[i]=pos[i].size();
	long long ans=0;
	for(int i=n-1;i>=0;--i){
		int nowid=getid(s[i]);
		--tmpNext[nowid];
		++num[nowid];
		--numm[nowid];
		for(int j=1;j<=62;++j){
			if(j==nowid||!pos[j].size())continue;
			ans=(ans+(1ll*tot-totc[nowid]-totc[j]-totd[nowid]-totd[j]+(tmpNext[nowid]<pos[nowid].size()?cd2[j][pos[nowid][tmpNext[nowid]]]:0)+(tmpNext[j]<pos[j].size()?cd2[nowid][pos[j][tmpNext[j]]]:0))*numm[j])%mod;
		}
		tmplast[nowid]=i;
		for(int j=1;j<=62;++j){
			if(j==nowid)continue;
			int next_i=Next[i],cd_1_nowid_tmplast_j=cd1[nowid][tmplast[j]];
			cd0[j][i]=(cd0[j][next_i]+num[j])%mod;
			cd1[j][i]=(cd1[j][next_i]+cd0[nowid][tmplast[j]])%mod;
			cd2[j][i]=(cd2[j][next_i]+cd_1_nowid_tmplast_j)%mod;
			tot=(tot+cd_1_nowid_tmplast_j)%mod;
			totc[nowid]=(totc[nowid]+cd_1_nowid_tmplast_j)%mod;
			totd[j]=(totd[j]+cd_1_nowid_tmplast_j)%mod;
		}
	}
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}
