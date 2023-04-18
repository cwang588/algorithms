#include<bits/stdc++.h>
using namespace std;
set<pair<long long,long long> >s;
long long q[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		s.clear();
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			long long l,r;
			cin>>l>>r;
			s.insert(pair{l,r});
		}
		for(int i=1;i<=m;++i)cin>>q[i];
		cout<<"Case #"<<Case<<": ";
		for(int i=1;i<=m;++i){
			auto it=upper_bound(s.begin(),s.end(),pair{q[i],q[i]});
			if(it==s.end()){
				--it;
				auto now=*it;
				if(now.second>q[i]){
					cout<<q[i]<<" ";
					s.erase(it);
					if(q[i]!=now.first)s.insert(pair{now.first,q[i]-1});
					s.insert(pair{q[i]+1,now.second});
				}
				else{
					cout<<now.second<<" ";
					s.erase(it);
					if(now.first!=now.second)s.insert(pair{now.first,now.second-1});
				}
			}
			else if(it==s.begin()){
				auto now=*it;
				cout<<now.first<<" ";
				s.erase(it);
				if(now.first!=now.second)s.insert(pair{now.first+1,now.second});
			}
			else{
				auto nxt=*it;
				--it;
				auto pre=*it;
				if(pre.second>=q[i]){
					cout<<q[i]<<" ";
					s.erase(it);
					if(pre.first<q[i])s.insert(pair{pre.first,q[i]-1});
					if(pre.second>q[i])s.insert(pair{q[i]+1,pre.second});
				}
				else{
					if(q[i]-pre.second<=nxt.first-q[i]){
						cout<<pre.second<<" ";
						s.erase(it);
						if(pre.first<pre.second)s.insert(pair{pre.first,pre.second-1});
					}
					else{
						cout<<nxt.first<<" ";
						++it;
						s.erase(it);
						if(nxt.first<nxt.second)s.insert(pair{nxt.first+1,nxt.second});
					}
				}
			}
		}
		cout<<"\n";
	}
	
	
	return 0;
}