unsigned long long fact(int n) {
    unsigned long long p = 1;
    for(int i=1;i<=n;i++) p *= i;
    return p;
}

unsigned long long helper(int n, int r) {
    if(r>n) return 0;
    return fact(n)/fact(n-r);
}

int main() {
    int n,r;
    cin >> n >> r;
    cout << helper(n, r) <<endl;
}
