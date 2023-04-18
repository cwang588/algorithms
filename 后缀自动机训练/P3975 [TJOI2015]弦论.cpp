#include<bits/stdc++.h>
#define N 500005
using namespace std;
char s[N];
int nl;
string ans;
struct suffixautomation{
    int mp[N][30];int fa[N];int ed;int ct;int len[N];int siz[N];
    suffixautomation(){ed=ct=1;}
    int v[N];int x[N];int al[N];int cnt;
    inline void add(int u,int V){v[++cnt]=V;x[cnt]=al[u];al[u]=cnt;}
    inline void ins(int c){
        int p=ed;siz[ed=++ct]=1;len[ed]=nl;
        for(;p&&mp[p][c]==0;p=fa[p]){mp[p][c]=ed;}
        if(p==0){fa[ed]=1;return;}int q=mp[p][c];
        if(len[p]+1==len[q]){fa[ed]=q;return;}
        len[++ct]=len[p]+1;
        for(int i=1;i<=26;i++){mp[ct][i]=mp[q][i];}
        fa[ct]=fa[q];fa[q]=ct;fa[ed]=ct;
        for(int i=p;mp[i][c]==q;i=fa[i]){mp[i][c]=ct;}
    }
    void bt(){for(int i=2;i<=ed;++i)add(fa[i],i);}
    void dfs(int now){
    	for(int i=al[now];i;i=x[i]){
    		dfs(v[i]);
    		siz[now]+=siz[v[i]];
		}
	}
}SAM;
bool usd[N];
long long sum[N];
void dfs(int now){
	if(usd[N])return;
	for(int i=1;i<=26;++i){
		if(SAM.mp[now][i]){
			dfs(SAM.mp[now][i]);
			sum[now]+=sum[SAM.mp[now][i]];
		}
	}
	usd[now]=true;
}
int main(){
	cin>>(s+1);
	int t,k,n=strlen(s+1);
	cin>>t>>k;
	for(nl=1;nl<=n;++nl)SAM.ins(s[nl]-'a'+1);
	if(t==0){
		for(int i=1;i<=SAM.ed;++i)sum[i]=SAM.siz[i]=1;
	}
	else{
		SAM.dfs(1);
	}
	dfs(1);
	++k;
	if(sum[1]<k)return !printf("-1\n");
	int now=1;
	while(now!=SAM.ed){
		if(!k)break;
		for(int i=1;i<=26;++i){
			int to=SAM.mp[now][i];
			if(!to)continue;
			if(sum[to]>=k){
				ans+=(char)('a'+i-1);
				now=to;
				break;
			}
			else k-=sum[to];
		}
	}
	cout<<ans<<"\n";
	return 0;
}