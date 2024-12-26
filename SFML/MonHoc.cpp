#include <iostream>
#include <string>
#include <cstring>
#include "MonHoc.h"
#include "SinhVien.h" // Bao gồm SinhVien.h nếu cần sử dụng con trỏ tới sinh viên trong các hàm liên quan
using namespace std;

// Hàm khởi tạo cây
void Initialize(PTRMH& root) {
    root = nullptr;
}
// Hàm tìm phần tử nhỏ nhất trong cây con phải
PTRMH AVLTreeMH:: findMin(PTRMH root) {
    while (root->pLeft != nullptr) {
        root = root->pLeft;
    }
    return root;
}
// Hàm xoay trái
PTRMH AVLTreeMH :: rotate_Left(PTRMH root) {
    PTRMH p;
    if (root == nullptr) {
        cout << "Khong the xoay trai vi cay rong." << endl;
        return root;
    }
    if (root->pRight == nullptr) {
        cout << "Khong the xoay trai vi khong co nut con ben phai." << endl;
        return root;
    }

    p = root->pRight;
    root->pRight = p->pLeft;
    p->pLeft = root;
    return p;
}
// Hàm xoay phải
PTRMH AVLTreeMH::rotate_Right(PTRMH root) {
    if (root == nullptr) {
        cout << "Cay rong, khong the xoay phai." << endl;
        return nullptr;
    }

    PTRMH p = root->pLeft;
    if (p == nullptr) {
        cout << "Khong the xoay phai vi khong co nut con ben trai." << endl;
        return root;
    }

    root->pLeft = p->pRight;
    p->pRight = root;
    return p;
}

// Hàm chèn node mới vào cây AVL
PTRMH AVLTreeMH::Insert(PTRMH& pavltree,  MonHoc x) {
    PTRMH fp = nullptr, p = pavltree, q = nullptr, fya = nullptr, ya = p, s = nullptr;
    int imbal;

    // Tìm vị trí chèn node mới
    while (p != nullptr) {
        if (x.MAMH == p->mh.MAMH) return pavltree; // Đã tồn tại mã môn học
        if (x.MAMH < p->mh.MAMH) {
            q = p->pLeft;
        } else {
            q = p->pRight;
        }
        if (q != nullptr) {
            if (q->bf != 0) {
                fya = p;
                ya = q;
            }
        }
        fp = p;
        p = q;
    }

    // Thêm node mới
    q = new NodeMH;
    q->mh = x;
    q->bf = 0;
    q->pLeft = nullptr;
    q->pRight = nullptr;
    if(fp == nullptr) {
        // Nếu cây rỗng
        pavltree = q;
        return pavltree;
    }
    if (x.MAMH < fp->mh.MAMH) {
        fp->pLeft = q;
    } else {
        fp->pRight = q;
    }

    // Điều chỉnh hệ số cân bằng
    if (x.MAMH < ya->mh.MAMH) {
        p = ya->pLeft;
    } else {
        p = ya->pRight;
    }

    s = p;
    while (p != q) {
        if (x.MAMH < p->mh.MAMH) {
            p->bf = 1;
            p = p->pLeft;
        } else {
            p->bf = -1;
            p = p->pRight;
        }
    }

    if (x.MAMH < p->mh.MAMH) {
        imbal = 1;
    } else {
        imbal = -1;
    }

    if (ya->bf == 0) {
        ya->bf = imbal;
        return pavltree;
    }

    if (ya->bf != imbal) {
        ya->bf = 0;
        return pavltree;
    }

    if (ya->bf == imbal) {
        if (imbal == 1) {
            p = rotate_Right(ya);
        } else {
            p = rotate_Left(ya);
        }
        ya->bf = 0;
        s->bf = 0;
    } else {
        if (imbal == 1) {
            ya->pLeft = rotate_Left(s);
            p = rotate_Right(ya);
        } else {
            ya->pRight = rotate_Right(s);
            p = rotate_Left(ya);
        }
        if (p->bf == 0) {
            ya->bf = 0;
            s->bf = 0;
        } else {
            if (p->bf == imbal) {
                ya->bf = -imbal;
                s->bf = 0;
            } else {
                ya->bf = 0;
                s->bf = imbal;
            }
            p->bf = 0;
        }
    }

    if (fya == nullptr) {
        pavltree = p;
    } else {
        if (ya == fya->pRight) {
            fya->pRight = p;
        } else {
            fya->pLeft = p;
        }
    }

    return pavltree;
}
// Hàm cân bằng cây khi nhánh trái giảm độ cao
void AVLTreeMH::balance_right(PTRMH& root) {
    if (root->bf == 1) { // Cây lệch trái
        if (root->pLeft->bf == 1) { // Cây lệch trái trái
            root = rotate_Right(root);
        } 
        else { // Cây lệch trái phải
            root->pLeft = rotate_Left(root->pLeft);
            root = rotate_Right(root);
        }
    } 
    else { // Cây lệch phải
        root->bf = 0; // Cân bằng lại cây
    }
}
// Hàm cân bằng cây khi nhánh phải giảm độ cao
void AVLTreeMH::balance_left(PTRMH& root) {
    if (root->bf == -1) { // Cây lệch phải
        if (root->pRight->bf == -1) { // Cây lệch phải phải
            root = rotate_Left(root);
        } 
        else { // Cây lệch phải trái
            root->pRight = rotate_Right(root->pRight);
            root = rotate_Left(root);
        }
    } 
    else { // Cây lệch trái
        root->bf = 0; // Cân bằng lại cây
    }
}
void AVLTreeMH::Create_AVLMH(PTRMH& root) {
    MonHoc monhoc;
    do {
        cout << "Nhap ma mon hoc (Q de quay lai): ";
        getline(cin, monhoc.MAMH);
        if (monhoc.MAMH == "Q") break;

        cout << "Nhap ten mon hoc: ";
        getline(cin, monhoc.TENMH);
        cout << "Nhap so luong tin chi ly thuyet: ";
        cin >> monhoc.STCLT;
        cout << "Nhap so luong tin chi thuc hanh: ";
        cin >> monhoc.STCTH;
        cin.ignore(); // Bỏ qua ký tự newline sau khi nhập số

        Insert(root, monhoc);
    } while (true);
}



