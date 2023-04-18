#include<bits/stdc++.h>
using namespace std;
struct mail{
	long long x,num;
}m[1005];
bool cmp(mail a,mail b){
	return a.x<b.x;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>m[i].x>>m[i].num;
	sort(m+1,m+1+n,cmp);
	int fg=n;
	for(int i=1;i<=n;++i){
		if(m[i].x>0){
			fg=i-1;
			break;
		}
	}
	long long ans=0,re=0;
	for(int i=1;i<=fg;++i){
		long long tmp=m[i].num%k;
		if(tmp<=re){
			re-=tmp;
			m[i].num-=tmp;
		}
		if(!m[i].num)continue;
		long long cs=m[i].num/k;
		if(m[i].num%k)++cs;
		ans+=cs*(-m[i].x)*2;
		re+=cs*k-m[i].num;
	}
	re=0;
	for(int i=n;i>fg;--i){
		long long tmp=m[i].num%k;
		if(tmp<=re){
			re-=tmp;
			m[i].num-=tmp;
		}
		if(!m[i].num)continue;
		long long cs=m[i].num/k;
		if(m[i].num%k)++cs;
		ans+=cs*(m[i].x)*2;
		re+=cs*k-m[i].num;
	}
	cout<<ans<<endl;
	return 0;
}
