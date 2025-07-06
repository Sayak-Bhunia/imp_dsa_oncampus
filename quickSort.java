import java.util.*;

class A {
    public static void swap(int[] a, int i, int j) {
        int z = a[i];
        a[i] = a[j];
        a[j] = z;
    }
    public static int partition(int[] a, int l, int h) {
        int i = l - 1;
        for(int j=l;j<h;j++) {
            if(a[j]<=a[h]) {
                i++;
                swap(a, i, j);
            }
        }
        swap(a, i+1, h);
        return i+1;
    }
    public static void helper(int[] a, int l, int h) {
        if(l<h) {
            int p = partition(a, l, h);
            helper(a, l, p-1);
            helper(a, p+1, h);
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
