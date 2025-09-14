import java.util.*;

public class ReverseWords {
    public static int helper(String a) {
        char[] s = a.toCharArray();
        int[] mp = new int[256];
        for(char it:s) {
            if(Character.isLetter(it)) mp[it]++;
        }
        int c = 0;
        for(int i=0;i<a.length()-2;i++) {
            if(Character.isLetter(s[i+1])) {
                int m = mp[s[i+1]];
                if(Character.isDigit(s[i]) && (s[i] - '0') == m) c++;
                else if(Character.isDigit(s[i+2]) && (s[i+2] - '0') == m) c++;
            }
        }
        return c;
    }

    public static void main(String[] args) {
        System.out.println(helper("a2a3b12ac"));
    }
}
