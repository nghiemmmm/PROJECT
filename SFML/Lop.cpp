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
// duyẹt den ds.n 


