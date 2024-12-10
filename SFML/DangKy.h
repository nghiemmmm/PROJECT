#ifndef DANGKY_H
#define DANGKY_H

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
class listDK
{
public :
    PTRDK head; // Con trỏ tới node đầu tiên của danh sách

public:
    // Constructor
    listDK() : head(nullptr) {}
    PTRDK getHead() {return head;}
    void setHead(PTRDK newhead) {head = newhead;}

    // Thêm đăng ký vào danh sách
    void themDangKy(DangKy &dangKy)
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
    bool isEmpty(listDK& list)
        {
	return(list.head == NULL ? true : false);
        }


    int size(listDK& list) {

	int cnt = 0;

	if (list.head == NULL)
		return cnt;

	for (PTRDK k = list.head ; k != NULL; k = k->next) {
		cnt++;
	}
	return cnt;
    }

    // Cập nhật thông tin đăng ký
    void adjustDK(string masv, DangKy &dk) {
        PTRDK node = findMASV(masv);
        if (node != nullptr) {
            node->sv = dk;
        }
    }
    // Tìm sinh viên theo MASV
    PTRDK findMASV(const std::string &masv) const {
        for (PTRDK temp = head; temp != nullptr; temp = temp->next) {
            if (temp->sv.MASV == masv) {
                return temp;
            }
        }
        return nullptr;
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
    bool danhSachRong()
    {
        return head == nullptr;
    }

     // Lấy danh sách sinh viên chưa hủy đăng ký
    void inDanhSachChuaHuy() const {
        PTRDK temp = head;
        while (temp != nullptr) {
            if (!temp->sv.Huy_Dang_Ky) {
                std::cout << "MSSV: " << temp->sv.MASV
                          << " | Diem: " << temp->sv.Diem
                          << std::endl;
            }
            temp = temp->next;
        }
    } 
    // Cập nhật trạng thái hủy đăng ký
    void huyDangKy(const std::string &masv) {
        PTRDK node = findMASV(masv);
        if (node != nullptr) {
            node->sv.Huy_Dang_Ky = true;
        }
    }

    PTRDK getAt(int i) {
    if (i < 0) {
        std::cerr << "Lỗi: Vị trí không hợp lệ (i < 0)" << std::endl;
        return nullptr;
    }

    PTRDK current = head;
    int index = 0;

    // Duyệt qua danh sách liên kết đến vị trí i
    while (current != nullptr && index < i) {
        current = current->next;
        index++;
    }

    if (current == nullptr) {
        std::cerr << "Lỗi: Vị trí vượt quá giới hạn danh sách" << std::endl;
        return nullptr;
    }

    return current;
}


// // tinh diem trung bình 
//    float Tinh_Diem_TB(AVLTreeMH& treeMH, LopTinChi& lopTC) {
//     if (treeMH.isEmpty(treeMH.root) || lopTC.Dssvdk.getHead() == nullptr) {
//         return 0;
//     }

//     float ketqua = 0;
//     int tongtinchi = 0;

//     // Lấy mã môn học từ lớp tín chỉ
//     std::string MAMH = lopTC.MAMH;

//     // Tìm môn học trong cây AVL dựa vào MAMH
//     PTRMH MH = treeMH.findMonHoc(treeMH.root, MAMH);
//     if (MH == nullptr) {
//         std::cout << "Không tìm thấy môn học: " << MAMH << "\n";
//         return 0;
//     }

//     // Lấy danh sách đăng ký của lớp tín chỉ
//     for (PTRDK p = lopTC.Dssvdk.getHead(); p != nullptr; p = p->next) {
//         // Bỏ qua các đăng ký bị hủy
//         if (p->sv.Huy_Dang_Ky) {
//             continue;
//         }

//         // Tính điểm tối đa cho sinh viên trong lớp tín chỉ này
//         float maxDiem = p->sv.Diem;

//         // Tính số tín chỉ của môn học
//         int tinChi = MH->mh.STCLT + MH->mh.STCTH;

//         // Cộng dồn điểm trung bình
//         ketqua += maxDiem * tinChi;
//         tongtinchi += tinChi;
//     }

//     if (tongtinchi == 0) {
//         return 0;
//     }

//     return ketqua / tongtinchi;
// }


    // Destructor để giải phóng bộ nhớ
    ~listDK()
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
