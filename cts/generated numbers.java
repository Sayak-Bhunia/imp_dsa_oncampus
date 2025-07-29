import java.util.*;

public class MarbleJar {

    public static void dfs(int current, int A, int B, Set<Integer> visited) {
        if (current < 1 || visited.contains(current)) return;
        visited.add(current);
        if (current - A >= 1)
            dfs(current - A, A, B, visited);

        if (current - B >= 1)
            dfs(current - B, A, B, visited);
    }

    public static int countUniqueMarbleStates(int N, int A, int B) {
        Set<Integer> visited = new HashSet<>();
        dfs(N, A, B, visited);
        return visited.size();
    }

    public static void main(String[] args) {
        int N = 10, A = 2, B = 5;
        System.out.println(countUniqueMarbleStates(N, A, B));  // Output: 8
    }
}
