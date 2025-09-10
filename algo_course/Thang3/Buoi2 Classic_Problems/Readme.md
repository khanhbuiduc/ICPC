# Quy hoạch động nâng cao

Tài liệu này tổng hợp các bài toán quy hoạch động nâng cao với độ phức tạp cao hơn, yêu cầu tư duy sâu hơn về việc định nghĩa trạng thái và xây dựng công thức truy hồi.

---

## Bài toán 1: Vacation

**Mô tả:** Một kỳ nghỉ hè có N ngày nghỉ. Ngày thứ i ta có thể chơi 1 trong 3 trò chơi là trò A, trò B hoặc trò C.

- Nếu ngày i chơi trò A, ta sẽ có độ hạnh phúc là `a[i]`
- Nếu ngày i chơi trò B, ta sẽ có độ hạnh phúc là `b[i]`  
- Nếu ngày i chơi trò C, ta sẽ có độ hạnh phúc là `c[i]`

**Ràng buộc:** Để đa dạng, 2 ngày liên tiếp ta không được phép chơi cùng một trò giống nhau.

**Yêu cầu:** Cho biết tổng độ hạnh phúc lớn nhất là bao nhiêu nếu ta chơi N ngày và không có 2 ngày liên tiếp chơi trò chơi giống nhau.

### Cách làm sai (thiếu thông tin trạng thái)

```plaintext
Trạng thái: f[i] = hạnh phúc lớn nhất ở ngày thứ i
Bài toán cơ sở: f[1] = max(a[1], b[1], c[1])
Đáp án: f[n]
Công thức: f[i] = f[i-1] + ...

=> THẤT BẠI vì không biết ngày thứ i-1 đã chơi trò gì
```

### Cách làm đúng (thêm chiều thông tin)

```plaintext
Trạng thái: f[i][game] = hạnh phúc lớn nhất ở ngày thứ i khi chơi trò game
           (0, 1, 2 lần lượt là game A, B, C)

Bài toán cơ sở:
  - f[1][0] = a[1]
  - f[1][1] = b[1] 
  - f[1][2] = c[1]

Đáp án: max(f[n][0], f[n][1], f[n][2])

Công thức truy hồi:
  - f[i][0] = max(f[i-1][1], f[i-1][2]) + a[i]
  - f[i][1] = max(f[i-1][0], f[i-1][2]) + b[i]
  - f[i][2] = max(f[i-1][0], f[i-1][1]) + c[i]
```

---

## Bài toán 2: IOIPALIN

**Mô tả:** Cho một chuỗi s gồm các ký tự. Hỏi cần thêm tối thiểu bao nhiêu ký tự vào chuỗi s để thành chuỗi đối xứng (palindrome)?

**Ví dụ:** 
```plaintext
Input: "Ab3bd" (độ dài 5)
Output: Số ký tự cần thêm tối thiểu
```

```plaintext
Trạng thái: f[i][j] = số lượng ký tự tối thiểu cần thêm vào chuỗi s[i...j] 
           để trở thành chuỗi đối xứng

Bài toán cơ sở: f[i][i] = 0 (chuỗi 1 ký tự đã đối xứng)

Đáp án: f[1][n]

Công thức truy hồi:
  - Case 1: s[i] == s[j] 
    => f[i][j] = f[i+1][j-1] (không cần thêm ký tự)
  - Case 2: s[i] != s[j]
    => f[i][j] = min(f[i+1][j], f[i][j-1]) + 1

Cách duyệt:
  for i = n down to 1:
    for j = i+1 to n:
      // áp dụng công thức
```

---

## Bài toán 3: Rectangle Cutting

**Mô tả:** Cho một hình chữ nhật kích thước N × M. Hỏi cần tối thiểu bao nhiêu nhát cắt, mỗi nhát chỉ được cắt theo chiều dọc hoặc chiều ngang và chỉ cắt chia thành độ dài số nguyên dương sao cho hình chữ nhật sau khi cắt trở thành các hình vuông.

