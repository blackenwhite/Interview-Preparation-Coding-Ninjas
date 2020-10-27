    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int MOD = 1e9 + 7;
     
    int binPow(int a, int n) {
        int res = 1;
        while (n) {
            if (n & 1)
                res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
     
            n >>= 1;
        }
        return res;
    }
     
    void binarySearch(int n, int x_position, int &cnt_big, int &cnt_less) {
        int left = 0, right = n;
     
        while(left < right) {
            int middle = (left + right) / 2;
            if (x_position >= middle) {
                if (x_position != middle) cnt_less++;
                left = middle + 1;
            }
            else if (x_position < middle){
                cnt_big++;
                right = middle;
            }
        }
    }
     
    int C(int n, int k, const vector <long long> &fact, const vector <long long> &inv) {
        if (k > n) return 0;
        int multiply = (1LL * fact[n] * inv[k]) % MOD;
        multiply = (1LL * multiply * inv[n - k]) % MOD;
        return multiply;
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
     
        int n, x, x_position;
        long long ans = 0;
     
     
        cin >> n >> x >> x_position;
        vector <long long> fact(n + 1, 1LL);
        vector <long long> inv(n + 1, 1LL);
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
            inv[i] = binPow(fact[i], MOD - 2);
        }
     
        int cnt_big = 0, cnt_less = 0;
        binarySearch(n, x_position, cnt_big, cnt_less);
     
        int other = (n - cnt_big - cnt_less - 1);
        int can_big = n - x, can_less = x - 1;
     
        int countLess = C(can_less, cnt_less, fact, inv);
        int countBig = C(can_big, cnt_big, fact, inv);
     
        countBig = (1LL * countBig * fact[cnt_big]) % MOD;
        countLess = (1LL * countLess * fact[cnt_less]) % MOD;
     
        int multiply = (1LL * countBig * countLess) % MOD;
        multiply = (1LL * multiply * fact[other]) % MOD;
     
        ans = (ans + multiply) % MOD;
     
        cout << ans << endl;
     
        return 0;
    }
