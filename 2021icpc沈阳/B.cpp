#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt,value;
}e[600005];
int cnt,Head[300005];
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int col[3000005],sz,num,x[200005],y[200005],z[200005];
void dfs(int now){
	++sz;
	if(col[now]==1)++num;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(!col[to]){
			if(e[i].value)col[to]=col[now];
			else col[to]=3-col[now];
			dfs(to);
		}
		else{
			if(e[i].value){
				if(col[to]!=col[now]){
					cout<<"-1";
					exit(0);
				}
			}
			else{
				if(col[to]==col[now]){
					cout<<"-1";
					exit(0);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i]>>z[i];
	}
	long long ans=0;
	for(int j=0;j<30;++j){
		cnt=0;
		memset(Head,0,sizeof(Head));
		memset(col,0,sizeof(col));
		for(int i=1;i<=m;++i){
			if(z[i]&(1<<j)){
				add(x[i],y[i],0);
				add(y[i],x[i],0);
			}
			else{
				add(x[i],y[i],1);
				add(y[i],x[i],1);
			}
		}
		for(int i=1;i<=n;++i){
			if(!col[i]){
				num=sz=0;
				col[i]=1;
				dfs(i);
				ans+=1ll*(1<<j)*min(num,sz-num);
			}
		}
	}
	cout<<ans;
	return 0;
}