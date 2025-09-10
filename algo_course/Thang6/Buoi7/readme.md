# Bài 7: Thuật Toán Tối Ưu và Dynamic Programming

## Bài toán SC1 (Summer Contest 2020): Vé Số

### Đề bài

Có 1 tờ vé số gồm 6 chữ số.

**Quy tắc trúng thưởng:**

- Để trúng giải đặc biệt: cần 6 chữ số phải khớp hết với 6 chữ số của giải đặc biệt
- Để trúng giải nhất: cần 5 chữ số cuối phải khớp với 5 chữ số của giải nhất
- Tương tự cho các giải khác...

Hỏi ta sẽ trúng giải mấy? Hoặc thông báo là ta không trúng giải.

### Thuật toán

```cpp
string checkLottery(string ticket, vector<string> prizes) {
    // Xét từng giải từ giải đặc biệt đến giải 8
    for (int i = 0; i < prizes.size(); i++) {
        string prize = prizes[i];
        int matchLength = 6 - i; // Giải đặc biệt: 6 số, giải 1: 5 số, etc.

        // Kiểm tra suffix matching
        if (ticket.length() >= matchLength &&
            prize.length() >= matchLength) {

            string ticketSuffix = ticket.substr(ticket.length() - matchLength);
            string prizeSuffix = prize.substr(prize.length() - matchLength);

            if (ticketSuffix == prizeSuffix) {
                if (i == 0) return "Giải đặc biệt";
                else return "Giải " + to_string(i);
            }
        }
    }

    return "Không trúng giải";
}
```

## Bài toán SC5 (Summer Contest 2020)

### Đề bài

**Hình minh họa:** `Thang6/Buoi7/img/bai2.png`

Cho một số nguyên dương N.

Sẽ có 2 loại thao tác:

- **Thao tác 1:** Tăng một số x lên thành số x + 1 và chi phí là A
- **Thao tác 2:** Gấp đôi một số x và chi phí là B

Hỏi để biến từ số 0 → thành số N, tổng chi phí tối thiểu là bao nhiêu?

### Thuật toán

**Phương pháp 1: Dynamic Programming**

```cpp
vector<long long> dp(N + 1, LLONG_MAX);
dp[0] = 0;

for (int i = 0; i < N; i++) {
    if (dp[i] == LLONG_MAX) continue;

    // Thao tác 1: tăng 1
    if (i + 1 <= N) {
        dp[i + 1] = min(dp[i + 1], dp[i] + A);
    }

    // Thao tác 2: gấp đôi
    if (i * 2 <= N) {
        dp[i * 2] = min(dp[i * 2], dp[i] + B);
    }
}

return dp[N];
```

**Phương pháp 2: Backward DP (Tối ưu hơn)**

```cpp
long long solve(int n) {
    if (n == 0) return 0;

    // Trường hợp 1: n được tạo từ n-1 bằng thao tác +1
    long long cost1 = solve(n - 1) + A;

    // Trường hợp 2: n được tạo từ n/2 bằng thao tác gấp đôi (nếu n chẵn)
    long long cost2 = LLONG_MAX;
    if (n % 2 == 0) {
        cost2 = solve(n / 2) + B;
    } else {
        // Nếu n lẻ, cần +1 để về số chẵn, rồi chia 2
        cost2 = solve((n + 1) / 2) + A + B;
    }

    return min(cost1, cost2);
}
```

## Bài toán: Book Shop II

### Đề bài

Có N loại đồ vật, đồ vật thứ i sẽ được định nghĩa bởi 3 giá trị {cost[i], weight[i], cnt[i]}:

- cost[i]: giá tiền của loại thứ i
- weight[i]: cân nặng của loại thứ i
- cnt[i]: số lượng đồ vật có loại là i

Có 1 cái túi có tải trọng là W. Hỏi cần mang những đồ vật nào sao cho tổng giá trị là lớn nhất và tổng khối lượng ≤ W?

### Thuật toán Ngây Thơ

Gọi f[i][j] là tổng giá trị lớn nhất khi có i loại đồ vật đầu tiên và tổng tải trọng là j.

**Bài toán cơ sở:** f[0][j] = 0, f[i][0] = 0, khởi tạo các f[i][j] = -1

**Đáp án bài toán:** f[N][W]

**Công thức QHĐ:**
Khi ta có f[i][j] ≠ -1, xét loại đồ vật thứ i + 1:

Nếu ta lấy x đồ vật (0 ≤ x ≤ cnt[i + 1] và j + x × weight[i + 1] ≤ W):

```cpp
f[i + 1][j + x × weight[i + 1]] = max(f[i + 1][j + x × weight[i + 1]],
                                      f[i][j] + x × cost[i + 1])
```

