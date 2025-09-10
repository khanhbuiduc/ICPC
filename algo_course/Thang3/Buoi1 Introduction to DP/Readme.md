# Giới thiệu quy hoạch động (QHĐ) và các bài toán kinh điển

Tài liệu này tổng hợp nhanh các khái niệm và ví dụ cơ bản về quy hoạch động. Mục tiêu là giúp bạn nắm ý tưởng và cách mô hình hóa; phần phân tích thuật toán (định nghĩa trạng thái, bài toán cơ sở, đáp án, công thức truy hồi) được giữ nguyên nguyên văn.

---

## Quy hoạch động là gì?

> Quy hoạch động là một kỹ thuật giải bài toán dựa vào việc giải một hoặc nhiều bài toán nhỏ hơn có cùng tính chất với bài đó.

### 4 bước giải một bài toán quy hoạch động

1. **Định nghĩa bài toán con và các yếu tố đi cùng**
2. **Xét lời giải bài toán trong trường hợp nhỏ nhất**
3. **Xác định đáp án bài toán ban đầu**
4. **Xác định công thức truy hồi** để tính bài toán hiện tại dựa trên bài toán nhỏ hơn (giả sử bài toán con được giải một cách chính xác và tối ưu)

---

## Ví dụ 1: Fibonacci

**Mô tả:** Trình bày cách làm ngây thơ và cách tối ưu bằng QHĐ (memoization/bottom-up).

### Cách làm ngây thơ

```plaintext
Bài toán: Tính số Fibonacci thứ n
Trường hợp cơ sở:
  - fibo(0) = 0
  - fibo(1) = 1
Công thức truy hồi: fibo(n) = fibo(n-1) + fibo(n-2)
Đáp án: fibo(n)
Độ phức tạp: O(2^n)
```

### Cải tiến bằng Quy hoạch động

```plaintext
Sử dụng mảng F[]: F[i] lưu trữ giá trị Fibonacci thứ i
Độ phức tạp: O(n)
```

---

## Ví dụ 2: Frog 1

**Mô tả:** Từ ô 1 nhảy đến ô n với chi phí tối thiểu; mỗi bước nhảy 1 hoặc 2 ô.

```plaintext
Trạng thái: f[i] = chi phí nhỏ nhất để nhảy từ ô 1 đến ô i
Bài toán cơ sở: 
  - f[1] = 0
  - f[2] = |h[2] - h[1] |
Đáp án: f[n]
Công thức truy hồi:
  - Nếu trước đó ở ô i-1: f[i] = f[i-1] + |h[i] - h[i-1] |
  - Nếu trước đó ở ô i-2: f[i] = f[i-2] + |h[i] - h[i-2] |
  => f[i] = min(f[i-1] + |h[i] - h[i-1] |, f[i-2] + |h[i] - h[i-2] |)
```

---

## Ví dụ 3: Longest Common Subsequence (LCS)

**Mô tả:** Tìm độ dài chuỗi con chung dài nhất của hai chuỗi.

Cho 2 chuỗi `a`, `b`. Định nghĩa chuỗi con của chuỗi `s` là chuỗi được tạo thành khi xóa một vài ký tự trong chuỗi `s`.

**Ví dụ:** `s = "abcde"` → chuỗi con của s là `"ac"`, `"bcd"`, ...

```plaintext
Trạng thái: f[i][j] = độ dài chuỗi con chung lớn nhất của i ký tự đầu tiên 
            của chuỗi a và j ký tự đầu tiên của chuỗi b
Bài toán cơ sở: f[i][0] = f[0][j] = 0
Đáp án: f[n][m] (n, m lần lượt là độ dài của a, b)
Công thức truy hồi:
  - Nếu a[i] == b[j]: f[i][j] = f[i-1][j-1] + 1
  - Nếu a[i] != b[j]: f[i][j] = max(f[i][j-1], f[i-1][j])
```

> **Lưu ý:** Dùng `getline(cin, a)` để đọc chuỗi có thể chứa khoảng trắng.

---

## Ví dụ 4: Longest Increasing Subsequence (LIS)

