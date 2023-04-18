#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int rd[100005],a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		long long ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)rd[i]=0,cin>>a[i],ans+=a[i];
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			++rd[x],++rd[y];
			if(rd[x]>1)q.push(a[x]);
			if(rd[y]>1)q.push(a[y]);
		}
		printf("%I64d ",ans);
		while(!q.empty()){
			printf("%I64d ",ans+=q.top());
			q.pop();
		}
		printf("\n");
	}
	return 0;
}
