### **Stack - Cấu trúc LIFO (Last In First Out)**

**Các hàm cơ bản:**

- `push()` - Thêm phần tử vào đỉnh stack
- `top()` - Lấy phần tử ở đỉnh (⚠️ Lỗi khi stack rỗng)
- `pop()` - Xóa phần tử ở đỉnh
- `empty()` - Kiểm tra stack có rỗng
- `size()` - Lấy kích thước stack

---

## 🔢 BÀI TOÁN 1: BIỂU THỨC BA LAN NGƯỢC (ONP)

### **Khái niệm:**

- **Biểu thức trung tố:** `(a o b)`
- **Biểu thức hậu tố (Polish Notation):** `a b o`

### **Ví dụ chuyển đổi:**

```
(1 + 2) * (3 + 4) → 1 2 + 3 4 + *
```

### **Thuật toán tính toán:**

**Input:** `50 75 + 25 10 20 * 30 2 / + + *`

**Các bước:**

1. Duyệt từng phần tử trong biểu thức
2. **Gặp số:** đẩy vào stack
3. **Gặp phép tính:**
   - Lấy 2 số ở đỉnh ra: `b = stack.top(), a = stack.top()`
   - Thực hiện: `a o b`
   - Đẩy kết quả vào stack
4. Kết quả cuối cùng là phần tử duy nhất trong stack

---

## 🔗 BÀI TOÁN 2: VALID PARENTHESES

### **Đề bài:**

Kiểm tra chuỗi ngoặc `(`, `)`, `[`, `]`, `{`, `}` có hợp lệ không.

### **Quy tắc:**

- Chuỗi rỗng là hợp lệ
- Nếu A hợp lệ thì `(A)`, `[A]`, `{A}` hợp lệ
- Nếu A, B hợp lệ thì `AB` hợp lệ

### **Ví dụ:**

- `()()()` ✅ hợp lệ
- `)()()()(` ❌ không hợp lệ

### **Thuật toán:**

- **Stack lưu trữ:** danh sách ngoặc mở chưa đóng
- **Gặp ngoặc mở:** đẩy vào stack
- **Gặp ngoặc đóng:** kiểm tra matching với đỉnh stack

---

## 📊 BÀI TOÁN 3: NEAREST SMALLER VALUE

### **Đề bài:**

Cho dãy số `a[N]`. Với mỗi `a[i]`, tìm vị trí gần nhất bên trái có giá trị `< a[i]`.

### **Ví dụ:**

```
Input:  a = [5, 9, 2, 2, 4, 1, 6, 7]
Index:      1  2  3  4  5  6  7  8
Output:     0  1  0  0  4  0  6  7
```

### **Nhận xét quan trọng:**

- Nếu có số ở sau nhỏ hơn số đằng trước → số đằng trước "không còn quan trọng"
- Ta có thể loại bỏ các phần tử không còn là ứng viên tiềm năng

### **Thuật toán:**

- **Stack lưu trữ:** các ứng viên tiềm năng (tăng dần)
- Duyệt từ trái sang phải, duy trì stack tăng dần

---

## 🏗️ BÀI TOÁN 4: BIỂN QUẢNG CÁO (ADVERTISEMENT)

### **Đề bài:**

Cho hàng rào N cọc với chiều cao `h[i]`. Tìm diện tích lớn nhất của biển quảng cáo hình chữ nhật.

### **Điều kiện:**

- Biển nằm trong phạm vi các cọc liên tiếp
- Chiều cao ≤ chiều cao thấp nhất trong đoạn
- Biển dựa trên mặt đất

### **Thuật toán:**

1. Xây dựng 2 mảng `L[]` và `R[]` bằng **Nearest Smaller Value**
   - `L[i]`: vị trí gần nhất bên trái có `h < h[i]`
   - `R[i]`: vị trí gần nhất bên phải có `h < h[i]`
2. **Diện tích tại vị trí i:** `area = h[i] * (R[i] - L[i] - 1)`
3. Lấy max của tất cả diện tích

---

## 🧪 BÀI TOÁN 5: PHÂN TỬ KHỐI HÓA HỌC (SPC6)

### **Đề bài:**

Tính phân tử khối của công thức hóa học gồm C, H, O và dấu ngoặc.

### **Ví dụ:**

```
C6H12O6 → 180
```

### **Thuật toán:**

1. **Gặp C, H, O, (:** đẩy vào stack
2. **Gặp số:** nhân với `stack.top()`
3. **Gặp ):** cộng tổng các phần tử cho đến khi gặp `(`
4. **Kết thúc:** tính tổng các phần tử còn lại

### **Khối lượng nguyên tử:**

- C (Carbon): 12
- H (Hydrogen): 1
- O (Oxygen): 16

---

## 💡 KINH NGHIỆM VÀ TIPS

### **Khi nào dùng Stack:**

- Xử lý biểu thức có dấu ngoặc
- Tìm phần tử gần nhất thỏa mãn điều kiện
- Duy trì danh sách ứng viên tiềm năng
- Backtracking problems

### **Template cơ bản:**

```cpp
stack<int> st;
for (int i = 0; i < n; i++) {
    // Loại bỏ các phần tử không phù hợp
    while (!st.empty() && condition) {
        st.pop();
    }

    // Xử lý phần tử hiện tại
    // ...

    // Thêm phần tử mới
    st.push(arr[i]);
}
```

### **Lưu ý:**

- ⚠️ Luôn kiểm tra `empty()` trước khi gọi `top()`
- 📊 Stack thường được dùng với độ phức tạp O(n)
- 🔄 Mỗi phần tử chỉ được push/pop tối đa 1 lần
