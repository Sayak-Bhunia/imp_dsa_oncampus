public class Main {

    public static int[] helper(int[] a) {
        int n = a.length;
        int[] res = new int[n];
        int[] mp = new int[100001];
        for(int it:a) mp[it]++;
        int i = 0;
        for(int it:a) {
            if(mp[it] != 0) {
                res[i++] = it;
                mp[it] = 0;
            }
        }
        int[] ans = new int[i];
        for(int j=0;j<i;j++) ans[j] = res[j];
        return ans;
    }

    public static void main(String[] args) {
        int[] a = {4, 3, 2, 3, 2, 1, 5, 6};
        int[] res = helper(a);
        for (int num : res) {
            System.out.print(num + " ");
        }
    }
}
