long int dectoOctal(int n) {
    if(n == 0) return 0;
    else return n%8 + 10*octal(n/8);
}

long int octToDec(int n) {
    if(n == 0) return 0;
    else return n%10 + 8*binToDec(n/10);
}
