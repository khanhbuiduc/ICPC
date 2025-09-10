# Bài 6: Lý Thuyết Trò Chơi

## Khái niệm cơ bản

Lý thuyết trò chơi là một ngành trong toán học chuyên dùng để nghiên cứu những trò chơi mang tính đối kháng khi có sự tham gia giữa 2 người chơi với nhau.

**Giả định quan trọng:**

- Cả 2 người đều chơi được những nước tối ưu
- Cả 2 người đều tìm cách đưa đối thủ vào trạng thái thua

## Bài toán: Stones

### Đề bài

Có K viên đá và có N giá trị a[1], a[2], ..., a[N].

Có 2 người chơi trò chơi bốc đá. Với người hiện tại, người đó sẽ chọn một con số x (x = a[i]) và bốc đúng x viên đá ra khỏi đống. Người nào không bốc được thì người đó thua.

Hỏi ai là người chiến thắng? In ra "First" nếu người đầu tiên chiến thắng, "Second" nếu người thứ 2 chiến thắng. Biết cả 2 người đều chơi với chiến thuật tối ưu nhất có thể.

### Thuật toán

**Xét từ cuối đẩy lại:**

Gọi f[i] là khả năng thắng - thua khi có người chơi vào trạng thái gồm i viên sỏi.

**Bài toán cơ sở:** f[0] = 0

**Đáp án bài toán:**

- f[K] == 1 ⟹ First
- f[K] == 0 ⟹ Second

**Công thức QHĐ:**
Giả sử người hiện tại bốc x viên sỏi: i → i - x

```cpp
if (tồn tại f[i - x] == 0) then f[i] = 1
else f[i] = 0
```

## Bài toán: Parigame

### Đề bài

Cho một bảng hình vuông gồm N hàng N cột. 2 người sẽ chơi trò chơi xóa bảng. Với mỗi lượt chơi, người hiện tại chỉ được phép xóa hàng cuối cùng hoặc cột cuối cùng nếu tổng các số trên hàng đó hoặc cột đó là số chẵn. Người nào không tiếp tục thực hiện được thì người đó thua.

Hỏi người chơi đầu tiên có thắng hay không?

### Thuật toán

Gọi f[i][j] là trạng thái thắng hoặc thua khi người hiện tại chơi vào bảng có i hàng và j cột.

**Đáp án bài toán:**

- f[N][N] == 1: YES
- f[N][N] == 0: NO

**Công thức QHĐ:**

**Nếu xóa hàng i:**

- Tổng các số trên hàng i (a[i][1] + a[i][2] + ... + a[i][j]) phải là số chẵn
- Nếu tổng các số trên hàng i là số chẵn và f[i-1][j] == 0: f[i][j] = 1

**Nếu xóa cột j:**

- Nếu tổng các số trên cột j là số chẵn và f[i][j-1] == 0: f[i][j] = 1

## Bài toán SPC4 (Spring Contest 2020)

### Đề bài

Có N lá bài, lá bài thứ i có giá trị là a[i]. 2 người chơi là K và T, người K có K lá "addition", người T có T lá "addition".

Với mỗi lượt chơi, người hiện tại BUỘC phải bốc 1 lá, nếu giả sử trong tay người này có x lá addition, người này có quyền bốc thêm y lá bài nữa (0 ≤ y ≤ x).

Tổng điểm của 1 người sẽ là tổng điểm của các lá bài mà người đó bốc.

Hỏi kết quả của trò chơi là Thắng (nếu K chiến thắng), Hòa nếu 2 người bằng điểm nhau hoặc Thua nếu (số điểm của K < số điểm của T).

### Thuật toán

Gọi f[i][a][b] là tổng điểm lớn nhất có thể khi có i lá bài đầu tiên và số lượng lá addition mà người hiện tại đang có là a và người đối thủ đang có b lá addition.

**Bài toán cơ sở:** f[0][a][b] = 0

**Đáp án bài toán:**

- Số điểm mà K có được: f[N][K][T]
- Số điểm mà T có được: a[1] + a[2] + ... + a[N] - f[N][K][T]

