#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int num,value[100005],n,k;
long long sum[100005];
bool cmp(long long x,long long y){
	return x>y;
}
bool dfs(int now,int pre,long long tot){
	if(value[now]>tot)return false;
	sum[now]=value[now];
	vector<long long>v;
	long long tmp=value[now];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		if(!dfs(to,now,tot))return false;
		v.push_back(sum[to]);
		tmp+=sum[to];
	}
	sort(v.begin(),v.end(),cmp);
	int pos=0;
	while(tmp>tot){
		tmp-=v[pos++];
		++num;
	}
	if(num>k)return false;
	sum[now]=tmp;
	return true;
}
bool judge(long long tot){
	num=0;
	return dfs(1,0,tot);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		cin>>n>>k;
		--k;
		cnt=0;
		for(int i=1;i<=n;++i)Head[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);		
		}
		for(int i=1;i<=n;++i)cin>>value[i];
		long long l=0,r=10000000000000000ll;
//		long long l=0,r=15;
		while(l<r-1){
			long long m=(l+r)/2;
			if(judge(m))r=m;
			else l=m;
		}
		cout<<"Case #"<<Case<<": "<<r<<"\n";
	}
	return 0;
}