#include<bits/stdc++.h>
using namespace std;
int num[200005],l,r;
int main(){
	l=100001,r=100000;
	int n;
	cin>>n;
	int now=0;
	for(int i=1;i<=n;++i){
		char t;
		cin>>t;
		if(t=='A'){
			cin>>t;
			if(t=='L')num[--l]=++now;
			else num[++r]=++now;
		}
		else{
			int k;
			cin>>t>>k;
			if(t=='L')l+=k;
			else r-=k;
		}
	}
	for(int i=l;i<=r;++i)cout<<num[i]<<"\n";
	
	return 0;
}