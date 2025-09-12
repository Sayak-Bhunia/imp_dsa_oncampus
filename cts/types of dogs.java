import java.util.*;

public class TotalStockValue {
    public static int calculateTotalStockValue(String s) {
        String[] a = s.split("\\.");
        Set<String> set = new HashSet<>();
        for(String it:a) {
            if(!it.isEmpty()) set.add(it);
        }
        return set.size();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        System.out.println(calculateTotalStockValue(input));
    }
}
