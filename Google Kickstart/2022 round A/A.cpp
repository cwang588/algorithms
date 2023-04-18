#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		string a,b;
		cin>>a>>b;
		int now=0,cnt=0,m=a.length(),n=b.length();
		bool ky=true;
		for(int i=0;i<m;++i){
			while(now<=n&&b[now]!=a[i])++now,++cnt;
			if(now>n){
				ky=false;
				break;
			}
			++now;
			if(i==m-1)cnt+=n-now;
		}
		cout<<"Case #"<<Case<<": ";
		if(!ky)cout<<"IMPOSSIBLE\n";
		else cout<<cnt<<"\n";
		
	}
	
	return 0;
}