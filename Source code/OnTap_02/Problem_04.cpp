/*
        2023.kiemtra.laptrinh.de2.problem4
        Anh Bình đã tốt nghiệp và được mời vào team phân tích dữ liệu cho một dự án game online rất lớn của công ty NaviGame (không có liên quan gì đến đội tuyển esport Navi hay công ty Vinagame cả). Sau một thời gian phân tích "vì sao dự án game được đầu tư hoành tráng nhưng doanh thu khá thấp?", Bình nhận ra một điều khá thú vị.

    Với tất cả n người chơi đã đăng ký của game, người chơi thứ i bất kỳ nào đó sẽ bắt đầu online từ ngày Ai (ngày game bắt đầu launch được đếm là ngày 1) và sau đó đăng nhập vào game liên tục trong Bi ngày rồi bỗng dưng ngưng luôn không còn muốn đăng nhập vào game nữa.

    Đây là thông tin quan trọng về khả năng thu hút người chơi của game và cần trình bày ngay cho ban giám đốc. Tuy nhiên để tổng hợp số liệu và đưa vào báo cáo thì Bình cần một chương trình nho nhỏ có khả năng đếm số ngày có chính xác một lượng người chơi nào đó online.

    Bạn viết chương trình này giúp Bình nhé.

    INPUT
    Cho biết n không quá 200.000 và các số còn lại trong input có giá trị không quá 1 tỷ.

    Input có dạng như sau:
    n
    n

    A1 B1

    A2 B2

    ...

    An Bn

    OUTPUT
    D1 D2 ... Dn

    Trong đó Dk là số lượng ngày có k user online

    Input
    3
    3
    1 2
    2 3
    3 1
    Output
    2 2 0

    Giải thích
    Player 1 có đăng nhập trong 02 ngày là ngày 1 và 2. Player 2 đăng nhập trong 03 ngày là 2,3,4 và Player 3 có đăng nhập trong 1 ngày duy nhất là ngày 3.

    Vậy có 02 ngày có đúng 1 player đăng nhập, 02 ngày có đúng 2 player đăng nhập và không có ngày nào có đúng 3 player đăng nhập.

    Input
    2
    2
    1000000000 1000000000
    1000000000 1000000000

    Output
    0
    1000000000

    Giải thích
    Không có ngày nào có đúng 1 player đăng nhập và có 1 tỷ ngày có cả 2 ông tướng kia cùng đăng nhập.  
*/