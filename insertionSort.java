import java.util.*;

class Main {
    public static void helper(int a[], int n) {
        for(int i=1;i<n;i++) {
            int key = a[i];
            int j = i - 1;
            while(j>=0 && key<a[j]) a[j+1] = a[j--];
            a[j+1] = key;
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
