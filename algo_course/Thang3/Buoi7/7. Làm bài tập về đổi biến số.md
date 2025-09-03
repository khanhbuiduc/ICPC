# Làm bài tập về đổi biến số

Tài liệu này trình bày các bài tập thực hành về kỹ thuật đổi biến số trong quy hoạch động.

---

## Bài toán 1: Spring Contest 2020 (SPC1)

**Mô tả:** Cho 2 dãy số a và b, dãy a gồm N số nguyên dương, dãy b gồm M số nguyên dương.

**Yêu cầu:** Tìm dãy c là dãy con chung có độ dài lớn nhất của 2 dãy a và b.

**Giới hạn:** 1 ≤ N ≤ 2,000,000, 1 ≤ M ≤ 2,000

**Ví dụ:**
```plaintext
a = [5, 2, 4, 2, 6, 1, 2, 4, 6, 5, 3, 2, 1, 3, 4, 2]
b = [1, 4, 3, 5, 6, 8]
```

### Phân tích và đổi biến

**Vấn đề:** N rất lớn (2 triệu), không thể dùng f[i][j] truyền thống O(N×M).

**Kỹ thuật đổi biến:** Thay vì lưu vị trí trong dãy a, ta lưu chỉ số tối thiểu cần thiết.

```plaintext
Trạng thái: f[i][j] = chỉ số tối thiểu cần thiết trong dãy a khi xét i phần tử 
           đầu tiên của dãy b và có độ dài dãy con chung là j

Bài toán cơ sở: f[0][0] = 0, các f[i][j] khác = ∞

Đáp án: j lớn nhất sao cho f[M][j] ≤ N

Công thức truy hồi:
  Nếu f[i][j] ≠ ∞, xét b[i+1]:
  
  1. Không xét b[i+1] vào dãy con chung:
     f[i+1][j] = min(f[i+1][j], f[i][j])
     
  2. Xét b[i+1] vào dãy con chung:
     Tìm p > f[i][j] sao cho a[p] = b[i+1] (dùng upper_bound)
     f[i+1][j+1] = min(f[i+1][j+1], p)

Cải tiến: Dùng map<int, vector<int>> để lưu vị trí của mỗi giá trị trong a.

Độ phức tạp: O(M² × log N)
```

---

## Bài toán 2: AC6 (Autumn Contest 2020)

**Mô tả:** Có một nền gạch gồm N ô, trong đó có M ô bị hỏng.

**3 loại gạch:**
- **Loại 1:** Giới hạn K viên, mỗi viên che 1 ô bình thường, độ đẹp G1
- **Loại 2:** Không giới hạn, mỗi viên che 2 ô bình thường liên tục, độ đẹp G2  
- **Loại 3:** Không giới hạn, mỗi viên che 3 ô theo thứ tự: bình thường - hỏng - bình thường, độ đẹp G3

**Ràng buộc:** 
- Không viên nào thừa ra ngoài
- Mỗi ô hỏng không được che có độ xấu U

**Yêu cầu:** Tối đa hóa tổng độ đẹp.

```plaintext
Trạng thái: f[i][k] = tổng độ đẹp lớn nhất khi xét i ô đầu tiên 
           và đã sử dụng k viên gạch loại 1

Bài toán cơ sở: f[0][0] = 0, các f[i][k] khác = -∞

Đáp án: max(f[N][k]) với k từ 0 đến K

Công thức truy hồi:
  Xét ô thứ i+1:
  
  1. Không lát ô i+1:
     - Nếu ô i+1 bình thường: f[i+1][k] = max(f[i+1][k], f[i][k])
     - Nếu ô i+1 hỏng: f[i+1][k] = max(f[i+1][k], f[i][k] - U)
     
  2. Dùng gạch loại 1 (nếu k < K và ô i+1 bình thường):
     f[i+1][k+1] = max(f[i+1][k+1], f[i][k] + G1)
     
  3. Dùng gạch loại 2 (nếu ô i+1, i+2 đều bình thường):
     f[i+2][k] = max(f[i+2][k], f[i][k] + G2)
     
  4. Dùng gạch loại 3 (nếu ô i+1 bình thường, i+2 hỏng, i+3 bình thường):
     f[i+3][k] = max(f[i+3][k], f[i][k] + G3)

Độ phức tạp: O(N × K)
```

---

**Kết luận:** Các bài tập về đổi biến số thường có đặc điểm:

1. **Một chiều có ràng buộc lớn** → Đổi sang chiều có giá trị nhỏ hơn
2. **Cần tối ưu hóa** cấu trúc dữ liệu (map, binary search) để giảm độ phức tạp
3. **Phân tích kỹ ràng buộc** để tìm hướng đổi biến phù hợp
4. **Kết hợp nhiều kỹ thuật** như đổi biến + binary search + cấu trúc dữ liệu

Kỹ thuật đổi biến giúp giải quyết các bài toán có ràng buộc lớn một cách hiệu quả, biến bài toán không khả thi thành khả thi.

