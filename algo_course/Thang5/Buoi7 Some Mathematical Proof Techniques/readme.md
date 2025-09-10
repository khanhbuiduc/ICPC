# Bài 7: Phương Pháp Toán Học

## Bài toán: Modulo Sum

### Đề bài

Cho một dãy số nguyên dương a. Cho một số nguyên dương K. Hỏi có thể chọn ra được vài số trong dãy a sao cho tổng chia hết cho K hay không?

### Ví dụ

```
N = 5
a = [2, 5, 1, 9, 4]
K = 14
```

**Kết quả:** YES

**Ràng buộc:**

- 1 ≤ N ≤ 1,000,000
- 1 ≤ K ≤ 100

### Thuật toán 1: Quy hoạch động (N ≤ K)

Phân tích các số thành các số % K lấy dư: [2, 5, 1, 9, 4] → [2, 5, 1, 9, 4]

Gọi f[i][r][state] là trạng thái có thể/không thể đạt được khi có i phần tử đầu tiên và tổng các số khi chia cho K có số dư là r và ta đã chọn được ít nhất một số.

**Bài toán cơ sở:** f[0][0][0] = 1

**Đáp án bài toán:** f[N][0][1] == 1 thì in ra YES, else in ra NO

**Công thức QHĐ:**
Khi ta có f[i][r][state] == 1:

**Tình huống 1:** Số thứ i + 1 ta không chọn

```cpp
f[i + 1][r][state] = 1
```

**Tình huống 2:** Số thứ i + 1 ta chọn

```cpp
f[i + 1][(r + a[i + 1]) % K][1] = 1
```

### Thuật toán 2: Nguyên lý Dirichlet (N > K)

Tính prefix sum:

```cpp
sum[0] = 0 % K = 0
sum[1] = a[1] % K
sum[2] = (a[1] + a[2]) % K
sum[3] = (a[1] + a[2] + a[3]) % K
...
```

**Nguyên lý Dirichlet:**
Có 4 con thỏ và muốn nhốt chúng vào 3 cái chuồng, chắc chắn phải có 1 chuồng có ít nhất 2 con.

**Áp dụng:**

- Với K = 6, N = 10 thì ta sẽ có 11 giá trị sum
- sum[0] % 6, sum[1] % 6, ..., sum[10] % 6
- Có 11 giá trị nhưng chỉ có 6 giá trị dư khác nhau (0, 1, 2, 3, 4, 5)
- Chắc chắn có ít nhất 2 giá trị có cùng số dư

**Kết luận:**
Giả sử i < j và sum[i] % K = sum[j] % K
⟹ sum[j] - sum[i] chia hết cho K
⟹ a[i + 1] + a[i + 2] + ... + a[j] chia hết cho K

**Với N > K:** Luôn luôn tìm được ít nhất 1 cách để chọn ra các số chia hết cho K ⟹ đáp án luôn là YES

## Bài toán AC6 (Autumn Contest 2021)

### Đề bài

Cho 3 số nguyên dương a, b, n. Xét các cặp (x, y) không âm thỏa mãn a×x + b×y = n.

Hỏi x + y nhỏ nhất là bao nhiêu?

**Ràng buộc:** 1 ≤ a, b, n ≤ 1 tỷ

### Thuật toán

**Bước 1:** Đặt g = gcd(a, b)

Nếu n không chia hết cho g ⟹ kết quả là -1

Trong trường hợp ngược lại, ta có: a = a/g, b = b/g, n = n/g

Phương trình trở thành: a×x + b×y = n với gcd(a, b) = 1

**Bước 2:** Giả sử a ≤ b

Vì đề yêu cầu x + y phải nhỏ nhất có thể.

### Chứng minh tối ưu

Giả sử ta có 2 đáp án (x₁, y₁) và (x₂, y₂) với y₁ < y₂

```
a×x₁ + b×y₁ = n
a×x₂ + b×y₂ = n

x₁ = (n - b×y₁)/a
x₂ = (n - b×y₂)/a
```

**Cần chứng minh:** x₁ + y₁ ≥ x₂ + y₂

```
x₁ + y₁ = (n - b×y₁)/a + y₁ = (n - b×y₁ + a×y₁)/a
x₂ + y₂ = (n - b×y₂)/a + y₂ = (n - b×y₂ + a×y₂)/a
```

