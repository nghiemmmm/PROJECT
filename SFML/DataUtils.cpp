
#include"DataUtils.h"
#include"globals.h"
// #include<vector>
#include"FileNFoder.h"
#include"BuiltClasses.h"
#include <iomanip>  // Để sử dụng std::setw
#include <sstream>
#include <algorithm>
#include<string>
// TinhchiList& list2 = TinhchiList::getInstance();
// DS_LOPSV& listclass2 =  DS_LOPSV::getInstance() ;
// ham get du lieu 
void Data::getlop( fsys::path filepath , DS_LOPSV& listclass ) {
    csvFile lopList(filepath);
    // Đọc nội dung file CSV
    lopList.readFile(); 

    // Kiểm tra nếu file không tồn tại hoặc có lỗi mở file
    if (lopList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        return; // Không tiếp tục nếu không đọc được dữ liệu
    }

    for (size_t i = 1; i < static_cast<size_t>(lopList.cnt.size()); ++i) {
        LopSV lop;
        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (static_cast<size_t>(lopList.cnt.size()) < 2) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong LopSV
        lop.MALOP = lopList.cnt[i][0];    // Cột 0 là MALOP
        lop.TENLOP = lopList.cnt[i][1];    // Cột 1 là TENLOP
        lop.FIRST = DanhSachSV();               // Khởi tạo danh sách sinh viên trống

        try {
            // Nếu cần thực hiện thao tác nào khác, có thể bổ sung ở đây.
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid data format at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu dữ liệu không đúng định dạng
        }

        // Thêm lớp sinh viên vào danh sách DS_LOPSV
        listclass.ThemLop(listclass,lop) ; 
        // listclass2.ThemLopSV(lop);
         
    }
}
void Data::getmonhoc(fsys::path filepath) {
    // Kiểm tra nếu tệp có tồn tại
    std::ifstream file(filepath.generic_string());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
        return;
    }

    // Đọc nội dung file CSV
    csvFile monhocList(filepath);
    monhocList.readFile();

    // Kiểm tra nếu file không chứa dữ liệu
    if (monhocList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        return;
    }

    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < static_cast<size_t>(monhocList.cnt.size()); ++i) {
        MonHoc mh;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (static_cast<size_t>(monhocList.cnt[i].size()) < 4) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong MonHoc
        mh.MAMH = monhocList.cnt[i][0]; // Cột 0 là MAMH
        mh.TENMH = monhocList.cnt[i][1]; // Cột 1 là TENMH

        // Kiểm tra giá trị Số tín chỉ lý thuyết và thực hành có phải là số hợp lệ không
        if (Data::isNumber(monhocList.cnt[i][2])) {
            mh.STCLT = std::stoi(monhocList.cnt[i][2]); // Cột 2 là Số tín chỉ lý thuyết
        } else {
            std::cerr << "Invalid number format in STCLT at line " << i + 1 << ". Skipping...\n";
            continue;
        }

        if (Data::isNumber(monhocList.cnt[i][3])) {
            mh.STCTH = std::stoi(monhocList.cnt[i][3]); // Cột 3 là Số tín chỉ thực hành
        } else {
            std::cerr << "Invalid number format in STCTH at line " << i + 1 << ". Skipping...\n";
            continue;
        }

        // Thêm môn học vào cây AVL
        AVLTreeMH::getInstance().Insert(AVLTreeMH::getInstance().root, mh);
    }

    // Đóng tệp sau khi xử lý
    file.close();
}
void Data::getstudent(fsys::path filepath , DS_LOPSV& listclass  ) {
    // Kiểm tra nếu tệp có tồn tại
    std::ifstream file(filepath.generic_string());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
        //return;
    }

    // Đọc nội dung file CSV
    csvFile studentList(filepath);
    studentList.readFile();

    // Kiểm tra nếu file không chứa dữ liệu
    if (studentList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        //return;
    }

    // DanhSachSV sinhvien ; 
    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < static_cast<size_t>(studentList.cnt.size()); ++i) {
        SinhVien sv;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (static_cast<size_t>(studentList.cnt[i].size()) < 4) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong MonHoc
        sv.MASV = studentList.cnt[i][0]; // Cột 0 là MAMH
        sv.HO = studentList.cnt[i][1]; // Cột 1 là TENMH
        sv.TEN = studentList.cnt[i][2];
        sv.PHAI = studentList.cnt[i][3];
        sv.SODT = studentList.cnt[i][4];

        listclass.themSV(listclass,listclass.nodes[0].MALOP ,sv) ;

          // Gán danh sách sinh viên vừa tạo cho lớp `lop`
          // duyẹt tu dau đen cuoi loi coi lop nao còn trong gan 
        //lop.FIRST = sinhvien;
    // Đóng tệp sau khi xử lý
    file.close();
    }
     listclass.In34(listclass , listclass.nodes[0].MALOP) ; 
    // listclass2.nodes[0].FIRST.setHead(sinhvien.getHead()) ;  
    // sinhvien.setHead(nullptr) ; 

    return; 
}
void Data::getstudent1(fsys::path filepath) {
    // Kiểm tra nếu tệp có tồn tại
    std::ifstream file(filepath.generic_string());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
        //return;
    }

    // Đọc nội dung file CSV
    csvFile studentList(filepath);
    studentList.readFile();

    // Kiểm tra nếu file không chứa dữ liệu
    if (studentList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        //return;
    }

    DanhSachSV sinhvien ; 
    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < static_cast<size_t>(studentList.cnt.size()); ++i) {
        SinhVien sv;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (static_cast<size_t>(studentList.cnt[i].size()) < 4) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong MonHoc
        sv.MASV = studentList.cnt[i][0]; // Cột 0 là MAMH
        sv.HO = studentList.cnt[i][1]; // Cột 1 là TENMH
        sv.TEN = studentList.cnt[i][2];
        sv.PHAI = studentList.cnt[i][3];
        sv.SODT = studentList.cnt[i][4];

        sinhvien.insertSV(sv) ; 
        
          // Gán danh sách sinh viên vừa tạo cho lớp `lop`
          // duyẹt tu dau đen cuoi loi coi lop nao còn trong gan 
        //lop.FIRST = sinhvien;
    // Đóng tệp sau khi xử lý
    file.close();
    }
    // DS_LOPSV::getInstance().nodes[1].FIRST.head = sinhvien.getHead() ; 
    sinhvien.setHead(nullptr) ; 
    return; 
}
void Data::gettc(fsys::path filepath) {
    // Kiểm tra nếu tệp có tồn tại
    std::ifstream file(filepath.generic_string());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
        return;
    }

    // Đọc nội dung file CSV
    csvFile tinchiList(filepath);
    tinchiList.readFile();

    // Kiểm tra nếu file không chứa dữ liệu
    if (tinchiList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        return;
    }

    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < static_cast<size_t>(tinchiList.cnt.size()); ++i) {
        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (static_cast<size_t>(tinchiList.cnt[i].size()) < 9) { // Cần đủ 9 cột
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Khởi tạo đối tượng LopTinChi
        LopTinChi tc;

        try {
            tc.MALOPTC = std::stoi(tinchiList.cnt[i][0]); // Cột 0: MALOPTC
            tc.MAMH = tinchiList.cnt[i][1];               // Cột 1: MAMH
            tc.NienKhoa = tinchiList.cnt[i][2];           // Cột 2: NienKhoa
            tc.HocKy = std::stoi(tinchiList.cnt[i][3]);   // Cột 3: HocKy
            tc.Nhom = std::stoi(tinchiList.cnt[i][4]);    // Cột 4: Nhom
            tc.soSvMin = std::stoi(tinchiList.cnt[i][5]); // Cột 5: soSvMin
            tc.soSvMax = std::stoi(tinchiList.cnt[i][6]); // Cột 6: soSvMax
            // tc.HuyLop = (tinchiList.cnt[i][7] == "false"); // Cột 7: HuyLop
            if(tinchiList.cnt[i][7] == "false") tc.HuyLop = false ; // Cột 7: HuyLop
            else tc.HuyLop = true ;
            // tc.HuyLop = false ; // Cột 7: HuyLop
            
        } catch (const std::exception& e) {
            std::cerr << "Error parsing data at line " << i + 1 << ": " << e.what() << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu có lỗi
        }
       TinhchiList::getInstance().addTC(TinhchiList::getInstance() , tc);
    }
    // Đóng tệp sau khi xử lý
    file.close();
}
void Data::getdk(fsys::path filepath , TinhchiList& dsTC){
     // Kiểm tra nếu tệp có tồn tại
    std::ifstream file(filepath.generic_string());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
        //return;
    }
    // Đọc nội dung file CSV
    csvFile studentList(filepath);
    studentList.readFile();
    // Kiểm tra nếu file không chứa dữ liệu
    if (studentList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        //return;
    }
    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < static_cast<size_t>(studentList.cnt.size()); ++i) {
        DangKy dk;
        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (static_cast<size_t>(studentList.cnt[i].size()) < 2) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }
        // Đọc và gán giá trị cho các trường trong MonHoc
        dk.MASV = studentList.cnt[i][0]; // Cột 0 là MAMH
        dk.Diem = std::stof(studentList.cnt[i][1]); // Cột 1 là TENMH
        dk.Huy_Dang_Ky = false ;  
        dsTC.themdk(dsTC, dsTC.Nodes[0]->MALOPTC , dk ) ; 
        file.close();
    }
    // list.inDanhSach() ; 
    // list2.Nodes[0]->Dssvdk.head = list.getHead() ; 
    // // Sau khi chuyển, "ngắt kết nối" giữa list và danh sách mà nó kiểm soát
    // list.setHead(nullptr);
    return ; 
}
// void Data::getdk1(fsys::path filepath){
//      // Kiểm tra nếu tệp có tồn tại
//     std::ifstream file(filepath.generic_string());
//     if (!file.is_open()) {
//         std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
//         //return;
//     }
//     // Đọc nội dung file CSV
//     csvFile studentList(filepath);
//     studentList.readFile();
//     // Kiểm tra nếu file không chứa dữ liệu
//     if (studentList.cnt.empty()) {
//         std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
//         //return;
//     }
//     listDK list ; 
//     // Duyệt qua từng dòng dữ liệu trong tệp CSV
//     for (size_t i = 1; i < studentList.cnt.size(); ++i) {
//         DangKy dk;
//         // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
//         if (studentList.cnt[i].size() < 2) {
//             std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
//             continue; // Bỏ qua dòng nếu thiếu dữ liệu
//         }
//         // Đọc và gán giá trị cho các trường trong MonHoc
//         dk.MASV = studentList.cnt[i][0]; // Cột 0 là MAMH
//         dk.Diem = std::stof(studentList.cnt[i][1]); // Cột 1 là TENMH
//         dk.Huy_Dang_Ky = false ;  
//         list.themDangKy(dk) ; 
//         file.close();
//     }
//     list.inDanhSach() ; 
//     list2.Nodes[1]->Dssvdk.head = list.getHead() ; 
//     // Sau khi chuyển, "ngắt kết nối" giữa list và danh sách mà nó kiểm soát
//     list.setHead(nullptr);
//     return ; 
// }
//ham hien thi 
// void Data::displaylop(fsys::path filepath , sf::Font& font) {
//       if (!fsys::exists(filepath)) {
//         std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
//         return;
//     }
    
