#ifndef DANGKY_H
#define DANGKY_H

#include "SinhVien.h"  // Bao gồm header SinhVien.h

struct DangKy {
    char MSSV[16];    // Mã số sinh viên
    float Diem;       // Điểm của sinh viên
    bool Huy_Dang_Ky; // Trạng thái hủy đăng ký
};

struct NodeDK {
    DangKy sv;        // Thông tin đăng ký của sinh viên
    NodeDK* next;     // Con trỏ đến node đăng ký tiếp theo
};

typedef NodeDK* ptrDK;

void dangKyLopTinChi(ptrDK &danhSachDK, const char* maSV); // Đăng ký lớp tín chỉ
void huyDangKyLopTinChi(ptrDK &danhSachDK, const char* maSV); // Hủy đăng ký lớp tín chỉ
void inDanhSachSinhVienDaDangKy(ptrDK danhSachDK); // In danh sách sinh viên đã đăng ký

#endif // DANGKY_H
