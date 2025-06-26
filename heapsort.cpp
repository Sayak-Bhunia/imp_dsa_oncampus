#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int mx) {
    int mx = i, int l = 2*i + 1, r = 2*i + 2;
    if(l<n && a[l]>a[mx]) mx = l;
    if(r<n && a[r]>a[mx]) mx = r;
    if(mx != -1) {
        swap(a[i], a[mx]);
        heapify(a, n, mx);
    }
}

void heapSort(int a[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(a, n, i);
    for(int i=n-1;i>=0;i--) swap(a[0], a[i]);
    heapify(a, i, 0);
}
