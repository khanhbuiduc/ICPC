#include <bits/stdc++.h>
using namespace std;

// Hàm in thông tin về một nhóm hàm
void printGroupInfo(const string &groupName, const string &description)
{
    cout << "\n===== " << groupName << " =====" << endl;
    cout << description << endl;
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> v;

    // NHÓM 1: KHỞI TẠO VÀ NHẬP VECTOR
    printGroupInfo("KHỞI TẠO VÀ NHẬP VECTOR",
                   "Các cách khởi tạo vector và nhập dữ liệu vào vector\n"
                   "Độ phức tạp: Khởi tạo - O(n), push_back - O(1) trung bình");

    // Vector với kích thước và giá trị cụ thể - Độ phức tạp: O(n)
    vector<int> v1(5, 10);         // 5 phần tử, mỗi phần tử có giá trị 10
    vector<int> v2{1, 2, 3, 4, 5}; // Khởi tạo với initializer list

    // Sao chép từ vector khác - Độ phức tạp: O(n)
    vector<int> v3(v2.begin(), v2.end());       // Sao chép toàn bộ v2
    vector<int> v4(v2.begin(), v2.begin() + 3); // Sao chép 3 phần tử đầu tiên của v2

    // Nhập từ input - push_back: Độ phức tạp trung bình O(1), tổng cộng O(n)
    int x;
    while (cin >> x)
    {
        v.push_back(x); // Amortized O(1)
    }

    // NHÓM 2: TRUY CẬP PHẦN TỬ
    printGroupInfo("TRUY CẬP PHẦN TỬ",
                   "Các cách để truy cập phần tử trong vector\n"
                   "Độ phức tạp: Truy cập trực tiếp - O(1), Duyệt - O(n)");

    // Truy cập trực tiếp - Độ phức tạp: O(1)
    cout << "First element (front): " << v.front() << endl; // O(1)
    cout << "Last element (back): " << v.back() << endl;    // O(1)
    cout << "Element at index 2 (at): " << v.at(2) << endl; // O(1) với kiểm tra biên
    cout << "Element at index 2 ([]): " << v[2] << endl;    // O(1) không kiểm tra biên

    // Truy cập bằng iterator - Độ phức tạp: O(n)
    cout << "Elements using iterators: ";
    for (auto it = v.begin(); it != v.end(); ++it) // O(n)
    {
        cout << *it << " "; // O(1)
    }
    cout << endl;

    // Truy cập bằng reverse iterator - Độ phức tạp: O(n)
    cout << "Elements in reverse using reverse iterators: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) // O(n)
    {
        cout << *it << " "; // O(1)
    }
    cout << endl;

    // NHÓM 3: THÔNG TIN KÍCH THƯỚC VÀ DUNG LƯỢNG
    printGroupInfo("KÍCH THƯỚC VÀ DUNG LƯỢNG",
                   "Các hàm kiểm tra kích thước và dung lượng của vector\n"
                   "Độ phức tạp: Hầu hết đều là O(1)");

    // Kiểm tra kích thước - Độ phức tạp: O(1)
    cout << "Size: " << v.size() << endl;                       // O(1)
    cout << "Capacity: " << v.capacity() << endl;               // O(1)
    cout << "Max size: " << v.max_size() << endl;               // O(1)
    cout << "Is empty: " << (v.empty() ? "Yes" : "No") << endl; // O(1)

    // Thay đổi dung lượng
    v.reserve(100); // Đảm bảo vector có thể chứa tối thiểu 100 phần tử - Độ phức tạp: O(n) nếu cần tái cấp phát
    cout << "After reserve(100), capacity: " << v.capacity() << endl;

    v.shrink_to_fit(); // Giảm capacity về bằng size - Độ phức tạp: O(n)
    cout << "After shrink_to_fit, capacity: " << v.capacity() << endl;

    // NHÓM 4: THÊM VÀ XÓA PHẦN TỬ
    printGroupInfo("THÊM VÀ XÓA PHẦN TỬ",
                   "Các hàm thêm và xóa phần tử trong vector\n"
                   "Độ phức tạp: Thêm/xóa cuối - O(1) trung bình, Thêm/xóa đầu/giữa - O(n)");

    // Thêm phần tử
    v.push_back(100);                              // Thêm vào cuối - Amortized O(1)
    v.insert(v.begin(), 10);                       // Thêm vào đầu - O(n)
    v.insert(v.begin() + 2, 20);                   // Thêm vào vị trí thứ 2 - O(n)
    v.insert(v.begin() + 3, 3, 30);                // Thêm 3 phần tử giá trị 30 vào vị trí thứ 3 - O(n)
    v.insert(v.begin() + 5, v2.begin(), v2.end()); // Chèn vector khác - O(n+m) với m là kích thước v2

    // Xóa phần tử
    v.pop_back(); // Xóa phần tử cuối cùng - O(1)

    if (!v.empty())
    {
        v.erase(v.begin()); // Xóa phần tử đầu tiên - O(n)
    }

    if (v.size() > 5)
    {
        v.erase(v.begin() + 2, v.begin() + 5); // Xóa phần tử từ vị trí 2 đến 4 - O(n)
    }

    // Thay đổi kích thước
    v.resize(10);      // Thay đổi kích thước thành 10 - O(n) nếu mở rộng, O(1) nếu thu nhỏ
    v.resize(15, 100); // Tăng kích thước lên 15, giá trị mới 100 - O(n) nếu mở rộng

    // Xóa tất cả
    vector<int> temp = v; // Lưu lại vector trước khi xóa - O(n)
    v.clear();            // Xóa tất cả phần tử - O(n)
    cout << "After clear, size: " << v.size() << endl;
    v = temp; // Khôi phục vector - O(n)

    // NHÓM 5: SẮP XẾP VÀ TÌM KIẾM
    printGroupInfo("SẮP XẾP VÀ TÌM KIẾM",
                   "Các hàm sắp xếp và tìm kiếm trong vector\n"
                   "Độ phức tạp: Sắp xếp - O(n log n), Tìm kiếm tuyến tính - O(n), Tìm kiếm nhị phân - O(log n)");

    // Sắp xếp tăng dần - Độ phức tạp: O(n log n)
    sort(v.begin(), v.end()); // O(n log n)
    cout << "After ascending sort: ";
    for (int i = 0; i < min(5, (int)v.size()); i++)
    {
        cout << v[i] << " ";
    }
    cout << "..." << endl;

    // Sắp xếp giảm dần - Độ phức tạp: O(n log n)
    sort(v.begin(), v.end(), greater<int>()); // Cách 1 - O(n log n)
    sort(v.rbegin(), v.rend());               // Cách 2 - O(n log n)
    cout << "After descending sort: ";
    for (int i = 0; i < min(5, (int)v.size()); i++)
    {
        cout << v[i] << " ";
    }
    cout << "..." << endl;

    // Tìm kiếm nhị phân (yêu cầu vector đã sắp xếp) - Độ phức tạp: O(log n)
    sort(v.begin(), v.end());                            // Sắp xếp lại tăng dần - O(n log n)
    bool exists = binary_search(v.begin(), v.end(), 20); // O(log n)
    cout << "20 exists in vector: " << (exists ? "Yes" : "No") << endl;

    // Tìm vị trí phần tử đầu tiên lớn hơn hoặc bằng x - Độ phức tạp: O(log n)
    auto lower = lower_bound(v.begin(), v.end(), 20); // O(log n)
    if (lower != v.end())
    {
        cout << "First element >= 20 is at position: " << (lower - v.begin()) << endl;
    }

    // Tìm vị trí phần tử đầu tiên lớn hơn x - Độ phức tạp: O(log n)
    auto upper = upper_bound(v.begin(), v.end(), 20); // O(log n)
    if (upper != v.end())
    {
        cout << "First element > 20 is at position: " << (upper - v.begin()) << endl;
    }

    // Tìm một phần tử bất kỳ - Độ phức tạp: O(n)
    auto it = find(v.begin(), v.end(), 2); // O(n)
    if (it != v.end())
    {
        cout << "Found 2 at position: " << (it - v.begin()) << endl;
    }

    // NHÓM 6: THUẬT TOÁN KHÁC
    printGroupInfo("THUẬT TOÁN KHÁC",
                   "Các thuật toán hữu ích khác với vector\n"
                   "Độ phức tạp: Đa số là O(n) hoặc O(n log n)");

    // Đảo ngược thứ tự - Độ phức tạp: O(n)
    reverse(v.begin(), v.end()); // O(n)

    // Đếm số lần xuất hiện - Độ phức tạp: O(n)
    int count2 = count(v.begin(), v.end(), 2); // O(n)
    cout << "Number of 2s: " << count2 << endl;

    // Tìm phần tử min và max - Độ phức tạp: O(n)
    auto minmax = minmax_element(v.begin(), v.end()); // O(n)
    cout << "Min: " << *minmax.first << ", Max: " << *minmax.second << endl;

    // Tính tổng - Độ phức tạp: O(n)
    int sum = accumulate(v.begin(), v.end(), 0); // O(n)
    cout << "Sum of all elements: " << sum << endl;

    // Tìm phần tử riêng biệt - Độ phức tạp: O(n log n) vì cần sắp xếp trước
    sort(v.begin(), v.end());               // O(n log n)
    auto last = unique(v.begin(), v.end()); // O(n)
    int unique_count = last - v.begin();
    cout << "Number of unique elements: " << unique_count << endl;

    // Xoay vòng vector - Độ phức tạp: O(n)
    rotate(v.begin(), v.begin() + 3, v.end()); // O(n)

    // Trộn ngẫu nhiên - Độ phức tạp: O(n)
    random_shuffle(v.begin(), v.end()); // O(n)

    // NHÓM 7: DUYỆT VECTOR
    printGroupInfo("DUYỆT VECTOR",
                   "Các cách duyệt qua các phần tử trong vector\n"
                   "Độ phức tạp: Đều là O(n)");

    // Duyệt với chỉ số - Độ phức tạp: O(n)
    cout << "Using index: ";
    for (int i = 0; i < min(5, (int)v.size()); i++) // O(n)
    {
        cout << v[i] << " "; // O(1)
    }
    cout << "..." << endl;

    // Duyệt với iterator - Độ phức tạp: O(n)
    cout << "Using iterator: ";
    int count = 0;
    for (auto it = v.begin(); it != v.end() && count < 5; ++it, ++count) // O(n)
    {
        cout << *it << " "; // O(1)
    }
    cout << "..." << endl;

    // Duyệt với range-based for - Độ phức tạp: O(n)
    cout << "Using range-based for: ";
    count = 0;
    for (int num : v) // O(n)
    {
        if (count++ >= 5)
            break;
        cout << num << " "; // O(1)
    }
    cout << "..." << endl;

    // NHÓM 8: HOÁN ĐỔI VÀ GÁN
    printGroupInfo("HOÁN ĐỔI VÀ GÁN",
                   "Các thao tác hoán đổi và gán giữa các vector\n"
                   "Độ phức tạp: Swap - O(1), Các thao tác gán - O(n)");

    // Hoán đổi hai vector - Độ phức tạp: O(1) - chỉ đổi con trỏ nội bộ
    vector<int> v5 = {100, 200, 300};
    cout << "Before swap - v5[0]: " << v5[0] << ", v[0]: " << v[0] << endl;
    v.swap(v5); // O(1)
    cout << "After swap - v5[0]: " << v5[0] << ", v[0]: " << v[0] << endl;

    // Gán lại vector - Độ phức tạp: O(n)
    v = vector<int>{1, 2, 3, 4, 5}; // O(n)
    cout << "After reassign, v size: " << v.size() << endl;

    // Gán giá trị cho tất cả phần tử - Độ phức tạp: O(n)
    fill(v.begin(), v.end(), 7); // O(n)
    cout << "After fill with 7: ";
    for (int i = 0; i < min(5, (int)v.size()); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "\n===== KẾT LUẬN =====" << endl;
    cout << "Vector là cấu trúc dữ liệu linh hoạt với nhiều hàm tiện ích." << endl;
    cout << "Mỗi nhóm hàm có mục đích riêng và độ phức tạp khác nhau." << endl;
    cout << "Độ phức tạp thời gian cần được cân nhắc khi sử dụng các hàm trong các bài toán thực tế." << endl;

    return 0;
}