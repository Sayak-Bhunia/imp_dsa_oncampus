import java.util.*;

class Main {
    public static void helper(String s, String t) {
        if(s.isEmpty()) {
            System.out.println(t);
            return;
        }
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            String s1 = s.substring(0, i) + s.substring(i+1);
            helper(s1, t+c);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        helper(s, "");
    }
}
