#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char dx[26]={'A',' ',' ',' ',' ',' ',' ','H','I',' ',' ',' ','M',' ','O',' ',' ',' ',' ','T','U','V','W','X','Y',' '};
char xx[26]={' ','d',' ','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','o','q','p',' ',' ',' ','U','v','w','x',' ',' '};
char s[1005];
int main()
{
	cin>>s;
	int l=0,r=strlen(s)-1;
	while(l<=r)
	{
		if(s[l]>='A'&&s[l]<='Z')
		{
			if(dx[s[l]-'A']!=s[r])
				return !printf("NIE");
		}
		else
		{
			if(xx[s[l]-'a']!=s[r])
				return !printf("NIE");
		}
		++l;
		--r;
	}
	return !printf("TAK");
}
