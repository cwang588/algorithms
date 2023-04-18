#include<bits/stdc++.h>
using namespace std;
string s;
bool judge(){
	int len=s.size();
	for(int i=0;i+3<len;++i){
		if(s[i]=='e'&&s[i+1]=='a'&&s[i+2]=='s'&&s[i+3]=='y')return false;
	}
	for(int i=0;i+6<len;++i){
		if(s[i]=='q'&&s[i+1]=='i'&&s[i+2]=='a'&&s[i+3]=='n'&&s[i+4]=='d'&&s[i+5]=='a'&&s[i+6]=='o')return false;
	}
	return true;
}
int main(){
	int n,m,cnt=0;
	cin>>n>>m;
	getchar();
	bool ky=false;
	for(int i=1;i<=n;++i){
		getline(cin,s);
		if(judge())++cnt;
		if(cnt==m+1&&!ky){
			cout<<s<<"\n";
		//	return 0;
			ky=true;
		}
	}
	if(!ky)printf("Wo AK le\n");
	return 0;
}
