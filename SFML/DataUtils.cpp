
#include"DataUtils.h"
#include"globals.h"
#include<vector>
#include"FileNFoder.h"
#include"BuiltClasses.h"
#include <iomanip>  // Để sử dụng std::setw
#include <sstream>
// 

TinhchiList& list2 = TinhchiList::getInstance();
DS_LOPSV& listclass2 =  DS_LOPSV::getInstance() ;
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

    for (size_t i = 1; i < lopList.cnt.size(); ++i) {
        LopSV lop;
        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (lopList.cnt[i].size() < 2) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong LopSV
        lop.MALOP = lopList.cnt[i][0];    // Cột 0 là MALOP
        lop.TENLOP = lopList.cnt[i][1];    // Cột 1 là TENLOP
        lop.FIRST  ;               // Khởi tạo danh sách sinh viên trống

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
    for (size_t i = 1; i < monhocList.cnt.size(); ++i) {
        MonHoc mh;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (monhocList.cnt[i].size() < 4) {
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
    for (size_t i = 1; i < studentList.cnt.size(); ++i) {
        SinhVien sv;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (studentList.cnt[i].size() < 4) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong MonHoc
        sv.MASV = studentList.cnt[i][0]; // Cột 0 là MAMH
        sv.HO = studentList.cnt[i][1]; // Cột 1 là TENMH
        sv.TEN = studentList.cnt[i][2];
        sv.PHAI = studentList.cnt[i][3];
        sv.SODT = studentList.cnt[i][4];

        DS_LOPSV::getInstance().themSV(DS_LOPSV::getInstance() , DS_LOPSV::getInstance().nodes[0].MALOP ,sv) ;
        
          // Gán danh sách sinh viên vừa tạo cho lớp `lop`
          // duyẹt tu dau đen cuoi loi coi lop nao còn trong gan 
        //lop.FIRST = sinhvien;
    // Đóng tệp sau khi xử lý
    file.close();
    }
     DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance() , DS_LOPSV::getInstance().nodes[0].MALOP) ; 
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
    for (size_t i = 1; i < studentList.cnt.size(); ++i) {
        SinhVien sv;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (studentList.cnt[i].size() < 4) {
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
    for (size_t i = 1; i < tinchiList.cnt.size(); ++i) {
        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (tinchiList.cnt[i].size() < 9) { // Cần đủ 9 cột
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
            tc.HuyLop = false ; // Cột 7: HuyLop
            
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
    listDK list ; 
    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < studentList.cnt.size(); ++i) {
        DangKy dk;
        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (studentList.cnt[i].size() < 2) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }
        // Đọc và gán giá trị cho các trường trong MonHoc
        dk.MASV = studentList.cnt[i][0]; // Cột 0 là MAMH
        dk.Diem = std::stof(studentList.cnt[i][1]); // Cột 1 là TENMH
        dk.Huy_Dang_Ky = false ;  
        TinhchiList::getInstance().themdk(TinhchiList::getInstance() , TinhchiList::getInstance().Nodes[0]->MALOPTC , dk ) ; 
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
void Data::displaylop(sf::Font& font) {
      if (listclass2.isEmpty(listclass2)) {
       cout << "LOP DAY " ; 
        return;
    }
    
    float yPosition = 334.f;

    // Duyệt qua từng dòng dữ liệu đã đọc từ file CSV
    for (int i = 0 ; i < listclass2.n; ++i) {  // Bỏ qua dòng tiêu đề (nếu có)
    LopSV a = listclass2.nodes[i] ; 
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
        Button button(217.f, yPosition, buttonWidth, 58.f, MALOP, font, sf::Color::Red, 15);
        Buttonclass.push_back(button);
        Buttonclass.push_back(button);

        //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
        yPosition = (static_cast<int>(yPosition) + 100) ;
        if (yPosition > 800)
            yPosition = 334.f;
    }
}
void Data::displaymonhoc(fsys::path filepath, sf::Font& font) {
    if (!fsys::exists(filepath)) {
        std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
        return;
    }

    csvFile monhocList(filepath);
    monhocList.readFile();

    if (monhocList.cnt.empty()) {
        std::cout << "File rỗng hoặc chưa đọc được!" << std::endl;
        return;
    }

    float yPosition = 422.f;

    for (size_t i = 1; i < monhocList.cnt.size(); ++i) {
        const auto& row = monhocList.cnt[i];

        if (row.size() < 4) {
            std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
            continue;
        }

        std::string MAMH = row[0];
        std::string TENMH = row[1];
        int STCLT = 0;
        int STCTH = 0;

        try {
            STCLT = std::stoi(row[2]);
            STCTH = std::stoi(row[3]);
        } catch (const std::exception& e) {
            std::cerr << "Lỗi tại dòng " << i + 1 << ": " << e.what() << std::endl;
            continue;
        }

        Text ma(68.f, yPosition, 234.f, 35.f, MAMH, font, sf::Color::Red, 15);
        Text ten(302.f, yPosition, 422.f, 35.f, TENMH, font, sf::Color::Red, 15);
        Text lt(724.f, yPosition, 260.f, 35.f, std::to_string(STCLT), font, sf::Color::Red, 15);
        Text th(984.f, yPosition, 296.f, 35.f, std::to_string(STCTH), font, sf::Color::Red, 15);

        subjectList.push_back(ma);
        subjectList.push_back(ten);
        subjectList.push_back(lt);
        subjectList.push_back(th);

        float buttonWidth = std::max(150.f, static_cast<float>(MAMH.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
        Button button(68.f, yPosition, buttonWidth, 58.f, MAMH , font, sf::Color::Red, 15);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);

        //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
        yPosition = (static_cast<int>(yPosition) + 100) ;
        if (yPosition > 800)
            yPosition = 422.f;
    }
}
// std::pair<std::vector<Text>, std::vector<Button>> Data::displaystudent(fsys::path filepath, sf::Font& font) {
//     if (!fsys::exists(filepath)) {
//         std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
//     }
//     cout << "da di den day " ; 
//     vector<Text> StudentList ; 
//     vector<Button> StudentButton  ;
//     csvFile studentList(filepath);
//     studentList.readFile();

//     if (studentList.cnt.empty()) {
//         std::cout << "File rỗng hoặc chưa đọc được!" << std::endl;
//         //return;
//     }

//     float yPosition = 410.f;

//     for (size_t i = 1; i < studentList.cnt.size(); ++i) {
//         const auto& row = studentList.cnt[i];

//         if (row.size() < 4) {
//             std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
//             continue;
//         }

//         std::string MASV = row[0];
//         std::string HO = row[1];
//         std::string TEN = row[2];   // Tên
//         std::string PHAI = row[3]; // Phái
//         std::string SODT= row[4] ; // Số điện thoại

//         Text ma(9.f, yPosition, 272.f, 50.f, MASV, font, sf::Color::Red, 15);
//         Text ho(273.f, yPosition, 272.f, 50.f, HO, font, sf::Color::Red, 15);
//         Text ten(544.f, yPosition, 272.f, 50.f, TEN, font, sf::Color::Red, 15);
//         Text phai(815.f, yPosition, 272.f, 50.f, PHAI, font, sf::Color::Red, 15);
//         Text sodt(1092.f, yPosition, 272.f, 50.f, SODT, font, sf::Color::Red, 15);
//         StudentList.push_back(ma);
//         StudentList.push_back(ho);
//         StudentList.push_back(ten);
//         StudentList.push_back(phai);
//         StudentList.push_back(sodt);

//         float buttonWidth = std::max(150.f, static_cast<float>(MASV.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
//         Button button(68.f, yPosition, buttonWidth, 58.f, MASV, font, sf::Color::Red, 15);
//         StudentButton.push_back(button);
//         StudentButton.push_back(button);
//         StudentButton.push_back(button);
//         StudentButton.push_back(button);
//         StudentButton.push_back(button);

//         //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
//         yPosition = (static_cast<int>(yPosition) + 100) ;
//         if (yPosition > 800)
//             yPosition = 410.f;
//     }
//      return {StudentList, StudentButton};
// }
void  Data::displaystudent(int vitri, sf::Font& font) {
    cout << "da di den day " ; 

    float yPosition = 410.f;
    cout << "NE " ; 
     DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance(),DS_LOPSV::getInstance().nodes[0].MALOP) ; 
     for (PTRSV p = DS_LOPSV::getInstance().nodes[vitri].FIRST.getHead(); p != nullptr; p = p->next) {
        if (p->sv.MASV.empty() || p->sv.HO.empty() || p->sv.TEN.empty() || p->sv.PHAI.empty() || p->sv.SODT.empty()) {
            cout << "Invalid student data" << endl;
            continue; // Bỏ qua node không hợp lệ
        }

        std::string MASV = p->sv.MASV;
        std::string HO = p->sv.HO;
        std::string TEN = p->sv.TEN;   // Sửa lỗi gán nhầm
        std::string PHAI = p->sv.PHAI;
        std::string SODT = p->sv.SODT;

        Text ma(9.f, yPosition, 272.f, 50.f, MASV, font, sf::Color::Red, 15);
        Text ho(273.f, yPosition, 272.f, 50.f, HO, font, sf::Color::Red, 15);
        Text ten(544.f, yPosition, 272.f, 50.f, TEN, font, sf::Color::Red, 15);
        Text phai(815.f, yPosition, 272.f, 50.f, PHAI, font, sf::Color::Red, 15);
        Text sodt(1092.f, yPosition, 272.f, 50.f, SODT, font, sf::Color::Red, 15);

        StudentList.push_back(ma);
        StudentList.push_back(ho);
        StudentList.push_back(ten);
        StudentList.push_back(phai);
        StudentList.push_back(sodt);

        float buttonWidth = std::max(150.f, static_cast<float>(MASV.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
        Button button(68.f, yPosition, buttonWidth, 58.f, MASV, font, sf::Color::Red, 15);
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
}
void Data::displaytc1(TinhchiList& list, sf::Font& font) {
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
                  << "HuyLop: " << (tc->HuyLop ? "Yes" : "No") << "\n"
                  << "-----------------------\n";

        // Tạo các đối tượng Text cho từng cột
        Text a(22.f, yPosition, 170.f, 59.f, std::to_string(tc->MALOPTC), font, sf::Color::Red, 15);
        Text d(192.f, yPosition, 170.f, 59.f, tc->MAMH, font, sf::Color::Red, 15);
        Text b(362.f, yPosition, 170.f, 59.f, tc->NienKhoa, font, sf::Color::Red, 15);
        Text c(532.f, yPosition, 170.f, 59.f, std::to_string(tc->HocKy), font, sf::Color::Red, 15);
        Text f(702.f, yPosition, 170.f, 59.f, std::to_string(tc->soSvMin), font, sf::Color::Red, 15);
        Text g(876.f, yPosition, 170.f, 59.f, std::to_string(tc->soSvMax), font, sf::Color::Red, 15);
        Text e(1042.f, yPosition, 170.f, 59.f, std::to_string(tc->Nhom), font, sf::Color::Red, 15);
        Text h(1212.f, yPosition, 170.f, 59.f, (tc->HuyLop ? "Yes" : "No"), font, sf::Color::Red, 15);

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
        Button button(22.f, yPosition, buttonWidth, 59.f,std::to_string(tc->MALOPTC), font, sf::Color::Red, 15);
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
// ham them xoa sua 
bool Data::addlophoc(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
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

void Data::deletelophoc(fsys::path filepath, string& malop) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == malop) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa lop học có mã " << malop << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy lop học có mã " << malop << ".\n";
}
void Data::updatelophoc(fsys::path filepath, const std::string& malophocUpdate, const std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == malophocUpdate) {
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
        std::cerr << "MALOP " << malophocUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "Môn học đã được cập nhật thành công.\n";
}
bool Data::addmonhoc(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
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

void Data::deletemonhoc(fsys::path filepath, string& mamh) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == mamh) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa môn học có mã " << mamh << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy môn học có mã " << mamh << ".\n";
}
void Data::updateMonHoc(fsys::path filepath, const std::string& mamhToUpdate, const std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == mamhToUpdate) {
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
        std::cerr << "MAMH " << mamhToUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "Môn học đã được cập nhật thành công.\n";
}
// hoc sinh 
bool Data::addstudent(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
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
void Data::deletstudent(fsys::path filepath, string& masv) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == masv) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa sinh vien  có mã " << masv << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy sinh vien có mã " << masv << ".\n";
}
static void updatestudent(fsys::path filepath, const std::string& masvToUpdate, const std::vector<std::string>& newRow){
     // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == masvToUpdate) {
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
        std::cerr << "MASV " << masvToUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "sinh vien  đã được cập nhật thành công.\n";
}
// lop tin chi 
bool Data::add(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
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
void Data::deleteall(fsys::path filepath, string& key) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == key) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa thanh phan  có mã " << key << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy thanh phan  có mã " << key << ".\n";
}
void Data::update(fsys::path filepath, const std::string& keyToUpdate, const std::vector<std::string>& newRow) {
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
        std::cerr << "MAMH " << keyToUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "Môn học đã được cập nhật thành công.\n";
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
//