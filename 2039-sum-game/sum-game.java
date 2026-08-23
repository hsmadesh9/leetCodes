class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int half = n / 2;
        int s1 = 0, s2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n; i++) {
            char c = num.charAt(i);
            if (c == '?') {
                if (i < half) q1++;
                else q2++;
            } else {
                if (i < half) s1 += (c - '0');
                else s2 += (c - '0');
            }
        }

        if ((q1 + q2) % 2 != 0) return true;

        return (2 * s1 + 9 * q1) != (2 * s2 + 9 * q2);
    }
}