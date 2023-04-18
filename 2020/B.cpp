#include<bits/stdc++.h>
using namespace std;
char ss[1000005];
stack<char>s;
bool judge(char c)
{
	char tmp=s.top();
	if(c==')'&&tmp=='(')return true;
	if(c==']'&&tmp=='[')return true;
	if(c=='}'&&tmp=='{')return true;
	return false;
}
int main()
{
	//ios::sync_with_stdio(false);
//	freopen("test.in","r",stdin);
	char t;
	bool ky=true;
	cin>>(ss+1);
	int l=strlen(ss+1);
	for(int i=1;i<=l;++i)
	{
		char t=ss[i];
		if(t=='['||t=='('||t=='{')s.push(t);
		else
		{
			if(s.empty()||!judge(t))
			{
				ky=false;
				break;
			}
			s.pop();
		}
	}
	if(!s.empty()||!ky)printf("No\n");
	else printf("Yes\n");
	return 0;
}
