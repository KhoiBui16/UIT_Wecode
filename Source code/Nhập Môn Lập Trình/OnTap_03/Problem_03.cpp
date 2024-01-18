/*
    Cặp khóa mã hóa
    An đang làm việc trong một công ty lớn và có trách nhiệm bảo mật dữ liệu quan trọng của công ty. Để đảm bảo an toàn cho dữ liệu cho công ty, An đã tham gia nhóm phát triển hệ thống mã hóa bất đối xứng với việc tạo cặp khóa mã hóa dựa trên những số “đặc biệt” mà nhóm của An mới tìm ra. Số “đặc biệt" là một số nguyên dương không thể chia hết cho bình phương của bất kỳ số nguyên nào lớn hơn 1. Sự phức tạp của những số “đặc biệt” này rất thích hợp cho việc tạo ra những khóa mã hóa mạnh.

    Bây giờ, nhóm của An muốn biết có bao nhiêu cặp khóa mã hóa mạnh với mỗi khóa nằm trong khoảng số nguyên nhất định từ L đến R. Một cặp khóa mã hóa (x, y) được xem là mạnh nếu cả khóa x, khóa y và giá trị x*y đều là những số “đặc biệt”, thêm vào đó thì x phải luôn nhỏ hơn y. An chịu trách nhiệm chính cho việc viết chương trình để tính số cặp khóa mạnh này nhưng khổ nỗi là cậu ấy đã quên gần hết việc lập trình. Bạn hãy giúp An viết chương trình này nhé

    Input:  
    Một dòng chứa hai số nguyên dương L và R (1≤L<R≤109,R−L≤1000)là 2 giới hạn của khoảng giá trị của các khóa mã hóa.
    
    Ouput:
    Số cặp khóa mã hóa mạnh mà nhóm An muốn biết.

    Input
    3
    9
    Output
    5

    Giải thích:
    Với L = 3, R = 9: Thì có 5 cặp khóa mã hóa là (3, 5), (3, 7), (5, 6), (5, 7), (6, 7).
*/