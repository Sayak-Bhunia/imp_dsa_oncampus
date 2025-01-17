double power(double a, int e) {
    if(e == 0) return 1;
    else return a*power(a, e-1);
}
