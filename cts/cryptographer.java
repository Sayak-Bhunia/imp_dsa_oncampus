import java.util.*;

class Main {
    public static String helper(String a) {
        char[] s = a.toCharArray();
        String res = "";
        for(int i=0;i<a.length();i++) {
            if(s[i] == 'a') res += 'z';
            else res += (char)(s[i] - 1);
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(helper(s));
    }
}
