#include<bits/stdc++.h>
using namespace std;
long long a[200005];
priority_queue<long long>q;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		int ans=0;
		long long now=0;
		if(m>1){
			while(!q.empty())q.pop();
			for(int i=m;i>1;--i){
				q.push(a[i]);
				now+=a[i];
				if(now>0){
					assert(!q.empty());
					now-=2*q.top();
					q.pop();
					++ans;
				}
			}
		}
		now=0;
		while(!q.empty())q.pop();
		for(int i=m+1;i<=n;++i){
			q.push(-a[i]);
			now+=a[i];
			if(now<0){
				assert(!q.empty());
				now+=2*q.top();
				q.pop();
				++ans;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}