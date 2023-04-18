#include<bits/stdc++.h>
using namespace std;
int a[105];
int work(){
     int re=0,tmp;
     while(1){
          cin>>tmp;
          if(tmp==-9999)break;
          a[++re]=tmp;
     }
     return re;
}
int work(int n){
	int re=0;
     for(int i=n;i>=1;--i)re+=a[i];
     return re;
}
int main(){
     int n=work();
     work(n);
     cout<<work(n);
     return 0;
}
