#include<bits/stdc++.h>
using namespace std;
int x[6005],y[6006],tong[2000005];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    int n,k,tot=0;
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
    for(int i=1;i<=n;++i){
	    for(int j=i+1;j<=n;++j){
	    	++tong[(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])];
		}
	}
	int now=0;
	for(int i=2000000;i>=0;--i){
		now+=tong[i];
		if(now>=k)return !printf("%d\n",i);
	}
	return 0;
}
