#include<bits/stdc++.h>
using namespace std;
char a[1005];
int num[30];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,' ',sizeof(a));
		memset(num,0,sizeof(num));
		cin>>a;
		int num1=0,num2=0;
		for(int i=0;i<strlen(a);++i)
		{
			if((a[i]-'a')%2==0&&!num[(a[i]-'a')])
				++num1;
			if((a[i]-'a')%2&&!num[(a[i]-'a')])
				++num2;
			++num[a[i]-'a'];
		}
		if(num1==1&&num2==1)
		{
			int even,odd;
			for(int j=0;j<26;++j)
			{
				if(num[j])
				{
					if(j%2)
						odd=j;
					else
						even=j;
				}
			}
			if(abs(even-odd)==1)
			{
				printf("No answer\n");
				continue;
			}
		}
		if(num1==1&&num2==2)
		{
			int even,odd1=0,odd2;
			for(int j=0;j<26;++j)
			{
				if(num[j])
				{
					if(j%2)
					{
						if(!odd1)
							odd1=j;
						else
							odd2=j;
					}
					else
						even=j;
				}
			}			
			if(abs(odd2-even)==1||abs(even-odd1)==1)
			{
				printf("No answer\n");
				continue;
			}				
		}
		if(num1==2&&num2==1)
		{
			int even1=-1,even2,odd;
			for(int j=0;j<26;++j)
			{
				if(num[j])
				{
					if(j%2==0)
					{
						if(even1==-1)
							even1=j;
						else
							even2=j;
					}
					else
						odd=j;
				}
			}			
			if(abs(even2-odd)==1||abs(odd-even1)==1)
			{
				printf("No answer\n");
				continue;
			}				
		}
		for(int i=0;i<26;++i)
			if(i%2==0)
			{
				while(num[i]--)
					cout<<(char)('a'+i);
			}
		for(int i=0;i<26;++i)
			if(i%2)
			{
				while(num[i]--)
					cout<<(char)('a'+i);
			}	
		cout<<endl;	
	}
	return 0;
}
