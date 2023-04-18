#include<bits/stdc++.h>
using namespace std;
char s[1005];
struct point
{
	char c;
	int nxt,pre;
	point()
	{
		nxt=0;
		pre=0;
	}
}p[1005];
int num;
void in(char c)
{
	p[++num].c=c;
	p[num-1].nxt=num;
	p[num].pre=num-1;
	p[num].nxt=-1;
}
void Delete(int index)
{
	if(!p[index].nxt)
	{
		p[p[index].pre].nxt=-1;
		return;
	}
	p[p[index].nxt].pre=p[index].pre;
	p[p[index].pre].nxt=p[index].nxt;
}
int main()
{
	int n;	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>s[i];
	int ans=0;
	for(int i=1;i<=n;++i)in(s[i]);
	for(int i=25;i>=1;--i)
	{
		char now=(char)('a'+i);
		for(int cnt=1;cnt<=105;++cnt)
		{
			int nowp=0;
			while(nowp!=-1)
			{
				if(p[nowp].c!=now)
				{
					nowp=p[nowp].nxt;
					continue;
				}
				bool ky=false;
				if(p[nowp].pre&&p[nowp].c==p[p[nowp].pre].c+1)ky=true;
				if(p[nowp].nxt!=-1&&p[nowp].c==p[p[nowp].nxt].c+1)ky=true;
				int tmp=nowp;
				nowp=p[nowp].nxt;
				if(ky)
				{
					++ans;
					Delete(tmp);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
