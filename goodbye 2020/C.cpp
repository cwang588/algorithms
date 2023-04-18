#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>(a+1);
		int n=strlen(a+1),ans=0;
		a[n+1]=a[n+2]=' ';
		for(int i=1;i<=n;++i){
			if(a[i]=='#')continue;
			if(a[i]==a[i+1]&&a[i]==a[i+2]){
				ans+=2;
				a[i+1]=a[i+2]='#';
			}
			else if(a[i]==a[i+2]){
				++ans;
				a[i+2]='#';
			}
			else if(a[i]==a[i+1]){
				++ans;
				a[i+1]='#';
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
