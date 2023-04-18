#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("1580.in","r",stdin);
//	freopen("1580.out","w",stdout);
	string s;
	while(cin>>s){
		if(s==".")return 0;
		int n=s.length();
		for(int i=1;i<=n;++i){
			if(n%i)continue;
			bool ky=true;
			for(int j=0;j<i;++j){
				for(int k=0;k<n/i;++k){
					if(s[k*i+j]!=s[j]){
						ky=false;
						break;
					}
				}
			}
			if(ky){
				printf("%d\n",n/i);
				break;
			}
		}	
	}
	return 0;
}
