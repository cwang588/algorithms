#include<bits/stdc++.h>
using namespace std;
int a[100005],pos[100005],Max[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],pos[a[i]]=i;
		for(int i=1;i<=n;++i)Max[i]=max(pos[i],Max[i-1]);
		int cnt=0,r=0;
		for(int i=1;i<=n;++i){
			if(i>r){
				++cnt;
				r=Max[a[i]];
			}
			else r=max(r,Max[a[i]]);
		}
		cout<<cnt<<"\n";
		
	}
	
	
	return 0;
}