#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=998244353;
struct edge{
	int from,to,nxt,value;
}e[200005];
struct edgee{
	int from,to,nxt;
	long long value;	
}ee[200005];
int Head[100005],Headd[100005],cnt,cntt;
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addd(int x,int y,long long z){
	++cntt;
	ee[cntt].from=x;
	ee[cntt].to=y;
	ee[cntt].value=z;
	ee[cntt].nxt=Headd[x];
	Headd[x]=cntt;
}
stack<int>st;
int col[100005],colcnt,dfn[100005],dfncnt,low[100005],value[100005],colvalue[100005];
bool usd[100005];
void tarjan(int now){
	st.push(now);
	usd[now]=true;
	dfn[now]=low[now]=++dfncnt;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(!dfn[to]){
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if(usd[to])low[now]=min(low[now],dfn[to]);
	}
	if(dfn[now]==low[now]){
		int tmp;
		++colcnt;
		do{
			tmp=st.top();
			col[tmp]=colcnt;
			usd[tmp]=false;
			colvalue[colcnt]+=value[tmp];
			st.pop();
		}while(tmp!=now);
	}
}
long long quickpower(long long a,long long b){
		long long re=1,now=a;
		while(b){
			if(b&1)re=re*now%mod;
			now=now*now%mod;
			b>>=1;
		}
		return re;
}
long long dis[100005];
bool usdd[100005];
void dfss(int now){
	usdd[now]=true;
	for(int i=Headd[now];i;i=ee[i].nxt){
		int to=ee[i].to;
		if(usdd[to]){
			if(dis[to]!=dis[now]*ee[i].value%mod){
				printf("NO\n");
				exit(0);
			}
		}
		else{
			dis[to]=dis[now]*ee[i].value%mod;
			dfss(to);
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	//for(int i=1;i<=n;++i)scanf("%d",&value[i]);
	for(int i=1;i<=m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	bool ky=true;
	for(int i=1;i<=m;++i){
		if(col[e[i].from]==col[e[i].to]){
			if(e[i].value!=1){
				ky=false;
				break;
			}
		}
		else{
			addd(col[e[i].from],col[e[i].to],e[i].value%mod);
			addd(col[e[i].to],col[e[i].from],quickpower(e[i].value,mod-2));
		}
	}
	if(!ky)return !printf("NO\n");
	for(int i=1;i<=colcnt;++i){
		if(!usdd[i]){
			dis[i]=1;
			dfss(i);
		}
	}
	printf("YES\n");
	return 0;
}
