#ifndef LOP_H
#define LOP_H

#include "SinhVien.h" // Bao gồm header SinhVien.h

const int MALOPSV = 10000;  // Số lượng lớp sinh viên tối đa

// Cấu trúc lớp sinh viên
struct LopSV {
    char MALOP[16];        // Mã lớp
    char TENLOP[51];      // Tên lớp
    
};

// Cấu trúc danh sách lớp sinh viên
struct DS_lop_SV {
    int n = 0;            // Số lượng lớp hiện có
    LopSV Nodes[MALOPSV]; // Mảng các lớp sinh viên
};

// Hàm để thêm lớp sinh viên mới
void themLop(LopSV &lop);
// Hàm để xóa lớp sinh viên theo mã lớp
void xoaLop(const char* maLop);
// Hàm để hiệu chỉnh thông tin lớp sinh viên theo mã lớp
void hieuChinhLop(const char* maLop);
// Hàm để in danh sách lớp sinh viên
void inDanhSachLop();
// Hàm để tìm lớp theo mã lớp
LopSV* timLop(const char* maLop);

#endif // LOP_H
