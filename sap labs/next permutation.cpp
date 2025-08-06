vector<int> nextPermutation(vector<int> &arr, int n)
{
    //  Write your code here.
    if(next_permutation(arr.begin(), arr.end()));
    else sort(arr.begin(), arr.end());
    return arr;
}

vector<int> nextPermutation(vector<int> &arr, int n)
{
    //  Write your code here.
    int i = n - 2;
    while(i>=0 && arr[i]>=arr[i+1]) i--;
    if(i>=0) {
        int j = n - 1;
        while(arr[j]<=arr[i]) j--;
        swap(arr[i], arr[j]);
    }
    reverse(arr.begin() + i + 1, arr.end());
    return arr;
}