So sánh x₁ + y₁ ≥ x₂ + y₂:

```
(n - b×y₁ + a×y₁)/a ≥ (n - b×y₂ + a×y₂)/a
⟺ n - b×y₁ + a×y₁ ≥ n - b×y₂ + a×y₂
⟺ (a - b)×y₁ ≥ (a - b)×y₂
⟹ y₁ ≤ y₂ (do a - b luôn âm)
```

### Algorithm

```cpp
// a×x + b×y = n
for (y = n/b; y >= 0; y--) {
    if ((n - b * y) % a == 0) {
        x = (n - b * y) / a;
        return x + y;
    }
}
```

### Tối ưu hóa

**Tình huống 1:** b ≥ √(1 tỷ) ≈ 33,000

- Duyệt trực tiếp

**Tình huống 2:** b < √(1 tỷ)

### Bổ đề

Với 2 số N và M có gcd(N, M) = 1, xét M bội liên tục của số N, các số này có số dư khác nhau khi chia cho M.

**Ví dụ:** N = 10, M = 7

```
0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, ...
0,  3,  6,  2,  5,  1,  4,  0,  3,  6,   2, ...
```

**Chứng minh bằng phản chứng:**
Giả sử xét M bội liên tục, có 2 số có cùng số dư, giả sử 2 số đó là i×N và j×N và 2 số này khi chia cho M có cùng số dư.

Ta có: j×N - i×N sẽ chia hết cho M
⟺ N×(j - i) chia hết cho M

Do gcd(N, M) = 1 ⟹ j - i chia hết cho M

Xét x×N, (x+1)×N, ..., (x+M-1)×N

Giả sử j = x + M - 1, i = x
⟹ j - i = M - 1 ⟹ vô lý

## Bài toán: Subsequence Addition

### Đề bài

Cho một dãy số a.

Có nguyên tắc tạo dãy số như sau:

Ban đầu, ta có dãy số b = [1]

Sau đó, ta có thể lấy một vài số trong dãy b cộng lại và thêm nó vào đằng sau để có một số mới.

Hỏi có thể tạo được dãy a từ dãy b hay không?

### Ví dụ 1

a = [1, 2, 1, 3, 4] ⟹ YES

```
b = [1]
b = [1, 1]        (thêm 1)
b = [1, 1, 2]     (thêm 1+1=2)
b = [1, 1, 2, 1]  (thêm 1)
b = [1, 1, 2, 1, 3] (thêm 1+2=3)
b = [1, 1, 2, 1, 3, 4] (thêm 1+3=4)
```

### Ví dụ 2

a = [1, 1, 2, 3, 5]

### Điều kiện cần và đủ

Dãy số a sẽ thỏa mãn nếu: a[i] ≤ Tổng của a[1] + a[2] + ... + a[i - 1]

### Chứng minh bằng quy nạp

**Bước cơ sở:**
Với N = 1, a[1] = 1. Điều này đúng.

**Giả thuyết quy nạp:**
Giả sử với N = k, điều này đúng (a[k] tạo được khi a[k] ≤ a[1] + a[2] + ... + a[k-1])

**Bước quy nạp:**
Ta sẽ chứng minh điều này đúng với N = k + 1 (a[k+1] tạo được khi a[k+1] ≤ a[1] + a[2] + ... + a[k])

**Trường hợp 1:**
Nếu a[k+1] ≤ a[1] + a[2] + ... + a[k-1]
⟹ Theo giả thuyết quy nạp, ta có thể tạo được a[k+1]

**Trường hợp 2:**
Nếu a[k+1] > a[1] + a[2] + ... + a[k-1] và a[k+1] ≤ a[1] + a[2] + ... + a[k]

Tách a[k+1] thành a[k] + x
⟹ x ≤ a[1] + a[2] + ... + a[k-1]
⟹ Có cách để chọn một vài số để tạo ra được x

**Kết luận:**
Bài toán đưa về: Cho dãy số a, ban đầu a[1] = 1, a[i] sẽ xây dựng được nếu tổng a[1] + a[2] + ... + a[i-1] ≥ a[i]
