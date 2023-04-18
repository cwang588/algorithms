#include<bits/stdc++.h>
using namespace std;
const long long mod1=1000000007,mod2=1000000009;
struct edge{
	int from,to,nxt;
}e[10005];
int Head[5005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void init(){
	memset(Head,0,sizeof(Head));
	cnt=0;
} 
int a[2005][2005],c[2005];
long long num1[2005],num2[2005];
int num[2005],ans;
void push(int x){
	++num[x];
	if(num[x]==1)++ans;
}
void pop(int x){
	--num[x];
	if(num[x]==0)--ans;
}
void dfs(int now,int pre,int top){
	push(c[now]);
	a[top][now]=ans;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now,top);
	}
	pop(c[now]);
}
int main(){
	int t;
	cin>>t;
	num1[0]=num2[0]=1;
	for(int i=1;i<=2000;++i){
		num1[i]=num1[i-1]*19560929%mod1;
		num2[i]=num2[i-1]*19560929%mod2;
	}
	while(t--){
		init();
		int n;
		cin>>n;
		for(int i=2;i<=n;++i){
			int now;
			cin>>now;
			add(now,i);
			add(i,now);
		}
		for(int i=1;i<=n;++i)cin>>c[i];
		for(int i=1;i<=n;++i)dfs(i,0,i);
		for(int i=1;i<=n;++i){
			long long ans1=0,ans2=0;
			for(int j=1;j<=n;++j){
				ans1=(ans1+num1[j-1]*a[i][j])%mod1;
				ans2=(ans2+num2[j-1]*a[i][j])%mod2;
			}
			cout<<ans1<<" "<<ans2<<endl;
		}
	}
	return 0;
}
