# Bài 3: Quy Hoạch Động + Tổ Hợp

## Bài toán: Candies

### Đề bài

Có N đứa trẻ và có M viên kẹo. Đứa trẻ thứ i sẽ muốn nhận tối đa a[i] viên kẹo.

Hỏi có bao nhiêu cách chia M viên kẹo cho N đứa trẻ sao cho phải chia hết toàn bộ M viên kẹo và số kẹo mỗi đứa trẻ không quá a[i] viên.

### Ví dụ

```
Input:
3 4
1 2 3

Output: 5
```

**Ràng buộc:**

- 1 ≤ N ≤ 100
- 1 ≤ M ≤ 100,000

### Thuật toán

Gọi f[i][j] là số cách để chia j viên kẹo cho i đứa trẻ đầu tiên.

**Bài toán cơ sở:** f[0][0] = 1

**Quy hoạch động:** Tính f[i][j]

Khi ta chia x viên kẹo cho bạn thứ i (0 ≤ x ≤ a[i], x ≤ j):

```
f[i][j] = f[i-1][j] + f[i-1][j-1] + f[i-1][j-2] + ... + f[i-1][j-min(j,a[i])]
```

**Tối ưu hóa:** Đặt sum[i][j] = tổng f[i][0] + f[i][1] + f[i][2] + ... + f[i][j]

**Khởi tạo:**

```cpp
f[0][0] = 1
sum[0][j] = sum[0][j-1] + f[0][j]
```

**Công thức:**

```cpp
r = j
l = j - min(j, a[i])
f[i][j] = sum[i-1][r] - sum[i-1][l-1]
sum[i][j] = sum[i][j-1] + f[i][j]
```

**Độ phức tạp:** O(N × M)

## Bài toán: Count Bulls

### Đề bài

Có bao nhiêu cách xếp N con bò, mỗi con có thể chọn là đực hoặc cái và thỏa mãn điều kiện: Giữa 2 con đực phải có ít nhất K con cái.

### Ví dụ

N = 5, K = 3

```
CCCCC
DCCCC
CDCCC
CCDCC
CCCDC
CCCCD
DCCCD
```

### Thuật toán

Gọi f[i] là số cách đặt bò khi có i con bò.

**Bài toán cơ sở:** f[i] = i + 1 nếu i ≤ K + 1

**Quy hoạch động:**

- Nếu bò thứ i là cái: f[i] = f[i-1]
- Nếu bò thứ i là đực: f[i] = f[i-K-1]

**Công thức:** f[i] = f[i-1] + f[i-K-1]

**Đáp án:** f[N]

## Bài toán: Permutation

### Đề bài

Cho chuỗi s gồm 2 dấu '>' và '<'. Đếm có bao nhiêu hoán vị gồm N + 1 số sao cho xét 2 số liền kề a[i] và a[i + 1], mối quan hệ giữa a[i] và a[i + 1] sẽ tương ứng với s[i].

### Ví dụ

s = "<><"

```
[1, 3, 2, 4]
[1, 4, 2, 3]
[2, 3, 1, 4]
[2, 4, 1, 3]
[3, 4, 1, 2]
```

**Kết quả:** 5

### Thuật toán

Gọi f[i][j] là số lượng hoán vị có i phần tử đầu tiên và phần tử cuối cùng là j.

**Bài toán cơ sở:** f[1][1] = 1

**Kết quả:** Tổng f[n][x] với x: 1 → n

### Phân tích

Trong hoán vị: (1000, 40, 4) ⟹ tương đương (3, 2, 1)

**Trường hợp s[i-1] = '<':**

```
? ? ? ? 5
```

f[5][5] = f[4][1→4]

**Công thức QHD:**

- Nếu s[i-1] là '<': f[i][j] = tổng f[i-1][x] với x: 1 → j-1
- Nếu s[i-1] là '>': f[i][j] = tổng f[i-1][x] với x: j → i-1

## Bài toán WC4 (Winter Contest 2019)

### Đề bài

Cho số nguyên dương N, xét tập hợp gồm N số tự nhiên đầu tiên. Hãy đếm có bao nhiêu cách chia tập hợp sao cho mỗi phần tử phải ở trong đúng 1 tập hợp.

### Ví dụ

N = 3

```
{1,2,3}
{1,2}, {3}
{1,3}, {2}
{2,3}, {1}
{1}, {2}, {3}
```

### Phân tích sai

**Cách 1 (sai):**

```
f[i]: số tập hợp xét i số đầu tiên
f[1] = 1: {1}
f[2] = 2: {1,2}; {1}, {2}
f[3] = 5
```

Giả sử nhóm cuối có j phần tử:

```
f[i] = f[i] + C(j,i) * f[i-j] với j: 1→i
```

Cách này đếm bị trùng.

### Thuật toán đúng

Gọi f[i] là số tập hợp khi xét i số đầu tiên.

Khi xét f[i]: giả sử nhóm cuối cùng có j phần tử và nhóm cuối chứa i.

**Nhóm j phần tử:** {i,?,?,?} ⟹ C(j-1, i-1)

**Công thức:**

```cpp
f[i] += C(j-1, i-1) * f[i-j]
```

## Bài toán SPC1 (Spring Contest 2021)

### Đề bài

Có N bà mẹ, bà mẹ thứ i có a[i] đứa con. N bà mẹ cùng vào một nhà hàng. Nhà hàng có K bàn.

**Quy tắc ngồi:**

- Những bà mẹ có thể ngồi bất kỳ bàn nào
- Những đứa con được lựa bàn như sau:
  - Chúng có thể ngồi bàn không có người lớn
  - Hoặc nếu bàn đó có người lớn, bàn đó phải có mẹ của chúng

Hỏi có bao nhiêu cách để xếp chỗ cho toàn bộ các thành viên?

### Ví dụ

```
Input:
2
1 2

Các cách có thể:
Bàn 1: m1 c1
Bàn 2: m2 c1 c2
```

### Phân tích

Giả sử có K bàn. N người mẹ đã ngồi vào j bàn.

Xét mỗi người con ⟹ K - j + 1 bàn có thể ngồi.

Có tổng sumA[n] người con.

**Số trường hợp:** (K - j + 1)^sumA[n]

Gọi f[i][j] là số cách xếp i người mẹ vào j bàn.

**Kết quả:** f[N][j] × (K - j + 1)^sumA[n]

### Thuật toán tính f[i][j]

Cách xếp N người mẹ vào j bàn.

Gọi f[i][j] là số cách xếp i người vào j bàn.

**Bài toán cơ sở:** f[0][0] = 1, f[i][0] = 0

**Ví dụ với K = 4:**

```
f[2][1] = C(1,4) × 1
f[2][2] = C(2,4) × 2!
```

**Quy hoạch động:**
Xét bà mẹ i + 1:

- Ngồi bàn mới: f[i+1][j+1] += f[i][j] × (K - j)
- Ngồi cùng bàn với mẹ cũ: f[i+1][j] += f[i][j] × j

**Công thức:**

```cpp
f[i+1][j+1] += f[i][j] * (K - j)
f[i+1][j] += f[i][j] * j
```
