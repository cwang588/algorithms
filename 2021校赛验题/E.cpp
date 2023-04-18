#include<bits/stdc++.h>
using namespace std;
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
int main(){
	__int128 x,y,z;
	x=read();
	y=read();
	z=read();
	__int128 l=0,r=1000000000000000005;
	while(l<r-1){
		__int128 m=(l+r)>>1;
		if(x*m<y*z)l=m;
		else r=m;
	}
	print(l);
	return 0;
}
