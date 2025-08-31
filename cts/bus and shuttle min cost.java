import java.util.*;

public class TransportCost {
    public static int minFuelCost(int n, int p, int q) {
        int nb = 0;
        while(n>80) {
            n -= 80;
            nb++;
        }
        if(n>0) {
            int b = (nb+1)*p*75;
            int ns = (n+8-1)/8;
            int s = (nb*p + ns*q)*75;
            return Math.min(b, s);
        }
        return nb*p*75;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();  // number of people
        int P = sc.nextInt();  // fuel per bus
        int Q = sc.nextInt();  // fuel per shuttle

        System.out.println(minFuelCost(N, P, Q));
    }
}
