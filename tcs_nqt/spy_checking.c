#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int sum = 0;
    int mul = 1;
    while(n != 0) {
        sum += n%10;
        mul *= n%10;
        n /= 10;
    }
    if(sum == mul) printf("Spy Number");
    else printf("Not Spy Number");
}
