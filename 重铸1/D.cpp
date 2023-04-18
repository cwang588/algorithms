#include<bits/stdc++.h>
using namespace std;
int mi[25];
long long dp[2][1100005],f[2][1100005][25];
bool ky[2][1100005],usd[25],hf[2][1000005][25];
struct graph{
	struct edge{
		int from,to,nxt;
	}e[205];
	int Head[25],cnt,n,rd[25],op;
	set<int>s[25];
	void init(int num,int sb){
		cnt=0;
		op=sb;
		for(int i=1;i<=20;++i)rd[i]=Head[i]=0,s[i].clear();
		n=num;
		for(int i=1;i<mi[n];++i)
			for(int j=1;j<=n;++j){
			{
				hf[op][i][j]=false;
				f[op][i][j]=0;
			}
		}	
		for(int i=1;i<mi[n];++i)ky[op][i]=false,dp[op][i]=0;	
	}
	void add(int x,int y){
		++cnt;
		e[cnt].from=x;
		e[cnt].to=y;
		e[cnt].nxt=Head[x];
		Head[x]=cnt;
		++rd[y];
	}
	void topo(){
		queue<int>q;
		for(int i=1;i<=n;++i){
			if(!rd[i])
				q.push(i);
		}
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int i=Head[now];i;i=e[i].nxt){
				int to=e[i].to;
				s[to].insert(now);
				--rd[to];
				if(!rd[to])q.push(to);
			}
		}
		ky[op][0]=true;
		dp[op][0]=1;
		for(int i=1;i<mi[n];++i){
			for(int j=1;j<=25;++j){
				usd[j]=false;
				if(i&mi[j-1])usd[j]=true;
			}
			bool tmp=true;
			for(int j=1;j<=n;++j){
				if(!usd[j])continue;
				for(auto x:s[j]){
					if(!usd[x]){
						tmp=false;
						goto bkx;
					}
				}
			}
			bkx:ky[op][i]=tmp;
		}
		for(int i=1;i<(1<<n);++i){
			if(!ky[op][i])continue;
			for(int j=1;j<=n;++j){
				if((i&mi[j-1])==0)continue;
				if(!ky[op][i^mi[j-1]])continue;
				dp[op][i]+=dp[op][i^mi[j-1]];
			}
		}
		for(int i=1;i<(1<<n);++i){
			if(!ky[op][i])continue;
			for(int j=1;j<=n;++j){
				if((i&mi[j-1])==0)continue;
				if(!ky[op][i^mi[j-1]])continue;
				f[op][i][j]+=dp[op][i^mi[j-1]];
				hf[op][i][j]=true;
			}
		}
	}
}p,q;
long long ans[25][25];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	mi[0]=1;
	for(int i=1;i<=23;++i)mi[i]=mi[i-1]*2;
	int t;
	cin>>t;
	while(t--){
		memset(ans,0,sizeof(ans));
		int n,m;
		cin>>n>>m;
		p.init(n,0);
		q.init(n,1);
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			p.add(x,y);
			q.add(y,x);
		}
		p.topo();
		q.topo();
		for(int i=1;i<mi[n];++i){
			for(int j=1;j<=n;++j){
				if((i&mi[j-1])==0||!hf[0][i][j]||!hf[1][mi[n]-i-1+mi[j-1]][j])continue;
				for(int k=j+1;k<=n;++k){
					if(k==j||(i&mi[k-1])==0)continue;
					ans[j][k]+=f[0][i][j]*f[1][mi[n]-i-1+mi[j-1]][j];
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i<j)cout<<ans[i][j]<<" ";
				else if(i==j)cout<<"0 ";
				else cout<<dp[0][mi[n]-1]-ans[j][i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
