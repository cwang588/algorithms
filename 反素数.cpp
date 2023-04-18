#include<cstdio>
using namespace std;
int M; 
int main()
{
	printf("int db[]={\n");
	for(int i=1;i<=2000000000;++i)
	{
		int num=0;
		for(int j=1;j*j<=i;++j)
		{
			if(i%j==0)
			{
				++num;
				if(j*j!=i)
					++num;
			}
		}
		if(num>M)
		{
			M=num;
			printf("%d,",i);
		}
	}
	printf("};");
	return 0;
}
