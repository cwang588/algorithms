#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>m;
const long long mod=1000000007;
long long dp[65][6];
void init(){
	m["white"]=0;
	m["green"]=1;
	m["red"]=2;
	m["orange"]=3;
	m["blue"]=4;
	m["yellow"]=5;
	for(int i=0;i<6;++i)dp[1][i]=1;
	for(int i=2;i<=60;++i){
		long long tot=0;
		for(int j=0;j<6;++j)tot+=dp[i-1][j];
		tot%=mod;
		for(int j=0;j<6;++j){
			dp[i][j]=(tot-dp[i-1][j]-dp[i-1][j])*(tot-dp[i-1][j]-dp[i-1][j])%mod;
		}
	}
}
struct node{
	long long a;
	string b;
}T[2006];
unordered_map<long long,long long>f[6];
unordered_map<long long,bool>usd,tmpusd;
int work(long long n){
	for(int i=0;;++i){
		if((1<<i)>n)return i;
	}
}
long long calc(long long x,long long y){
	int i=work(x),j=work(y);
	long long re=0;
	for(int k=1;k<=min(i,j);++k){
		if(((x&(1<<(i-k)))==0)!=((y&(1<<(j-k)))==0))return re;
		re=re*2+((x&(1<<(i-k)))!=0?1:0);
	}
	return re;
}
vector<long long>v;
unordered_map<long long,int>col;
int main(){
	ios::sync_with_stdio(false);
	init();
	int k,n;
	cin>>k>>n;
	if(k==1&&n==1)return !printf("1\n");
	for(int i=1;i<=n;++i){
		cin>>T[i].a>>T[i].b;
		col[T[i].a]=m[T[i].b]+1;
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			long long now=calc(T[i].a,T[j].a);
			usd[now]=true;
			tmpusd[now]=true;
			v.push_back(now);
		}
	}
	v.push_back(1);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	reverse(v.begin(),v.end());
	for(int i=1;i<=n;++i){
		long long now=T[i].a;
		if(tmpusd[now])continue;
		long long tot=0;
		int h=work(now);
		if(h==k)f[m[T[i].b]][now]=1;
		else{
			for(int j=0;j<6;++j)tot+=dp[k-h][j];
			tot%=mod;
			f[m[T[i].b]][now]=(tot-dp[k-h][m[T[i].b]]-dp[k-h][5-m[T[i].b]])*(tot-dp[k-h][m[T[i].b]]-dp[k-h][5-m[T[i].b]])%mod;
		}
		usd[now]=true;
		now>>=1;
		while(!usd[now]){
			usd[now]=true;
			long long tot1=0,tot2=0;
			if(usd[now<<1]){
				for(int j=0;j<6;++j)tot1+=f[j][now<<1];
			}
			else{
				h=work(now);
				for(int j=0;j<6;++j)tot1+=dp[k-h][j];
			}
			if(usd[now<<1|1]){
				for(int j=0;j<6;++j)tot2+=f[j][now<<1|1];
			}
			else{
				h=work(now);
				for(int j=0;j<6;++j)tot2+=dp[k-h][j];
			}
			for(int j=0;j<6;++j){
				long long tmp1=tot1,tmp2=tot2;
				if(usd[now<<1]){
					tmp1-=f[j][now<<1]+f[5-j][now<<1];
				}
				else{
					h=work(now);
					tmp1-=dp[k-h][j]+dp[k-h][5-j];
				}
				if(usd[now<<1|1]){
					tmp2-=f[j][now<<1|1]+f[5-j][now<<1|1];
				}
				else{
					h=work(now);
					tmp2-=dp[k-h][j]+dp[k-h][5-j];
				}
				f[j][now]=tmp1*tmp2%mod;
			}
			now>>=1;
		}
	}
		for(auto now:v){
			int h;
			while(1){
				usd[now]=true;
				long long tot1=0,tot2=0;
				if(usd[now<<1]){
					for(int j=0;j<6;++j)tot1+=f[j][now<<1];
					tot1%=mod;
				}
				else{
					h=work(now);
					for(int j=0;j<6;++j)tot1+=dp[k-h][j];
				}
				if(usd[now<<1|1]){
					for(int j=0;j<6;++j)tot2+=f[j][now<<1|1];
				}
				else{
					h=work(now);
					for(int j=0;j<6;++j)tot2+=dp[k-h][j];
				}
				for(int j=0;j<6;++j){
					long long tmp1=tot1,tmp2=tot2;
					if(usd[now<<1]){
						tmp1-=f[j][now<<1]+f[5-j][now<<1];
						tmp1%=mod;
					}
					else{
						h=work(now);
						tmp1-=dp[k-h][j]+dp[k-h][5-j];
						tmp1%=mod;
					}
					if(usd[now<<1|1]){
						tmp2-=f[j][now<<1|1]+f[5-j][now<<1|1];
						tmp2%=mod;
					}
					else{
						h=work(now);
						tmp2-=dp[k-h][j]+dp[k-h][5-j];
						tmp2%=mod;
					}
					f[j][now]=tmp1*tmp2%mod;
				}
				if(col[now]){
					for(int j=0;j<6;++j)if(j!=col[now]-1)f[j][now]=0;
				}
				if(now==1)break;
				now>>=1;
				if(usd[now])break;
			}
		}
	long long ans=0;
	for(int i=0;i<6;++i)ans+=f[i][1];
	ans=(ans%mod+mod)%mod;
	cout<<ans<<"\n";
	return 0;
}