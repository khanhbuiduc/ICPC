# Binary Search

## Giới thiệu

Bài toán tìm kiếm là một bài toán cổ điển. Cho dãy a gồm N số nguyên dương và một số x, hãy tìm vị trí của x trong a.

Ví dụ:

- a = [5, 1, 2, 9, 9, 4, 6, 3, 7], x = 4
- Tìm kiếm tuyến tính: Duyệt i = 1..N, nếu a[i] == x, trả về i. Độ phức tạp O(N).

Nếu a đã được sắp xếp tăng dần, ta dùng Binary Search với độ phức tạp O(log N).

Ví dụ:

- a (đã sort) = [1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 6, 7, 8, 9, 9], x = 9
- 2^10 = 1024 => log2(1024) = 10; N ~ 1e6 => log2(N) ~ 20.

## Mã giả Binary Search (tìm một vị trí bất kỳ của x)

```
find(a, x):
    lo = 1
    hi = n
    while lo <= hi:
        đặt mid = (lo + hi) / 2
        neu a[mid] == x:
            return mid
        else if a[mid] < x
            lo = mid + 1
        else
            hi = mid - 1
    return -1
```

Lưu ý: Dãy a phải được sắp xếp trước khi dùng Binary Search.

---

## Bài 1: OPCPIZZA — Đếm cặp (i, j) sao cho a[i] + a[j] = x

Cho dãy số nguyên a và giá trị x. Đếm số cặp chỉ số (i, j), i < j, sao cho a[i] + a[j] = x. (Các phần tử trong a đều khác nhau)

Cách làm (hai con trỏ, O(N log N) cho sort + O(N) duyệt):

```
Sắp xếp a tăng dần.
Đặt i = 0, j = n - 1, ans = 0.
Trong khi i < j:
  s = a[i] + a[j]
  Nếu s == x: ans++, i++, j--
  Nếu s < x: i++
  Nếu s > x: j--
In ans.
```

Ghi chú: Có thể làm O(N log N) bằng cách cố định j và Binary Search x - a[j] trong [0..j-1].

---

## Bài 2: Subarray Sums — Đếm số đoạn con có tổng = x

Cho dãy a gồm N số nguyên dương và số x. Đếm số đoạn con liên tiếp có tổng bằng x.

Ký hiệu:

- prefix sum: `pref[r] = a[1] + ... + a[r]`, với `pref[0] = 0`.
- Đoạn [l..r] có tổng x khi `pref[r] - pref[l-1] = x` ⇔ `pref[l-1] = pref[r] - x`.

Pseudocode gốc:

```
sum[1]+sum[2] + .... +sum[n]

tìm sum[l] - sum[r] = x  => cho sum[r] tìm sum[l] = sum[r] +  x

O(NlogN)
```

---

## Bài 3: Guess the Number — Tìm số x với ≤ 25 câu hỏi (tương tác)

Hệ thống có một số x (1..1e6). Với mỗi lần hỏi, ta in ra số u, hệ thống trả lời:

- '<' nếu x < u
- '>=' nếu x ≥ u

Pseudocode gốc:

```
cout << u << endl;
fflush(stdout);
string oper;
cin >> oper;

lo = 1, hi = 1'000'000

lấy mid = (lo + hi) / 2

Hỏi mid

    + Neu tra ve < thì hi = mid - 1
    + Neu tra ve >= thì ta ghi nhan ans = mid, lo = mid + 1
```

---

## Bài 4: New Scanning Device — Tìm hình chữ nhật ẩn bằng truy vấn diện tích giao

- Bảng kích thước 1e9 x 1e9, có một hình chữ nhật ẩn (x1, y1, x2, y2), với (x1, y1) là góc trái trên, (x2, y2) là góc phải dưới.
- Một truy vấn: Cho HCN (X1, Y1, X2, Y2), hệ thống trả về số ô giao giữa HCN ẩn và HCN truy vấn.
- Mục tiêu: tìm (x1, y1, x2, y2) trong ≤ 66 truy vấn.

Ý tưởng:

```
1. Tìm x1 bằng nhị phân trên dải dọc tiền tố:

- Query Qx(mid) = area([1..mid] × [1..1e9]).
- Qx(mid) > 0 ⇔ x1 ≤ mid. Nhị phân tìm mid nhỏ nhất có Qx(mid) > 0 ⇒ x1.
- Số truy vấn ~ ⌈log2(1e9)⌉ ≈ 30.

2. Tìm y1 tương tự trên dải ngang tiền tố:

- Query Qy(mid) = area([1..1e9] × [1..mid]).
- Qy(mid) > 0 ⇔ y1 ≤ mid. Nhị phân tìm mid nhỏ nhất có Qy(mid) > 0 ⇒ y1.
- Số truy vấn ~ 30.

3. Tìm chiều cao (h) và chiều rộng (w):

- Hỏi đường thẳng dọc tại x = x1: area([x1..x1] × [1..1e9]) = h = y2 - y1 + 1.
- Hỏi đường thẳng ngang tại y = y1: area([1..1e9] × [y1..y1]) = w = x2 - x1 + 1.

4. Suy ra:

- x2 = x1 + w - 1
- y2 = y1 + h - 1
```

Pseudocode:

```
binary_search:
    lo = 1; hi=10^9
    while 100 vòng
        mid = (lo + high) / 2
        check(mid)
            nếu số ô nhận  đc > 0
                ans=mid
                hi=mid
            else lo=mid
```

Tổng truy vấn: ~30 (x1) + ~30 (y1) + 2 (đường thẳng) = 62 ≤ 66.
