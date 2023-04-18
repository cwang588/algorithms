#include<bits/stdc++.h>
using namespace std;
int a[100005],pos[100005],ans[5][100005];
bool usd[100005];
void jh(int x,int y){
    int pos1=pos[x],pos2=pos[y];
    swap(a[pos1],a[pos2]);
    pos[a[pos1]]=pos1;
    pos[a[pos2]]=pos2;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),pos[a[i]]=i;
    bool ky=true;
    for(int i=2;i<=n;++i){
        if(a[i]<a[i-1]){
            ky=false;
            break;
        }
    }
    if(ky)return !printf("0\n");
    int k=0;
    for(int i=1;i<=n;++i){
        if(!usd[i]&&pos[i]!=i){
        	++k;
            ans[1][2*k-1]=i;
            ans[1][2*k]=pos[i];
            usd[i]=usd[a[i]]=true;
            int now=a[i];
            jh(i,a[i]);
            while(now!=a[now]){
                if(pos[now]==a[now]){
                    usd[now]=usd[a[now]]=true;
                    break;
                }
                ++k;
                int tmp=a[now];
                ans[1][2*k-1]=now;
                ans[1][2*k]=pos[pos[now]];
                usd[pos[now]]=usd[a[now]]=true;
                jh(pos[now],a[now]);
                now=tmp;
            }
        }
    }
    ans[1][0]=k;
    ky=true;
    for(int i=2;i<=n;++i){
        if(a[i]<a[i-1]){
            ky=false;
            break;
        }
    }
    if(ky){
        printf("1\n");
        for(int i=0;i<=2*ans[1][0];++i)printf("%d ",ans[1][i]);
        return !printf("\n");
    }
    for(int i=1;i<=n;++i)usd[i]=false;
    int num=0;
    for(int i=1;i<=n;++i){
        if(a[i]!=i&&!usd[a[i]]){
            ++num;
            ans[2][num*2-1]=i;
            ans[2][num*2]=a[i];
            usd[a[i]]=true;
            usd[a[a[i]]]=true;
        }
    }
    ans[2][0]=num;
    printf("2\n");
    for(int i=0;i<=2*k;++i)printf("%d ",ans[1][i]);
    printf("\n");
    for(int i=0;i<=2*num;++i)printf("%d ",ans[2][i]);
    printf("\n");

   // system("pause");
    return 0;
}
