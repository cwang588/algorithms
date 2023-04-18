#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
bool usd[500005];
int main()
{
    //节点数量 
    srand((unsigned)time(0));
    int n=100000; //文件名 
    char file_name[100]="datax.in";
    int k=rand()%n+1;
    srand(time(0));
   	FILE* f=fopen(file_name,"w");
    fprintf(f,"%d %d\n",n,k);
    for(int i=2;i<=n;i++)
    {
        int j=i-1-rand()%7;
        j=j<1?1:j;
        fprintf(f,"%d %d %d\n",j,i,rand()+1);
    }
    for(int i=1;i<=k;++i)
    {
    	int t=rand()%n+1;
    	while(usd[t])t=rand()%n+1;
    	usd[t]=true;
    	fprintf(f,"%d\n",t);
    }
    return 0;
}
