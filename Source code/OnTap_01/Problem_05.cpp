/*
Trúng Tuyển
An mới nhận tin trúng tuyển vào UIT năm nay nhưng niềm đam mê thuật toán của cậu ấy rất lớn. Vì vậy, An quyết tâm luyện thuật toán để tham dự vào đội tuyển ICPC của trường. Qua tìm hiểu để đạt được một trình độ cao về thuật toán thì An phải học ít nhất là 
M
 thuật toán. Vì An là sinh viên mới bắt đầu trên con đường thuật toán nên độ hiểu biết về mỗi thuật toán trong 
M
 thuật toán cần học của An là 0 (zero).

Để tăng kiến thức thì An quyết định vào thư viện của trường để tìm những cuốn sách có các thuật toán này. An đã chọn ra được 
N
 cuốn sách, trong mỗi cuốn sách đều có 
M
 thuật toán và nếu An đọc thuật toán j trong cuốn sách thứ i thì độ hiểu biết về thuật toán j sẽ tăng lên là  
H
i
,
j
. Hơn nữa, để thuê cuốn sách thứ i thì phải An trả tiền giá thuê sách là 
C
i
.

Do thời gian ôn luyện có hạn nên để đạt đi mục tiêu thi của mình thì An muốn độ hiểu biết của mình cho mỗi thuật toán trong 
M
 thuật toán đều ít nhất là 
K
. Vì chưa có nhiều điều kiện nên An mong muốn số tiền thuê sách là ít nhất nhưng vẫn đạt mục tiêu đề ra.

Bạn hãy giúp An giải quyết vấn đề nan giải này nhé!

Input:

Dòng đầu tiên gồm 3 số nguyên N, M, K (1≤N,M≤12,1≤K≤105)là số lượng sách mà An đã chọn, số lượng thuật toán An cần học và độ hiểu biết tối thiểu của mỗi thuật toán.

Trong N dòng tiếp theo, dòng thứ i+1 chứa M+1 số nguyên, số đầu tiên là giá tiền để thuê quyển sách thứ i là Ci (1≤Ci≤105)và M số  Hi,1,Hi,2,…,Hi,M (0≤Hi,j≤105) là độ iểu biết khi đọc thuật toán j trong quyển sách thứ i.

Output:

In ra số tiền thuê sách ít nhất mà An mong muốn, nếu không thể thực hiện được thì in ra -1.

Input
3 3 10

60 2 2 4

70 8 7 9

50 2 3 9

Output
120
*/