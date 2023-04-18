#include<bits/stdc++.h>
using namespace std;
struct point{
	int pos;
	long long value;
}p1[500005],p2[500005];
unordered_map<int,long long>m;
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;++i)scanf("%d%lld",&p1[i].pos,&p1[i].value);
	for(int i=1;i<=b;++i)scanf("%d%lld",&p2[i].pos,&p2[i].value),m[p2[i].pos]=p2[i].value;
	long long ans=0;
	for(int i=1;i<=a;++i)ans+=p1[i].value*m[p1[i].pos];
	printf("%lld\n",ans);
	return 0;
}
