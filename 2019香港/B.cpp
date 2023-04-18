#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[20005];
int Head[5005],cnt,num;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool dfs(int now,int pre){
	bool ky=true;
	int son=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		ky&=dfs(to,now);
		++son;
	}
	++num;
	if(son==2&&ky)num-=2;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cnt=num=0;
		for(int i=1;i<=n;++i)Head[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		if(num%2==0)printf("Bob\n");
		else printf("Alice\n");
	}
	
	return 0;
} 
