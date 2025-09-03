# Đổi biến số trong quy hoạch động

Tài liệu này tập trung vào kỹ thuật đổi biến trong QHĐ để giải quyết các bài toán có ràng buộc lớn bằng cách thay đổi không gian trạng thái.

---

## Bài toán 1: Knapsack 2

**Mô tả:** Bài toán túi xách với ràng buộc lớn về trọng lượng.

**Ví dụ:**
```plaintext
N = 5, W = 10^9 (rất lớn)
(value, weight):
(3, 6), (10, 8), (3, 2), (2, 1), (2, 1)

Nhận xét: W rất lớn (≤ 10^9), nhưng v[i] ≤ 1000
=> Tổng value ≤ N × 1000 = 100,000
```

### Kỹ thuật đổi biến

**Thay vì:** f[i][w] = value tối đa với trọng lượng w  
**Ta dùng:** f[i][v] = trọng lượng tối thiểu để đạt value v

```plaintext
Trạng thái: f[i][j] = tổng trọng lượng nhỏ nhất khi xét i đồ vật đầu tiên 
           và tổng giá trị là j

Bài toán cơ sở: f[0][0] = 0, các f[i][j] khác = ∞

Đáp án: j lớn nhất sao cho f[n][j] ≤ W

Công thức truy hồi:
  Nếu f[i][j] ≠ ∞, xét đồ vật thứ i+1:
  
  1. Không thêm vào túi:
     f[i+1][j] = min(f[i+1][j], f[i][j])
     
  2. Thêm vào túi (nếu f[i][j] + w[i+1] ≤ W):
     f[i+1][j + v[i+1]] = min(f[i+1][j + v[i+1]], f[i][j] + w[i+1])

Độ phức tạp: O(N × Σv[i]) thay vì O(N × W)
```

---

## Bài toán 2: Longest Increasing Subsequence (Tối ưu)

**Mô tả:** Tìm dãy con tăng dài nhất với độ phức tạp O(N log N).

**Bản thường:** O(N²) với f[i] = độ dài LIS kết thúc tại i  
**Bản tối ưu:** O(N log N) với đổi biến

### Kỹ thuật đổi biến tối ưu

**Thay vì:** f[i] = độ dài LIS kết thúc tại vị trí i  
**Ta dùng:** f[len] = chỉ số của phần tử nhỏ nhất trong tất cả LIS có độ dài len

```plaintext
Ví dụ: a = [5, 1, 9, 2, 4, 3, 6, 7, 8, 10, 2, 12]

i = 5 (phần tử 4):
  f[1] = 2 (phần tử a[2] = 1)
  f[2] = 4 (phần tử a[4] = 2)  
  f[3] = 5 (phần tử a[5] = 4)

i = 6 (phần tử 3):
  f[1] = 2, f[2] = 4, f[3] = 6 (a[6] = 3 < a[5] = 4)

Trạng thái: f[len] = chỉ số phần tử nhỏ nhất có độ dài LIS = len
           maxlength = độ dài LIS lớn nhất hiện tại

Bài toán cơ sở: 
  - Thêm a[0] = 0 vào đầu dãy
  - f[0] = 0, maxlength = 0

Đáp án: maxlength

Công thức truy hồi:
  Xét phần tử a[i+1]:
  
  1. Nếu a[f[maxlength]] < a[i+1] (tăng độ dài):
     maxlength++
     f[maxlength] = i+1
     
  2. Ngược lại (không tăng độ dài):
     Tìm len lớn nhất sao cho a[f[len]] < a[i+1] (dùng binary search)
     f[len+1] = i+1

Độ phức tạp: O(N log N)
```

---

## Bài toán 3: SC1 (Summer Contest 2022)

**Mô tả:** Bài toán đổi tiền phức tạp.

Ta có a[1] tờ mệnh giá 1000, a[2] tờ mệnh giá 2000, ..., a[9] tờ mệnh giá 500000.  
Tiệm trà sữa có b[1] tờ 1000, b[2] tờ 2000, ..., b[9] tờ 500000.  
Cần mua trà sữa giá C đồng.

**Mục tiêu:** 
- Ta muốn có ít tờ tiền nhất
- Tiệm muốn có nhiều tờ tiền nhất, nhưng ưu tiên thối ít tờ nhất

