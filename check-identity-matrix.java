import java.util.*;

class Main {
    public static boolean helper(int[][] a, int n, int m) {
        if(n != m) return false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0)) return false;
            }
        }
        return true;a
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] a = new int[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) a[i][j] = sc.nextInt();
        }
        if(helper(a, n, m)) System.out.println("identity matrix");
        else System.out.println("not identity matrix");
    }
}
