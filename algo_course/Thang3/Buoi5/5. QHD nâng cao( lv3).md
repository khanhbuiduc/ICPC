# Quy hoạch động nâng cao (Level 3)

Tài liệu này bao gồm các bài toán QHĐ có độ khó cao nhất, yêu cầu tư duy sâu về mô hình hóa và tối ưu hóa.

---

## Bài toán 1: Bài cỏ - K chuồng cho N con bò

**Mô tả:** Có một bãi cỏ kích thước 2×B (B ≤ 15,000,000) với N con bò và K cái chuồng.

**Yêu cầu:** Tính diện tích nhỏ nhất để phủ hết N con bò bằng K chuồng.

**Ví dụ minh họa:**
```plaintext
--------------------------------------------------------------
|     | cow |     |     |     | cow | cow | cow | cow |
--------------------------------------------------------------  
|     | cow | cow | cow |     |     |     |     |     |
--------------------------------------------------------------
```

```plaintext
Trạng thái: f[i][j][state] = tổng số ô tối thiểu để phủ i con bò 
           sử dụng j chuồng, con bò thứ i trong trạng thái state
           state = 0: bò i trong chuồng có độ rộng 1 (chỉ hàng của nó)
           state = 1: bò i trong chuồng có độ rộng 2 (cả 2 hàng)  
           state = 2: bò i trong chuồng độ rộng 1, hàng kia có chuồng độ rộng 1 kéo dài

Bài toán cơ sở:
  - f[1][1][0] = 1
  - f[1][1][1] = 2
  - f[1][2][2] = 2
  - Các f[i][j][state] khác = ∞

Đáp án: min(f[N][k][state]) với state từ 0 đến 2

Công thức truy hồi:
  Nếu f[i][j][state] ≠ ∞, xét con bò thứ i+1:
  
  1. Tách chuồng mới cho bò i+1:
     - state = 0: f[i+1][j+1][0] = min(..., f[i][j][state] + 1)
     - state = 1: f[i+1][j+1][1] = min(..., f[i][j][state] + 2)
     - state = 2: f[i+1][j+2][2] = min(..., f[i][j][state] + 2)
     
  2. Dùng chung chuồng với bò cũ:
     - Từ state = 0:
       * Nếu a[i].x == a[i+1].x: f[i+1][j][0] = min(..., f[i][j][0] + Δy)
       * f[i+1][j+1][2] = min(..., f[i][j][0] + Δy + 1)
     - Từ state = 1: f[i+1][j][1] = min(..., f[i][j][1] + 2×Δy)
     - Từ state = 2: 
       * f[i+1][j][0] = min(..., f[i][j][2] + Δy)
       * f[i+1][j][2] = min(..., f[i][j][2] + 2×Δy)
       * f[i+1][j+1][2] = min(..., f[i][j][2] + Δy + 1)
  
  (với Δy = a[i+1].y - a[i].y)
```

---

## Bài toán 2: Exam Cheating

**Mô tả:** Ta có 2 bạn An và Bình. Có n câu trắc nghiệm. An biết làm các câu a[1], a[2], ..., a[na]. Bình biết làm các câu b[1], b[2], ..., b[nb].

**Ràng buộc:** 
- Có tối đa P lần chép bài
- Mỗi lần chép không quá K câu liên tục

**Yêu cầu:** Tìm số điểm tối đa có thể đạt được.

