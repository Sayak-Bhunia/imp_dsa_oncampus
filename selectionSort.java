import java.util.*;

class A {
    public static void selectionSort(int[] a, int n) {
        for(int i=0;i<n-1;i++) {
            int mn = i;
            for(int j=i+1;j<n;j++) {
                if(a[j]<a[mn]) mn = j;
            }
            int z = a[mn];
            a[mn] = a[i];
            a[i] = z;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = sc.nextInt();
        selectionSort(a, n);
        for(int i=0;i<n;i++) System.out.print(a[i] + " ");
    }
}
