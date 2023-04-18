#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int f[1000005];
int a[10005];
int main()
{
	//freopen("test.txt","r",stdin);
    char line[1000001];
    while (cin.getline(line, 1000000)) 
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		int Max=0,Min=9999999;
 		int num=0,i=0;
 		while(i<strlen(line))
 		{
 			++num;
 			while(line[i]!=','&&i<strlen(line))
 			{
 				a[num]=a[num]*10+line[i]-'0';
 				++i;
 			}
 			++f[a[num]];
 			Max=max(Max,a[num]);
 			Min=min(Min,a[num]);
 			++i;
		}
		i=Min;
		int now=0,ans=0;
		while(i<=Max)
		{
			if(!f[i])
			{
				++i;
				continue;
			}
			while(f[i])
			{
				++now;
				ans=max(ans,now);
				++i;
			}
			now=0;
			++i;
		}
		printf("%d\n",ans);
    }
    
    return 0;
}