```plaintext
Trạng thái: f[i][j][kA][kB] = tổng số câu tối đa khi có i câu, đã có j đợt chép,
           kA và kB là số câu liên tục đã chép ở An và Bình

Bài toán cơ sở: f[0][0][0][0] = 0, các f khác = -∞

Đáp án: max(f[n][p][kA][kB]) với kA, kB từ 0 đến K

Hàm phụ trợ:
  - nextA = (kA == 0 || kA == K) ? 0 : kA + 1
  - nextB = (kB == 0 || kB == K) ? 0 : kB + 1  
  - score(i, hasA, hasB): tính điểm câu i dựa vào An và Bình biết làm không

Công thức truy hồi:
  Nếu f[i][j][kA][kB] ≠ -∞:
  
  1. Không mở đợt chép mới:
     f[i+1][j][nextA][nextB] = max(..., f[i][j][kA][kB] + score(i+1, nextA>0, nextB>0))
     
  2. Mở đợt chép mới cho An:
     f[i+1][j+1][1][nextB] = max(..., f[i][j][kA][kB] + score(i+1, true, nextB>0))
     
  3. Mở đợt chép mới cho Bình:
     f[i+1][j+1][nextA][1] = max(..., f[i][j][kA][kB] + score(i+1, nextA>0, true))
     
  4. Mở đợt chép mới cho cả hai:
     f[i+1][j+2][1][1] = max(..., f[i][j][kA][kB] + score(i+1, true, true))

Độ phức tạp: O(N×P×K²)
```

### Tối ưu hóa

**Nhận xét:** Nếu P ≥ 2×⌈N/K⌉ + 2 thì có thể chép tất cả câu An và Bình biết.

---

## Bài toán 3: Alyona And Strings

**Mô tả:** Cho 2 chuỗi S và T và số K. Chọn K nhóm từ mỗi chuỗi sao cho các nhóm tương ứng giống nhau và tổng số ký tự lớn nhất.

**Ví dụ:**
```plaintext
k = 3
S = "a[abc]cba[baab][baab]c"
T = "[abc]b[baab]c[baab]"
```

### Phiên bản cải tiến (có thông tin trạng thái)

```plaintext
Trạng thái: f[i][j][groups][state] = số ký tự tối đa khi có i ký tự đầu S,
           j ký tự đầu T, đã tạo groups nhóm, với trạng thái state
           state = 0: S[i] và T[j] không cùng nhóm hoặc không bằng nhau
           state = 1: S[i] và T[j] bằng nhau và cùng trong 1 nhóm

Bài toán cơ sở:
  - f[0][0][0][0] = 0
  - Các f[i][j][groups][state] khác = -∞

Đáp án: max(f[|S|][|T|][K][0], f[|S|][|T|][K][1])

Công thức truy hồi:
  Nếu f[i][j][groups][state] ≠ -∞:
  
  1. Bỏ qua S[i+1]:
     f[i+1][j][groups][0] = max(..., f[i][j][groups][state])
     
  2. Bỏ qua T[j+1]:
     f[i][j+1][groups][0] = max(..., f[i][j][groups][state])
     
  3. Nếu S[i+1] == T[j+1]:
     - Tạo nhóm mới:
       f[i+1][j+1][groups+1][1] = max(..., f[i][j][groups][state] + 2)
     - Nếu state == 1 (tiếp tục nhóm cũ):
       f[i+1][j+1][groups][1] = max(..., f[i][j][groups][1] + 2)

Độ phức tạp: O(|S|×|T|×K)
```

---

**Kết luận:** Các bài toán QHĐ nâng cao level 3 đặc trưng bởi:

1. **Không gian trạng thái phức tạp** với nhiều chiều thông tin
2. **Tối ưu hóa cao cấp** như phân tích trường hợp đặc biệt
3. **Kỹ thuật mô hình hóa** các bài toán thực tế phức tạp
4. **Cân bằng giữa độ chính xác và hiệu quả** của thuật toán
5. **Xử lý ràng buộc** và các trường hợp biên một cách tinh tế
công thức qh:

Khi ta co f[i][j][groups] != -1
    Ta bỏ qua ký tự thứ i+1: 
        f[i+1][j][groups][0] = max(f[i+1][j][groups][0], f[i][j][groups][state])

    Ta bỏ qua ký tự thứ j+1: 
        f[i][j+1][groups][0] = max(f[i][j+1][groups][0], f[i][j][groups][state])

    Nếu S[i+1] == T[j+1]:
        Ta có thể cho S[i+1] và T[j+1] vào nhóm mới:
            f[i+1][j+1][groups+1][1] = max(f[i+1][j+1][groups+1][1], f[i][j][groups][state] +1)
        Nếu state = 1
            f[i+1][j+1][groups][1] = max(f[i+1][j][groups+1][1], f[i][j][groups][state] +1);

-------------------------------------------------------
