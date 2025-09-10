# Two Pointers

## 1) Books (Two Pointers / Sliding Window)

Bài toán:

- Có N cuốn sách, thời gian đọc cuốn thứ i là t[i].
- Thư viện cho phép tổng thời gian đọc là T.
- Ta chọn một đoạn liên tiếp các cuốn sách (bắt đầu ở vị trí bất kỳ) để đọc liên tục.
- Hỏi: số lượng sách tối đa có thể đọc sao cho tổng thời gian không vượt quá T?

Ví dụ:

- N = 10, T = 20
- t = [4, 5, 12, 1, 8, 2, 2, 9, 6]
- Đáp án: 4

Giới hạn:

- 1 <= N <= 100000
- 1 <= T <= 1e9
- 1 <= t[i] <= 1e4

Cách 1 (ngây thơ, dùng prefix sum, O(N^2)):

- Dựng mảng prefix sum `sum[i] = t[1] + ... + t[i]`, với `sum[0] = 0`.
- Mỗi cặp (l, r) kiểm tra `sum[r] - sum[l-1] <= T` để cập nhật đáp án `r - l + 1`.

Cách 2 (tối ưu, Two Pointers / Sliding Window, O(N)):

- Duy trì cửa sổ [l..r] và tổng `cur`. Di chuyển r từ trái sang phải, khi `cur > T` thì tăng l và trừ bớt.

Pseudo-code:

```
sum[0]-0
sum[i] = sum[i - 1] + a[i]
Một đoạn [1 .. r] sẽ thòa mãn khi: a[l] + a[l + 1] + .... + a[r] <= T
Hay: sum[r] - sum[1 - 1] <= T

ans = 0
for 1: 0 -> n
    for r = 1 + 1 -> ng
        neu sum[r] - sum[1] <- T
        ans = max(ans, r - 1)

xuất ans
```

---

## 2) Camera (Sliding Window + Greedy)

Bài toán:

- Có N căn nhà trên một hàng. Một số nhà đã có camera (a[i] = 1), số khác chưa có (a[i] = 0).
- Cần bổ sung ít nhất bao nhiêu camera để mọi đoạn K nhà liên tiếp đều có ít nhất 2 camera.

Ý tưởng:

- Dùng cửa sổ trượt kích thước K, duy trì `cnt` = số camera trong cửa sổ hiện tại.
- Nếu `cnt < 2`, ta thêm camera tại vị trí xa bên phải nhất còn trống trong cửa sổ để ảnh hưởng tốt cho các cửa sổ sau (greedy). Cập nhật `a[j] = 1`, `cnt++`, và tăng đáp án.

Pseudo-code:

```
---o--o-----------------
i  j
dùng cửa sổ chượt xét từng khối 4 ngôi nhà liền nhau
đặt cntCamera là số lượng camera trong 4 nhà đang xét
đặt  setCamera=0 là số lượng camera thêm vào
for i: 1->4
    nếu là camera
        cntCamera++
    nếu cntCamera == 0 thì thêm setCamera++, a[3] =1
    nếu cntCamera == 1 thì thêm setCamera++, a[4] =1
    R: 4->n
        cntCamera= cntCamera - camera[R-1] + cntCamera[r];
        nếu số camera<2 thêm camera vào cuối
            setCamera++, a[4] =1
```

Ghi chú: Có thể tối ưu tìm vị trí j bằng cách lưu sẵn các vị trí trống để đạt O(N).

---

## 3) MEX Maximizing (theo modulo k)

Định nghĩa:

- MEX của dãy là số nguyên không âm nhỏ nhất không xuất hiện trong dãy.
  - MEX([1, 2, 3]) = 0
  - MEX([0, 2, 9, 1]) = 3
  - MEX([0, 1, 2, 3]) = 4

Bài toán:

- Có Q truy vấn, mỗi truy vấn thêm một số x vào dãy a.
- Ta được phép cộng/trừ k nhiều lần cho mỗi phần tử (không âm), tức là các số cùng dư modulo k có thể hoán đổi “vai trò”.
- Sau mỗi lần thêm x, hỏi MEX lớn nhất có thể đạt được là bao nhiêu?

Nhận xét quan trọng:

- u biến đổi thành v khi và chỉ khi `u % k == v % k`.
- Chỉ cần theo dõi số lượng phần tử theo từng dư modulo k: `count[r]` với `r ∈ [0..k-1]`.

Thuật toán:

- Duy trì `mex` ban đầu bằng 0.
- Mỗi lần thêm x: tăng `count[x % k]`.
- Trong khi `count[mex % k] > 0`, giảm `count[mex % k]` và tăng `mex`.
- In ra `mex` sau mỗi truy vấn.

Pseudo-code:

```
mex - 0
for i: 1 -> Q
    count[a[i] % k]++
    while true
        neu count[mex % k] > 0
            count[mex % k] --
            mex++
        else: break
    cout << mex << endl
```

Ví dụ:

- Q = 8, k = 4, stream: 2, 120, 9, 2, 15, 101, 1004, 1
- Kết quả MEX sau mỗi lần thêm: 0, 1, 3, 3, 4, 4, 7, 7

Độ phức tạp: Mỗi truy vấn O(1) trung bình; tổng số lần tăng `mex` không vượt quá tổng số phần tử đã thêm.
