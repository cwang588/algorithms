#include<bits/stdc++.h>
using namespace std;
char s[10];
int main(){	
	cin>>(s+1);
	int n=strlen(s+1);
	if(n==4){
		int now=(s[1]-'0')*10+(s[2]-'0');
		if(now<22)printf("20");
		else printf("19");
		printf("%c%c-%c%c",s[1],s[2],s[3],s[4]);
	}
	else{
		printf("%c%c%c%c-%c%c",s[1],s[2],s[3],s[4],s[5],s[6]);
	}
	return 0;
}
