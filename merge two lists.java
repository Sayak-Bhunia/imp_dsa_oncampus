import java.util.*;

class Main {
    public static void main(String[] args) {
        List<Integer> a = new ArrayList<>(Arrays.asList(1, 2, 3));
        List<Integer> b = new ArrayList<>(Arrays.asList(5, 6, 7));
        a.addAll(b);
        System.out.println(a);
    }
}
