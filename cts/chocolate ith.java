import java.util.Scanner;

public class Main {
    static final int mod = 1000000007;
    public static int totalChocolates(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++) {
            sum = (sum+i)%mod;
            int l = (i == 1)? n:i-1;
            int r = (i == n)? 1:i+1;
            if(l%5 == 0 || r%5 == 0) sum = (sum+2)%mod;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(totalChocolates(n));
    }
}
