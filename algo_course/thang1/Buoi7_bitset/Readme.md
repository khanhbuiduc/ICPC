bitset: 

Cú pháp:
bitset <10000> mybitset; // mybitset = <000000000000 ...... 0000>

Bình thường 1 byte chiếm 8 bit

Số byte ma 1 bitset gom 1000 bit chiếm: 1000 / 8 = 125 byte

Mặc định khi khai bao bitset thì cac bit la bit 0

Một số hàm trong bitset

    Hàm reset(): Hàm reset cac bit ve 0.
        Ví dụ:
            bitset <5> mybitset = "10110";
            mybitset.reset(2); // 10010
            mybitset.reset(); // 00000
    Hàm flip(): Hàm flip đổi giá trị các bit (từ 0 -> 1 và từ 1 -> 0).\
        Ví dụ:
            bitset <5> mybitset = "10110";
            mybitset.flip(2); // 10010
            mybitset.flip(); // 01101
    Hàm set(): Gán giá trị của bit tại vị trí bằng 1 bit cho trước.
        Ví dụ:
            bitset <5> mybitset = "10110";
            mybitset.set(2, 1); // 10110
            mybitset.set(0, 1); // 10111
    Hàm count(): trả về số lượng 1: O(Limit/64)
phép toán:
    << : shift left
    >> : shilf right
    ^ : xor
    ~ : flip
    & : and
    | : or

-------------
Bitset

Co N cong nhan, mỗi cong nhan se co mot danh sach nhung ngay ranh trong thang (gia sử thang có 30 ngày). Ta cần chon 2 công nhân i và j sao cho số lượng ngày nghi
cua 2 cong nhan nay nhieu nhat co the.

1 <= N <= 5000

Ví dụ:
Công nhân 1: 1, 3, 5, 6, 15, 18, 24, 30
Công nhân 2: 2, 3, 9, 10, 15, 16, 18, 29, 30
Công nhân 3: 7, 8, 12, 13, 15, 19, 26, 27, 30
In ra số ngày ranh nhieu nhat co thể.
 ----------------

Ta lưu freeDay[i] với ý nghĩa freeDay[i] la một bitset đại diện cho nhung ngay nghi cua cong nhan

Ta khai báo:

bitset <101> freeDay[5005];

Công nhân thứ i nghi ngày d, ta se gọi freeDay[i].set(d, 1)

Xét 2 công nhân i và j
    Xét day bitset <101> B = freeDay[i] & freeDay[j] // 0(101/ 64)
        số lượng ngày nghi: B.count() // 0(101 / 64)
O(N^2)

------------------------------
Nktrio:

Co N cao thủ, ta co mot bang A kich thuoc N hang N cot. Trong do A[i][j] - 0 hoặc 1.
A[i][j] = 1 nếu cao thủ i có thể đanh bại được cao thủ j
Ta cần chọn ra 3 cao thủ X, Y, Z có thể khac chế lẫn nhau.

X, Y, Z khắc chế lẫn nhau nếu

X thắng Y
Y thắng Z
Z thắng X

----------------------------

Ta tạo ra N bitset canWin[i] với ý nghia canWin[i] chứa một tập hợp cac cao thu ma i co the đanh bại. Bit thứ j trong canWin[i] - 1 nếu i có thể đánh bại j
Ta tạo ra N bitset canLose[i] với ý nghĩa canLose[i] chứa một tập hợp cac cao thủ co thể đanh bại cao thủ i. Bit thứ j trong canLose[i] - 1 nếu j đánh bại được i.
Xét cao thủ i và j và i có thể đánh bại được j
Ta tìm cao thủ k sao cho j đánh bại được k và k đánh bại được i
--=- > k nam trong tập canWin[j], và k nam trong tập canLose[i]
Ta xét tập hợp B = canWin[j] & canLose[i]. Neu B.count() >- 1 ---- > co 1 nguoi trong tap B co the thang nguoi i va thua người j. |

-------------------------------

Beautiful Subgrids

Cho mot bang hanh chu nhat, mot so o la o den, mot so o la o trang. Dem co bao nhieu hinh Ichu nhat ma 4 goc la mau den.

tạo bitset: and dòng i vs j với nhau: đếm số bit 1: nC2 là ra kết quả
 