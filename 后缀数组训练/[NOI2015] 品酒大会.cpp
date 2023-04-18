#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
struct SuffixArray{
	char s[maxn];
	int n,m,lg2[maxn],st[maxn][35],y[maxn],x[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],wt[30];
	void init(){
		memset(c,0,sizeof(c));
    	memset(y,0,sizeof(y)); 
    	memset(x,0,sizeof(x)); 
	}
	void get_SA(){
		n=strlen(s+1);m=256;
		for(int i=1;i<=n;++i)++c[x[i]=s[i]];
	    for(int i=2;i<=m;++i)c[i]+=c[i-1]; 
	    for(int i=n;i>=1;--i)sa[c[x[i]]--]=i; 
	    for(int k=1;k<=n;k<<=1){
	        int num=0;
	        for(int i=n-k+1;i<=n;++i)y[++num]=i;
	        for(int i=1;i<=n;++i)if(sa[i]>k)y[++num]=sa[i]-k; 
	        for(int i=1;i<=m;++i)c[i]=0;
	        for(int i=1;i<=n;++i)++c[x[i]];
	        for(int i=2;i<=m;++i)c[i]+=c[i-1];
	        for(int i=n;i>=1;--i)sa[c[x[y[i]]]--]=y[i],y[i]=0;
	        swap(x,y);
	        x[sa[1]]=1;num=1;
	        for(int i=2;i<=n;++i)x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
	        if(num==n)break;
	        m=num;
	    }
	}
	void get_height(){
	    int k=0;
	    for(int i=1;i<=n;++i)rk[sa[i]]=i;
	    for(int i=1;i<=n;++i){
	        if(rk[i]==1)continue;
	        if(k)--k;
	        int j=sa[rk[i]-1];
	        while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])++k;
	        height[rk[i]]=k;
	    }
	}
	void get_lcp() {
	    lg2[0]=-1;for(int i=1;i<maxn;i++)lg2[i]=lg2[i/2]+1;lg2[0]=0; 
	    for(int i=1;i<=n;i++)st[i][0]=height[i]; 
	    for(int j=1;(1<<j)<=n;j++)
	    	for(int i=1;i+(1<<j)-1<=n;i++)
	    		st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int Lcp(int l,int r) {
		l=rk[l],r=rk[r];
		if(l>r)swap(l,r);l++; 
		int k=lg2[r-l+1]; 
		return min(st[l][k],st[r-(1 << k)+1][k]); 
	}
}SA;
long long a[maxn];
vector<int>pos[maxn];
bool usd[maxn];
int fa[maxn],sz[maxn];
long long Max[maxn][2],Min[maxn][2],ans[maxn][2];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
long long calc(int n){
	return 1ll*n*(n-1)/2;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>SA.s[i];
	for(int i=1;i<=n;++i)cin>>a[i];
	SA.get_SA(),SA.get_height(),SA.get_lcp();
	for(int i=1;i<=n;++i){
		fa[i]=i;
		pos[SA.height[i]].push_back(i);
	}
	long long ans1=0,ans2=-1000000000000000009;
	for(int i=n-1;i>=0;--i){
		for(auto x:pos[i]){
			if(x==1)continue;
			if(!usd[x-1]&&!usd[x]){
				usd[x-1]=usd[x]=true;
				Merge(x,x-1);
				Min[x-1][0]=min(a[SA.sa[x-1]],a[SA.sa[x]]);	
				Min[x-1][1]=max(a[SA.sa[x-1]],a[SA.sa[x]]);	
				Max[x-1][0]=max(a[SA.sa[x-1]],a[SA.sa[x]]);	
				Max[x-1][1]=min(a[SA.sa[x-1]],a[SA.sa[x]]);
				sz[x-1]=2;
				++ans1;
				ans2=max(ans2,a[SA.sa[x-1]]*a[SA.sa[x]]);	
			}
			else if(!usd[x-1]){
				usd[x-1]=true;
				int rt=getfa(x);
				Merge(x-1,rt);
				if(Max[rt][0]<=a[SA.sa[x-1]]){
					Max[rt][1]=Max[rt][0];
					Max[rt][0]=a[SA.sa[x-1]];
				}
				else Max[rt][1]=max(Max[rt][1],a[SA.sa[x-1]]);
				if(Min[rt][0]>=a[SA.sa[x-1]]){
					Min[rt][1]=Min[rt][0];
					Min[rt][0]=a[SA.sa[x-1]];
				}
				else Min[rt][1]=min(Min[rt][1],a[SA.sa[x-1]]);
				ans1+=sz[rt];
				++sz[rt];
				ans2=max(ans2,Max[rt][0]*Max[rt][1]);
				ans2=max(ans2,Min[rt][0]*Min[rt][1]);
			}
			else if(!usd[x]){
				usd[x]=true;
				int rt=getfa(x-1);
				Merge(x,rt);
				if(Max[rt][0]<=a[SA.sa[x]]){
					Max[rt][1]=Max[rt][0];
					Max[rt][0]=a[SA.sa[x]];
				}
				else Max[rt][1]=max(Max[rt][1],a[SA.sa[x]]);
				if(Min[rt][0]>=a[SA.sa[x]]){
					Min[rt][1]=Min[rt][0];
					Min[rt][0]=a[SA.sa[x]];
				}
				else Min[rt][1]=min(Min[rt][1],a[SA.sa[x]]);
				ans1+=sz[rt];
				++sz[rt];
				ans2=max(ans2,Max[rt][0]*Max[rt][1]);
				ans2=max(ans2,Min[rt][0]*Min[rt][1]);
			}
			else{
				int rt1=getfa(x-1),rt2=getfa(x);
				Merge(rt2,rt1);
				ans1+=calc(sz[rt1]+sz[rt2])-calc(sz[rt1])-calc(sz[rt2]);
				sz[rt1]+=sz[rt2];
				vector<int>v;
				for(int i=0;i<=1;++i){
					v.push_back(Max[rt1][i]);
					v.push_back(Max[rt2][i]);
				}
				sort(v.begin(),v.end());
				Max[rt1][0]=v[3];
				Max[rt1][1]=v[2];
				v.clear();
				for(int i=0;i<=1;++i){
					v.push_back(Min[rt1][i]);
					v.push_back(Min[rt2][i]);
				}
				sort(v.begin(),v.end());
				Min[rt1][0]=v[0];
				Min[rt1][1]=v[1];
				ans2=max(ans2,Max[rt1][0]*Max[rt1][1]);
				ans2=max(ans2,Min[rt1][0]*Min[rt1][1]);
			}
			ans[i][0]=ans1;
			ans[i][1]=ans2;
		}
	}
	for(int i=0;i<n;++i)cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
	return 0;
}