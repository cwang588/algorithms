#include<bits/stdc++.h>
using namespace std;
__int128 a[100005];
inline __int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
bool cmp(__int128 x,__int128 y){
	return x>y;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n,cmp);
	long long x=0,y=0;
	for(int i=1;i<=n;++i){
		if(x*x<=a[i]*2*x*y+a[i]*y*y){
			x+=a[i];
			++y;
		}
	}
	printf("%.8f\n",1.0*x*x/y);
	return 0;
}
