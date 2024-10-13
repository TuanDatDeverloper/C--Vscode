#include <iostream>
#include <vector>
using namespace std;
//team VKU VTĐ
const int VKU_MAXN = 100005;
vector<int> vku_adj[VKU_MAXN];
int vao_vku[VKU_MAXN], ra_vku[VKU_MAXN], tg_vku = 0;
void vku_dfs(int vku_u, int vku_p) {
vao_vku[vku_u] = ++tg_vku;
for (int vku_v : vku_adj[vku_u]) {
if (vku_v != vku_p) {
vku_dfs(vku_v, vku_u);
}
}
ra_vku[vku_u] = ++tg_vku;
}

int main() {
int vku_n; 
cin >> vku_n;

vector<int> vku_parent(vku_n + 1, -1);
for (int i = 0; i < vku_n - 1; ++i) {
int vku_u, vku_v;
cin >> vku_u >> vku_v;
vku_adj[vku_u].push_back(vku_v);
vku_parent[vku_v] = vku_u;
}

int vku_root = 1;
for (int i = 1; i <= vku_n; ++i) {
if (vku_parent[i] == -1) {
vku_root = i;
break;
}
}

vku_dfs(vku_root, -1);

int vku_q;
cin >> vku_q;

while (vku_q--) {
int vku_x, vku_y;
cin >> vku_x >> vku_y;
// Kiểm tra nếu x là tổ tiên của y
if (vao_vku[vku_x] <= vao_vku[vku_y] && ra_vku[vku_x] >= ra_vku[vku_y]) {
cout << "Yes " <<endl;
} else {
cout << "No " << endl;
}
}

return 0;
}
