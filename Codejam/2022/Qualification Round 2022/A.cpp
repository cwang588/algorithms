#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		cin>>n>>m;
		cout<<"Case #"<<Case<<":\n";
		for(int i=1;i<=n;++i){
			if(i==1)cout<<"..+";
			else cout<<"+-+";
			for(int i=1;i<m;++i)cout<<"-+";
			cout<<"\n";
			if(i==1)cout<<".";
			else cout<<"|";
			for(int i=1;i<=m;++i)cout<<".|";
			cout<<"\n";
		}
		for(int i=1;i<=m;++i)cout<<"+-";
		cout<<"+\n";
	}
	
	return 0;
}