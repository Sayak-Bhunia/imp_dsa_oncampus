import java.util.*;

class Main {
    public static int simulateJumps(int[] arr, int startIdx) {
        int n = arr.length;
        boolean[] visited = new boolean[n];
        int count = 0;
        int idx = startIdx;
        boolean goRight = true; // start by going right

        while (idx >= 0 && idx < n) {
            if (visited[idx]) {
                return -1; // loop found
            }
            visited[idx] = true;
            count++;

            if (goRight) {
                idx += arr[idx]; // move right
            } else {
                idx -= arr[idx]; // move left
            }

            goRight = !goRight; // alternate direction
        }

        return count; // stopped because went out of bounds
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 1, 1, 2}; 
        int a = arr.length; 
        int b = 0; // starting index

        int result = simulateJumps(arr, b);
        System.out.println(result);
    }
}
