#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;

        vector<int> amount(n);
        for (int i = 0; i < n; i++) {
            cin >> amount[i];
        }

        long long result = 0; // 이득은 큰 숫자가 될 수 있으므로 long long
        int max_value = 0;    // 현재 시점 이후의 최고 판매가

        // 배열의 끝부터 거꾸로 탐색
        for (int i = n - 1; i >= 0; i--) {
            if (amount[i] > max_value) {
                // 현재 가격이 이후 최고가보다 높으면 최고가 갱신
                max_value = amount[i];
            } else {
                // 최고가보다 낮으면 그 차익만큼 수익 발생
                result += (max_value - amount[i]);
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}