#include<bits/stdc++.h>
using namespace std;
struct monster{
	long long a,b;
}m[100005];
bool cmp(monster x,monster y){
	return x.a<y.a;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long A,B;
		scanf("%I64d%I64d%d",&A,&B,&n); 
		for(int i=1;i<=n;++i)scanf("%I64d",&m[i].a);
		for(int i=1;i<=n;++i)scanf("%I64d",&m[i].b);
		sort(m+1,m+1+n,cmp);
		bool ky=true;
		for(int i=1;i<n;++i){
			long long num=(m[i].b-1)/A+1;
			B-=num*m[i].a;
			if(B<=0){
				ky=false;
				break;
			}
		}
		if(!ky){
			printf("NO\n");
			continue;
		}
		long long num=(m[n].b-1)/A;
		B-=num*m[n].a;
		if(B>0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
