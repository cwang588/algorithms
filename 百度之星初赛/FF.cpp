#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int t,x,y,z,upp1,upp2,upp3;
int calc(int a,int b,int c)
{
    int res=1e9;
    upp1=min((1000+b-1)/b,(1000+a-1)/a);
    for(int i=0;i<=upp1;++i)
    {
        int nowa=1000-i*b;
        int nowb=1000-i*a;
        int ano=(nowa+c-1)/c;
        if(nowa<=0)    ano=0;
        int bno=(nowb+c-1)/c;
        if(nowb<=0)    bno=0;
        int hur=0;
        if(a>b)
        {
            for(int j=1;j<=ano;++j)
            {
                hur+=a;
                if(hur>=1000)
                {
                    ano=1e9;    
                    break;
                }
            }
            for(int j=1;j<=bno;++j)
            {
                hur+=b;
                if(hur>=1000&&j!=bno)
                {
                    bno=1e9;
                    break;
                }
            }
            res=min(res,i+ano+bno);    
        }
        else
        {
            for(int j=1;j<=bno;++j)
            {
                hur+=b;
                if(hur>=1000)
                {
                    bno=1e9;    
                    break;
                }
            }
            for(int j=1;j<=ano;++j)
            {
                hur+=a;
                if(hur>=1000&&j!=ano)
                {
                    ano=1e9;
                    break;
                }
            }
            res=min(res,i+ano+bno);    
        }
        if(res==664)
        {
            printf("%d %d %d %d %d %d",i,ano,bno,a,b,c);
            exit(0);
        } 
    }
    return res;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&x,&y,&z);
        printf("%d\n",min(min(calc(x,y,z),calc(y,z,x)),calc(z,x,y)));
    }
    return 0;
}
