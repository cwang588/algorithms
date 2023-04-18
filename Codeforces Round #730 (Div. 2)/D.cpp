#include<bits/stdc++.h>
using namespace std;
int yihuo[105];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;++i){
			cout<<(i?i^(i-1):i)<<endl;
			fflush(stdout);
			int tmp;
			cin>>tmp;
			if(tmp)break;
		}
	}
	return 0;
}
