#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int tong[100005]; 
struct nn
{
	int shu,sum;
}n[100005];
bool cmp(nn a,nn b)
{
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	return a.shu<b.shu;
}
int main()
{
	freopen("test.txt","r",stdin); 
    char line[1000001];
    while (cin.getline(line, 1000000)) 
	{
		int Max=0,Min=99999999;
  		int num=0,i=0;
  		while(i<strlen(line)&&line[i]!=' ')
  		{
  			++num;
  			int t=0;
  			while(line[i]!=','&&i<strlen(line)&&line[i]!=' ')
  			{
  				t=t*10+line[i]-'0';
  				++i;
  			}
  			Max=max(Max,t);
  			Min=min(Min,t);
  			++tong[t];
  			if(line[i]==' ')
  				break;
  			++i;
  		}
  		++i;
  		int r=0;
  		while(i<strlen(line))
  		{
  			r=r*10+line[i]-'0';
  			++i;
  		}
  		num=0;
  		for(int j=Min;j<=Max;++j)
  			if(tong[j])
  			{
  				++num;
  				n[num].shu=j;
  				n[num].sum=tong[j];
  			}
  		sort(n+1,n+1+num,cmp);
  		for(int j=1;j<=r;++j)
  		{
  			printf("%d",n[j].shu);
  			if(j!=r)
  				printf(",");
  			else
  				printf("\n");
  		}
    }
    
    return 0;
}
