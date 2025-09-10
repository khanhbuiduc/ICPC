# Bài 3: Thuật Toán Nâng Cao

## Bài toán: Abstract

### Đề bài

Cho matrix N×M. Mỗi ô chứa bức tượng với chiều cao h[i][j].

Hỏi có bao nhiêu bức tượng có thể nhìn thấy, khi nhìn cả 4 phía?

**Hình minh họa:** `Thang6/Buoi3/img/1.abstract.png`

### Thuật toán

**Ý tưởng:** Duyệt 4 lần, L→R, R→L, U→D, D→U

```cpp
bool check[i][j] = false; // Khởi tạo

// Duyệt từ trái sang phải
for (int i = 1; i <= n; i++) {
    int high = 0;
    for (int j = 1; j <= m; j++) {
        if (h[i][j] > high) {
            check[i][j] = true;
            high = h[i][j];
        }
    }
}

// Duyệt từ phải sang trái
for (int i = 1; i <= n; i++) {
    int high = 0;
    for (int j = m; j >= 1; j--) {
        if (h[i][j] > high) {
            check[i][j] = true;
            high = h[i][j];
        }
    }
}

// Duyệt từ trên xuống dưới
for (int j = 1; j <= m; j++) {
    int high = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i][j] > high) {
            check[i][j] = true;
            high = h[i][j];
        }
    }
}

// Duyệt từ dưới lên trên
for (int j = 1; j <= m; j++) {
    int high = 0;
    for (int i = n; i >= 1; i--) {
        if (h[i][j] > high) {
            check[i][j] = true;
            high = h[i][j];
        }
    }
}

// Đếm số lượng check == true
```

## Bài toán: Jumbled Graph

### Đề bài

Xét một đồ thị G gồm N đỉnh và các đỉnh liên thông với nhau.

Xét hàm DFS được tổ chức như sau:

```cpp
dfs(u) {
    // Đặt v = random các đỉnh chưa được xét
    dfs(v);
}

main() {
    dfs(random các đỉnh từ 1 → N);
}
```

Hỏi có bao nhiêu đồ thị vô hướng liên thông G có N đỉnh sao cho hàm DFS chạy ra được mảng p₁, p₂, p₃, ..., pₙ?

### Ví dụ

```
N = 3
p = [3, 1, 2]
```

**Hình minh họa:**

- `Thang6/Buoi3/img/2.jumpledGraph.png`
- `Thang6/Buoi3/img/2.jumpledGraph2.png`

### Thuật toán

Gọi f[i][h] là số lượng đồ thị có thể sinh ra hành trình ứng với i đỉnh đầu tiên và đỉnh thứ i ở độ cao là h.

**Bài toán cơ sở:** f[1][0] = 1

**Công thức QHĐ:**
Khi ta có f[i][h] > 0, xét đỉnh thứ i + 1:

Đỉnh i + 1 có thể ở những độ cao j' từ 1 → h + 1:

```cpp
f[i + 1][j'] += f[i][h] × 2^(j' - 1)
```

**Đáp án bài toán:** Tính tổng f[n][h] với h: 1 → n

## Bài toán: Finding RPS

### Đề bài

Có N trận đấu bao (P) - búa (R) - kéo (S). Trận đấu thứ i, đối thủ sẽ ra món a[i] (a[i] = 'R', 'S', 'P').

Vì lười, ta sẽ xét k trận liên tục và k trận này ta sẽ ra 1 loại giống nhau. Hỏi số trận thắng tối đa ta có thể đạt được là bao nhiêu nếu k dao động từ 2 → n. Hãy cho biết số k lớn nhất để số trận đấu chiến thắng là tối đa.

### Ví dụ

```
N = 8
a = "RSSPRRPS"

k = 4: "RRRRSSSS" → thắng 4 trận
k = 5: "SSSSSPPP" → thắng 2 trận
```

### Thuật toán

Gọi countR[i], countS[i], countP[i] là số lượng R, S, P khi xét i phần tử đầu tiên.

**Tính số lượng trong đoạn [l..r]:**

