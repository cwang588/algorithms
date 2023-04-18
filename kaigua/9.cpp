#include<bits/stdc++.h>
using namespace std;
const long long inf=1145141919810;
long long a[2005],b[2005],dp[2005];
const int maxn=2005;
struct node{int l,r,sum;long long tot;}T[maxn*40];
vector<int>v;
int cnt,root[maxn];
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;};	
void update(int l,int r,int &x,int y,int pos)
{
	T[++cnt]=T[y],T[cnt].sum++,x=cnt,T[cnt].tot+=v[pos-1];
	if(l==r)return;
	int mid=(l+r)>>1;
	if(mid>=pos)update(l,mid,T[x].l,T[y].l,pos);
	else update(mid+1,r,T[x].r,T[y].r,pos);
}
long long query(int l,int r,int x,int y,int k)
{
	if(!k)return 0;
	if(l==r)return v[l-1];
	int mid=(l+r)>>1;
	int sum=T[T[y].r].sum-T[T[x].r].sum;
	if(sum==k)return T[y].tot-T[x].tot;
	if(sum>k)return query(mid+1,r,T[x].r,T[y].r,k);
	else return T[T[y].r].tot-T[T[x].r].tot+query(l,mid,T[x].l,T[y].l,k-sum);
}
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),b[i]=b[i-1]+a[i],v.push_back(a[i]),dp[i]=inf;
	sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)update(1,n,root[i],root[i-1],getid(a[i]));
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			int k=(i-j)-(i-j)/c;
			dp[i]=min(dp[i],dp[j]+query(1,n,root[j],root[i],k));
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
