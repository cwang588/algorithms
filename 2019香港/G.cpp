#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,value,fa;
	bool usd;
}T[2000005];
int cnt;
void dfs(int now,int k){
	if(k==1){
		T[now].value=1;
		return;
	}
	int to=++cnt;
	dfs(to,k/2);
	T[to].fa=now;
	T[now].r=to;
	T[now].value=T[to].value*2;
	if(k%2==0)T[now].usd=true;
	++cnt;
	T[cnt].fa=now;
	T[now].l=cnt;
	T[cnt].value=T[to].value;
	int tmp=cnt++;
	T[cnt].fa=tmp;
	T[tmp].l=cnt;
	T[cnt].value=T[to].value;
}
int main(){
	int k;
	scanf("%d",&k);
	if(k==1)return !printf("2\n1\n1 2\n");
	cnt=1;
	dfs(1,k);
	printf("%d\n",cnt);
	for(int i=2;i<=cnt;++i)printf("%d ",T[i].fa);
	printf("\n");
	for(int i=1;i<=cnt;++i){
		if(!T[i].usd)printf("%d ",T[i].value);
		else printf("1000000000 ");
	}
	printf("\n");
	return 0;
}
