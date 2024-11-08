#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int m = n;
    int k = m*m;
    int sum = 0;
    while(k != 0) {
        sum += k%10;
        k /= 10;
    }
    if(m == sum) printf("Neon Number");
    else printf("Not a Neon Number");
}
