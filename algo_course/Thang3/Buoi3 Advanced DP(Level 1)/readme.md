# Quy hoạch động nâng cao (Level 1)

Tài liệu này tập trung vào các bài toán QHĐ nâng cao yêu cầu mở rộng không gian trạng thái và xử lý nhiều trường hợp phức tạp.

---

## Bài toán 1: Stmerge

**Mô tả:** Có 2 chuỗi X và Y, chuỗi X gồm N ký tự X₁X₂...Xₙ, chuỗi Y gồm M ký tự Y₁Y₂...Yₘ.

Chuỗi T được gọi là chuỗi trộn của 2 chuỗi trên nếu T được tạo nên bằng việc trộn toàn bộ các ký tự của X và Y lại với nhau và vẫn bảo toàn thứ tự xuất hiện của các ký tự trong 2 chuỗi X và Y.

**Chi phí trộn:** Xét 2 ký tự T[i] và T[i+1]:
- Nếu 2 ký tự cùng thuộc chuỗi X hoặc chuỗi Y thì chi phí = 0
- Nếu ký tự thứ i từ chuỗi X và ký tự thứ j từ chuỗi Y thì chi phí cộng vào là `cost[i][j]`

**Ví dụ:**
```plaintext
n=2, m=3
cost matrix:
  3  2 30    // x1,y1 chi phí = 3
 15  5  4    // x1,y2 chi phí = 15, ...

x1 x2
y1 y2 y3

T = x1 x2 y1 y2 y3 => chi phí = 0 + 15 + 0 + 0 = 15
T = y1 y2 x1 x2 y3 => chi phí = 0 + 2 + 0 + 4 = 6
```

### Cách làm sai (thiếu thông tin trạng thái)

```plaintext
Trạng thái: f[i][j] = chi phí nhỏ nhất khi trộn i ký tự của X và j ký tự của Y
=> THẤT BẠI vì không biết ký tự cuối là từ X hay Y
```

### Cách làm đúng (thêm chiều thông tin)

```plaintext
Trạng thái: f[i][j][state] = chi phí nhỏ nhất khi trộn i ký tự của X và j ký tự của Y
           với ký tự cuối cùng có trạng thái state
           state = 0: ký tự cuối từ X
           state = 1: ký tự cuối từ Y

Bài toán cơ sở:
  - f[0][j][0] = ∞ (không thể có ký tự cuối từ X khi chưa dùng ký tự nào từ X)
  - f[0][j][1] = 0
  - f[i][0][0] = 0
  - f[i][0][1] = ∞

Đáp án: min(f[n][m][0], f[n][m][1])

Công thức truy hồi:
  - state = 0: f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1] + cost[i][j])
  - state = 1: f[i][j][1] = min(f[i][j-1][0] + cost[i][j], f[i][j-1][1])
```

---

## Bài toán 2: Khuyến mãi

**Mô tả:** Một cửa hàng siêu thị có N món đồ. Món thứ i có giá `a[i]`.

**Chương trình khuyến mãi:** 
- Khi mua món có giá > 100 thì được tặng 1 thẻ khuyến mãi
- Có thể dùng thẻ để trả cho bất kỳ món nào mà không cần mất tiền
- Nếu dùng thẻ để trả món có giá > 100 thì không nhận thêm thẻ

**Yêu cầu:** Tìm chi phí tối thiểu để mua toàn bộ N món đồ (mua lần lượt từ món 1 đến món N).

**Ví dụ:**
```plaintext
N = 6
p = [9, 102, 80, 109, 1, 45]

Mua 1,2 bằng tiền mặt: 111 đồng, 1 coupon
Mua 3 bằng coupon: 111 đồng, 0 coupon
Mua 4 bằng tiền: 220 đồng, 1 coupon
...
```

```plaintext
Trạng thái: f[i][j] = số tiền tối thiểu để mua i món đầu tiên với j coupon hiện có

Bài toán cơ sở: 
  - f[0][0] = 0
  - f[i][j] = ∞ với các trường hợp khác

Đáp án: min(f[n][j]) với j từ 0 đến n

Công thức truy hồi:
  Tình huống 1: p[i] ≤ 100
    - Mua bằng tiền mặt: f[i][j] = min(f[i][j], f[i-1][j] + p[i])
    - Mua bằng coupon (j > 0): f[i][j] = min(f[i][j], f[i-1][j+1])
  
  Tình huống 2: p[i] > 100
    - Mua bằng tiền mặt: f[i][j+1] = min(f[i][j+1], f[i-1][j] + p[i])
    - Mua bằng coupon (j > 0): f[i][j] = min(f[i][j], f[i-1][j+1])
```

