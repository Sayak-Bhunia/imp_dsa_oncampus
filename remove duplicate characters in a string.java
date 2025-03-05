import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int[] a = new int[256];
        for(char c:s.toCharArray()) a[c]++;
        for(int i=0;i<256;i++) {
            if(a[i]>1) System.out.print((char)i + " ");
        }
    }
}
