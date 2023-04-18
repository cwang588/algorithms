#include<bits/stdc++.h>
using namespace std;
int a[505],tmp[505];
bool usd[505];
int n;
bool judge(int re){
	for(int i=1;i<=n;++i)if(!usd[i]&&a[i]==0)return true;
	return false;
}
struct query{
	int x,y,ans;
}q[1200005];
bool cmp(query p,query q){
	return p.ans>q.ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],tmp[i]=a[i];
	int re=n;
	while(judge(re)&&re>2){
		for(int i=1;i<=n;++i){
			if(usd[i])continue;
			if(a[i]==0)usd[i]=true;
			else --a[i];
		}
	}
	if(re<=2)return !printf("! 0 0\n");
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(usd[i]||usd[j])continue;
			++cnt;
			if(a[i]<a[j]){
				q[cnt].x=j;
				q[cnt].y=i;
			}
			else{
				q[cnt].x=i;
				q[cnt].y=j;
			}
			q[cnt].ans=abs(tmp[i]-tmp[j]);
		}
	}
	sort(q+1,q+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		printf("? %d %d\n",q[i].x,q[i].y);
		fflush(stdout);
		string tt;
		cin>>tt;
		if(tt=="Yes")return !printf("! %d %d\n",q[i].x,q[i].y); 
	}
	printf("! 0 0\n");
	return 0;
}
