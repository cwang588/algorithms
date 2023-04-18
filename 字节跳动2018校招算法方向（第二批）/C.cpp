#include<bits/stdc++.h>
using namespace std;
char s[1005];
int pos[28][1005],cnt[28],now[28],n,m,sum[28][1005];
bool check(int x){
	for(int i=1;i<=26;++i)now[i]=0;
	for(int i=1;i+x-1<=n;++i){
		++now[s[i]-'a'+1];
		if(cnt[s[i]-'a'+1]<now[s[i]-'a'+1]+x-1)continue;
		int l=now[s[i]-'a'+1],r=l+x-1,mid=(l+r)>>1,tmppos=pos[s[i]-'a'+1][mid];
		int tot=0;
		tot+=tmppos*(mid-l+1)-(sum[s[i]-'a'+1][mid]-sum[s[i]-'a'+1][l-1])-(mid-l+1)*(mid-l)/2;
		tot+=(sum[s[i]-'a'+1][r]-sum[s[i]-'a'+1][mid])-tmppos*(r-mid)-(r-mid-1)*(r-mid)/2;
		if(tot<=m)return true;		
	}
	return false;
}
int main(){
	cin>>(s+1)>>m;
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		++cnt[s[i]-'a'+1];
		sum[s[i]-'a'+1][cnt[s[i]-'a'+1]]=sum[s[i]-'a'+1][cnt[s[i]-'a'+1]-1]+i;
		pos[s[i]-'a'+1][cnt[s[i]-'a'+1]]=i;
	}
	int l=1,r=1001;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
