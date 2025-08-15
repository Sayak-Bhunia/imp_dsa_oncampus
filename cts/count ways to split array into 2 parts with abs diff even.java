import java.util.*;

public class FairSplits {
    public static int countFairSplits(int[] arr) {
        int sum = 0;
        for(int it:arr) sum += it;
        if(sum%2 == 0) return arr.length-1;
        return 0;
    }

    public static void main(String[] args) {
        int[] arr = {10, 10, 3, 7, 6};
        System.out.println(countFairSplits(arr)); // Output: 4
    }
}
