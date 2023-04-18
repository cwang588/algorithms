#include<bits/stdc++.h>
using namespace std;
char s[]={'*','(',')'};
int main()
{
	srand((unsigned)time(0));
	freopen("in.txt","w",stdout);
	printf("10\n");
	for(int i=1;i<=10;++i)
	{
		for(int j=1;j<=10;++j)cout<<s[rand()%3];
		cout<<endl;
	}
	return 0;
}
