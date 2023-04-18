#include<bits/stdc++.h>
using namespace std;
char now[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,cnt1=0,cnt2=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>now[i];
			if(now[i]=='L')++cnt1;
			else ++cnt2;
		}
		if(cnt1&&cnt2){
			for(int i=1;i<n;++i){
				if(now[i]=='L'){
					if(now[i+1]=='R'){
						cout<<i<<"\n";
						break;
					}
				}
				else{
					if(now[i+1]=='L'){
						cout<<"0\n";
						break;
					}
				}
			}
		}
		else cout<<"-1\n";
	}
	
	
	return 0;
}