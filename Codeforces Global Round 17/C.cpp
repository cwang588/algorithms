#include<bits/stdc++.h>
using namespace std;
struct people{
	int a,b,id;
}p[100005];
bool cmp(people x,people y){
	return x.a+x.b>y.a+y.b;
}
int sum[200005],n;
int lowbit(int x){
	return x&(-x);
}
void add(int x){
	while(x<=n){
		++sum[x];
		x+=lowbit(x);
	}
}
int ask(int x){
	int re=0;
	while(x){
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
int Min[200005<<2],col[];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)sum[i]=0,cin>>p[i].a>>p[i].b,p[i].id=i;
		sort(p+1,p+1+n,cmp);
		int tot=0;
		for(int i=1;i<=n;++i){
			int tmp=ask(p[i].id);
			if(tmp<=p[i].b&&tot-tmp<=p[i].a){
				++tot;
				add(p[i].id);
			}
		}
		cout<<tot<<"\n";
	}
	
	return 0;
}