#include<cstdio>
#include<cstring>
using namespace std;
char tmp[105];
int main(){
    scanf("%s",tmp);
    int n = strlen(tmp);
    for(int i=0;i<n;++i){
        if(tmp[i]>='0'&&tmp[i]<='9'){
            if(i%2==0)
                tmp[i]=tmp[i]-'0'+'A';
            else
                tmp[i]=tmp[i]-'0'+'a';
        }
    }
    printf("%s",tmp);
    return 0;
}
