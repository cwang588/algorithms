#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int k,n;
		cin>>k>>n;
		int now=1;
		cout<<now<<" ";
		for(int i=1;i<k;++i){
			now+=i;
			if(i+1+n-now>=k)cout<<now<<" ";
			else{
				now-=i;
				for(int j=1;j<=k-i;++j)cout<<now+j<<" ";
				break;
			}
		}
		cout<<"\n";
	}
	
	return 0;
}