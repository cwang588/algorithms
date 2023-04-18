#include<bits/stdc++.h>
using namespace std;
deque<int>q;
int main(){
	int t;
	cin>>t;	
	while(t--){
		int n;
		cin>>n;
		q.clear();
		for(int i=1;i<=n;++i){
			int now;
			cin>>now;
			if(now<q.front()||q.empty())q.push_front(now);
			else q.push_back(now);
		}
		for(auto x:q)cout<<x<<" ";
		cout<<"\n";
	}
	return 0;
}
