//manacherËã·¨ 
#include<bits/stdc++.h>
using namespace std;
char s[320005],st[30005];
int p[320005];
int change()
{
    int len=strlen(st);
    int j=2;
    s[0]='^';
    s[1]='$';
    for (int i=0;i<len;i++)
    {
        s[j++]=st[i];
        s[j++]='$';
    }
    s[j]='&';
    return j;
}
int Manacher()
{
    int len=change(),mid=1,mx=1,ans=-1;
    for (int i=1;i<len;i++)
    {
        if (i<mx)
            p[i]=min(mx-i,p[mid*2-i]);
        else
            p[i]=1;
        while (s[i-p[i]]==s[i+p[i]])
            p[i]++;
        if (mx<i+p[i])
        {
            mid=i;
            mx=i+p[i];
        }
        ans=max(ans,p[i]-1);
    }
    return ans;
}
int main()
{
    while(cin>>st)
	{
		memset(p,0,sizeof(p));
		memset(s,0,sizeof(s));
		printf("%d\n",Manacher());
	}
	return 0; 
}
