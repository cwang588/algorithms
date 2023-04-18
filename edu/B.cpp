#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
	int t;	
	cin>>t;
	while(t--){
		cin>>(s+1);
		int n=strlen(s+1);
		int pos1=2147483647,pos2=0;
		for(int i=1;i<n;++i){
			if(s[i]=='1'&&s[i+1]=='1')pos1=min(pos1,i);
			if(s[i]=='0'&&s[i+1]=='0')pos2=max(pos2,i);
		}
		if(pos2>pos1)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
