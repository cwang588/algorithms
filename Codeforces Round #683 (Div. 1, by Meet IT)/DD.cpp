#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt[200005],sum[200005],s[200005],fst[200005];
vector<int>pos[200005];
int main(){
	int n,Max=0,tmp=0;;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pos[a[i]].push_back(i),++cnt[a[i]],tmp=max(tmp,cnt[a[i]]);
	for(int i=1;i<=n;++i){
		if(cnt[i]==tmp){
			if(Max)return !printf("%d\n",n);
			Max=i;
		}
	}
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1];
		if(a[i]==Max)++sum[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(i==Max)continue;
		int len=pos[i].size();
		for(int j=0;i<len;++j)
	}
	return 0;
}
