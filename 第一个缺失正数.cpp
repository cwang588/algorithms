#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool f[100005];
int main()
{
	//freopen("test.txt","r",stdin);
    char line[1000001];
    while (cin.getline(line, 1000000)) 
	{
		memset(f,false,sizeof(f));
		int num=0,i=0;
 		while(i<strlen(line))
 		{
 			int fu=1;
 			int t=0;
 			++num;
 			if(line[i]=='-')
			{
				fu=-1;
				++i;
			} 
 			while(line[i]!=','&&i<strlen(line))
 			{
 				t=t*10+line[i]-'0';
 				++i;
 			}
 			f[t*fu]=true;
 			++i;
		}
		for(int j=1;;++j)
			if(!f[j])
			{
				printf("%d\n",j);
				break;
			}
    }
    
    return 0;
}
