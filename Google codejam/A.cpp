#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		cin>>n>>m;
		printf("Case #%d:\n",Case);
		for(int i=1;i<=2*n+1;++i){
			if(i==1){
				cout<<"..";
				for(int j=3;j<=2*m+1;++j){
					if(j%2)cout<<"+";
					else cout<<"-";
				}
			}
			else if(i==2){
				cout<<".";
				for(int j=2;j<=2*m+1;++j){
					if(j%2)cout<<"|";
					else cout<<".";
				}
			}
			else{
				if(i%2){
					for(int j=1;j<=2*m+1;++j){
						if(j%2)cout<<"+";
						else cout<<"-";
					}
				}
				else{
					for(int j=1;j<=2*m+1;++j){
						if(j%2)cout<<"|";
						else cout<<".";
					}
				}
			}
			cout<<"\n";
		}
	}
	
	return 0;
}