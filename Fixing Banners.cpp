#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[15];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=6;++i)
		{
			string s;
			cin>>s;
			for(int j=0;j<s.length();++j)
			{
				if(s[j]=='h')a[i][1]=1;
				else if(s[j]=='a')a[i][2]=1;
				else if(s[j]=='r')a[i][3]=1;
				else if(s[j]=='b')a[i][4]=1;
				else if(s[j]=='i')a[i][5]=1;
				else if(s[j]=='n')a[i][6]=1;
				else;
			}
		}
		for(int i=1;i<=6;++i)b[i]=i;
		if(a[1][b[1]]&&a[2][b[2]]&&a[3][b[3]]&&a[4][b[4]]&&a[5][b[5]]&&a[6][b[6]])
		{
			printf("Yes\n");
			continue;
		}
		bool ky=false;
		while(next_permutation(b+1,b+7))
		{
			if(a[1][b[1]]&&a[2][b[2]]&&a[3][b[3]]&&a[4][b[4]]&&a[5][b[5]]&&a[6][b[6]])
			{
				printf("Yes\n");
				ky=true;
				break;
			}
		}
		if(!ky)printf("No\n");
	}
	
	return 0;
}
