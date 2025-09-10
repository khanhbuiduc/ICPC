# Đệ quy và Quay lui (Recursion & Backtracking)

## Nguyên tắc thiết kế hàm đệ quy

1. **Định nghĩa rõ mục đích** của hàm đệ quy
2. **Xác định trường hợp biên** ("điểm dừng")
3. **Tìm mối liên hệ** giữa bài toán hiện tại và bài toán con (giả sử bài toán con đã được giải đúng)

---

## 1. Luy thừa

**Bài toán:** Tính 2^N

**Thiết kế hàm:** `power2(N)` trả về giá trị 2^N

```cpp
int power2(int N) {
    if (N == 0) return 1;        // Trường hợp biên
    else return power2(N-1) * 2; // Gọi đệ quy
}
```

---

## 2. Tìm giá trị lớn nhất

**Bài toán:** Cho mảng `a = [5,1,2,3,4,5,3,5]`, tìm phần tử lớn nhất

**Thiết kế hàm:** `findMax(n)` trả về giá trị lớn nhất trong N phần tử đầu tiên

```cpp
int findMax(int n) {
    if (n == 1) return a[0];                    // Trường hợp biên
    else return max(findMax(n-1), a[n-1]);     // So sánh với phần tử cuối
}
```

---

## 3. In hình sao

**Bài toán:** Cho số N, in N dòng sao, dòng thứ i có i ngôi sao

**Ví dụ với N=5:**

```
*
**
***
****
*****
```

**Thiết kế hàm:** `printStar(N)` in N-1 dòng trước, sau đó in N ngôi sao

```cpp
void printStar(int N) {
    if (N == 0) return;           // Trường hợp biên

    printStar(N-1);               // In N-1 dòng trước

    for (int i = 0; i < N; i++) { // In N ngôi sao
        cout << "* ";
    }
    cout << endl;
}
```

---

## 4. Tạo chuỗi từ các ký tự

**Bài toán:** Cho chuỗi "aabac", tạo tất cả các hoán vị có thể

**Thuật toán:**

- Dùng mảng `count[]` để đếm số lượng từng ký tự
- Đệ quy để điền từng vị trí

```cpp
string st;
int count[26]; // Đếm số lượng từng chữ cái

void createString(int position, int n) {
    if (position == n) {
        cout << st << endl;
        return;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (count[c - 'a'] > 0) {
            st[position] = c;
            count[c - 'a']--;

            createString(position + 1, n);

            count[c - 'a']++; // Backtrack
        }
    }
}
```

---

## 5. Liệt kê hoán vị

**Bài toán:** Cho dãy [1,2,3], liệt kê tất cả hoán vị: [1,2,3], [1,3,2], [2,1,3], ...

**Thuật toán Backtracking:**

```cpp
vector<int> a = {1, 2, 3};
vector<int> permutation;
vector<bool> used;

void generatePermutation(int position, int n) {
    if (position == n) {
        // In hoán vị hiện tại
        for (int x : permutation) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            permutation[position] = a[i];
            used[i] = true;

            generatePermutation(position + 1, n);

            used[i] = false; // Backtrack
        }
    }
}
```

**Độ phức tạp:** O(N × N!)

---

## 6. Liệt kê tập con

**Bài toán:** Cho tập [1,2,3], liệt kê tất cả tập con: [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

**Thuật toán:**

```cpp
vector<int> a = {1, 2, 3};
vector<int> subset;

void generateSubset(int position, int n) {
    if (position == n) {
        // In tập con hiện tại
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
        return;
    }

    // Lựa chọn 1: Không chọn phần tử thứ position
    generateSubset(position + 1, n);

    // Lựa chọn 2: Chọn phần tử thứ position
    subset.push_back(a[position]);
    generateSubset(position + 1, n);
    subset.pop_back(); // Backtrack
}
```

**Độ phức tạp:** O(2^N)

---

## Tóm tắt Backtracking

**Backtracking** là một kỹ thuật để tìm tất cả (hoặc một số) lời giải của bài toán bằng cách:

1. **Thử** từng lựa chọn có thể
2. **Đệ quy** để giải quyết bài toán con
3. **Hoàn tác** (backtrack) nếu lựa chọn không dẫn đến lời giải

**Template cơ bản:**

```cpp
void backtrack(int position) {
    if (position == target) {
        // Xử lý lời giải
        return;
    }

    for (each choice) {
        if (valid choice) {
            make choice;
            backtrack(position + 1);
            undo choice; // Backtrack
        }
    }
}
```
