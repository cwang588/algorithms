#include<bits/stdc++.h>
using namespace std;
int a[300005];
bool usd[300005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),usd[i]=false;
		int ans=2147483647,tot=0;
		for(int i=2;i<n;++i){
			if(a[i-1]<a[i]&&a[i]>a[i+1])++tot,usd[i]=true;
			if(a[i-1]>a[i]&&a[i]<a[i+1])++tot,usd[i]=true;
		}
		ans=min(ans,tot);
		for(int i=2;i<n;++i){
			if(usd[i-1]){
				int tans=tot-1;
				if(usd[i])--tans;
				if(i+2<=n){
					if(usd[i+1]){
						if((a[i+1]>a[i+2]&&a[i+1]>a[i-1])||(a[i+1]<a[i+2]&&a[i+1]<a[i-1]));
						else --tans;
					}
					else{
						if((a[i+1]>a[i+2]&&a[i+1]>a[i-1])||(a[i+1]<a[i+2]&&a[i+1]<a[i-1]))++tans;
						else;
					}
				}
				else;
				ans=min(ans,tans);
			}
			else{
				int tans=tot;
				if(usd[i])--tans;
				if(i+2<=n){
					if(usd[i+1]){
						if((a[i+1]>a[i+2]&&a[i+1]>a[i-1])||(a[i+1]<a[i+2]&&a[i+1]<a[i-1]));
						else --tans;
					}
					else{
						if((a[i+1]>a[i+2]&&a[i+1]>a[i-1])||(a[i+1]<a[i+2]&&a[i+1]<a[i-1]))++tans;
						else;
					}
				}
				else;
				ans=min(ans,tans);
			}
			if(usd[i+1]){
				int tans=tot-1;
				if(usd[i])--tans;
				if(i>2){
					if(usd[i-1]){
						if((a[i-1]>a[i-2]&&a[i-1]>a[i+1])||(a[i-1]<a[i-2]&&a[i-1]<a[i+1]));
						else --tans;
					}
					else{
						if((a[i-1]>a[i-2]&&a[i-1]>a[i+1])||(a[i-1]<a[i-2]&&a[i-1]<a[i+1]))++tans;
						else;
					}
				}
				else;
				ans=min(ans,tans);
			}
			else{
				int tans=tot;
				if(usd[i])--tans;
				if(i>2){
					if(usd[i-1]){
						if((a[i-1]>a[i-2]&&a[i-1]>a[i+1])||(a[i-1]<a[i-2]&&a[i-1]<a[i+1]));
						else --tans;
					}
					else{
						if((a[i-1]>a[i-2]&&a[i-1]>a[i+1])||(a[i-1]<a[i-2]&&a[i-1]<a[i+1]))++tans;
						else;
					}
				}
				else;
				ans=min(ans,tans);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
