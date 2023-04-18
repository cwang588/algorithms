#include<cstdio>
using namespace std;
int main()
{
	int a,b,n,aa=0,bb=0;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=n;++i)
	{
		int p1,p2,q1,q2;
		scanf("%d%d%d%d",&p1,&p2,&q1,&q2);
		bool jia=false,yi=false;
		if(p1+q1==p2)
			jia=true;
		if(p1+q1==q2)
			yi=true;
		if(!(jia^yi))
			continue;
		if(jia)
			++aa;
		else
			++bb;
		if(a==aa-1)
			return !printf("A\n%d",bb);
		if(b==bb-1)
			return !printf("B\n%d",aa);
	}
	return 0;
}
