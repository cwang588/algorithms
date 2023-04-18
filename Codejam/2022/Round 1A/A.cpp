#include<bits/stdc++.h>
using namespace std;
char a[10005];
bool usd[10005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		cin>>(a+1);
		int n=strlen(a+1);
		for(int i=1;i<=n;++i)usd[i]=false;
		int now=1;
		for(int i=2;i<=n;++i){
			if(a[i]==a[now])continue;
			if(a[i]>a[now]){
				for(int j=now;j<i;++j)usd[j]=true;
			}
			now=i;
		}
		cout<<"Case #"<<Case<<": ";
		for(int i=1;i<=n;++i){
			cout<<a[i];
			if(usd[i])cout<<a[i];
		}
		cout<<"\n";
	}
	
	
	return 0;
}