import java.util.*;

class A {
    public static boolean helper(int n) {
        if(n == 1) return true;
        int m = n*n;
        int c = (int) Math.log10(m) + 1, d = 1;
        for(int i=1;i<c;i++) {
            d *= 10;
            int a = m/d, b = m%d;
            if(a != 0 && b != 0 && a + b == n) return true;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(helper(n)) System.out.println("Kaprekar");
        else System.out.println("not Kaprekar");
    }
}
