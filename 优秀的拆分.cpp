#include<bits/stdc++.h>
#define maxn 1000050
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
}SA[2];
long long a[maxn],b[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>SA[0].s+1;
		int n=strlen(SA[0].s+1);
		for(int i=1;i<=n;++i)a[i]=b[i]=0,SA[1].s[i]=SA[0].s[n-i+1];
		SA[0].init(),SA[0].get_SA(),SA[0].get_height(),SA[0].get_lcp();
		SA[1].init(),SA[1].get_SA(),SA[1].get_height(),SA[1].get_lcp();
		for(int len=1;len<=n/2;++len){
			for(int i=len;i+len<=n;i+=len){
				int l=i,r=i+len,lcp=min(len,SA[0].Lcp(l,r));
				int L=n-r+2,R=n-l+2,lcs=min(len-1,SA[1].Lcp(L,R));
				if(lcp+lcs>=len){
					b[i-lcs]++,b[i-lcs+(lcp+lcs-len+1)]--;
          			a[r+lcp-(lcp+lcs-len+1)]++,a[r+lcp]--; 
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i)a[i]+=a[i-1],b[i]+=b[i-1];
		for(int i=1;i<n;++i)ans+=a[i]*b[i+1];
		cout<<ans<<"\n";
	}
    return 0;
}
