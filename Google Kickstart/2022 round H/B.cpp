#include<bits/stdc++.h>
using namespace std;
long long getdis(int x,int y){
	return 1ll*x*x+1ll*y*y;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		long long r1,r2;
		cin>>r1>>r2;
		cin>>n;
		vector<pair<long long,bool> >now;
		for(int i=1;i<=n;++i){
			int x,y;
			cin>>x>>y;
			if(getdis(x,y)<=(r1+r2)*(r1+r2))now.push_back(make_pair(getdis(x,y),false));
		}
		cin>>m;
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			if(getdis(x,y)<=(r1+r2)*(r1+r2))now.push_back(make_pair(getdis(x,y),true));
		}
		if(!now.size()){
			cout<<"Case #"<<Case<<": "<<0<<" "<<0<<"\n";
			continue;
		}
		sort(now.begin(),now.end());
		int ans1=0,ans2=0;
		if(!now[0].second){
			ans1=1;
			for(int i=1;i<now.size();++i){
				if(now[i].second)break;
				++ans1;
			}
		}
		else{
			ans2=1;
			for(int i=1;i<now.size();++i){
				if(!now[i].second)break;
				++ans2;
			}
		}
		cout<<"Case #"<<Case<<": "<<ans1<<" "<<ans2<<"\n";
	}
	
	
	return 0;
}