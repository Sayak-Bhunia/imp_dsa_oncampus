import java.util.*;

class Main {
    public static Integer findEquilibriumElement(int[] arr) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        int leftSum = 0;
        for (int i = 0; i < arr.length; i++) {
            int rightSum = totalSum - leftSum - arr[i];
            if (leftSum == rightSum) {
                return arr[i]; // return the element
            }
            leftSum += arr[i];
        }

        return null; // no equilibrium element found
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 2, 2}; // example
        Integer result = findEquilibriumElement(arr);

        if (result != null)
            System.out.println("Equilibrium element: " + result);
        else
            System.out.println("No equilibrium element found");
    }
}
