#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int cnt=0;
		for(int i=1;i<=4;++i){
			int tmp;
			cin>>tmp;
			if(tmp==1)++cnt;
		}
		if(!cnt)cout<<"0\n";
		else if(cnt==4)cout<<"2\n";
		else cout<<"1\n";
	}
	
	
	return 0;
}