- Số lượng R, S, P lần lượt là:
  - countR[r] - countR[l-1]
  - countS[r] - countS[l-1]
  - countP[r] - countP[l-1]

**Algorithm:**

```cpp
for (int k = 2; k <= n; k++) {
    int totalWins = 0;

    for (int j = k; j <= n; j += k) {
        int l = j - k + 1;
        int r = j;

        int R_count = countR[r] - countR[l-1];
        int S_count = countS[r] - countS[l-1];
        int P_count = countP[r] - countP[l-1];

        // Ta thắng khi:
        // - Ra P để thắng R
        // - Ra R để thắng S
        // - Ra S để thắng P
        int maxWins = max({R_count, S_count, P_count});
        totalWins += maxWins;
    }

    // Cập nhật kết quả tối đa
    if (totalWins > maxTotalWins) {
        maxTotalWins = totalWins;
        bestK = k;
    }
}
```

**Chia đoạn:** [1..k], [k+1..2k], [2k+1..3k], ...

## Bài toán: Interactive

### Đề bài

Cho một chuỗi s chỉ gồm các số 0 và 1 và chuỗi s này được ẩn.

Biết chuỗi s có số lượng ký tự là số lẻ.

Ta có thể đặt câu hỏi, xuất ra 1 chuỗi st cũng gồm các ký tự 0 và 1.

Hệ thống sẽ thực hiện như sau:

- Tính cntCorrect: số lượng vị trí i mà chuỗi st giống với chuỗi ẩn
- Tính cntFail: số lượng vị trí i mà chuỗi st khác với chuỗi ẩn

Hệ thống sẽ trả ra 0 nếu cntCorrect > cntFail, ngược lại sẽ trả số 1.

Hỏi: Hãy tìm ra được chuỗi ẩn sau không quá 1024 lần hỏi?

### Ví dụ 1

```
S = "0011001"
? "0001011"
→ 0
```

### Ví dụ 2

```
s = "1011011"
p = "1111111"
```

### Thuật toán

#### Phương pháp 1: Tìm vị trí cân bằng

Nếu ta thay đổi i ký tự đầu tiên và cho ra được đáp án là 0 và thay đổi i + 1 ký tự đầu tiên lại cho ra đáp án là 1.

⟹ Chứng tỏ chuỗi được hoán đổi i ký tự đầu tiên là chuỗi có số lượng ký tự đúng = (n + 1) / 2

**Binary Search:**

```cpp
int lo = 0, hi = n - 1;

while (lo <= hi) {
    int mid = (lo + hi) / 2;

    flip(mid); // Flip tất cả ký tự từ 0 đến mid

    if (query() == 0) {
        position = mid;
        lo = mid + 1;
    } else {
        hi = mid - 1;
    }
}
```

Vị trí position chính là vị trí mà nếu ta flip tất cả các ký tự từ vị trí 0 → position, ta được 1 chuỗi có số lượng vị trí đúng = (n + 1) / 2.

#### Phương pháp 2: Xác định từng ký tự

```cpp
// ans = 0: wrong < right; ans = 1: wrong >= right

// Ví dụ:
// a = "1011011"
// s = "0000000"
// s = "1000000" là tối thiểu để ans(s) vẫn bằng 0: đúng 3, sai 4

string s = "0000000"; // Khởi tạo
string temp = s;
temp[0] = '1';

if (query(temp) == 0) {
    // Tìm được chuỗi có đúng 3, sai 4
    for (int i = 0; i < n; i++) {
        temp[i] = (temp[i] == '0') ? '1' : '0';
        if (query(temp) == 1) {
            s[i] = (temp[i] == '0') ? '1' : '0'; // Vị trí này sai
        } else {
            s[i] = temp[i]; // Vị trí này đúng
        }
        temp[i] = s[i]; // Cập nhật temp
    }
}
```

**Ý tưởng:**

1. Tìm một chuỗi có số ký tự đúng = (n + 1) / 2
2. Từ chuỗi đó, thay đổi từng ký tự và kiểm tra để xác định ký tự đúng/sai
3. Xây dựng lại chuỗi gốc
