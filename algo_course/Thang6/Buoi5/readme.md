# Bài 5: Các Thuật Toán Đồ Thị và Tối Ưu

## Bài toán SC1 (Summer Contest 2022)

### Đề bài

Có một chuỗi vô hạn: 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, ...

Khi tới một lá thứ i, lá này sẽ được chia cho bạn i % 4.

Gọi count[i] với ý nghĩa: số lượng lá heo mà bạn thứ i sở hữu.

Khi ta chia lá thứ i, nếu đây là một lá heo, ta sẽ tăng count[i % 4]++.

Bạn x sẽ ăn trắng nếu count[x] == 4.

### Thuật toán

```cpp
int count[4] = {0, 0, 0, 0};

for (int i = 0; i < total_cards; i++) {
    int player = i % 4;
    if (cards[i] == "heo") {
        count[player]++;
        if (count[player] == 4) {
            cout << "Player " << player << " loses!" << endl;
            break;
        }
    }
}
```

## Bài toán VOI 06: Mạng Máy Tính

### Đề bài

Ta có N máy tính và M cọng dây nối. Một cọng dây nối sẽ nối dữ liệu từ máy u → máy v (đây là dữ liệu 1 chiều).

Một hệ thống máy tính được gọi là "thông suốt" nếu tất cả các cặp máy tính (u, v) đều có thể truyền dữ liệu đến với nhau (trực tiếp hoặc thông qua một số máy tính trung gian). Và v có thể nhận được dữ liệu từ u và u cũng có thể nhận được dữ liệu từ v.

Hỏi: Có thể thêm đúng duy nhất 1 cọng dây nối sao cho mạng máy tính trở nên thông suốt hay không? Nếu có, hãy in ra cạnh u v cần nối.

**Hình minh họa:** `Thang6/Buoi5/img/bai2.png`

### Thuật toán

**Ý tưởng:**

1. Dùng SCC chuyển đồ thị thành đồ thị DAG
2. Đồ thị chỉ có 1 đỉnh bắt đầu và chỉ có 1 đỉnh kết thúc thì thông suốt

**Cài đặt:**

```cpp
// 1. Tìm các thành phần liên thông mạnh (SCC)
vector<vector<int>> sccs = findSCC(graph);

// 2. Xây dựng đồ thị DAG từ các SCC
vector<vector<int>> dag = buildDAG(sccs, graph);

// 3. Đếm số đỉnh có in-degree = 0 và out-degree = 0
int sources = 0, sinks = 0;
for (int i = 0; i < dag.size(); i++) {
    if (inDegree[i] == 0) sources++;
    if (outDegree[i] == 0) sinks++;
}

// 4. Kiểm tra điều kiện
if (sources == 1 && sinks == 1) {
    cout << "YES" << endl;
    // In ra cạnh cần nối từ sink đến source
} else {
    cout << "NO" << endl;
}
```

---

Nâng cap tuyến đường.

Cho một đồ thị có hướng và có N đình. Ta có M cạnh, cạnh thứ i nối ui -> vi với trọng số wi

Ta có Q truy van, mỗi truy van gồm một đinh s và một gia trị t0 với ý nghĩa:

Già sử ta được phép thay đổi TỐI ĐA 1 cạnh trở thẳnh trọng sõ t
Hòi: độ dài đường đi ngan nhất từ 1 -> s là bao nhiêu

---

Nhận xét: 1 <= n <= 2000

Với mỗi truy van, vì ta chi tìm độ dài đường đi từ 1 -> s

Gọi dijkstra xuất phát từ đình 1, đặt dist[u] là độ dài đường đi ngắn nhất từ 1 -> u
Với các đình u từ 2 -> n, gọi dijkstra xuất phát từ u (trên đo thị ngược), ta co bang rev_dist[u][v] với ý nghĩa: rev_dist[u][v] la độ dai đuong đi ngan nhat từ u -> v
(trên đô thị ngược)

Với mỗi truy vấn s, t0

