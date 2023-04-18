#include<bits/stdc++.h>
using namespace std;
int Min[5];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		for(int i=1;i<=4;++i)Min[i]=1e9;
		for(int i=1;i<=3;++i){
			for(int j=1;j<=4;++j){
				int col;
				cin>>col;
				Min[j]=min(Min[j],col);
			}
		}
		int tot=0;
		for(int i=1;i<=4;++i)tot+=Min[i];
		cout<<"Case #"<<Case<<": ";
		if(tot<1000000)cout<<"IMPOSSIBLE\n";
		else{
			tot=1000000;
			for(int i=1;i<=4;++i){
				int now=min(tot,Min[i]);
				cout<<now<<" ";
				tot-=now;
			}
			cout<<"\n";
		}
	}
	
	return 0;
}