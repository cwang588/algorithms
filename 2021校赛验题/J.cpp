#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int num1=0,num2=0,num3=0,n=s.length();
	for(int i=0;i<n;++i){
		if(s[i]=='a')++num1;
		else if(s[i]=='b')++num2;
		else ++num3;
	}
	if(num1<num2)swap(num1,num2);
	if(num2<num3)swap(num2,num3);
	if(num1<num2)swap(num1,num2);
	if(num1-num3>=2)printf("NO\n");
	else printf("YES\n");
	return 0;
}
