#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005]; 


//struct student
//{
//	char name[10005];
//	int number;
//	bool sex;
//};
//bool cmp(student a,student b)
//{
//	if(a.number<b.number)return true;
//	return false;
//}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)cout<<a[i]<<' ';
	return 0;
}
