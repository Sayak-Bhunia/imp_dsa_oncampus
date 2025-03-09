import java.util.*;

class Main {
    public static void helper(int[] a, int n) {
        Random r = new Random();
        for(int i=n-1;i>=0;i--) {
            int j = r.nextInt(i+1);
            int z = a[i];
            a[i] = a[j];
            a[j] = z;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = sc.nextInt();
        helper(a, n);
        for(int it:a) System.out.print(it + " ");
    }
}
