#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0,lasta=0,lastb=0;
	for(int i=1;i<=n;++i){
		if(lasta==lastb){
			if(lasta!=a[i])++ans;
			lasta=a[i];
		}
		else{
			if(lasta==a[i]){
				++ans;
				lastb=a[i];
			}
			else if(lastb==a[i]){
				++ans;
				lasta=a[i];
			}
			else{
				++ans;
				if(a[i+1]==lasta)lasta=a[i];
				else lastb=a[i];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
