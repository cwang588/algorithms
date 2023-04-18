#include<bits/stdc++.h>
using namespace std;
int a[15],ans;
bool usd[15];
struct edge{
	int from,to,nxt;
}e[2005];
int Head[1005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfss(int now){
	usd[now]=true;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(!usd[to]&&a[to])dfss(to);
	}
}
void dfs(int now){
	if(now==8){
		int tot=0;
		for(int i=1;i<=7;++i)tot+=a[i],usd[i]=false;
		for(int i=1;i<=7;++i){
			if(a[i]){
				dfss(i);
				break;
			}
		}
		bool ky=true;
		for(int i=1;i<=7;++i)if(a[i]&&!usd[i])ky=false;
		if(ky)++ans;
		return;
	}
	a[now]=1;
	dfs(now+1);
	a[now]=0;
	dfs(now+1);
}
int main(){
	add(1,2);
	add(1,6);
	add(2,1);
	add(2,7);
	add(2,3);
	add(3,2);
	add(3,7);
	add(3,4);
	add(4,3);
	add(4,5);
	add(5,4);
	add(5,6);
	add(5,7);
	add(6,1);
	add(6,5);
	add(6,7);
	add(7,6);
	add(7,2);
	add(7,3);
	add(7,5);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
