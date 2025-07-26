import java.util.*;

class Main {
    public static int helper(int[][] a, int n) {
        int c = 0;
        for(int i=0;i<a.length;i++) {
            int sum = 0;
            
                for(int j=0;j<a[i].length;j++) if(a[i][j]%2 == 1) sum += a[i][j];
                if(sum%2 == 0) c++;
            
        }
        return c;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                a[i][j] = sc.nextInt();
            }
        }
        System.out.println(helper(a, n));
    }
}
