#include<bits/stdc++.h>
using namespace std;
struct op{
	long long pos;
	bool type;
}p[100005];
int h[10005],k[10005];
bool cmp(op x,op y){
	if(x.pos!=y.pos)return x.pos<y.pos;
	return x.type<y.type;

}
long long calc(int x){
	return 1ll*(x+1)*x/2;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>k[i];
		for(int i=1;i<=n;++i)cin>>h[i];
		for(int i=1;i<=n;++i){
			p[i*2-1]={k[i]-h[i]+1,false};
			p[i*2]={k[i],true};
		}
		sort(p+1,p+1+n*2,cmp);
		long long ans=0;
		int cnt=0,last=0;
		for(int i=1;i<=n*2;++i){
			if(!p[i].type){
				if(!last)last=p[i].pos;
				++cnt;
			}
			else{
				--cnt;
				if(!cnt){
					ans+=calc(p[i].pos-last+1);
					last=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}