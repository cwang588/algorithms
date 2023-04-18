#include<bits/stdc++.h>
using namespace std;
char t[100];
struct node{
    int x,y,z;
}a[1005];
int f1(int x){
    switch (x){
	    case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
	        return 31;
	    case 2:
	        return 28;
	    default:
	        return 30;
    }
}
int f2(int x,int y){
    while(x--){
        y += f1(x);
    }
    return y;
}
int f3(int x,int y){
    if(f2(x,y)>331)return (f2(x,y)-331);
    else if(f2(x,y)<331)return (f2(x, y)+35);
    else return 365;
}
bool cmp(node a, node b){
    return a.z < b.z;
}
int main()
{
    int n,nowm,nowd;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
    	int month,day;
        scanf("%s%d-%d",t,&month,&day);
        a[i].z=f2(month,day);
        a[i].x=month;
        a[i].y=day;
    }
    sort(a+1,a+n+1,cmp);
    int Max=(a[1].z+(365-a[n].z));
    nowm=a[1].x;
    nowd=a[1].y;
    for (int i=2;i<=n;++i){
        if((a[i].z-a[i-1].z)>Max){
            Max=a[i].z-a[i-1].z;
            nowm=a[i].x;
            nowd=a[i].y;
        }else if ((a[i].z-a[i-1].z)==Max){
            if(f3(a[i].x,a[i].y)<f3(nowm,nowd)){
                nowm=a[i].x;
                nowd=a[i].y;
            }
        }else;
    }
    if (nowd==1){
        if (nowm== 1)
            printf("12-31\n");
        else
            printf("%02d-%02d\n",nowm-1,f1(nowd-1));
    }else
        printf("%02d-%02d\n",nowm,nowd-1);
    return 0;
}