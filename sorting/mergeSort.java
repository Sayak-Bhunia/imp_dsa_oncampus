import java.util.*;

class A {
    public static void swap(int[] a, int i, int j) {
        int z = a[i];
        a[i] = a[j];
        a[j] = z;
    }
    public static void merge(int[] a, int p, int q, int r) {
        int n = q - p + 1, m = r - q;
        int[] b = new int[n];
        int[] c = new int[m];
        for(int i=0;i<n;i++) b[i] = a[p+i];
        for(int i=0;i<m;i++) c[i] = a[q+i+1];
        int i = 0, j = 0, k = p;
        while(i<n && j<m) {
            if(b[i]<=c[j]) a[k++] = b[i++];
            else a[k++] = c[j++];
        }
        while(i<n) a[k++] = b[i++];
        while(j<m) a[k++] = c[j++];
    }
    public static void helper(int[] a, int l, int r) {
        if(l<r) {
            int m = l + (r - l)/2;
            helper(a, l, m);
            helper(a, m+1, r);
            merge(a, l, m, r);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = sc.nextInt();
        helper(a, 0, n-1);
        for(int i=0;i<n;i++) System.out.print(a[i] + " ");
    }
}
