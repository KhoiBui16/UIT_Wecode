/*
    Lô Tô 3 x 3
    An đang tham
    An đang tham gia một trò chơi do hội trại của trường tổ chức, được gọi là "Lô Tô 3x3". Trò chơi này khá giống với trò chơi lô tô truyền thống, nhưng có một vài thay đổi trong cách chơi và cấu trúc phiếu chơi.

    Mỗi người chơi nhận một phiếu chơi có dạng hình vuông 3x3, với mỗi ô tại hàng i từ trên xuống và cột j từ trái sang phải chứa số Ai,j. Những con số này nằm trong khoảng từ 1 đến 100 và không có hai ô nào trong phiếu có số giống nhau.

    Sau đó, người dẫn quản trò sẽ lấy ngẫu nhiên trong một hộp kín ra lần lượt các N phiếu có chứa số 
    b1,b2,…,bN. Nếu phiếu lô tô chứa một số trong những số được lấy lên từ hộp, người chơi sẽ đánh dấu chúng trên phiếu của mình. Người chơi đầu tiên có một hàng, cột hoặc đường chéo của ba số đã đánh dấu trên phiếu sẽ là người chiến thắng và nhận được một phần quà rất giá trị.

    Nhiệm vụ của bạn là giúp An xác định rằng cậu ấy có thể nhận được phần quà từ trò chơi này sau N lần lấy phiếu hay không?

    Input:

    Trong 3 dòng đầu tiên, dòng chứ i chứa ba số nguyên 
    Ai,1,Ai,2,Ai,3.
    Dòng thứ 4 chứa số nguyên N (1≤N≤10) là số lấy phiếu trong hộp kín.

    N dòng tiếp theo mỗi dòng là một số nguyên bi là số trên phiếu ở lần lấy thứ i.

    Output:

    Nếu An đạt được giải thưởng thì in ra ‘Yes’, ngược lại in ra ‘No’.

    Input
    84 97 66
    84 97 66

    79 89 11

    61 59 7

    7

    89

    7

    87

    79

    24

    84

    30

    Ouput
    Yes
*/