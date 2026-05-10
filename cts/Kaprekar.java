import java.util.*;

class Main {
    public static boolean helper(int n) {
        if(n == 1) return true;
        long sq = n*n;
        int d = String.valueOf(n).length();
        long p = (long)Math.pow(10, d);
        long l = sq%p;
        long r = sq/p;
        return (l+r) == n;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = 0;
        for(int i=a;i<=b;i++) {
            if(helper(i)) {
                c++;
                System.out.print(i+" ");
            }
        }
        if(c == 0) System.out.println("INVALID RANGE");
    }
}
