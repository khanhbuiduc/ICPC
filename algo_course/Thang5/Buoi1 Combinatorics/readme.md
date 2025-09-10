# Bài 1: Tổ Hợp

## Phép toán trong tổ hợp

### Phép cộng

Công việc P có k phương án độc lập hoàn thành:

- Phương án 1: p1 cách
- Phương án 2: p2 cách
- Phương án k: pk cách

**Tổng số phương án:** p1 + p2 + ... + pk

### Phép nhân

Công việc P có k giai đoạn độc lập để hoàn thành:

- Giai đoạn 1: p1 cách
- Giai đoạn 2: p2 cách
- Giai đoạn k: pk cách

**Tổng số cách thực hiện:** p1 × p2 × ... × pk

## Bài toán: Ball in Berland

### Đề bài

- Có N bạn trai đánh số từ 1 → N, có M bạn gái đánh số từ 1 → M
- Có K cặp sẵn sàng nhảy với nhau, mỗi cặp gồm 1 bạn trai và 1 bạn gái
- Nhà trường sẽ chọn ra 2 cặp để biểu diễn văn nghệ
- Điều kiện: Nếu đã chọn bạn trai trong cặp này thì cặp kia sẽ không có bạn này nữa. Tương tự với bạn gái

**Hỏi:** Có bao nhiêu cách chọn?

### Ví dụ

```
N = 5, M = 6, K = 5
Các cặp:
1 1 X
3 4
3 1
2 5
5 4 X
```

### Thuật toán ngây thơ

```cpp
for i: 1 -> n
    for j: 1 -> i - 1
        if (a[i].boy != a[j].boy && a[i].girl != a[j].girl):
            ans++
```

**Độ phức tạp:** O(K²)

### Thuật toán tối ưu

**Ý tưởng:**

- `countBoys[x]`: số lượng cặp trước đó có bạn trai = x
- `countGirls[x]`: số lượng cặp trước đó có bạn gái = x

```cpp
for i: 1 -> k
    số lượng j không thỏa = countBoys[a[i].boy] + countGirls[a[i].girl]
    số lượng j thỏa = (i - 1) - số lượng j không thỏa
    ans += số lượng j thỏa
    countBoys[a[i].boy]++
    countGirls[a[i].girl]++
```

## Hoán vị

Cho một số tự nhiên N, xét tất cả các số 1, 2, 3, ..., N. Hỏi có bao nhiêu dãy số gồm N số này, biết rằng các số trong dãy phải khác nhau.

### Ví dụ

N = 3

```
[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 1, 2]
[3, 2, 1]
```

**Kết quả:** 6 dãy

### Phân tích

Việc xây dựng dãy số trên là một công việc gồm N giai đoạn có hình ảnh: [?, ?, ?, ..., ?]

- Vị trí 1: Có N cách điền {1, 2, 3, ..., N}
- Vị trí 2: Có N - 1 cách điền {1, 2, 3, ..., N} \ {p[1]}
- Vị trí 3: Có N - 2 cách điền {1, 2, 3, ..., N} \ {p[1], p[2]}
- ...
- Vị trí N: Có 1 cách điền

**Số cách tạo ra hoán vị:** N × (N - 1) × (N - 2) × ... × 2 × 1

Ta ký hiệu: 1 × 2 × 3 × ... × N = N! (N giai thừa)

---

## Chỉnh hợp

Xét số tự nhiên N và xét các số {1, 2, 3, ..., N}. Cho một số nguyên dương K, hỏi có bao nhiêu dãy số gồm K số khác nhau được chọn từ N số trên?

### Ví dụ

N = 4, K = 3

### Công thức

**Chỉnh hợp:** A(k,n) = n!/(n-k)!

---

## Tổ hợp

Xét số tự nhiên N và xét các số {1, 2, 3, ..., N}. Cho một số nguyên dương K, hỏi có bao nhiêu tập hợp gồm K số khác nhau được chọn từ N số trên?

### Công thức

**Tổ hợp:** C(k,n) = n! / [k! × (n-k)!]

---

## Bài toán SPC2 (Spring Contest 2020)

### Đề bài

Cho một dãy số a gồm N số nguyên dương a₁, a₂, ..., aₙ.

Xét tất cả các hoán vị của dãy số a, với mỗi hoán vị gồm các vị trí [x₁, x₂, ..., xₙ], ta tính tổng các |a[xᵢ] - a[xᵢ₋₁]|

Ta hãy tính trung bình cộng của tất cả các tổng và rút gọn giá trị này dưới hình thức là một phân số tối giản.

**Hỏi:** Giá trị của tử và mẫu là bao nhiêu?

### Ví dụ

a = [2, 3, 5]

```
[2, 3, 5] ---> |2 - 0| + |3 - 2| + |5 - 3| = 5
[2, 5, 3] ---> |2 - 0| + |5 - 2| + |3 - 5| = 7
[3, 2, 5] ---> |3 - 0| + |2 - 3| + |5 - 2| = 7
[3, 5, 2] ---> |3 - 0| + |5 - 3| + |2 - 5| = 8
[5, 2, 3] ---> |5 - 0| + |2 - 5| + |3 - 2| = 9
[5, 3, 2] ---> |5 - 0| + |3 - 5| + |2 - 3| = 8
```

### Phân tích

