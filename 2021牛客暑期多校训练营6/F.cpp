#include<bits/stdc++.h>
using namespace std;
struct bin{
	long long t,l1,l2,r1,r2;
	int id,k,num1,num2;
}a[100005];
int n,m;
bool check(long long now){
	int cnt=1;
	long long re=now;
	for(int i=1;i<=n;++i){
		if(a[i].t>now)return false;
		if(re>a[i].t)re-=a[i].t;
		else{
			++cnt;
			re=now-(a[i].t-re);
		}
	}
	if(re==now)--cnt;
	return cnt<=m;
}
void work(long long now){
	int cnt=1;
	long long re=now;
	for(int i=1;i<=n;++i){
		if(re>=a[i].t){
			a[i].num1=cnt;
			a[i].k=1;
			a[i].l1=now-re,a[i].r1=now-re+a[i].t;
			re-=a[i].t;
			if(!re){
				re=now;
				++cnt;
			}
		}
		else{
			a[i].k=2;
			a[i].num2=cnt;
			a[i].num1=cnt+1;
			a[i].l2=now-re,a[i].r2=now;
			a[i].l1=0,a[i].r1=a[i].t-re;
			++cnt;
			re=now-(a[i].t-re);
		}
	}
}
bool cmp(bin x,bin y){
	return x.t>y.t;
}
bool cmpp(bin x,bin y){
	return x.id<y.id;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i].t,a[i].id=i;
	long long l=0,r=1000000000000000000;
	sort(a+1,a+1+n,cmp);
	while(l<r-1){
		long long mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}	
	work(r);
	sort(a+1,a+1+n,cmpp);
	for(int i=1;i<=n;++i){
		cout<<a[i].k<<" ";
		if(a[i].k==1)cout<<a[i].num1<<" "<<a[i].l1<<" "<<a[i].r1<<endl;
		else cout<<a[i].num1<<" "<<a[i].l1<<" "<<a[i].r1<<" "<<a[i].num2<<" "<<a[i].l2<<" "<<a[i].r2<<endl;
	} 
	return 0;
}
