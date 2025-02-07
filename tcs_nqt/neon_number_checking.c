#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int k = n*n;
    int sum = 0;
    while(k != 0) {
        sum += k%10;
        k /= 10;
    }
    if(n== sum) printf("Neon Number");
    else printf("Not a Neon Number");
}
