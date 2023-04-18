#include<bits/stdc++.h>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int n[10],m[10],a[5][150005],dp[5][150005];
vector<int>v[5],tag[4][150005];
bool usd[5][150005];
int getid(int num,int x){
	return lower_bound(v[num].begin(),v[num].end(),x)-v[num].begin()+1;
}
int sum[5][150005<<2];
void modify(int num,int l,int r,int rt,int pos,int d){
	if(l==r){
		sum[num][rt]+=d;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)modify(num,lson,pos,d);
	else modify(num,rson,pos,d);
	sum[num][rt]=sum[num][rt<<1]+sum[num][rt<<1|1];
}
int query(int num,int l,int r,int rt){
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(sum[num][rt<<1])return query(num,lson);
	else return query(num,rson);
}
int main(){
	for(int i=1;i<=4;++i)scanf("%d",&n[i]);
	for(int i=1;i<=4;++i){
		for(int j=1;j<=n[i];++j){
			scanf("%d",&a[i][j]);
			v[1].push_back(a[i][j]);
		}
	}
	sort(v[1].begin(),v[1].end());
	v[1].erase(unique(v[1].begin(),v[1].end()),v[1].end());
	for(int i=1;i<=3;++i){
		scanf("%d",&m[i]);
		for(int j=1;j<=m[i];++j){
			int x,y;
			scanf("%d%d",&x,&y);
			tag[i][y].push_back(x);
		}
	}
	for(int i=1;i<=n[1];++i)usd[1][i]=true;
	for(int i=1;i<=n[1];++i){
		dp[1][i]=a[1][i];
		modify(1,1,n[1],1,getid(1,a[1][i]),1);
	}
	bool ky=true;
	for(int num=2;num<=4;++num){
		for(int i=1;i<=n[num];++i){
			for(int x:tag[num-1][i])if(usd[num-1][x])modify(num-1,1,n[num-1],1,getid(num-1,dp[num-1][x]),-1);
			if(sum[num-1][1]){
				int tmp=v[num-1][query(num-1,1,n[num-1],1)-1];
				if(tmp!=0)dp[num][i]=v[num-1][query(num-1,1,n[num-1],1)-1]+a[num][i];
				else dp[num][i]=1000000000;
				v[num].push_back(dp[num][i]);
				usd[num][i]=true;
			}
			for(int x:tag[num-1][i])if(usd[num-1][x])modify(num-1,1,n[num-1],1,getid(num-1,dp[num-1][x]),1);
		}
		sort(v[num].begin(),v[num].end());
		v[num].erase(unique(v[num].begin(),v[num].end()),v[num].end());
		for(int i=1;i<=n[num];++i){
			if(usd[num][i])modify(num,1,n[num],1,getid(num,dp[num][i]),1);
		}
		if(!sum[num][1]){
			ky=false;
			break;
		}
	}
	if(!ky)printf("-1\n");
	else{
		int ans=2147483647;
		for(int i=1;i<=n[4];++i)if(usd[4][i])ans=min(ans,dp[4][i]);
		printf("%d\n",ans);
	}
	return 0;
}
