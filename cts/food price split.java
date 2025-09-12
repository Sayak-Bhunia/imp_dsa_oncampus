import java.util.*;

public class TotalStockValue {
    public static int calculateTotalStockValue(String s) {
        int c = 0;
        String[] a = s.split(";");
        for(String it:a) {
            String[] b = it.split(":");
            int price = Integer.parseInt(b[1]);
            int quantity = Integer.parseInt(b[2]);
            c += price*quantity;
        }
        return c;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        System.out.println(calculateTotalStockValue(input));
    }
}
