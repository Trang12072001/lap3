#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertAndSort(std::vector<int>& nums, int m) {
    int max_value = *max_element(nums.begin(), nums.end());
    auto it = find(nums.begin(), nums.end(), max_value);
    nums.insert(it, m);
    sort(nums.begin(), nums.end(), [](int a, int b) {
        if (a < 0 && b >= 0) {
            return true;
        }
        if (a >= 0 && (b < 0 || b == 0)) {
            return false;
        }
        return a < b;
    });
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        insertAndSort(nums, m);

        // In ra kết quả
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