----- > độ dài đường đi ngần nhất từ 1 -> s sẽ chính là dist[s] (nếu không sửa)
Nếu ta sửa một cạnh (u, v) từ trọng số w --- > t0
Cạnh (u, v) ta chỉ nên sửa nếu w > t0
Việc sửa chỉ có ý nghĩa nếu đường đi từ 1 -> s có băng qua cạnh (u, v)
-===- > độ dài đường đi ngắn nhất từ 1 -> s (CÓ BĂNG QUA CẠNH (u, v)):
dist[u] + t0 + rev_dist[s][v]
Bài toán đưa về: Trong tat cả các cạnh (u, v) có w > t0, hay thm gia trị dist[u] + t0 + rev_dist[s][v] nho nhat có thể.

---

Gọi minDist[s][w] là giá trị dist[u] + rev_dist[s][v] nhỏ nhất có thể với w(u, v) >= w

Xét đinh s = 5

Có các cạnh (2, 3, 4: 15), (1, 2, 10:19), (2, 6, 3: 17)

minDist[5][3] = 15

minDist[5][9] = 19

minDist[5][1] = 15

Duyệt ngược w: 9 -> 1
minDist[s][w] = max(minDist[s][w], minDist[s][w + 1])

Khi ta có truy vẫn s, t0, xét tất cả các cạnh (u, v) có w > t0 và xác định dist[u] + rev_dist[s][v] nhỏ nhất có thể:

Giá trį dist[u] + rev_dist[s][v] = minDist[s][t0 + 1]
-=-==== > độ dài ngắn nhất từ 1 -> s = min(dist[s], minDist[s][t0 +1] + t0)|

---

tự phân tích:
ans là min(dist[s] and dist[u] + rev_dist[s][v] + t0)

xét: min(dist[u] + rev_dist[s][v] + t0):
min_dist = min(dist[u] + rev_dist[s][v]) //chỉ quan tâm cạnh lớn hơn w>t0
gọi min_dist[s][w] là dist[u] + rev_dist[s][v] với w(u,v) = w;

tính subfix_min[s][w]: w(u,v) >= w

subfix_min[s][w] = min(subfix_min[s][w], subfix_min[s][w+1])

## vậy kết quả là: min(dist[s], subfix_min[s][t0 + 1] + t0)

---

## Bài toán: Nâng Cấp Tuyến Đường

### Đề bài

Cho một đồ thị có hướng và có N đỉnh. Ta có M cạnh, cạnh thứ i nối uᵢ → vᵢ với trọng số wᵢ.

Ta có Q truy vấn, mỗi truy vấn gồm một đỉnh s và một giá trị t₀ với ý nghĩa:

Giả sử ta được phép thay đổi TỐI ĐA 1 cạnh trở thành trọng số t₀.

Hỏi: Độ dài đường đi ngắn nhất từ 1 → s là bao nhiêu?

### Phân tích

**Nhận xét:** 1 ≤ N ≤ 2000

Với mỗi truy vấn, vì ta chỉ tìm độ dài đường đi từ 1 → s:

1. Gọi Dijkstra xuất phát từ đỉnh 1, đặt dist[u] là độ dài đường đi ngắn nhất từ 1 → u
2. Với các đỉnh u từ 2 → N, gọi Dijkstra xuất phát từ u (trên đồ thị ngược), ta có bảng rev_dist[u][v] với ý nghĩa: rev_dist[u][v] là độ dài đường đi ngắn nhất từ u → v (trên đồ thị ngược)

### Thuật toán

#### Bước 1: Tiền xử lý

```cpp
// Tính dist[u]: khoảng cách từ đỉnh 1 đến u
vector<int> dist = dijkstra(1, graph);

// Tính rev_dist[s][v]: khoảng cách từ s đến v trên đồ thị ngược
vector<vector<int>> rev_dist(n+1);
for (int s = 1; s <= n; s++) {
    rev_dist[s] = dijkstra(s, reverse_graph);
}
```

#### Bước 2: Xử lý từng truy vấn

Với mỗi truy vấn s, t₀:

**Trường hợp 1:** Không sửa cạnh nào

- Độ dài đường đi ngắn nhất từ 1 → s = dist[s]

**Trường hợp 2:** Sửa một cạnh (u, v) từ trọng số w → t₀

