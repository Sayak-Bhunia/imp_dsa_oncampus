public class Main {
    public static int nearestMultipleOf10(String s) {
        int m = Integer.parseInt(s);
        int l = (m/10)*10;
        int h = l + 10;
        if(2*m<l+h) return l;
        else if(2*m>l+h) return h;
        else return l;
    }

    public static void main(String[] args) {
        String s1 = "29";
        String s2 = "15";

        System.out.println(nearestMultipleOf10(s1)); // Output: 30
        System.out.println(nearestMultipleOf10(s2)); // Output: 10
    }
}
