#include "SinhVien.h"
#include <iostream>
#include <string>

// Phương thức thêm sinh viên vào lớp
void LinkedListSV::ThemSinhVien(const SinhVien &sv) {
    // Tạo một nút mới cho sinh viên
    NodeSV* newNode = new NodeSV(sv); // Sử dụng NodeSV* thay vì PTRSV
    if (head == nullptr) {
        head = newNode; // Nếu danh sách trống, thêm sinh viên làm phần tử đầu
    } else {
        NodeSV* temp = head;
        // Duyệt đến cuối danh sách
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode; // Thêm sinh viên vào cuối danh sách
    }
}

// Hàm tìm sinh viên trong lớp
NodeSV* LinkedListSV::TimSinhVien(const std::string& masv) {
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
void LinkedListSV::xoaSinhVien(const std::string& masv) {
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
