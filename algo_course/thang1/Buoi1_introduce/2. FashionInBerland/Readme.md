# Stack Data Structure

## Lý thuyết

**Stack**: Cấu trúc dữ liệu LIFO (Last In - First Out)

### Các hàm cơ bản của Stack:

- `push()`: Thêm phần tử vào đỉnh stack
- `top()`: Lấy phần tử ở đỉnh stack (lỗi khi stack rỗng)
- `pop()`: Loại bỏ phần tử ở đỉnh stack
- `empty()`: Kiểm tra stack có rỗng không
- `size()`: Trả về kích thước stack

---

## 1. ONP (Ký pháp Ba Lan Ngược)

### Khái niệm:

- **Biểu thức chính quy**: `(a o b)`
- **Chuyển đổi**: Biểu thức chính quy → Biểu thức Ba Lan Ngược
- **Ký pháp Ba Lan Ngược**: `(a o b)` → `a b o`

### Ví dụ:

```
(1 + 2) * (3 + 4) → 1 2 + 3 4 + *
```

### Thuật toán tính toán Ba Lan Ngược:

```
Cho: a = 50 75 + 25 10 20 * 30 2 * + + *

Sử dụng stack để lưu trữ số:
1. Duyệt từng phần tử trong a
2. Gặp số: đẩy vào stack
3. Gặp phép tính:
   - Lấy 2 số ở top ra
   - Thực hiện: a o b
   - Đẩy kết quả vào stack
```

---

## 2. Valid Parentheses

### Đề bài:

Cho một chuỗi `s` gồm những dấu ngoặc `(`, `)`, `[`, `]`, `{`, `}`, kiểm tra chuỗi này có hợp lệ hay không.

### Quy tắc:

- Chuỗi rỗng là chuỗi hợp lệ
- Nếu A là chuỗi hợp lệ thì `(A)`, `[A]`, `{A}` là những chuỗi hợp lệ
- Nếu A và B là 2 chuỗi hợp lệ thì AB sẽ là chuỗi hợp lệ

### Ví dụ:

- `()()()`: **hợp lệ**
- `)()()()(`: **không hợp lệ**

### Thuật toán:

Stack lưu trữ danh sách ngoặc mở chưa được đóng.

---

## 3. Nearest Smaller Value

### Đề bài:

Cho một dãy số nguyên dương `a` gồm N phần tử.  
Với mỗi số `a[i]`, tìm vị trí gần nhất ở bên trái của nó mà giá trị < `a[i]`.  
Nếu không tồn tại, xuất số 0.

### Ví dụ:

```
Input:  a = [5, 9, 2, 2, 4, 1, 6, 7]
Index:      1  2  3  4  5  6  7  8
Output:     0  1  0  0  4  0  6  7
```

### Nhận xét:

- Nếu có một số ở sau mà còn nhỏ hơn số đằng trước, thì số đằng trước "không còn quan trọng"
- Ta có thể bỏ qua các phần tử không còn là ứng viên tiềm năng
- **Stack**: lưu giá trị của các ứng viên tiềm năng

---

## 4. Advertisement (Biển Quảng Cáo)

### Đề bài:

Bạn được cho một hàng rào gồm N cái cọc. Cọc thứ i có chiều cao là `h[i]`.

Bạn muốn cắt ra một biển quảng cáo hình chữ nhật sao cho:

- Biển nằm hoàn toàn trong phạm vi các cọc liên tiếp
- Chiều cao của biển không vượt quá chiều cao thấp nhất trong đoạn được chọn
- Biển nằm dựa trên mặt đất, hai cạnh dọc dựa trên cọc

### Yêu cầu:

Tính diện tích lớn nhất của một biển quảng cáo hình chữ nhật có thể cắt được.

### Thuật toán:

1. Xây dựng 2 mảng `L` và `R` sử dụng **Nearest Smaller Value**
2. Tính diện tích: `area = h[i] * (R[i] - L[i] - 1)`

---

## 5. SPC6 (Spring Contest 2020) - Phân Tử Khối

### Đề bài:

Cho một công thức phân tử hóa học hữu cơ chỉ gồm 3 nguyên tố:

- **C** (Carbon)
- **H** (Hydrogen)
- **O** (Oxygen)

Hãy tính **phân tử khối** (molecular mass) của phân tử này.

### Ví dụ:

```
C6H12O6 → 180
```

### Thuật toán sử dụng Stack:

1. Gặp `C`, `H`, `O`, `(`: đẩy vào stack
2. Gặp số: nhân với `stack.top()`
3. Gặp `)`: cộng tổng đến khi gặp `(`
4. Kết thúc: tính tổng các phần tử còn lại trong stack
