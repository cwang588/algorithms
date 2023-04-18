#include<bits/stdc++.h>
using namespace std;
vector<int>pos[105];
long long a[500005],b[500005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=100;++i)pos[i].push_back(0);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		pos[a[i]].push_back(i);
		b[i]=b[i-1]+a[i];
	}
	for(int i=0;i<=100;++i)pos[i].push_back(n+1);
	long long ans=0;
	for(int i=1;i<=n;++i){
		int pos1=0,pos2=n;
		for(int j=0;j<a[i];++j){
			pos1=max(pos1,pos[j][lower_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin()-1]);
			pos2=min(pos2,pos[j][lower_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin()]);
		}
		ans=max(ans,(b[pos2-1]-b[pos1])*a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
