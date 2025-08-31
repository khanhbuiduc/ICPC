# Buổi 3: Queue/Deque

## Queue

**Queue**: Cấu trúc dữ liệu dạng FIFO (First In - First Out)

### Các hàm chính:

- `push()` - Thêm phần tử vào cuối hàng đợi
- `pop()` - Loại bỏ phần tử đầu hàng đợi
- `empty()` - Kiểm tra hàng đợi có rỗng không
- `size()` - Lấy kích thước hàng đợi
- `front()` - Lấy phần tử đầu hàng đợi

---

## Bài tập 1: Hàng đợi bệnh nhân

### Đề bài

Có một hàng đợi bệnh nhân, ban đầu rỗng.

**Có 2 loại thao tác:**

1. `E x`: Ưu tiên bệnh nhân thứ x lên đầu hàng (x là số nguyên dương)
2. `N`: Người đầu hàng được gọi vào khám. Sau đó, in ra số thứ tự của người đó

**Yêu cầu:** Với mỗi thao tác N, hãy xuất ra số thứ tự của người được khám.

### Input/Output

```
Input:
E 5
E 3
N
N
N

Output:
3
5
1
```

### Ý tưởng ngây thơ

1. Tạo một hàng đợi Q và đưa các bệnh nhân 1, 2, 3, ..., N vào hàng đợi Q
2. Với yêu cầu `N`: Đặt `v = Q.front()`, `Q.pop()`, `Q.push(v)`
3. Với yêu cầu `E x`:
   - Tạo một Q2, đổ tất cả các phần tử trong Q vào Q2 (ngoại trừ x)
   - Sau đó đưa x vào Q và đưa tất cả các phần tử trong Q2 vào Q

**Ràng buộc:**

- 1 ≤ N ≤ 10^9
- 1 ≤ C ≤ 1000

### Ý tưởng tối ưu

1. Tạo một hàng đợi Q và đưa các bệnh nhân 1, 2, 3, ..., min(N,C) vào hàng đợi Q
2. Với yêu cầu `N`: Đặt `v = Q.front()`, `Q.pop()`, `Q.push(v)`
3. Với yêu cầu `E x`:
   - Tạo một Q2, đổ tất cả các phần tử trong Q vào Q2 (ngoại trừ x)
   - Sau đó đưa x vào Q và đưa tất cả các phần tử trong Q2 vào Q

**Độ phức tạp:** 1000 câu lệnh × 1000 thao tác = không bị TLE

---

## Deque

**Deque**: Cấu trúc dữ liệu có thể thao tác ở cả 2 đầu

### Các hàm chính:

- `push_back()` - Thêm phần tử vào cuối
- `push_front()` - Thêm phần tử vào đầu
- `pop_back()` - Loại bỏ phần tử cuối
- `pop_front()` - Loại bỏ phần tử đầu
- `size()` - Lấy kích thước
- `empty()` - Kiểm tra rỗng

---

## Bài tập 2: MinK

### Đề bài

Cho một dãy số nguyên dương `a` gồm N số. Cho trước một số nguyên K.

**Yêu cầu:** Với mỗi đoạn gồm K số liên tiếp trong dãy a, hãy in ra **giá trị nhỏ nhất** trong đoạn đó.

### Ví dụ

```
a = [5, 9, 1, 1, 4, 6, 2, 7, 3, 3, 5, 8, 3]
K = 5
```

**Ràng buộc:**

- 1 ≤ N ≤ 100000
- 1 ≤ K ≤ N ≤ 10^5

### Ý tưởng

Sử dụng deque để lưu vị trí các ứng viên min trong cửa sổ trượt:

- `Kho` lưu vị trí ứng viên min trong K vị trí đang xét từ L→R
- loại bỏ ứng viên < L.
- nếu ai > cuối kho, loại bỏ ứng viên cuối.
- thêm ứng viên đang xét vào cuối
- lấy min ở đầu

(tóm lại kho phải tăng dần).

---

## Bài tập 3: Max Value Equation

### Đề bài

Cho một dãy số points[i] = [xi, yi] với xi < xj khi i < j . Cho trước một số nguyên K.

**Yêu cầu:** tìm max `|yi + yj + |xi - xj||` khi `|xi - xj| <= k`

### Phân tích

```
yi + yj + |xi - xj| = yi + yj - (xi - xj) = yi + yj + xj - xi
```

**Bài toán đưa về:**
Xét các cặp chỉ số (i, j) sao cho:

- i < j
- xj - xi ≤ k
- yi - xi + yj + xj là lớn nhất có thể

### Thuật toán ngây thơ

```cpp
ans = -200000001
for j = 0 to n - 1:
    for i = 0 to j - 1:
        if x[j] - x[i] <= k:
            ans = max(ans, y[i] - x[i] + y[j] + x[j])
```

### Ví dụ minh họa

```
N = 10, k = 5

Danh sách điểm (x, y):
<1, 4>, <2, 8>, <5, -1>, <7, 2>, <11, 9>
<12, 4>, <14, 4>, <19, 7>, <22, -5>, <25, -10>

j = 1: Điểm thỏa mãn x[j] - x[i] <= k: {}
j = 2: {1} ---------> tổng lớn nhất = 13
j = 3: {1, 2}->{2} -> tổng lớn nhất = 10; tổng 2 >= tổng 1 → vứt 1
j = 4: {2, 3} ------> tổng lớn nhất = 15; tổng 3 < tổng 2 → giữ 2
```

### thuật toán chuẩn

### Nhận xét

Khi ta có điểm thứ j, những điểm i cần thiết là những điểm i sao cho: `x[j] - x[i] ≤ k`

```
yi + yj + |xi - xj| = (yi-xi)+ (yj + xj)
```

Ta lưu trữ {(yi-xi), xi} thay vì yi,xi vì ta cần yi - xi max;

### Sử dụng deque lưu trữ số giảm dần

xét (xj,yj): xi = dq.front()

- xj-xi > k => dq.pop_front()
- update maxVal = max(maxVal, (yi - xi)+ (yj + xj))
- thêm {(yj-xj),xj} vào dq.
