#include<cstdio>
#include<iostream>
#include<algorithm> 
using namespace std;
long long n,sum,ans=1;
long long f(long long n1){
    int x,s,s1=0;
    while(n1!=0){
        s=1;
        x=n1%10;
        for(int i=2;i<=x;++i)s*=i;
        s1+=s;
        n1/=10;
    }
    return n=s1;
}
bool check(long long x){
    long long s=f(x);
    if(s==1||s==2||s==145||s==169||s==871||s==872||s==1454||s==40585||s==363601||s==){
        return false;
    }
    return true;
}
int main()
{
 cin>>n;
 if(n==1||n==2||n==145||n==169||n==871||n==872||n==1454||n==40585){
        cout<<"0";
    }
 else{
 	while(check(n))
	 ans++;	 
 cout<<ans;
 }
 return 0; 
}
