#include<bits/stdc++.h>
using namespace std;
int n,A,B;
char s[45];
struct half{
	bool usd[25];
	int cnta,cntb;
	bool operator <(const half &x){
		return cnta-cntb<x.cnta-x.cntb;
	}
};
int cnt;
map<pair<int,int>,int>m;
vector<half>v[2005],za[45],zb[45],all;
bool usd[55];
long long quickpower(long long a,long long b,long long p){
	if(b<0)return 0;
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
void dfs(int now){
	if(now==n/2+1){
		int ra=0,rb=0,cnta=0,cntb=0;
		for(int i=1;i<now;++i){
			if(usd[i]){
				++cnta;
				ra=(ra*10+s[i]-'0')%A;
			}
			else{
				++cntb;
				rb=(rb*10+s[i]-'0')%B;
			}
		}
		auto tt=make_pair(ra,rb);
		if(!m[tt]){
			m[tt]=++cnt;
			v[m[tt]].clear();
		}
		half tmp;
		for(int i=1;i<now;++i)tmp.usd[i]=usd[i];
		tmp.cnta=cnta;
		tmp.cntb=cntb;
		v[m[tt]].push_back(tmp);
		za[ra].push_back(tmp);
		zb[rb].push_back(tmp);
		all.push_back(tmp);
		return;
	}
	usd[now]=false;
	dfs(now+1);
	usd[now]=true;
	dfs(now+1);
}
struct answer{
	bool usd[45];
	int cnta,cntb;
}ans;
bool answered;
void update(half l,half r){
	if(!answered||abs(ans.cnta-ans.cntb)>abs(l.cnta+r.cnta-l.cntb-r.cntb)){
		ans.cnta=l.cnta+r.cnta;
		ans.cntb=l.cntb+r.cntb;
		for(int i=1;i<=n/2;++i)ans.usd[i]=l.usd[i];
		for(int i=n/2+1;i<=n;++i)ans.usd[i]=usd[i];
		answered=true;
	}
}
void dfss(int now){
	if(now==n+1){
		int ra=0,rb=0,cnta=0,cntb=0;
		for(int i=n/2+1;i<now;++i){
			if(usd[i]){
				++cnta;
				ra=(ra*10+s[i]-'0')%A;
			}
			else{
				++cntb;
				rb=(rb*10+s[i]-'0')%B;
			}
		}
		int tmpa=quickpower(quickpower(10,cnta-1,A),A-2,A),tmpb=quickpower(quickpower(10,cntb-1,B),B-2,B);
		int ta,tb;
		ta=((-ra)%A+A)%A*tmpa%A;
		tb=((-rb)%B+B)%B*tmpb%B;
		half tmp;
		tmp.cnta=cnta;
		tmp.cntb=cntb;
		if((tmpa==0&&ra!=0)||(tmpb==0&&rb!=0))return;
		if((tmpa==0&&ra==0)||(tmpb==0&&rb==0)){
			if((tmpa==0&&ra==0)&&(tmpb==0&&rb==0)){
				int tpos=lower_bound(all.begin(),all.end(),tmp)-all.begin();
				if(tpos<all.size())update(all[tpos],tmp);
				if(tpos>=1)update(all[tpos-1],tmp);
			}
			else if((tmpa==0&&ra==0)){
				int tpos=lower_bound(zb[tb].begin(),zb[tb].end(),tmp)-zb[tb].begin();
				if(tpos<zb[tb].size())update(zb[tb][tpos],tmp);
				if(tpos>=1)update(zb[tb][tpos-1],tmp);
			}
			else{
				int tpos=lower_bound(za[ta].begin(),za[ta].end(),tmp)-za[ta].begin();
				if(tpos<za[ta].size())update(za[ta][tpos],tmp);
				if(tpos>=1)update(za[ta][tpos-1],tmp);
			}
			return;
		}
		auto tt=make_pair(ta,tb);
		if(!m[tt])return;
		int id=m[tt];
		int pos=lower_bound(v[id].begin(),v[id].end(),tmp)-v[id].begin();
		if(pos<v[id].size()){
			if(!answered||abs(ans.cnta-ans.cntb)>abs(cnta+v[id][pos].cnta-cntb-v[id][pos].cntb)){
				ans.cnta=cnta+v[id][pos].cnta;
				ans.cntb=cntb+v[id][pos].cntb;
				for(int i=1;i<=n/2;++i)ans.usd[i]=v[id][pos].usd[i];
				for(int i=n/2+1;i<=n;++i)ans.usd[i]=usd[i];
				answered=true;
			}
		}
		if(pos>=1){
			--pos;
			if(!answered||abs(ans.cnta-ans.cntb)>abs(cnta+v[id][pos].cnta-cntb-v[id][pos].cntb)){
				ans.cnta=cnta+v[id][pos].cnta;
				ans.cntb=cntb+v[id][pos].cntb;
				for(int i=1;i<=n/2;++i)ans.usd[i]=v[id][pos].usd[i];
				for(int i=n/2+1;i<=n;++i)ans.usd[i]=usd[i];
				answered=true;
			}
		}
		return;
	}
	usd[now]=false;
	dfss(now+1);
	usd[now]=true;
	dfss(now+1);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cnt=0;
		m.clear();
		answered=false;
		for(int i=0;i<=40;++i)za[i].clear(),zb[i].clear();
		all.clear();
		cin>>n>>A>>B>>(s+1);
		dfs(1);
		for(int i=1;i<=cnt;++i)sort(v[i].begin(),v[i].end());
		for(int i=0;i<=40;++i)sort(za[i].begin(),za[i].end()),sort(zb[i].begin(),zb[i].end());
		sort(all.begin(),all.end());
		dfss(n/2+1);
		if(!answered||abs(ans.cnta-ans.cntb)==n)cout<<"-1\n";
		else{
			for(int i=1;i<=n;++i){
				if(ans.usd[i])cout<<"R";
				else cout<<"B";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}