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


import java.util.*;

public class Main {

    public static int maxDistance(String s) {
        int n = s.length();
        Map<Character, Integer> firstPos = new HashMap<>();
        Map<Character, Integer> lastPos = new HashMap<>();

        // Record first and last occurrences
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            firstPos.putIfAbsent(ch, i);
            lastPos.put(ch, i);
        }

        int maxDist = 0;

        // Compare all pairs of different characters
        for (char c1 : firstPos.keySet()) {
            for (char c2 : lastPos.keySet()) {
                if (c1 != c2) {
                    int dist = Math.abs(firstPos.get(c1) - lastPos.get(c2));
                    maxDist = Math.max(maxDist, dist);
                }
            }
        }

        return maxDist;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        System.out.println(maxDistance(s));
        scanner.close();
    }
}
