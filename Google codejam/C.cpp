#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		int ans=0,now=0;
		for(int i=1;i<=n;++i){
			if(a[i]>now){
				++ans;
				++now;
			}
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	
	return 0;
}