// Hàm duyệt cây theo thứ tự giữa
void AVLTreeMH:: InOrder(PTRMH root) {
    if (root != nullptr) {
        InOrder(root->pLeft);
        cout << "Ma mon hoc: " << root->mh.MAMH << ", Ten mon hoc: " << root->mh.TENMH << ", So tin chi Ly thuyet: "
             << root->mh.STCLT << ", So tin chi Thuc hanh: " << root->mh.STCTH << endl;
        InOrder(root->pRight);
    }
}



// Hàm xóa nút có khóa x trong cây AVL
void AVLTreeMH::Remove(PTRMH& root, MonHoc x) {
    if (root == nullptr) {
        cout << "Không thể xóa được nút với mã môn học: " << x.MAMH << " trên cây." << endl;
        return;
    }

    // So sánh x với khóa hiện tại của root
    if (x.MAMH < root->mh.MAMH) {
        // Nếu x nhỏ hơn khóa của root, xóa đệ quy bên trái
        Remove(root->pLeft, x);
        // Cân bằng lại cây nếu nhánh trái bị giảm độ cao
        balance_right(root);
    } 
    else if (x.MAMH > root->mh.MAMH) {
        // Nếu x lớn hơn khóa của root, xóa đệ quy bên phải
        Remove(root->pRight, x);
        // Cân bằng lại cây nếu nhánh phải bị giảm độ cao
        balance_left(root);
    } 
    else {
        // Nếu x bằng khóa của root, thực hiện xóa nút root
        PTRMH temp = root;

        // Trường hợp 1: Nút cần xóa là lá
        if (root->pLeft == nullptr && root->pRight == nullptr) {
            root = nullptr;
            delete temp;
        } 
        // Trường hợp 2: Nút cần xóa có một con
        else if (root->pLeft == nullptr) {
            root = root->pRight;
            delete temp;
        } 
        else if (root->pRight == nullptr) {
            root = root->pLeft;
            delete temp;
        } 
        // Trường hợp 3: Nút cần xóa có hai con
        else {
            // Tìm phần tử nhỏ nhất trong cây con bên phải
            temp = findMin(root->pRight);
            root->mh = temp->mh;  // Sao chép dữ liệu
            Remove(root->pRight, temp->mh);  // Xóa nút bên phải
            // Cân bằng lại cây nếu nhánh phải bị giảm độ cao
            balance_left(root);
        }
    }
}

