#include<bits/stdc++.h>
using namespace std;
int s[3][3];
void hanoi(int n,int a,int b,int c)
{
    if(n==1)
    {
        ++s[a][c];
        return;
    }
    hanoi(n-1,a,c,b);
    ++s[a][c];
    hanoi(n-1,b,a,c);
}
int main()
{
    for(int n=1;n<=15;++n)
    {
        memset(s,0,sizeof(s));
        printf("%d\n",n);
        hanoi(n,0,1,2);
        for(int i=0;i<=2;++i)
        {
            for(int j=0;j<=2;++j)
                printf("%d ",s[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
