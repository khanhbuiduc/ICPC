# Bài 5: Kỳ Vọng (Expected Value)

## Khái niệm cơ bản về Kỳ vọng

### Ví dụ: Mua vé số

Đại lý vé số có 1 triệu tờ:

- **Giải đặc biệt:** 2 tờ, mỗi tờ có 2 tỷ
- **Giải nhất:** 100 tờ, mỗi tờ có 10 triệu
- **Giải nhì:** 300 tờ, mỗi tờ có 5 triệu
- **Giải ba:** 500 tờ, mỗi tờ có 2 triệu

**Hỏi:** Trung bình cộng của số tiền là bao nhiêu?

### Tính toán

```
Kỳ vọng = (2,000,000,000 × 2 + 100 × 10,000,000 + 300 × 5,000,000 + 500 × 2,000,000) / 1,000,000
        = (4,000,000,000 + 1,000,000,000 + 1,500,000,000 + 1,000,000,000) / 1,000,000
        = 7,500,000,000 / 1,000,000
        = 7,500 đồng
```

**Kết luận:** Giá trị 7,500 được gọi là **KỲ VỌNG** số tiền ta thu được khi mua 1 tờ vé số ngẫu nhiên.

### Công thức tổng quát

```
E(X) = X₁ × P(X₁) + X₂ × P(X₂) + ... + Xₖ × P(Xₖ)
```

### Tính chất quan trọng của kỳ vọng

```
E(X + Y) = E(X) + E(Y)
```

## Bài toán: Little Pony and Maximum Expected Value

### Đề bài

Ta có N con xúc xắc, mỗi xúc xắc sẽ có M mặt, đánh số từ 1 → M.

Ta thảy xúc xắc, và xét số chấm trên các mặt.

Hỏi kỳ vọng của số chấm lớn nhất là bao nhiêu?

### Ví dụ

N = 2, M = 3

```
Kết quả có thể:
1 1 → max = 1
1 2 → max = 2
1 3 → max = 3
2 1 → max = 2
2 2 → max = 2
2 3 → max = 3
3 1 → max = 3
3 2 → max = 3
3 3 → max = 3
```

### Thuật toán

Ta duyệt i là số chấm cao nhất sau khi thảy N lần.

Với mỗi i, ta cần tính xác suất để số chấm lớn nhất của N xúc xắc là đúng i.

**Phân tích:**

- Xác suất để số chấm của cả N xúc xắc ≤ i: (i/M)^N
- Xác suất để số chấm của cả N xúc xắc ≤ i-1: ((i-1)/M)^N
- Xác suất để có ít nhất 1 xúc xắc có số chấm là i: (i/M)^N - ((i-1)/M)^N

**Công thức kỳ vọng:**

```cpp
for (int i = 1; i <= M; i++) {
    expected_value += i * ((pow(i, N) - pow(i-1, N)) / pow(M, N));
}
```

**Kết quả:**

```
Kỳ vọng = Σ(i=1 to M) i × [(i/M)^N - ((i-1)/M)^N]
```
