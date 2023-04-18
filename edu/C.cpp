#include<bits/stdc++.h>
using namespace std;
long long a[100005],minodd[100050],mineven[100005],sumodd[100050],sumeven[100050];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
		minodd[0]=mineven[0]=2147483647;
		long long ans=1919810114514114514;
		for(int i=1;i<=n;++i){
			minodd[i]=minodd[i-1];
			mineven[i]=mineven[i-1];
			sumodd[i]=sumodd[i-1];
			sumeven[i]=sumeven[i-1];
			if(i%2){
				minodd[i]=min(minodd[i],a[i]);
				sumodd[i]+=a[i];
			}
			else{
				mineven[i]=min(mineven[i],a[i]);
				sumeven[i]+=a[i];
			}
			ans=min(ans,mineven[i]*(n-i/2+1)+sumeven[i]-mineven[i]+minodd[i]*(n-i+i/2+1)+sumodd[i]-minodd[i]);
		//	ans=min(ans,mineven[i]*(n-i+i/2+1)+sumeven[i]-mineven[i]+minodd[i]*(n-i/2+1)+sumodd[i]-minodd[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
