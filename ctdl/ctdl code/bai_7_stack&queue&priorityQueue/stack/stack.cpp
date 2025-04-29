#include <iostream>
#include <fstream>
#include <stack> // Thêm thư viện stack tiêu chuẩn
using namespace std;

int main()
{
    // Mở tệp đầu ra
    ofstream outFile("output.txt");

    // Tạo một stack các số nguyên sử dụng thư viện chuẩn
    stack<int> st;

    outFile << "Minh họa các thao tác trên stack:" << endl;
    outFile << "-------------------------------------" << endl;

    // Ví dụ về push
    outFile << "Thêm các phần tử: 10, 20, 30, 40, 50" << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // Kiểm tra kích thước
    outFile << "Kích thước của stack: " << st.size() << endl;

    // Xem phần tử đỉnh
    outFile << "Phần tử ở đỉnh: " << st.top() << endl;

    // Thực hiện pop và kiểm tra phần tử đỉnh mới
    outFile << "Sau khi thực hiện pop: ";
    st.pop();
    outFile << "Phần tử đỉnh mới: " << st.top() << endl;

    // Kiểm tra xem có rỗng không
    outFile << "Stack có rỗng không? " << (st.empty() ? "Có" : "Không") << endl;

    // Làm rỗng stack
    outFile << "Thực hiện pop tất cả các phần tử:" << endl;
    while (!st.empty())
    {
        outFile << "Pop: " << st.top() << endl;
        st.pop();
    }

    // Kiểm tra lại xem có rỗng không
    outFile << "Stack có rỗng bây giờ không? " << (st.empty() ? "Có" : "Không") << endl;

    // Ví dụ về stack chuỗi
    outFile << "\nVí dụ về stack với chuỗi:" << endl;
    stack<string> strStack;
    strStack.push("Xin");
    strStack.push("chào");
    strStack.push("thế giới");
    strStack.push("Stack");

    outFile << "Kích thước: " << strStack.size() << endl;
    outFile << "Phần tử ở đỉnh: " << strStack.top() << endl;

    outFile << "Các phần tử (từ trên xuống dưới):" << endl;
    while (!strStack.empty())
    {
        outFile << strStack.top() << endl;
        strStack.pop();
    }

    // Giải thích các phương thức chính của stack
    outFile << "\nCác phương thức chính của stack STL:" << endl;
    outFile << "1. push(element): Thêm phần tử vào đỉnh stack" << endl;
    outFile << "2. pop(): Loại bỏ phần tử ở đỉnh stack" << endl;
    outFile << "3. top(): Trả về phần tử ở đỉnh mà không loại bỏ nó" << endl;
    outFile << "4. empty(): Kiểm tra xem stack có rỗng không" << endl;
    outFile << "5. size(): Trả về số phần tử trong stack" << endl;

    outFile.close();
    cout << "Kết quả đã được lưu vào tệp output.txt" << endl;

    return 0;
}
