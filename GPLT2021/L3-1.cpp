#include<bits/stdc++.h>
using namespace std;
struct program{
	int ans[105],cnt;
}p[10005];
int cnt,tmp[105];
map<unsigned long long,int>mm;
unsigned long long hash[1005];
int n,m;
bool cmp(program x,program y){
	if(x.cnt!=y.cnt)return x.cnt>y.cnt;
	for(int i=1;i<=m;++i){
		if(x.ans[i]!=y.ans[i])return x.ans[i]<y.ans[i];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		unsigned long long now=0;
		for(int j=1;j<=m;++j){
			scanf("%d",&tmp[j]);
			now=now*19260817+tmp[j]+2147483649;
		}
		if(mm[now])++p[mm[now]].cnt;
		else{
			++cnt;
			p[cnt].cnt=1;
			for(int j=1;j<=m;++j)p[cnt].ans[j]=tmp[j];
			mm[now]=cnt;
		}
	}
	sort(p+1,p+1+cnt,cmp);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		printf("%d ",p[i].cnt);
		for(int j=1;j<m;++j)printf("%d ",p[i].ans[j]);
		printf("%d\n",p[i].ans[m]);
	}
	return 0;
}
