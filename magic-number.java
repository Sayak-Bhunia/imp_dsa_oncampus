import java.util.*;

class A {
    public static int sumd(int n) {
        int sum = 0;
        while(n != 0) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    public static boolean helper(int n) {
        while(n>=10) n = sumd(n);
        return n == 1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(helper(n)) System.out.println("magic number");
        else System.out.println("not magic number");
    }
}
