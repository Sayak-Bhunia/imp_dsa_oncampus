import java.util.*;

public class Main {
    public static int discountedSum(int[] arr, int k) {
        Set<Integer> set = new HashSet<>();
        for(int it:arr) set.add(it);
        if(set.size()<k) return 0;
        int[] a = new int[set.size()];
        int i = 0, n = set.size();
        for(int it:set) a[i++] = it;
        Arrays.sort(a);
        for(i=0;i<n/2;i++) {
            a[i] ^= a[n-i-1];
            a[n-i-1] ^= a[i];
            a[i] ^= a[n-i-1];
        }
        int sum = 0;
        for(i=0;i<k;i++) sum += a[i];
        return sum - a[0];
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