**Mô tả:** Tìm dãy con tăng dài nhất của một dãy số.

Cho một dãy số nguyên `a` gồm `n` số, tìm dãy số `b` là dãy con của dãy `a` sao cho các phần tử của dãy `b` tăng dần và có độ dài lớn nhất.

**Ví dụ:**
```plaintext
n = 10
a = [0, 5, 1, 9, 2, 2, 4, 6, 3, 7, 3]
Một dãy con tăng: [0, 1, 2, 4, 6, 7]
```

```plaintext
Trạng thái: f[i] = độ dài dãy con tăng dài nhất kết thúc tại a[i]
Bài toán cơ sở: f[i] = 1 với mọi i
Đáp án: max(f[i]) với mọi i từ 1 đến n
Công thức truy hồi: f[i] = max(f[j] + 1) với j từ 0 đến i-1, a[j] < a[i]
```

---

## Ví dụ 5: Knapsack 0/1

**Mô tả:** Chọn đồ vật đưa vào túi sao cho tổng giá trị tối đa và không vượt quá tải trọng.

Một ngôi nhà có `n` đồ vật. Đồ vật thứ `i` có giá trị `c[i]` và trọng lượng `w[i]`. Một người ăn trộm có cái túi với tải trọng tối đa `M`. Hỏi ăn trộm lấy được tổng giá trị tối đa là bao nhiêu để tổng trọng lượng ≤ M?

**Ví dụ:**
```plaintext
N = 6, M = 10
Đồ vật: (giá trị, trọng lượng)
1: (4, 3)    4: (3, 9)
2: (7, 2)    5: (6, 10)
3: (1, 1)    6: (8, 12)
```

```plaintext
Trạng thái: f[i][j] = tổng giá trị lớn nhất khi xét i đồ vật đầu tiên 
            với túi có tải trọng j
Bài toán cơ sở: f[0][j] = 0, f[i][0] = 0
Đáp án: f[N][M]
Công thức truy hồi:
  - Tình huống 1: Đồ vật thứ i KHÔNG THỂ bỏ vào túi (w[i] > j)
    f[i][j] = f[i-1][j]
  - Tình huống 2: Đồ vật thứ i có thể bỏ vào túi (w[i] ≤ j)
    + Không bỏ đồ vật i: f[i][j] = f[i-1][j]
    + Bỏ đồ vật i: f[i][j] = f[i-1][j-w[i]] + c[i]
    => f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + c[i])
```

---

## Ví dụ 6: Edit Distance

**Mô tả:** Số phép biến đổi tối thiểu (Insert/Delete/Replace) để biến s1 thành s2.

Cho 2 chuỗi `s1` và `s2`. Ta có 3 phép biến đổi chỉ áp dụng lên chuỗi `s1`:

- **Delete:** Lựa chọn 1 ký tự bất kỳ và xóa nó
- **Insert c:** Lựa chọn 1 vị trí bất kỳ và thêm ký tự c vào
- **Replace:** Lựa chọn 1 vị trí bất kỳ trong chuỗi s1 và thay đổi ký tự đó

**Ví dụ:**
```plaintext
s1 = "ABBC"
s2 = "CDC"
ABBC → CBBC → CBC → CDC (3 phép biến đổi)
```

```plaintext
Trạng thái: f[i][j] = số phép biến đổi ít nhất để biến i ký tự đầu tiên 
            của s1 thành j ký tự đầu tiên của s2
Bài toán cơ sở: f[i][0] = i, f[0][j] = j
Đáp án: f[s1.length()][s2.length()]
Công thức truy hồi:
  Case 1: s1[i] == s2[j]
    f[i][j] = f[i-1][j-1]
  Case 2: s1[i] != s2[j]
    - Delete: f[i-1][j] + 1
    - Insert: f[i][j-1] + 1  
    - Replace: f[i-1][j-1] + 1
    => f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1, f[i-1][j-1] + 1)
```

---

**Kết luận:** Trên đây là các mô hình QHĐ thường gặp. Khi luyện tập, hãy luôn viết rõ 4 bước (trạng thái, cơ sở, đáp án, truy hồi) trước khi cài đặt.