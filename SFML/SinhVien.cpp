#include "SinhVien.h"
#include <iostream>
#include <string>

// Phương thức thêm sinh viên vào lớp
void DanhSachSV::ThemSinhVien(const SinhVien &sv) {
   PTRSV newnode = new NodeSV(sv);
        if (!head) {
            head = newnode;
            return;
        }

        PTRSV tail = head;
        while (tail->next) {
            tail = tail->next;
        }

        tail->next = newnode;
}

// Hàm tìm sinh viên trong lớp
NodeSV* DanhSachSV::TimSinhVien(const std::string& masv) {
    NodeSV* current = head;
    while (current != nullptr) {
        if (current->sv.MASV == masv) { // So sánh với MASV của sinh viên
            return current; // Trả về sinh viên tìm thấy
        }
        current = current->next; // Tiến tới sinh viên tiếp theo
    }
    return nullptr; // Trả về nullptr nếu không tìm thấy
}

// Phương thức xóa sinh viên khỏi danh sách theo mã sinh viên
void DanhSachSV::xoaSinhVien(const std::string& masv) {
    NodeSV* prev = nullptr;
    NodeSV* current = head;
    while (current != nullptr) {
        if (current->sv.MASV == masv) {
            if (prev == nullptr) { // Nếu là node đầu
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current; // Giải phóng bộ nhớ của node hiện tại
            break;
        }
        prev = current;
        current = current->next;
    }
}
