# Bài 1: Các Thuật Toán Cơ Bản

## Bài toán: Angry Birds

### Đề bài

1 chú chim khi bay với thời điểm là t thì độ cao của chú chim sẽ là f(t). Trong đó f(t) là hàm có dạng f(t) = a + b×t + c×t²

Hỏi chú chim sẽ bay theo đường cong úp ngược hay đường cong quay lên hay sẽ bay theo đường thẳng?

### Phân tích

Ta có: f(t) = a + b×t + c×t² là phương trình của 1 đường parabol

**Tình huống 1:** Nếu c = 0

- f(t) = a + b×t → phương trình đường thẳng
- Xuất ra thông báo là "đường thẳng"

**Tình huống 2:** Nếu c > 0

- f(t) = a + b×t + c×t² là phương trình đường parabol có điểm cực tiểu
- Đường cong quay lên

**Tình huống 3:** Nếu c < 0

- f(t) = a + b×t + c×t² là phương trình đường parabol úp ngược
- Đường cong úp ngược

## Bài toán: Greatest Common Divisors

### Đề bài

Cho một dãy số nguyên a gồm N số. Xét mọi tập hợp các số trong dãy a và ta tính ước chung lớn nhất của các số này. Hỏi tổng của tất cả các ước chung lớn nhất của tất cả các tập hợp trong dãy a là bao nhiêu?

### Ví dụ

```
Dãy: 1 10 5 7 2
1 ≤ a[i] ≤ 70

1 số: 1, 10, 5, 7, 2
2 số: {1,10}, {1,5}, {1,7}, {1,2}, {10,5}, {10,7}, {10,2}
3 số: {1,10,5}, {1,10,7}, {1,10,2}, ...
```

### Thuật toán

Gọi f[i][g] là số cách chọn:

- Xét i số đầu tiên
- ƯCLN = g

**Bài toán cơ sở:** f[0][0] = 1

**Đáp án bài toán:** Tổng g × f[n][g] với g: 1 → 70

**Công thức QHĐ:**
Khi ta có f[i][g] > 0:

**Tình huống 1:** Ta không chọn số ở vị trí i+1

```cpp
f[i+1][g] += f[i][g]
```

**Tình huống 2:** Ta chọn số ở vị trí i+1

```cpp
if (g == 0):
    f[i+1][a[i+1]] += f[i][g]
else:
    f[i+1][gcd(g, a[i+1])] += f[i][g]
```

## Bài toán: Dazzling

### Đề bài

Cho một dãy số nguyên a gồm N số, các số a[i] nằm trong đoạn [1..N]. Hỏi có bao nhiêu đoạn [l..r] sao cho các số trong đoạn [l..r] hoàn toàn khác nhau.

### Nhận xét

```
a = [5, 2, 9, 1, 1, 2, 6]
```

Nếu 1 đoạn [l..r] có các số khác nhau thì tất cả các đoạn con trong đoạn này đều sẽ chứa các số khác nhau.

### Thuật toán Two Pointers

```
i = 1 -> l = 1
i = 2 -> l = 1
i = 3 -> l = 1
i = 4 -> l = 1
i = 5 -> l = 5 (do có số 1 trùng)
i = 6 -> l = 5
i = 7 -> l = 5
```

**Điều kiện:** 1 đoạn [l..i] sẽ thỏa mãn khi số lượng số khác nhau = i - l + 1

**Cài đặt:**

- Gọi mảng count[x]: số lượng số có giá trị x tính đến thời điểm hiện tại
- Gọi numDiff: số lượng số khác nhau

```cpp
for (int i = 1; i <= n; i++) {
    count[a[i]]++;
    if (count[a[i]] == 1) numDiff++;

    while (numDiff < i - l + 1) {
        count[a[l]]--;
        if (count[a[l]] == 0) numDiff--;
        l++;
    }

    ans += (i - l + 1);
}
```

## Bài toán: LCS2X

### Đề bài

Cho 2 dãy số a và b, dãy a có N số và dãy b có M số. Hãy tìm c là dãy con chung dài nhất của dãy a và b, với 1 điều kiện:

```
2 × c[i] ≤ c[i + 1]
```

### Thuật toán ngây thơ

Gọi f[i][j] là độ dài của dãy con chung dài nhất khi ta chấp nhận a[i] và b[j] làm phần tử chung của dãy c (a[i] = b[j]).

**Công thức:**

```cpp
f[i][j] = max(f[x][y] + 1)
với x < i, y < j và a[x] == b[y] và 2 × a[x] ≤ a[i]
```

**Độ phức tạp:** O(N² × M²)

### Thuật toán tối ưu

#### Ví dụ

```
a = [0, 9, 1, 2, 6, 3, 8]
b = [0, 1, 6, 2, 4, 8]

f[1][j] = [0, -1, -1, -1, -1, -1]
f[2][j] = [0, 1, -1, -1, -1, -1]
f[3][j] = [0, -1, ...]
```

#### Định nghĩa mới

Gọi f[i][j] là độ dài dãy con chung dài nhất khi có i phần tử đầu tiên của dãy a và phần tử cuối cùng trong dãy chung là b[j].

**Bài toán cơ sở:** f[0][0] = 0, f[0][j] = -1

**Đáp án bài toán:** Max(f[n][j])

#### Công thức QHĐ

```cpp
f[i][j] = f[i-1][j]

if (a[i] == b[j]):
    f[i][j] = max(f[i-1][y] + 1) với y < j và 2 × b[y] ≤ b[j]
```

#### Tối ưu hóa

```cpp
for (int i = 1; i <= n; i++) {
    int maxLength = -2;

    for (int j = 0; j <= m; j++) {
        f[i][j] = f[i-1][j];

        if (b[j] == a[i]) {
            f[i][j] = max(f[i][j], maxLength + 1);
        }

        if (2 * b[j] <= a[i]) {
            maxLength = max(maxLength, f[i-1][j]);
        }
    }
}
```

**Ý tưởng:** Sử dụng biến maxLength để lưu giá trị lớn nhất của f[i-1][y] với các y thỏa mãn điều kiện 2 × b[y] ≤ a[i].
