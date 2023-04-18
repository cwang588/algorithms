#include<bits/stdc++.h>
using namespace std;
struct seg{
	long long l,r;
}s[200005];
bool cmp(seg x,seg y){
	return x.l<y.l;
}
int main(){
	long long n;
	int m; 
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>s[i].l>>s[i].r;
	sort(s+1,s+1+m,cmp);
	long long nowr=0,maxr=0;
	int cnt=0,now=0;
	while(now<m&&nowr!=n){
		++now;
		if(s[now].l>nowr+1){
			++cnt;
			nowr=maxr;
			maxr=0;
		}
		if(s[now].l<=nowr+1)maxr=max(maxr,s[now].r);
	}
	if(nowr<n)++cnt;
	cout<<cnt<<endl;
	return 0;
}