//     // Tạo đối tượng csvFile để đọc dữ liệu
//     csvFile lopList(filepath);
//     lopList.readFile(); 

//     // Đảm bảo rằng dữ liệu đã được đọc vào
//     if (lopList.cnt.empty()) {
//         std::cout << "File trống hoặc chưa được đọc!" << std::endl;
//         return;
//     }

//     float yPosition = 334.f;

//     // Duyệt qua từng dòng dữ liệu đã đọc từ file CSV
//     for (size_t i = 1; i < lopList.cnt.size(); ++i) {  // Bỏ qua dòng tiêu đề (nếu có)
//         const auto& row = lopList.cnt[i];

//         // Kiểm tra xem dòng có đủ dữ liệu không
//         if (row.size() < 2) {  // Giả sử chỉ có MALOP và TENLOP
//             std::cerr << "Dòng không hợp lệ trong dữ liệu CSV: " << i + 1 << std::endl;
//             continue;
//         }

//         // Đọc các trường từ dòng CSV (MALOP, TENLOP)
//         std::string MALOP = row[0];
//         std::string TENLOP = row[1];

//         // Tạo chuỗi thông tin lớp
//         Text ma(217.f, yPosition, 539.f, 54.f,  MALOP, font, sf::Color::Red, 15); 
//         Text lop(756.f, yPosition, 539.f, 54.f, TENLOP, font, sf::Color::Red, 15); 

//         // Thêm vào các vector
//         classList.push_back(ma);
//         classList.push_back(lop);

//         // Tạo nút cho lớp
//         float buttonWidth = std::max(150.f, static_cast<float>(MALOP.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
//         Button button(217.f, yPosition, buttonWidth, 58.f, MALOP, font, sf::Color::Red, 15);
//         Buttonclass.push_back(button);
//         Buttonclass.push_back(button);

