# Bài 6: Các Thuật Toán Tổng Hợp

## Bài toán 1: PalindromeReorder

### Đề bài

Cho dãy s: "AFFFBCACBZZTFUU"

Sắp xếp lại thành dãy đối xứng.

### Thuật toán

```cpp
string palindromeReorder(string s) {
    // Đếm số lượng từng chữ cái
    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'A']++;
    }

    // Kiểm tra điều kiện tạo palindrome
    int oddCount = 0;
    char oddChar = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    // Nếu có hơn 1 chữ cái có số lượng lẻ thì không thể tạo palindrome
    if (oddCount > 1) {
        return "NO";
    }

    // Xây dựng nửa đầu của palindrome
    string tempS = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            tempS += ('A' + i);
        }
    }

    // Kết quả: tempS + oddChar + reverse(tempS)
    string result = tempS;
    if (oddCount == 1) {
        result += oddChar;
    }
    reverse(tempS.begin(), tempS.end());
    result += tempS;

    return result;
}
```

## Bài toán 2: ReachableNodes

### Đề bài

N đỉnh, M cạnh có hướng.

Đếm xem từ mỗi đỉnh có thể đến bao nhiêu đỉnh khác.

**Hình minh họa:** `Thang6/Buoi6/img/bai2_1.png`

### Thuật toán

**Sử dụng DFS và Bitset:**

```cpp
bitset<MAXN> go_to[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    go_to[u].set(u, 1); // Đỉnh u có thể đến chính nó

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
        go_to[u] |= go_to[v]; // Hợp các đỉnh có thể đến từ v
    }
}

int main() {
    // Đọc input và xây dựng đồ thị

    // DFS từ tất cả các đỉnh chưa thăm
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // In kết quả
    for (int i = 1; i <= n; i++) {
        cout << go_to[i].count() << "\n";
    }

    return 0;
}
```

**Ý tưởng:**

- Ban đầu: go_to[u].set(u, 1)
- Nếu v kề u thì: go_to[u] |= go_to[v]

## Bài toán 3: ComNet

### Đề bài

Có N đỉnh, M cạnh (uᵢ, vᵢ, wᵢ) 2 chiều.

**Định nghĩa:**

- **Thông suốt:** Từ 1 đỉnh có thể đi đến các đỉnh còn lại (có thể qua trung gian)
- **Cạnh không tiềm năng:** Không thuộc cây khung nhỏ nhất

**Câu hỏi:** Cạnh k có tiềm năng không?

**Query:** Cạnh k, cạnh j có chi phí mới cⱼ.

**Hình minh họa:** `Thang6/Buoi6/img/bai3_1.png`

### Thuật toán

**Ý tưởng:** Sử dụng thuật toán Kruskal tìm cây khung nhỏ nhất với w < k.

```cpp
bool isPotential(int k, vector<Edge>& edges) {
    // Sắp xếp các cạnh theo trọng số
    sort(edges.begin(), edges.end());

    UnionFind uf(n);

    // Thêm các cạnh có trọng số < k
    for (Edge& e : edges) {
        if (e.weight >= k) break;
        uf.unite(e.u, e.v);
    }

    // Kiểm tra xem cạnh k(u,v) đã được kết nối chưa
    Edge edgeK = edges[k];
    if (uf.connected(edgeK.u, edgeK.v)) {
        return false; // Không tiềm năng
    } else {
        return true; // Có tiềm năng
    }
}
```

**Lưu ý:** Bài gốc sử dụng cin/cout bị TLE → sử dụng scanf/printf.

## Bài toán SPC5 (Spring Contest 2021)

### Đề bài

Cho chuỗi: "T_T_T****\*\*****\_****\*\*****T\***\*\_\*\***T**\_\_\_**T"

Một mặt buồn được xây dựng như thế nào?

### Phân tích

**Cấu trúc mặt buồn:**

- Mắt: 'T'
- Miệng: '\_'
- Cấu trúc: T_T (mắt-miệng-mắt)

### Thuật toán Dynamic Programming

Gọi f[i][oneEye][eyeAndMouth] là số cách có thể xây dựng được khi có i ký tự đầu tiên:

- **oneEye:** số lượng mắt đơn lẻ (chưa ghép thành cặp)
- **eyeAndMouth:** số lượng cặp mắt-miệng đã hoàn thành

**Bài toán cơ sở:** f[0][0][0] = 1

**Đáp án bài toán:** f[n][0][0]

### Công thức QHĐ

Khi ta có f[i][oneEye][eyeAndMouth] > 0, xét ký tự thứ i + 1:

#### Tình huống 1: s[i + 1] = 'T'

**Trường hợp 1a:** Bổ sung vào tập oneEye thêm 1 phần tử

```cpp
f[i + 1][oneEye + 1][eyeAndMouth] += f[i][oneEye][eyeAndMouth]
```

**Trường hợp 1b:** Ghép 'T' vào 1 phần tử của tập eyeAndMouth (eyeAndMouth > 0)

```cpp
f[i + 1][oneEye][eyeAndMouth - 1] += eyeAndMouth * f[i][oneEye][eyeAndMouth]
```

#### Tình huống 2: s[i + 1] = '\_'

**Trường hợp 2a:** Thêm dấu '\_' vào 1 con mắt tự do (oneEye > 0)

```cpp
f[i + 1][oneEye - 1][eyeAndMouth + 1] += oneEye * f[i][oneEye][eyeAndMouth]
```

**Trường hợp 2b:** Thêm dấu '\_' vào 1 phần tử trong tập eyeAndMouth (eyeAndMouth > 0)

```cpp
f[i + 1][oneEye][eyeAndMouth] += eyeAndMouth * f[i][oneEye][eyeAndMouth]
```

### Cài đặt

```cpp
int n = s.length();
long long f[n + 1][n + 1][n + 1];
memset(f, 0, sizeof(f));

f[0][0][0] = 1;

for (int i = 0; i < n; i++) {
    for (int oneEye = 0; oneEye <= n; oneEye++) {
        for (int eyeAndMouth = 0; eyeAndMouth <= n; eyeAndMouth++) {
            if (f[i][oneEye][eyeAndMouth] == 0) continue;

            if (s[i] == 'T') {
                // Tạo mắt mới
                f[i + 1][oneEye + 1][eyeAndMouth] += f[i][oneEye][eyeAndMouth];

                // Hoàn thành cặp mắt-miệng
                if (eyeAndMouth > 0) {
                    f[i + 1][oneEye][eyeAndMouth - 1] += eyeAndMouth * f[i][oneEye][eyeAndMouth];
                }
            } else { // s[i] == '_'
                // Tạo miệng cho mắt đơn lẻ
                if (oneEye > 0) {
                    f[i + 1][oneEye - 1][eyeAndMouth + 1] += oneEye * f[i][oneEye][eyeAndMouth];
                }

                // Mở rộng miệng đã có
                if (eyeAndMouth > 0) {
                    f[i + 1][oneEye][eyeAndMouth] += eyeAndMouth * f[i][oneEye][eyeAndMouth];
                }
            }
        }
    }
}

cout << f[n][0][0] << endl;
```
