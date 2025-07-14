public class MagicalLibrary {
    public static int countMagicalRows(int[][] books) {
        int c = 0;
        for(int i=0;i<books.length;i++) {
            int sum = 0;
            for(int it:books[i]) {
                if(it%2 == 1) sum += it;
            }
            if(sum%2 == 0) c++;
        }
        return c;
    }

    public static void main(String[] args) {
        int[][] input3 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        int result = countMagicalRows(input3);
        System.out.println("Number of magical rows: " + result); // Output should be 2
    }
}
