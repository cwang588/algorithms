#include<bits/stdc++.h>
using namespace std;
int last[50];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(last,-1,sizeof(last));
		string s;
		cin>>s;
		set<char>a;
		for(auto c:s)a.insert(c);
		int n=a.size();
		bool ky=true;
		for(int i=0;i<s.length();++i){
			if(last[s[i]-'a'+1]==-1)last[s[i]-'a'+1]=i;
			else{
				if(i-last[s[i]-'a'+1]<n){
					ky=false;
					break;
				}
				last[s[i]-'a'+1]=i;
			}
		}
		if(ky)printf("YES\n");
		else printf("NO\n");
	}
	
	
	return 0;
}