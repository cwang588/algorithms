#include<iostream>
#include<algorithm> 
using namespace std;
int n,s,a,b,x_,y_,can,rest,ans;
struct apple{
    int xi,yi;
}ap[50005];
int cmp(apple x,apple y){
    return x.yi<y.yi;
}
int main(){
//	freopen("zz15214.in","r",stdin);
//	freopen("zz15214.out","w",stdout);
    cin>>n>>s>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>x_>>y_;
        if(x_<=a+b){
            can++;
            ap[can].xi=x_;
            ap[can].yi=y_;
        }
    }
    sort(ap+1,ap+can+1,cmp);
    rest=s;
    ans=0;
    for(int i=1;rest>=ap[i].yi&&i<=can;i++){
        ans++;
        rest-=ap[i].yi;
    }
    cout<<ans<<"\n";
    return 0;
} 
