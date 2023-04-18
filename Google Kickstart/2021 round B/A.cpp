#include<bits/stdc++.h>
using namespace std;
char s[200005];
int ans[200005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n>>s+1;
		cout<<"Case #"<<Case<<": 1 ";
		ans[1]=1;
		for(int i=2;i<=n;++i){
			if(s[i]>s[i-1])ans[i]=ans[i-1]+1;
			else ans[i]=1;
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}