#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>dic;
unordered_map<string,int>num1,num2;
string s[25];
int main(){
	int n,m;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>s[i];
	cin>>m;
	for(int i=1;i<=m;++i){
		string a,b,c;
		cin>>a>>b>>c;
		if(dic[a]=="")dic[a]=b;
		if(c=="correct")++num1[a];
		else ++num2[a];
	}
	long long tot=1,ans=1;
	for(int i=1;i<=n;++i){
		tot*=(num1[s[i]]+num2[s[i]]);
		ans*=num1[s[i]];
	}
	if(tot==1){
		bool ky=true;
		for(int i=1;i<=n;++i){
			cout<<dic[s[i]]<<" ";
			if(num2[s[i]])ky=false;
		}
		cout<<endl;
		if(ky)cout<<"correct\n";
		else cout<<"incorrect\n";
	}
	else{
		cout<<ans<<" correct\n";
		cout<<tot-ans<<" incorrect\n";
	}
	return 0;
} 
