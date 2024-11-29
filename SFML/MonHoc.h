#ifndef MONHOC_H
#define MONHOC_H
#include<string>
#include "SinhVien.h" // Bao gồm SinhVien.h nếu cần sử dụng con trỏ tới sinh viên trong các hàm liên quan
using namespace std;

// Cấu trúc dữ liệu môn học
class MonHoc {
    public : 
    string MAMH  ;   // Mã môn học gio han 11 ky tu 
    string TENMH ;  // Tên môn học gio han 51 ky tu 
    int STCLT;       // Số tín chỉ lý thuyết
    int STCTH;       // Số tín chỉ thực hành
};

// Node của cây AVL cho môn học
class NodeMH {
    public :
    MonHoc mh;       // Dữ liệu môn học
    int bf;          // Hệ số cân bằng
    NodeMH* pLeft;   // Con trỏ tới node con trái
    NodeMH* pRight;  // Con trỏ tới node con phải
};

typedef NodeMH* PTRMH ; 



class AVLTreeMH {
public:
    PTRMH root; // Gốc của cây AVL

    // Constructor khởi tạo cây rỗng
    AVLTreeMH() : root(nullptr) {}

public:
    // Hàm để lấy thể hiện duy nhất của lớp
    static AVLTreeMH& getInstance() {
        static AVLTreeMH instance; // Thể hiện duy nhất
        return instance;
    }

    // Hàm khởi tạo cây
    void Initialize(PTRMH& root) {
        root = nullptr;
    }

    // Tạo cây
    void Create_AVLMH(PTRMH& root);
    
    // Hàm chèn node mới vào cây AVL
    PTRMH Insert(PTRMH& pavltree, MonHoc x);

    // Hàm xoay phải
    PTRMH rotate_Right(PTRMH root);

    // Hàm xoay trái
    PTRMH rotate_Left(PTRMH root);

    // Hàm duyệt cây theo thứ tự giữa
    void InOrder(PTRMH root);

    // Hàm tìm phần tử nhỏ nhất trong cây con phải
    PTRMH findMin(PTRMH root);

    // Hàm xóa nút có khóa x trong cây AVL
    void Remove(PTRMH& root, MonHoc x);

    // Hàm cân bằng cây khi nhánh trái giảm độ cao
    void balance_right(PTRMH& root);

    // Hàm cân bằng cây khi nhánh phải giảm độ cao
    void balance_left(PTRMH& root);

    // Hàm tìm kiếm phần tử
    PTRMH Search(PTRMH root, MonHoc x);
     // Hàm tìm kiếm phần tử
    PTRMH Search1(PTRMH root, string mamh);

    bool isEmpty(PTRMH root){
        return root == NULL ; 
    }
    // ham tim mon hoc 
    int KTMonHoc(PTRMH root, string mamh) // Trả về 1 nếu trùng, 0 nếu không trùng
    {
        if (root == nullptr) {
            return 0; // Cây rỗng hoặc không tìm thấy
        }

        if (root->mh.MAMH == mamh) {
            return 1; // Tìm thấy mã môn học trùng
        } 
        else if (mamh < root->mh.MAMH) {
            return KTMonHoc(root->pLeft, mamh); // Tìm bên cây con trái
        } 
        else {
            return KTMonHoc(root->pRight, mamh); // Tìm bên cây con phải
        }
    }
    // kiem tra ma mon hoc họp le khong 
    bool checkMAMH(const string& mamh) {
    return mamh.length() == 11;
}
    // ham tim mon hoc 
    PTRMH findMonHoc(PTRMH root, const string& mamh) {
    if (root != nullptr) {
        if (root->mh.MAMH == mamh) {
            return root; // Tìm thấy node chứa môn học
        } 
        else if (mamh > root->mh.MAMH) {
            return findMonHoc(root->pRight, mamh); // Tìm bên cây con phải
        } 
        else {
            return findMonHoc(root->pLeft, mamh); // Tìm bên cây con trái
        }
    }
    return nullptr; // Không tìm thấy
}
// thay doi mot mon hoc 
void adjustMonHoc(MonHoc& newMH, PTRMH& node) {
    if (node != nullptr) {
        node->mh = newMH; // Thay thế dữ liệu môn học tại node hiện tại
    }
}



    
    // Xóa hàm copy và move constructor và assignment operator để ngăn chặn sao chép
    AVLTreeMH(const AVLTreeMH&) = delete;
    AVLTreeMH& operator=(const AVLTreeMH&) = delete;
    AVLTreeMH(AVLTreeMH&&) = delete;
    AVLTreeMH& operator=(AVLTreeMH&&) = delete;
};



#endif // MONHOC_H

