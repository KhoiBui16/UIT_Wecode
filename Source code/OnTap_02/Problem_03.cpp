/*
Đề này ngắn lắm: Cho dãy n số nguyên A1, A2, ..., An . Tính tổng  các tích giữa các cặp số trong dãy rồi chia tổng đó cho một tỷ lẻ bảy lấy dư. Nếu đọc câu mô tả ngắn đó chưa giúp  bạn hiểu đề thì đây sẽ là công thức:

\( \sum_{i =1}^{n-1} \sum_{j=i+1}^{n}A_iA_j \) modulo (109+7)

INPUT
Dòng đầu tiên chứa số nguyên dương n giá trị từ 2 đến 200.000

Dòng tiếp theo chứa n số nguyên không âm, giá tị không quá 1 tỷ, mỗi số cách nhau bởi 1 khoảng trắng.

OUTPUT
Giá trị đề yêu cầu.

Input
3
1 2 3

Output
11
(Vì 1×2+1×3+2×3=11)

INPUT
4
141421356 17320508 22360679 244949

OUTPUT
437235829
*/