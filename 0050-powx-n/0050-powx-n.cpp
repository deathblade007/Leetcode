class Solution {
public:
    double pow(double x, long long N) {
        if (N == 0)
            return 1.0;
        if (N % 2 == 0) {
            return pow(x * x, N / 2);
        } else {
            return x * pow(x * x, (N - 1) / 2);
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N == 0) {
            return 1;
        } else if (N > 0) {
            long double s = pow(x, N);
            return s;
        } else if (N < 0) {
            long double s = pow(x, -1 * N);
            double z = 1.0 / s;
            return z;
        }
        return 0;
    }
};