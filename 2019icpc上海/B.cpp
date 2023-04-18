#include<bits/stdc++.h>
using namespace std;
string s[100005];
bool judge(int x,int y){
	if(s[x].length()>s[y].length())return false;
	int n=s[x].length();
	for(int i=0;i<n;++i){
		if(s[x][i]!=s[y][i])return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>s[i];
		sort(s+1,s+1+n);
		bool ky=true;
		for(int i=2;i<=n;++i){
			if(judge(i-1,i)){
				ky=false;
				cout<<"Case #"<<Case<<": No\n";
				break;
			}
		}
		if(ky)cout<<"Case #"<<Case<<": Yes\n";
	}
	return 0;
}