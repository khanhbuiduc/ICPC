# Lazy Update on Segment Tree

## Bài toán Qmax2

### Đề bài

**Nhận xét:** Nếu tất cả các số trong đoạn [l..r] cùng được tăng thêm một lượng là x thì số lớn nhất cũng sẽ được tăng thêm một lượng là x.

Một node trên cây segment tree khi quản lý đoạn [l..r], sẽ có chứa 2 thông tin sau:

- **lazyValue**: Giá trị được tăng trên toàn bộ các nút thuộc đoạn [l..r]
- **maxValue**: Giá trị lớn nhất của các số trên đoạn [l..r]

### Ví dụ minh họa

```
a = [2, 5, 1, 2, 2, 4]

                            1: [1..6]:0,8
        2: [1..3]:15                                   3: [4..6]:15

    4: [1..2]         5: [3..3]:10         6: [4..5]        7: [6..6]

8: [1..1] 9: [2..2]:10                   12: [4..4] 13: [5..5]

Operations:
- Cập nhật đoạn [2..6] lên 10 đơn vị
- Cập nhật đoạn [1..6] lên 3 đơn vị
- Hỏi gtln của đoạn [4..4]
```

### Implementation

#### Update Lazy Value

```cpp
void updateLazyValue(int index, int l, int r) {
    if (tree[index].lazyValue > 0 && l <= r) {
        tree[2*index].lazyValue += tree[index].lazyValue;
        tree[2*index+1].lazyValue += tree[index].lazyValue;
        tree[2*index].maxValue += tree[index].lazyValue;
        tree[2*index+1].maxValue += tree[index].lazyValue;
        tree[index].lazyValue = 0;
    }
}
```

#### Update Function

```cpp
void update(int index, int L, int R, int x, int y, int k) {
    lazyUpdate(index, L, R);

    if (x > R || L > y) {
        return;
    }

    if (x <= L && R <= y) {
        it[index].lazyvalue += k;
        it[index].maxValue += k;
        lazyUpdate(index, L, R);
        return;
    }

    int mid = (L + R) / 2;
    update(2 * index, L, mid, x, y, k);
    update(2 * index + 1, mid + 1, R, x, y, k);
    it[index].maxValue = max(it[2 * index].maxValue, it[2 * index + 1].maxValue);
}
```

#### Get Function

```cpp
int get(int index, int L, int R, int x, int y) {
    lazyUpdate(index, L, R);

    if (x > R || L > y) {
        return -1;
    }

    if (x <= L && R <= y) {
        return it[index].maxValue;
    }

    int mid = (L + R) / 2;
    int vLeft = get(2 * index, L, mid, x, y);
    int vRight = get(2 * index + 1, mid + 1, R, x, y);
    return max(vLeft, vRight);
}
```

## Bài toán SC3 (Summer Contest 2020)

### Đề bài

```
Bài này yêu cầu chúng ta:

    - Có N tờ giấy màu (màu i tương ứng tờ thứ i)
    - Dán theo thứ tự từ 1 đến N, tờ i dán từ vị trí li đến ri
    - Tờ sau sẽ che khuất tờ trước nếu có vùng trùng nhau
    - Đếm số màu còn nhìn thấy được sau cùng
```

### Thuật toán.

Vì tờ sau che khuất tờ trước, ta sẽ xét ngược từ tờ N về tờ 1:

#### Định nghĩa Segment Tree

Định nghĩa nút `it[index] = true/false` với ý nghĩa:

- Nếu `it[index] = true` thì nút index quản lý đoạn [L..R], các phần tử trên đoạn [L..R] đều đã được che khuất
- `it[index] = false`: có ít nhất 1 chỗ trống

#### Implementation

##### Lazy Update

```cpp
void lazyUpdate(int index, int L, int R) {
    if (it[index] == true && L < R) {
        it[2 * index] = true;
        it[2 * index + 1] = true;
    }
}
```

##### Update Function

```cpp
void update(int index, int L, int R, int x, int y) {
    lazyUpdate(index, L, R);

    if (L > y || x > R) {
        return;
    }

    if (x <= L && R <= y) {
        it[index] = true;
        lazyUpdate(index, L, R);
        return;
    }

    int mid = (L + R) / 2;
    update(2 * index, L, mid, x, y);
    update(2 * index + 1, mid + 1, R, x, y);

    if (it[2 * index] == true && it[2 * index + 1] == true) {
        it[index] = true;
    }
}
```

##### Get Function

```cpp
bool get(int index, int L, int R, int x, int y) {
    lazyUpdate(index, L, R);

    if (L > y || x > R) {
        return true;
    }

    if (x <= L && R <= y) {
        return it[index];
    }

    int mid = (L + R) / 2;
    bool vLeft = get(2 * index, L, mid, x, y);
    bool vRight = get(2 * index + 1, mid + 1, R, x, y);

    if (vLeft == true && vRight == true) {
        return true;
    }
    return false;
}
```

#### Thuật toán chính

```cpp
// Xét việc dán tường với các miếng dán i: Q -> 1
// Xét miếng dán i có vị trí [x..y]:
for (int i = Q; i >= 1; i--) {
    if (get(1, 1, n, x, y) == false) {
        ans++;
        update(1, 1, n, x, y);
    }
}
```

## Bài toán ACM

