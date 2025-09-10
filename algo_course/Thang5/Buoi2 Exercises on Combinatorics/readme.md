# Bài 2: Tổ Hợp Nâng Cao

## Bài toán: Distributing Apples

### Đề bài

Cho N quả táo và có M bạn nhỏ. Hãy đếm số cách chia N quả táo cho M bạn nhỏ (cho phép một vài bạn không có táo, nhưng táo không được phép thừa).

### Ví dụ

N = 3, M = 2

```
[0, 3]
[1, 2]
[2, 1]
[3, 0]
```

**Kết quả:** 4 cách

## Bài toán chia kẹo Euler

### Đề bài

Có N viên kẹo và có M đứa nhỏ, hỏi có bao nhiêu cách để chia toàn bộ N viên cho M đứa nhỏ sao cho mỗi đứa phải có kẹo.

### Ví dụ

N = 4, M = 3

```
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
```

**Kết quả:** 3 cách

### Mô hình hóa

```
o | o | o | o o o
```

Bài toán đưa về: Cho n viên kẹo, đếm có bao nhiêu cách đặt m - 1 vách ngăn vào n - 1 khe.

**Số cách chia:** C(m - 1, n - 1)

### Chuyển đổi bài toán thành bài toán Euler

**Bài toán gốc:** N quả táo, M bạn. Đếm số cách chia N quả táo cho M bạn (1 số bạn có thể không có táo, táo được chia hết)

**Chuyển đổi:**

- N quả táo → N + M quả táo
- 1 số bạn có thể không có táo → ít nhất mỗi bạn 1 quả táo

**Công thức:** C(M - 1, N + M - 1)

## Bài toán Zerone

### Đề bài

Đếm có bao nhiêu chuỗi s chỉ gồm ký tự 0 và ký tự 1 sao cho:

- Tổng số lượng ký tự 0 không vượt quá a₀
- Tổng số lượng ký tự 1 không vượt quá a₁

Nếu ta tách chuỗi s thành các chuỗi 0 và 1 liên tục nhau thì:

- Số lượng chữ số 0 của mỗi đoạn phải ≥ b₀
- Số lượng chữ số 1 ở mỗi đoạn phải ≥ b₁

### Ví dụ

a₀ = 6, a₁ = 4, b₀ = 2, b₁ = 3

```
[00], [111], [000]
```

Chuỗi: `001110001` - không thỏa mãn

```
[00], [111], [000], [1]
```

**Nhận xét:** Nếu có k nhóm 0 thì có k-1, k, hoặc k+1 nhóm 1

### Phân tích toán học

Cho:

- a₀ = 25, b₀ = 2
- a₁ = 30, b₁ = 2

Điều kiện:

- x₀[i] ≥ b₀
- Tổng các x₀[i] ≤ a₀
- x₁[i] ≥ b₁
- Tổng các x₁[i] ≤ a₁

Đặt u₀[i] = x₀[i] - b₀ ⟹ u₀[i] ≥ 0

```
x₀[1] + x₀[2] + ... + x₀[k] ≤ a₀
⟺ (x₀[1] - b₀) + (x₀[2] - b₀) + ... + (x₀[k] - b₀) ≤ a₀ - b₀ × k
⟺ u₀[1] + u₀[2] + ... + u₀[k] ≤ a₀ - b₀ × k
```

Tương tự:

```
u₁[1] + u₁[2] + ... + u₁[k] ≤ a₁ - b₁ × k
```

Bài toán trở thành: Chia a₁ - b₁ × k cái kẹo cho k bạn, mỗi bạn có ít nhất 0 cái kẹo.

## Nghịch đảo Modulo

### Định lý Fermat nhỏ

```
a^(M-1) % M = 1
⟹ (1/a) % M đồng dư với a^(M-2) % M
```

### Công thức tính

```
(a / b) % M = (a × 1/b) % M = (a × b^(M-2)) % M
```

### Ứng dụng trong tổ hợp

Đếm số cách tạo ra bộ số x gồm N số sao cho tổng x[1] + x[2] + ... + x[N] = M  
**Công thức:** C(M + N - 1, N - 1)

```
C(N, k) = N! / ((N-k)! × k!)
```

**Cài đặt:**

```cpp
fact[i] = i! % M
inv_fact[i] = 1/fact[i] = fact[i]^(M-2) % M
C(N, k) = fact[N] × inv_fact[N-k] × inv_fact[k]
```

## Bài toán Trồng Cây

### Đề bài

Có mảnh đất N×N, trồng cây sao cho mỗi hàng, cột đều có cây. Tồn tại đường đi từ (1,1) tới (N,N).

**Ràng buộc:**

- N < 10⁷
- T < 10⁴

### Phân tích

**S1:** Số cách đặt cây sao cho mỗi hàng 1 cây, cột 1 cây = N!

**S2:** Số cách đặt chặn 1 đường chéo

```
S2 = 2 × (N - i)! + 1 với i: 1 → N - 1
```

**S3:** Số cách đặt 1 đường chéo có độ dài i và 1 đường chéo có độ dài j

```
S3 = (N - i - j)! với i + j < N
```

**Kết quả:** `ans = S1 - S2 + S3`

### Tối ưu hóa

#### Tính N!

Tạo mảng `fact[i]` với i: 1 → 10⁷ để tính nhanh

#### Tính tổng (N - i)! với i: 1 → N - 1

```cpp
// Tạo bảng sumFact[i] với i: 0 → 10⁷
S2 = 2 × (sumFact[N-1] - 1) + 1
```

#### Tính tổng (N - i - j)! với i + j < N

```cpp
for i: 0 → N-1:
    S3 += sumFact[N-1]

// Tạo bảng sum2fact[i] với i: 0 → 10⁷
S3 = sum2fact[N - 2]
```