**Công thức QHĐ:**
Giả sử người hiện tại bốc x lá (x: 0 → min(a, i - 1))

Trạng thái: (i, a, b) → (i - x - 1, b, a - x)

```cpp
f[i][a][b] = Max(a[1] + a[2] + ... + a[i] - f[i - x - 1][b][a - x])
```

## Bài toán SC4 (Summer Contest 2019)

### Đề bài

Có 2 người A và B chơi trò chơi bốc hạt dẻ. Trong đống hạt dẻ hiện tại có N hạt và 2 người chơi lần lượt với nhau. Mỗi lượt chơi, người hiện tại sẽ bốc x hạt dẻ (1 ≤ x ≤ M).

Khi một người bốc hạt dẻ, người này sẽ bỏ hạt dẻ vào một tô hiện tại của người đó. Khi một người bốc được hạt dẻ cuối cùng thì người đó sẽ ăn toàn bộ hạt dẻ có trong tô. Người còn lại sẽ phải đổ hạt dẻ vào lại đống và trò chơi bắt đầu lại từ người vừa đổ vào.

Hỏi: Người đầu tiên có thể ăn tối đa bao nhiêu hạt dẻ nếu cả 2 người đều chơi với chiến thuật tối ưu?

### Ví dụ

N = 5, M = 2

```
Tô A: 3 ⟹ ăn 3 hạt
Tô B: 2

Người A ăn 3 hạt
Người B ăn 2 hạt
```

**Giới hạn dữ liệu:** 1 ≤ N ≤ 100

### Phân tích đặc biệt

**Xét tình huống M ≥ N/2:**

- Đáp án là N (người đầu tiên có thể lấy hết)

**Tình huống ngược lại: M < N/2**

### Thuật toán (Cách 1)

Gọi f[i][a][b] là tổng lượng hạt dẻ tối đa mà người hiện tại có thể bốc được khi đang có i hạt dẻ, tô của người hiện tại có a hạt và tô của người đối thủ có b hạt.

**Bài toán cơ sở:** f[0][0][0] = 0, khởi tạo f[i][a][b] = -1

**Đáp án bài toán:** f[N][0][0]

**Công thức QHĐ:**

**Tình huống 1:** Nếu a + b = i

```cpp
f[i][a][b] = f[a][0][0]
```

**Tình huống 2:** Nếu a + b < i
Giả sử ta bốc x hạt (1 ≤ x ≤ min(M, i - a - b))
Trạng thái: (i, a, b) → (i, b, a + x)

```cpp
f[i][a][b] = Max(i - f[i][b][a + x])
```

**Algorithm:**

```cpp
for i: 1 -> N
    for a: 0 -> i
        for b: 0 -> i - a
            if (a + b == i):
                f[i][a][b] = f[a][0][0]
            else:
                for x: 1 -> min(M, i - a - b)
                    f[i][a][b] = max(f[i][a][b], i - f[i][b][a + x])
```

### Thuật toán (Cách 2 - Tối ưu)

Gọi f[i][a][b] là tổng lượng hạt dẻ người hiện tại có thể ăn được khi hiện tại có i hạt dẻ, tô của người hiện tại có a hạt và tổng hạt dẻ của cả 2 tô là b.

⟹ Số hạt dẻ trong tô của đối thủ là b - a (0 ≤ a ≤ b ≤ i)

**Bài toán cơ sở:** f[0][0][0] = 0

**Đáp án bài toán:** f[N][0][0]

**Công thức QHĐ:**

**Tình huống 1:** b = i

```cpp
f[i][a][b] = f[a][0][0]
```

**Tình huống 2:** b < i
Giả sử người hiện tại bốc x hạt (1 ≤ x ≤ min(M, i - b))

```cpp
f[i][a][b] = Max(i - f[i][b - a][b + x])
```

**Algorithm:**

```cpp
for i: 1 -> N
    for b: i -> 0
        for a: 0 -> b
            if (b == i):
                f[i][a][b] = f[a][0][0]
            else:
                for x: 1 -> min(M, i - b)
                    f[i][a][b] = max(f[i][a][b], i - f[i][b - a][b + x])
```
