#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int cnt=0;
		for(int i=1;i<=4;++i){
			int t;
			cin>>t;
			if(t)++cnt;
		}
		if(cnt==0)cout<<"Typically Otaku\n";
		else if(cnt==1)cout<<"Eye-opener\n";
		else if(cnt==2)cout<<"Young Traveller\n";
		else if(cnt==3)cout<<"Excellent Traveller\n";
		else cout<<"Contemporary Xu Xiake\n";
	}
	
	return 0;
}
