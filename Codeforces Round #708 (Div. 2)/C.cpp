#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		if(n%2)printf("%d %d %d\n",n/2,n/2,1);
		else{
			int tmp=n/2;
			if(tmp%2==0)printf("%d %d %d\n",tmp,tmp/2,tmp/2);
			else printf("%d %d %d\n",tmp/2*2,tmp/2*2,2);
		}
	}
	return 0;
}
