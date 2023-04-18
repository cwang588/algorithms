#include<cstdio>
#include<cstring>

int p[15]={0,999999751,999999757,999999761,999999797,999999883};
char s[1000005],a[1000005],b[1000005];
int alen,slen,blen,cnt=1,hash[10],ha[10],_pow[10];
int main()
{
	scanf("%s",s+1);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int alen=strlen(a+1);
	int blen=strlen(b+1);
	int slen=strlen(s+1);
	for(int i=1;i<=5;i++) _pow[i]=1;
	for(int i=1;i<=alen;i++)
	{
		for(int j=1;j<=5;j++)
		{
			hash[j]=hash[j]*26+a[i]-'a';
			hash[j]%=p[j];
			if(i>1)
			_pow[j]=(_pow[j]*26)%p[j];
		}
	}
	for(int i=1;i<=slen;i++)
	{
		if(i==slen&&cnt<alen)
		for(int j=i-cnt+1;j<=i;j++) printf("%c",s[j]);
		for(int j=1;j<=5;j++)
		{
			if(cnt<=alen)
				ha[j]=(ha[j]*26+s[i]-'a')%p[j];
			else
			{
				ha[j]=(ha[j]-(s[i-alen]-'a')*_pow[j])%p[j];
				ha[j]=(ha[j]*26+p[j])%p[j];
				ha[j]=(ha[j]+s[i]-'a')%p[j];
			}
		}
		if(cnt>alen) cnt=alen;
		if(cnt==alen)
		{
			bool flg=true;
			for(int j=1;j<=5;j++)
				if(ha[j]!=hash[j]) 
					flg=false;
			if(flg)
			{
				for(int j=1;j<=blen;j++) printf("%c",b[j]);
				memset(ha,0,sizeof(ha));
				cnt=0;
			}
			else if(i!=slen) printf("%c",s[i-alen+1]);
			else for(int j=i-alen+1;j<=i;j++) printf("%c",s[j]);
		}
		cnt++;
	}
	return 0;
}

