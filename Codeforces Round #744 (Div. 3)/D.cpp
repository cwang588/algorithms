#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >q;
int a[2000006];
vector<pair<int,int> >v;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(a[i])q.push(make_pair(a[i],i));
		}
		int ans=0;
		v.clear();
		while(q.size()>1){
			int now1=q.top().second;
			q.pop();
			int now2=q.top().second;
			q.pop();
			a[now1]-=1;
			a[now2]-=1;
			if(a[now1]>0)q.push(make_pair(a[now1],now1));		
			if(a[now2]>0)q.push(make_pair(a[now2],now2));		
			v.push_back(make_pair(now1,now2));
			ans+=1;
		}
		cout<<ans<<"\n";
		for(auto x:v)cout<<x.first<<" "<<x.second<<"\n";
	}
	
	return 0;
}
