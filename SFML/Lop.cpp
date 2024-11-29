#include "Lop.h"
#include <iostream>
#include <string>

// Phương thức thêm lớp sinh viên vào danh sách
void DS_LOPSV::ThemLopSV(LopSV lop){
        if (n < MAXLOPSV) {
            nodes[n++] = lop;
        } else {
            std::cout << "Danh sách lớp đã đầy!" << std::endl;
        }
    }

 // Phương thức xóa lớp sinh viên
void DS_LOPSV::XoaLopSV(const std::string& malop)  {
        for (int i = 0; i < n; ++i) {
            if (nodes[i].MALOP == malop) {
                for (int j = i; j < n - 1; ++j) {
                    nodes[j] = nodes[j + 1];
                }
                --n;
                std::cout << "Lớp " << malop << " đã bị xóa!" << std::endl;
                return;
            }
        }
        std::cout << "Không tìm thấy lớp " << malop << " để xóa!" << std::endl;
    }


 // Phương thức tìm lớp
int DS_LOPSV::TimLop(const std::string& malop) {
        for (int i = 0; i < n; ++i) {
            if (nodes[i].MALOP == malop) {
                return i;  // Trả về chỉ số của lớp tìm thấy
            }
        }
        return -1;  // Nếu không tìm thấy, trả về -1
    }
// Phương thức hiển thị danh sách lớp sinh viên
void DS_LOPSV::HienThiDanhSachLop()  {
        if (n == 0) {
            std::cout << "Danh sách lớp trống!" << std::endl;
            return;
        }
        for (int i = 0; i < n; ++i) {
            std::cout << "Mã lớp: " << nodes[i].MALOP << ", Tên lớp: " << nodes[i].TENLOP << std::endl;
        }
    }
