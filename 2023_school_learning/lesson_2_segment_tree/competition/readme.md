# Bài toán Competition

## Mô tả bài toán

Có 2 trường thi đấu:

- **Trường I**: Người thứ i có năng lực `ai`
- **Trường II**: Người thứ i có năng lực `bi`

Có `m` trận đấu, mỗi trận có dạng `(p, q)` với `1 ≤ p < q ≤ n`:

- Mỗi trường chọn 2 người trong đoạn `[p, q]` có năng lực **lớn nhất** và **lớn thứ 2**
- So sánh tổng năng lực của 2 người được chọn
- Trường nào có tổng lớn hơn thì thắng, bằng nhau thì hòa

**Output**: Số trận thắng của mỗi trường

## Cách giải

### Cách ngây thơ O(n\*m)

```cpp
win_a = 0; win_b = 0
for i = 1 to m:
    max_a = ai + aj với ai, aj là max1 và max2 của trường a trong [p,q]
    max_b = bi + bj với bi, bj là max1 và max2 của trường b trong [p,q]

    if max_a > max_b: win_a++
    else if max_a < max_b: win_b++
```

### Cách tối ưu O(log n \* m) - Segment Tree

**Ý tưởng**: Sử dụng Segment Tree để tìm max1 và max2 trong đoạn [p,q] một cách hiệu quả.

#### Xây dựng Segment Tree

- Mỗi nút lưu: `{giá_trị_max, chỉ_số}`
- Xây dựng bottom-up từ lá lên gốc

#### Tìm max1 và max2 trong đoạn [p,q]

1. **Tìm max1**: `max1 = findMax(tree, p, q)`

2. **Tìm max2**:
   - Nếu `max1.pos == p`: `max2 = findMax(tree, p+1, q)`
   - Nếu `max1.pos == q`: `max2 = findMax(tree, p, q-1)`
   - Ngược lại: `max2 = max(findMax(tree, p, max1.pos-1), findMax(tree, max1.pos+1, q))`

#### Độ phức tạp

- Xây dựng segment tree: O(n)
- Mỗi query: O(log n)
- Tổng: O(n + m\*log n)
