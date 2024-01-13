/*
Mua quà
Nhân dịp ngày 20/11, ba bạn Hà, Ý, Dương được lớp trưởng phân đi đến cửa hàng lưu niệm để mua quà để tặng thầy/cô, mỗi người phải mua một món quà. Trong cửa hàng có N món quà được sắp theo thứ tự trên kệ từ vị trí 1 đến vị trí 
N
. Món quà ở vị trí thứ i có mã món quà là 
a
i
 . Vì không muốn bị “đụng hàng”  nên ba bạn Hà, Ý, Dương sẽ chọn ra ba món (mỗi người một món) quà khác nhau (hai món quà được xem khác nhau khi nó có mã là khác nhau) hơn nữa, thứ tự chọn quà của ba bạn cũng có chút đặc biệt : vị trí món quà của Hà chọn phải nhỏ hơn vị trí món quà của Ý và vị trí món quà của Ý chọn cũng sẽ nhỏ hơn vị trí món quà của Dương. 

Ví dụ: Cửa hàng có 4 món quà có các mã lần lượt là [3, 1, 4, 1]. Nếu Hà chọn món quà ở vị trí 2, Ý chọn món quà ở vị trí 1 và Dương chọn món quà ở vị trí 3 mặc dù là ba món quà có mã khác nhau nhưng thứ tự chọn của Hà, Ý, Dương lại không thỏa mãn nên lần chọn như vầy sẽ không hợp lệ.

Bạn hãy đếm thử Hà, Ý, Dương cần thử tất cả bao nhiêu cách để chọn quà cho thầy cô.

Input:

Dòng đầu tiên chứa số nguyên N (3≤N≤2×105) là số lượng món quà  có trong cửa hàng.

Dòng thứ 2 chứa N số nguyên là a1,a2,…,aN (1≤ai≤2×105) là mã của các món quà.

Output:

Đưa ra số lương cách chọn quà của Hà, Ý, Dương. 

Input
4

3 1 4 1

Output
2
*/