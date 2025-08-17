# CHASE - Bài toán truy đuổi với Priority Queue

## Đề bài:

Một xe buôn lậu xuất phát ở km **s** trên quốc lộ, xe đồn biên phòng xuất phát ở km **0** để truy đuổi.

- Xe buôn lậu có tốc độ **v₁**, xe truy đuổi có tốc độ **v₂**
- Xe buôn lậu mang theo **k** thùng dầu
- Trên đường có **n** điểm (tọa độ **xᵢ**), tại mỗi điểm nếu đổ dầu sẽ làm xe truy đuổi mất thêm **aᵢ** giây để vượt qua
- Mỗi lần đổ phải dùng trọn một thùng dầu
- Xe buôn lậu chỉ có thể đổ dầu ở những điểm nằm sau vị trí xuất phát s

**Yêu cầu:**

- Xác định thời gian tối đa bọn buôn lậu có thể trì hoãn trước khi bị bắt
- Thời điểm bị bắt tính là khi hai xe ở cùng một vị trí (kể cả nếu xe buôn lậu đang đứng lại để đổ dầu)
- Nếu xe truy đuổi không thể bắt kịp thì in ra "inf"

Trong đó:

- (1 ≤ n ≤ 100000)
- (1 ≤ k ≤ 100000)
- (1 ≤ v1 ≤ 1000)
- (1 ≤ v2 ≤ 1000)
- (0 ≤ s ≤ 10^9)
- (0 ≤ x[i] ≤ 10^9)
- (1 ≤ a[i] ≤ 1000)

## Solution:

**Ý tưởng:** Greedy + Priority Queue + Simulation

**Các bước:**

1. **Case đặc biệt:**

   - `s = 0`: return "0"
   - `v1 >= v2`: return "inf"

2. **Thuật toán chính:**

   ```
   // Tìm điểm đầu tiên >= s (xe buôn lậu có thể đổ dầu)
   m = 0;
   for i in [0, n):
       if x[i] >= s: m = i; break;

   while (còn dầu k > 0):
       - Thu thập dầu từ các điểm mà xe truy đuổi đến trước
       - Điều kiện: (x[i] - s)/v1 >= (x[i] + d)/v2
       - Chọn thùng dầu có a[i] lớn nhất (priority_queue)
       - Cập nhật: d += a[i] * v2
   ```

3. **Kết quả:** `ans = (s + d) / (v2 - v1)`

**Giải thích:**

- `d`: khoảng cách gia tăng do sử dụng dầu
- Công thức cuối: thời gian để xe truy đuổi bắt kịp từ vị trí `s + d`

**CTDL:** Priority Queue (max heap)
**Độ phức tạp:** O(n log n)
