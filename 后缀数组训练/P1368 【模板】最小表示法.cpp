#include<bits/stdc++.h>
#define maxn 600005
using namespace std;
struct SuffixArray{
	int s[maxn];
	int n,m,lg2[maxn],st[maxn][35],y[maxn],x[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],wt[30];
	void init(){
		memset(c,0,sizeof(c));
    	memset(y,0,sizeof(y)); 
    	memset(x,0,sizeof(x)); 
	}
	void get_SA(){
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
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],v.push_back(a[i]);
//	sort(v.begin(),v.end());
//	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)SA.s[i]=SA.s[i+n]=a[i];
	SA.n=n<<1,SA.m=v.size();
	SA.get_SA(),SA.get_height(),SA.get_lcp();
	int rt;
	for(int i=1;i<=n;++i){
		if(SA.sa[i]<=n+1){
			rt=SA.sa[i];
			break;
		}
	}
	for(int i=1;i<=n;++i){
		int now=i+rt-1;
		if(now<=n)cout<<a[now]<<" ";
		else cout<<a[now-n]<<" ";
	}
	cout<<"\n";
	return 0;
}