- Cạnh (u, v) ta chỉ nên sửa nếu w > t₀
- Việc sửa chỉ có ý nghĩa nếu đường đi từ 1 → s có băng qua cạnh (u, v)
- Độ dài đường đi ngắn nhất từ 1 → s (CÓ BĂNG QUA CẠNH (u, v)):
  ```
  dist[u] + t₀ + rev_dist[s][v]
  ```

#### Bước 3: Tối ưu hóa với Suffix Minimum

Gọi minDist[s][w] là giá trị dist[u] + rev_dist[s][v] nhỏ nhất có thể với w(u,v) ≥ w.

```cpp
// Xây dựng bảng minDist
for (int s = 1; s <= n; s++) {
    vector<int> minDist(MAX_W + 1, INF);

    for (auto& edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        minDist[w] = min(minDist[w], dist[u] + rev_dist[s][v]);
    }

    // Tính suffix minimum
    for (int w = MAX_W - 1; w >= 0; w--) {
        minDist[w] = min(minDist[w], minDist[w + 1]);
    }
}

// Trả lời truy vấn
for (auto& query : queries) {
    int s = query.s, t0 = query.t0;
    int ans = min(dist[s], minDist[s][t0 + 1] + t0);
    cout << ans << endl;
}
```

**Kết quả:** min(dist[s], minDist[s][t₀ + 1] + t₀)

---

### Đề bài

Cho bàn cờ N×N: '.' là ô trống, 'R' là quân xe.

Hãy đặt chính xác K quân xe vào bàn cờ.

Liệu có thể có chính xác P cặp quân xe ăn nhau không? In "YES" hoặc "NO".

**Hình minh họa:** `Thang6/Buoi5/img/bai4.png`

### Phân tích

**Quy tắc ăn nhau:**

- Với một hàng i, nếu hàng i có x con xe → có x - 1 cặp ăn nhau
- Với một cột j, nếu cột j có y con xe → có y - 1 cặp ăn nhau

**Tổng số cặp ăn nhau:**

```
Tổng số cặp = Σ(row[i] - 1) + Σ(col[j] - 1)
           = Σrow[i] - (Số lượng hàng có số xe > 0) + Σcol[j] - (Số lượng cột có số xe > 0)
           = (Số lượng xe có sẵn) - (Số lượng hàng có số xe > 0) + (Số lượng xe có sẵn) - (Số lượng cột có số xe > 0)
           = 2 × placed - x₀ - y₀
```

Trong đó:

- placed: số lượng xe có sẵn
- x₀: số lượng hàng có số xe dương
- y₀: số lượng cột có số xe dương

### Thuật toán

Giả sử sau khi đặt thêm K xe, ta có số lượng hàng có xe > 0 là x, số lượng cột có xe > 0 là y.

**Số lượng cặp xe ăn nhau:** 2 × (placed + K) - x - y = P

**Bài toán đưa về:** Hãy tìm một bộ (x, y) thỏa mãn những điều kiện sau:

```cpp
// Điều kiện cần thiết
x + y = 2 × (placed + K) - P

// Ràng buộc
x ≥ x₀
y ≥ y₀
K ≥ max(x - x₀, y - y₀)

// Nếu x = 0 thì y = 0, nếu x > 0 thì y > 0
if (x == 0) y = 0;
if (x > 0) y > 0;

// Số xe không vượt quá số ô có thể đặt
placed + K ≤ x × y
```

### Cài đặt

```cpp
bool solve(int n, int k, int p, int placed, int x0, int y0) {
    for (int x = x0; x <= n; x++) {
        int y = 2 * (placed + k) - p - x;

        if (y < y0) continue;
        if (y > n) continue;

        // Kiểm tra điều kiện đặc biệt
        if (x == 0 && y != 0) continue;
        if (x > 0 && y == 0) continue;

        // Kiểm tra K hợp lệ
        if (k < max(x - x0, y - y0)) continue;

        // Kiểm tra số xe không vượt quá
        if (placed + k > x * y) continue;

        return true;
    }
    return false;
}
```

### Ví dụ

```
K = 4, P = 12, placed = 5, x₀ = 3, y₀ = 3
x + y = 2 × (5 + 4) - 12 = 6
⟹ x = 3, y = 3

Kết quả: YES
```
