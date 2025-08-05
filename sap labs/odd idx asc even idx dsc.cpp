#include <bits/stdc++.h>
using namespace std;

void bitonicGenerator(vector<int>& arr)
{
    int n = arr.size();
    int i = 1, j = n - 1;
    if(j%2) j--;
    while(i<j) {
        swap(arr[i], arr[j]);
        i += 2;
        j -= 2;
    }
    sort(arr.begin(), arr.begin() + (n+1)/2);
    sort(arr.begin() + (n+1)/2, arr.end(), greater<int>());
}

// Driver Program
int main()
{
    vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7};
    bitonicGenerator(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
