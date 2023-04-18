#include<bits/stdc++.h>
using namespace std;
char a[105];	
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k>>(a+1);
		if(k==0){
			printf("YES\n");
			continue;
		}
		bool ky=true; 
		for(int i=1;2*i<=n;++i){
			if(a[i]!=a[n-i+1]){
				if(i>k)ky=true;
				else ky=false;
				break;
			}
		}		
		if(n%2==0&&k==n/2)ky=false;
		if(ky)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
