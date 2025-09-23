# Buổi 4: Fenwick Tree và Các Bài Toán Ứng Dụng

## 1. Fenwick Tree (Binary Indexed Tree)

### Mô tả bài toán

Khi bài toán có 2 loại query:

- **Query 1**: Tăng f[x] lên k đơn vị
- **Query 2**: Tính sum(f[1->i])

### Implementation

```cpp
void update(int index, int k) {
    for(; index <= 100000; index += index & -index)
        fw[index] += k;
}

long long get(int index) {
    long long res = 0;
    for(; index > 0; index -= index & -index)
        res += fw[index];
    return res;
}
```

---

## 2. Bài toán NKINV (Đếm cặp nghịch thế)

### Đề bài

Cho một hoán vị n số nguyên dương trong đoạn [1..n]. Hãy đếm xem có bao nhiêu cặp nghịch thế.

**Cặp nghịch thế**: i < j thì p[i] > p[j]

### Ví dụ

- N = 5
- Array: [2, 5, 1, 4, 3]
- Kết quả: 5 cặp nghịch thế

### Giải pháp với Fenwick Tree

```cpp
// Duyệt từ cuối về đầu
for(int i = n; i >= 1; i--) {
    ans += get(a[i] - 1);  // Tính tổng 1 -> a[i]-1
    update(a[i], 1);       // Cập nhật f[a[i]] += 1
}
```

---

## 3. Bài toán Inversion

### Đề bài

Cho hoán vị N phần tử. Chọn a[i] làm mốc:

- Dồn số nhỏ hơn a[i] về bên trái
- Dồn số lớn hơn a[i] về phía bên phải

Chọn a[i] để số lượng nghịch thế minimum.

### Ví dụ

Array: {4, 1, 5, 3, 2, 6}

- Chọn a[1] = 4: [1, 3, 2, 4, 5, 6] → 1 nghịch thế
- Chọn a[2] = 1: [1, 2, 3, 4, 5, 6] → 0 nghịch thế

### Thuật toán

```cpp
// Tính bigger[x]: số lượng số bên trái > x
for(int i = 1; i <= n; i++) {
    int x = a[i];
    bigger[x] = i - 1 - (x - 1 - smaller[x]);
}

// Khi chọn k làm mốc: Left[k-1] + Right[k+1]
```

---

## 4. Bài toán NKMOBILES (IOI 2001)

### Đề bài

Cho bảng kích thước 1024 x 1024 với 3 loại truy vấn:

1. **Truy vấn 1**: Tăng f[x][y] lên k đơn vị
2. **Truy vấn 2**: Tính tổng hình chữ nhật từ (x1,y1) đến (x2,y2)
3. **Truy vấn 3**: Dừng thuật toán

### Fenwick Tree 2D

```cpp
void update(int x, int y, int k) {
    for(int indexx = x; indexx <= 1024; indexx += indexx & -indexx)
        for(int indexy = y; indexy <= 1024; indexy += indexy & -indexy)
            fw[indexx][indexy] += k;
}

int get(int x, int y) {
    int ret = 0;
    for(int indexx = x; indexx > 0; indexx -= indexx & -indexx)
        for(int indexy = y; indexy > 0; indexy -= indexy & -indexy)
            ret += fw[indexx][indexy];
    return ret;
}
```

### Tính tổng hình chữ nhật

```
sum(x1,y1 -> x2,y2) = sum(x2,y2) - sum(x2,y1-1) - sum(x1-1,y2) + sum(x1-1,y1-1)
```

---

## 5. Sort Problems (ICPC Miền Trung 2021)

### Đề bài

Có N học sinh, bạn thứ i có điểm {a[i], b[i]}:

- a[1..n]: distinct, b[1..n]: distinct
- a[i], b[j] ∈ [1..n]

**Student i áp đảo j** nếu: a[i] > a[j] và b[i] > b[j]

Đếm số cách chọn k học sinh sao cho không có học sinh nào áp đảo nhau.

### Ví dụ

N = 6, k = 3

```
2 5
6 3
4 1
3 6
1 4
5 2
```

### Quy hoạch động

**Định nghĩa**: f[i][j] = số cách chọn j bạn từ i bạn đầu tiên, bạn thứ i là bạn cuối cùng

**Công thức**:

```
f[i][j] = Σ f[x][j-1] với x < i và b[x] < b[i]
```

### Tối ưu với Fenwick Tree

```cpp
for(int j = 1; j <= k; j++) {
    for(int i = 1; i <= n; i++) {
        f[i][j] = get(b[i] - 1, j - 1);
        update(b[i], j - 1, f[i][j - 1]);
    }
}
```

**Độ phức tạp**: O(n × k × log n)

---

## 6. Manhattan Distance

### Đề bài

Cho N điểm trên mặt phẳng (xi, yi). Khoảng cách Manhattan:

```
d(i,j) = |xi - xj| + |yi - yj|
```

Tìm khoảng cách Manhattan thứ k nhỏ nhất.

### Biến đổi công thức

Đặt:

- a[i] = x[i] + y[i]
- b[i] = x[i] - y[i]

Khoảng cách Manhattan:

```
d(i,j) = max(|a[i] - a[j]|, |b[i] - b[j]|)
```

### Thuật toán

1. **Binary Search** trên kết quả (0 đến 4×10^8)
2. **Đếm cặp** có khoảng cách ≤ mid:

```cpp
// Sắp xếp theo a[i] tăng dần
// Với mỗi i, tìm l sao cho a[i] - a[l] ≤ k

for(int i = 1; i <= n; i++) {
    update(b[i], 1);
    while(l < i && a[i] - a[l] > k) {
        update(b[l], -1);
        l++;
    }
    int low = b[i] - k, high = b[i] + k;
    count += get(high) - get(low - 1);
}
```

### Fenwick Tree Usage

- **fw[i]**: số điểm j có b[j] = i
- **Query**: đếm điểm trong đoạn [b[i] - k, b[i] + k]
