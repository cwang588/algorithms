#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	cout<<v.size()<<"\n";
	for(int i=0;i<v.size();++i)cout<<v[i]<<' ';
	cout<<"\n";
	return 0;
}