**Vấn đề:** Độ phức tạp O(N × W × 1000)

### Thuật toán Tối Ưu: Binary Lifting

**Tính chất quan trọng:** Một số N bất kỳ, nếu ta có thể tách được số N thành 2⁰ + 2¹ + ... + 2ᵏ + R thì bất kỳ số nào từ số 1 → số N cũng có thể biểu diễn được thành tổng của các số này.

**Ví dụ:**
Đồ vật i có giá tiền là 5 đồng, cân nặng 4 ký và số lượng là 19 cái.

19 = 1 + 2 + 4 + 8 + 4

Ta "gom cục" các sản phẩm lại:

- Đồ vật (5 đồng, 4 ký) - 1 cái
- Đồ vật (10 đồng, 8 ký) - 2 cái gộp
- Đồ vật (20 đồng, 16 ký) - 4 cái gộp
- Đồ vật (40 đồng, 32 ký) - 8 cái gộp
- Đồ vật (20 đồng, 16 ký) - 4 cái còn lại

**Kết quả:** Đưa về bài toán cái túi cổ điển

```cpp
vector<Item> items;

for (int i = 0; i < N; i++) {
    int cnt = count[i];
    int power = 1;

    while (cnt > 0) {
        int take = min(cnt, power);
        items.push_back({cost[i] * take, weight[i] * take});
        cnt -= take;
        power *= 2;
    }
}

// Giờ áp dụng DP cái túi 0/1 cho items
```

**Độ phức tạp:** O(N × log(max_cnt) × W)

Số lượng đồ vật ≤ 1000 mỗi loại ⟹ gom được tối đa 11 cục
N loại ⟹ tách thành 11N đồ vật

## Bài toán SC6 (Summer Contest 2020)

### Đề bài

Tính số lượng cách tạo ra đồ thị với các ràng buộc về tính chẵn lẻ của đường đi.

### Thuật toán

Gọi f[i][ew][ow][eb] là số lượng cách tạo ra đồ thị khi có i đỉnh đầu tiên:

- **ew:** số lượng đỉnh trong tập EW (Even White)
- **ow:** số lượng đỉnh trong tập OW (Odd White)
- **eb:** số lượng đỉnh trong tập EB (Even Black)
- **ob:** số lượng đỉnh trong tập OB (Odd Black) = i - ew - ow - eb

**Bài toán cơ sở:** f[0][0][0][0] = 1

**Đáp án bài toán:** Tổng các f[n][ew][ow][eb] sao cho (ow + ob) % 2 == p

### Công thức QHĐ

#### Nếu đỉnh i + 1 là màu trắng:

**Trường hợp 1:** Kết nạp i + 1 vào tập EW

Các đỉnh từ tập EW, OW nối vào đỉnh i + 1 thì tính chẵn lẻ không thay đổi → có 2^(ow + ew) sự lựa chọn

Các đỉnh từ tập EB nối vào i + 1 thì tính chẵn lẻ không thay đổi → có 2^eb cách

Các đỉnh trong tập OB, ta cần chọn 0, 2, 4, 6, 8, ... đỉnh để nối vào i + 1:

```
Số cách chọn = C(0, ob) + C(2, ob) + C(4, ob) + ...
```

```cpp
f[i + 1][ew + 1][ow][eb] += 2^(ew + ow + eb) × (C(0, ob) + C(2, ob) + ...) × f[i][ew][ow][eb]
```

**Trường hợp 2:** Kết nạp i + 1 vào tập OW

```cpp
f[i + 1][ew][ow + 1][eb] += 2^(ew + ow + eb) × (C(1, ob) + C(3, ob) + ...) × f[i][ew][ow][eb]
```

#### Nếu đỉnh i + 1 là màu đen:

**Trường hợp 1:** i + 1 vào tập EB

```cpp
f[i + 1][ew][ow][eb + 1] += 2^(eb + ob + ew) × (C(0, ow) + C(2, ow) + ...) × f[i][ew][ow][eb]
```

**Trường hợp 2:** i + 1 vào tập OB

```cpp
f[i + 1][ew][ow][eb] += 2^(eb + ob + ew) × (C(1, ow) + C(3, ow) + ...) × f[i][ew][ow][eb]
```

### Tối ưu hóa

**Tính tổng tổ hợp chẵn/lẻ:**

```cpp
// Tổng các C(k, n) với k chẵn
long long evenSum = (powMod(2, n) + powMod(-1, n)) / 2;

// Tổng các C(k, n) với k lẻ
long long oddSum = (powMod(2, n) - powMod(-1, n)) / 2;
```

**Độ phức tạp:** O(N⁴)
