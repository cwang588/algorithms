#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x%2==y%2)return x<y;
	return x%2>y%2;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k%2){
			cout<<"YES\n";
			for(int i=1;i<=n;i+=2)cout<<i<<" "<<i+1<<"\n";
		}
		else{
			if(k%4==2){
				cout<<"YES\n";
				for(int i=1;i<=n;i+=2){
					if((i+1)%4==0)cout<<i<<" "<<i+1<<"\n";
					else cout<<i+1<<" "<<i<<"\n";
				}
			}
			else cout<<"NO\n";
		}
		
	}
	
	
	return 0;
}