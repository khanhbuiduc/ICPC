# Quy hoạch động nâng cao (Level 2)

Tài liệu này tập trung vào các bài toán QHĐ có độ phức tạp cao hơn, yêu cầu kỹ thuật phá trị tuyệt đối và xử lý nhiều trạng thái phức tạp.

---

## Bài toán 1: Maximum Monotonicity

**Mô tả:** Cho 2 dãy số a và b gồm N số nguyên. Cho một số nguyên dương K.

Nếu ta chọn 1 đoạn [l..r] thì giá trị sẽ được cộng một lượng là |b[l] - a[r]| + |b[r] - a[l]|.

**Ràng buộc:** 
- Các đoạn không được phép phủ lên nhau
- Tổng số lượng phần tử được chọn = K

**Ví dụ:**
```plaintext
N = 7, K = 2
a = [1, 3, 7, 6, 4, 7, 2]
b = [1, 5, 3, 2, 7, 4, 5]

Đoạn [3..3]: chi phí = |3 - 7| + |3 - 7| = 8
Đoạn [4..4]: chi phí = |2 - 6| + |2 - 6| = 8
Tổng: 16
```

### Kỹ thuật phá trị tuyệt đối

**Nhận xét:** |x - y| = x - y nếu x ≥ y, và y - x nếu x < y

Đoạn [l..r] có 4 cách phá trị tuyệt đối:
1. (b[l] - a[r]) + (b[r] - a[l])
2. (b[l] - a[r]) + (a[l] - b[r]) 
3. (a[r] - b[l]) + (b[r] - a[l])
4. (a[r] - b[l]) + (a[l] - b[r])

```plaintext
Trạng thái: f[i][j][state] = tổng giá trị lớn nhất khi có i phần tử, 
           đã chọn j phần tử, với trạng thái state
           state = 0: phần tử thứ i không được chọn
           state = 1: giá trị dạng b[i] - a[l] + b[l] - a[i]
           state = 2: giá trị dạng b[i] - a[l] + a[l] - b[i]
           state = 3: giá trị dạng a[l] - b[i] + b[l] - a[i]
           state = 4: giá trị dạng a[l] - b[i] + a[l] - b[i]

Bài toán cơ sở: f[0][0][0] = 0, các f[i][j][state] khác = -∞

Đáp án: max(f[n][k][state]) với state từ 0 đến 4

Công thức truy hồi:
  Nếu f[i][j][state] ≠ -∞:
  
  1. Không chọn phần tử i+1:
     f[i+1][j][0] = max(f[i+1][j][0], f[i][j][state])
     
  2. Phần tử i+1 bắt đầu đoạn mới:
     - f[i+1][j+1][1] = max(f[i+1][j+1][1], f[i][j][state] + 2×b[i+1] - 2×a[i+1])
     - f[i+1][j+1][2] = max(f[i+1][j+1][2], f[i][j][state] + 0)
     - f[i+1][j+1][3] = max(f[i+1][j+1][3], f[i][j][state] + 2×a[i+1] - 2×b[i+1])
     - f[i+1][j+1][4] = max(f[i+1][j+1][4], f[i][j][state] + 0)
     
  3. Phần tử i+1 tiếp tục đoạn cũ (state ≠ 0):
     - state = 1: f[i+1][j+1][1] = max(..., f[i][j][1] + Δb - Δa)
     - state = 2: f[i+1][j+1][2] = max(..., f[i][j][2] + Δb + Δa)
     - state = 3: f[i+1][j+1][3] = max(..., f[i][j][3] - Δb - Δa)
     - state = 4: f[i+1][j+1][4] = max(..., f[i][j][4] - Δb + Δa)
     
  (với Δb = b[i+1] - b[i], Δa = a[i+1] - a[i])
```

---

## Bài toán 2: K Miners

**Mô tả:** Có 2 mỏ than, mỗi đợt vận chuyển ta chọn 1 trong 4 loại than (0,1,2,3) để đưa vào 1 trong 2 mỏ.

**Hàm tính than:** Lượng than sinh ra khi có 3 món kề nhau là (a,b,c):
```plaintext
calc(a, b, c):
    đặt ret = 0
    nếu a == 1 || b == 1 || c == 1: ret++
    nếu a == 2 || b == 2 || c == 2: ret++  
    nếu a == 3 || b == 3 || c == 3: ret++
    return ret
```

