import java.util.*;

class Main {
    public static int helper(String a) {
        char[] s = a.toCharArray();
        int mx = Integer.MIN_VALUE;
        for(int i=0;i<s.length;i++) {
            for(int j=i+1;j<s.length;j++) {
                if(s[i] != s[j]) mx = Math.max(mx, Math.abs(i - j));
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
