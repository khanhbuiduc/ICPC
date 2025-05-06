#include <bits/stdc++.h>
using namespace std;
int n; // n<12
bool isInCol[13], isDiag1[26], isDiag2[26];
vector<int> curQueenSetX, curQueenSetY;
// hàm in kết quả
void printQueen()
{
    for (int i = 0; i < n; i++)
    {
        cout << curQueenSetX[i] << " " << curQueenSetY[i] << endl;
    }
    cout << "-----------------------------\n";
}
// hàm đệ quy
void genQueenSet(int r)
{
    // từng cột
    for (int c = 1; c <= n; c++)
    {
        // xác định đương chéo chính phụ//chính=row+col,phụ=row-col+13
        int curDiag1 = r + c;
        int curDiag2 = r - c + 13;
        // kiểm tra xem tọa độ mới có thỏa mãn không
        if (isInCol[c])
            continue;
        if (isDiag1[curDiag1])
            continue;
        if (isDiag2[curDiag2])
            continue;
        // nếu thỏa mãn lưu tọa độ
        curQueenSetX.push_back(r);
        curQueenSetY.push_back(c);
        isInCol[c] = true;
        isDiag1[curDiag1] = true;
        isDiag2[curDiag2] = true;
        // gọi hàm đệ quy quân tiếp theo hoặc in kết quả
        if (curQueenSetX.size() == n)
            printQueen();
        else
            genQueenSet(r + 1);
        // xóa quân vửa thêm khỏi tập hợp
        curQueenSetX.pop_back();
        curQueenSetY.pop_back();
        isInCol[c] = 0;
        isDiag1[curDiag1] = 0;
        isDiag2[curDiag2] = 0;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    genQueenSet(1);
    return 0;
}