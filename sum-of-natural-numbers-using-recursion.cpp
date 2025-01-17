int sumOfNaturalNumbers(int n) {
    if(n == 1) return 1;
    else return n + sumOfNaturalNumbers(n-1); 
}
