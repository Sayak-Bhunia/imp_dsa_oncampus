import java.util.*;

class Main {
    public static int helper(String a) {
        char[] s = a.toCharArray();
        char[] t = a.toCharArray();
        Arrays.sort(t);
        int c = 0;
        for(int i=0;i<a.length();i++) {
            if(s[i] != t[i]) c++;
        }
        return c;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(helper(s));
    }
}