//  while (window.isOpen()) {
//         long long displayLimit = (static_cast<std::vector<Text>::size_type>(displayFrom) + 3) >  classList.size() ?  classList.size() : (static_cast<std::vector<Text>::size_type>(displayFrom) + 3);
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             } else if (event.type == sf::Event::MouseButtonPressed) {
//                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);

//                 if (nextPageBtn.isClicked(mousePos)) {
//                    if (displayFrom + itemsPerPage < static_cast<int>( classList.size())) {
//                         displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
//                     }
//                 }

//                 if (prevPageBtn.isClicked(mousePos)) {
//                     if (displayFrom - itemsPerPage >= 0) {
//                         displayFrom -= itemsPerPage; // Quay lại trang trước
//                     }
//                 }

//                 if (addBtn.isClicked(mousePos)) {
//                     // Gọi hàm xử lý khi nhấn nút ADD
//                     // window.close()
//                     return 3 ; 
//                 }
//             }
//         }

//         // Tính số trang hiện tại và tổng số trang
//         int currentPage = (displayFrom / itemsPerPage) + 1;
//         int totalPages = ( classList.size() + itemsPerPage - 1) / itemsPerPage;

//         // Cập nhật nội dung văn bản hiển thị số trang
//         pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
//         window.clear(sf::Color::White);
//          // Vẽ menu chính 
//         BaseScreenLopHoc::drawMainMenu1(window) ; 
//         // Vẽ các yếu tố lớp học
//         // int displayLimit = std::min(displayFrom + 5, static_cast<int>(courseList.size()));
//         for (int i = displayFrom; i < displayLimit; i++) {
//             classList[i].draw(window);
//         }

//         nextPageBtn.draw(window);
//         prevPageBtn.draw(window);
//         addBtn.draw(window);
//         window.draw(pageText);
//         window.display();







// // Phương thức thêm sinh viên vào lớp
// void LopSV::ThemSinhVien(PTRSV &First, const SinhVien &sv) {
//     // Tạo một nút mới cho sinh viên
//     PTRSV newNode = new NodeSV(sv);
//     if (First == nullptr) {
//         First = newNode; // Nếu danh sách trống, thêm sinh viên làm phần tử đầu
//     } else {
//         PTRSV temp = First;
//         // Duyệt đến cuối danh sách
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode; // Thêm sinh viên vào cuối danh sách
//     }
// }

// // Phương thức thêm lớp sinh viên vào danh sách
// void DS_LOPSV::ThemLopSV() {
//     while (n < MAXLOPSV) {
//         LopSV lop;
        
//         std::cout << "Nhap ma so (<=0 la ket thuc): ";
//         std::cin >> lop.MALOP;
//         if (lop.MALOP <= "0") break;

//         // Kiểm tra xem lớp đã tồn tại chưa
//         if (TimLop(lop.MALOP) != -1) {
//             std::cout << "Ma lop sv bi trung" << std::endl;
//             continue;
//         }

//         std::cout << "Nhap TENLOP: ";
//         std::cin >> lop.TENLOP;

//         lop.FIRST = nullptr;  // Khởi tạo danh sách sinh viên trống cho lớp mới.
        
//         nodes[n] = lop; // Thêm lớp mới vào danh sách.
//         n++; // Tăng số lượng lớp trong danh sách.
//     }

//     if (n == MAXLOPSV) {
//         std::cout << "Danh sach lop da day!" << std::endl;
//     }
// }

// // Phương thức sửa lớp sinh viên
// void DS_LOPSV::SuaLopSV() {
//     std::string malop;
//     std::cout << "Nhap ma lop can sua: ";
//     std::cin >> malop;

//     int index = TimLop(malop); // Tìm lớp theo mã
//     if (index == -1) {
//         std::cout << "Lop khong ton tai!" << std::endl;
//         return;
//     }

//     std::string newMalop, newTenlop;
//     std::cout << "Nhap ma lop moi (hoac nhan enter de giu nguyen): ";
//     std::cin.ignore();
//     std::getline(std::cin, newMalop);
//     std::cout << "Nhap ten lop moi (hoac nhan enter de giu nguyen): ";
//     std::getline(std::cin, newTenlop);

//     // Cập nhật thông tin lớp
//     if (!newMalop.empty()) {
//         nodes[index].MALOP = newMalop;
//     }
//     if (!newTenlop.empty()) {
//         nodes[index].TENLOP = newTenlop;
//     }

//     std::cout << "Da sua lop!" << std::endl;
// }

// // Phương thức xóa lớp sinh viên
// void DS_LOPSV::XoaLopSV() {
//     std::string malop;
//     std::cout << "Nhap ma lop can xoa: ";
//     std::cin >> malop;

//     int index = TimLop(malop); // Tìm lớp theo mã
//     if (index == -1) {
//         std::cout << "Lop khong ton tai!" << std::endl;
//         return;
//     }

//     // Di chuyển các lớp sau lớp bị xóa lên
//     for (int i = index; i < n - 1; i++) {
//         nodes[i] = nodes[i + 1];
//     }
//     n--; // Giảm số lượng lớp
//     std::cout << "Da xoa lop " << malop << "!" << std::endl;
// }

// // Phương thức tìm lớp
// int DS_LOPSV::TimLop(const std::string& malop) const {
//     for (int i = 0; i < n; i++) {
//         if (nodes[i].MALOP == malop) {
//             return i; // Trả về chỉ số lớp trong danh sách
//         }
//     }
//     return -1; // Không tìm thấy lớp
// }

// // Hàm tìm sinh viên trong lớp
// PTRSV TimSinhVien(PTRSV First, const std::string& masv) {
//     NodeSV *current = First;
//     while (current != nullptr) {
//         if (current->data.MASV == masv) {
//             return current; // Trả về sinh viên tìm thấy
//         }
//         current = current->next; // Tiến tới sinh viên tiếp theo
//     }
//     return nullptr; // Trả về nullptr nếu không tìm thấy
// }
