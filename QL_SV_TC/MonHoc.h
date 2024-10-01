#ifndef MONHOC_H
#define MONHOC_H

#include "SinhVien.h" // Bao gồm SinhVien.h nếu cần sử dụng con trỏ tới sinh viên trong các hàm liên quan

struct MonHoc {
    char MAMH[11];   // Mã môn học
    char TENMH[51];  // Tên môn học
    int STCLT;       // Số tín chỉ lý thuyết
    int STCTH;       // Số tín chỉ thực hành
};

// Cây nhị phân cân bằng (AVL Tree)
struct NodeMH {
    MonHoc mh;       // Dữ liệu môn học
    int bf;          // Hệ số cân bằng
    NodeMH* pLeft;   // Con trỏ tới node con trái
    NodeMH* pRight;  // Con trỏ tới node con phải
};

typedef NodeMH* treeMH;  // Cây môn học

void themMonHoc(MonHoc &monHoc); // Thêm môn học mới
void xoaMonHoc(const char* maMH); // Xóa môn học
void hieuChinhMonHoc(const char* maMH); // Hiệu chỉnh thông tin môn học
void inDanhSachMonHoc(); // In danh sách môn học
MonHoc* timMonHoc(const char* maMH); // Tìm môn học theo mã

#endif // MONHOC_H
