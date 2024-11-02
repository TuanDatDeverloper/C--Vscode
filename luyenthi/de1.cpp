/*
You are given an array a=[1,2,…,n], where n is odd, and an integer k.
Your task is to choose an odd positive integer m and to split a into m subarrays b1,b2,…,bm such that:
Each element of the array a belongs to exactly one subarray.
For all 1≤i≤m, |bi| is odd, i.e., the length of each subarray is odd.
median([median(b1),median(b2),…,median(bm)])=k, i.e., the median of the array of medians of all subarrays must equal k. median(c) denotes the median of the array c.
A subarray of the array a of length n is the array [al,al+1,…,ar] for some integers 1≤l≤r≤n.
A median of the array of odd length is the middle element after the array is sorted in non-decreasing order. For example: median([1,2,5,4,3])=3, median([3,2,1])=2, median([2,1,2,1,2,2,2])=2.
Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤5000) — the number of test cases. The description of the test cases follows.
The first line of each test case contains two integers n and k(1≤k≤n<2x10^5, n is odd) — the length of array a and the desired median of the array of medians of all subarrays.
It is guaranteed that the sum of n over all test cases does not exceed 2x10^5.
Output
For each test case:
If there is no suitable partition, output −1 in a single line.
Otherwise, in the first line, output an odd integer m (1≤m≤n), and in the second line, output m distinct integers p1,p2,p3,…,pm (1=p1<p2<p3<…<pm≤n) — denoting the left borders of each subarray.
In detail, for a valid answer [p1,p2,…,pm]:
b1=[ap1,ap1+1,…,ap2−1]
b2=[ap2,ap2+1,…,ap3−1]
…
bm=[apm,apm+1,…,an].
If there are multiple solutions, you can output any of them.
Example
Input
4
1 1
3 2
3 3
15 8
Output
1
1
3
1 2 3
-1
5
1 4 7 10 13
Note
In the first test case, the given partition has m=1 and b1=[1]. It is obvious that median([median([1])])=median([1])=1.
In the second test case, the given partition has m=3 and:
b1=[1]
b2=[2]
b3=[3]
Therefore,  median([median([1]),median([2]),median([3])])=median([1,2,3])=2.
In the third test case, there is no valid partition for k=3.
In the fourth test case, the given partition has m=5 and:
b1=[1,2,3]
b2=[4,5,6]
b3=[7,8,9]
b4=[10,11,12]
b5=[13,14,15]
Therefore, median([median([1,2,3]),median([4,5,6]),median([7,8,9]),median([10,11,12]),median([13,14,15])])=median([2,5,8,11,14])=8
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    
    // Special case: n = 1
    if (n == 1) {
        if (k == 1) {
            cout << "1\n1\n";
            return;
        }
        cout << "-1\n";
        return;
    }
    
    if (k > n || k < 1) {
        cout << "-1\n";
        return;
    }

    // Try to find a valid partition with k as median
    vector<long long> starts;
    starts.push_back(1);  // First subarray always starts at 1

    // Create central subarray containing k
    long long centerSize = 1;
    long long centerStart = k - centerSize/2;
    if (centerStart > 1) starts.push_back(centerStart);
    
    // Add left side subarrays
    for (long long i = 1; i < centerStart; i += 3) {
        if (i != 1) starts.push_back(i);
    }
    
    // Add right side subarrays
    for (long long i = k + centerSize/2 + 1; i <= n; i += 3) {
        starts.push_back(i);
    }
    
    sort(starts.begin(), starts.end());
    long long m = starts.size();
    
    // Verify if this is a valid solution
    if (m % 2 == 1) {
        vector<long long> medians;
        for (long long i = 0; i < m; i++) {
            long long start = starts[i];
            long long end = (i == m-1) ? n : starts[i+1]-1;
            long long len = end - start + 1;
            if (len % 2 == 0) continue;  // Skip if length is even
            medians.push_back(start + len/2);
        }
        
        if (medians.size() % 2 == 1) {
            sort(medians.begin(), medians.end());
            if (medians[medians.size()/2] == k) {
                cout << m << "\n";
                for (long long x : starts) cout << x << " ";
                cout << "\n";
                return;
            }
        }
    }
    
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
github copilot giúp tôi sửa:
Những Vấn Đề Trong Đoạn Mã
Có một số điểm chính khiến đoạn mã của tôi không chính xác:
Kiểm Tra Trung Vị Không Đúng Yêu Cầu:
Yêu cầu: Trung vị của tất cả các trung vị của các mảng con phải bằng k.
Trong mã của bạn: Bạn chỉ kiểm tra xem có bất kỳ mảng con nào có trung vị bằng k hay không, điều này không đảm bảo rằng trung vị của các trung vị là k.
Phương Pháp Phân Chia Mảng Con Cố Định:
Bạn cố gắng chia mảng thành các mảng con có độ dài 3, nhưng không đảm bảo rằng điều này sẽ luôn tạo ra một phân chia hợp lệ thỏa mãn yêu cầu về trung vị.
Điều này làm giới hạn khả năng phân chia và có thể dẫn đến kết quả sai cho các trường hợp khác nhau.
Xử Lý Các Trường Hợp Dư:
Khi xử lý phần tử dư, bạn chỉ thêm một mảng con nữa nếu còn đủ 3 phần tử, nhưng không đảm bảo rằng việc này sẽ giúp đạt được trung vị mong muốn.
Đề Xuất
4. Đề Xuất Giải Pháp Sửa Đổi
Để giải quyết vấn đề một cách chính xác, chúng ta cần:
Chọn Một Mảng Con Trung Tâm Chứa k Là Trung Vị:
Vì mảng a đã được sắp xếp, mảng con này phải bao gồm k và các phần tử xung quanh một cách đối xứng.
Phân Chia Các Phía Trái và Phải Đúng Cách:
Phía trái của mảng trung tâm phải được phân chia thành các mảng con có trung vị nhỏ hơn hoặc bằng k.
Phía phải của mảng trung tâm phải được phân chia thành các mảng con có trung vị lớn hơn hoặc bằng k.
Đảm Bảo Số Lượng Các Mảng Con Ở Hai Phía Phù Hợp:
Tổng số mảng con phải là số lẻ.
Đảm bảo rằng số lượng các mảng con bên trái và bên phải đều phù hợp để trung vị của các trung vị là k.
Tính Toán và Xác Minh Phân Chia:
Sau khi phân chia, tính toán các trung vị của từng mảng con.
Sắp xếp các trung vị này và kiểm tra xem trung vị của danh sách này có bằng k hay không.
*/
