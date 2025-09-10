# Bài 4: Xác Suất

## Khái niệm cơ bản về xác suất

### Ví dụ: Vé số

Có 1 triệu tờ vé số, có 4 giải:

- **Đặc biệt:** 2 tờ
- **Nhất:** 1000 tờ
- **Nhì:** 2000 tờ
- **Ba:** 5000 tờ

**Tính toán:**

- Tỉ lệ trúng đặc biệt: 2/1,000,000
- Tỉ lệ trúng giải: (2 + 1000 + 2000 + 5000)/1,000,000 = 8002/1,000,000
- Ký hiệu: p
- Không gian mẫu: 1,000,000

---

## Quy tắc xác suất

### Quy tắc cộng

Có k phương án:

- Phương án i có xác suất thành công là pᵢ với i: 1→k
- **Xác suất hoàn thành công việc:** p₁ + p₂ + ... + pₖ

### Quy tắc nhân

Có k giai đoạn:

- Giai đoạn i có xác suất thành công là pᵢ với i: 1→k
- **Xác suất hoàn thành công việc:** p₁ × p₂ × p₃ × ... × pₖ

### Bài tập áp dụng

**Đề bài:** Xác suất mua 3 tờ vé số để ít nhất 1 tờ trúng giải

**Phương pháp:** 1 - P(cả 3 tờ đều không trúng)
= 1 - C(3, không trúng)/C(3, 1,000,000)

**Giải chi tiết:**

- Tình huống 1: 1 tờ có giải
  - p₁ = 8002 × C(2, 991998) / C(3, 1,000,000)
- Tình huống 2: 2 tờ có giải
  - p₂ = C(2, 8002) × 991998 / C(3, 1,000,000)
- Tình huống 3: 3 tờ có giải
  - p₃ = C(3, 8002) / C(3, 1,000,000)

## Bài toán: Coins

### Đề bài

Cho N đồng xu. Đồng xu thứ i có xác suất xuất hiện mặt ngửa là p[i] (0.0 < p[i] < 1.0).

Tung toàn bộ N đồng xu, hãy tính xác suất để số lượng đồng xu xuất hiện mặt ngửa nhiều hơn số lượng đồng xu xuất hiện mặt úp.

### Ví dụ

N = 3, p = [0.2, 0.3, 0.5]

**Tình huống 1:** N N N: 0.2 × 0.3 × 0.5 = 0.03
**Tình huống 2:** N N U: 0.2 × 0.3 × (1 - 0.5) = 0.03
**Tình huống 3:** N U N: 0.2 × (1 - 0.3) × 0.5 = 0.07
**Tình huống 4:** U N N: (1 - 0.2) × 0.3 × 0.5 = 0.12

**Kết quả:** 0.25

### Thuật toán

Gọi f[i][j] là xác suất khi ta có i đồng xu đầu tiên và có j đồng xu nằm mặt ngửa.

**Bài toán cơ sở:** f[0][0] = 1

**Đáp án:** Tổng f[N][j] (với j > N - j)

**Công thức QHD:**
Khi ta có f[i][j] > 0:

- **Tình huống 1:** Đồng xu thứ i + 1 nằm ngửa
  ```
  f[i + 1][j + 1] += f[i][j] × p[i + 1]
  ```
- **Tình huống 2:** Đồng xu thứ i + 1 nằm úp
  ```
  f[i + 1][j] += f[i][j] × (1 - p[i + 1])
  ```

## Bài toán: Bad Luck Island

### Đề bài

Trên 1 vùng đảo, có R con búa, S con kéo và P con bao. Cứ mỗi ngày, sẽ có 2 con khác loại gặp nhau và chúng sẽ tiêu diệt nhau theo quy luật:

- Búa → Kéo
- Kéo → Bao
- Bao → Búa

Một loại sẽ được gọi là thống trị nếu toàn bộ số sinh vật của 2 loại còn lại đã không còn.

Xác định xác suất để búa thống trị, kéo thống trị và bao thống trị.

### Ví dụ

R = 1, S = 1, P = 2

**Kịch bản 1:**

- Ngày 1: R - S: R thắng, xác suất 1/5
- Ngày 2: R - P: P thắng, xác suất 1
- Xác suất để bao thắng: 1/5 × 1 = 0.2

**Kịch bản 2:** Kéo thắng, 0.2

- Ngày 1: R - P: P thắng, xác suất 1/5
- Ngày 2: S - P: S thắng, xác suất 1
- Ngày 3: S - P: S thắng, xác suất 1

### Thuật toán

Gọi f[r][s][p]: xác suất để đạt trạng thái khi có r búa còn sống, s kéo còn sống và p bao còn sống.

**Bài toán cơ sở:** f[R][S][P] = 1.0

