long int dectoBin(int n) {
    if(n == 0) return 0;
    else return n%2 + 10*octal(n/2);
}

int bintodec(string &s) {
    int dec = 0, p = 0;
    for(int i=s.length()-1;i>=0;i--) {
        if(s[i] == '1') dec += pow(2, p);
        p++;
    }
    return dec;
}
