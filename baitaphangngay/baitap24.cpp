/*Một trò chơi bao gồm n phòng và m máy dịch chuyển. Vào đầu mỗi ngày, bạn bắt đầu ở phòng 1 và bạn phải đến phòng n.
Bạn có thể sử dụng mỗi máy dịch chuyển nhiều nhất một lần trong trò chơi. Bạn có thể chơi bao nhiêu ngày nếu bạn chọn tuyến đường của mình một cách tối ưu?
Input
  Dòng đầu tiên là hai số nguyên n và m: số phòng và số máy dịch chuyển. Các phòng được đánh số
1,2,…,n.
  m dòng tiếp theo mô tả những máy dịch chuyển. Mỗi dòng gồm hai số nguyên a và b: có một máy dịch chuyển từ phòng a sang phòng b.
  Không có hai máy dịch chuyển nào có phòng bắt đầu và kết thúc giống nhau.
Output
  Đầu tiên in ra một số nguyên k: số ngày tối đa bạn có thể chơi trò chơi. Sau đó, in k mô tả tuyến đường theo ví dụ. Bạn có thể in bất kỳ giải pháp hợp lệ nào.
Constraints
2 ≤ n ≤ 500
1 ≤ m ≤ 1000
1 ≤ a,b ≤ n 
example
input
6 7
1 2
1 3
2 6
3 4
3 5
4 6
5 6
output
2
3
1 2 6
4
1 3 4 6*/
#include <bits/stdc++.h>
using namespace std;
// sử dụng phương pháp DFS để tìm đường đi từ phòng 1 đến phòng n
void dfs(int u, int n, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path){
    visited[u] = 1;
    path.push_back(u);
    if(u == n) return;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, n, adj, visited, path);
            if(path.back() == n) return;
            path.pop_back();
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> visited(n + 1, 0);
    vector<int> path;
    dfs(1, n, adj, visited, path);
    cout << path.size() - 1 << endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    return 0;
}
