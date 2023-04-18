#include<bits/stdc++.h>
#define N 3000010
using namespace std;
typedef long long ll;
char s[N];
int nl;ll res;
bool ky;
vector<char>ans;
int type;
long long k;
struct suffixautomation{
    int mp[N][30];int fa[N];int ed;int ct;int len[N];long long siz[N];
    long long num[N];
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
        for(int i=al[u];i;i=x[i]){
			dfs(v[i]);
			if(type==1)siz[u]+=siz[v[i]];
		}
    }
    void dfss(int u){
    	for(int i=1;i<=26;++i){
    		if(mp[u][i]){
				if(!num[mp[u][i]])dfss(mp[u][i]);
				num[u]+=num[mp[u][i]];
			}
		}
		num[u]+=siz[u];
	}
	void solve(int u){
		if(k<=0){
			ky=true;
			return;
		}
		for(int i=1;i<=26;++i){
			if(mp[u][i]){
				if(num[mp[u][i]]>=k){
					k-=siz[mp[u][i]];
					putchar((char)('a'+i-1));
					solve(mp[u][i]);
					return;
				}
				else k-=num[mp[u][i]];
			}
		}
	}
}SAM;


int main(){
//	ios::sync_with_stdio(false);
    scanf("%s",s+1);
    int n=strlen(s+1);
    scanf("%d%lld",&type,&k);
    for(nl=1;nl<=n;++nl)SAM.ins(s[nl]-'a'+1);
    SAM.bt();
	SAM.dfs(1);
	SAM.dfss(1);
//	if(SAM.num[1]<k){
//		puts("-1");
//		return 0;
//	};
	SAM.solve(1);
//	puts("");
  	return 0;
}