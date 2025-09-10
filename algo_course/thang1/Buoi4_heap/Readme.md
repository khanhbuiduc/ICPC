# Buổi 4 - HEAP

## Khái niệm cơ bản

- **Min heap**: Phần tử nhỏ nhất ở top `<dùng greater<type>>`
- **Max heap**: Phần tử lớn nhất ở top

---

## Bài 1: Add All

### Đề bài

Cho một dãy số nguyên dương a gồm N số.  
Thực hiện các thao tác cho đến khi dãy a chỉ còn 1 số.

**Một thao tác như sau:**

- Chọn 2 số a[i] và a[j] bất kỳ trong dãy a và xóa chúng
- Tính tổng: a[i] + a[j] và đưa tổng này trở lại dãy a
- Chi phí cho thao tác này là: a[i] + a[j]

**Yêu cầu:** Tổng chi phí **tối thiểu** để dãy a còn lại 1 số là bao nhiêu?

### Ví dụ

```
N = 4
a = [1, 2, 3, 4]
```

### Thuật toán

Sử dụng heap: luôn lấy được số nhỏ nhất ra để tối ưu chi phí.

---

## Bài 2: QHEAP1

### Đề bài

Cho Q thao tác, mỗi thao tác là một trong 3 loại.

Ban đầu, ta có dãy a là dãy rỗng.

**Các loại thao tác:**

- **Loại 1:** Thêm một số x vào dãy a
- **Loại 2:** Xóa số x khỏi dãy a (nếu tồn tại)
- **Loại 3:** In ra số nhỏ nhất hiện tại trong dãy a

### Ví dụ

```
Q = 12

1 5
1 4
1 4
3     → Output: 4
2 5
1 7
2 4
1 9
3     → Output: 4
2 4
2 7
3     → Output: 9
```

### Thuật toán

**Thuật toán ngây thơ:**

- **Loại 1:** Thêm một số x vào heap
- **Loại 2:** Xóa số x khỏi heap (nếu tồn tại): lấy min đưa vào heap 2 đến khi thấy x xóa đi, lại cho heap 2 vào heap chính
- **Loại 3:** In ra số nhỏ nhất hiện tại trong dãy a

**Ý tưởng thuật toán chính:**

- Tạo Q2 với ý nghĩa lưu các phần tử yêu cầu xóa nhưng chưa được xóa
- Nếu `Q2.min() == Q1.min()` thì xóa ở cả 2
- Nếu không thì thêm x vào Q2

**Độ phức tạp:** O(Q log Q)

---

## Bài 3: Kmin

### Đề bài

Cho 2 dãy số nguyên dương a và b:

- Dãy a gồm Na số
- Dãy b gồm Nb số

**Thuật toán cho sẵn:**

```cpp
vector<int> c;

for (int i = 1; i <= Na; i++) {
    for (int j = 1; j <= Nb; j++) {
        c.push_back(a[i] + b[j]);
    }
}
```

Sau đó, sắp xếp dãy c theo thứ tự tăng dần.

**Yêu cầu:** Tìm K phần tử đầu tiên của dãy c sau khi sắp xếp.

### Ví dụ

```
a = [5, 1, 9]
b = [7, 1, 2, 8]
→ c = {12, 6, 7, 13, 8, 2, 3, 9, 16, 10, 11, 17}

Sau khi sắp xếp:
c = {2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 16, 17}

K = 5
→ K phần tử đầu tiên là: 2, 3, 6, 7, 8
```

### Thuật toán

- Sử dụng heap lưu `<ai + bj, i, j>`
  - Ban đầu i = 1; j từ 1 → length B
  - Lấy min từ heap ra đồng thời in ra
  - Tăng i lên 1; rồi thêm `<a[i+1] + bj, i+1, j>` vào heap

---

## Bài 4: WC3 (Winter Contest 2019)

### Đề bài

Cho N đoạn thẳng.  
Đoạn thẳng thứ i phủ các điểm nguyên có tọa độ thuộc đoạn [li .. ri].

**Yêu cầu:**

- Chọn ra K đoạn bất kỳ
- Xét tất cả các điểm được **cả K đoạn này cùng phủ lên**
- Tìm cách chọn K đoạn sao cho **số lượng điểm được tất cả K đoạn cùng phủ là lớn nhất có thể**

### Ví dụ

```
N = 8, K = 4

Danh sách các đoạn:
1. [1, 10]
2. [5, 8]
3. [3, 9]
4. [1, 15]
5. [2, 3]
6. [6, 12]
7. [4, 9]
8. [5, 11]
```

**Một số cách chọn:**

- Chọn {1, 2, 3, 4} → các điểm chung: 5, 6, 7, 8 → tổng: **4 điểm**
- Chọn {1, 2, 4, 6} → các điểm chung: 6, 7, 8 → tổng: **3 điểm**
- Chọn {1, 4, 6, 8} → các điểm chung: 6, 7, 8, 9, 10 → tổng: **5 điểm**

→ **Đáp án tốt nhất:** chọn {1, 4, 6, 8} với **5 điểm chung**

### Thuật toán

**Công thức tính:**

- `maxL = max(Li)`: điểm trái lớn nhất
- `minR = min(Ri)`: điểm phải nhỏ nhất
- Số điểm phủ = `minR - maxL + 1`

**Ví dụ tính toán:**

```
1. [1, 10], 4. [1, 15], 5. [2, 3]   → maxL = 2, minR = 3  → 2 điểm
1. [1, 10], 4. [1, 15], 3. [3, 9]   → maxL = 3, minR = 9  → 7 điểm
1. [1, 10], 4. [1, 15], 7. [4, 9]   → maxL = 4, minR = 9  → 6 điểm
1. [1, 10], 4. [1, 15], 8. [5, 8]   → maxL = 5, minR = 8  → 4 điểm
1. [1, 10], 4. [1, 15], 2. [5, 11]  → maxL = 5, minR = 10 → 6 điểm
1. [1, 10], 4. [1, 15], 6. [6, 12]  → maxL = 6, minR = 10 → 5 điểm
```

**Cách làm:** Tạo 1 heap với ý nghĩa lưu trữ R giá trị được chọn.
