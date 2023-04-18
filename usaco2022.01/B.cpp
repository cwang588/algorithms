#include<bits/stdc++.h>
using namespace std;
int a[1000005],pos[1000005];
struct node{
	int l,r,val,key,sz;
}fhq[500005];
int cnt,root;
inline int newnode(int val){
	fhq[++cnt].val=val;
	fhq[cnt].sz=1;
	fhq[cnt].key=32768*rand()%32768+rand()%32768;
	return cnt;
}
void update(int now){
	fhq[now].sz=fhq[fhq[now].l].sz+fhq[fhq[now].r].sz+1;
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
void del(int val){
	split_value(root,val,x,z);
	split_value(x,val-1,x,y);
	y=merge(fhq[y].l,fhq[y].r);
	root=merge(merge(x,y),z);
}
int getrank(int val){
	split_value(root,val-1,x,y);
	int re=fhq[x].sz+1;
	root=merge(x,y);
	return re;
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
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	insert(2147483647);
	insert(-2147483647);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pos[a[i]]=i;
	}
	long long ans=0;
	for(int i=n;i>=1;--i){
		int tmp=getnext(pos[i]);
		if(tmp<2147483647)ans+=tmp-pos[i]+1;
		tmp=getpre(pos[i]);
		if(tmp>-2147483647)ans+=pos[i]-tmp+1;
		insert(pos[i]);
	}
	cout<<ans;
	return 0;
}