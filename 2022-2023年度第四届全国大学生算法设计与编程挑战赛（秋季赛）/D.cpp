#include<bits/stdc++.h>
#define N 8000010
using namespace std;
typedef long long ll;
char s[N];
int nl;ll res;
struct suffixautomation{
    int mp[N][30];int fa[N];int ed;int ct;int len[N];int siz[N];
    suffixautomation(){ed=ct=1;}
    int v[N];int x[N];int al[N];int cnt;
    long long dp[N];
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
    long long dfs(int u){
       	if(dp[u])return dp[u];
    	dp[u]=1;
    	for(int i=1;i<=26;++i){
    		if(mp[u][i])dp[u]+=dfs(mp[u][i]);
		}
		return dp[u];
	}
}SAM;
int main(){
    cin>>(s+1);
    int n=strlen(s+1);
    for(nl=1;nl<=n;++nl)SAM.ins(s[nl]-'a'+1);
    SAM.dfs(1);printf("%lld",SAM.dp[1]-1);return 0;
}