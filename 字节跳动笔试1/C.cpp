#include<bits/stdc++.h>
using namespace std;
struct idea{
	int atime,rtime,prop,id,pm,pid,stime;
	bool operator < (const idea &b)const{
		if(prop!=b.prop)return prop>b.prop;
		if(rtime!=b.rtime)return rtime<b.rtime;
		return atime<b.atime;
	}
}tmp[3005],ptmp[3005];
int ans[3005];
bool cmp1(idea a,idea b){
	return a.atime<b.atime;
}
struct cmp2{
	bool operator()(idea a,idea b){
		if(a.rtime!=b.rtime)return a.rtime<b.rtime;
		return a.pm<b.pm;
	}
};
priority_queue<idea>q[3005];
priority_queue<idea,vector<idea>,cmp2>qq[3005];
int pid[3005];
int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;++i){
		scanf("%d%d%d%d",&tmp[i].pm,&tmp[i].atime,&tmp[i].prop,&tmp[i].rtime);
		tmp[i].id=i;
	}
	sort(tmp+1,tmp+1+p,cmp1);
	for(int i=1;i<=p;++i)tmp[i].pid=i;
	int now=1;
	for(int i=1;i<=3000;++i){
		while(tmp[now].atime==i){
			q[tmp[now].pm].push(tmp[now]);
			++now;
		}
		for(int j=1;j<=m;++j){
			if(pid[j]&&tmp[pid[j]].stime+tmp[pid[j]].rtime==i){
				ans[tmp[pid[j]].id]=i;
				pid[j]=0;
			}
		}
		for(int j=1;j<=m;++j){
			if(!pid[j]){
				int num=0;
				for(int k=1;k<=n;++k){
					if(!q[k].empty()){
						ptmp[++num]=q[k].top();
					}
				}
				if(!num)break;
				sort(ptmp+1,ptmp+1+num,cmp2);
				pid[j]=ptmp[1].pid;
				q[ptmp[1].pm].pop();
				tmp[pid[j]].stime=i;
			}
		}
	}
	for(int i=1;i<=p;++i)printf("%d\n",ans[i]);
	return 0;
}
