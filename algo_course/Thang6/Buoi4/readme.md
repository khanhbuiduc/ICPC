# Bài 4: Các Bài Toán Nâng Cao

## Bài toán: Watching TV

### Đề bài

Ta sẽ bắt đầu xem TV từ phút thứ 1. Nếu sau 15 phút không có một phút hào hứng nào thì ta sẽ tắt TV.

Hỏi ta sẽ tắt TV ở phút bao nhiêu?

### Ví dụ

**Ví dụ 1:**

```
N = 3
Phút hào hứng: [13, 50, 80]
Kết quả: 28
```

**Ví dụ 2:**

```
N = 3
Phút hào hứng: [20, 50, 80]
Kết quả: 15
```

**Ví dụ 3:**

```
N = 8
Phút hào hứng: [10, 20, 30, 40, 50, 60, 70, 80]
Kết quả: 90
```

### Thuật toán

**Ý tưởng:** Thêm phút 0 vào đầu và xét khoảng cách giữa các phút liên tiếp.

```cpp
vector<int> t = {0}; // Thêm phút 0
for (int x : exciting_minutes) {
    t.push_back(x);
}
t.push_back(90); // Thêm phút 90

for (int i = 0; i < t.size() - 1; i++) {
    if (t[i+1] - t[i] > 15) {
        return t[i] + 15;
    }
}
return 90;
```

**Quy tắc:** Xét 2 thời điểm tᵢ và tᵢ₊₁, nếu tᵢ₊₁ - tᵢ > 15 → xuất tᵢ + 15, dừng thuật toán.

## Bài toán WC6 (Winter Contest 2020)

### Đề bài

Cho một chuỗi s.

Tạo một chuỗi rev_s là chuỗi s nhưng đảo ngược thứ tự.

Tạo chuỗi st bằng cách ghép chuỗi s nối với chuỗi rev_s.

Ta gán s = st.

Thực hiện thao tác này vô hạn lần.

Cho một vị trí p, hãy cho biết vị trí p này là chữ cái nào?

### Ví dụ

```
S = "bbac"

s = "bbaccabb"
s = "bbaccabbbbaccabb"
s = "bbaccabbbbaccabbbbaccabbbbaccabb"
s = "bbaccabbbbaccabbbbaccabbbbaccabbbbaccabbbbaccabbbbaccabbbbaccabb"

p = 10 → xuất ra chữ 'b'
```

### Thuật toán

Ta có độ dài 16 là độ dài nhỏ nhất ≥ 10.

Độ dài 16 chia thành 2 phần:

- s1 gồm 8 ký tự đầu
- s2 gồm 8 ký tự cuối

Ký tự thứ 10 nằm ở vị trí số 2 của s2 → ký tự thứ 7 của s1.

**Tổng quát:** Nếu ta biết ký tự này nằm ở vị trí thứ p của chuỗi s2 thì ký tự này sẽ nằm ở vị trí n - p + 1 ở chuỗi s1.

```cpp
int findCharacter(string s, long long p) {
    if (p <= s.length()) {
        return s[p-1];
    }

    long long len = s.length();
    while (len < p) {
        len *= 2;
    }

    long long half = len / 2;
    if (p <= half) {
        return findCharacter(s, p);
    } else {
        // p nằm ở nửa sau (rev_s)
        long long pos_in_rev = p - half;
        long long pos_in_original = half - pos_in_rev + 1;
        return findCharacter(s, pos_in_original);
    }
}
```

Ký tự thứ 7 nằm ở vị trí số 3 của s2 → vị trí thứ 2 của chuỗi s1.

## Bài toán: Buying

### Đề bài

Có N món hàng và 3 siêu thị A, B, C. Mỗi món hàng có giá khác nhau ở mỗi siêu thị.

**Quy tắc giảm giá:**

- Siêu thị B: Món thứ k được mua sẽ giảm k-1 đồng
- Siêu thị C: Món thứ k được mua sẽ giảm k-1 đồng

Hỏi chi phí tối thiểu để mua hết N món hàng?

### Phân tích

**Nhận xét 1:**

```
Mua món 2, 4, 5, 9 ở siêu thị B:
y[2] - 0 + y[4] - 1 + y[5] - 2 + y[9] - 3 = y[2] + y[4] + y[5] + y[9] - (0 + 1 + 2 + 3)

Mua món 4, 5, 2, 9 ở siêu thị B:
y[4] - 0 + y[5] - 1 + y[2] - 2 + y[9] - 3 = y[4] + y[5] + y[2] + y[9] - (0 + 1 + 2 + 3)
```

⟹ Thứ tự mua không ảnh hưởng đến tổng chi phí

**Nhận xét 2:**
Nếu y[i] < z[i], ta nên sắp xếp các mặt hàng tăng dần theo giá trị y[i] - z[i] (để ưu tiên mua ở siêu thị có lợi hơn trước).

