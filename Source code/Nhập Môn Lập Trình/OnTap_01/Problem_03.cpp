/*
Giao dịch
Thị trường giao dịch mã cổ phiếu X đang rất sôi động vì sự giao dịch của N cổ đông và M nhà đầu tư. Người chơi trong thị trường này đều có thể tự do đưa ra mức giá riêng mà họ cảm thấy thoải mái để mua hoặc bán. Mỗi cổ đông, với kỹ năng và phân tích của mình, không sẵn lòng nhả cổ phiếu của mình với mức giá dưới 
a
i
 đô la. Trong khi đó, mỗi nhà đầu tư, với sự đánh giá và phân tích thị trường của mình, chỉ sẵn lòng mua cổ phiếu với mức giá không vượt quá 
b
i
 đô la.

Giả sử bạn là  một chuyên gia phân tích tài chính, bạn cần xác định mức giá cổ phiếu tối thiểu X (trong đó X là  số nguyên), sao cho số cổ đông có thể bán cổ phiếu với mức giá X đô la không nhỏ hơn số nhà đầu tư sẵn lòng mua cổ phiếu với mức giá X đô la. Mục tiêu của việc này là tạo ra một sự cân bằng giữa cung và cầu trên thị trường cổ phiếu, với hy vọng tối ưu hóa lợi ích kinh tế cho tất cả các bên tham gia thị trường.


Input:

Dòng đầu tiên chứa hai số nguyên N, M (1≤N,M≤2×105) là số lượng cổ đông và số lượng nhà đầu tư.

Dòng tiếp theo chứa N số a1,a2,…,aN  với ai  (1≤ai≤109) là mức giá tối thiểu của cổ đông thứ i.

Dòng cuối cùng chứa M số b1,b2,…,bM với bi  (1≤bi≤109) là mức giá tối đa mà nhà đầu tư i có thể mua. 

Output:

In ra mức giá cổ phiếu tối thiểu để cân bằng sự cung cầu của thị trường.


Input
3 4

110 90 120

100 80 120 10000

Output
110
*/