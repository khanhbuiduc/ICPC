# Thuật toán Greedy (Tham lam)

Greedy là một chiến lược thiết kế thuật toán để giải quyết các bài toán tối ưu hóa. Ý tưởng chính là ở mỗi bước, ta chọn lựa chọn "tốt nhất" tại thời điểm đó (local optimal) với hy vọng sẽ dẫn đến lời giải tối ưu toàn cục (global optimal).

---

## 1. AC6 (Autumn Contest 2019) - Chia kẹo

### Bài toán:

- Có **N** viên kẹo, viên thứ i có màu `c[i]` và độ ngon `d[i]`
- Chia cho **K** đứa trẻ, mỗi đứa nhận đúng 2 viên
- Điều kiện: Mỗi đứa trẻ chỉ vui nếu 2 viên kẹo có màu **khác nhau**
- **Hỏi:** Có thể chia được 2×K viên kẹo không? Nếu có, tổng độ ngon lớn nhất là bao nhiêu?

### Ví dụ:

```
n=8, k=3
Viên kẹo: (màu, độ ngon)
1 21
2 17
5 15
3 10
1 6
2 3
1 3
1 1
```

### Phân chia tối ưu:

- **Đứa 1:** `<1, 21>`, `<2, 17>` → Tổng: 38
- **Đứa 2:** `<5, 15>`, `<3, 10>` → Tổng: 25
- **Đứa 3:** `<1, 6>`, `<2, 3>` → Tổng: 9

### Nhận xét và thuật toán:

- **Điều kiện cần:** Để chia được 2×K viên, số lượng kẹo mỗi màu ≤ K
- **Greedy:** Sắp xếp kẹo theo độ ngon giảm dần, ưu tiên ghép những viên ngon nhất có màu khác nhau
- **Cài đặt:**
  - Đếm `count[c]` = số lượng kẹo màu c
  - Kiểm tra điều kiện: `max(count[c]) ≤ K`
  - Sắp xếp và ghép cặp tham lam

---

## 2. Friends and Restaurant

### Bài toán:

Có N người, người thứ i có `x[i]` (số tiền cần chi) và `y[i]` (số tiền có). Hỏi có bao nhiêu nhóm thỏa mãn điều kiện: tổng tiền có của nhóm ≥ tổng tiền cần chi của nhóm?

### Ví dụ:

```
N = 6
x: 8 3 9 2 4 5   (tiền cần chi)
y: 5 3 1 4 5 10  (tiền có)
```

### Phân tích:

- Điều kiện nhóm: `(x[i] + x[j] + ...) ≤ (y[i] + y[j] + ...)`
- Biến đổi: `(y[i] - x[i]) + (y[j] - x[j]) + ... ≥ 0`
- Đặt `b[i] = y[i] - x[i]` (lợi nhuận của người i)

### Thuật toán Greedy:

```
b: -3, 0, -8, 2, 1, 5
Sắp xếp: -8, -3, 0, 1, 2, 5
```

**Nhận xét:** Một nhóm chỉ cần tối đa 2 người vì nếu nhóm 3 người có thể loại người với `b[i]` nhỏ nhất mà kết quả không đổi.

**Two Pointers:**

```cpp
l = 1, r = n, group = 0;
while(l < r) {
    if(b[r] + b[l] >= 0) {
        group++;
        l++; r--;
    } else {
        l++;
    }
}
```

---

## 3. Shortest Subsequence

### Bài toán:

Cho chuỗi DNA gồm các ký tự A, C, G, T. Tìm chuỗi ngắn nhất **KHÔNG** phải là subsequence của chuỗi đầu vào.

### Ví dụ:

```
Input: ACGTACGT
Output: Chuỗi ngắn nhất không phải subsequence
```

### Phân tích và thuật toán:

**Nhận xét:** Với chuỗi `ACGTACGT`, ký tự đầu tiên nên là T vì nó loại được nhiều từ nhất.

**Cách lưu trữ vị trí:**

```
A: [1, 5]
C: [2, 6]
G: [3, 7]
T: [4, 8]
```

**Thuật toán Greedy:**

```cpp
string ans = "";
while(A, C, G, T đều không rỗng) {
    // Tìm max của first element trong mỗi deque
    int maxPos = max({A.front(), C.front(), G.front(), T.front()});

    // Thêm ký tự tương ứng với maxPos vào ans
    if(maxPos == T.front()) ans += 'T';
    else if(maxPos == G.front()) ans += 'G';
    else if(maxPos == C.front()) ans += 'C';
    else ans += 'A';

    // Remove các phần tử <= maxPos từ đầu mỗi deque
    while(!A.empty() && A.front() <= maxPos) A.pop_front();
    while(!C.empty() && C.front() <= maxPos) C.pop_front();
    while(!G.empty() && G.front() <= maxPos) G.pop_front();
    while(!T.empty() && T.front() <= maxPos) T.pop_front();
}

// Thêm ký tự từ deque rỗng đầu tiên
if(A.empty()) ans += 'A';
else if(C.empty()) ans += 'C';
else if(G.empty()) ans += 'G';
else if(T.empty()) ans += 'T';
```

**Cấu trúc dữ liệu:** Sử dụng `deque` (vào trước ra trước) để lưu trữ các vị trí.

---

## Tóm tắt nguyên lý Greedy

1. **Xác định lựa chọn tham lam:** Tại mỗi bước, chọn lựa chọn tốt nhất hiện tại
2. **Chứng minh tính đúng đắn:** Lựa chọn tham lam dẫn đến lời giải tối ưu
3. **Cài đặt hiệu quả:** Thường kết hợp với sắp xếp, two pointers, hoặc cấu trúc dữ liệu phù hợp
