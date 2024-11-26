#include <stdio.h>

long int octal(int n) {
    if(n == 0) return 0;
    else return n%8 + 10*octal(n/8);
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%ld", octal(n));
}
