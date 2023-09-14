public class NonPigRolls {
    public static int catalanNum(int n) {
        if (n == 0)
            return 1;
        return (4*n - 2) * catalanNum(n - 1) / (n + 1);
    }


    private static int[] dp = new int[52];
    public static int getNumSequences(int turnTotal) {
        dp[0] = 1;
        if (dp[turnTotal] == 0)
            for (int i = 2; i <= turnTotal; ++i) {
                if (dp[i] != 0)
                    continue;
                int vi = 0;
                for (int j = 2; j <= 6 && j <= i; ++j) {
                    vi += dp[i - j];
                }
                dp[i] = vi;
            }
        return dp[turnTotal];
    }

    public static void main(String[] args) {
        System.out.println("PIGS ROLLS:");
        for (int i = 0; i <= 50; ++i) {
            System.out.println(getNumSequences(i));
        }
        System.out.println("\n\nCATALAN:");
        for (int i = 0; i < 10; ++i) {
            System.out.println(catalanNum(i));
        }
    }
}
