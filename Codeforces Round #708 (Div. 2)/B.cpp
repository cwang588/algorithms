#include<bits/stdc++.h>
using namespace std;
int a[100005],cnt[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m); 
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]%=m,++cnt[a[i]];
		int ans=0;
		if(cnt[0])++ans;
		for(int i=1;2*i<m;++i){
			int x=cnt[i],y=cnt[m-i];
			if(x==0&&y==0)continue;
			if(x==y||x==y+1||x==y-1)++ans;
			else ans+=max(x,y)-min(x,y);
		}
		if(m%2==0&&cnt[m/2])++ans;
		printf("%d\n",ans);
		for(int i=0;i<m;++i)cnt[i]=0;
	}

	return 0;
}
