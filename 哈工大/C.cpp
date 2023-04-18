#include<bits/stdc++.h>
using namespace std;
long long base[5000005]={0,9,189,2889,38889,488889,5888889,68888889,788888889,8888888889,98888888889,1088888888889,11888888888889,128888888888889,1388888888888889,14888888888888889,158888888888888889};
long long tmp[10005];
long long ppow(long long a,long long b)
{
	long long re=1;
	for(int i=1;i<=b;++i)
		re*=a;
	return re;
}
int main()
{
//	int t;
//	scanf("%d",&t);
//	while(t--)
//	{
//		memset(tmp,0,sizeof(tmp));
//		long long pos;
//		cin>>pos;
for(long long pos=1;;++pos)
{
		if(pos==1000000000000000000)
		{
			printf("3\n");
			continue;
		}
		long long ws=0;
		for(int i=1;i<=17;++i)
		{
			if(base[i-1]<pos&&pos<=base[i])
			{
				ws=i;
				pos-=base[i-1];
				break;
			}
		}
		if(!ws)
			return !printf("%lld",pos);
//		long long tep=ppow(10,ws-1)+(pos/ws),re=pos%ws;
//		if(!re)
//		{
//			--tep;
//			re=ws;
//		}
//		long long now=ws;
//		while(tep)
//		{
//			tmp[now--]=tep%10;
//			tep/=10;
//		}
		//printf("%lld\n",tmp[re]);
       // cout<<tmp[re]<<endl;
	//}
}
	return 0;
}
