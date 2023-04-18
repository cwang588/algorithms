#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a,b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		int score=a*s.length();
		if(b>=0)score+=b*s.length();
		else{
			int cnt1=0,cnt2=0;
			if(s[0]=='0')++cnt1;
			else ++cnt2;
			for(int i=1;i<s.length();++i){
				if(s[i]!=s[i-1]){
					if(s[i]=='0')++cnt1;
					else ++cnt2;
				}
			}
			score+=b*(min(cnt1,cnt2)+1);
		}
		cout<<score<<endl;
	}
	
	return 0;
}
