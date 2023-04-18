#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
unsigned long long Hash[100005];
const long long mod=; 
struct paper{
	unsigned long long Hash;
	int cnt,id,a[10005];
	paper(){
		Hash=cnt=0;
	}
}p[105];
bool cmp(paper x,paper y){
	return x.cnt>y.cnt;
}
bool usd[100005];
unsigned long long quickpower(unsigned long long a,int b){
	unsigned long long re=1,now=a;
	while(b){
		if(b&1)re*=now;
		now=now*now;
		b>>=1;
	}
	return re;
}
unsigned long long getHash(int l,int r){
	return Hash[r]-Hash[l-1]*quickpower(mod,r-l+1);
}
int ans[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		Hash[i]=Hash[i-1]*mod+a[i];
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&p[i].cnt);
		for(int j=1;j<=p[i].cnt;++j){
			scanf("%d",&p[i].a[j]);
			p[i].Hash=p[i].Hash*mod+p[i].a[j];
		}
		p[i].id=i;
	}
	sort(p+1,p+1+m,cmp);
	for(int i=1;i<=m;++i){
		int num=0;
		for(int j=1;j<=p[i].cnt-2;++j)if(usd[j])++num;
		for(int j=1;j+p[i].cnt-1<=n;++j){
			if(usd[j+p[i].cnt-2])++num;
			if(usd[j-1])--num;
			if(a[j]!=p[i].a[1])continue;
			if(num||getHash(j,j+p[i].cnt-1)!=p[i].Hash)continue;
			ans[j]=p[i].id;
			for(int k=j;k<=j+p[i].cnt-2;++k)usd[k]=true;
			break;
		}
	}
	int anscnt=0;
	for(int i=1;i<=n;++i){
		if(ans[i]){
			printf("%d",ans[i]);
			++anscnt;
			if(anscnt<m)printf(" ");
		}
	}
	return 0;
}
