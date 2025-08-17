public class MostFrequentPair {
    public static String mostFrequentPair(String s) {
        String[] w = s.split(" ");
        int[][] a = new int[26][26];
        int[][] mp = new int[26][26];
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) a[i][j] = -1;
        }
        int mx = 0;
        String res = "";
        int idx = 0;
        for(String it:w) {
            if(it.length()>0) {
                char start = it.charAt(0);
                char end = it.charAt(it.length() - 1);
                int i = start - 'a';
                int j = end - 'a';
                mp[i][j]++;
                if(a[i][j] == -1) a[i][j] = idx;
                if(mp[i][j]>mx || (mp[i][j] == mx && a[i][j]<a[res.charAt(0) - 'a'][res.charAt(1) - 'a'])) {
                    mx = mp[i][j];
                    res = "" + start + end;
                }
            }
            idx++;
        }
        return res;
    }
    public static void main(String[] args) {
        String input = "she is good grid god and ground player plotter";
        System.out.println(mostFrequentPair(input));
    }
}

def most_frequent_pair(s: str) -> str:
    words = s.split()
    # 26x26 arrays
    first_occurrence = [[-1] * 26 for _ in range(26)]
    freq = [[0] * 26 for _ in range(26)]

    mx = 0
    res = ""
    idx = 0

    for word in words:
        if len(word) > 0:
            start = word[0]
            end = word[-1]
            i = ord(start) - ord('a')
            j = ord(end) - ord('a')

            freq[i][j] += 1
            if first_occurrence[i][j] == -1:
                first_occurrence[i][j] = idx

            if (res == "" or 
                freq[i][j] > mx or 
                (freq[i][j] == mx and first_occurrence[i][j] < first_occurrence[ord(res[0]) - ord('a')][ord(res[1]) - ord('a')])):
                
                mx = freq[i][j]
                res = start + end
        idx += 1

    return res


if __name__ == "__main__":
    input_str = "she is good grid god and ground player plotter"
    print(most_frequent_pair(input_str))  # expected: gd

