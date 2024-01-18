/*
    Chính phương
    Alice và Bob đang làm việc tại một công ty bảo mật mạng. Một ngày nọ, hai bạn nhận được một yêu cầu từ khách hàng, yêu cầu họ phát triển một hệ thống mật mã dựa trên số chính phương.

    Được biết, số chính phương là những số có thể được biểu diễn dưới dạng bình phương của một số nguyên. Trong mật mã học, các số chính phương đôi khi được sử dụng như là một phần quan trọng của quá trình sinh khóa hoặc mã hóa thông tin. Sự đặc biệt của số chính phương là độ khó trong việc phân tích các thành phần nguyên tố, đặc biệt khi số cần phân tích trở nên lớn, điều này giúp tăng cường bảo mật trong quá trình mã hóa.

    Để xây dựng một hệ thống lớn như trên, Alice và Bob đã lên kế hoạch chia dự án thành các phần nhỏ hơn và sẽ hoàn thành từng phần. Dù đã gần hoàn thành tất cả các phần của dự án, nhưng hai bạn vẫn có một phần chưa thể giải quyết được đó là tạo một hàm để đếm các cặp số nguyên dương từ một tập hợp các số nguyên dương không lớn hơn số nguyên N sao cho tích của chúng tạo ra một số chính phương. 

    Đối mặt với nhiệm vụ phức tạp này, Alice và Bob vẫn chưa nghĩ ra được một ý tưởng gì mới. Bạn hãy giúp Alice và Bob thực hiện phần này nhé!

    Input: Một dòng chứa số nguyên dương N (1≤N≤105)

    Output: Một số là đầu ra của hàm mà bạn giúp cho Alice và Bob.

    Input
    4
    Output
    6

    Giải thích: Với N = 4 thì có 6 cặp số với mỗi số nhỏ với mỗi số nhỏ hơn 4 nhưng tích

    là số chính phương đó là (1, 1), (1, 4), (4, 1), (2, 2), (3, 3), (4, 4).

*/