#include "SinhVien.h"
#include <iostream>
#include <string>

void DanhSachSV::In() {
    PTRSV p =  head ;
    while (p != NULL) {
        cout << p->sv.MASV << " " ;
        p = p->next;
    }
    cout << endl;
}
int DanhSachSV::size(DanhSachSV& list) {
	int cnt = 0;
	if (list.getHead() == NULL)
		return cnt;

	for (PTRSV k = list.getHead() ; k != NULL; k = k->next) {
		cnt++;
	}
	return cnt;
    }
void DanhSachSV::In2(string ma) {
    PTRSV p =  head ;
    while (p != NULL && p->sv.MASV == ma ) {
             cout << p->sv.MASV << " " ;
             cout << "da thay " ; 
        p = p->next;
    }
    cout << endl;
}

SinhVien DanhSachSV::findStudentByMASV(string masv) {
        PTRSV p = head;
        while (p != nullptr) {
            if (p->sv.MASV == masv) {
                return p->sv;  // Trả về sinh viên tìm thấy
            }
            p = p->next;
        }
        return SinhVien();  // Trả về đối tượng SinhVien mặc định nếu không tìm thấy
}
PTRSV DanhSachSV::findStudentByMASV1( string masv) {
    PTRSV p = head;
    while (p != nullptr) {
        if (p->sv.MASV == masv) {
            return p;  // Trả về con trỏ đến sinh viên tìm thấy
        }
        p = p->next;
    }
    return nullptr;  // Trả về nullptr nếu không tìm thấy
}
PTRSV DanhSachSV::In3() {
    PTRSV p =  head ;
    while (p != NULL) {
       cout << p ->sv.HO ; 
        p = p->next;
    }
    return NULL ; 
}
bool DanhSachSV::isEmpty(){
    return head == nullptr;
}
void DanhSachSV::selectionSortSV(SinhVien* dsSinhVien, int soluongsv) {
    for (int i = 0; i < soluongsv - 1; ++i) {
        int smallestIndex = i;
        for (int j = i + 1; j < soluongsv; ++j) {
            // So sánh tên trước
            if (dsSinhVien[smallestIndex].TEN > dsSinhVien[j].TEN) {
                smallestIndex = j;
            } else if (dsSinhVien[smallestIndex].TEN == dsSinhVien[j].TEN) { // Nếu tên bằng nhau, so sánh họ
                if (dsSinhVien[smallestIndex].HO > dsSinhVien[j].HO) {
                    smallestIndex = j;
                }
            }
        }
        // Hoán đổi giá trị sinh viên
        if (smallestIndex != i) {
            std::swap(dsSinhVien[i], dsSinhVien[smallestIndex]);
        }
    }
}
bool DanhSachSV::KTSV(DanhSachSV& list, std::string& maSV) {
    // Duyệt qua danh sách sinh viên
    for (PTRSV p = list.getHead(); p != nullptr; p = p->next) {
        if (p->sv.MASV == maSV) {
            return true; // Trả về true nếu tìm thấy sinh viên
        }
    }
    return false; // Trả về false nếu không tìm thấy sinh viên
}
bool DanhSachSV::KTTrung(DanhSachSV& list, std::string& maSV) {
    // Duyệt qua danh sách sinh viên
    for (PTRSV p = list.getHead(); p != nullptr; p = p->next) {
        if (p->sv.MASV == maSV) {
            return true; // Trả về true nếu tìm thấy sinh viên
        }
    }
    return false; // Trả về false nếu không tìm thấy sinh viên
}