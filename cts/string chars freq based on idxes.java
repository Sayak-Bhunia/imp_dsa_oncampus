import java.util.Scanner;

public class Main {
    public static String formatString(String a) {
        int[] mp = new int[256];
        char[] s = a.toCharArray();
        
        // Store first occurrence positions
        for (int i = 0; i < a.length(); i++) {
            if (mp[s[i]] == 0) mp[s[i]] = i + 1;
        }
        
        String res = new String(); // use StringBuilder for efficiency
        for (int i = 0; i < a.length(); i++) {
            while(mp[s[i]] != 0) {
                res += s[i];
                mp[s[i]]--;
            }
            if (i != a.length() - 1) res += '-';
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


def format_string(s) -> str:
    mp = [0]*256
    for i in range(0, len(s)):
        if mp[ord(s[i])] == 0:
            mp[ord(s[i])] = i + 1
    res = ""
    for i in range(0, len(s)):
        c = mp[ord(s[i])]
        res += s[i]*c
        if i != len(s) - 1:
            res += '-'
    return res
    


# Main
s = input().strip()
print(format_string(s))

