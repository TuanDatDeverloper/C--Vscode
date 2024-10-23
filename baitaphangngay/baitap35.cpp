/*
Admin trẻ tuổi nhất của cộng đồng Vinoy — VLT — sinh ra trong gia tộc V.L. danh gia vọng tộc đứng thứ 2 thế giới chỉ sau gia tộc N.H. Trong truyện, cậu được miêu tả một cách vô cùng hư cấu như sau:
Ngoại hình : soái ca, vô cùng đẹp trai cao 1 mét 86 đôi mắt hổ phách mái tóc bạch kim
Tính cách : lạnh lùng thờ ơ chỉ bên người thân mới ấm áp và rất yêu nó, siêu quậy
IQ : 300 / 300 giỏi tất cả các loại võ chuyên về sử dụng súng và chế tạo vũ khí
Gần đây, VLT vừa khám phá ra một văn tự cổ xưa, nghi rằng có liên quan đến gia tộc V.L.
Đáng ngạc nhiên là văn tự này lại được viết bằng bảng chữ cái Latin in thường. Ngay lập tức, VLT bắt tay vào việc giải mã văn tự này. Với IQ 300/300 của mình, VLT suy luận rằng manh mối chắc chắn nằm ở một đoạn liên tiếp của văn tự và có liên quan đến tên của một trong các tổ tiên của mình. Tất nhiên, VLT đã có sẵn gia phả bao gồm tên của n tổ tiên thuộc gia tộc V.L. Như một truyền thống, thành viên thứ i gia tộc V.L. được đặt tên giống với tên của một tổ tiên xi trước đó, ghép với "tên riêng" là một xâu si không rỗng gồm các chữ cái Latin viết thường. Ví dụ, nếu tổ tiên thứ nhất có tên là "vuong", x2 = 1,s2 = " long" thì tổ tiên thứ hai sẽ có tên là "vuonglong". Tương tự, nếu x3 = 2,s3 = "toan" thì tổ tiên thứ ba sẽ có tên là "vuonglongtoan".
Vấn đề duy nhất còn lại là VLT không chắc là manh mối nằm ở đoạn nào của văn tự, do đó cậu chọn ra q đoạn văn, đoạn thứ i gồm các kí tự thứ từ li tới ri của văn tự. Với mỗi đoạn văn, VLT muốn biết số thứ tự của tổ tiên có tên có thứ tự từ điển lớn nhất nhưng không lớn hơn đoạn văn đang xét.
Nhắc lại, xâu ký tự s = s1s2…sm có thứ tự từ điển nhỏ hơn xâu ký tự t = t1t2…tn khi và chỉ khi một trong hai điều kiện sau được thoả mãn:
	m < n và s1 = t1, s2 = t2, …,sm = tm. Nói cách khác, s là một tiền tố thực sự của t.
	Tồn tại chỉ số i thoả mãn i < min(m,n), s1 = t1, s2 = t2, …,si = ti và si+1 < ti+1. 
Input
  Dòng đầu tiên chứa số nguyên T – số thứ tự của subtask chứa test này.
  Dòng thứ hai chứa xâu ký tự gồm từ 1 tới 5 × 10^5 chữ cái in thường thể hiện văn tự cổ xưa mà VLT khám phá được.
Dòng thứ ba chứa số nguyên n – số tổ tiên thuộc gia tộc V.L.
Trong n dòng tiếp theo, dòng thứ i chứa số nguyên xi và xâu ký tự si (gồm từ 1 tới  5 × 10^5 chữ cái in thường), cho biết tên của thành viên thứ i trong gia tộc được tạo ra bằng cách ghép tên của thành viên thứ xi với tên riêng  si. Nếu xi = 0, tên của thành viên thứ i chính là si. Tổng độ dài của các xâu s1, s2, …,sn không quá  5 × 10^5.
Dòng tiếp theo chứa số nguyên q – số đoạn văn mà VLT quan tâm.
Trong q dòng cuối cùng, dòng thứ i chứa hai số nguyên li và ri với p là độ dài văn tự cổ, cho biết đoạn văn thứ i được tạo ra bởi cách lấy các ký tự từ vị trí li tới vị trí ri của văn tự cổ. Các ký tự được đánh số từ 1.
Output
  Gồm q dòng, dòng thứ i chứa một số nguyên duy nhất là số thứ tự của tổ tiên có tên có thứ tự từ điển lớn nhất nhưng không lớn hơn đoạn văn thứ i. Nếu nhiều tổ tiên cùng thoả mãn điều kiện này, in ra số thứ tự của tổ tiên có số thứ tự nhỏ nhất. Nếu không có tổ tiên nào thoả mãn, in ra −1. Các tổ tiên được đánh số từ 1 tới n.
Constraints
1 ≤ T ≤ 4
1 ≤ n ≤ 3 × 10^5
0 ≤ xi < i
1 ≤ q ≤ 3 × 10^5
1 ≤ li ≤ ri ≤ p
Scoring
  Subtask 1 (8.3% số điểm): n,q ≤ 2000. Văn tự cổ và tên của mỗi người trong dòng họ có không quá 2000 kí tự.
  Subtask 2 (26.6% số điểm): Tổng độ dài của q đoạn văn tự cần xét (tổng của các ri − li + 1) không quá 10^7.
  Subtask 3 (28.3% số điểm): x1 = x2 = ⋯ = xn = 0.
  Subtask 4 (36.6% số điểm): Không có ràng buộc gì thêm.
Example 
input
2 
vuonglongtoanatgmaildotcomorz 
6 
0 vuong 
1 long 
2 tu 
1 hoang 
2 toan 
4 long 
6 
1 13 
1 4 
1 6 
14 26 
29 29 
1 8  
output
5 
-1 
6 
-1 
3
6
input
1 
aaabcbdaac 
6 
0   a 
1   bc 
0 ab 
3 c 
3 ab 
1 ab 
6 
1 3 
3 5 
2 2 
8 10 
10 10 
9 10  
output
1 
2 
1 
6 
2 
2
*/
