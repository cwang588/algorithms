#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,tmp;
		scanf("%d%d",&n,&tmp);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		bool ky=true;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i){
			if(a[i]>tmp){
				if(i<3){
					ky=false;
					break;
				}
				else{
					if(a[1]+a[2]>tmp){
						ky=false;
						break;
					}
				}
			} 
		}
		if(ky)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
