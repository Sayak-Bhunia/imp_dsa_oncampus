import java.util.Scanner;

public class Main {
    static boolean helper1(int[] a) {
        for(int i=0;i<a.length-1;i++) {
            if(a[i+1] == a[i] + 1) return false;
        }
        return true;
    }

    static boolean helper(int[] a) {
        int n = a.length;
        int i = n - 2;
        int j = n - 1;
        while(i>=0 && a[i]>=a[i+1]) i--;
        if(i<0) return false;
        while(a[j]<=a[i]) j--;
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        for(int l=i+1, r=n-1;l<r;l++,r--) {
            tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
        }
        return true;
    }

    static int countValidPermutations(int n) {
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = i + 1;
        int c = 0;
        do {
            if(helper1(a)) c++;
        } while(helper(a));
        return c;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(countValidPermutations(n));
    }
}
