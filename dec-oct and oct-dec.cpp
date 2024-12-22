long int dectoOctal(int n) {
    if(n == 0) return 0;
    else return n%8 + 10*octal(n/8);
}

int octalToDec(string n) {
    int dec = 0, p = 0;
    for(int i=n.length()-1;i>=0;i--) {
        if(n[i]>='0' && n[i]<='7') dec += (n[i] - '0')*pow(8, p);
        p++;
    }
    return dec;
}
