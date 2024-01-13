/*
    Bạn Bình mua được một tờ giấy kẻ ô được tô màu trắng đen lẫn lộn. Nhìn tờ giấy tô màu không có quy tắc gì cả, Bình bỗng nghĩ ra một câu hỏi thú vị. Giả sử chúng ta chọn một vài hàng và một vài cột nào đó (có thể không chọn cũng được), sau đó tô lại tất cả các ô trong những hàng và cột được chọn thành màu đỏ thì có cách nào để số ô màu đen còn lại sẽ đúng bằng số tuổi của Bình hay không?

    Hãy viết chương trình giúp Bình đếm xem có bao nhiêu cách chọn hàng và cột thỏa mãn yêu cầu.

    INPUT
    Dòng đầu tin chứa 03 số nguyên H, W, K, lần lượt là số hàng, số cột và số tuổi của Bình.

    H dòng tiếp theo sẽ có đúng W ký tự viết liền với nhau. Ký tự dấu chấm (".") đại diện cho ô màu trắng, và ký tự dấu hashtag ("#") đại diện cho ô màu đen.

    Cho biết H và W sẽ không vượt quá 6 và Bình thì không quá H*W tuổi

    OUTPUT
    Số cách lựa chọn thỏa mãn yêu cầu

    Input
    2 3 2
    2 3 2
    ..#
    ###

    Output
    5

    Giải thich
    5 cách lựa
    5 cách lựa chọn tô màu đó là:

    Hàng 1, cột 1
    Hàng 1 cột 2
    Hàng 1 cột 3
    Cột 1 và cột 2
    Chỉ tô cột 3

    Input
    2 3 4
    2 3 4
    ..#
    ###

    Output
    1

    Giải thích
    Chỉ có 01 lựa chọn đúng, là đừng có tô gì cả

    Input
    2 2 3
    2 2 3
    ##
    ##

    Output
    0

    Giải thích
    Tô hay không tô gì thì cũng không đáp ứng yêu cầu

    Input
    6 6 8
    6 6 8
    ..##..
    .#..#.
    #....#
    ######
    #....#
    #....#

    Output
    208
*/