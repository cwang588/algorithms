#include<bits/stdc++.h>
using namespace std;
int book[5000005],op[45];
int ans[25]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,0};
int main()
{
	int n,cd=0,wz=0;
	scanf("%d",&n);
	book[0]=1;
	for(int i=1;i<=21;++i)
		book[ans[i]]=1;
	if(book[n]) 
	{
		printf("0");
		return 0;
	}
	while(1)
	{
		for(int i=0;(1<<i)<=n;++i)
			if(!((1<<i)&n)) 
				wz=i;
		n^=ans[wz];
		cd++;
		op[cd]=wz;
		if(book[n])
		    break;
		else 
			++n;
		cd++;
		op[cd]=-1;
		if(book[n]) 
			break; 
	}
	printf("%d\n",cd);
	for(int i=1;i<=cd;++i)
		if(op[i]!=-1)
			printf("%d ",op[i]+1);
	return 0;
}