### Thuật toán

**Chia bài toán:**
Giả sử ta có 20 món:

- 9 món đầu tiên: mua ở A hoặc B
- 11 món còn lại: mua ở A hoặc C

#### Phần 1: Dynamic Programming cho A và B

Gọi f_AB[i][j] là tổng tiền nhỏ nhất phải trả khi có i sản phẩm đầu tiên và ta đã mua j sản phẩm ở siêu thị B.

**Bài toán cơ sở:** f_AB[0][0] = 0, khởi tạo các f_AB[i][j] = ∞

**Công thức QHĐ:**
Khi ta có f_AB[i][j] ≠ ∞, xét món i + 1:

```cpp
// Nếu được mua ở siêu thị A:
f_AB[i+1][j] = min(f_AB[i+1][j], f_AB[i][j] + x[i+1]);

// Nếu món i+1 được mua ở siêu thị B:
f_AB[i+1][j+1] = min(f_AB[i+1][j+1], f_AB[i][j] + y[i+1] - j);
```

#### Phần 2: Dynamic Programming cho A và C

Gọi f_AC[i][j] là tổng tiền nhỏ nhất phải trả khi có i sản phẩm cuối cùng và ta đã mua j sản phẩm ở siêu thị C.

**Bài toán cơ sở:** f_AC[N+1][0] = 0, khởi tạo các f_AC[i][j] = ∞

**Công thức QHĐ:**
Khi ta có f_AC[i][j] ≠ ∞, xét món i - 1:

```cpp
// Nếu được mua ở siêu thị A:
f_AC[i-1][j] = min(f_AC[i-1][j], f_AC[i][j] + x[i-1]);

// Nếu món i-1 được mua ở siêu thị C:
f_AC[i-1][j+1] = min(f_AC[i-1][j+1], f_AC[i][j] + z[i-1] - j);
```

#### Tối ưu hóa

```cpp
// Tạo bảng tối ưu
min_AB[i][j] = min(f_AB[i][0], f_AB[i][1], ..., f_AB[i][j]);
min_AC[i][j] = min(f_AC[i][0], f_AC[i][1], ..., f_AC[i][j]);

// Tổng tiền tối thiểu
for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
        ans = min(ans, min_AB[i][j] + min_AC[i+1][n-i]);
    }
}
```

## Bài toán AC2 (Autumn Contest 2021)

### Đề bài

**Hình minh họa:** `Thang6/Buoi4/img/AC2.png`

### Thuật toán

Gọi f[i][dSing][friendSing][dDance][friendDance][dRemain][friendRemain] là số cách khi có i bạn đầu tiên, khoảng cách từ bạn i đến bạn gần nhất trong đội hát, đội múa và đội ăn ở không lần lượt là dSing, dDance và dRemain.

**Trạng thái của 3 bạn cuối cùng trong 3 đội:**

**friendSing:**

- 0: đội hát chưa có bạn nào
- 1: Bạn cuối cùng trong đội hát chưa được ghép đôi
- 2: Bạn cuối cùng trong đội hát đã được ghép đôi

**friendDance và friendRemain:** Tương tự

### Công thức QHĐ

**Bài toán cơ sở:** f[0][0][0][0][0][0][0] = 1

**Đáp án bài toán:**
Tổng của các f[n][dSing][2][dDance][2][dRemain][0] + f[n][dSing][2][dDance][2][dRemain][2]

**Chuyển trạng thái:**
Khi ta có f[i][dSing][friendSing][dDance][friendDance][dRemain][friendRemain] > 0

#### Xét bạn thứ i + 1 có kỹ năng hát

**Trường hợp 1:** friendSing == 2

```cpp
if (dSing != 0) {
    f[i+1][1][2][(dDance + 1 == d ? 0 : dDance + 1)][friendDance][dRemain + 1][friendRemain]
    += f[i][dSing][friendSing][dDance][friendDance][dRemain][friendRemain];
}

if (dSing == 0) {
    f[i+1][1][1][dDance + 1][friendDance][dRemain + 1][friendRemain]
    += f[i][dSing][friendSing][dDance][friendDance][dRemain][friendRemain];
}
```

**Trường hợp 2:** friendSing == 1 và dSing != 0

```cpp
f[i+1][1][2][...] += f[i][dSing][friendSing][dDance][friendDance][dRemain][friendRemain];
```

**Trường hợp 3:** friendSing == 0

```cpp
f[i+1][1][1][...] += f[i][dSing][friendSing][dDance][friendDance][dRemain][friendRemain];
```

### Lưu ý

**Cập nhật khoảng cách:** Khi chuyển sang bạn i + 1, khoảng cách được cập nhật là 0 chứ không phải 1.

**Xử lý tương tự cho kỹ năng múa và ăn ở không.**
