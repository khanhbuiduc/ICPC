Buổi 5: Binary search tree
set


upper_bound(x) >> tìm số >x  
lower_bound(x) >> tìm số >= x 
end()
insert()
begin()
size()
swap()
------------------------
Minimum Loss

Đề bài:

Một căn nhà sẽ có giá thay đổi theo thời gian trong N năm.  
Năm thứ i, căn nhà có giá là p[i].

Yêu cầu:
- Người ta chọn mua nhà ở năm i và bán lại ở năm j (với j > i)
- Điều kiện:
    + Giá mua phải **lớn hơn** giá bán (tức là bị lỗ)
    + Số tiền **lỗ là ít nhất có thể**

Hãy tính số tiền lỗ nhỏ nhất có thể.


---

Ví dụ:

N = 10  
p = [5, 10, 1, 1, 2, 9, 5, 6, 2, 3]

dùng 1 kho chứa giá trị năm i -> j-1
	kho tìm đc giá trị nhỏ nhất > giá trị hiện tại
---------------------------------------
Movie  festival

Đề bài:

Có N bộ phim. Bộ phim thứ i sẽ chiếu trong khoảng thời gian [start[i], end[i]].

Có K người đi xem phim, với các nguyên tắc sau:

+ Không có 2 người cùng xem một bộ phim.  
+ Người xem không được bỏ về giữa chừng khi bộ phim đang chiếu.  
+ Một người có thể xem tiếp một bộ phim khác nếu:
    - Bộ phim hiện tại họ đang xem đã kết thúc, hoặc  
    - Hiện tại họ không đang xem bộ phim nào.

Lưu ý: Nếu một bộ phim kết thúc tại thời điểm x, thì người đó **có thể bắt đầu xem bộ phim tiếp theo từ thời điểm x trở đi.**

Yêu cầu:  
Hỏi có thể có **tối đa bao nhiêu bộ phim** được xem?

N = 10, K = 4  

Danh sách các bộ phim (start, end):

1. [1, 4]  
2. [1, 10]  
3. [3, 4]  
4. [2, 8]  
5. [4, 6]  
6. [2, 10]  
7. [2, 4]  
8. [6, 6]  
9. [11, 14]  
10. [2, 7]


nhận xét: ta ưu tiên xem những bộ phim có thời điểm kết thúc sớm nhất
============> xắp xếp những khoảng thời gian coi bộ phim tăng dần theo thời điểm kết thúc
1 4
3 4
2 4
4 6
5 6
2 7
2 8
1 10
2 10
11 14

kho = {0,0,0,0}
1 4	có ai xem phim trc 1 không,
kho = {4,0,0,0}
ans=1

3 4 có ai xem phim trc 3 không
kho = {4,4,0,0}
ans = 2
....
thay người  lớn nhất <= x (tìm upper_bound rồi lùi lại,  nếu upper_bound là begin() thì không tìm ra và k cần lùi)

kho  đc tổ chức bằng multiset
----------------------------------------------------------
Max Median (Bài H - ACM ICPC miền Bắc)

Cho một dãy số a, ban đầu là một dãy rỗng.

Có Q thao tác, mỗi thao tác là một trong ba loại sau:

- IN x: Thêm số x vào dãy a.
- OUT x: Xóa số x khỏi dãy a.
- MEDIAN: Tính trung vị của dãy a.

**Định nghĩa trung vị của dãy a như sau:**

Đánh số các phần tử trong dãy a từ 0 đến N - 1 sau khi sắp xếp tăng dần.

- Nếu số phần tử là lẻ: Trung vị là a[N / 2].
- Nếu số phần tử là chẵn: Trung vị là (a[N / 2 - 1] + a[N / 2]) / 2.

**Ví dụ:**
Q = 10
IN 3        // a = [3]
IN 2        // a = [3, 2]
MEDIAN      // [2, 3] ==== > (2 + 3) / 2 = 2.5
OUT 2       // a = [3]
IN 4        // a = [3, 4]
IN 6        // a = [3, 4, 6]
IN 6        // a = [3, 4, 6, 6]
MEDIAN      // [3, 4, 6, 6] === > (4 + 6) / 2 - 5
IN 10       // a = [3, 4, 6, 6, 10]
MEDIAN      // [3, 4, 6, 6, 10]  ===- > 6 |

Ta định nghĩa hai tập hợp:
- smaller: là tập hợp chứa một nửa số phần tử nhỏ hơn trong dãy a.
- larger: là tập hợp chứa nửa còn lại (các phần tử lớn hơn) trong dãy a.

Lưu ý: Nếu dãy a có số lượng phần tử là lẻ, thì smaller sẽ chứa nhiều hơn larger đúng 1 phần tử.

Ban đầu, ta khởi tạo:
- smaller = {}
- larger = {}



















