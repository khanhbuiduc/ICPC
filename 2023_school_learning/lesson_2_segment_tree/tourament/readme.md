# Tournament Problem - Segment Tree Solution

## Đề bài

Có `n` học sinh (n lẻ), trong đó 1 người làm quản trò và `n-1` người còn lại ghép thành `(n-1)/2` cặp.

Người thứ `i` có năng lực `a[i]`. Cần ghép cặp sao cho **hiệu giữa tổng năng lực lớn nhất và nhỏ nhất của các cặp** là nhỏ nhất.

**Output:** `min(max_sum - min_sum)` trong tất cả các cách chọn quản trò.

## Ví dụ

```
n = 5
a = [1, 2, 3, 5, 9]

Kết quả: 1
```

## Thuật toán ngây thơ - O(n²)

### Ý tưởng

1. Cho từng người làm quản trò
2. Ghép cặp tối ưu: `(0,n-1)`, `(1,n-2)`, `(2,n-3)`, ...
3. Với mỗi manager, tính lại toàn bộ min/max của tất cả cặp

### Pseudocode

```
min_result = infinity
for i = 0 to n-1:  // từng người làm quản trò
    pairs = []
    for j = 0 to n/2:  // ghép cặp tối ưu, bỏ qua i
        if j != i and (n-1-j) != i:
            pairs.append(a[j] + a[n-1-j])

    min_sum = min(pairs)
    max_sum = max(pairs)
    min_result = min(min_result, max_sum - min_sum)
```

### Độ phức tạp: O(n²)

- **Mỗi manager:** O(n) để tính min/max
- **Tổng cộng:** O(n²)

## Thuật toán tối ưu - Segment Tree

### Ý tưởng chính

1. **Sort** mảng `a` tăng dần
2. **Cặp tối ưu:** `(0,n-1)`, `(1,n-2)`, `(2,n-3)`, ... để minimize hiệu max-min
3. **Segment Tree** để tối ưu việc tìm min/max khi thay đổi manager
4. Khi chọn manager ở vị trí `i`, chỉ có **1 cặp** chứa `i` bị ảnh hưởng

### Độ phức tạp: O(n log n)

- **Build tree:** O(n)
- **Mỗi manager:** O(log n) update + O(log n) query
- **Tổng cộng:** O(n + n × log n) = O(n log n)

### Phân tích chi tiết

```
a = [1, 2, 3, 5, 9] (đã sort)

Manager = 0 (bỏ 1): cặp (2,9), (3,5) → sums = [11, 8] → diff = 3
Manager = 1 (bỏ 2): cặp (1,9), (3,5) → sums = [10, 8] → diff = 2
Manager = 2 (bỏ 3): cặp (1,9), (2,5) → sums = [10, 7] → diff = 3
Manager = 3 (bỏ 5): cặp (1,9), (2,3) → sums = [10, 5] → diff = 5
Manager = 4 (bỏ 9): cặp (1,5), (2,3) → sums = [6, 5]  → diff = 1

Kết quả: min(3, 2, 3, 5, 1) = 1
```

## Key Insight

Khi thay manager từ vị trí `i`, ta chỉ cần thay phần tử `i` bằng phần tử ở giữa `(n/2)` trong cặp tương ứng.
