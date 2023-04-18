#include <stdio.h>
int a[1000000],b[1000000],c[1000000];
void seek(int a[],int b[],int c[],int k,int n){
    int i=0,j=n;
    int temp=a[i],count=0,d=0,e=0;
    for(int i=0;i<n;i++){
        if(a[i]==temp)count++;
        else if(a[i]<temp)b[d++]=a[i];
        else c[e++]=a[i];
    }
    if(k>d&&k<=d+count){
        printf("%d",temp);
        return;
    }
    else if(d>=k)seek(b,a,c,k,d);
    else seek(c,a,b,k-count-d,e);
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    seek(a,b,c,k,n);
    return 0;
}

