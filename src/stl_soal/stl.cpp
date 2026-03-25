#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), c(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    // Gabungkan x dan c, lalu sort berdasarkan x
    vector<pair<int,int>> paket(n);
    for (int i = 0; i < n; i++) paket[i] = {x[i], c[i]};
    sort(paket.begin(), paket.end());

    // Tracking kategori yang sudah diambil
    map<int, bool> sudah_ambil;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int kategori = paket[i].second;
        if (!sudah_ambil[kategori]) {
            sudah_ambil[kategori] = true;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}