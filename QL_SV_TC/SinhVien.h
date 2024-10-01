#ifndef SINHVIEN_H
#define SINHVIEN_H

struct SinhVien {
    char MASV[16];      // Mã số sinh viên
    char HO[51];        // Họ sinh viên
    char TEN[11];       // Tên sinh viên
    char PHAI[4];       // Giới tính
    char SDT[16];       // Số điện thoại
    char MaLop[15];     // Mã lớp sinh viên
    int namNhapHoc;     // Năm nhập học
};

struct NodeSV {
    SinhVien sv;        // Thông tin sinh viên
    NodeSV *next;       // Con trỏ đến node sinh viên tiếp theo
};

typedef NodeSV* ptrSV; // Con trỏ tới NodeSV

#endif // SINHVIEN_H
