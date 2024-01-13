/*
Các bạn có 02 bảng số. Bảng A có HA hàng và WA cột, bảng B có HB hàng và WB cột. Các bạn được thực hiện một trong 02 loại thao tác sau lên bảng A:

1.Xóa nguyên một hàng ra khỏi bảng A
2.Xóa nguyên một cột ra khỏi bảng A
Số lượng thao tác được thực hiện là không giới hạn (dĩ nhiên xóa một hồi mà bảng A không còn số nào thì cũng phải ngừng). Hỏi có thể biến bảng A thành bảng B hay không?

INPUT
Dòng đầu tiên là 02 số nguyên HA và WA

HA dòng tiếp theo, mỗi dòng bao gồm WA số nguyên, mỗi số giá trị không quá 1 tỷ và cách nhau bởi khoảng trắng.  Đây là các số trong bảng A

Dòng kế tiếp lại gồm 02 số nguyên là HB và WB

HB dòng tiếp theo là các số trong bảng B với cách ghi tương tự như các số trong bảng A

Cho biết

1 ≤ HB ​≤ HA ​≤ 10
1 ≤ WB ​≤ WA ​≤ 10

OUTPUT
Nếu có thể biến bảng A thành bảng B thì xuất chữ Yes , ngược lại xuất chữ No

Input
4 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
2 3
6 8 9
16 18 19

Output
Yes

Giải thích
Xóa cột 2 ra khỏi bảng A ta có

1 3 4 5
6 8 9 10
11 13 14 15
16 18 19 20
Xóa tiếp hàng thứ 3 ra khỏi bảng A ta lại có

1 3 4 5
6 8 9 10
16 18 19 20
Cuối cùng xóa nốt cột thứ 4 ra khỏi bảng A thì nó sẽ thành bảng B

Input
3 3
1 1 1
1 1 1
1 1 1
1 1
2

Output
No

Giải thích
Trường hợp này thì xóa kiểu gì đi nữa bảng A cũng không thành bảng B được
*/