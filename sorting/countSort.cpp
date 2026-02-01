#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void countSort(int a[], int n) {
    int b[10], c[10], mx = a[0];
    for(int i=1;i<n;i++) mx = max(mx, a[i]);
    for(int i=0;i<=mx;i++) c[i] = 0;
    for(int i=0;i<n;i++) c[a[i]]++;
    for(int i=1;i<=mx;i++) c[i] += c[i-1];
    for(int i=n-1;i>=0;i--) {
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }
    for(int i=0;i<n;i++) a[i] = b[i];
}

int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
  }
  
