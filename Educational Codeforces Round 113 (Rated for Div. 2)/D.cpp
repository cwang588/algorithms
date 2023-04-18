#include<bits/stdc++.h>
using namespace std;
int x[200005],y[200005];
struct point{
	int xw,yw;
}p1[300005],p2[300005];
bool cmp1(point a,point b){
	if(a.xw!=b.xw)return a.xw<b.xw;
	return a.yw<b.yw;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;++i)cin>>x[i];
		for(int i=1;i<=m;++i)cin>>y[i];
		int num1=0,num2=0;
		for(int i=1;i<=k;++i){
			int tx,ty;
			cin>>tx>>ty;
			int txw=lower_bound(x+1,x+n+1,tx)-x;
			int tyw=lower_bound(y+1,y+m+1,ty)-y;
			if(x[txw]==tx&&y[tyw]==ty)continue;
			if(x[txw]==tx)p2[++num2]=point{tyw,txw};
			else p1[++num1]=point{txw,tyw};
		} 
		sort(p1+1,p1+1+num1,cmp1);
		sort(p2+1,p2+1+num2,cmp1);
		long long ans=0,tot1=0,tot2=0;
		for(int i=1;i<=num1;++i){
			if(p1[i].xw!=p1[i-1].xw){
				ans+=tot1*tot1-tot2*tot2;
				tot1=tot2=1;
			}
			else{
				++tot1;
				if(p1[i].yw!=p1[i-1].yw){
					ans-=tot2*tot2;
					tot2=1;
				}
				else ++tot2;
			}
		}
		ans+=tot1*tot1-tot2*tot2;
		tot1=0,tot2=0;
		for(int i=1;i<=num2;++i){
			if(p2[i].xw!=p2[i-1].xw){
				ans+=tot1*tot1-tot2*tot2;
				tot1=tot2=1;
			}
			else{
				++tot1;
				if(p2[i].yw!=p2[i-1].yw){
					ans-=tot2*tot2;
					tot2=1;
				}
				else ++tot2;
			}
		}
		ans+=tot1*tot1-tot2*tot2;
		cout<<ans/2<<"\n";
	}
	
	return 0;
}
