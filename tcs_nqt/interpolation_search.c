#include <stdio.h>

int sort(int *a, int n) {
    int i,j,temp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int search(int *a, int l, int r, int val) {
    int mid;
    while(l<=r) {
        mid = l + (r - l)*((val-a[l])/(a[r]-a[l]));
        if(val == a[mid]) return mid;
        if(val<a[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a, n);
    int val;
    scanf("%d",&val);
    if(search(a, 0, n-1, val) != -1) printf("%d found",val);
    else printf("not found");
}