**Đáp án bài toán:**

- Xác suất để búa còn sống: Tổng các f[r][0][0]
- Tính tương tự với kéo và bao

**Công thức QHĐ:**
Khi ta có f[r][s][p]

Giả sử búa mất 1 con ⟹ búa bị tiêu diệt bởi bao

Xác suất để 1 con búa gặp 1 con bao: `r × p / (r × s + s × p + p × r)`

```cpp
f[r-1][s][p] += f[r][s][p] × (r×p / (r×s + s×p + p×r))
```

## Bài toán: Random Events

### Đề bài

Cho một dãy số a là một hoán vị của N số tự nhiên đầu tiên.

Ta có M sự kiện, trong đó sự kiện thứ i gồm 2 số (rᵢ, pᵢ) với ý nghĩa: Ta sắp xếp tất cả các phần tử từ vị trí 1 đến vị trí rᵢ trong dãy a thành các phần tử tăng dần.

Xác suất để sự kiện này xảy ra là pᵢ.

Hỏi nếu các sự kiện xảy ra một cách ngẫu nhiên, hỏi xác suất để dãy a là dãy tăng dần là bao nhiêu?

### Ví dụ

```
N = 8, M = 4
a = [5, 1, 3, 2, 4, 6, 7, 8]

Sự kiện 1: r = 3, p = 0.7
Sự kiện 2: r = 7, p = 0.2
Sự kiện 3: r = 1, p = 1.0
Sự kiện 4: r = 5, p = 0.5
```

**Phân tích:**

- SK1 không xảy ra: 0.3
- SK2 không xảy ra: 0.8
- SK3 có xảy ra: 1.0
- SK4 có xảy ra: 0.5

**Kết quả:** 0.3 × 0.8 × 1.0 × 0.5 = 0.12

### Thuật toán

Ta tìm được một vị trí p nhỏ nhất sao cho nếu sắp xếp các phần tử a[1], a[2], ..., a[p] mà được dãy tăng dần.

⟹ Những cách sắp xếp [1..p-1], [1..p-2], [1..1] cũng sẽ không làm dãy tăng dần.

**Công thức:**
Xác suất để các sự kiện j₁, j₂, ..., jₖ không xảy ra:

```
(1 - pⱼ₁) × (1 - pⱼ₂) × ... × (1 - pⱼₖ)
```

## Bài toán: Andrei And Problem

### Đề bài

Cho một dãy số p với p[i] là một giá trị xác suất với ý nghĩa: p[i] là xác suất để sự kiện i có xuất hiện.

Ta cần chọn một vài giá trị trong dãy p và hãy tính xác suất mà duy nhất một phần tử xuất hiện.

Hỏi xác suất lớn nhất là bao nhiêu?

### Ví dụ

```
4
0.1 0.2 0.3 0.8
```

Chọn 0.2 và 0.8 (chọn vật 2 và 4)

- **Kịch bản 1:** vật 2 xuất hiện: 0.2 × 0.2 = 0.04
- **Kịch bản 2:** vật 4 xuất hiện: 0.8 × 0.8 = 0.64

**Xác suất để duy nhất 1 vật xuất hiện:** 0.68

### Phân tích toán học

Giả sử tập hợp các vật chúng ta chọn là i₁, i₂, ..., iₖ

**Xác suất để 1 vật xuất hiện:**

```
P = p[i₁] × (1 - p[i₂]) × (1 - p[i₃]) × ... × (1 - p[iₖ]) +
    (1 - p[i₁]) × p[i₂] × (1 - p[i₃]) × ... × (1 - p[iₖ]) +
    ...
    (1 - p[i₁]) × (1 - p[i₂]) × ... × p[iₖ]
```

Đặt M = (1 - p[i₁]) × (1 - p[i₂]) × ... × (1 - p[iₖ])

⟹ P = M × (p[i₁]/(1 - p[i₁]) + p[i₂]/(1 - p[i₂]) + ... + p[iₖ]/(1 - p[iₖ]))

### Thuật toán

**So sánh hai lựa chọn:**

```
Pₓ = M × (tổng + p[x]/(1-p[x]))
Pᵧ = M × (tổng + p[y]/(1-p[y]))
```

Giả sử sau khi thêm x, xác suất sẽ lớn hơn sau khi thêm y:

```
Pₓ > Pᵧ
⟺ p[x]/(1-p[x]) > p[y]/(1-p[y])
⟺ p[x] > p[y]
```

**Kết luận:** Khi có 2 lựa chọn, luôn chọn xác suất lớn hơn.

**Algorithm:**

1. Sắp xếp dãy p theo thứ tự giảm dần
2. Thử từng prefix của dãy đã sắp xếp
3. Tính xác suất cho mỗi prefix và chọn giá trị lớn nhất
