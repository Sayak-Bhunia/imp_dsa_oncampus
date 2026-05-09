import java.util.*;

class Main {
    public static int helper(String s) {
        char[] a = s.toCharArray();
        int mx = 0;
        for(int i=0;i<s.length();i++) {
            for(int j=i+1;j<s.length();j++) {
                if(a[i] != a[j]) mx = Math.max(mx, Math.abs(i-j));
            }
        }
        return mx;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(helper(s));
    }
}
