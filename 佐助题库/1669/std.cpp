#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
char db[]={'C','R','F'};
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);	
		int aa=rand()%10000+1,b=rand()%10000+1,c=rand()%10000+1;
		printf("%d.00\n",aa);
		freopen(s2,"w",stdout);
		int m=aa*100;
		double a[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
	    int ans[12] = {0};
	
	    for (int i = 0; i < 12; i++)
	    {
	        int cnt = 0;
	        while (m >= a[i])
	        {
	            m -= a[i];
	            cnt++;
	        }
	        ans[i] = cnt;
	    }
	
	    puts("NOTAS:");
	    for (int i = 0; i < 6; i++)
	        printf("%d nota(s) de R$ %.2lf\n", ans[i], (double)a[i] / 100);
	    puts("MOEDAS:");
	    for (int i = 6; i < 12; i++)
	        printf("%d moeda(s) de R$ %.2lf\n", ans[i], (double)a[i] / 100);
	}
	return 0;
}	
