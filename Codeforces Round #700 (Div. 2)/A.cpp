#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>(s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;++i){
			if(i%2){
				if(s[i]!='a')s[i]='a';
				else ++s[i];
			}
			else{
				if(s[i]!='z')s[i]='z';
				else --s[i];
			}
		} 
		cout<<(s+1)<<"\n";
	}
	return 0;
}
