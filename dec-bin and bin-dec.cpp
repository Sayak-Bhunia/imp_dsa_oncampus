long int dectoBin(int n) {
    if(n == 0) return 0;
    else return n%2 + 10*octal(n/2);
}

long int binToDec(int n) {
    if(n == 0) return 0;
    else return n%10 + 2*binToDec(n/10);
}
