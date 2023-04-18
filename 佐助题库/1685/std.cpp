#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
char db[]={'C','R','F'};
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int aa[5],bb[5];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);	
		aa[1]=rand()%200-100;
		aa[2]=rand()%200-100;
		aa[3]=rand()%200-100;
		printf("%d %d %d\n",aa[1],aa[2],aa[3]);
		freopen(s2,"w",stdout);
		double a=aa[1],b=aa[2],c=aa[3];
		if(b*b-4*a*c<0||a==0)
    {
        cout<<"Impossivel calcular";
        return 0;
    }
    else printf("R1 = %.5f\nR2 = %.5f\n",(-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
	}
	return 0;
}
