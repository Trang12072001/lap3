#include <iostream>
#include <cmath>
using namespace std;

// Bai 1: Tim so nho nhat trong 2 so
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Bai 1: Tim so nho nhat trong 3 so
int min(int a, int b, int c) {
    return min(a, min(b, c));
}

// Bai 2: Tim uoc chung lon nhat (GCD) cua 2 so nguyen duong
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Bai 2: Tim boi so chung nho nhat (LCM) cua 2 so nguyen duong
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Bai 3: Tinh giai thua (n!)
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Bai 4: Tinh X''(x, n) khong dung de quy
double nonRecursiveX(double x, int n) {
    double result = 0.0;
    double power = 1.0;

    for (int i = 1; i <= n; i++) {
        power *= x * x;
        if (i % 2 == 1) {
            result += power;
        } else {
            result -= power;
        }
    }

    return result;
}

// Bai 5: Tinh to hop C(n, k) = n! / (k! * (n - k)!)
int combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Bai 6: Tinh chu vi hinh chu nhat
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Bai 6: Tinh dien tich hinh chu nhat
double calculateArea(double length, double width) {
    return length * width;
}

// Bai 6: Ve hinh chu nhat
void drawRectangle(int length, int width) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == length - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Bai 7: Kiem tra mot so co phai la so hoan thien hay khong
bool isPerfectNumber(int number) {
    int sum = 0;
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

// Bai 8: Tinh so to tien it nhat de tra ve so tien can doi
void calculateMinimumNotes(int amount) {
    int denominations[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int numOfNotes[sizeof(denominations) / sizeof(denominations[0])] = {0};

    for (int i = 0; i < sizeof(denominations) / sizeof(denominations[0]); i++) {
        while (amount >= denominations[i]) {
            numOfNotes[i]++;
            amount -= denominations[i];
        }
    }

    cout << "So to tien it nhat de tra la: " << endl;
    for (int i = 0; i < sizeof(denominations) / sizeof(denominations[0]); i++) {
        if (numOfNotes[i] > 0) {
            cout << numOfNotes[i] << " to " << denominations[i] << " VND" << endl;
        }
    }
}

// Bai 9: Dao nguoc cac chu so trong so nguyen duong
int reverseDigits(int n) {
    int reversed = 0;
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int main() {
    int choice;

    do {
        cout << "=========================" << endl;
        cout << "MENU" << endl;
        cout << "=========================" << endl;
        cout << "1. Tim so nho nhat trong 2 so" << endl;
        cout << "2. Tim uoc chung lon nhat va boi so chung nho nhat cua 2 so" << endl;
        cout << "3. Tinh giai thua" << endl;
        cout << "4. Tinh X''" << endl;
        cout << "5. Tinh to hop C(n, k)" << endl;
        cout << "6. Tinh chu vi va dien tich hinh chu nhat" << endl;
        cout << "7. Kiem tra so hoan thien" << endl;
        cout << "8. Tinh so to tien it nhat" << endl;
        cout << "9. Dao nguoc cac chu so trong so nguyen duong" << endl;
        cout << "0. Thoat" << endl;

        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int a, b;
                cout << "Nhap hai so a va b: ";
                cin >> a >> b;
                int minimum = min(a, b);
                cout << "So nho nhat trong hai so " << a << " va " << b << " la: " << minimum << endl;
                break;
            }
            case 2: {
                int a, b;
                cout << "Nhap hai so a va b: ";
                cin >> a >> b;
                int gcdResult = gcd(a, b);
                int lcmResult = lcm(a, b);
                cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << gcdResult << endl;
                cout << "Boi so chung nho nhat cua " << a << " va " << b << " la: " << lcmResult << endl;
                break;
            }
            case 3: {
                int n;
                cout << "Nhap so nguyen duong n: ";
                cin >> n;
                int result = factorial(n);
                cout << "Giai thua cua " << n << " la: " << result << endl;
                break;
            }
            case 4: {
                double x;
                int n;
                cout << "Nhap so thuc x: ";
                cin >> x;
                cout << "Nhap so nguyen duong n: ";
                cin >> n;
                double result = nonRecursiveX(x, n);
                cout << "Gia tri cua X''(" << x << ", " << n << ") la: " << result << endl;
                break;
            }
            case 5: {
                int n, k;
                cout << "Nhap so nguyen duong n va k (n >= k): ";
                cin >> n >> k;
                int result = combination(n, k);
                cout << "To hop C(" << n << ", " << k << ") la: " << result << endl;
                break;
            }
            case 6: {
                double length, width;
                cout << "Nhap do dai hai canh cua hinh chu nhat: ";
                cin >> length >> width;
                double perimeter = calculatePerimeter(length, width);
                double area = calculateArea(length, width);
                cout << "Chu vi cua hinh chu nhat la: " << perimeter << endl;
                cout << "Dien tich cua hinh chu nhat la: " << area << endl;
                cout << "Hinh chu nhat:" << endl;
                drawRectangle(length, width);
                break;
            }
            case 7: {
                int N;
                cout << "Nhap so nguyen duong N: ";
                cin >> N;
                cout << "Cac so hoan thien nho hon " << N << " la: ";
                for (int i = 1; i < N; i++) {
                    if (isPerfectNumber(i)) {
                        cout << i << " ";
                    }
                }
                cout << endl;
                break;
            }
            case 8: {
                int amount;
                cout << "Nhap so tien can doi: ";
                cin >> amount;
                calculateMinimumNotes(amount);
                break;
            }
            case 9: {
                int n;
                cout << "Nhap so nguyen duong n: ";
                cin >> n;
                int reversed = reverseDigits(n);
                cout << "So sau khi dao nguoc cac chu so: " << reversed << endl;
                break;
            }
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
