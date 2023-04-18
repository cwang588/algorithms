#include<bits/stdc++.h>
using namespace std;
const int N=600005; 
int a[600005];
struct node{
	int l,r,val,key,sz,num,xor1,xor2;
}fhq[500005];
int cnt,root;
inline int newnode(int val){
	fhq[++cnt].val=val;
	fhq[cnt].sz=1;
	fhq[cnt].key=32768*rand()%32768+rand()%32768;
	return cnt;
}
void split_value(int now,int val,int &x,int &y){
	if(!now)x=y=0;
	else{
		if(fhq[now].val<=val){
			x=now;
			split_value(fhq[now].r,val,fhq[now].r,y);
		}
		else{
			y=now;
			split_value(fhq[now].l,val,x,fhq[now].l);
		}
		update(now);
	}
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(fhq[x].key>fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		update(x);
		return x;
	}
	else{
		fhq[y].l=merge(x,fhq[y].l);
		update(y);
		return y;
	}
}
int x,y,z;
void insert(int val){
	split_value(root,val,x,y);
	root=merge(merge(x,newnode(val)),y);
}
int getnum(int rank){
	int now=root;
	while(now){
		if(fhq[fhq[now].l].sz+1==rank)break;
		if(fhq[fhq[now].l].sz>=rank)now=fhq[now].l;
		else{
			rank-=fhq[fhq[now].l].sz+1;
			now=fhq[now].r;
		}
	}
	return fhq[now].val;
}
int getpre(int val){
	split_value(root,val-1,x,y);
	int now=x;
	while(fhq[now].r)now=fhq[now].r;
	int re=fhq[now].val;
	root=merge(x,y);
	return re;
}
int getnext(int val){
	split_value(root,val,x,y);
	int now=y;
	while(fhq[now].l)now=fhq[now].l;
	int re=fhq[now].val;
	root=merge(x,y);
	return re;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	return 0;
}
