#include <iostream>
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
unsigned long long quickPower(int a,int b)//����a��b�η�
{
    unsigned long long ans=1,base=a;//ansΪ�𰸣�baseΪa^(2^n)
    while(b>0)//b��һ���仯�Ķ��������������û������
    {
        if(b&1)
		{//&��λ���㣬b&1��ʾb�ڶ����������һλ�ǲ���1������ǣ�
            ans*=base;//��ans���϶�Ӧ��a^(2^n)
            ans%=mod;
        }
		base*=base;//base�Գˣ���a^(2^n)���a^(2^(n+1))
        base%=mod;
		b>>=1;//λ���㣬b����һλ����101���10�������ұߵ�1�Ƶ��ˣ���10010���1001������b�ڶ����������һλ�Ǹոյĵ����ڶ�λ���������b & 1ʳ�ø���
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
