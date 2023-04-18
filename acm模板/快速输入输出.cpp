inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
