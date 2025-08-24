public class DecodeWays {
    public static void main(String[] args) {
        String s = "226";
        System.out.println(numDecodings(s)); // Output: 5
    }

    public static int numDecodings(String a) {
        if(a == null || a.length() == 0) return 0;
        int n = a.length();
        char[] s = a.toCharArray();
        int[] dp = new int[n+1];
        dp[0] = 1;
        if(s[0] != '0') dp[1] = 1;
        else dp[1] = 1;
        for(int i=2;i<=n;i++) {
            if(s[i-1] != '0') dp[i] += dp[i-1];
            int t = (s[i-2] - '0')*10 + (s[i-1] - '0');
            if(t>=10 && t<=26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
}
