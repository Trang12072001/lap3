#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Hàm để chuẩn hóa số điện thoại
string normalizePhoneNumber(const string& phone) {
    string normalized = phone;

    // Loại bỏ các ký tự không phải số
    normalized.erase(remove_if(normalized.begin(), normalized.end(), [](char c) {
        return !isdigit(c);
    }), normalized.end());

    return normalized;
}

int main() {
    int T;
    cout << "Nhap so bo test: ";
    cin >> T; // Nhập số lượng bộ test

    vector<string> phoneNumbers(T);
    cin.ignore(); // Đọc ký tự newline còn lại sau khi nhập T
    for (int t = 0; t < T; ++t) {
        cout << "Nhap sdt ";
        getline(cin, phoneNumbers[t]); // Nhập số điện thoại từng bộ test
    }

    // Chuẩn hóa và in ra số điện thoại đã chuẩn hóa từng bộ test
    for (const string& phone : phoneNumbers) {
        string normalized = normalizePhoneNumber(phone);
        cout << "SDT chuan hoa  " << normalized << endl;
    }

    return 0;
}