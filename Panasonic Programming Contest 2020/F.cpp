#include<bits/stdc++.h>
using namespace std;
bool judge(int x)
{
	if(x==1)return true;
	if(x%3==2)return false;
	return judge((x-1)/3+1);
}
int main()
{
	for(int i=1;i<=243;++i)
	{
		if(judge(i))
			printf("%d\n",i);
	}
	
	return 0;
}
