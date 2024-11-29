#ifndef DANGKY_H
#define DANGKY_H

#include "LopTinChi.h"
#include "SinhVien.h"
#include <iostream>
#include <string>

// Lớp DangKy đại diện cho thông tin đăng ký của sinh viên
class DangKy
{
public:
    std::string MASV; // Mã số sinh viên
    float Diem;       // Điểm của sinh viên
    bool Huy_Dang_Ky; // Trạng thái hủy đăng ký

    DangKy(const std::string &mssv = "", float diem = 0.0f, bool huy = false)
        : MASV(mssv), Diem(diem), Huy_Dang_Ky(huy) {}
};

// NodeDK: Một phần tử của danh sách liên kết đơn
class NodeDK
{
public:
    DangKy sv;    // Thông tin đăng ký của sinh viên
    NodeDK *next; // Con trỏ tới node đăng ký tiếp theo

    NodeDK(const DangKy &dangKy) : sv(dangKy), next(nullptr) {}
};

typedef NodeDK* PTRDK;

// DanhSachDangKy - Quản lý danh sách đăng ký sinh viên
class DanhSachDangKy
{
private:
    PTRDK head; // Con trỏ tới node đầu tiên của danh sách

public:
    // Constructor
    DanhSachDangKy() : head(nullptr) {}

    // Thêm đăng ký vào danh sách
    void themDangKy(const DangKy &dangKy)
    {
        NodeDK *newNode = new NodeDK(dangKy);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            NodeDK *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Xóa đăng ký theo mã sinh viên
    void xoaDangKy(const std::string &mssv)
    {
        if (head == nullptr)
            return;

        if (head->sv.MASV == mssv)
        {
            NodeDK *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        NodeDK *temp = head;
        while (temp->next != nullptr && temp->next->sv.MASV != mssv)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {
            NodeDK *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Tìm đăng ký theo mã sinh viên
    NodeDK *timDangKy(const std::string &mssv)
    {
        NodeDK *temp = head;
        while (temp != nullptr)
        {
            if (temp->sv.MASV == mssv)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // In danh sách đăng ký sinh viên
    void inDanhSach()
    {
        NodeDK *temp = head;
        while (temp != nullptr)
        {
            std::cout << "MSSV: " << temp->sv.MASV 
                      << " | Diem: " << temp->sv.Diem 
                      << " | Huy: " << (temp->sv.Huy_Dang_Ky ? "Yes" : "No") 
                      << std::endl;
            temp = temp->next;
        }
    }

    // Kiểm tra danh sách có rỗng không
    bool danhSachRong() const
    {
        return head == nullptr;
    }

    // Destructor để giải phóng bộ nhớ
    ~DanhSachDangKy()
    {
        while (head != nullptr)
        {
            PTRDK temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif // DANGKY_H
