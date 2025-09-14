import java.util.*;

public class Main {
    public static int discountedSum(int[] arr, int k) {
        Set<Integer> set = new TreeSet<>();
        for(int it:arr) set.add(it);
        int i = 0, n = set.size();
        if(n<k) return 0;
        int[] a = new int[n];
        for(int it:set) a[i++] = it;
        int sum = 0;
        for(i=n-1;i>=n-k;i--) sum += a[i];
        return sum - a[n-1];
    }

    public static void main(String[] args) {
        int[] arr1 = {5, 2, 9, 1, 7, 4, 6};
        System.out.println(discountedSum(arr1, 3)); // Output: 13

        int[] arr2 = {5, 2, 9, 1, 7, 4, 6};
        System.out.println(discountedSum(arr2, 1)); // Output: 0

        int[] arr3 = {1, 1, 1};
        System.out.println(discountedSum(arr3, 2)); // Output: 0
    }
}
