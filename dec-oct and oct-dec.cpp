string decToOctal(int n) {
    string s = "";
    if(n == 0) return "0";
    while(n != 0) {
        s = to_string(n%8) + s;
        n /= 8;
    }
    return s;
}

int octalToDec(string n) {
    int dec = 0, p = 0;
    for(int i=n.length()-1;i>=0;i--) {
        if(n[i]>='0' && n[i]<='7') dec += (n[i] - '0')*pow(8, p);
        p++;
    }
    return dec;
}
