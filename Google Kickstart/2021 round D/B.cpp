#include<bits/stdc++.h>

using namespace std;
map<long long,pair<int,int> >num;
struct point{
	long long pos;
	int num;
	bool type;
};
bool cmp(point x,point y){
	if(x.pos!=y.pos)return x.pos<y.pos;
	return x.type>y.type;
}
signed main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		num.clear();
		int n;
		long long c;
		cin>>n>>c;
		for(int i=1;i<=n;++i){
			long long l,r;
			cin>>l>>r;
			++num[l].first,++num[r].second;
		}
		int cnt=0;
		vector<pair<int,long long> >v;
		long long last=0;
		for(auto now:num){
			if(cnt>0)v.push_back(pair{-cnt,now.first-last-1});
			cnt-=now.second.second;
			v.push_back({-cnt,1});
			cnt+=now.second.first;
			last=now.first;
		}
		sort(v.begin(),v.end());
		long long ans=n;
		for(auto now:v){
			if(c>=now.second){
				ans+=now.second*(-now.first);
				c-=now.second;
			}
			else{
				ans+=c*(-now.first);
				c=0;
			}
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	return 0;
}