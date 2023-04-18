#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005],sum[1005][1005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	long long tot=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%lld",&a[i][j]);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
			tot+=a[i][j];
		}
	}
	int ansx,ansy;
	long long Min=2147483647777;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			long long now=abs(2*sum[i][j]-tot);
			if(now<Min){
				Min=now;
				ansx=i;
				ansy=j; 
			}
			else if(now==Min){
				if(i*j<ansx*ansy){
					ansx=i;
					ansy=j;
				}
				else if(i*j==ansx*ansy){
					if(i<ansx){
						ansx=i;
						ansy=j;
					}
					else;
				}
				else;
			}
			else;
		}
	}
	printf("%d %d\n",ansx,ansy);
	return 0;
}