//         //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
//         yPosition = (static_cast<int>(yPosition) + 100) ;
//         if (yPosition > 800)
//             yPosition = 334.f;
//     }
// }
void Data::displaylop(sf::Font& font , DS_LOPSV& listlop ) {
    cout << "DA VAO HAM HIEN THI LOP " << endl ;
      if (listlop.isEmpty(listlop)) {
        return;
    } 
    float yPosition = 334.f;
    // Duyệt qua từng dòng dữ liệu đã đọc từ file CSV
    for (int i = 0 ; i < listlop.n; ++i) {
    LopSV& a = listlop.nodes[i] ; 
        // Đọc các trường từ dòng CSV (MALOP, TENLOP)
        std::string MALOP = a.MALOP ;
        std::string TENLOP = a.TENLOP ;
        // Tạo chuỗi thông tin lớp
        Text ma(217.f, yPosition, 539.f, 54.f,  MALOP, font, sf::Color::Red, 15); 
        Text lop(756.f, yPosition, 539.f, 54.f, TENLOP, font, sf::Color::Red, 15); 

        // Thêm vào các vector
        classList.push_back(ma);
        classList.push_back(lop);
        // Tạo nút cho lớp
        float buttonWidth = std::max(150.f, static_cast<float>(MALOP.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
        Button button(217.f, yPosition, buttonWidth, 58.f, MALOP, font, sf::Color(218, 110, 50), 15);
        Buttonclass.push_back(button);
        Buttonclass.push_back(button);
        //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
        yPosition = (static_cast<int>(yPosition) + 100) ;
        if (yPosition > 800)
            yPosition = 334.f;
    }
    cout << "DA RA KHOI HAM HIEN THI LOP " << endl ; 
}
// void Data::displaymonhoc(fsys::path filepath, sf::Font& font) {
//     if (!fsys::exists(filepath)) {
//         std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
//         return;
//     }

//     csvFile monhocList(filepath);
//     monhocList.readFile();

//     if (monhocList.cnt.empty()) {
//         std::cout << "File rỗng hoặc chưa đọc được!" << std::endl;
//         return;
//     }

//     float yPosition = 422.f;

//     for (size_t i = 1; i < monhocList.cnt.size(); ++i) {
//         const auto& row = monhocList.cnt[i];

//         if (row.size() < 4) {
//             std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
//             continue;
//         }

//         std::string MAMH = row[0];
//         std::string TENMH = row[1];
//         int STCLT = 0;
//         int STCTH = 0;

//         try {
//             STCLT = std::stoi(row[2]);
//             STCTH = std::stoi(row[3]);
//         } catch (const std::exception& e) {
//             std::cerr << "Lỗi tại dòng " << i + 1 << ": " << e.what() << std::endl;
//             continue;
//         }

//         Text ma(68.f, yPosition, 234.f, 35.f, MAMH, font, sf::Color::Red, 15);
//         Text ten(302.f, yPosition, 422.f, 35.f, TENMH, font, sf::Color::Red, 15);
//         Text lt(724.f, yPosition, 260.f, 35.f, std::to_string(STCLT), font, sf::Color::Red, 15);
//         Text th(984.f, yPosition, 296.f, 35.f, std::to_string(STCTH), font, sf::Color::Red, 15);

//         subjectList.push_back(ma);
//         subjectList.push_back(ten);
//         subjectList.push_back(lt);
//         subjectList.push_back(th);

//         float buttonWidth = std::max(150.f, static_cast<float>(MAMH.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
//         Button button(68.f, yPosition, buttonWidth, 58.f, MAMH , font, sf::Color::Red, 15);
//         buttonsubject.push_back(button);
//         buttonsubject.push_back(button);
//         buttonsubject.push_back(button);
//         buttonsubject.push_back(button);

//         //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
//         yPosition = (static_cast<int>(yPosition) + 100) ;
//         if (yPosition > 800)
//             yPosition = 422.f;
//     }
// }

void Data::displaymonhoc(AVLTreeMH& listmh, sf::Font& font) {
    if (listmh.isEmpty(listmh.root)) {
        std::cerr << "Danh sách môn học rỗng." << std::endl;
        return;
    }

    float yPosition = 422.f; // Vị trí y ban đầu cho hiển thị
    int soluongmh = listmh.countMH(listmh.root) ; 
        MonHoc MH[soluongmh+1];
        int dem = 0 ; 
	    listmh.MangTam_MonHoc(listmh.root,MH,dem); //Do Cay Nhi Phan ra Mang?
        listmh.bubbleSortTENMH(MH,soluongmh) ;
        for(int i = 0 ; i < soluongmh ; i++ ){
        // Lấy thông tin môn học từ node hiện tại
        const std::string& MAMH = MH[i].MAMH;
        const std::string& TENMH = MH[i].TENMH;
        const std::string STCLT = std::to_string(MH[i].STCLT);
        const std::string STCTH = std::to_string(MH[i].STCTH);

        // Tạo các đối tượng Text và Button cho từng thuộc tính
        Text ma(68.f, yPosition, 234.f, 35.f, MAMH, font, sf::Color::Red, 15);
        Text ten(302.f, yPosition, 422.f, 35.f, TENMH, font, sf::Color::Red, 15);
        Text lt(724.f, yPosition, 260.f, 35.f, STCLT, font, sf::Color::Red, 15);
        Text th(984.f, yPosition, 296.f, 35.f, STCTH, font, sf::Color::Red, 15);

        subjectList.push_back(ma);
        subjectList.push_back(ten);
        subjectList.push_back(lt);
        subjectList.push_back(th);

        float buttonWidth = std::max(150.f, static_cast<float>(MAMH.size() * 10)); // Tính chiều rộng nút
        Button button(68.f, yPosition, buttonWidth, 58.f, MAMH, font, sf::Color(218, 110, 50), 15);

        buttonsubject.push_back(button);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);
        // Tăng vị trí y cho dòng tiếp theo
        yPosition += 100.f;
        if (yPosition > 800.f) yPosition = 422.f;

    }
}


void Data::displaystudent(int vitri, sf::Font& font) {
    cout << "DI DEN HAM HIEN THI SINH VIEN\n " ; 
    cout << "Vi tri la : " << vitri << endl ;
    cout << "DANH SACH SINH VIEN CUA LOP : " << DS_LOPSV::getInstance().nodes[vitri].MALOP << endl ;
    float yPosition = 410.f;
     for (PTRSV p = DS_LOPSV::getInstance().nodes[vitri].FIRST.getHead(); p != nullptr; p = p->next) {
        // if (p->sv.MASV.empty() || p->sv.HO.empty() || p->sv.TEN.empty() || p->sv.PHAI.empty() || p->sv.SODT.empty()) {
        //     cout << "Invalid student data" << endl;
        //     continue; // Bỏ qua node không hợp lệ
        // }
        std::string MASV1 = p->sv.MASV;
        std::string HO1 = p->sv.HO;
        std::string TEN1 = p->sv.TEN;   // Sửa lỗi gán nhầm
        std::string PHAI1 = p->sv.PHAI;
        std::string SODT1 = p->sv.SODT;
         // In ra console
        std::cout << "MASV: " << MASV1
                  << ", HO: " << HO1 
                  << ", TEN: " << TEN1 
                  << ", PHAI: " << PHAI1 
                  << ", SODT: " << SODT1 << std::endl;

        Text ma(9.f, yPosition, 272.f, 50.f, MASV1, font, sf::Color::Red, 15);
        Text ho(273.f, yPosition, 272.f, 50.f, HO1, font, sf::Color::Red, 15);
        Text ten(544.f, yPosition, 272.f, 50.f, TEN1, font, sf::Color::Red, 15);
        Text phai(815.f, yPosition, 272.f, 50.f, PHAI1, font, sf::Color::Red, 15);
        Text sodt(1092.f, yPosition, 272.f, 50.f, SODT1, font, sf::Color::Red, 15);

        StudentList.push_back(ma);
        StudentList.push_back(ho);
        StudentList.push_back(ten);
        StudentList.push_back(phai);
        StudentList.push_back(sodt);

        float buttonWidth = std::max(150.f, static_cast<float>(MASV1.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
        Button button(68.f, yPosition, buttonWidth, 58.f, MASV1, font, sf::Color(218, 110, 50), 15);
        ButtonStudent.push_back(button);
        ButtonStudent.push_back(button);
        ButtonStudent.push_back(button);
        ButtonStudent.push_back(button);
        ButtonStudent.push_back(button);

        //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
        yPosition = (static_cast<int>(yPosition) + 100) ;
        if (yPosition > 800)
            yPosition = 410.f;
    }
    cout << "DI RA KHOI HAM HIEN THI SINH VIEN\n " ;
}
void Data::displaytc1(TinhchiList& list, sf::Font& font) {
    cout << "DA VAO HAM HIEN THI LOP TIN CHI " ;
    if (list.isEmpty()) {
        std::cout << "Danh sách lớp tín chỉ trống.\n";
        return;
    }

    float yPosition = 295.f;

    for (int i = 0; i < list.n; ++i) {
        LopTinChi* tc = list.Nodes[i];

        // In thông tin ra console
        std::cout << "MALOPTC: " << tc->MALOPTC << "\n"
                  << "MAMH: " << tc->MAMH << "\n"
                  << "NienKhoa: " << tc->NienKhoa << "\n"
                  << "HocKy: " << tc->HocKy << "\n"
                  << "Nhom: " << tc->Nhom << "\n"
                  << "MinSV: " << tc->soSvMin << "\n"
                  << "MaxSV: " << tc->soSvMax << "\n"
                  << "HuyLop: " << (tc->HuyLop ? "HUY" : "NO") << "\n"
                  << "-----------------------\n";

        // Tạo các đối tượng Text cho từng cột
        Text a(22.f, yPosition, 170.f, 59.f, std::to_string(tc->MALOPTC), font, sf::Color::Red, 15);
        Text d(192.f, yPosition, 170.f, 59.f, tc->MAMH, font, sf::Color::Red, 15);
        Text b(362.f, yPosition, 170.f, 59.f, tc->NienKhoa, font, sf::Color::Red, 15);
        Text c(532.f, yPosition, 170.f, 59.f, std::to_string(tc->HocKy), font, sf::Color::Red, 15);
        Text f(702.f, yPosition, 170.f, 59.f, std::to_string(tc->Nhom), font, sf::Color::Red, 15);
        Text g(876.f, yPosition, 170.f, 59.f, std::to_string(tc->soSvMin), font, sf::Color::Red, 15);
        Text e(1042.f, yPosition, 170.f, 59.f,std::to_string(tc->soSvMax), font, sf::Color::Red, 15);
        Text h(1212.f, yPosition, 170.f, 59.f, (tc->HuyLop ? "HUY" : " "), font, sf::Color::Red, 15);

        // Đẩy vào danh sách đối tượng hiển thị
        TCList.push_back(a);
        TCList.push_back(b);
        TCList.push_back(c);
        TCList.push_back(d);
        TCList.push_back(e);
        TCList.push_back(f);
        TCList.push_back(g);
        TCList.push_back(h);

        // Tạo button hiển thị thông tin lớp và môn học
        float buttonWidth = std::max(150.f, static_cast<float>(std::to_string(tc->MALOPTC).size() * 10));
        Button button(22.f, yPosition, buttonWidth, 59.f,std::to_string(tc->MALOPTC), font, sf::Color(218, 110, 50), 15);
        buttonTC.push_back(button);
        buttonTC.push_back(button);
        buttonTC.push_back(button);
        buttonTC.push_back(button);
        buttonTC.push_back(button);
        buttonTC.push_back(button);
        buttonTC.push_back(button);
        buttonTC.push_back(button);
        // Điều chỉnh vị trí Y cho dòng tiếp theo
        yPosition += 100;
        if (yPosition > 800)  // Đặt lại yPosition khi vượt quá giới hạn
            yPosition = 295.f;
    }
}
void Data::displaytc2(TinhchiList& list, sf::Font& font, string nienKhoa, int hocKy) {
    if (list.isEmpty()) {
        std::cout << "Danh sách lớp tín chỉ trống.\n";
        return;
    }

    float yPosition = 372.f;

    for (int i = 0; i < list.n; ++i) {
        LopTinChi* tc = list.Nodes[i];

        // Lọc lớp tín chỉ theo niên khóa và học kỳ
        if (tc->NienKhoa != nienKhoa || tc->HocKy != hocKy) {
            continue;  // Bỏ qua lớp tín chỉ không phù hợp
        }

        // Tính số sinh viên đăng ký (dựa trên số sinh viên hiện tại trong danh sách đăng ký)
        // int soSinhVienDangKi = tc->soSvMax - tc->soSvMin;  // Ví dụ, có thể thay đổi theo cách tính thực tế của bạn
         int soSinhVienDangKi = tc->Dssvdk.size(tc->Dssvdk) ;   // Ví dụ, có thể thay đổi theo cách tính thực tế của bạn
        cout << soSinhVienDangKi ;
        // Xác định lớp có "TRONG" hay không (chưa đầy sinh viên)
        int trong1 = tc->soSvMax - soSinhVienDangKi ; 
        string trong = std::to_string(trong1) ; 
        // std::string trong = (soSinhVienDangKi < tc->soSvMax) ? "Yes" : "No";
        cout << trong1 ;

        // In thông tin ra console
        std::cout << "MALOPTC: " << tc->MALOPTC << "\n"
                  << "MAMH: " << tc->MAMH << "\n"
                  << "SoSinhVienDangKi: " << soSinhVienDangKi << "\n"
                  << "Nhom: " << tc->Nhom << "\n"
                  << "TRONG: " << trong << "\n"
                  << "-----------------------\n";

        // Tạo các đối tượng Text cho từng cột
        Text a(500.f, yPosition, 170.f, 59.f, std::to_string(tc->MALOPTC), font, sf::Color::Red, 15);
        Text b(790.f, yPosition, 170.f, 59.f, tc->MAMH, font, sf::Color::Red, 15);
        Text c(1108.f, yPosition, 170.f, 59.f,std::to_string(tc->Nhom) , font, sf::Color::Red, 15);  // Số sinh viên đăng ký
        Text d(1340.f, yPosition, 170.f, 59.f,std::to_string(soSinhVienDangKi) , font, sf::Color::Red, 15);
        Text e(1543.f, yPosition, 170.f, 59.f, trong, font, sf::Color::Red, 15);

        // Đẩy vào danh sách đối tượng hiển thị
        TCList1.push_back(a);
        TCList1.push_back(b);
        TCList1.push_back(c);
        TCList1.push_back(d);
        TCList1.push_back(e);
        // Điều chỉnh vị trí Y cho dòng tiếp theo
        yPosition += 80;
        if (yPosition > 496)  // Đặt lại yPosition khi vượt quá giới hạn
            yPosition = 372.f;
    }
}
void Data::displaytchuy(TinhchiList& list, sf::Font& font, string nienKhoa, int hocKy) {
    if (list.isEmpty()) {
        std::cout << "Danh sách lớp tín chỉ trống.\n";
        return;
    }

    float yPosition = 609.f;

    for (int i = 0; i < list.n; ++i) {
        LopTinChi* tc = list.Nodes[i];
        listDK dk ;
        // Lọc lớp tín chỉ theo niên khóa và học kỳ
        if (tc->NienKhoa != nienKhoa || tc->HocKy != hocKy) {
            continue;  // Bỏ qua lớp tín chỉ không phù hợp
        }
        if(dk.size(tc->Dssvdk)  >= tc->soSvMin )
        {
            continue; 
        } 

        // Tạo các đối tượng Text cho từng cột
        Text a(533.f, yPosition, 170.f, 59.f, std::to_string(tc->MALOPTC), font, sf::Color::Red, 15);
        Text b(790.f, yPosition, 170.f, 59.f, tc->NienKhoa, font, sf::Color::Red, 15);
        Text c(1015.f, yPosition, 170.f, 59.f,std::to_string(tc->HocKy) , font, sf::Color::Red, 15);  // Số sinh viên đăng ký
        Text d(1256.f, yPosition, 170.f, 59.f,tc->MAMH, font, sf::Color::Red, 15);
        Text e(1543.f, yPosition, 170.f, 59.f, std::to_string(tc->Nhom), font, sf::Color::Red, 15);

        // Đẩy vào danh sách đối tượng hiển thị
        TCList2.push_back(a);
        TCList2.push_back(b);
        TCList2.push_back(c);
        TCList2.push_back(d);
        TCList2.push_back(e);

        // Điều chỉnh vị trí Y cho dòng tiếp theo
        yPosition += 80;
        if (yPosition > 800)  // Đặt lại yPosition khi vượt quá giới hạn
            yPosition = 609.f;
    }
}
bool Data::add(fsys::path filepath, sf::Font& font, custom::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Thêm một dòng dữ liệu mới vào bộ nhớ (cnt)
    bool rowAdded = file.addRow();  // Thêm một hàng mới (hàng trống)
    
    // Kiểm tra nếu việc thêm hàng thành công
    if (!rowAdded) {
        std::cerr << "Không thể thêm dữ liệu vào bộ nhớ." << std::endl;
        return false;  // Không thể thêm hàng vào bộ nhớ
    }

    // Cập nhật dữ liệu trong hàng mới
    file.cnt[file.cnt.size() - 1] = newRow;

    // Ghi lại dữ liệu vào tệp CSV
    if (file.writeFile()) {
        std::cout << "Dữ liệu đã được thêm vào tệp CSV thành công!" << std::endl;
        return true;  // Dữ liệu đã được thêm và ghi vào tệp thành công
    } else {
        std::cerr << "Không thể ghi dữ liệu vào tệp CSV." << std::endl;
        return false;  // Không thể ghi dữ liệu vào tệp
    }
}
void Data::deletefile(fsys::path filepath, string& key) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();
    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < static_cast<size_t>(file.cnt.size()); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == key) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << " xoa thanh phan co ma " << key << " thành công.\n";
            return;
        }
    }
    std::cerr << "Khong co  thanh phan co ma " << key << ".\n";
}
void Data::update(fsys::path filepath, const std::string& keyToUpdate, const custom::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();
    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == keyToUpdate) {
            // Cập nhật thông tin môn học từ newRow
            if (newRow.size() == row.size()) {
                row = newRow;  // Thay thế toàn bộ hàng bằng newRow
                found = true;
            } else {
                std::cerr << "Dữ liệu trong newRow không phù hợp với số lượng cột trong file.\n";
                return;  // Thoát khỏi hàm nếu số lượng cột không khớp
            }
            break;
        }
    }
    // Nếu không tìm thấy môn học, in ra thông báo lỗi
    if (!found) {
        std::cerr << "keyupdatekeyupdate " << keyToUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }
    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }
    std::cout << "keyupdate đã được cập nhật thành công.\n";
}
// xu li du lieu khac 
string Data::formatFloat(float value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value; // Định dạng 2 chữ số thập phân
    return oss.str();
}
bool Data::isNumber( std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '-') {  // '-' for negative numbers
            return false;
        }
    }
    return true;
}
// 
// hiển thị thông báo 
bool Data::confirm(std::string content)
{
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return false ; // Return error if font can't be loaded
    }
    sf::RenderWindow windowNext(sf::VideoMode(636, 301), "Notification", sf::Style::Close | sf::Style::Titlebar);
    windowNext.setPosition(sf::Vector2i(500, 400));
    std::cout << "Generate popup sucess" << std::endl;
    Button yesBtn(310.f, 241.f, 60, 45, "Yes", font , sf :: Color :: Red, 15 );
    Button noBtn(230.f, 241.f, 60, 45, "No", font , sf :: Color :: Red, 15 );
    Text text(140.f, 95.f ,  60 , 45  , content, font ,  sf :: Color :: Red, 15);
    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                if (yesBtn.isClicked(mousePos)) {
                    windowNext.close();
                    return true;
                }
                if (noBtn.isClicked(mousePos)) {
                    windowNext.close();
                    return false;
                }
            }
        }
        windowNext.clear(sf::Color::White);
        text.draw(windowNext);
        yesBtn.draw(windowNext);
        noBtn.draw(windowNext);
        windowNext.display();
    }
    return false;
}
void Data::popup(std::string content)
{
      sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return ; // Return error if font can't be loaded
    }
    sf::RenderWindow windowNext(sf::VideoMode(636, 301), "Notification", sf::Style::Close | sf::Style::Titlebar);
    windowNext.setPosition(sf::Vector2i(500, 400));
    std::cout << "Generate popup sucess" << std::endl;
    Button okBtn(246.f, 241.f, 143, 45, "OKAY", font , sf :: Color ::  Red , 15);
    Text text(100, 95, 60 , 40  , content, font , sf :: Color ::  Red , 15);
    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::KeyPressed) {
                if (event.text.unicode == '\r') windowNext.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (okBtn.isClicked(mousePos))
                    windowNext.close();
            }
        }
        windowNext.clear(sf::Color::White);
        text.draw(windowNext);
        okBtn.draw(windowNext);
        windowNext.display();
    }
}
// void Data::diemmhtc(fsys::path filepath, sf::Font& font, int vitri) {
//     if (!fsys::exists(filepath)) {
//         std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
//         return;
//     }
//     csvFile diemlist(filepath);
//     diemlist.readFile();
//     if (diemlist.cnt.empty()) {
//         std::cerr << "File rỗng hoặc không đọc được!" << std::endl;
//         return;
//     }
//     Text stt(76.f, 187, 170.f, 40.f, "STT", font, sf::Color::Red, 15);
//     Text ma(246.f, 187, 295.f, 40.f, "MASV", font, sf::Color::Red, 15);
//     Text ho(539.f, 187, 500.f, 40.f, "HO", font, sf::Color::Red, 15);
//     Text ten1(1039.f, 187, 351.f, 40.f, "TEN", font, sf::Color::Red, 15);
//     Text th(1390.f, 187, 186.f, 40.f, "DIEM", font, sf::Color::Red, 15);
//     baocao.push_back(stt);
//     baocao.push_back(ma);
//     baocao.push_back(ho);
//     baocao.push_back(ten1);
//     baocao.push_back(th);

