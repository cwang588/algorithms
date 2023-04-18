#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
bool usd[205][205];
int pos[205],rd[100005];
string name[205];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct edge
{
	int from,to,nxt;
}e[200005];
int cnt,Head[105],a[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
//int getid(string x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int s,l,n;
	cin>>s>>l>>n;	
	for(int i=1;i<=s;++i)
	{
		string tmp;
		cin>>tmp;
		m[tmp]=1;
	}
	int tmpnum=0;
	for(auto &x:m)
	{
		x.second+=tmpnum++;
		name[x.second]=x.first;
	}
///	sort(v.begin(),v.end());
//	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=l;++i)
	{
		string tmp1,tmp2;
		cin>>tmp1>>tmp2;
		int x=m[tmp1],y=m[tmp2];
		usd[x][y]=usd[y][x]=true;
	}
	for(int i=1;i<=n;++i)
	{
		string tmp;
		cin>>tmp;
		a[i]=m[tmp];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=s;++j)
		{
			if(usd[a[i]][j]||!pos[j])continue;
			add(pos[j],i);
			++rd[i];
		}
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;++i)if(!rd[i])q.push(make_pair(a[i],i));
	while(!q.empty())
	{
		int now2=q.top().second,now1=q.top().first;
		q.pop();
		if(now1)cout<<name[now1]<<' ';
		for(int i=Head[now2];i;i=e[i].nxt)
		{
			int to=e[i].to;
			--rd[to];
			if(!rd[to])q.push(make_pair(a[to],to));
		}
	}
	//cout<<"\n";
	return 0;
}
