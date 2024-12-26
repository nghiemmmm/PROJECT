#include"DangKy.h"

void listDK::addDK(DangKy &dangKy)
    {
        PTRDK newNode = new NodeDK(dangKy);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            PTRDK temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

bool listDK::isEmpty(listDK& list)
    {
	    return(list.head == NULL ? true : false);
    }
int listDK::size(listDK& list) {
	int cnt = 0;
	if (list.getHead() == NULL)
		return cnt;

	for (PTRDK k = list.getHead() ; k != NULL; k = k->next) {
		cnt++;
	}
	return cnt;
}
void listDK::adjustDK(string masv, DangKy &dk) {
        PTRDK node = findMASV(masv);
        if (node != nullptr) {
            node->sv = dk;
        }
    }
PTRDK listDK::findMASV( std::string masv)  {
        for (PTRDK temp = head; temp != nullptr; temp = temp->next) {
            if (temp->sv.MASV == masv) {
                return temp;
            }
        }
        return nullptr;
    }
void listDK::inDanhSach()
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
void listDK::inDanhSachChuaHuy() const {
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
void listDK::huyDangKy(const std::string &masv) {
        PTRDK node = findMASV(masv);
        if (node != nullptr) {
            node->sv.Huy_Dang_Ky = true;
        }
    }

PTRDK listDK::getAt(int i) {
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
PTRDK listDK::findStudentByMASV(std::string& masv){
    // Duyệt qua danh sách để tìm sinh viên có mã số MASV
    for (PTRDK temp = head; temp != nullptr; temp = temp->next) {
        if (temp->sv.MASV == masv) {
            return temp;  // Trả về con trỏ đến node chứa sinh viên tìm được
        }
    }
    return nullptr;  // Nếu không tìm thấy sinh viên với MASV đó
}
void listDK::removeDK( std::string mssv)
{
    // Kiểm tra xem danh sách có trống không
    if (head == nullptr)
    {
        std::cout << "Danh sách đăng ký trống.\n";
        return;
    }

    // Nếu phần tử đầu tiên cần xóa
    if (head->sv.MASV == mssv)
    {
        NodeDK *temp = head;
        head = head->next;  // Đổi head sang phần tử tiếp theo
        delete temp;        // Giải phóng bộ nhớ
        std::cout << "Đã xóa đăng ký của sinh viên có MASV = " << mssv << "\n";
        return;
    }

    // Duyệt qua danh sách để tìm sinh viên cần xóa
    NodeDK *temp = head;
    while (temp->next != nullptr && temp->next->sv.MASV != mssv)
    {
        temp = temp->next;
    }

    // Nếu tìm thấy sinh viên cần xóa
    if (temp->next != nullptr)
    {
        NodeDK *toDelete = temp->next;
        temp->next = temp->next->next;  // Liên kết lại danh sách
        delete toDelete;  // Giải phóng bộ nhớ
        std::cout << "Đã xóa đăng ký của sinh viên có MASV = " << mssv << "\n";
    }
    else
    {
        std::cout << "Không tìm thấy sinh viên với MASV = " << mssv << "\n";
    }
}
bool listDK::kiemTraDK(const std::string &masv)
{
    PTRDK current = head; // Bắt đầu từ node đầu tiên trong danh sách
    while (current != nullptr)
    {
        if (current->sv.MASV == masv) // So sánh mã sinh viên
        {
            return true; // Tìm thấy sinh viên
        }
        current = current->next; // Chuyển sang node tiếp theo
    }
    return false; // Không tìm thấy sinh viên
}
