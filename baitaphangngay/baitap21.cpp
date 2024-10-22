/*Cho đồ thị có hướng G = (V ,E) gồm N đỉnh và M cung, s và t là hai đỉnh của đồ thị G. Một dãy các đỉnh P = ⟨p0 = s,p1, p2, …,pk = t⟩ sao cho (pi1 , pi) ∈ E, được gọi là 1 đường đi từ s đến t. Một đường đi đơn giản (còn gọi là đường đi đơn) nếu tất cả các đỉnh trên đường đi đôi một khác nhau.
Biết rằng tồn tại ít nhất một đường đi từ s tới t, hãy chỉ ra đường đi đơn có thứ tự từ điển nhỏ nhất.
Input
Dòng đầu chứa các số nguyên N, M, đỉnh xuất phát s, đỉnh cần đến t.
M dòng tiếp theo, mỗi dòng chứa 2 số nguyên dương u,v (1 ≤ u,v ≤ N), thể hiện cho 1 cung nối từ đỉnh u đến đỉnh $v trong đồ thị.
Output
  Ghi ra trên một dòng các đỉnh theo đúng thứ tự trên đường đi tìm được, bắt đầu từ đỉnh s, kết thúc ở đỉnh t theo thứ tự từ điển nhỏ nhất.
Scoring
Subtask 1 (30% số điểm): N ≤ 10^3,M ≤ 10^4
Subtask 2 (70% số điểm): N ≤ 10^5,M ≤ 10^6
Input
8 12 1 8
1 2
1 3
2 3
2 4
3 1
3 5
3 7
4 6
6 2
6 8
7 8
7 6 
Output
1 2 3 7 6 8
*/
#include <bits/stdc++.h>
using namespace std;
// sử dụng mảng kề để lưu đồ thị
vector<int> a[100005];
// đọc số lượng đỉnh và cung
int n, m;
// đọc đỉnh xuất phát và đỉnh kết thúc
int s, t;
// đọc cung của đồ thị
int u, v;
// mảng đánh dấu đỉnh đã thăm
bool visited[100005];
// mảng đánh dấu đỉnh trước đỉnh i trên đường đi
int trace[100005];
// hàm đọc dữ liệu
void read(){
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        a[u].push_back(v);
    }
}
// hàm dfs tìm đường đi từ s đến t
void dfs(int u){
    visited[u] = true;
    for(int v : a[u]){
        if(!visited[v]){
            trace[v] = u;
            dfs(v);
        }
    }
}
// hàm in ra đường đi từ s đến t
void print(){
    if(!visited[t]){
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    while(t != s){
        res.push_back(t);
        t = trace[t];
    }
    res.push_back(s);
    reverse(res.begin(), res.end());
    for(int v : res){
        cout << v << " ";
    }
}
int main(){
    read();
    dfs(s);
    print();
    return 0;
}