//     float yPosition = 228.f;
//     int STT = 0;
//      cout << "den day " ; 
//     for (size_t i = 1; i < static_cast<size_t>(diemlist.cnt.size()); ++i) {
//         const auto& row = diemlist.cnt[i];
//         if (row.size() < 3) {
//             std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
//             continue;
//         }

//         std::string MASV = row[0];
//         std::string MALOP = row[1];
//         int MALOPTC  = std::stoi(row[2]);
//         if (MALOPTC == vitri) {
//             continue;
//         }
//         cout << MASV ; 
//         int idex = 0  ; 
//         int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(), MALOP, DS_LOPSV::getInstance().n);
//         cout << temp ; 
//         if(temp != 0){
//             if(temp == -1)
//                 {
//                     idex = 0;	
//                 }else{
//                     idex = temp;
//                     }
//                 } 
//         PTRSV k = DS_LOPSV::getInstance().nodes[idex].FIRST.findStudentByMASV1(MASV);
//         std::string ho, ten;
//             if(k != NULL){
//             ho = k->sv.HO;
//             ten = k->sv.TEN ;
//             }

//         LopTinChi* tc = TinhchiList::getInstance().Nodes[vitri];
//         if (!tc) {
//             std::cerr << "Không tìm thấy lớp tín chỉ tại vị trí: " << vitri << std::endl;
//             continue;
//         }
//         PTRDK p = tc->Dssvdk.findStudentByMASV(MASV);
//         if (!p) {
//             std::cerr << "Không tìm thấy điểm cho MASV: " << MASV << std::endl;
//             continue;
//         }
//         Text stt(76.f, yPosition, 170.f, 40.f, std::to_string(STT + 1), font, sf::Color::Red, 15);
//         Text ma(246.f, yPosition, 295.f, 40.f, MASV, font, sf::Color::Red, 15);
//         Text ho1(539.f, yPosition, 500.f, 40.f, ho, font, sf::Color::Red, 15);
//         Text ten1(1039.f, yPosition, 351.f, 40.f, ten, font, sf::Color::Red, 15);
//         Text th(1390.f, yPosition, 186.f, 40.f, std::to_string(p->sv.Diem), font, sf::Color::Red, 15);

//         baocao.push_back(stt);
//         baocao.push_back(ma);
//         baocao.push_back(ho1);
//         baocao.push_back(ten1);
//         baocao.push_back(th);

//         yPosition += 100.f;
//         if (yPosition > 800.f)
//             yPosition = 228.f;

