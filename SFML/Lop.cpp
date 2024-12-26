#include "Lop.h"
#include <iostream>
#include <string>

int DS_LOPSV::TimChiSoLopQuaMaSV(DS_LOPSV& dsLop,string maSV) {
    for (int i = 0; i < dsLop.n; ++i) { // Duyệt qua từng lớp
        DanhSachSV currentList = dsLop.nodes[i].FIRST; // Lấy danh sách sinh viên của lớp
        PTRSV currentNode = currentList.getHead();         // Bắt đầu từ sinh viên đầu tiên trong danh sách
        while (currentNode != nullptr) {              // Duyệt qua danh sách liên kết
            if (currentNode->sv.MASV == maSV) {       // So sánh mã sinh viên
                return i;                             // Trả về chỉ số của lớp nếu tìm thấy
            }
            currentNode = currentNode->next;          // Tiến tới sinh viên tiếp theo
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy sinh viên
}

int DS_LOPSV::KTMaLop(DS_LOPSV& ds, string malop, int demkhongdoi) {
    for (int i = 0; i <= demkhongdoi; i++) {
        if (ds.n == i) {
            continue; // Bỏ qua nếu vị trí vượt quá số lớp hiện tại
        }

        // So sánh mã lớp, xử lý trường hợp phần tử đầu tiên
        if ((ds.nodes[i].MALOP == malop) && i == 0) {
            return -1; // Trả về -1 nếu trùng phần tử đầu tiên
        }

        // So sánh mã lớp, xử lý các phần tử khác
        if (ds.nodes[i].MALOP == malop) {
            return i; // Trả về vị trí nếu tìm thấy lớp
        }
    }
    return 0; // Không tìm thấy lớp, trả về 0
}
bool DS_LOPSV::KTMaLopVaTenLop(DS_LOPSV& dsLop,  std::string& malop,  std::string& tenlop) {
    for (int i = 0; i < dsLop.n; ++i) {
        // Kiểm tra mã lớp và tên lớp có trùng khớp không
        if (dsLop.nodes[i].MALOP == malop && dsLop.nodes[i].TENLOP == tenlop) {
            return true; // Đã tồn tại
        }
    }
    return false; // Không tồn tại
}

bool DS_LOPSV::KiemTraLopCoSinhVien(DS_LOPSV& dsLop,  std::string& maLop) {
    for (int i = 0; i < dsLop.n; ++i) {
        if (dsLop.nodes[i].MALOP == maLop) { // Tìm lớp theo mã lớp
            return dsLop.nodes[i].FIRST.getHead() != nullptr; // Trả về `true` nếu có sinh viên
        }
    }
    return false; // Không tìm thấy lớp
}
void DS_LOPSV::SuaLop(string malop, LopSV& lopMoi) {
    DS_LOPSV& dsLop = DS_LOPSV::getInstance(); // Lấy thể hiện singleton

    // Sử dụng hàm KTMaLop để kiểm tra và tìm vị trí lớp
    int viTri = KTMaLop(dsLop, malop, dsLop.n);

    if (viTri == 0) {
        std::cout << "Lop voi ma lop " << malop << " khong ton tai!" << std::endl;
        return;
    }

    if (viTri == -1) {
        std::cout << "Loi: Lop voi ma lop " << malop << " dang o vi tri dau tien, khong the sua!" << std::endl;
        return;
    }

    // Thực hiện cập nhật thông tin lớp
    dsLop.nodes[viTri] = lopMoi;

    std::cout << "Lop " << malop << " da duoc sua thong tin!" << std::endl;
}

void DS_LOPSV::XoaLop(DS_LOPSV& dsLop ,  std::string& malop) {
    // Sử dụng hàm KTMaLop để kiểm tra và tìm vị trí lớp
    int viTri = KTMaLop(dsLop, malop, dsLop.n);

    if (viTri == 0) {
        std::cout << "Không tìm thấy lớp có mã " << malop << "!" << std::endl;
        return;
    }

    if (viTri == -1) {
        std::cout << "Lớp với mã " << malop << " đang ở vị trí đầu tiên, không thể xóa!" << std::endl;
        return;
    }

    // Kiểm tra lớp có sinh viên không
    if (nodes[viTri].FIRST.getHead() != nullptr) {
        std::cout << "Không thể xóa lớp " << malop << " vì vẫn còn sinh viên!" << std::endl;
        return;
    }

    // Di chuyển các phần tử phía sau lên trước
    for (int i = viTri; i < n - 1; ++i) {
        nodes[i] = nodes[i + 1];
    }

    n--; // Giảm số lượng lớp
    std::cout << "Xóa lớp " << malop << " thành công!" << std::endl;
}

// Phương thức hiển thị danh sách lớp sinh viên
void DS_LOPSV::HienThiDanhSachLop()  {
        if (n == 0) {
            std::cout << "Danh sách lớp trống!" << std::endl;
            return;
        }
        for (int i = 0; i < n; ++i) {
            std::cout << "MALOP: " << nodes[i].MALOP << "   |"  << " TENLOP :" << nodes[i].TENLOP << std::endl;
        }
    }
// duyẹt den ds.n 
bool DS_LOPSV::isEmpty(DS_LOPSV& dsLop){
    return dsLop.n == 0;
}

int DS_LOPSV::TimViTriChenLop(DS_LOPSV& dsLop,string malop) {
    int left = 0, right = dsLop.n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (dsLop.nodes[mid].MALOP == malop) {
            return mid;  // Trả về vị trí nếu tìm thấy
        }

        if (dsLop.nodes[mid].MALOP < malop) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;  // Trả về vị trí chèn nếu không tìm thấy
}
void DS_LOPSV::ThemLop(DS_LOPSV& dsLop , LopSV lop) {
    int viTri = TimViTriChenLop(dsLop, lop.MALOP);
    if (viTri < dsLop.n && dsLop.nodes[viTri].MALOP == lop.MALOP) {
        std::cout << "Ma lop " << lop.MALOP << " da ton tai!" << std::endl;
        return;
    }

    if (dsLop.n >= MAXLOPSV) {
        std::cout << "Danh sach lop da day!" << std::endl;
        return;
    }

    for (int i = dsLop.n; i > viTri; i--) {
        dsLop.nodes[i] = dsLop.nodes[i - 1];
    }

    dsLop.nodes[viTri] = lop;
    dsLop.n++;

    std::cout << "Lop " << lop.MALOP << " da duoc them vao danh sach!" << std::endl;
}
void DS_LOPSV::themSV(DS_LOPSV& dsLop , string& malop , SinhVien& sv){
    for(int i = 0 ; i <  dsLop.n ; i++){
        if(dsLop.nodes[i].MALOP == malop){
            dsLop.nodes[i].FIRST.insertSV(sv) ; 
        }
    }
 }

void DS_LOPSV::deleteSV(DS_LOPSV& dsLop, string& malop, string& masv) {
    for (int i = 0; i < dsLop.n; i++) {
        // Kiểm tra xem mã lớp có khớp không
        if (dsLop.nodes[i].MALOP == malop) {
            // Truy cập danh sách sinh viên của lớp
            PTRSV curr = dsLop.nodes[i].FIRST.getHead();
            PTRSV prev = nullptr;

            // Nếu sinh viên cần xóa là đầu danh sách
            if (curr && curr->sv.MASV == masv) {
                dsLop.nodes[i].FIRST.setHead(curr->next); // Cập nhật head
                delete curr;
                return;
            }

            // Duyệt danh sách để tìm sinh viên
            while (curr && curr->sv.MASV != masv) {
                prev = curr;
                curr = curr->next;
            }

            // Nếu tìm thấy sinh viên
            if (curr) {
                prev->next = curr->next; // Bỏ qua node cần xóa
                delete curr;
            }
            return;
        }
    }
    // Nếu không tìm thấy mã lớp
    cout << "Class not found: " << malop << endl;
}
void DS_LOPSV::SuaSinhVien(DS_LOPSV& dsLop,  string& malop,  string& masv,  SinhVien& thongTinMoi) {
    // Duyệt qua danh sách lớp
    for (int i = 0; i < dsLop.n; i++) {
        // Kiểm tra mã lớp
        if (dsLop.nodes[i].MALOP == malop) {
            // Lấy danh sách sinh viên của lớp
            PTRSV p = dsLop.nodes[i].FIRST.getHead();

            // Duyệt danh sách để tìm sinh viên có MASV tương ứng
            while (p != nullptr) {
                if (p->sv.MASV == masv) {
                    // Cập nhật thông tin sinh viên
                    p->sv = thongTinMoi;
                    std::cout << "Sinh vien " << masv << " trong lop " << malop << " da duoc cap nhat!" << std::endl;
                    return;
                }
                p = p->next;
            }

            // Nếu không tìm thấy sinh viên
            std::cout << "Khong tim thay sinh vien co ma " << masv << " trong lop " << malop << "!" << std::endl;
            return;
        }
    }

    // Nếu không tìm thấy lớp
    std::cout << "Khong tim thay lop co ma " << malop << "!" << std::endl;
}
void DS_LOPSV::In34(DS_LOPSV& dsLop, const std::string& malop) {
    // Tìm lớp bằng MALOP
    for (int i = 0; i < dsLop.n; i++) {
        if (dsLop.nodes[i].MALOP == malop) {
            PTRSV p = dsLop.nodes[i].FIRST.getHead(); // Lấy đầu danh sách sinh viên
            if (p == nullptr) {
                std::cout << "Lop khong co sinh vien nao!" << std::endl;
                return;
            }

            std::cout << "Danh sach sinh vien cua lop " << malop << ":" << std::endl;
            std::cout << "MASV\tHO\t\tTEN\tPHAI\tSODT" << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;

            while (p != nullptr) {
                std::cout << p->sv.MASV << "\t" 
                          << p->sv.HO << "\t\t" 
                          << p->sv.TEN << "\t" 
                          << p->sv.PHAI << "\t" 
                          << p->sv.SODT << std::endl;
                p = p->next;  // Chuyển đến sinh viên tiếp theo
            }
            return;  // Kết thúc sau khi in danh sách sinh viên
        }
    }
    std::cout << "Lop khong ton tai!" << std::endl;  // Không tìm thấy lớp
}
PTRSV DS_LOPSV::FindSV( DS_LOPSV& dsLOP,string masv) {
    for (int i = 0; i < dsLOP.n; ++i) { // Duyệt qua từng lớp
        DanhSachSV currentList = dsLOP.nodes[i].FIRST; // Lấy danh sách sinh viên của lớp
        PTRSV currentNode = currentList.getHead();         // Bắt đầu từ sinh viên đầu tiên trong danh sách
        while (currentNode != nullptr) {              // Duyệt qua danh sách liên kết
            if (currentNode->sv.MASV == masv) {       // So sánh mã sinh viên
                return currentNode;                   // Tìm thấy sinh viên, trả về node
            }
            currentNode = currentNode->next;          // Tiến tới sinh viên tiếp theo
        }
    }
    return nullptr; // Không tìm thấy sinh viên
}

