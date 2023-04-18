#include<bits/stdc++.h>
using namespace std;
static unsigned long next = 1;
/* RAND_MAX assumed to be 32767 */
int myrand(){
    next=next*1103515245+12345;
    return((unsigned)(next/65536) % 32768);
}
struct point{
	double u,v,a,b,c,d;
}p[1005];
struct edge{
	int from,to,nxt,num;
	double value;
}e[1005];
int cnt,Head[1005];
void add(int x,int y,int z,double value){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	e[cnt].num=z;
	e[cnt].value=value;
	Head[x]=cnt;
}
double r[1005];
int main(){
	int n,m,P,T;
	double t;
	cin>>n>>m>>P>>T>>t;
	int tmpcnt=0;
	while(true){
		int cnt;
		double u,v,a,b,c,d;
		cin>>cnt>>u>>v>>a>>b>>c>>d;
		for(int i=1;i<=cnt;++i)p[i+tmpcnt]=point{u,v,a,b,c,d};
		tmpcnt+=cnt;
		if(tmpcnt==n)break;
	}
	for(int i=1;i<=P;++i)cin>>r[i];
	for(int i=1;i<=m;++i){
		int x,y,D;
		double w;
		cin>>x>>y>>D>>w;
		add(x+1,y+1,D,w);
	}
	for(int i=1;i<=T;++i){
		
	}
	return 0;
}