//         STT++;
//     }
// }
void Data::diemmhtc(fsys::path filepath, sf::Font& font, int vitri) {
    if (!fsys::exists(filepath)) {
        std::cerr << "KHONG TIM THAY FILE: " << filepath.string() << std::endl;
        return;
    }

    std::cout << "DOC FILE " << filepath.string() << std::endl;
    csvFile diemlist(filepath);
    diemlist.readFile();

    if (diemlist.cnt.empty()) {
        std::cerr << "FILE RONG HOAC KHONG DOC DUOC" << std::endl;
        return;
    }

    std::cout << "SO LUONG DONG TRONG FILE" << diemlist.cnt.size() << std::endl;

    // Khởi tạo các tiêu đề cột
    Text stt(76.f, 187, 170.f, 40.f, "STT", font, sf::Color::Red, 15);
    Text ma(246.f, 187, 295.f, 40.f, "MASV", font, sf::Color::Red, 15);
    Text ho(539.f, 187, 500.f, 40.f, "HO", font, sf::Color::Red, 15);
    Text ten1(1039.f, 187, 351.f, 40.f, "TEN", font, sf::Color::Red, 15);
    Text th(1390.f, 187, 186.f, 40.f, "DIEM", font, sf::Color::Red, 15);
    baocao.push_back(stt);
    baocao.push_back(ma);
    baocao.push_back(ho);
    baocao.push_back(ten1);
    baocao.push_back(th);

    float yPosition = 228.f;
    int STT = 0;
    for (size_t i = 1; i < static_cast<size_t>(diemlist.cnt.size()); ++i) {
        const auto& row = diemlist.cnt[i];
        if (row.size() < 3) {
            std::cerr << "DONG KHONG HOP LE TAI DONG : " << i + 1 << std::endl;
            continue;
        }

        std::string MASV = row[0];
        std::string MALOP = row[1];
        int MALOPTC = std::stoi(row[2]);

        std::cout << "DONG " << i + 1 << ": MASV = " << MASV << ", MALOP = " << MALOP << ", MALOPTC = " << MALOPTC << std::endl;
        if (MALOPTC != vitri ) {
            std::cout << "BO QUA VI MA LOP TINH CHI KHONG KHOP" << std::endl;
            continue;
        }
        int idex = 0  ; 
        int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(), MALOP, DS_LOPSV::getInstance().n);
        if(temp != 0){
            if(temp == -1)
                {
                    idex = 0;	
                }else{
                    idex = temp;
                    }
                } 
        PTRSV k = DS_LOPSV::getInstance().nodes[idex].FIRST.findStudentByMASV1(MASV);

        std::string ho, ten;
        if (k != nullptr) {
            ho = k->sv.HO;
            ten = k->sv.TEN;
        }
        cout << ho << " " << ten << endl ;
        LopTinChi* tc = TinhchiList::getInstance().Nodes[MALOPTC - 1];
        if (!tc) {
            std::cerr << "KHONG TIM THAY LOP TINH CHI TAI VI TRI " << vitri << std::endl;
            continue;
        }

        PTRDK p = tc->Dssvdk.findStudentByMASV(MASV);
        if (!p) {
            std::cerr << "KHONG THAY DIEM CHO MA SINH VIEN " << MASV << std::endl;
            continue;
        }

        std::cout << "THEM DIEM CHO MASV: " << MASV << ", HO: " << ho << ", TEN: " << ten << ", DIEM: " << p->sv.Diem << std::endl;
         // Làm tròn và chuyển thành chuỗi với 2 chữ số sau dấu thập phân
                string diemString = " " ; 
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(2) << p->sv.Diem;
                diemString = oss.str();
        Text stt(76.f, yPosition, 170.f, 40.f, std::to_string(STT + 1), font, sf::Color::Red, 15);
        Text ma(246.f, yPosition, 295.f, 40.f, MASV, font, sf::Color::Red, 15);
        Text ho1(539.f, yPosition, 500.f, 40.f, ho, font, sf::Color::Red, 15);
        Text ten1(1039.f, yPosition, 351.f, 40.f, ten, font, sf::Color::Red, 15);
        Text th(1390.f, yPosition, 186.f, 40.f, diemString, font, sf::Color::Red, 15);

        baocao.push_back(stt);
        baocao.push_back(ma);
        baocao.push_back(ho1);
        baocao.push_back(ten1);
        baocao.push_back(th);

        yPosition += 100.f;
        if (yPosition > 800.f)
            yPosition = 228.f;

        STT++;
    }

    std::cout << "HOAN THANH XU LY DU LIEU " << std::endl;
}

// void Data::diemtb(fsys::path filepath, sf::Font& font, int vitri) {
//      // Kiểm tra sự tồn tại của file
//     if (!fsys::exists(filepath)) {
//         std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
//         return;
//     }
//     csvFile diemlist(filepath);
//     diemlist.readFile();
//     if (diemlist.cnt.empty()) {
//         std::cerr << "File rỗng hoặc không đọc được!" << std::endl;
//         return;
//     }

//     LopSV& lop = DS_LOPSV::getInstance().nodes[vitri];
//     string malop = lop.MALOP ; 
//     cout << malop ;
//     if (lop.FIRST.getHead() == nullptr) {
//         std::cout << "Lop nay chua co sinh vien!\n";
//         return;
//     }
//     //Đếm số lượng sinh viên
//     int soluongsv = lop.FIRST.size(lop.FIRST) ; 
//     cout << soluongsv ;
//     if(soluongsv){
//         cout << " CO SINH VIEN" ;
//     }
//      //Lấy danh sách sinh viên
//     SinhVien *dsSinhVien = new SinhVien[soluongsv];
//     int index = 0;
//     for (PTRSV p = lop.FIRST.getHead(); p != nullptr; p = p->next) {
//         dsSinhVien[index++] = p->sv ;
//     } 
//     std::vector<int> dssv[soluongsv] ; 
//     std::vector<float> diemtb ; 
//     Text stt(127.f, 128.f, 125.f, 40.f, "STT", font, sf::Color::Red, 15);
//     Text ma(252.f, 128.f, 224.f, 40.f, "MASV", font, sf::Color::Red, 15);
//     Text ho(476.f, 128.f, 314.f, 40.f, "HO", font, sf::Color::Red, 15);
//     Text ten1(790.f, 128.f, 567.f, 40.f, "TEN", font, sf::Color::Red, 15);
//     Text th(1360.f, 128.f, 223.f, 40.f, "DIEM", font, sf::Color::Red, 15);
//     baocao.push_back(stt);
//     baocao.push_back(ma);
//     baocao.push_back(ho);
//     baocao.push_back(ten1);
//     baocao.push_back(th);
//     for (size_t i = 1; i < diemlist.cnt.size(); ++i) {
//         const auto& row = diemlist.cnt[i];
//         if (row.size() < 3) {
//             std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
//             continue;
//         }
//         std::string MASV = row[0];
//         std::string MALOP = row[1];
//         int MALOPTC  = std::stoi(row[2]);
//         if (MALOP != malop) {
//             continue;
//         }
//         for(int j = 0 ; j < soluongsv ; j++ ){
//             if(dsSinhVien[j].MASV ==  MASV){
//             dssv[j].push_back(MALOPTC) ; 
//             }
//         }
//     }
//     for (int  i = 0; i < soluongsv; ++i) {
//     if (!dssv[i].empty()) { // Nếu dssv[i] không rỗng
//         std::cout << "SINH VIEN " << dsSinhVien[i].MASV << " CO THONG TIN LOP TC \n";
//         for (int maloptc : dssv[i]) {
//             std::cout << "- MA LOP TC  " << maloptc << std::endl;
//         }
//     } else {
//         std::cout << "SINH VIEN" << dsSinhVien[i].MASV << " CHUA CO THONG TIN LOP TC \n";
//     }
// }

