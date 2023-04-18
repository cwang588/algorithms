#include<bits/stdc++.h>
using namespace std;
unsigned long long k1, k2 ,mod;
unsigned long long rng() 
{
    unsigned long long k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
int a[100005],b[100005];
unordered_map<int,int>c,q;
unordered_map<int,bool>mm;
vector<int>v;
bool cmp(int x,int y)
{
	return c[x]+q[x]>c[y]+q[y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		q.clear(); 
		c.clear();
		v.clear();
		mm.clear();
		int n,m,p;
		cin>>n>>m>>p;
		if(p==1)
		{
			for(int i=1;i<=n;++i)cin>>a[i];
			for(int i=1;i<=m;++i)cin>>b[i];
		}
		else
		{
			cin>>k1>>k2>>mod;
			for(int i=1;i<=n;++i)a[i]=rng()%mod;
			cin>>k1>>k2>>mod;
			for(int i=1;i<=m;++i)b[i]=rng()%mod;
		}
		for(int i=1;i<=n;++i)++c[a[i]];
		for(int i=1;i<=m;++i)
		{
			++q[b[i]];
			if(q[b[i]]==1&&c[b[i]])
			{
				v.push_back(b[i]);
				mm[b[i]]=true;
			}
		}
		sort(v.begin(),v.end(),cmp);
		int now=0;
		long long ans1=0,ans2=0;
		for(auto it=v.begin();it!=v.end();++it)
		{
			if(now%2)ans2+=q[*it];
			else ans1+=c[*it];
			++now;
		}
		for(int i=1;i<=n;++i)if(!mm[a[i]])++ans1;
		for(int i=1;i<=m;++i)if(!mm[b[i]])++ans2;
		if(ans1>ans2)cout<<"Cuber QQ\n";
		else cout<<"Quber CC\n";		
	}	
	return 0;
}
