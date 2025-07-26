import java.util.*;

public class Main {

    public static int maxBalloons(int n, int X, int[] A, int[] B) {
        int mx = -1;

        // Try every pair of packets
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if(B[i]+B[j]<=X) {
                    mx = Math.max(A[i]+A[j], mx);
                }
            }
        }

        return mx;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int X = sc.nextInt();

        int[] A = new int[n];
        int[] B = new int[n];

        for (int i = 0; i < n; ++i) {
            A[i] = sc.nextInt();
        }

        for (int i = 0; i < n; ++i) {
            B[i] = sc.nextInt();
        }

        int result = maxBalloons(n, X, A, B);
        System.out.println(result);
    }
}
