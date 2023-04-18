#include<cstdio>
using namespace std;
char a[15];
bool usd[10];
int arr[10],pos[10];
int num;
int main()
{
	scanf("%s",&a); 
	for(int i=0;i<11;++i)
		usd[a[i]-'0']=true;
	printf("int[] arr = new int[]{");
	for(int i=9;i>=0;--i)
		if(usd[i])
		{
			arr[++num]=i;
			pos[i]=num;
		}
	for(int i=1;i<=num;++i)
	{
		if(i!=num)
			printf("%d,",arr[i]);
		else
			printf("%d};\n",arr[i]);
	}
	printf("int[] index = new int[]{");
	for(int i=0;i<11;++i)
	{
		if(i!=10)
			printf("%d,",pos[a[i]-'0']-1);
		else
			printf("%d",pos[a[i]-'0']-1);
	}	
	printf("};");
	return 0;
}
