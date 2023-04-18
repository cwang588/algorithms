#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dr[10005];
int main()
{
//	freopen("test.txt","r",stdin);
    char line[1000001];
    while (cin.getline(line, 1000000)) 
	{
		memset(dr,0,sizeof(dr));
		int n=0,i=0;
		while(i<strlen(line))
		{
			++n;
			while(i<strlen(line)&&line[i]!=' ')
			{
				dr[n]=dr[n]*10+line[i]-'0';
				++i;
			}
			++i;
		}
		sort(dr+1,dr+1+n);
		int num=0;
		for(int j=1;j<=n;++j)
			dr[j]=(dr[j]+1)/2;
		int now=0;
		int j=1;
		for(int j=1;j<=n;++j)
		{
			if(dr[j]==now)
				++now;
			else if(dr[j]>now)
			{
				num+=dr[j]-now;
				now=dr[j]+1;
			}
			else;
		}
		printf("%d\n",num);
    }
    
    return 0;
}
