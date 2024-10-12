#include <iostream>
using namespace std;
typedef unsigned long long u64;

// team VKU VTĐ
u64 tinhTongBinhPhuong(u64 N, u64 M) {
    if (N == 0) return 0;
    if (M == 0) return 0;

    u64 a = N, b = N + 1, c = 2 * N + 1;

    
    if (a % 2 == 0) {
        a /= 2;
    } else {
        b /= 2;
    }

    
    if (a % 3 == 0) {
        a /= 3;
    } else if (b % 3 == 0) {
        b /= 3;
    } else {
        c /= 3;
    }

    
    __int128 ketQua = (__int128)a * b;
    ketQua %= M;
    ketQua = (ketQua * c) % M;

    return (u64)ketQua;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    u64 A, B, M;
    cin >> A >> B >> M;

    
    u64 tongB = tinhTongBinhPhuong(B, M);
    u64 tongA = (A > 0) ? tinhTongBinhPhuong(A - 1, M) : 0;

    
    u64 ketQua = (tongB >= tongA) ? (tongB - tongA) : (M + tongB - tongA);
    ketQua %= M;

    cout << ketQua << endl;
}
