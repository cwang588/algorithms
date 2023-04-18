#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int tot=0;
		for(auto c:s)tot+=c-'a'+1;
		if(s.length()==1)cout<<"Bob "<<tot<<"\n";
		else{
			cout<<"Alice ";
			if(s.length()%2)cout<<tot-2*(min(s[0],s[s.length()-1])-'a'+1);
			else cout<<tot;
			cout<<"\n";
		}
	}
	
	
	return 0;
}