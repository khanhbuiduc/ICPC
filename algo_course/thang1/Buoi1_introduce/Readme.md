# Lý thuyết

## Thuật toán là gì?

Thuật toán là tập hợp những bước giúp giải quyết một vấn đề, chuyển từ dữ liệu đầu vào (input) thành kết quả đầu ra (output).

## Độ phức tạp thuật toán

Độ phức tạp thuật toán là đại lượng dùng để so sánh hiệu quả giữa các thuật toán.

## Đại lượng Big O

Là thời gian xử lý tối đa của thuật toán trên một bộ dữ liệu đầu vào, dùng để đánh giá độ hiệu quả của thuật toán.

## Cấu trúc Vector trong C++

### Các hàm cơ bản:

- `pop_back()`: xóa phần tử cuối
- `push_back()`: thêm phần tử vào cuối
- `empty()`: kiểm tra rỗng
- `size()`: kích thước vector
- `resize()`: thay đổi kích thước
- `clear()`: xóa toàn bộ

### Sắp xếp mảng

```cpp
// Tăng dần từ index 3->7
sort(a+3, a+8);
// Giảm dần từ index 3->7
sort(a+3, a+8, greater<int>());
// Độ phức tạp: O(nlog(n))
```

# Các bài tập

## Vanya And Fence

**Đề bài:**

- Có N người bạn, người thứ i có chiều cao a[i]
- Hàng rào cao h
- Tìm tổng diện tích để N người không bị phát hiện
- Mỗi người chiếm diện tích:
  - 1 nếu cao ≤ h (đứng thẳng)
  - 2 nếu cao > h (cúi người)

**Ví dụ:**

```
N=8, h=6
a = [5, 9, 1, 2, 6, 3, 8, 7]
Kết quả: 1+2+1+1+1+1+2+2 = 11
```

## Fashion In Berland

**Đề bài:**
Áo hợp thời trang nếu:

- Áo nhiều nút: tất cả được cài, chỉ 1 nút hở
- Áo 1 nút: phải được cài

**Ví dụ:**

```
n=5
buttons = [1, 0, 1, 1, 1]
Kết quả: Yes
```

## Watermelon

**Đề bài:**
Chia dưa hấu nặng W kg thành 2 phần có trọng lượng chẵn?
Nếu có thì "Yes" nếu không thì "No"

**Ví dụ:**

```
w = 6
Kết quả: Yes
Giải thích: 2 + 4 hoặc 4 + 2

w = 11
Kết quả: No
```

**Thuật toán:**

```
Nếu w là số lẻ || w == 2
    in ra "No"
Ngược lại:
    in ra "Yes"
```

## New Year Transportation

**Thuật toán:**

```cpp
// Đặt p: vị trí mà ta đang đứng
p = 1
while (p < k) {
    p = p + a[p]
}
if (p == k)
    cout << "Yes"
else
    cout << "No"
```

## Three Square

**Đề bài:**
Cho hình chữ nhật có diện tích = m×n. Gạch có diện tích: a×a. Đặt gạch:

- Gạch song song với cạnh hình chữ nhật
- Có thể đè cạnh hình chữ nhật
- Tìm số viên tối thiểu

**Thuật toán:**

- Gọi `width` là số gạch ít nhất lát chiều rộng: `w = ⌈n/a⌉`
- Gọi `height` là số gạch ít nhất lát chiều dài: `h = ⌈m/a⌉`
- Đáp án: `h × w`
