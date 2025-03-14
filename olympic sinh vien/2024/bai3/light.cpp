#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int STEP = 62;
const int dx[3] = {1, 0, -1}; // Di chuyển theo hướng xuống, ngang phải, và chéo lên trái.
const int dy[3] = {0, 1, -1}; // Tương ứng với dx để di chuyển trên lưới.

const int MAX = 555;
int n, k;
bool blocked[MAX * MAX / 2]; // Đánh dấu các ô bị chặn.
bool ok[MAX][MAX];           // Đánh dấu các ô không bị chặn.
long long mask[MAX][MAX][3]; // Lưu trữ thông tin bitmask cho các hướng di chuyển.

void init()
{
    cin >> n >> k; // Nhập số hàng của tam giác và số lượng ô bị chặn.

    // Đọc vào các ô bị chặn và đánh dấu chúng.
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        blocked[x] = true;
    }

    // Đánh dấu các ô không bị chặn trong tam giác.
    int cell_number = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cell_number++;
            ok[i][j] = !blocked[cell_number]; // Nếu không bị chặn thì đánh dấu là true.
        }
    }
}

// Kiểm tra xem ô (x, y) có nằm trong tam giác hay không.
bool inside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= x;
}

void process()
{
    // Duyệt qua tất cả các ô và xây dựng bitmask cho các hướng di chuyển.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int direction = 0; direction < 3; direction++)
            {
                for (int step = 0; step < STEP; step++)
                {
                    int newX = i + dx[direction] * step;
                    int newY = j + dy[direction] * step;
                    if (!inside(newX, newY))
                        break; // Nếu vượt ra ngoài tam giác thì dừng lại.
                    if (ok[newX][newY])
                    {
                        mask[i][j][direction] |= (1LL << step); // Đánh dấu ô hợp lệ trong bitmask.
                    }
                }
            }
        }
    }

    long long result = 0;

    // Tính toán số tam giác nhỏ hợp lệ.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int r = 1; r <= n - i; r++)
            { // r là bán kính của tam giác nhỏ.
                int x[3], y[3];

                // Tọa độ của đỉnh tam giác nhỏ.
                x[0] = i;
                y[0] = j;

                // Di chuyển xuống dưới.
                x[1] = x[0] + dx[0] * r;
                y[1] = y[0] + dy[0] * r;

                // Di chuyển ngang sang phải.
                x[2] = x[1] + dx[1] * r;
                y[2] = y[1] + dy[1] * r;

                int remaining_steps = r;

                // Kiểm tra từng bước nhỏ trong giới hạn STEP.
                while (remaining_steps > 0)
                {
                    long long tempMask = (1LL << min(remaining_steps, STEP)) - 1;

                    // Lấy giao các bitmask của ba cạnh tam giác.
                    for (int t = 0; t < 3; t++)
                    {
                        tempMask &= mask[x[t]][y[t]][t];
                    }

                    // Đếm số bit 1 (số tam giác hợp lệ).
                    result += __builtin_popcountll(tempMask);

                    remaining_steps -= STEP;

                    // Cập nhật tọa độ cho bước tiếp theo.
                    for (int t = 0; t < 3; t++)
                    {
                        x[t] += dx[t] * STEP;
                        y[t] += dy[t] * STEP;
                    }
                }
            }
        }
    }

    cout << result << endl;
}

int main()
{
    init();    // Khởi tạo dữ liệu.
    process(); // Xử lý và xuất kết quả.
    return 0;
}
