class Solution {

    // The given numTrees function calculates the number of unique Binary Search
    // Trees (BSTs) that can be formed with n distinct nodes. This count is
    // given by the Catalan number for n, which can be computed using the
    // formula: 𝐶𝑛 = (1/n+1) * (2n/n)
    //  or
    // 𝐶𝑛 = 2n!/((n+1)!n!)
    // or
    // Cn+1 = 4n+1/n+2 * Cn

private:
    long ncr(int n, int r) {
        long ans = 1;
        for (int i = 0; i < r; i++) {
            ans *= n - i;
            ans /= i + 1;
        }
        return ans;
    }

public:
    int numTrees(int n) { return ncr(2 * n, n) / (n + 1); }
};