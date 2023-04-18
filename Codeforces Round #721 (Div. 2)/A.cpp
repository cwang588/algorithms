#include<bits/stdc++.h>
using namespace std;
int mi[50];
int main(){
	int t;
	mi[0]=1;
	for(int i=1;i<=30;++i)mi[i]=mi[i-1]*2;
	scanf("%d",&t);
	while(t--){
		int n,ans=0;
		scanf("%d",&n);
		bool ky=false,yes=false;
		for(int i=30;i>=0;--i){
			if(n>=mi[i]){
				n-=mi[i];
				if(!ky){
					ky=true;
					ans-=mi[i];
				}
			}
			if(ky)ans+=mi[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