```plaintext
Trạng thái: f[i][j] = số nhát cắt tối thiểu để cắt hình chữ nhật kích thước 
           i×j thành những hình vuông

Bài toán cơ sở: f[i][i] = 0 (hình vuông không cần cắt)

Đáp án: f[n][m]

Công thức truy hồi:
  - Cắt ngang: cạnh i → u và (i-u), tạo ra u×j và (i-u)×j
    f[i][j] = min(f[u][j] + f[i-u][j] + 1) với u từ 1 đến i-1
    
  - Cắt dọc: cạnh j → v và (j-v), tạo ra i×v và i×(j-v)  
    f[i][j] = min(f[i][v] + f[i][j-v] + 1) với v từ 1 đến j-1

  => f[i][j] = min(tất cả các cách cắt ngang và dọc)
```

---

## Bài toán 4: Nktick

**Mô tả:** Có N người xếp hàng mua vé. Họ sẽ mua vé từ người 1 → người N.

- Thời gian để người thứ i mua vé là `t[i]`
- Người thứ i+1 có thể nhờ người thứ i mua giúp vé cho cả 2 và thời gian để mua vé cho cả 2 là `r[i]`

**Yêu cầu:** Tổng thời gian tối thiểu để toàn bộ N người có vé là bao nhiêu?

```plaintext
Trạng thái: f[i] = tổng thời gian tối thiểu để i người đầu tiên có vé

Bài toán cơ sở: 
  - f[0] = 0
  - f[1] = t[1]
  - f[2] = min(t[1] + t[2], r[1])

Đáp án: f[n]

Công thức truy hồi:
  - Case 1: Người i tự mua vé 
    => f[i] = f[i-1] + t[i]
  - Case 2: Người i nhờ người i-1 mua dùm
    => f[i] = f[i-2] + r[i-1]
    
  => f[i] = min(f[i-1] + t[i], f[i-2] + r[i-1])
```

---

## Bài toán 5: Blast

**Mô tả:** Có 2 chuỗi s1 và s2, chuỗi s1 gồm n ký tự in thường, chuỗi s2 gồm m ký tự in thường.

Ta có thể chèn dấu `_` vào 2 chuỗi sao cho độ dài 2 chuỗi bằng nhau. Chi phí:
- Chèn dấu `_`: chi phí k
- Ghép 2 ký tự khác nhau: chi phí |c1 - c2| (độ chênh lệch ASCII)

**Ví dụ:**
```plaintext
s1 = "abf"
s2 = "be"
=> s1 = "a_bf", s2 = "b_e_" (một cách ghép)
```

```plaintext
Trạng thái: f[i][j] = tổng chi phí tối thiểu khi ghép i ký tự đầu tiên của s1 
           và j ký tự đầu tiên của s2

Bài toán cơ sở:
  - f[0][j] = j × k (chèn j dấu _ vào s1)
  - f[i][0] = i × k (chèn i dấu _ vào s2)

Đáp án: f[n][m]

Công thức truy hồi:
  - Tình huống 1: Ghép s1[i] với dấu _
    => f[i][j] = f[i-1][j] + k
  - Tình huống 2: Ghép s2[j] với dấu _  
    => f[i][j] = f[i][j-1] + k
  - Tình huống 3: Ghép s1[i] với s2[j]
    => f[i][j] = f[i-1][j-1] + |s1[i] - s2[j]|

  => f[i][j] = min(f[i-1][j] + k, f[i][j-1] + k, f[i-1][j-1] + |s1[i] - s2[j]|)
```

---

**Kết luận:** Các bài toán QHĐ nâng cao thường yêu cầu:
1. **Mở rộng không gian trạng thái** (thêm chiều thông tin như Vacation)
2. **Xét nhiều trường hợp** trong công thức truy hồi 
3. **Tư duy về thứ tự duyệt** (như IOIPALIN cần duyệt ngược)
4. **Kết hợp nhiều phương án** tối ưu (như Rectangle Cutting, Blast)
