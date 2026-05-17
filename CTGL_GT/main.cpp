#include <iostream>
#include <fstream>      // Thư viện đặc biệt quan trọng để thao tác Đọc/Ghi file (File Stream)
#include <cstdlib>
#include <ctime>
#include "Converter.h" // Nhúng thư viện thuật toán chuyển đổi biểu thức mà chúng ta đã tự viết

using namespace std;

// Hàm xử lý dữ liệu: Đọc hàng loạt biểu thức từ file input, chuyển đổi và lưu sang file output
void processData(string inputFile, string outputFile) {
    ifstream inFile(inputFile);   // Mở file để ĐỌC dữ liệu vào (Input File Stream)
    ofstream outFile(outputFile); // Mở file để GHI kết quả ra (Output File Stream)
    
    // Kiểm tra an toàn: Nhỡ file input không tồn tại hoặc bị lỗi quyền truy cập thì báo lỗi ngay
    if (!inFile || !outFile) {
        cout << "Loi mo file doc/ghi!" << endl;
        return; // Thoát hàm ngay lập tức để tránh crash chương trình
    }
    
    string line;            // Biến tạm để hứng dữ liệu của từng dòng
    int processCount = 0;   // Biến đếm xem đã xử lý được bao nhiêu biểu thức
    
    // Vòng lặp getline sẽ đọc lần lượt từng dòng trong file cho đến khi hết file (EOF)
    while (getline(inFile, line)) {
        if (line != "") {   // Đề phòng file có các dòng trắng, chỉ xử lý dòng có dữ liệu
            // Lấy dòng đó đưa vào hàm infixToPostfix, sau đó đẩy kết quả thẳng vào file output
            outFile << infixToPostfix(line) << "\n";
            processCount++; // Tăng biến đếm lên 1 sau mỗi lần chuyển đổi thành công
        }
    }
    
    // Nguyên tắc vàng khi làm việc với file: Mở ra thì phải Đóng lại để giải phóng bộ nhớ (RAM)
    inFile.close();
    outFile.close();
    
    // In thông báo tổng kết ra màn hình Terminal
    cout << "Da xu ly va chuyen doi xong " << processCount << " bieu thuc sang " << outputFile << endl;
}

int main() {
    // Khai báo file chứa 100.000 biểu thức đầu vào và file chứa kết quả đầu ra
    string inputFile = "input_100k.txt";
    string outputFile = "output_100k.txt";
    
    // Khởi chạy quá trình đọc, chuyển đổi và ghi file
    processData(inputFile, outputFile);
    
    return 0;
}
