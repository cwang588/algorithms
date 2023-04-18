#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[10],b[19];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i].first>>a[i].second;
		for(int i=1;i<=n;++i)cin>>b[i].first>>b[i].second;
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(int i=1;i<=n;++i){
			cout<<"6\n";
			cout<<a[i].first<<" "<<a[i].second<<"\n";
			cout<<a[i].first<<" "<<666+i<<"\n";
			cout<<-666-i<<" "<<666+i<<"\n";
			cout<<-666-i<<" "<<-666-i<<"\n";
			cout<<b[i].first<<" "<<-666-i<<"\n";
			cout<<b[i].first<<" "<<b[i].second<<"\n";
		}
	}
	
	
	return 0;
}