```plaintext
Trạng thái: f[i][a][b][c][d] = tổng lượng than lớn nhất khi có i đợt vận chuyển,
           2 món cuối cùng trong mỏ 1 lần lượt là a và b,
           2 món cuối cùng trong mỏ 2 lần lượt là c và d

Bài toán cơ sở: 
  - f[0][0][0][0][0] = 0
  - Khởi tạo các f[i][a][b][c][d] khác = -1

Đáp án: max(f[n][a][b][c][d]) với a,b,c,d từ 0 đến 3

Công thức truy hồi:
  Nếu f[i][a][b][c][d] ≠ -1, xét đợt vận chuyển thứ i+1 (gọi là shipment[i+1]):
  
  Tình huống 1: shipment[i+1] vào mỏ 1:
    i → i+1
    a → b  
    b → shipment[i+1]
    c → c (không đổi)
    d → d (không đổi)
    
    f[i+1][b][shipment[i+1]][c][d] = max(f[i+1][b][shipment[i+1]][c][d], 
                                          f[i][a][b][c][d] + calc(a, b, shipment[i+1]))
  
  Tình huống 2: shipment[i+1] vào mỏ 2:
    i → i+1
    a → a (không đổi)
    b → b (không đổi)
    c → d
    d → shipment[i+1]
    
    f[i+1][a][b][d][shipment[i+1]] = max(f[i+1][a][b][d][shipment[i+1]], 
                                          f[i][a][b][c][d] + calc(c, d, shipment[i+1]))

Độ phức tạp: O(N × 4⁴) = O(256 × N)
```

---

## Bài toán 3: Kinh nghiệm (Olimpic 30/4 2019)

**Mô tả:** An và Bình cùng đi trên bảng N hàng M cột từ (1,1) đến (N,M). Chỉ được đi sang phải hoặc xuống dưới. Mỗi ô có nấm với năng lượng c[i][j].

**Ràng buộc:** 2 người chỉ gặp nhau tại điểm đầu và điểm cuối.

**Giới hạn:** 1 ≤ N, M ≤ 200

### Tối ưu hóa không gian trạng thái

**Nhận xét:** 
- Để đi từ (1,1) đến (N,M): cần N-1 lần đi xuống + M-1 lần đi sang phải = N+M-2 bước
- Nếu biết số bước và hàng thì tính được cột: y = step + 2 - x
- Có thể giảm từ 4 chiều xuống 3 chiều

```plaintext
Trạng thái: f[step][xA][xB] = số lượng nấm lớn nhất sau step bước,
           An đang ở hàng xA, Bình đang ở hàng xB

Bài toán cơ sở: f[0][1][1] = c[1][1], các f[step][xA][xB] khác = -∞

Đáp án: f[N+M-2][N][N]

Công thức truy hồi:
  Nếu f[step][xA][xB] ≠ -∞:
  yA = step + 2 - xA, yB = step + 2 - xB
  
  Case 1: An sang phải (yA + 1 ≤ M && xA ≤ xB):
    - Bình sang phải: f[step+1][xA][xB] = max(..., f[step][xA][xB] + nấm)
    - Bình xuống: f[step+1][xA][xB+1] = max(..., f[step][xA][xB] + nấm)
    
  Case 2: An xuống (xA + 1 ≤ N):
    - Bình sang phải: f[step+1][xA+1][xB] = max(..., f[step][xA][xB] + nấm)  
    - Bình xuống: f[step+1][xA+1][xB+1] = max(..., f[step][xA][xB] + nấm)
    
  Lưu ý: Tránh trùng ô bằng cách đảm bảo xA ≤ xB (trừ bước cuối)

Độ phức tạp: O((N+M) × N²)
```

---

**Kết luận:** Các bài toán QHĐ nâng cao level 2 yêu cầu:
1. **Kỹ thuật phá trị tuyệt đối** để xử lý các biểu thức phức tạp
2. **Tối ưu hóa không gian trạng thái** để giảm độ phức tạp
3. **Xử lý ràng buộc phức tạp** như tránh trùng lặp, chia trường hợp
4. **Kỹ năng mô hình hóa** các bài toán thực tế phức tạp