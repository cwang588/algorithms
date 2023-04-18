#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long qpow(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return re;
}
vector<int>vx,vy;
int getxid(int x){return lower_bound(vx.begin(),vx.end(),x)-vx.begin()+1;}
int getyid(int x){return lower_bound(vy.begin(),vy.end(),x)-vy.begin()+1;}
struct block{
    int xx1,yy1,xx2,yy2;
    int X1,Y1,X2,Y2;
}a[15];
int x,y,n;
bool nb[2005];
long long dp[2005];
bool judge(int state){
    for(int i=1;i<x;++i){
    	for(int j=1;j<y;++j){
            bool ky=false;
            for(int k=0;k<n;++k){
                if((1<<k)&state){
                    if(i>=a[k+1].X1&&i<a[k+1].X2&&j>=a[k+1].Y1&&j<a[k+1].Y2){
                        ky=true;
                        break;
                    }
                }
            }
            if(!ky)return false;
        }
	}
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(nb,0,sizeof(nb));
        vx.clear(),vy.clear();
        cin>>n;
        int w,h;
        cin>>w>>h;
        vx.push_back(0),vx.push_back(w);
        vy.push_back(0),vy.push_back(h);
        for(int i=1;i<=n;++i){
            cin>>a[i].xx1>>a[i].yy1>>a[i].xx2>>a[i].yy2;
            vx.push_back(a[i].xx1),vx.push_back(a[i].xx2);
            vy.push_back(a[i].yy1),vy.push_back(a[i].yy2);
        }
        sort(vx.begin(),vx.end()),vx.erase(unique(vx.begin(),vx.end()),vx.end());
        sort(vy.begin(),vy.end()),vy.erase(unique(vy.begin(),vy.end()),vy.end());
        for(int i=1;i<=n;++i){
            a[i].X1=getxid(a[i].xx1);
            a[i].X2=getxid(a[i].xx2);
            a[i].Y1=getyid(a[i].yy1);
            a[i].Y2=getyid(a[i].yy2);
        }
        x=vx.size(),y=vy.size();
        bool ky=false;
        for(int i=0;i<(1<<n);++i){
            nb[i]=judge(i);
            if(nb[i])ky=true;
        } 
        if(!ky){
            cout<<"-1\n";
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=(1<<n)-1;i>=0;--i){
            if(nb[i])continue;
            int sz=0;
			for(int j=0;j<n;++j){
            	if((1<<j)&i)continue;
            	++sz;
            	dp[i]=(dp[i]+dp[i^(1<<j)])%mod;
			}
			dp[i]=(dp[i]+n)%mod*qpow(sz,mod-2,mod)%mod;			
        }
        cout<<dp[0]<<"\n";
    }
    return 0;
}