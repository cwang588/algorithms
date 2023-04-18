#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxl 5000000
using namespace std;
char S[maxl+5],A[maxl+5],B[maxl+5];
int ls,la,lb,k,nx[maxl+5],ans[maxl+5],last=0;
int main(){
    scanf("%s%s%s",S+1,A+1,B+1);
    ls=strlen(S+1);
    la=strlen(A+1);
    lb=strlen(B+1);
    k=0;
    for(int i=2;i<=la;i++){
        while(k&&A[i]!=A[k+1])k=nx[i];
        if(A[i]==A[k+1])k++;
        nx[i]=k;
    }
    k=0;
    for(int i=1;i<=ls;i++){
        while(k&&S[i]!=A[k+1])k=nx[i];
        if(S[i]==A[k+1])k++;
        if(k==la&&i-la+1>last){
            last=i;
            ans[i-la+1]=1;
        }
    }
    for(int i=1;i<=ls;i++)
        if(ans[i]==0)printf("%c",S[i]);
        else {
            printf("%s",B+1);
            i=i+la-1;
        }
    return 0;
}