//     for (int i = 0; i < soluongsv; i++) {
//         // float ketqua = 0;
//         // int tongtinchi = 0;
//         // for (int j = 0 ; j < dssv[i].size() ; j++ ) {
//         //     int temp = dssv[i][j] ;
//         //     LopTinChi* tc = TinhchiList::getInstance().Nodes[temp] ;
//         //         string mamh =  tc->MAMH ; 
//         //         cout << "chjay den day " ;
//         //         PTRMH k = AVLTreeMH::getInstance().findMonHoc(AVLTreeMH::getInstance().root,mamh) ;
//         //         tongtinchi += k->mh.STCLT + k->mh.STCTH;
//         //         PTRDK p = tc->Dssvdk.findMASV(dsSinhVien[i].MASV) ;
//         //             ketqua = p->sv.Diem * tongtinchi ; 
//         //         }
//         //     ketqua = ketqua/tongtinchi;
//         //     diemtb.push_back(ketqua) ; 
//             float ketqua = Data::TinhDiemTrungBinh(dssv[i], dsSinhVien[i].MASV);
//             cout << "DA RA KHOI HAM " ; 
//             diemtb.push_back(ketqua);
//         }
//         for(size_t  i = 0 ; i < diemtb.size() ; i++){
//             cout << diemtb[i] << " " ; 
//         }
//         cout << "CHJAY DEN DAY ROI " ; 
//         float yPosition = 167.f;
//         for (int i = 0; i < soluongsv; i++) {
//         Text stt(127.f, yPosition, 125.f, 40.f, std::to_string(i), font, sf::Color::Red, 15);
//         Text ma(252.f, yPosition, 224.f, 40.f, dsSinhVien[i].MASV, font, sf::Color::Red, 15);
//         Text ho1(476.f, yPosition, 314.f, 40.f, dsSinhVien[i].HO, font, sf::Color::Red, 15);
//         Text ten1(790.f, yPosition, 567.f, 40.f, dsSinhVien[i].TEN, font, sf::Color::Red, 15);
//         Text th(1360.f, yPosition, 223.f, 40.f, std::to_string(diemtb[i]), font, sf::Color::Red, 15);
//         baocao.push_back(stt);
//         baocao.push_back(ma);
//         baocao.push_back(ho1);
//         baocao.push_back(ten1);
//         baocao.push_back(th);
//         yPosition += 100.f;
//         if (yPosition > 800.f)
//             yPosition = 167.f;
//     }
//     delete[] dsSinhVien;
// }
void Data::diemtb(fsys::path filepath, sf::Font& font, int vitri) {
    // Kiem tra su ton tai cua file
    if (!fsys::exists(filepath)) {
        std::cerr << "Khong tim thay file: " << filepath.string() << std::endl;
        return;
    }
    std::cout << "Da tim thay file: " << filepath.string() << std::endl;

    csvFile diemlist(filepath);
    diemlist.readFile();
    if (diemlist.cnt.empty()) {
        std::cerr << "File rong hoac khong doc duoc!" << std::endl;
        return;
    }
    std::cout << "Doc file CSV thanh cong!\n";

    LopSV& lop = DS_LOPSV::getInstance().nodes[vitri];
    std::string malop = lop.MALOP;
    std::cout << "Lay thong tin ma lop: " << malop << std::endl;

    if (lop.FIRST.getHead() == nullptr) {
        std::cout << "Lop nay chua co sinh vien!\n";
        return;
    }

    // Dem so luong sinh vien
    int soluongsv = lop.FIRST.size(lop.FIRST);
    std::cout << "So luong sinh vien trong lop: " << soluongsv << std::endl;

    if (soluongsv) {
        std::cout << "Lop co sinh vien, tiep tuc xu ly...\n";
    }

    // Lay danh sach sinh vien
    SinhVien* dsSinhVien = new SinhVien[soluongsv];
    int index = 0;
    for (PTRSV p = lop.FIRST.getHead(); p != nullptr; p = p->next) {
        dsSinhVien[index++] = p->sv;
    }
    std::cout << "Danh sach sinh vien da duoc lay thanh cong.\n";

    custom::vector<int> dssv[soluongsv];
    std::vector<float> diemtb;

    // Them cac tieu de vao bao cao
    Text stt(127.f, 128.f, 125.f, 40.f, "STT", font, sf::Color::Red, 15);
    Text ma(252.f, 128.f, 224.f, 40.f, "MASV", font, sf::Color::Red, 15);
    Text ho(476.f, 128.f, 314.f, 40.f, "HO", font, sf::Color::Red, 15);
    Text ten1(790.f, 128.f, 567.f, 40.f, "TEN", font, sf::Color::Red, 15);
    Text th(1360.f, 128.f, 223.f, 40.f, "DIEM", font, sf::Color::Red, 15);
    baocao.push_back(stt);
    baocao.push_back(ma);
    baocao.push_back(ho);
    baocao.push_back(ten1);
    baocao.push_back(th);

    // Doc du lieu tu file CSV va xu ly
    for (size_t i = 1; i < static_cast<size_t>(diemlist.cnt.size()); ++i) {
        const auto& row = diemlist.cnt[i];
        if (row.size() < 3) {
            std::cerr << "Dong khong hop le trong du lieu CSV tai dong: " << i + 1 << std::endl;
            continue;
        }
        std::string MASV = row[0];
        std::string MALOP = row[1];
        int MALOPTC = std::stoi(row[2]);
        if (MALOP != malop) {
            continue;
        }
        for (int j = 0; j < soluongsv; j++) {
            if (dsSinhVien[j].MASV == MASV) {
                dssv[j].push_back(MALOPTC);
                std::cout << "Sinh vien " << MASV << " tham gia lop tin chi " << MALOPTC << std::endl;
            }
        }
    }

    // Hien thi thong tin sinh vien co lop tin chi
    for (int i = 0; i < soluongsv; ++i) {
        if (!dssv[i].empty()) {
            std::cout << "SINH VIEN " << dsSinhVien[i].MASV << " co thong tin lop tin chi:\n";
            for (int maloptc : dssv[i]) {
                std::cout << "- Ma lop tin chi: " << maloptc << std::endl;
            }
        } else {
            std::cout << "SINH VIEN " << dsSinhVien[i].MASV << " chua co thong tin lop tin chi.\n";
        }
    }

    // Tinh diem trung binh
    for (int i = 0; i < soluongsv; i++) {
        float ketqua = Data::TinhDiemTrungBinh(dssv[i], dsSinhVien[i].MASV);
        std::cout << "Diem trung binh cua sinh vien " << dsSinhVien[i].MASV << ": " << ketqua << std::endl;
        diemtb.push_back(ketqua);
    }

    // Xuat ket qua ra console
    std::cout << "Danh sach diem trung binh:\n";
    for (size_t i = 0; i < diemtb.size(); i++) {
        std::cout << "- Sinh vien " << dsSinhVien[i].MASV << ": " << diemtb[i] << std::endl;
    }

    // Hien thi thong tin len man hinh
    string diemString = " " ; 
    float yPosition = 167.f;
    for (int i = 0; i < soluongsv; i++) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << diemtb[i];
        diemString = oss.str();
        Text stt(127.f, yPosition, 125.f, 40.f, std::to_string(i + 1), font, sf::Color::Red, 15);
        Text ma(252.f, yPosition, 224.f, 40.f, dsSinhVien[i].MASV, font, sf::Color::Red, 15);
        Text ho1(476.f, yPosition, 314.f, 40.f, dsSinhVien[i].HO, font, sf::Color::Red, 15);
        Text ten1(790.f, yPosition, 567.f, 40.f, dsSinhVien[i].TEN, font, sf::Color::Red, 15);
        Text th(1360.f, yPosition, 223.f, 40.f, diemString, font, sf::Color::Red, 15);
        baocao.push_back(stt);
        baocao.push_back(ma);
        baocao.push_back(ho1);
        baocao.push_back(ten1);
        baocao.push_back(th);
        yPosition += 100.f;
        if (yPosition > 800.f) {
            yPosition = 167.f;
        }
    }

    delete[] dsSinhVien;
    std::cout << "Hoan thanh viec xu ly diem trung binh.\n";
}

// void Data::diemtk(fsys::path filepath, sf::Font& font , int vitri) {
//     if (!fsys::exists(filepath)) {
//         std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
//         return;
//     }
//     csvFile diemlist(filepath);
//     diemlist.readFile();

//     if (diemlist.cnt.empty()) {
//         std::cerr << "File rỗng hoặc không đọc được!" << std::endl;
//         return;
//     }
//     int soluongmh = 0 ; 
//     vector<string> dsTenMH; // Vector lưu tên môn học không trùng
//     for (int i = 0; i < TinhchiList::getInstance().n; i++) {
//         bool daTonTai = false;
//         // Kiểm tra xem tên môn học đã tồn tại trong vector chưa
//         for (const auto& tenMH : dsTenMH) {
//             if (TinhchiList::getInstance().Nodes[i]->MAMH == tenMH) {
//                 daTonTai = true;
//                 break;
//             }
//         }
//         // Nếu chưa tồn tại, thêm vào vector
//         if (!daTonTai) {
//             dsTenMH.push_back(TinhchiList::getInstance().Nodes[i]->MAMH);
//         }
//     }
//     // Kích thước của vector là số lượng môn học không trùng
//     cout << "day ne " ; 
//     soluongmh = dsTenMH.size();
//     cout << soluongmh ;
//     cout << "day "  ; 
//     // Kiểm tra mã lớp hợp lệ
//     LopSV& lop = DS_LOPSV::getInstance().nodes[vitri];
//     string malop = lop.MALOP ;
//     if (lop.FIRST.getHead() == nullptr) {
//         std::cout << "Lop nay chua co sinh vien!\n";
//         return;
//     }
//     //Đếm số lượng sinh viên
//     int soluongsv = lop.FIRST.size(lop.FIRST) ; 
//     if(soluongsv){
//         cout << "LOP CO SINH VIEN" << soluongsv ; 
//     }
//      //Lấy danh sách sinh viên
//     SinhVien *dsSinhVien = new SinhVien[soluongsv];
//     int index = 0;
//     for (PTRSV p = lop.FIRST.getHead(); p != nullptr; p = p->next) {
//         dsSinhVien[index++] = p->sv ;
//     }
//     // Sắp xếp danh sách sinh viên theo tên
//     lop.FIRST.selectionSortSV(dsSinhVien,soluongsv) ;
      
