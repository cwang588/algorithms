#include <iostream>
#include <cstdio>

using namespace std;

int a,b,m,temp,phi,ans=1;
bool flag;

int main()
{
    int i;
    char c;

    scanf("%d%d",&a,&m);

    temp=phi=m;

    for (i=2;i*i<=m;++i) //����phi
    {
        if (temp%i==0)
        {
            phi=phi-phi/i;
            while (temp%i==0)
            {
                temp/=i;
            }
        }
    }
    if (temp>1)
    {
        phi=phi-phi/temp;
    }

    while (!isdigit(c=getchar())); //�߶���b��ȡģ
    for (;isdigit(c);c=getchar())
    {
        b=b*10+c-'0';
        if (b>=phi)
        {
            flag=true;
            b%=phi;
        }
    }
    if (flag) //ֻ��b>=phiʱ��b+=phi
    {
        b+=phi;
    }

    for (i=20;i>=0;--i) //�����ݣ����Ǳ����
    {
        ans=1ll*ans*ans%m;
        if (b&(1<<i))
        {
            ans=1ll*ans*a%m;
        }
    }

    cout<<ans;

    return 0;
}
