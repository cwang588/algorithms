#include<bits/stdc++.h>
using namespace std;
char s[2000005];
int x[200005],pos[1200005];
struct point{
	int type,son[2],fa,value,sum[2],depth,tot;//type: !n+1 |n+2 &n+3
}p[2000005];
int cnt,root,n;
void dfs(int now,int pre){
	p[now].depth=p[pre].depth+1;
	if(p[now].type<=n){
		p[now].value=x[p[now].type];
		pos[p[now].type]=now;
		return;
	}
	if(p[now].type==n+1){
		dfs(p[now].son[1],now);
		p[now].value=1-p[p[now].son[1]].value; 
		p[now].sum[1]=1;
	}
	else if(p[now].type==n+2){
		dfs(p[now].son[0],now);
		dfs(p[now].son[1],now);
		p[now].value=p[p[now].son[1]].value||p[p[now].son[0]].value;
		if(p[now].value){
			if(p[p[now].son[1]].value&&p[p[now].son[0]].value);
			else if(p[p[now].son[0]].value)p[now].sum[0]=1;
			else if(p[p[now].son[1]].value)p[now].sum[1]=1;
			else;
		}
		else p[now].sum[0]=p[now].sum[1]=1;
	}
	else{
		dfs(p[now].son[0],now);
		dfs(p[now].son[1],now);
		p[now].value=p[p[now].son[1]].value&&p[p[now].son[0]].value;
		if(!p[now].value){
			if((!p[p[now].son[1]].value)&&(!p[p[now].son[0]].value));
			else if(!p[p[now].son[0]].value)p[now].sum[0]=1;
			else if(!p[p[now].son[1]].value)p[now].sum[1]=1;
			else;
		}
		else p[now].sum[0]=p[now].sum[1]=1;
	}
}
void dfss(int now,int pre){
	if(pre){
		if(p[pre].son[0]==now)p[now].tot=p[pre].tot+p[pre].sum[0];
		else p[now].tot=p[pre].tot+p[pre].sum[1];
	}
	if(p[now].son[0])dfss(p[now].son[0],now);
	if(p[now].son[1])dfss(p[now].son[1],now);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0); 
	gets(s+1);
	int len=strlen(s+1);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>x[i];
	int tmp=0,num=0,now=0;
	for(int i=len;i>0;--i){
		if(s[i]==' ')continue;
		if(s[i]=='x'){
			++cnt;
			p[cnt].type=num;
			if(!root)now=root=cnt;
			else{
				if(!p[now].son[1])p[now].son[1]=cnt;
				else p[now].son[0]=cnt;
				p[cnt].fa=now;
				while((p[now].son[0]&&p[now].son[1])||(p[now].type==n+1))now=p[now].fa;
			}
			num=tmp=0;
		}
		else if(s[i]=='!'){
			++cnt;
			p[cnt].type=n+1;
			if(!root)now=root=cnt;
			else{
				if(!p[now].son[1])p[now].son[1]=cnt;
				else p[now].son[0]=cnt;
				p[cnt].fa=now;
				now=cnt;
			}
		}
		else if(s[i]=='|'){
			++cnt;
			p[cnt].type=n+2;
			if(!root)now=root=cnt;
			else{
				if(!p[now].son[1])p[now].son[1]=cnt;
				else p[now].son[0]=cnt;
				p[cnt].fa=now;
				now=cnt;
			}
		}
		else if(s[i]=='&'){
			++cnt;
			p[cnt].type=n+3;
			if(!root)now=root=cnt;
			else{
				if(!p[now].son[1])p[now].son[1]=cnt;
				else p[now].son[0]=cnt;
				p[cnt].fa=now;
				now=cnt;
			}
		}
		else{
			num+=pow(10,tmp)*(s[i]-'0');
			++tmp;
		}
	}
	dfs(root,0);
	dfss(root,0);
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		int ans=p[root].value;
		if(p[pos[t]].tot+1==p[pos[t]].depth)ans=1-ans;
		printf("%d\n",ans);
	}
	return 0;
} 