//     // tao cac text mo dau 
//         Text stt(40.f, 129.f, 85.f, 40.f, "STT", font, sf::Color::Red, 15);
//         Text ma(125.f, 129.f, 99.f, 40.f, "MASV", font, sf::Color::Red, 15);
//         Text ho1(224.f, 129.f, 227.f, 40.f, "HO VA TEN ", font, sf::Color::Red, 15);
//         baocao.push_back(stt) ;
//         baocao.push_back(ma) ;
//         baocao.push_back(ho1) ;
//         float xtiep = 451.f ;
//     for(int i = 0 ; i < soluongmh ; i++){
//         Text mamon(xtiep, 129.f, 99.f, 40.f,dsTenMH[i], font, sf::Color::Red, 15);
//         baocao.push_back(mamon) ;
//         xtiep+=100.f ; 
//     }
//     std::vector<int> dssv[soluongsv] ; 
//     for (size_t i = 1; i < diemlist.cnt.size(); ++i) {
//         const auto& row = diemlist.cnt[i];
//         if (row.size() < 3) {
//             std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
//             continue;
//         }
//         std::string MASV = row[0];
//         std::string MALOP = row[1];
//         int MALOPTC  = std::stoi(row[2]);
//         if (MALOP != malop) {
//             continue;
//         }
//         for(int i = 0 ; i < soluongsv ; i++ ){
//             if(dsSinhVien[i].MASV ==  MASV) 
//             dssv[i].push_back(MALOPTC) ; 
//         }
//     }
//     cout << "DAY NE" ; 
//      for (int  i = 0; i < soluongsv; ++i) {
//     if (!dssv[i].empty()) { // Nếu dssv[i] không rỗng
//         std::cout << "SINH VIEN " << dsSinhVien[i].MASV << " CO THONG TIN LOP TC \n";
//         for (int maloptc : dssv[i]) {
//             std::cout << "- MA LOP TC  " << maloptc << std::endl;
//         }
//     } else {
//         std::cout << "SINH VIEN" << dsSinhVien[i].MASV << " CHUA CO THONG TIN LOP TC \n";
//     }
// }

//     // Tạo ma trận điểm, khởi tạo với giá trị -1
//     std::vector<std::vector<float>> MaxDiem(soluongsv, std::vector<float>(soluongmh, -1.0f));
//     // Tìm điểm cao nhất cho từng sinh viên trong từng môn học
//     for (int i = 0; i < soluongsv; i++) {
//         // for (int j = 0 ; j < dssv[i].size() ; j++ ) {
//         //     if(!dssv[i].empty()){
//         //     int temp = dssv[i][j] ;
//         //     LopTinChi* tc = TinhchiList::getInstance().Nodes[temp] ;
//         //     string mamh =  tc->MAMH ; 
//         //     for (int k = 0; k < soluongmh; k++) {
//         //         if ( dsTenMH[k]== mamh ) {
//         //         PTRDK p = tc->Dssvdk.findMASV(dsSinhVien[i].MASV) ;
//         //             MaxDiem[i][k] = std::max(MaxDiem[i][k], p->sv.Diem);
//         //         }
//         //     }
//         // }
//         // }
//         tinhdiemtk(MaxDiem, dssv[i], dsSinhVien[i].MASV , dsTenMH, soluongsv, soluongmh ,i);
//     }
//  for (size_t i = 0; i < MaxDiem.size(); i++) {
//         std::cout << "Thong tin diem cua sinh vien SV" << i + 1 << ":\n";

//         // Duyệt qua từng môn học của sinh viên
//         for (size_t j = 0; j < MaxDiem[i].size(); j++) {
//             float diem = MaxDiem[i][j];

//             // Thông báo trạng thái của từng giá trị điểm
//             if (diem == -1.0f) {
//                 std::cout << "   Mon hoc MH" << j + 1 << ": Chua co diem (N/A).\n";
//             } else {
//                 std::cout << "   Mon hoc MH" << j + 1 << ": Diem cao nhat la " 
//                           << std::fixed << std::setprecision(1) << diem << ".\n";
//             }
//         }
//     }

//     //In kết quả
//     //hoanh do 
//     float yPosition = 168.f;
//     for (int i = 0; i < soluongsv; i++) {
//         Text stt(40.f, yPosition, 170.f, 40.f, std::to_string(i), font, sf::Color::Red, 15);
//         Text ma(125.f, yPosition, 295.f, 40.f, dsSinhVien[i].MASV, font, sf::Color::Red, 15);
//         Text ho1(224.f, yPosition, 500.f, 40.f, dsSinhVien[i].HO, font, sf::Color::Red, 15);
//         baocao.push_back(stt) ;
//         baocao.push_back(ma) ;
//         baocao.push_back(ho1) ;
//         // khia bao ho ten sinh vien 
//         // khai bao hoanh do 
//         float xPosition = 500.f;
//         for (int j = 0; j < soluongmh; j++) {
//                 Text diem;
//             if (MaxDiem[i][j] != -1) {
//                 // std::cout << "  Môn " << dsMonHoc[j].MAMH << ": " << MaxDiem[i][j] << "\n";
//                diem = Text(xPosition, yPosition, 99.f, 40.f, std::to_string(MaxDiem[i][j]), font, sf::Color::Red, 15);
//             } else {
//                 // std::cout << "  Môn " << dsMonHoc[j].MAMH << ": Không có điểm\n";
//                diem = Text(xPosition, yPosition, 99.f, 40.f, " ", font, sf::Color::Red, 15);
//             }
//             baocao.push_back(diem);
//             //hoanh do tang 
//              xPosition += 100.f;
//             if (xPosition > 1500.f)
//             xPosition = 500.f;
//         }
//         // hoanh do tang 
//         yPosition += 100.f;
//         if (yPosition > 800.f)
//             yPosition = 168.f;
//     }
//     delete[] dsSinhVien;
// }

void Data::diemtk(fsys::path filepath, sf::Font& font , int vitri) {
    if (!fsys::exists(filepath)) {
        std::cerr << "Khong tim thay file: " << filepath.string() << std::endl;
        return;
    }
    csvFile diemlist(filepath);
    diemlist.readFile();

    if (diemlist.cnt.empty()) {
        std::cerr << "File rong hoac khong doc duoc!" << std::endl;
        return;
    }
    int soluongmh = 0 ; 
    custom::vector<string> dsTenMH; // Vector luu ten mon hoc khong trung
    for (int i = 0; i < TinhchiList::getInstance().n; i++) {
        bool daTonTai = false;
        // Kiem tra xem ten mon hoc da ton tai trong vector chua
        for (const auto& tenMH : dsTenMH) {
            if (TinhchiList::getInstance().Nodes[i]->MAMH == tenMH) {
                daTonTai = true;
                break;
            }
        }
        // Neu chua ton tai, them vao vector
        if (!daTonTai) {
            dsTenMH.push_back(TinhchiList::getInstance().Nodes[i]->MAMH);
        }
    }
    // Kich thuoc cua vector la so luong mon hoc khong trung
    soluongmh = dsTenMH.size();
    cout << "SO LUONG MON HOC : "<< soluongmh << endl  ; 
    // Kiem tra ma lop hop le
    LopSV& lop = DS_LOPSV::getInstance().nodes[vitri];
    string malop = lop.MALOP ;
    if (lop.FIRST.getHead() == nullptr) {
        std::cout << "Lop nay chua co sinh vien!\n";
        return;
    }
    // Dem so luong sinh vien
    int soluongsv = lop.FIRST.size(lop.FIRST) ; 
    if(soluongsv){
        cout << "LOP CO SO LUONG  SINH VIEN" << soluongsv << endl ; 
    }
     // Lay danh sach sinh vien
    SinhVien *dsSinhVien = new SinhVien[soluongsv];
    int index = 0;
    for (PTRSV p = lop.FIRST.getHead(); p != nullptr; p = p->next) {
        dsSinhVien[index++] = p->sv ;
    }
    // Sap xep danh sach sinh vien theo ten
    lop.FIRST.selectionSortSV(dsSinhVien,soluongsv) ;
    // hien thi danh sach sinh vien tang dan theo ten ; 
    for(int i = 0 ; i < soluongsv ; i++){
        cout << dsSinhVien[i].MASV << " " << dsSinhVien[i].HO << " " << dsSinhVien[i].TEN << endl ; 
    } 
    cout <<"DA TANG DAN THEO TEN\n " ;
    // tao cac text mo dau 
        Text stt(40.f, 129.f, 85.f, 40.f, "STT", font, sf::Color::Red, 15);
        Text ma(125.f, 129.f, 99.f, 40.f, "MASV", font, sf::Color::Red, 15);
        Text ho1(224.f, 129.f, 227.f, 40.f, "HO VA TEN ", font, sf::Color::Red, 15);
        baocao.push_back(stt) ;
        baocao.push_back(ma) ;
        baocao.push_back(ho1) ;
        float xtiep = 451.f ;
    for(int i = 0 ; i < soluongmh ; i++){
        Text mamon(xtiep, 129.f, 99.f, 40.f,dsTenMH[i], font, sf::Color::Red, 15);
        baocao.push_back(mamon) ;
        xtiep+=100.f ; 
    }
    custom::vector<int> dssv[soluongsv] ; 
    for (size_t i = 1; i < static_cast<size_t>(diemlist.cnt.size()); ++i) {
        const auto& row = diemlist.cnt[i];
        if (row.size() < 3) {
            std::cerr << "Dong khong hop le trong du lieu CSV tai dong: " << i + 1 << std::endl;
            continue;
        }
        std::string MASV = row[0];
        std::string MALOP = row[1];
        int MALOPTC  = std::stoi(row[2]);
        if (MALOP != malop) {
            continue;
        }
        for(int i = 0 ; i < soluongsv ; i++ ){
            if(dsSinhVien[i].MASV ==  MASV) 
            dssv[i].push_back(MALOPTC) ; 
        }
    }
     for (int  i = 0; i < soluongsv; ++i) {
    if (!dssv[i].empty()) { // Neu dssv[i] khong rong
        std::cout << "SINH VIEN " << dsSinhVien[i].MASV << " CO THONG TIN LOP TC \n";
        for (int maloptc : dssv[i]) {
            std::cout << "- MA LOP TC  " << maloptc << std::endl;
        }
    } else {
        std::cout << "SINH VIEN" << dsSinhVien[i].MASV << " CHUA CO THONG TIN LOP TC \n";
    }
}

    // Tao ma tran diem, khoi tao voi gia tri -1
    custom::vector<custom::vector<float>> MaxDiem(soluongsv, custom::vector<float>(soluongmh, -1.0f));
    // Tim diem cao nhat cho tung sinh vien trong tung mon hoc
    for (int i = 0; i < soluongsv; i++) {
        tinhdiemtk(MaxDiem, dssv[i], dsSinhVien[i].MASV , dsTenMH, soluongsv, soluongmh ,i);
    }
 for (int i = 0; i < static_cast<int>(MaxDiem.size()); i++) {
        std::cout << "Thong tin diem cua sinh vien SV" << i + 1 << ":\n";

        // Duyet qua tung mon hoc cua sinh vien
        for (int j = 0; j < static_cast<int>(MaxDiem[i].size()); j++) {
            float diem = MaxDiem[i][j];

            // Thong bao trang thai cua tung gia tri diem
            if (diem == -1.0f) {
                std::cout << "   Mon hoc MH" << j + 1 << ": Chua co diem (N/A).\n";
            } else {
                std::cout << "   Mon hoc MH" << j + 1 << ": Diem cao nhat la " 
                          << std::fixed << std::setprecision(1) << diem << ".\n";
            }
        }
    }

    //In ket qua
    float yPosition = 168.f;
    cout << "SO LUONG SINH VIEN " << soluongsv << endl ;
    for (int i = 0; i < soluongsv; i++) {
        Text stt(40.f, yPosition,  85.f, 40.f, std::to_string(i), font, sf::Color::Red, 15);
        Text ma(125.f, yPosition, 99.f, 40.f, dsSinhVien[i].MASV, font, sf::Color::Red, 15);
        Text ho1(224.f, yPosition, 227.f, 40.f, dsSinhVien[i].HO + " " + dsSinhVien[i].TEN, font, sf::Color::Red, 15);
        baocao.push_back(stt) ;
        baocao.push_back(ma) ;
        baocao.push_back(ho1) ; 
        float xPosition = 451.f;
        for (int j = 0; j < soluongmh; j++) {
                string diemString;
                Text diem;
            if (MaxDiem[i][j] != -1) {
                // Làm tròn và chuyển thành chuỗi với 2 chữ số sau dấu thập phân
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(2) << MaxDiem[i][j];
                diemString = oss.str();
            //    diem = Text(xPosition, yPosition, 99.f, 40.f, std::to_string(MaxDiem[i][j]), font, sf::Color::Red, 15);
                diem = Text(xPosition, yPosition, 99.f, 40.f, diemString, font, sf::Color::Red, 15);
            } else {
               diem = Text(xPosition, yPosition, 99.f, 40.f, " ", font, sf::Color::Red, 15);
            }
            baocao.push_back(diem);
             xPosition += 100.f;
            if (xPosition > 1500.f)
            xPosition = 500.f;
        }

        yPosition += 50.f;
        if (yPosition > 800.f)
            yPosition = 168.f;
    }
    delete[] dsSinhVien;
    cout << "HOAN THANH XU LY DIEM TRUNG BINH " ; 
}

