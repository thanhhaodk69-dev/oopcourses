#include <iostream>
using namespace std;

// Chương trình giới thiệu bản thân - Format Tối giản & Hiện đại
int main() {
// Thiết lập mã màu ANSI chuyên nghiệp
string RESET   = "\033[0m";
string BLUE    = "\033[34m"; // Màu xanh dương cho tiêu đề và các đường phân cách
string CYAN    = "\033[36m"; // Màu xanh ngọc cho phần nội dung chính
string MAGENTA = "\033[35m"; // Màu hồng tím nhấn mạnh thông điệp cuối

// 1. Phần tiêu đề (Format thanh lịch)
cout << BLUE << "-------------------------------------------\n" << RESET;
cout << BLUE << "          DEVELOPER PROFILE: THANHHAO   \n";
cout  << "-------------------------------------------\n";

// 2. Phần thông tin học vấn (Sử dụng tab \t để căn lề thẳng hàng)
cout << CYAN << "▫️ Full Name:\tThanhHao\n" << RESET;
cout << CYAN << "▫️ Academic:\tHCMUTE (University of Technology & Education)\n" << RESET;
cout << CYAN << "▫️ Current:\tLearning OOP with C++\n" << RESET;
cout << CYAN << "▫️ Location:\tHo Chi Minh City, Vietnam\n" << RESET;

// 3. Phần kỹ năng & Định hướng công nghệ
cout << BLUE << "...........................................\n" << RESET;
cout << CYAN << "🚀 Tech Stack:\tC++ | Git & GitHub | VS Code\n" << RESET;
cout << CYAN << "🎯 Target:\tBecome a Professional Software Engineer\n" << RESET;
cout << CYAN << "🎮 Interest:\tCoding, Exploring Tech & Gaming\n" << RESET;

// 4. Khung kết thúc và Thông điệp truyền cảm hứng
cout << BLUE << "-------------------------------------------\n" << RESET;
cout << MAGENTA << "  💡 \"The best way to predict the future is to create it.\"\n" << RESET;
cout << BLUE << "-------------------------------------------\n" << RESET;

return 0;
}