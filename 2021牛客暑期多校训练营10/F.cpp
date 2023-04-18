#include<bits/stdc++.h>
using namespace std;
char a[2000005];
struct edge{
	int from,to,nxt;
}e[2000005];
int cnt,Head[1000005],col[1000005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int fa[1000005],tong[1000005],tocol[1000005];
priority_queue<pair<int,int> >q;
vector<pair<int,int> >tmp;
int main(){
	int n,num=0,now;
	cin>>n>>(a+1);
	now=n+1;
	for(int i=1;i<=n;++i)cin>>col[i],++tong[col[i]];
	for(int i=1;i<=n*2;++i){
		if(a[i]=='('){
			++num;
			add(now,num);
			fa[num]=now;
			now=num;
		}
		else now=fa[now];
	}
	for(int i=1;i<=n;++i)if(tong[i])q.push(make_pair(tong[i],i));
	bool ky=true;
	for(int i=1;i<=n+1;++i){
		for(int j=Head[i];j;j=e[j].nxt){
			int to=e[j].to;
			if(q.empty())return !printf("NO\n");
			pair<int,int>c=q.top();
			q.pop();
			--c.first;
			tocol[to]=c.second;
			tmp.push_back(c);
		}
		for(auto x:tmp)if(x.first)q.push(x);
		tmp.clear();
	}
	cout<<"YES\n";
	for(int i=1;i<=n;++i)cout<<tocol[i]<<" ";
	return 0;
}
