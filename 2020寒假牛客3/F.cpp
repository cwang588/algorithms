#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
char s[1000005];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i];
    long long tot=0,ans=0,num=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='1')
        {
            ans=(ans+(num*i-tot)%mod)%mod;
            ++num;
            tot+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
