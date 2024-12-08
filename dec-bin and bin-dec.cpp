string dectobin(int n) {
    string s = "";
    if(n == 0) return "0";
    while(n != 0) {
        s = to_string(n%2) + s;
        n /= 2;
    }
    return s;
}

int bintodec(string &s) {
    int dec = 0, p = 0;
    for(int i=s.length()-1;i>=0;i--) {
        if(s[i] == '1') dec += pow(2, p);
        p++;
    }
    return dec;
}
