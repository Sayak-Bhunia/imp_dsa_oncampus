import java.util.*;

public class Main {
    public static int countPalindromes(String a, int mod) {
        int n = a.length();
        char[] s = a.toCharArray();
        long res = 1;
        for(int i=0;i<=n/2;i++) {
            if(s[i] == '_' && s[n-i-1] == '_') res = (res*26)%mod;
            else if(s[i] == '_' || s[n-i-1] == '_') res %= mod;
            else if(s[i] != s[n-i-1]) return 0;
        }
        return (int)res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int mod = sc.nextInt();
        System.out.println(countPalindromes(s, mod));
    }
}
