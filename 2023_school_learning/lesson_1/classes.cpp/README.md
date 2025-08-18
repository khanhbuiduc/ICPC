# CLASSES - Bài toán tô màu

## Đề bài:

Cho dãy số tự nhiên **A = (a₁, a₂, ..., aₙ)**.

Mỗi số trong dãy được gán một trong hai màu: màu **1** hoặc màu **2**.

**Quy tắc tô màu:**

Với hai số **x** và **y** trong dãy, nếu **x** chia hết cho **y** và **x/y** là một số nguyên tố, thì **x** và **y** phải có màu khác nhau.

**Yêu cầu:**

- Tô màu tất cả các số trong dãy sao cho thỏa mãn quy tắc trên
- Đề bài đảm bảo luôn tồn tại một cách tô màu hợp lệ

**Ràng buộc:**

- (1 ≤ n ≤ 10⁵)
- (1 ≤ aᵢ ≤ 10¹²)

**Ví dụ:**

- Dãy [2, 4, 8]: 8/4=2 (nguyên tố), 4/2=2 (nguyên tố) → cần tô màu xen kẽ
- Dãy [3, 6, 12]: 6/3=2 (nguyên tố), 12/6=2 (nguyên tố) → tương tự

## Solution:

**Ý tưởng hiện tại:** Prime Factorization Parity
**Thuật toán ngây thơ**

```cpp
/*
    xem mỗi số là 1 đỉnh
    nếu ai/aj = p hoặc aj/ai == p, nối cạnh ai,aj
    dfs: tô màu cho đồ thị sao cho 2 đỉnh nối cạnh khác màu.
    O(n^2)
*/
```

**Thuật toán chuẩn**

```cpp
//x/y=p => x có i ước, y có i-1 ước
// x có chẵn ước => y có lẻ ước và ngược lại
// Phân loại: số ước lẻ → màu 1, chẵn → màu 2
int countDivisors(int n) {
    int cnt = 0;
    // Đếm số ước nguyên tố (với bội số)
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            cnt++; n /= i;
        }
    if (n != 1) cnt++;
    return cnt;
}
```

**Độ phức tạp đúng:** O(n × √n)
