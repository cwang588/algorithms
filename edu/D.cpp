#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
namespace MillerRabin {
	long long Mul(long long a,long long b,long long mo){
		long long tmp=a*b-(long long)((long double)a/mo*b+1e-8)*mo;
		return (tmp%mo+mo)%mo;
	}

	long long Pow(long long a,long long b,long long mo){
		long long res=1;
		for(;b;b>>=1,a=Mul(a,a,mo))
			if(b&1)
				res=Mul(res,a,mo);
		return res;
	}

	bool IsPrime(long long n){
		if(n==2)return 1;
		if(n<2||!(n&1))return 0;
		vector<int> tester={2,3,5,7,11,13,17,19,23};
		long long x=n-1;int t=0;
		for(;!(x&1);x>>=1)++t;
		for(auto p : tester) {
			long long a=p%(n-1)+1,res=Pow(a%n,x,n),last=res;
			for(int j=1;j<=t;++j){
				res=Mul(res,res,n);
				if(res==1&&last!=1&&last!=n-1)return 0;
				last=res;
			}
			if(res!=1)return 0;
		}
		return 1;
	}
}

namespace PollardRho {
	using namespace MillerRabin;
	unsigned long long seed;
	
	long long Rand(long long mo){
		return (seed+=4179340454199820289ll)%mo;
	}
	
	long long F(long long x,long long c,long long mo){
		return (Mul(x,x,mo)+c)%mo;
	}
	
	long long gcd(long long a,long long b){
		return b?gcd(b,a%b):a;
	}

	long long Get(long long c,long long n){
		long long x=Rand(n),y=F(x,c,n),p=n;
		for(;x!=y&&(p==n||p==1);x=F(x,c,n),y=F(F(y,c,n),c,n))
			p=x>y?gcd(n,x-y):gcd(n,y-x);
		return p;
	}

	void Divide(long long n,long long p[]){
		if(n<2)return;
		if(IsPrime(n)){p[++*p]=n;return;}
		for(;;){
			long long tmp=Get(Rand(n-1)+1,n);
			if(tmp!=1&&tmp!=n){
				Divide(tmp,p);
				Divide(n/tmp,p);
				return;
			}
		}
	}
}

using namespace PollardRho;
ll ans=0;
ll c,d,x;
ll p[1005];
ll px[1005];
ll pcnt[1005];
unordered_map<ll,bool> mp;
void check(ll c,ll d,ll x,ll g){
	if((x/g+d)%c!=0) return;
	ll l=(x+d*g)/c;
	ll ab=l/g,cnt=0;
	if(mp[ab]) return;
	mp[ab]=true;
	p[0]=0;
	Divide(ab,p);
	sort(p+1,p+p[0]+1);
	p[p[0]+1]=0;
	for(int i=1;i<=p[0];i++) if(p[i]!=p[i+1]) cnt++;
	ans+=(1ll<<cnt);
}
ll qpow(ll a,ll b){
	ll res=1,Pow=a;
	while(b){
		if(b&1) res=res*Pow;
		Pow=Pow*Pow;
		b>>=1;
	}
	return res;
}
void dfs(int now,ll g,int ln){
	if(now==ln+1){
		check(c,d,x,g);
		return;
	}
	for(int i=0;i<=pcnt[now];i++) 
		dfs(now+1,g*qpow(px[now],i),ln);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ans=0;
		mp.clear();
		scanf("%lld%lld%lld",&c,&d,&x);
		if(x%gcd(c,d)){
			printf("0\n");
			continue;
		}
		if(x==1){
			check(c,d,x,1);
			printf("%lld\n",ans);
			continue;
		}
		memset(px,0,sizeof(px));
		memset(pcnt,0,sizeof(pcnt));
		px[0]=0;
		Divide(x,px);
		sort(px+1,px+px[0]+1);
		int ln=1;
		pcnt[ln]=1;
		for(int i=2;i<=px[0];i++){
			if(px[i]!=px[ln]){
				px[++ln]=px[i];
				pcnt[ln]=1;
			}else pcnt[ln]++;
		}
		dfs(1,1,ln);
		printf("%lld\n",ans);
	}
}
