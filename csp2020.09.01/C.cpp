#include<bits/stdc++.h>
using namespace std;
struct point{
	int type,value;//0:! 1:& 2:| 3:^ 4:!& 5:!|
	void init(){
		if(type==0||type==2||type==3||type==5)value=0;
		else value=1;
	}
}p[3005];
struct edge{
	int from,to,nxt;
}e[200005][2];
int Head[505][2],cnt[2],in[10005][505],out[10005][505];
void add(int x,int y,int type){
	++cnt[type];
	e[cnt[type]][type].from=x;
	e[cnt[type]][type].to=y;
	e[cnt[type]][type].nxt=Head[x][type];
	Head[x][type]=cnt[type];
}
bool usd[505];
int rd[505],trd[505];
queue<int>q;
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(Head,0,sizeof(Head));
		memset(cnt,0,sizeof(cnt));
		memset(trd,0,sizeof(trd));
		int m,n;
		cin>>m>>n;
		for(int i=1;i<=n;++i){
			string type;
			int k;
			cin>>type>>k;
			if(type=="NOT")p[i].type=0;
			if(type=="AND")p[i].type=1;
			if(type=="OR")p[i].type=2;
			if(type=="XOR")p[i].type=3;
			if(type=="NAND")p[i].type=4;
			if(type=="NOR")p[i].type=5;
			for(int j=1;j<=k;++j){
				char tmp;
				int id;
				cin>>tmp>>id;
				if(tmp=='I'){
					add(i,id+n,0);
					add(id+n,i,1);	
				}
				else{
					add(i,id,0);
					add(id,i,1);
				}
			}
			trd[i]=k;
		}
		int s;
		cin>>s;
		for(int i=1;i<=s;++i){
			for(int j=1;j<=m;++j)cin>>in[i][j];
		}
		for(int i=1;i<=s;++i){
			cin>>out[i][0];
			for(int j=1;j<=out[i][0];++j)cin>>out[i][j];
		}
		for(int i=1;i<=s;++i){
			int tmpcnt=0;
			for(int j=1;j<=m;++j)q.push(j+n),p[j+n].value=in[i][j];
			for(int j=1;j<=n;++j)rd[j]=trd[j],p[j].init();
			while(!q.empty()){
				int now=q.front();
				q.pop();
				for(int j=Head[now][1];j;j=e[j][1].nxt){
					int to=e[j][1].to;
					--rd[to];
					if(p[to].type==0)p[to].value=p[now].value^1;
					if(p[to].type==1)p[to].value=p[now].value&p[to].value;
					if(p[to].type==2)p[to].value=p[now].value|p[to].value;
					if(p[to].type==3)p[to].value=p[now].value^p[to].value;
					if(p[to].type==4)p[to].value=p[now].value&p[to].value;
					if(p[to].type==5)p[to].value=p[now].value|p[to].value;
					if(!rd[to]){
						q.push(to);
						++tmpcnt;
						if(p[to].type==4||p[to].type==5)p[to].value^=1;
					}
				}
			}	
			if(tmpcnt!=n){
				printf("LOOP\n");
				break;
			}
			for(int j=1;j<=out[i][0];++j)printf("%d ",p[out[i][j]].value);
			printf("\n");		
		}
	}	
	return 0;
}
