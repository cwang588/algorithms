#include<cstdio>

int num,book[5000005],ans[25],ln,pos,op[45];
int main()
{
	ans[0]=1;
	book[0]=1;
	for(int i=1;i<=21;i++)
	{
		ans[i]=ans[i-1]*2+1;
		book[ans[i]]=true;
	}
	scanf("%d",&num);
	if(book[num]) return !printf("0\n");
	while(1)
	{
		for(int i=0;(1<<i)<=num;i++)
			if(((1<<i)&num)==0) 
				pos=i;
		num^=ans[pos];
		op[++ln]=pos;
		if(book[num]) break;
		else num+=1;
		op[++ln]=-1;
		if(book[num]) break; 
	}
	printf("%d\n",ln);
	for(int i=1;i<=ln;i++)
		if(op[i]!=-1)
			printf("%d ",op[i]+1);
	return 0;
} 

