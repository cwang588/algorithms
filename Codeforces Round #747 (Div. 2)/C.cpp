#include<bits/stdc++.h>
using namespace std;
char s[300005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		char c;
		cin>>n>>c>>(s+1);
		bool ky=true;
		for(int i=1;i<n;++i){
			if(s[i]!=c){
				ky=false;
				break;
			}
		}
		if(ky){
			if(s[n]==c)cout<<"0\n";
			else cout<<"1\n"<<n-1<<"\n";
		}
		else{
			if(s[n]==c)cout<<"1\n"<<n<<"\n";
			else{
				bool ans=false;
				for(int i=1;i<=n;++i){
					if(s[i]!=c)continue;
					bool ky=true;
					for(int j=1;j*i<=n;++j){
						if(s[i*j]!=c){
							ky=false;
							break;
						}
					}
					if(ky){
						cout<<"1\n"<<i<<"\n";
						ans=true;
						break;
					}
				}
				if(!ans)cout<<"2\n"<<n-1<<" "<<n<<"\n";
			}
		}
	}
	
	
	return 0;
}