#include<stdio.h>
#include<conio.h>
#define SIZE 10
int FindEvenNmbers(int list[],int even[])
{
	int count,i;
	count=0;
	for(i=0;i<SIZE;i++)
	{
		if(list[i]%2==0)
		{
			++count;
		    even[count]=list[i];
		}
	}
	return count;
}
int main()
{
	int list[SIZE];
	int even[SIZE];
	int count;
	int i;
	printf("����%d��������\n",SIZE);
	for(i=0;i<SIZE;i++)
	   scanf("%d",&list[i]);
	count=FindEvenNmbers(list,even);
	printf("��%d��ż����\n",count);
	for(i=1;i<=count;i++)
	   printf("%d ",even[i]);
	printf("\n");
	printf("�밴���������...");
	getch();
	return 0;
}
