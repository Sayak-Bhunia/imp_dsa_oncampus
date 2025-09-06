public class EncodeString {
    public static String encode(String a) {
        String res = "";
        char[] s = a.toCharArray();
        for(int i=0;i<a.length();i++) {
            char curr = s[i];
            int pos = curr - 'A' + 1;
            if(i>0 && curr == s[i-1]) res += "*";
            else res += curr + "" + pos;
        }
        return res;
    }

    public static void main(String[] args) {
        String input1 = "ABAZ";
        String input2 = "AABBC";
        
        System.out.println(encode(input1)); // Output: A1B2A1Z26
        System.out.println(encode(input2)); // Output: A1*B2*
    }
}
