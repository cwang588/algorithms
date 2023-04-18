#include<bits/stdc++.h>
using namespace std;
struct interval{
	int l,r;
}a[100005],ans[100005];
bool cmp(interval x,interval y){
	if(x.l!=y.l)return x.l<y.l;
	return x.r<y.r;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].l>>a[i].r;
	sort(a+1,a+1+n,cmp);
	int num=0;
	ans[0].r=-2147483647;
	for(int i=1;i<=n;++i){
		if(a[i].l<=ans[num].r)ans[num].r=max(a[i].r,ans[num].r);
		else ans[++num]=a[i];
	}
	cout<<num<<"\n";
	for(int i=1;i<=num;++i)cout<<ans[i].l<<' '<<ans[i].r<<"\n";
	return 0;
}
