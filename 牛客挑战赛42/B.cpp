#include<bits/stdc++.h>
#define ll _int128
using namespace std;
ll num1,num2,num3,num4,num5,num6,num7,num8;
inline void print(__int128 x){
    if(x<0){

       putchar('-');

        x=-x;

    }

    if(x>9)

        print(x/10);

    putchar(x%10+'0');

}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		long long t;
		scanf("%lld",&t);
		if(t==1)++num1;
		else if(t==2)++num2;
		else if(t==31)++num3;
		else if(t==62)++num4;
		else if(t==1847)++num5;
		else if(t==3694)++num6;
		else if(t==57257)++num7;
		else if(t==114514)++num8;
		else;
	}
	ll ans=0;
	ans=num2*num7+num8+num4*num5+num3*num6+num2*num3*num5;
	ans*=(num1+1);
	print(ans);
	return 0;
}
