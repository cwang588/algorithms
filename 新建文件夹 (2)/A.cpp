#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
long long p[100005],s[100005];
long long Min[100005];
vector<long long>v;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(p,0,sizeof(p));
		memset(s,0,sizeof(s));
		memset(Min,0x3f,sizeof(Min));
		v.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld%lld",&s[i],&p[i]);
			Min[i]=s[i]*p[i];
			v.push_back(s[i]); 
		}
		for(int i=n-1;i>=1;--i)
			Min[i]=min(Min[i],Min[i+1]);
		for(int i=1;i<=m;++i)
		{
			int q;
			scanf("%d",&q);
			vector<long long>::iterator it=lower_bound(v.begin(),v.end(),q);
			int num1=it-v.begin()+1,num2=it-v.begin();
			if(v[num1]==q)
				++num2;
			if(num1==n+1)
				printf("%lld\n",(long long)q*p[num2]);
			else
				printf("%lld\n",min((long long)q*p[num2],Min[num1]));
		}
	}
	return 0;
}