---

## Bài toán 3: Line Game

**Mô tả:** Cho một dãy số nguyên `a` gồm N số. Ta chọn ra một vài số bất kỳ trong dãy.

Giả sử ta chọn ra k số với các chỉ số i₁ < i₂ < ... < iₖ.
Giá trị = a[i₁] - a[i₂] + a[i₃] - a[i₄] + ... + (-1)^(k-1) × a[iₖ]

**Yêu cầu:** Tìm tổng giá trị lớn nhất có thể.

**Ví dụ:**
```plaintext
a = [5, -2, 4, 9, 1, -6, -3]
Chọn 5, -2, 9, -6
=> Tổng: 5 - (-2) + 9 - (-6) = 22
```

```plaintext
Trạng thái: f[i][state] = tổng giá trị lớn nhất khi phần tử TIẾP THEO 
           mà ta muốn chọn sẽ mang dấu state
           state = 0: phần tử tiếp theo mang dấu dương
           state = 1: phần tử tiếp theo mang dấu âm

Bài toán cơ sở: f[0][0] = 0, các f[i][state] khác = -∞

Đáp án: max(f[n][0], f[n][1])

Công thức truy hồi:
  Giả sử f[i][state] ≠ -∞, xét phần tử thứ i+1:
  
  - Không chọn phần tử i+1:
    f[i+1][state] = max(f[i+1][state], f[i][state])
    
  - Chọn phần tử i+1:
    f[i+1][1-state] = max(f[i+1][1-state], 
                          f[i][state] + (state ? -1 : 1) × a[i+1])
```

---

## Bài toán 4: Buy and Sell Stock

**Mô tả:** Giá cổ phiếu của 1 công ty biến động trong 1 năm. Năm thứ i có giá `p[i]`.

**Ràng buộc:** 
- Được phép thực hiện không quá k giao dịch
- 1 giao dịch = 1 thao tác mua + 1 thao tác bán
- Các giao dịch không được phủ lên nhau

**Ví dụ:**
```plaintext
N = 5, k = 2
p = [5, 8, 2, 1, 10]

Giao dịch 1: Mua năm 1, bán năm 2 => -5 + 8 = 3
Giao dịch 2: Mua năm 4, bán năm 5 => -1 + 10 = 9
=> Tổng lợi nhuận: 3 + 9 = 12
```

**Nhận xét quan trọng:**
```plaintext
Mua năm x, bán năm i: lợi nhuận = p[i] - p[x]
Mua năm x, bán năm i+1: lợi nhuận = p[i+1] - p[x] = (p[i] - p[x]) + (p[i+1] - p[i])
```

```plaintext
Trạng thái: f[i][j][state] = tổng lợi nhuận lớn nhất khi có i năm, 
           đã thực hiện j giao dịch, năm thứ i trong trạng thái state
           state = 0: năm i không nằm trong giao dịch nào
           state = 1: năm i đang nằm trong giao dịch (tạm thời chấp nhận bán)

Bài toán cơ sở:
  - f[1][0][0] = 0
  - f[1][1][1] = 0  
  - Các f[i][j][state] khác = -∞

Đáp án: max(f[n][j][0], f[n][j][1]) với j từ 0 đến k

Công thức truy hồi:
  Nếu f[i][j][state] ≠ -∞:
  
  - Năm i+1 không nằm trong giao dịch:
    f[i+1][j][0] = max(f[i+1][j][0], f[i][j][state])
    
  - Năm i+1 bắt đầu giao dịch mới:
    f[i+1][j+1][1] = max(f[i+1][j+1][1], f[i][j][state] + 0)
    
  - Năm i+1 tiếp tục giao dịch hiện tại:
    f[i+1][j][1] = max(f[i+1][j][1], f[i][j][1] + p[i] - p[i+1])
```

---

**Kết luận:** Các bài toán QHĐ nâng cao level 1 thường yêu cầu:
1. **Mở rộng không gian trạng thái** để lưu thêm thông tin cần thiết
2. **Xử lý nhiều trường hợp** trong công thức truy hồi
3. **Tối ưu hóa** khi các ràng buộc lớn (như số giao dịch trong Stock)
4. **Sử dụng kỹ thuật** như đổi biến để giảm độ phức tạp









