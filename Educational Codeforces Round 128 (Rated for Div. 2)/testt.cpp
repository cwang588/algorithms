#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	priority_queue<int,vector<int>,greater<int> >q;
	long long ans=0;
	for(int i=1;i<=n;++i){
		if(q.size()<(i+1)/2){
			ans+=a[i];
			q.push(a[i]);
		}
		else{
			if(q.top()<a[i]){
				ans-=q.top();
				ans+=a[i];
				q.pop();
				q.push(a[i]);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}