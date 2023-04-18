#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int Max1=0,Max2=0,Max3=0,Max4=0;
		for(int i=1;i<=n;++i){
			int x,y;
			cin>>x>>y;
			Max1=max(Max1,x);
			Max2=max(Max2,-x);
			Max3=max(Max3,y);
			Max4=max(Max4,-y);
		}
		cout<<(Max1+Max2+Max3+Max4)*2<<"\n";
	}
	
	return 0;
}