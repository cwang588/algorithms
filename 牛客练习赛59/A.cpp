#include<bits/stdc++.h>
using namespace std;
char s1[]="XiaoQiao",s2[]="XiaoHuiHui";
char s[100005];
int main()
{
	cin>>s;
	int n=strlen(s);
	int now1=0,now2=0;
	for(int i=0;i<n;++i) 
	{
		if(now1<=7&&s[i]==s1[now1])++now1;
		if(now2<=9&&s[i]==s2[now2])++now2; 
	}
	if(now1==8&&now2==10)printf("Happy\n");
	else printf("emm\n");
	return 0;
}
