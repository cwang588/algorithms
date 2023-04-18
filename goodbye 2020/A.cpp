#include<bits/stdc++.h>
using namespace std;
int a[10005];
set<int>s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j)s.insert(a[j]-a[i]);
		}
		printf("%d\n",s.size());
		s.clear();
	}
	return 0;
}
