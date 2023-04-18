#include<bits/stdc++.h>
using namespace std;
void foo(int *b, int a, char *c) {
    if (a != 1) {
        printf("%d%s\n", 10/ *b,c);
        foo(b,a-1,",\\*^_^*/,");
    }else{
        printf("%d\n",c[0]);
    }
}
int main() {
    int a=2;
    foo(&a,a," unit");
    a--;
    foo(&a,a," unit");
    return 0;
} 