- `sum = tổng các phần tử aᵢ`
- Số hoán vị mà aᵢ đứng đầu tiên: `aᵢ, ?, ?, ?..., ?` có (n-1) vị trí ?
  → s₁ = (a₁ + ... + aₙ) × (n - 1)!
- Số hoán vị mà ta có a[i] và a[j] đứng cạnh nhau: `?, ?, ?,...a[i], a[j], ..., ?, ?` có (n-2) vị trí ? và 1 vị trí của cặp a[i], a[j]
  → s₂ = (n-1)! × 2 × tổng mọi |a[i] - a[j]|

**Công thức:**

- Tử = s₁ + s₂
- Mẫu = n!
- Tử/Mẫu = ((a₁ + ... + aₙ) + 2 × tổng mọi |a[i] - a[j]|) / n

### Tính tổng mọi |a[i] - a[j]|

**Phá trị tuyệt đối:** Sắp xếp a tăng dần.

```cpp
for i: 1->n
    for j: 1->i-1
        sum += a[i] - a[j]
```

**Tối ưu hóa:**
Vị trí i: a[i] đóng góp (i-1) lần  
Vị trí sau i: -a[i] đóng góp (n-i) lần  
⇒ a[i] × (2i - n - 1)

```cpp
for i: 1 -> N
    sum += (2i - 1 - N) × a[i]
```

### Algorithm

1. Sắp xếp dãy a tăng dần
2. Tính tổng a₁ + a₂ + ... + aₙ
3. Tính tổng aᵢ × (2i - N - 1)
4. Rút gọn phân số cho tử và mẫu

---

## Bài toán Pizza

### Đề bài

Cho đa giác N đỉnh, vẽ các đường chéo. Hỏi số phần mà được chia ra từ đa giác này.

**Ràng buộc:** N ≤ 10¹⁸

### Phân tích

**Nhận xét:**
Khi có một đường chéo mới, thì nếu đường chéo mới cắt K đường chéo cũ thì sẽ sinh ra thêm K + 1 hình mới.

- 1 đường chéo cắt K đường chéo cũ ⟺ có K giao điểm ⟺ sinh ra K + 1 hình mới
- Đếm số lượng hình bằng việc đếm số lượng giao điểm + số lượng đường chéo + 1

**Tính toán:**

- Cứ 4 đỉnh ta có 1 giao điểm
- Với mỗi đỉnh ta có thể nối tới n-3 đỉnh còn lại ⟹ n-3 đường chéo, nhưng bị lặp 2 lần
- Số lượng giao điểm: C(4, N)
- Số lượng đường chéo: N × (N - 3) / 2

**Công thức tổng quát:** N × (N - 3) / 2 + C(4, N) + 1

### Xử lý với N ≤ 10¹⁸

**Modulo:** M = 987654321

**Tính C(4, N):**

Các phép MOD:

- Phép cộng: (a + b) % M = (a % M + b % M) % M
- Phép trừ: (a - b) % M = (a % M - b % M + M) % M
- Phép nhân: (a × b) % M = ([a % M] × [b % M]) % M

**Phân tích:**

```
C(4, N) = n! / (k! × (n-k)!) = n × (n-1) × (n-2) × (n-3) / 24
```

Với 24 = 2³ × 3, và 4 số liên tiếp chắc chắn có:

- 1 số chia hết cho 2 và 1 số chia hết cho 4
- 1 số chia hết cho 3

⟹ Chỉ cần dùng phép mod thông thường

**Xử lý N × (N-3) / 2:**

- Chắc chắn chia hết cho 2 vì 1 số chẵn, 1 số lẻ
- Kiểm tra nếu N là số chẵn thì lấy N = N / 2, sau đó nhân với (N - 3)

### Algorithm

Tạo một bảng `check[x]` với ý nghĩa: `check[x] == true` nghĩa là số x đã được chia khi tính N × (N - 1) × (N - 2) × (N - 3)

---

## Sum of Divisors

### Đề bài

Cho số nguyên dương N, gọi hàm f(i) là hàm tính tổng các ước của i.

Hãy tính f(1) + f(2) + ... + f(N)

### Ví dụ

N = 4

```
f(1) = 1
f(2) = 3
f(3) = 4
f(4) = 7
```

f(1) + f(2) + f(3) + f(4) = 15

**Ràng buộc:** 1 ≤ N ≤ 10¹²

⟹ Độ phức tạp nhỏ hơn O(√N)

### Phân tích

N = a × b với a < b thì a < √N

Ví dụ: N = 100

- 1: đóng góp trong tổng 100 lần
- 2: đóng góp trong tổng 50 lần
- 3: đóng góp trong tổng 33 lần
- ...
- 10: đóng góp trong tổng 10 lần

### Thuật toán

**Case 1:** Số < √N

```cpp
for(int i = 1; i*i < n; i++)
    ans += i * (100/i);
```

**Case 2:** Trường hợp còn lại (tmp = 100/√100 - 1 = 9)

- Chỉ đóng góp 1 lần: 51 → 100 (từ N/2 + 1 tới N)
- Đóng góp 2 lần: 34 → 50 (từ N/3 + 1 tới N/2)
- ...
- Đóng góp 9 lần: từ N/9 + 1 tới N/8

```cpp
for(int i = 1; i <= tmp; i++) {
    a = n/(i + 1) + 1
    b = n/i
    ans += i * (b + a) * (b - a + 1) / 2
}
```
