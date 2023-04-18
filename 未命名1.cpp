#include<bits/stdc++.h>
using namespace std;
char s[N];
int nl;ll res;
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
    void bt(){for(int i=2;i<=ct;i++){add(fa[i],i);}}
    void dfs(int u){
        for(int i=al[u];i;i=x[i]){dfs(v[i]);siz[u]+=siz[v[i]];}
        if(siz[u]!=1){res=max(res,(ll)siz[u]*len[u]);}
    }
}SAM;
int main(){
	
	
	return 0;
}