#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int k = n*n;
    int f = 0;
    while(n != 0) {
        if(n%10 != k%10) {
            f = 1;
            break;
        }
        n /= 10;
        k /= 10;
    }
    if(f) printf("Not Automorphic");
    else printf("Automorphic");
}
