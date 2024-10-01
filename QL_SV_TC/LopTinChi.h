#ifndef LOPTINCHI_H
#define LOPTINCHI_H

#include "SinhVien.h"  // Bao gồm header SinhVien.h
#include "MonHoc.h"    // Bao gồm header MonHoc.h
#include "DangKy.h"    // Bao gồm header DangKy.h

const int MAX_LTC = 10000; // Số lượng lớp tín chỉ tối đa

struct Lop_Tin_Chi {
    int MALOPTC;             // Mã lớp tín chỉ
    char MAMH[11];           // Mã môn học
    char NienKhoa[10];       // Niên khóa
    int HocKy;               // Học kỳ
    int Nhom;                // Nhóm
    int soSvMin;             // Số sinh viên tối thiểu
    int soSvMax;             // Số sinh viên tối đa
    bool HuyLop = false;     // Trạng thái hủy lớp
    ptrDK Dssvdk = NULL;     // Danh sách sinh viên đăng ký lớp tín chỉ
};

struct list_Loptc {
    int n = 0;                         // Số lượng lớp hiện có
    Lop_Tin_Chi* Nodes[MAX_LTC];       // Mảng con trỏ tới các lớp tín chỉ
};

void moLopTinChi(Lop_Tin_Chi &lop); // Mở lớp tín chỉ
void xoaLopTinChi(int malop); // Xóa lớp tín chỉ
void hieuChinhLopTinChi(int malop); // Hiệu chỉnh thông tin lớp tín chỉ
void inDanhSachLopTinChi(); // In danh sách lớp tín chỉ
Lop_Tin_Chi* timLopTinChi(int malop); // Tìm lớp tín chỉ theo mã

#endif // LOPTINCHI_H
