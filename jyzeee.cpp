#include<stdio.h>
int search(int a,int b,int c,int d,int e)
{
	for(int i=a;;++i)
		if(i%a==0&&i%b==0&&i%c==0&&i%d==0&&i%e==0)
			return i;
}
int main()
{
	int x,y,m,n,t,p;
	printf("请输入五个正整数：");
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&t);
    p=search(x,y,m,n,t);
    printf("%d",p);
	return 0;
}
