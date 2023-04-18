#include <iostream>
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
unsigned long long quickPower(int a,int b)//是求a的b次方
{
    unsigned long long ans=1,base=a;//ans为答案，base为a^(2^n)
    while(b>0)//b是一个变化的二进制数，如果还没有用完
    {
        if(b&1)
		{//&是位运算，b&1表示b在二进制下最后一位是不是1，如果是：
            ans*=base;//把ans乘上对应的a^(2^n)
            ans%=mod;
        }
		base*=base;//base自乘，由a^(2^n)变成a^(2^(n+1))
        base%=mod;
		b>>=1;//位运算，b右移一位，如101变成10（把最右边的1移掉了），10010变成1001。现在b在二进制下最后一位是刚刚的倒数第二位。结合上面b & 1食用更佳
    }
    return ans;
}
int main()
{
	//freopen("test.txt","r",stdin);
    char line[1000001];
    while (cin.getline(line, 1000000)) 
	{
		int a=0,b=0,c=0,d=0;
		int i=0;
		while(line[i]!=' ')
		{
			a=a*10+line[i]-'0';
			++i;
		}
		++i;
		while(line[i]!=' ')
		{
			b=b*10+line[i]-'0';
			++i;
		}
		++i;
		while(line[i]!=' ')
		{
			c=c*10+line[i]-'0';
			++i;
		}
		++i;
		while(line[i]!=' '&&i<strlen(line))
		{
			d=d*10+line[i]-'0';
			++i;
		}
		cout<<quickPower(2,a+c)*(d+b+1)%mod+quickPower(2,b+a)%mod-quickPower(2,a)*(b+1)%mod%mod<<endl; 
    }
    
    return 0;
}