### Đề bài

Có n ứng viên ngồi vòng tròn (được đánh số từ 1 đến n, trong đó vị trí 1 kề với vị trí n). Ban đầu mỗi ứng viên có điểm ACM bằng 1.

Có m truy vấn thuộc 3 loại sau:

- **Loại 0**: `0 L R P` - In ra tích các điểm ACM của những ứng viên từ vị trí L đến vị trí R (theo chiều kim đồng hồ) modulo P.

- **Loại 1**: `1 L R X` - Nhân điểm ACM của mỗi ứng viên trong đoạn L đến R với X.

- **Loại 2**: `2 L R Y` - Chia điểm ACM của mỗi ứng viên trong đoạn L đến R cho Y (đề bài đảm bảo mọi giá trị đều chia hết).

**Lưu ý**: Các chỉ số L, R có thể "quẹo vòng" khi L > R, tức là đoạn sẽ bao gồm các vị trí L, L+1, ..., n, 1, 2, ..., R.

### Giới hạn

- 1 ≤ n ≤ 50,000
- 1 ≤ m ≤ 50,000
- 1 ≤ L, R ≤ n
- 1 ≤ P ≤ 10^9 + 7
- 1 ≤ X, Y ≤ 150

### Ví dụ

```
Input:
5 4
0 2 4 1000000007
1 2 4 6
0 2 4 1000000007
2 1 3 2

Output:
1
216
```

**Giải thích:**

- Ban đầu: a = [1, 1, 1, 1, 1]
- Truy vấn 1: Tích từ vị trí 2 đến 4 = 1 × 1 × 1 = 1
- Truy vấn 2: Nhân đoạn [2,4] với 6 → a = [1, 6, 6, 6, 1]
- Truy vấn 3: Tích từ vị trí 2 đến 4 = 6 × 6 × 6 = 216
- Truy vấn 4: Chia đoạn [1,3] cho 2 → a = [0.5, 3, 3, 6, 1]

### Phân tích

Với X, Y ≤ 150

Ví dụ: `2 * 6 * 1 * 9 * 15 * 20 * 4 = 2^6 * 3^4 * 5^2`

Phân tích thành thừa số nguyên tố:

- 2 = 2¹
- 6 = 2¹ \* 3¹
- 1 = 1
- 9 = 3²
- 15 = 3¹ \* 5¹
- 20 = 2² \* 5¹
- 4 = 2²

Ta nhận thấy từ 1 → 150 chỉ có 35 số nguyên tố.

Ta sẽ có 35 cây segment tree, mỗi cây segment tree tương ứng sẽ làm nhiệm vụ:

- Cây segment tree thứ j, nút index quản lý đoạn [L..R] sẽ tính tổng các số mũ khi phân tích các giá trị a[L], a[L+1], ..., a[R] thành thừa số nguyên tố và ta đang xét thừa số nguyên tố thứ j

### Với một truy vấn lấy các số [L..R] và nhân thêm giá trị x

Phân tích: `X = 2^k2 * 3^k3 * 5^k5 * 7^k7 * ...`

#### Lazy Update

```cpp
// Tăng [L..R] lên x
it[j][index].sum += (R - L + 1) * x;
it[j][index].lazyvalue += x;
```

## Another Update Queries (ICPC National Việt Nam 2017)

### Đề bài

Cho một dãy số a và ban đầu các số đều = 0.

Có Q truy vấn, mỗi truy vấn là 1 trong 3 loại sau:

1. **Loại 1**: Cho đoạn [l..r], hãy tính tổng `a[l] + a[l+1] + ... + a[r]`

2. **Loại 2**: Cho đoạn [l..r], tăng:

   - `a[l]` lên `1 × 2 × 3`
   - `a[l+1]` lên `2 × 3 × 4`
   - `a[l+2]` lên `3 × 4 × 5`
   - ...

3. **Loại 3**: Cho đoạn [l..r], giảm tương tự như loại 2

### Phân tích công thức

Với vị trí i trong đoạn [l..r], ta có:
`(i-l+1) × (i-l+2) × (i-l+3)`

Đặt `u = l-1`, ta có:
`(i-u) × (i-u+1) × (i-u+2)`

Khai triển thành đa thức:

```
i³ × 1
+ i² × (-3×u + 6)
+ i¹ × (3×u² - 12×u + 11)
+ i⁰ × (-u³ + 6×u² - 11×u + 6)
```

### Thuật toán

Ta duy trì các giá trị:

- `c3[i] = i³`
- `c2[i] = i²`
- `c1[i] = i¹`
- `c0[i] = 1`

Khi ta tăng đoạn [l..r] lên lượng tương ứng, ta cập nhật các hệ số tương ứng cho từng bậc của đa thức.

### Ví dụ minh họa

```
Đoạn [2..5]:
- a[2] tăng 1×2×3
- a[3] tăng 2×3×4
- a[4] tăng 3×4×5
- a[5] tăng 4×5×6

Đoạn [4..7]:
- a[4] tăng thêm 1×2×3
- a[5] tăng thêm 2×3×4
- a[6] tăng thêm 3×4×5
- a[7] tăng thêm 4×5×6
```

Khi xét đoạn [l..r], ta cập nhật các hệ số của đa thức tương ứng với từng bậc i³, i², i¹, i⁰.
