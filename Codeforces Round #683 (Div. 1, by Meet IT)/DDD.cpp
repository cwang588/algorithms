#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt[200005],s[200005],fst[400005],cntnow[4000005],pos[200005];
int main(){
	int n,Max,num=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++cnt[a[i]];
	for(int i=1;i<=n;++i){
		if(cnt[i]>num){
			Max=i;
			num=cnt[i];
		}
	}
	for(int i=1;i<=n;++i){
		if(i!=Max&&cnt[i]>=447){
			for(int j=0;j<=2*n;++j)fst[j]=-1;
			fst[0]=0;
			for(int j=1;j<=n;++j){
				if(a[j]==Max)s[j]=s[j-1]+1;
				else if(a[j]==i)s[j]=s[j-1]-1;
				else s[j]=s[j-1];
				if(fst[s[j]+n]==-1)fst[s[j]+n]=j;
				else ans=max(ans,j-fst[s[j]+n]+2);
			}
		}
	}
	int tmp=0;
	for(int i=1;i<=n;++i)if(a[i]==Max)pos[++tmp]=i;
	pos[num+1]=n+1,a[n+1]=a[0]=Max;
	for(int i=1;i<=min(447,num);++i){
		memset(cntnow,0,sizeof(cntnow));
		int l=0,r=0,ok=0;
		for(int j=i+1;j<=n+1;++j){
			while(r<=pos[j]){
				++cntnow[a[r]];
				if(a[r]!=Max&&cntnow[a[r]]==i)++ok;
				++r;
			}
			while(l<=pos[j-i-1]){
				--cntnow[a[l]];
				if(a[l]!=Max&&cntnow[a[l]]==i-1)--ok;
				++l;
			}
			if(ok)ans=max(ans,pos[j]-pos[j-i-1]-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}
