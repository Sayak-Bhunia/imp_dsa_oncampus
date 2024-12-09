vector<int> genPrimes(int n) {
    vector<bool> p(n+1, true);
    p[0] = p[1] = false;
    for(int i=2;i*i<=n;i++) {
        if(p[i]) for(int j=i*i;j<=n;j+=i) p[j] = false;
    }
    vector<int> primes;
    for(int i=2;i<=n;i++) {
        if(p[i]) primes.push_back(i);
    }
    return primes;
}

int helper(int n) {
    vector<int> primes = genPrimes(n);
    int c = 0;
    for(auto it:primes) {
        if(pow(it, 8)>n) break;
        c++;
    }
    int psz = primes.size();
    for(int i=0;i<psz;i++) {
        for(int j=i+1;j<psz;j++) {
            if(pow(primes[i], 2)*pow(primes[j], 2)>n) break;
            c++;
        }
    }
    return c;
}
