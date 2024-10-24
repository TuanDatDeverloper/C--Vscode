#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;
vector<int> danhSachKe[MAX];
int doiNam[MAX], doiNu[MAX];
int khoangCach[MAX];
int soNam, soNu, soCap;

bool timDuongTang() {
    queue<int> hangdoi;
    for (int u = 1; u <= soNam; ++u) {
        if (doiNam[u] == 0) {
            khoangCach[u] = 0;
            hangdoi.push(u);
        } else {
            khoangCach[u] = INT_MAX;
        }
    }
    khoangCach[0] = INT_MAX;

    while (!hangdoi.empty()) {
        int u = hangdoi.front();
        hangdoi.pop();

        if (u != 0) {
            for (int v : danhSachKe[u]) {
                if (khoangCach[doiNu[v]] == INT_MAX) {
                    khoangCach[doiNu[v]] = khoangCach[u] + 1;
                    hangdoi.push(doiNu[v]);
                }
            }
        }
    }

    return khoangCach[0] != INT_MAX;
}

bool timVaGhepDuongTang(int u) {
    if (u != 0) {
        for (int v : danhSachKe[u]) {
            if (khoangCach[doiNu[v]] == khoangCach[u] + 1) {
                if (timVaGhepDuongTang(doiNu[v])) {
                    doiNam[u] = v;
                    doiNu[v] = u;
                    return true;
                }
            }
        }
        khoangCach[u] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    fill(doiNam, doiNam + MAX, 0);
    fill(doiNu, doiNu + MAX, 0);

    int soLuongGhep = 0;
    while (timDuongTang()) {
        for (int u = 1; u <= soNam; ++u) {
            if (doiNam[u] == 0 && timVaGhepDuongTang(u)) {
                soLuongGhep++;
            }
        }
    }
    return soLuongGhep;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Đọc đầu vào
    cin >> soNam >> soNu >> soCap;
    for (int i = 0; i < soCap; ++i) {
        int nam, nu;
        cin >> nam >> nu;
        danhSachKe[nam].push_back(nu);
    }

    // Tìm số lượng cặp ghép tối đa
    int soLuongGhep = hopcroftKarp();

    // Xuất kết quả
    cout << soLuongGhep << "\n";
    for (int u = 1; u <= soNam; ++u) {
        if (doiNam[u] != 0) {
            cout << u << " " << doiNam[u] << "\n";
        }
    }

    return 0;
}