### Kỹ thuật đổi biến và QHĐ kép

```plaintext
Đổi biến: Chia tất cả cho 1000, xem như có các mệnh giá 1, 2, 5, 10, ...

Bước 1: Tính số tờ tối đa người mua có thể đưa
Trạng thái: f_max[i][j] = số tờ tối đa khi xét i mệnh giá đầu và tổng tiền j

Bài toán cơ sở: f_max[0][0] = 0, các f_max[i][j] khác = -1

Công thức: 
  Nếu f_max[i][j] ≠ -1, xét mệnh giá i+1:
  Sử dụng x tờ (x từ 0 đến a[i+1]):
    f_max[i+1][j + x×c[i+1]] = max(f_max[i+1][j + x×c[i+1]], f_max[i][j] + x)

Bước 2: Tính số tờ tối thiểu tiệm cần thối
Trạng thái: f_min[i][j] = số tờ tối thiểu khi xét i mệnh giá đầu và tổng tiền j

Bài toán cơ sở: f_min[0][0] = 0, các f_min[i][j] khác = ∞

Công thức tương tự f_max nhưng dùng min thay vì max

Bước 3: Tính kết quả
  Duyệt tất cả X có thể (số tiền người mua đưa):
  Nếu f_max[9][X] ≠ -1 và f_min[9][X-C] ≠ ∞:
    Kết quả = min(tổng tờ ban đầu - f_max[9][X] - f_min[9][X-C])
```
---

## Bài toán 4: SPC4 (Spring Contest 2022)

**Mô tả:** Bún và Đậu là 2 thợ cắt tóc. Có N vị khách, thời gian để Bún phục vụ vị khách thứ i là b[i], thời gian để Đậu phục vụ vị khách thứ i là d[i].

Ta sẽ để một vài vị khách cho Bún phục vụ, những vị khách còn lại sẽ cho Đậu phục vụ.

Thời gian tiệm cắt tóc đóng cửa sẽ là thời gian mà Bún và Đậu kết thúc.

**Yêu cầu:** Thời gian tiệm cắt tóc đóng cửa sớm nhất là bao nhiêu?

### Kỹ thuật cố định một biến

**Nhận xét:** 
- 1 ≤ N ≤ 100, 1 ≤ b[i], d[i] ≤ 100
- Thời gian 1 người phục vụ lớn nhất là 10⁴

**Ý tưởng:** Cố định thời gian Bún phục vụ là t, tính f(t) = thời gian tối thiểu để Đậu phục vụ những vị khách còn lại.

**Kết quả:** min(max(t, f(t))) với mọi t.

```plaintext
Trạng thái: f[i][t] = tổng thời gian Đậu phục vụ ít nhất khi có i vị khách đầu tiên
           và thời gian Bún phục vụ là t

Bài toán cơ sở: f[0][0] = 0, các f[i][j] khác = ∞

Đáp án: min(max(t, f[n][t])) với t từ 0 đến 10⁴

Công thức truy hồi:
  Nếu f[i][t] ≠ ∞, xét khách i+1:
  
  1. Bún phục vụ:
     f[i+1][t + b[i+1]] = min(f[i+1][t + b[i+1]], f[i][t])
     
  2. Đậu phục vụ:
     f[i+1][t] = min(f[i+1][t], f[i][t] + d[i+1])

Độ phức tạp: O(N × T_max) với T_max = 10⁴
```

---

**Kết luận:** Kỹ thuật đổi biến trong QHĐ bao gồm:

1. **Đổi không gian trạng thái:** Từ f[weight] sang f[value] (Knapsack 2)
2. **Đổi ý nghĩa trạng thái:** Từ f[position] sang f[length] (LIS tối ưu)
3. **QHĐ kép:** Tính cả max và min (Bài đổi tiền)
4. **Cố định biến:** Duyệt một chiều, QHĐ chiều kia (Bài cắt tóc)
5. **Phân tích ràng buộc:** Tìm chiều có giá trị nhỏ để tối ưu

Những kỹ thuật này giúp giải quyết các bài toán có ràng buộc lớn một cách hiệu quả.
