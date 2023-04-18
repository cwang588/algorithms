#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=19260817;
namespace MillerRabin{
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
		vector<int> tester={2,3,5,7,11,13,17,19,23,29,31,37};
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
	void Divide(long long n,vector<long long>&p){
		if(n<2)return;
		if(IsPrime(n)){p.push_back(n);return;}
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
long long a[50005];
map<long long,int>m;
int cnt[40005],mi[55],supernum[50005],dp[50005],tmpdp[50005];
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	mi[0]=1;
	for(int i=1;i<=20;++i)mi[i]=mi[i-1]*2;
	for(int Case=1;Case<=t;++Case){
		int n;
		long long x;
		cin>>n>>x;
		for(int i=1;i<=n;++i)cin>>a[i];
		vector<long long>p;
		m.clear();
		memset(supernum,0,sizeof(supernum));
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		if(x==1){
			bool yi=false;
			for(int i=1;i<=n;++i){
				if(a[i]==1){
					yi=true;
					break;
				}
			}
			if(yi)printf("Case %d: 1\n",Case);
			else printf("Case %d: -1\n",Case);
			continue;
		}
		PollardRho::Divide(x,p);
		for(auto y:p)++m[y];
		for(int i=1;i<=n;++i){
			int id=0,micnt=0;
			bool ky=true;
			for(auto y:m){
				long long now=y.first;
				int num=0;
				while(a[i]%now==0){
					++num;
					a[i]/=now;
				}
				if(num>y.second){
					ky=false;
					break;
				}
				if(num==y.second)id+=mi[micnt];
				++micnt;
			}
			if(a[i]>1||!ky)continue;
			++cnt[id];
		}
		for(int i=1;i<=mi[15]-1;++i)if(cnt[i])supernum[i]=1;
		for(int i=mi[15]-1;i>=1;--i){
//			if(!cnt[i])continue;
			for(int j=0;j<=14;++j){
				if((mi[j]&i)==0)continue;
				if(supernum[i]>=1)supernum[i-mi[j]]=2;
			}
		}
		vector<int>v;
		for(int i=1;i<mi[15];++i)if(supernum[i]==1&&cnt[i])v.push_back(i);
		int len=v.size();
		for(int i=1;i<mi[15];++i)tmpdp[i]=inf;
		for(int i=1;i<=len;++i){
			for(int j=1;j<mi[15];++j)dp[j]=tmpdp[j];
			for(int j=0;j<mi[15];++j)tmpdp[v[i-1]|j]=min(tmpdp[v[i-1]|j],dp[j]+1);
		}
		int ansid=mi[m.size()]-1;
		if(tmpdp[ansid]!=inf)printf("Case %d: %d\n",Case,tmpdp[ansid]);
		else printf("Case %d: -1\n",Case);
	}
	
	return 0;
}
