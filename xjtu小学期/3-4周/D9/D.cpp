#include<bits/stdc++.h>
using namespace std;
long long eular(long long n)
{
	long long ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i; //�ȼ���ͨ���n�˽�ȥ
            while(n % i == 0) //ȷ����һ��i��n��������
                n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
    return ans;
}
int main()
{
	freopen("data.txt","w",stdout);
	long long x=100000000;
	while(x!=1)
	{
		x=eular(x);
		cout<<x<<',';
	}
	return 0;
}
