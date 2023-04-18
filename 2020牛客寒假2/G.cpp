#include<bits/stdc++.h>
using namespace std;
long long mod[3]={19260817,998244353,1000000007};
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d,e,f,g;
        cin>>a>>b>>c>>d>>e>>f>>g;
        bool ky=true;
        for(int i=0;i<3;++i)
        {
            long long tot=quickpower(a,d,mod[i])+quickpower(b,e,mod[i])+quickpower(c,f,mod[i]);
            tot%=mod[i];
            if(tot!=g%mod[i])
            {
                ky=false;
                break;
            }
        }
        printf("%s\n",ky?"Yes":"No");
    }
    return 0;
}
