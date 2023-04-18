#include<bits/stdc++.h>
using namespace std;
int a[200005];
struct point{
	int value;
	bool type;
}p[200005];
bool cmp(point x,point y){
	return x.value<y.value;
}
long long myabs(int x){
	if(x>0)return x;
	else return -x;
}
int main(){
	ios::sync_with_stdio(false);
	int n,N;
	cin>>n>>N;
	for(int i=1;i<=n;++i)cin>>p[i].value,p[i].type=true;
	p[n+1]=point{N,true};
	long long ans=0;
	int base=N/(n+1),m=n+1,now=base;
	while(now<N){
		p[++m]=point{now,false};
		now+=base;
	}
	//assert(m<=200000);
	sort(p+1,p+1+m,cmp);
	int cnta=0,cntb=0;
	for(int i=1;i<=m;++i){
		ans+=myabs(cnta-cntb)*(p[i].value-p[i-1].value);
		if(p[i].type)++cnta;
		else ++cntb;
	}
	cout<<ans<<"\n";
	return 0;
}