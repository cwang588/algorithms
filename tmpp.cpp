#include<bits/stdc++.h>
using namespace std;
string s;
bool check(char a,char b){
	if(a=='0'||a>'2')return false;
	if(a=='2'&&b>'6')return false;
	return true;
}
int main(){

	cin>>s;
	int n=s.length();
	long long x=1,y=0;
	for(int i=0;i<n;++i){
		long long tmp=0;
		if(s[i]!='0'){
			tmp=x;
			if(i>=1&&check(s[i-1],s[i]))tmp+=y;
		}
		else{
			if(i>=1&&check(s[i-1],s[i]))tmp=y;
		}
		y=x,x=tmp;
	}
	cout<<x<<"\n";
	return 0;
}