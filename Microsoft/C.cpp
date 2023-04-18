// you can use includes, for example:
#include <bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
long long mi[15];
void init(){
    mi[0]=1;
    for(int i=1;i<=9;++i)mi[i]=mi[i-1]*10;
}
int num[15];
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int m=0,ans=0;
    while(N){
        num[++m]=N%10;
        N/=10;
    }
    init();
    reverse(num+1,num+1+m);
    int sum=0;
    for(int i=1;i<=m;++i){
        for(int j=0;j<num[i];++j){
            int nowsum=sum+(j==1?1:0);
            ans+=nowsum*mi[m-i]+(m-i)*mi[max(m-i-1,0)];
        }
        sum+=(num[i]==1)?1:0;
    }
    ans+=sum;
    return ans;
}
int cnt[300005];
int main(){
	for(int i=1;i<=200000;++i){
		int tmp=i;
		while(tmp){
			if(tmp%10==1)++cnt[i];
			tmp/=10;
		}
		cnt[i]+=cnt[i-1];
	}
	srand(time(0));
	while(true){
		int n=rand()*rand()%200000+1;
		if(cnt[n]!=solution(n)){
			cout<<"WA! n="<<n<<"\n";
			cout<<solution(n)<<" "<<cnt[n]<<"\n";
			break;
		}
		cout<<"AC\n";
	}
	return 0;
}