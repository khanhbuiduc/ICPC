#include <iostream>
#include <fstream>
#include <queue> // Thêm thư viện queue tiêu chuẩn
using namespace std;

int main()
{
    // Mở tệp đầu ra
    ofstream outFile("output");

    // Tạo một queue các số nguyên
    queue<int> q;

    outFile << "Minh họa các thao tác trên queue:" << endl;
    outFile << "-------------------------------------" << endl;

    // Ví dụ về push
    outFile << "Thêm các phần tử: 10, 20, 30, 40, 50" << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Kiểm tra kích thước
    outFile << "Kích thước của queue: " << q.size() << endl;

    // Xem phần tử đầu và cuối
    outFile << "Phần tử ở đầu hàng đợi: " << q.front() << endl;
    outFile << "Phần tử ở cuối hàng đợi: " << q.back() << endl;

    // Thực hiện pop và kiểm tra phần tử đầu mới
    outFile << "Sau khi thực hiện pop: ";
    q.pop();
    outFile << "Phần tử đầu mới: " << q.front() << endl;

    // Kiểm tra xem có rỗng không
    outFile << "Queue có rỗng không? " << (q.empty() ? "Có" : "Không") << endl;

    // Làm rỗng queue
    outFile << "Thực hiện pop tất cả các phần tử:" << endl;
    while (!q.empty())
    {
        outFile << "Pop: " << q.front() << endl;
        q.pop();
    }

    // Kiểm tra lại xem có rỗng không
    outFile << "Queue có rỗng bây giờ không? " << (q.empty() ? "Có" : "Không") << endl;

    // Giải thích các phương thức chính của queue
    outFile << "\nCác phương thức chính của queue STL:" << endl;
    outFile << "1. push(element): Thêm phần tử vào cuối hàng đợi" << endl;
    outFile << "2. pop(): Loại bỏ phần tử ở đầu hàng đợi" << endl;
    outFile << "3. front(): Trả về phần tử ở đầu hàng đợi mà không loại bỏ nó" << endl;
    outFile << "4. back(): Trả về phần tử ở cuối hàng đợi" << endl;
    outFile << "5. empty(): Kiểm tra xem hàng đợi có rỗng không" << endl;
    outFile << "6. size(): Trả về số phần tử trong hàng đợi" << endl;

    outFile.close();
    cout << "Kết quả đã được lưu vào tệp output" << endl;

    return 0;
}