// Hàm tính điểm trung bình của một sinh viên
// float Data::TinhDiemTrungBinh(const std::vector<int>& dssv, const std::string& masv) {
//     float tongDiem = 0;
//     int tongTinChi = 0;
//     cout << "DA VAO DC DAY " ; 
//     for (int temp : dssv) {
//         LopTinChi* tc = TinhchiList::getInstance().Nodes[temp];
//         std::string mamh = tc->MAMH;
//         cout << "den day " ; 
//         // Tìm môn học trong AVL Tree
//         PTRMH k = AVLTreeMH::getInstance().findMonHoc(AVLTreeMH::getInstance().root, mamh);
//         cout << "den day " ; 
//         if (k == nullptr) continue; // Bỏ qua nếu không tìm thấy môn học

//         int soTinChi = k->mh.STCLT + k->mh.STCTH;
//         PTRDK p = tc->Dssvdk.findMASV(masv);
//         if (p == nullptr) continue; // Bỏ qua nếu sinh viên chưa đăng ký môn này

//         tongTinChi += soTinChi;
//         tongDiem += p->sv.Diem * soTinChi;
//     }
//     // Tránh chia cho 0
//     return (tongTinChi > 0) ? (tongDiem / tongTinChi) : 0.0f;
// }
float Data::TinhDiemTrungBinh(const custom::vector<int>& dssv, const std::string& masv) {
    float tongDiem = 0;
    int tongTinChi = 0;

    if (dssv.empty()) {
        std::cerr << "Dannh SACH TIN CHI SINH VIEN " << masv << " CHUA DANG KY LOP TC CHI NAO CA " << std::endl;
        return 0.0f;
    }

    // for (int temp : dssv) {
    for(int i  = 0 ; i < dssv.size() ; i++){
        int temp = dssv[i];
        if (temp < 0) {
            std::cerr << "CHI SO KHONG HOP LE " << temp << std::endl;
            continue;
        }
        cout << "CHI SO TEMPP HOP LE :" << temp << std::endl;
        LopTinChi* tc = TinhchiList::getInstance().Nodes[temp - 1];
        if (tc == nullptr) {
            std::cerr << "KHONG TIM THAY LOP TINH CHI  temp = " << temp << std::endl;
            continue;
        }

        std::string mamh = tc->MAMH;
        cout << "MA MON HOC CUA LOP TINH CHI NAY LA : " << mamh << std::endl;
        PTRMH k = AVLTreeMH::getInstance().findMonHoc(AVLTreeMH::getInstance().root, mamh);
        if (k == nullptr) {
            std::cerr << "KHONG TIM THAY MON HOC  " << mamh << std::endl;
            continue;
        }
        cout <<"MON HOC DA DC TIM THAY\n " ; 
        int soTinChi = k->mh.STCLT + k->mh.STCTH;
        cout << "SO TIN CHI CUA MON HOC NAY LA : " << soTinChi << std::endl;
        PTRDK p = tc->Dssvdk.findMASV(masv);
        if (p == nullptr) {
            std::cerr << "SINH VIEN " << masv << " CHUA DANG KY MON HOC  " << mamh << std::endl;
            continue;
        }
        tongTinChi += soTinChi;
        tongDiem += p->sv.Diem * soTinChi;
        cout << "TONG DIEM CUA SINH VIEN " << masv << " LA : " << tongDiem << std::endl;
    }

    if (tongTinChi == 0) {
        std::cerr << "SINH VIEN " << masv << " KHONG CO TINH CHI HOP LE" << std::endl;
    }

    return (tongTinChi > 0) ? (tongDiem / tongTinChi) : 0.0f;
    cout << "KET THUC HAM TINH TOAN " ; 
}
void Data::tinhdiemtk(custom::vector<custom::vector<float>>& MaxDiem, const custom::vector<int>& dssvLTC, const std::string& masv, const custom::vector<std::string>& dsTenMH, int soluongsv , int soluongmh , int i) {
    std::cout << "Bat dau tinh diem cho sinh vien co MASV: " << masv << "\n";
    std::cout << "Sinh vien nay dang co " << dssvLTC.size() << " lop tin chi.\n";

    // for (int temp : dssvLTC) { // Duyệt qua từng mã lớp tín chỉ của sinh viên
    for(int h = 0 ; h < dssvLTC.size() ; h++){
        std::cout << "Dang xu ly lop tin chi voi ma: " << dssvLTC[h] << "\n";
        int temp = dssvLTC[h];
        LopTinChi* tc = TinhchiList::getInstance().Nodes[temp - 1];
        if (!tc) {
            std::cout << "Lop tin chi ma " << temp << " khong hop le. Bo qua.\n";
            continue;
        }

        std::string mamh = tc->MAMH;
        std::cout << "Lop tin chi hop le. Mon hoc tuong ung: " << mamh << "\n";

        // Duyệt qua danh sách tên môn học
        for (int k = 0; k < soluongmh; k++) {
            if (dsTenMH[k] == mamh) { // Tìm môn học tương ứng
                std::cout << "Mon hoc tim thay: " << dsTenMH[k] << " tai vi tri: " << k << "\n";

                PTRDK p = tc->Dssvdk.findMASV(masv);
                if (p) { // Kiểm tra sinh viên có đăng ký lớp tín chỉ này không
                    std::cout << "Sinh vien MASV: " << masv 
                              << " co dang ky lop tin chi nay. Diem hien tai: " 
                              << p->sv.Diem << "\n";
                    // Làm tròn điểm trước khi lưu vào ma trận (2 chữ số sau dấu thập phân)
                    float roundedDiem = static_cast<int>(p->sv.Diem * 100 + 0.5f) / 100.0f;  // Thêm +0.5f để làm tròn theo quy tắc thông thường
                    float oldDiem = MaxDiem[i][k];
                    cout << "DIEM SAU KHI LAM TRON " << roundedDiem << endl ;
                    // MaxDiem[i][k] = std::max(MaxDiem[i][k], p->sv.Diem);
                    MaxDiem[i][k] = std::max(MaxDiem[i][k], roundedDiem);
                    std::cout << "Diem cua mon hoc sau khi cap nhat: " << MaxDiem[i][k]
                              << " (Truoc: " << oldDiem << ")\n";
                } else {
                    std::cout << "Sinh vien MASV: " << masv 
                              << " khong dang ky lop tin chi nay. Bo qua.\n";
                }
            }
        }
    }

    std::cout << "Hoan thanh tinh diem cho sinh vien co MASV: " << masv << "\n\n";
}




