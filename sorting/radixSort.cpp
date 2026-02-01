#include<iostream>
using namespace std;

int getMx(int a[], int n){
  int mx = a[0];
  for(int i=1;i<n;i++) mx = max(mx, a[i]);
  return mx;
}

void countingSort(int a[], int n, int place){
  int mx = 10;
  int b[n];
  int c[mx];
  for(int i=0;i<mx;++i) c[i] = 0;
  for(int i=0;i<n;i++) c[(a[i]/place)%10]++;
  for(int i=1;i<mx;i++) c[i] += c[i - 1];
  for(int i=n-1;i>=0;i--){
    b[c[(a[i]/place)%10]-1] = a[i];
    c[(a[i]/place)%10]--;
  }
  for(int i=0;i<n;i++) a[i] = b[i];
}

void radixsort(int a[], int n){
  int mx = getMx(a, n);
  for(int place=1;mx/place>0;place*=10) countingSort(a, n, place);
}

int main(){
  int array[]={121,432,564,23,1,45,788};
  int n=sizeof(array)/sizeof(array[0]);
  radixsort(array,n);
  for(int i=0;i<n;i++)
    cout<<array[i]<<" ";
  cout<<endl;
}