PTRMH AVLTreeMH::Search(PTRMH root, MonHoc x) {
    PTRMH p = root; // Khởi tạo con trỏ p trỏ đến root
    // Duyệt qua các node trong cây cho đến khi tìm thấy MAMH hoặc hết cây
    while (p != nullptr && x.MAMH != p->mh.MAMH) {
        if (x.MAMH < p->mh.MAMH) {
            p = p->pLeft; // Di chuyển sang cây con bên trái nếu MAMH nhỏ hơn
        } else {
            p = p->pRight; // Di chuyển sang cây con bên phải nếu MAMH lớn hơn
        }
    }

    // Nếu tìm thấy môn học trong cây, thực hiện cập nhật thông tin
    if (p != nullptr) {
        p->mh.TENMH = x.TENMH; // Cập nhật tên môn học
        p->mh.STCLT = x.STCLT; // Cập nhật số tín chỉ lý thuyết
        p->mh.STCTH = x.STCTH; // Cập nhật số tín chỉ thực hành
    }

    return p; // Trả về con trỏ đến node môn học tìm thấy, hoặc nullptr nếu không tìm thấy
}

PTRMH AVLTreeMH::Search1(PTRMH root, string mamh) {
    PTRMH p = root; // Khởi tạo con trỏ p trỏ đến root

    // Duyệt qua các node trong cây cho đến khi tìm thấy MAMH hoặc hết cây
    while (p != nullptr && mamh != p->mh.MAMH) {
        if (mamh < p->mh.MAMH) {
            p = p->pLeft; // Di chuyển sang cây con bên trái nếu MAMH nhỏ hơn
        } else {
            p = p->pRight; // Di chuyển sang cây con bên phải nếu MAMH lớn hơn
        }
    }

    // Nếu tìm thấy môn học trong cây, thực hiện cập nhật thông tin

    return p; // Trả về con trỏ đến node môn học tìm thấy, hoặc nullptr nếu không tìm thấy
}
int AVLTreeMH::KTMonHoc(PTRMH root, string mamh) // Trả về 1 nếu trùng, 0 nếu không trùng
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
  
bool AVLTreeMH::checkMAMH(const string& mamh) {
    return mamh.length() == 11;
}

bool AVLTreeMH::isEmpty(PTRMH root){
        return root == NULL ; 
}
PTRMH AVLTreeMH::findMonHoc(PTRMH root, const string& mamh) {
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
void AVLTreeMH::adjustMonHoc(MonHoc& newMH, PTRMH& node) {
    if (node != nullptr) {
        node->mh = newMH; // Thay thế dữ liệu môn học tại node hiện tại
    }
}
int AVLTreeMH::countMH(PTRMH node) {
        if (node == nullptr) {
            return 0; // Nếu node là null, không có node nào
        }
        // Đếm node hiện tại và đệ quy đếm các node trong cây con trái và cây con phải
        return 1 + countMH(node->pLeft) + countMH(node->pRight);
}
void AVLTreeMH::MangTam_MonHoc(PTRMH root, MonHoc mh[], int &dem) {
    if (root != nullptr) {
        // Duyệt cây con trái
        MangTam_MonHoc(root->pLeft, mh, dem);

        // Lưu node vào mảng
        mh[dem++] = root->mh;

        // Duyệt cây con phải
        MangTam_MonHoc(root->pRight, mh, dem);
    }
}
void AVLTreeMH::bubbleSortTENMH(MonHoc mh[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (mh[i].TENMH > mh[j].TENMH) {  // So sánh tên môn học
                // Hoán đổi hai phần tử nếu tên môn học của phần tử i lớn hơn phần tử j
                MonHoc temp = mh[i];
                mh[i] = mh[j];
                mh[j] = temp;
            }
        }
    }
}