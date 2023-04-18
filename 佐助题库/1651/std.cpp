#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[100][105],b[1005];
char db[]={'C','R','F'};
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=0;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);	
		printf("100 100\n");
		freopen(s2,"w",stdout);
		int n=100,num=1;
		int t = ceil(1.0 * n / 2);////根据推导总结，转的圈数为行数除以2，如果行数是奇数还要+1，其实就是ceil。
		for(int i=0; i<t; i++) {
		for (int j = i; j < n - i; j++) {
            a[i][j] = num++;//每一圈判断第一行
        }
        for (int j = i + 1; j < n - i - 1; j++) {
            a[j][n - i - 1] = num++;//每一圈判断最后一列
        }
        for (int j = n - i - 1; j > i; j--) {
            a[n - i - 1][j] = num++;//判断每一圈最后一行
        }
        for (int j = n - i - 1; j > i; j--)  {
            a[j][i] = num++;//判断每一圈第一列
        }
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%d ", a[i][j]);//输出方式要注意，%3d
		}
		printf("\n");
	}
	}
	return 0;
}
