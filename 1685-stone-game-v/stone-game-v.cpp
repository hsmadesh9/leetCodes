class Solution {
private:
    int search(const vector<int>& prefix, int leftBound, int rightBound) {
        int total = prefix[rightBound + 1] - prefix[leftBound];
        int start = leftBound;

        int left = leftBound;
        int right = rightBound;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int leftSum = prefix[mid + 1] - prefix[start];

            if (leftSum * 2 >= total) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        vector<vector<int>> left(n, vector<int>(n, 0));

        vector<vector<int>> right(n,vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            left[i][i] = stoneValue[i];
            right[i][i] = stoneValue[i];
        }

        for (int length = 1; length < n; length++) {
            for (int i = 0; i < n - length; i++) {
                int j = i + length;

                int k = search(prefix, i, j);

                int total = prefix[j + 1] - prefix[i];
                int leftHalf = prefix[k + 1] - prefix[i];

                if (leftHalf * 2 == total) {
                    dp[i][j] = max(
                        left[i][k],
                        right[k + 1][j]
                    );
                } else {
                    int leftBest =
                        k == i ? 0 : left[i][k - 1];

                    int rightBest =
                        k == j ? 0 : right[k + 1][j];

                    dp[i][j] = max(
                        leftBest,
                        rightBest
                    );
                }

                left[i][j] = max(
                    left[i][j - 1],
                    total + dp[i][j]
                );

                right[i][j] = max(
                    right[i + 1][j],
                    total + dp[i][j]
                );
            }
        }

        return dp[0][n - 1];
    }
};