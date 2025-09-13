import java.util.Scanner;

public class Main {
    public static String formatString(String a) {
        int[] mp = new int[256];
        int n = a.length();
        String res = "";
        char[] s = a.toCharArray();
        for(int i=0;i<n;i++) {
            if(mp[s[i]] == 0) mp[s[i]] = i + 1;
        }
        for(int i=0;i<n;i++) {
            int m = mp[s[i]];
            while(m != 0) {
                res += s[i];
                m--;
            }
            if(i != n - 1) res += "-";
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();  // Take input from user
        
        String result = formatString(s);
        System.out.println(result);
        
        sc.close();
    }
}
