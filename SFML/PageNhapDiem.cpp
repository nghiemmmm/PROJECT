
// BaseScreenNhapDiem.cpp
#include "PageNhapDiem.h"
#include<string>
#include"DataUtils.h"
#include <cmath> // Thư viện hỗ trợ std::round


fsys::path diemPath = "D:\\du an\\SFML\\SFML\\data\\Courses\\Diem.csv";

int ScreenDiem::nhapdk(sf::RenderWindow& window) {
    cout << "DA DI VAO NHAP DANG KY" ; 
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
     sf::RectangleShape square(sf::Vector2f(1700, 900)); // Tạo ô vuông kích thước `size x size`
        square.setFillColor(sf::Color(220, 220, 220)); // RGB: (220, 220, 220)            // Đặt màu nền trắng
        square.setPosition(0.f, 172.f); 
    Text title1(541.f, 31.f, 618.f ,118.f ,  "QUAN LY SINH VIEN", font, sf::Color::Red, 40);
    Text title(667.f, 172.f, 342.f, 45.f, "DANG KI TIN CHI", font, sf::Color::Red, 20);
    Text masv(22.f, 242.f, 172.f, 40.f, "MA SINH VIEN", font, sf::Color::Red, 15);
    InputField ma(221.f, 247.f , 243.f , 40.f , font  ) ; 
    Button tracuu(501.f, 244.f, 148.f, 40.f, "TRA CUU", font, sf::Color(218, 110, 50), 15);
    Button exit(1600.f, 225.f, 91.f, 71.f, "EXIT", font, sf::Color(218, 110, 50), 15);
       // Vòng lặp chính để xử lý giao diện
       ma.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        if (ma.isSelected()) ma.textCursor(ma.getInput());
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
                 ma.handleMouseClick(mousePos);
            if(tracuu.isClicked(mousePos)){
                string masv = ma.getInput() ; 
                if(masv.length() > 11 ){
                    Data::popup("MA SINH VIEN KHONG HOP LE") ;
                }else{
                     showDK(window , masv) ;
                }
                // showDK(window , masv) ; 
                break ;
            }
            if(exit.isClicked(mousePos)){
                return 0 ; 
            }
    }
    ma.processInput(event);
}
        // Xóa màn hình
        window.clear(sf::Color::White);

        // Vẽ các đối tượng giao diện
        window.draw(square) ;
        title.draw(window);
        masv.draw(window);
        ma.draw(window);
        tracuu.draw(window);
        exit.draw(window) ; 
        title1.draw(window);
       
        // Hiển thị nội dung lên màn hình
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}
int ScreenDiem::showDK(sf::RenderWindow& window , string& masv) {
    TCList1.clear() ; 
    TCList2.clear() ;
    cout << "DA VAO HAM SHOW DK" ; 
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    string malop = " " ; 
    vector<Text> sv ;
    for(int i =0 ; i < DS_LOPSV::getInstance().n ; i++){
                    if(DS_LOPSV::getInstance().nodes[i].FIRST.getHead() != NULL){
                        // Tìm sinh viên theo MASV
                         SinhVien foundStudent = DS_LOPSV::getInstance().nodes[i].FIRST.findStudentByMASV(masv);
                        if (foundStudent.MASV != "") {
                            cout << "SINH VIEN TIM THAY " << foundStudent << endl;
                            Text masv2(4.f, 423.f, 118.f, 29.f,foundStudent.MASV, font, sf::Color::Red, 15);
                            sv.push_back(masv2) ; 
                            Text masv5(182.f, 636.f , 274.f , 34.f ,foundStudent.MASV, font, sf::Color::Red, 15);
                            sv.push_back(masv5) ; 
                            Text ten1(193.f, 423.f, 155.f, 29.f,foundStudent.TEN, font, sf::Color::Red, 15);
                            sv.push_back(ten1) ; 
                            Text ho1(121.f, 423.f, 72.f, 29.f,foundStudent.HO, font, sf::Color::Red, 15);
                            sv.push_back(ho1) ; 
                            Text lop2(349.f, 423.f, 144.f, 29.f,DS_LOPSV::getInstance().nodes[i].TENLOP, font, sf::Color::Red, 15); // Đổi tên ở đây
                             sv.push_back(lop2) ; 
                             malop = DS_LOPSV::getInstance().nodes[i].MALOP ;
                        } else {
                            cout << "KHONG TIM THAY  MASV 23CTT2001 TRONG LOP  " << i << endl;
                        }

                    }
            }
        sf::RectangleShape square(sf::Vector2f(1700, 169)); // Tạo ô vuông kích thước `size x size`
        square.setFillColor(sf::Color(220, 220, 220)); // RGB: (220, 220, 220)            // Đặt màu nền trắng
        square.setPosition(0.f, 172.f);    
        sf::RectangleShape square1(sf::Vector2f(494, 308)); // Tạo ô vuông kích thước `size x size`
        square1.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square1.setPosition(0.f, 546.f);   
        sf::RectangleShape square2(sf::Vector2f(489, 176)); // Tạo ô vuông kích thước `size x size`
        square2.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square2.setPosition(0.f, 341.f);  
         sf::RectangleShape square3(sf::Vector2f(1206, 155)); // Tạo ô vuông kích thước `size x size`
        square3.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square3.setPosition(505.f, 341.f);    
          sf::RectangleShape square4(sf::Vector2f(1150, 308)); // Tạo ô vuông kích thước `size x size`
        square4.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square4.setPosition(532.f, 546.f);    

        // InputField ma(221.f, 247.f , 243.f , 40.f , font  ) ; 
        InputField nienkhoa1(1058.f, 225.f , 31.f , 40.f , font  ) ; 
        InputField hocki3(1058.f, 277.f , 31.f , 40.f , font  ) ;
        //  InputField ma3(182.f, 636.f , 274.f , 34.f , font  ) ;
         InputField matc3(185.f, 714.f , 274.f , 34.f , font  ) ;
     Text title(667.f, 172.f, 342.f, 45.f, "DANG KI TIN CHI", font, sf::Color::Red, 20);
    // Text masv(22.f, 242.f, 172.f, 40.f, "MA SINH VIEN", font, sf::Color::Red, 15);
    Text lop(881.f, 230.f, 149.f, 34.f, "NIEN KHOA", font, sf::Color::Red, 15);
    Text hocki(880.f, 284.f, 150.f, 34.f, "HOC KI", font, sf::Color::Red, 15);
    Text title1(109.f, 341.f, 222.f, 43.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 15);
    Text title2(541.f, 31.f, 618.f ,118.f ,  "QUAN LY SINH VIEN", font, sf::Color::Red, 40);
    Button huytc(21.f, 250.f ,438.f , 40, " HUY TC KHONG PHU HOP " , font , sf::Color(218, 110, 50) , 15) ;

    Text masv1(4.f, 395.f, 113.f, 29.f, "MA ", font, sf::Color::Red, 15);
    Text ten(194.f, 395.f, 155.f, 29.f, "TEN", font, sf::Color::Red, 15);
    Text ho(118.f, 395.f, 72.f, 29.f, "HO", font, sf::Color::Red, 15);
    Text lop1(349.f, 395.f, 144.f, 29.f, "LOP", font, sf::Color::Red, 15);

    Text title3(103.f, 574.f, 256.f, 38.f, "THONG TIN DANG KI", font, sf::Color::Red, 15);
    Text ma1(21.f, 638.f, 123.f, 34.f, "MA SINH VIEN", font, sf::Color::Red, 15);
    Text matc(21.f, 714.f, 123.f, 34.f, "MA LOP TC", font, sf::Color::Red, 15);

    Text matc_tinchi(500.f, 341.f, 290.f, 31.f, "MA LOP TC", font, sf::Color::Red, 15);
    Text monhoc(791.f, 341.f, 310.f, 31.f, "MA MON HOC", font, sf::Color::Red, 15);
    Text nhom(1101.f, 341.f, 239.f, 31.f, "NHOM", font, sf::Color::Red, 15);
    Text sodk(1339.f, 341.f, 198.f, 31.f, "SO SV DANG KI", font, sf::Color::Red, 15);
    Text trong(1539.f, 341.f, 166.f, 31.f, "TRONG", font, sf::Color::Red, 15);

    Text title4(815.f, 546.f, 703.f, 28.f, "DANH SACH TIN CHI CO THE HUY", font, sf::Color::Red, 15);
    Text matc1(537.f, 585.f, 230.f, 27.f, "MA LOP TC", font, sf::Color::Red, 15);
    Text nienkhoa(770.f, 585.f, 241.f, 27.f, "NIEN KHOA", font, sf::Color::Red, 15);
    Text hocki1(1015.f, 585.f, 241.f, 27.f, "HOC KI", font, sf::Color::Red, 15); // Đổi tên ở đây
    Text monhoc_tinchi(1256.f, 585.f, 241.f, 27.f, "MON HOC", font, sf::Color::Red, 15);
    Text nhom_tinchi(1501.f, 585.f, 166.f, 27.f, "NHOM", font, sf::Color::Red, 15);

    // Button objects
    // Button tracuu(501.f, 244.f, 148.f, 40.f, "TRA CUU", font, sf::Color::Red, 15);
    Button tim(1340.f, 237.f, 111.f, 76.f, "TIM", font, sf::Color(218, 110, 50), 15);
    Button dk(319.f, 782.f, 155.f, 53.f, "DANG KI", font, sf::Color(218, 110, 50), 15);
    Button huydk(49.f, 782.f, 155.f, 53.f, "HUY DANG KI", font, sf::Color(218, 110, 50), 15);
    Button exit(1600.f, 237.f, 91.f, 71.f, "EXIT", font, sf::Color(218, 110, 50), 15);
    cout << "SO LUONG BUTON VA TEXT HIEN TAI " << sv.size() << endl ;
    int displayFrom = 0;
    int itemsPerPage = 10;
    int displayFrom1 = 0;
    int itemsPerPage1 = 20;

    // Khởi tạo các nút điều hướng
    Button nextPageBtn(1024.f, 517.f, 91.f, 18.f, "=>", font, sf::Color(218, 110, 50), 10);
    Button prevPageBtn(890.f, 517.f, 91.f, 18.f, "<=", font, sf::Color(218, 110, 50), 10);
    // Khởi tạo các nút điều hướng
    Button nextPageBtn1(1028.f, 855.f, 91.f, 18.f, "=>", font, sf::Color(218, 110, 50), 10);
    Button prevPageBtn1(895.f, 855.f, 91.f, 18.f, "<=", font, sf::Color(218, 110, 50), 10);

    // ma.setSelected(true);
    nienkhoa1.setSelected(true);
    // ma3.setSelected(true);
    matc3.setSelected(true);
    hocki3.setSelected(true);
   
    while (window.isOpen()) {
        sf::Event event;
        // displayLimit = std::min(displayFrom + itemsPerPage, TCList1.size());
        // size_t displayLimit1 = std::min(displayFrom + itemsPerPage, TCList2.size());
        long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(TCList1.size()) ? static_cast<int>(TCList1.size()) : (displayFrom + itemsPerPage);
        long long displayLimit1 = (displayFrom1 + itemsPerPage1) > static_cast<int>(TCList2.size()) ? static_cast<int>(TCList2.size()) : (displayFrom + itemsPerPage);
        // if (ma.isSelected()) ma.textCursor(ma.getInput());
        if (nienkhoa1.isSelected()) nienkhoa1.textCursor(nienkhoa1.getInput());
        if (hocki3.isSelected()) hocki3.textCursor(hocki3.getInput());
        // if (ma3.isSelected()) ma3.textCursor(ma3.getInput());
        if (matc3.isSelected()) matc3.textCursor(matc3.getInput());
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
                //   ma.handleMouseClick(mousePos);
                nienkhoa1.handleMouseClick(mousePos);
                  hocki3.handleMouseClick(mousePos);
                // ma3.handleMouseClick(mousePos);
                  matc3.handleMouseClick(mousePos);
                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(TCList1.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
                if (nextPageBtn1.isClicked(mousePos)) {
                    if (displayFrom1 + itemsPerPage1 < static_cast<int>(TCList2.size())) {
                        displayFrom1 += itemsPerPage1; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn1.isClicked(mousePos)) {
                    if (displayFrom1 - itemsPerPage1 >= 0) {
                        displayFrom1 -= itemsPerPage1; // Quay lại trang trước
                    }
                }
                if(huytc.isClicked(mousePos)){
                   if(Data::confirm("XAC NHAN HUY")){
                      for(int i = 0 ; i < static_cast<int>(TCList2.size()) ; i = i + 5 ){
                        cout << TCList2[i].getContent() << endl ;
                        // int matc = std::stoi(TCList2[i].getContent()) ;
                        // TinhchiList::getInstance().Nodes[matc]->HuyLop = true ; 
                      }
                   }
                }
            // if(tracuu.isClicked(mousePos)){
            //     sv.clear() ; 
            //     string masv = ma.getInput() ;
            //     //  SinhVien a = DS_LOPSV::getInstance().nodes[0].FIRST.findStudentByMASV("23CTT2001") ;
            //     //     cout << a.HO; 
            //     // string a = "23CTT2001" ; 
            //     cout << "denday" ;
            //    int vitri = 0 ; 
            //      for(int i =0 ; i < DS_LOPSV::getInstance().n ; i++){
            //         if(DS_LOPSV::getInstance().nodes[i].FIRST.head != NULL){
            //             // Tìm sinh viên theo MASV
            //              SinhVien foundStudent = DS_LOPSV::getInstance().nodes[i].FIRST.findStudentByMASV("23CTT2001");
            //             if (foundStudent.MASV != "") {
            //                 cout << "Sinh viên tìm thấy: " << foundStudent << endl;
                           
            //             } else {
            //                 cout << "Không tìm thấy sinh viên với MASV 23CTT2001 trong lớp " << i << endl;
            //             }

            //         }
            //          vitri = i ;
            // }
            //     cout << endl;
            //     cout << vitri ;  
            //     cout << endl ; 
            //     cout << "denday" ; 
            //     break ; 
            //     }
                
            if(tim.isClicked(mousePos)){
                string nienkhoa = nienkhoa1.getInput() ; 
                int hocki =  std::stoi(hocki3.getInput()) ;
                cout << "CAC DAU VAO HOP LE KHONG " ; 
                cout << nienkhoa << hocki ;
                int temp =TinhchiList::getInstance().KTLOPTC1(TinhchiList::getInstance(),nienkhoa,hocki) ;
                cout << temp ;
                if(temp != -1){
                    cout << "DANH SACH TIN CHI CO THE DANG KI " ; 
                    Data::displaytc2(TinhchiList::getInstance(),font ,nienkhoa, hocki ) ; 
                    Data::displaytchuy(TinhchiList::getInstance(),font ,nienkhoa, hocki ) ;
                }else{
                    Data::popup("LOP TINH CHI KHONG PHU HOP VUI LONG NHAP LAI") ; 
                }
                break ; 
            }
            if(dk.isClicked(mousePos)){
                if(Data::confirm("XAC NHAN DANG KY")){
                   cout << masv ; 
                   cout << malop ;
                   int matc = std::stoi(matc3.getInput()) ; 
                   DangKy dangKy(masv,0.0f, true);
                   TinhchiList::getInstance().themdk(TinhchiList::getInstance(),matc,dangKy) ;
                   custom::vector<std::string> newRow = {masv, malop,matc3.getInput()};
                   Data::add(diemPath ,font ,newRow ) ;
                }
                Data::popup("DANG KY THANH CONG ") ; 
            }
            if(huydk.isClicked(mousePos)){
                if(Data::confirm("XAC NHAN HUY")){
                    int matc = std::stoi(matc3.getInput()) ;
                    TinhchiList::getInstance().removedk(TinhchiList::getInstance(),matc,masv) ;
                }
                Data::popup("HUY THANH CONG ");
            }
            if(exit.isClicked(mousePos)){
                return 10 ;
            }
            }
            matc3.processInput(event);
            nienkhoa1.processInput(event);
            hocki3.processInput(event);


        
        
    }

    //   // Xử lý nhập liệu theo logic
    //     if (ma.chooseNextField()) {
    //         nienkhoa1.setSelected(true);
    //         ma.setSelected(false);
    //     }

    //     nienkhoa1.processInput(event);
    //     if (nienkhoa1.chooseNextField()) {
    //         hocki3.setSelected(true);
    //         nienkhoa1.setSelected(false);
    //     }

    //     hocki3.processInput(event);
    //     if (hocki3.chooseNextField()) {
    //         ma3.setSelected(true);
    //         hocki3.setSelected(false);
    //     }

    //     ma3.processInput(event);
    //     if (ma3.chooseNextField()) {
    //         matc3.setSelected(true);
    //         ma3.setSelected(false);
    //     }

    //     matc3.processInput(event);
    //     if (matc3.chooseNextField()) {
    //         // Xử lý logic kết thúc (nếu cần)
    //     }


        // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    // ma.setSelected(ma.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // nienkhoa1.setSelected(nienkhoa1.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // hocki1.setSelected(hocki1.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // ma1.setSelected(ma1.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // matc3.setSelected(matc3.isClicked(mousePos) && !ghi.isClicked(mousePos));

    // Vẽ lại màn hình
    window.clear(sf::Color::White);
    window.draw(square); 
    window.draw(square1);
     window.draw(square2);
      window.draw(square3);
       window.draw(square4);
        for (int i = 0; i < displayLimit; i++){
                        if (static_cast<int>(TCList1.size()) <= i )
                            break;
                        TCList1[i].draw(window);
                }

         for (int i = 0; i < displayLimit1; i++){
                        if (static_cast<int>(TCList2.size()) <= i )
                            break;
                        TCList2[i].draw(window);
                }
        for(size_t i = 0 ; i < sv.size() ; i++){
            sv[i].draw(window) ; 
        }
   
    huytc.draw(window) ;    
    title.draw(window);
    // masv.draw(window);
    lop.draw(window);
    hocki.draw(window);
    title1.draw(window);
    masv1.draw(window);
    ten.draw(window);
    ho.draw(window);
    // lop2.draw(window);

    title2.draw(window);
    title3.draw(window);
    ma1.draw(window);
    matc.draw(window);
    lop1.draw(window) ; 

    matc_tinchi.draw(window);
    monhoc.draw(window);
    nhom.draw(window);
    sodk.draw(window);
    trong.draw(window);

    title4.draw(window);
    matc1.draw(window);
    nienkhoa.draw(window);
    hocki1.draw(window); // Dùng đúng tên biến đã đổi
    monhoc_tinchi.draw(window);
    nhom_tinchi.draw(window);

    // Vẽ các nút bấm (Buttons)
    // tracuu.draw(window);
    tim.draw(window);
    dk.draw(window);
    huydk.draw(window);
    exit.draw(window);

    // masv2.draw(window) ; 
    // ten1.draw(window) ; 
    // ho1.draw(window) ; 
    // for(size_t i = 0 ; i < sv.size() ; i++){
    //     sv[i].draw(window) ; 
    // }
        // ma.draw(window) ; 
        nienkhoa1.draw(window) ; 
        // ma3.draw(window) ; 
        matc3.draw(window) ; 
        hocki3.draw(window) ;
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        nextPageBtn1.draw(window);
        prevPageBtn1.draw(window);
    // Hiển thị cửa sổ
    window.display();
    }
 return 0 ;   
}

// phan nhap diem 
int ScreenDiem::showDiem(sf::RenderWindow& window) {
    cout << "DA DI VAO HAM SHOW DIEM" ;
    cout <<"CAC LOP TINH CHI HIEN TAI\n " ;
    TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance());
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    
    sf::RectangleShape square3(sf::Vector2f(1700, 223)); // Tạo ô vuông kích thước `size x size`
    square3.setFillColor(sf::Color(220, 220, 220)); // RGB: (220, 220, 220)            // Đặt màu nền trắng
    square3.setPosition(0.f, 0.f);  

     sf::RectangleShape square(sf::Vector2f(1696, 133)); // Tạo ô vuông kích thước `size x size`
        square.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square.setPosition(0.f, 226.f);   
     sf::RectangleShape square1(sf::Vector2f(1696, 548)); // Tạo ô vuông kích thước `size x size`
        square1.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square1.setPosition(0.f, 356.f);   
      // Khởi tạo các phần tử giao diện
    Text title1(541.f, 31.f, 618.f ,118.f ,  "QUAN LY SINH VIEN", font, sf::Color::Red, 40);
    Text title(537.f, 181.f, 618.f, 38.f, "NHAP DIEM SINH VIEN", font, sf::Color::Red, 15);
    Text thongtin(21.f, 220.f, 217.f, 29.f, "NHAP THONG TIN", font, sf::Color::Red, 15);
    Text nienkhoa(21.f, 259.f, 108.f, 29.f, "NIEN KHOA", font, sf::Color::Red, 15);
    Text hocki(21.f, 298.f, 108.f, 29.f, "HOC KI", font, sf::Color::Red, 15);
    Text nhom(412.f, 263.f, 125.f, 27.f, "NHOM", font, sf::Color::Red, 15);
    Text mh_label(412.f, 298.f, 125.f, 27.f, "MON HOC", font, sf::Color::Red, 15);

    Button batdau(1006.f, 260.f, 115.f, 41.f, "BAT DAU", font, sf::Color::Red, 15);
    Button capnhat(1186.f, 262.f, 115.f, 39.f, "CAP NHAT", font, sf::Color::Red, 15);
    Button thoat(1356.f, 258.f, 115.f, 40.f, "EXIT", font, sf::Color::Red, 15);

    InputField Nienkhoa(148.f, 261.f, 205.f, 27.f, font);
    InputField HocKi(148.f, 298.f, 205.f, 27.f, font);
    InputField Nhom(575.f, 263.f, 223.f, 27.f, font);
    InputField MonHoc(575.f, 297.f, 223.f, 27.f, font);
    // Text stt(21.f , 372.f , 307.f , 33.f ,"STT " , font , sf :: Color :: Red , 15) ;
    //  Text ma(328.f , 372.f , 307.f , 33.f ,"MA SV " , font , sf :: Color :: Red , 15) ;
    //  Text ho(635.f , 372.f , 307.f , 33.f ,"HO " , font , sf :: Color :: Red , 15) ;
    //  Text ten(942.f , 372.f , 307.f , 33.f ,"TEN " , font , sf :: Color :: Red , 15) ;
    //  Text diem(1250.f , 372.f , 307.f , 33.f ,"DIEM" , font , sf :: Color :: Red , 15) ;

    vector<Text> DIEM ; 

    Nienkhoa.setSelected(true);
    HocKi.setSelected(true);
    Nhom.setSelected(true);
    MonHoc.setSelected(true);

    // Vòng lặp chính của màn hình
    while (window.isOpen()) {
        sf::Event event;

        // Hiển thị con trỏ văn bản nếu trường đang được chọn
        if (Nienkhoa.isSelected()) Nienkhoa.textCursor(Nienkhoa.getInput());
        if (HocKi.isSelected()) HocKi.textCursor(HocKi.getInput());
        if (Nhom.isSelected()) Nhom.textCursor(Nhom.getInput());
        if (MonHoc.isSelected()) MonHoc.textCursor(MonHoc.getInput());

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                Nienkhoa.handleMouseClick(mousePos) ; 
                HocKi.handleMouseClick(mousePos) ; 
                Nhom.handleMouseClick(mousePos) ; 
                MonHoc.handleMouseClick(mousePos) ; 
                if (batdau.isClicked(mousePos)) {
                    string  nienkhoa =Nienkhoa.getInput() ;
                    int hocki = std::stoi(HocKi.getInput()) ; 
                    int nhom = std::stoi(Nhom.getInput()) ; 
                    string monhoc = MonHoc.getInput() ; 
                    cout<< nienkhoa << " " << hocki << "  "  << nhom << "  " <<  monhoc << endl; 
                    int temp = TinhchiList::getInstance().KTLOPTC(TinhchiList::getInstance(),nienkhoa , hocki , nhom ,monhoc ) ;
                    cout << temp ;
                    if(temp != -1){
                          Indiem(window,temp) ;

                    }else{
                        Data::popup("LOP TINH CHI KHONG PHU HOP VUI LONG NHAP LAI") ; 
                    }
                    break ;
                    // Indiem(window,vitri) ;
                    // cout << "den day " ; 
                }

                if (capnhat.isClicked(mousePos)) {
                    return 3; 
                    }
                if (thoat.isClicked(mousePos)) {
                    return 0 ; 
                }
            }
             // Xử lý logic nhập liệu
        Nienkhoa.processInput(event);
        if (Nienkhoa.chooseNextField()) {
            HocKi.setSelected(true);
            Nienkhoa.setSelected(false);
        }

        HocKi.processInput(event);
        if (HocKi.chooseNextField()) {
            Nhom.setSelected(true);
            HocKi.setSelected(false);
        }

        Nhom.processInput(event);
        if (Nhom.chooseNextField()) {
            MonHoc.setSelected(true);
            Nhom.setSelected(false);
        }

        MonHoc.processInput(event);
        if (MonHoc.chooseNextField()) {
            // Xử lý khi kết thúc nhập liệu
        }
        }

       
        // Vẽ giao diện
        window.clear(sf::Color::White);
        window.draw(square) ; 
        window.draw(square1) ; 
        window.draw(square3) ; 
        title1.draw(window) ; 

        title.draw(window);
        thongtin.draw(window);
        nienkhoa.draw(window);
        hocki.draw(window);
        nhom.draw(window);
        mh_label.draw(window);

        batdau.draw(window);
        capnhat.draw(window);
        thoat.draw(window);

        Nienkhoa.draw(window);
        HocKi.draw(window);
        Nhom.draw(window);
        MonHoc.draw(window);
        // stt.draw(window) ; 
        // ma.draw(window) ;
        // ho.draw(window) ;
        // ten.draw(window) ;
        // diem.draw(window) ;
        window.display() ; 
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}
int ScreenDiem::Indiem(sf::RenderWindow& window, int& vitri) {
    cout << "DA DI VAO HAM IN DIEM" ;
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }

    std::vector<Text> info;
    std::vector<EditableText> DIEM;
    std::vector<InputField> nhap;
    info.clear() ; 
    DIEM.clear() ;   

    float yPosition = 408.f;
    int STT = 1; // Bắt đầu từ số thứ tự 1

    // Duyệt qua danh sách sinh viên đăng ký

    int slsv = TinhchiList::getInstance().Nodes[vitri]->Dssvdk.size(TinhchiList::getInstance().Nodes[vitri]->Dssvdk) ; 
    for(int i = 0 ; i < slsv ; i++){
        // Tạo InputField cho điểm
        InputField diem(1249.f, yPosition, 618.f, 47.f, font);
        nhap.push_back(diem);
        yPosition += 50.f; // Di chuyển vị trí Y cho dòng tiếp theo

    // Kiểm tra nếu vượt quá chiều cao hiển thị
    if (yPosition > 800) {
        yPosition = 408.f; // Reset về đầu
        break;             // Hoặc dừng việc thêm nếu cần
    }
    }
    float yPosition2 = 408.f;
    int i = 0 ; 
   for (PTRDK p = TinhchiList::getInstance().Nodes[vitri]->Dssvdk.getHead(); p != NULL && i < slsv; p = p->next, ++i) {
    // Tạo EditableText từ InputField và gán giá trị điểm
    string diem1 = Data::formatFloat(p->sv.Diem);
    EditableText diemEditable(1249.f, yPosition2, diem1, font, &nhap[i]);
    DIEM.push_back(diemEditable);

    yPosition2 += 50.f; // Di chuyển vị trí Y cho dòng tiếp theo

    // Kiểm tra nếu vượt quá chiều cao hiển thị
    if (yPosition2 > 800) {
        yPosition2 = 408.f; // Reset về đầu
        break;             // Hoặc dừng việc thêm nếu cần
    }
    }

    float yPosition1 = 408.f;
     for (PTRDK p = TinhchiList::getInstance().Nodes[vitri]->Dssvdk.getHead(); p != NULL; p = p->next) {
        string masv = p ->sv.MASV ; 
          for (int i = 0; i < DS_LOPSV::getInstance().n; i++) {
            if (DS_LOPSV::getInstance().nodes[i].FIRST.getHead() != NULL) {
                // Tìm sinh viên theo MASV
                SinhVien foundStudent = DS_LOPSV::getInstance().nodes[i].FIRST.findStudentByMASV(masv);
                if (!foundStudent.MASV.empty()) {
                    Text stt(17.f , yPosition1 ,170.f, 59.f, std::to_string(STT) ,font, sf::Color::Red, 15  ) ;
                    info.push_back(stt);

                    Text masv2(328.f, yPosition1, 170.f, 59.f, foundStudent.MASV, font, sf::Color::Red, 15);
                    info.push_back(masv2);

                    Text ten1(938.f, yPosition1, 170.f, 59.f, foundStudent.TEN, font, sf::Color::Red, 15);
                    info.push_back(ten1);

                    Text ho1(635.f, yPosition1, 170.f, 59.f, foundStudent.HO, font, sf::Color::Red, 15);
                    info.push_back(ho1);
                    yPosition1 += 50.f; // Dịch chuyển vị trí y cho dòng tiếp theo
                      // Đặt lại yPosition nếu vượt quá giới hạn
                    if (yPosition1 > 800)  
                        yPosition1 = 408.f;
                    STT++;
                }
            }
          }
     }
    


    cout << DIEM.size() ; 
    cout << nhap.size() ; 
    // Tạo các nút bấm
    Button batdau(1006.f, 260.f, 115.f, 41.f, "BAT DAU", font, sf::Color(218, 110, 50), 15);
    Button capnhat(1186.f, 262.f, 115.f, 39.f, "CAP NHAT", font, sf::Color(218, 110, 50), 15);
    Button thoat(1356.f, 258.f, 115.f, 40.f, "EXIT", font, sf::Color(218, 110, 50), 15);
    sf::RectangleShape square(sf::Vector2f(1700, 900)); // Tạo ô vuông kích thước `size x size`
        square.setFillColor(sf::Color(220, 220, 220)); // RGB: (220, 220, 220)            // Đặt màu nền trắng
        square.setPosition(0.f, 172.f); 
    Text title1(541.f, 31.f, 618.f ,118.f ,  "QUAN LY SINH VIEN", font, sf::Color::Red, 40);

    // Thêm vòng lặp xử lý sự kiện
    while (window.isOpen()) {
        sf::Event event;
        for (auto& field : nhap) {
             if (field.isSelected()){
                field.textCursor(field.getInput());
             } 
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            for (auto& edit : DIEM) {
                    edit.update(event);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                 for (auto& edit : DIEM) {
                    edit.handleMouseClick(mousePos);
                    }
                if (batdau.isClicked(mousePos)) {
                // Xử lý logic khi nhấn nút "BAT DAU"
                }
                if (capnhat.isClicked(mousePos)) {
                        for (size_t i = 0; i < DIEM.size(); ++i) {
                        std::string diemMoi = DIEM[i].getText();
                        try {
                        float diemSo = std::stof(diemMoi); // Chuyển đổi sang float
                        diemSo = std::round(diemSo * 100) / 100;
                        TinhchiList::getInstance().Nodes[vitri]->Dssvdk.getAt(i)->sv.Diem = diemSo; // Cập nhật điểm
                        } catch (...) {
                    std::cerr << "Lỗi: Điểm không hợp lệ tại dòng " << i + 1 << std::endl;
                    }
                    }
                    TinhchiList::getInstance().Nodes[vitri]->Dssvdk.inDanhSach() ; 
                    Data::popup("CAP NHAT THANH CONG ") ; 
            }
            if (thoat.isClicked(mousePos)) {
                return 0 ; 
            }
        }

         for (auto& field : nhap) {
            field.updateCursor();
        }
        
        // for (auto& field : nhap) {
        //     field.processInput(event);
        // }
        }

     // Vẽ tất cả các thành phần lên cửa sổ
       window.clear(sf::Color::White);
        window.draw(square);
        title1.draw(window);
        for (auto& text : info) {
            text.draw(window);
        }
        // for (auto& field : nhap) {
        //     field.draw(window);
        // }
        for (auto& edit : DIEM) {
            edit.draw(window);
        }
       
        batdau.draw(window);
        capnhat.draw(window);
        thoat.draw(window);
        window.display();
    }
    return 0;
}
// phan bao cao 
int ScreenDiem::baseIn(sf::RenderWindow& window) {
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    Text title(541.f, 31.f, 618.f ,118.f ,  "QUAN LY SINH VIEN", font, sf::Color(218, 110, 50), 40);
   Button diemmh(1.f , 181.f ,  316.f , 71.f , "BANG DIEM MON HOC " , font , sf::Color(218, 110, 50), 15) ;
   Button diemtb(320.f , 180.f , 316.f , 71.f, "BANG THONG KE TRUNG BINH KHOA " , font , sf::Color(218, 110, 50), 15) ;
   Button diemtk(636 , 180.f ,  316.f , 71.f, "BANG DIEM TONG KET" , font , sf::Color(218, 110, 50), 15) ;
   Button thoat (1296.f, 180.f ,  87.f , 71.f, "EXIT" , font ,sf::Color(218, 110, 50), 15) ;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
            if(thoat.isClicked(mousePos)){
                return 0 ; 
        }
        if(diemmh.isClicked(mousePos)){
                baseIn1(window) ; 
                return 13 ;
        }
        if(diemtb.isClicked(mousePos)){
                baseIn2(window) ; 
                return 13 ; 
        }
         if(diemtk.isClicked(mousePos)){
                baseIn3(window) ;
                return 13 ; 
        }
    }
    }
        window.clear(sf::Color::White);
        title.draw(window);
        diemmh.draw(window);
        diemtb.draw(window);
        diemtk.draw(window);
        thoat.draw(window);
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}

int ScreenDiem::baseIn1(sf::RenderWindow& window) {
    cout << "DA DI VAO HAM IN DIEM CUA MOT LOP TINH CHI \n" ;
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    Text nienkhoa(306.f, 401.f, 150.f ,27.f ,"NIEN KHOA ", font, sf::Color::Red, 15);
    Text hocki(320.f, 490.f, 150.f, 27.f, "HOC KI ", font, sf::Color::Red, 15);
    Text nhom(802.f, 400.f, 150.f, 27.f, "NHOM ", font, sf::Color::Red, 15);
    Text monhoc(804.f, 494.f, 150.f, 27.f, "MA MON  ", font, sf::Color::Red, 15);
    // Text muc(0.f, 188.f, 108.f, 29.f, "IN BANG DIEM MON HOC ", font, sf::Color::Red, 15);
    // Text title(504.f, 188.f,512.f, 21.f, "HOC KI", font, sf::Color::Red, 15);
    // Text title2(508.f, 227.f, 512.f, 21.f, "HOC KI", font, sf::Color::Red, 15);
    InputField nk(572.f , 400.f , 150.f , 30.f , font ) ; 
    InputField hk(568.f , 494.f , 150.f , 30.f , font ) ; 
    InputField nhom1(1058.f,407.f , 150.f , 30.f , font ) ; 
    InputField ma(1057.f , 494.f , 150.f , 30.f , font ) ; 
    Button in (572.f , 598.f ,  150.f , 43.f , "IN " , font , sf::Color(218, 110, 50), 15) ; 
    Button thoat (797.f , 605.f ,  150.f , 43.f , "THOAT  " , font , sf::Color(218, 110, 50), 15) ; 
    nk.setSelected(true) ; 
    hk.setSelected(true) ; 
    nhom1.setSelected(true) ; 
    ma.setSelected(true) ; 
    while (window.isOpen()) {
        sf::Event event;
        if (nk.isSelected()) nk.textCursor(nk.getInput());
        if (hk.isSelected()) hk.textCursor(hk.getInput());
        if (nhom1.isSelected()) nhom1.textCursor(nhom1.getInput());
        if (ma.isSelected()) ma.textCursor(ma.getInput());
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
            nk.handleMouseClick(mousePos) ; 
            hk.handleMouseClick(mousePos) ;
            nhom1.handleMouseClick(mousePos) ;
            ma.handleMouseClick(mousePos) ;
        if(in.isClicked(mousePos)){
            string nienkhoa = nk.getInput(); 
            int hochi = std::stoi(hk.getInput()); 
            int nhom = std::stoi(nhom1.getInput()); 
            string ma1 = ma.getInput(); 
            // tim vi tri lop tinh chi 
            int vitri = 0  ; 
            int temp = TinhchiList::getInstance().KTLOPTC(TinhchiList::getInstance(),nienkhoa,hochi,nhom,ma1) ; 
            if(temp == -1)
            {
                Data::popup("LOP TINH CHI KHONG PHU HOP VUI LONG NHAP LAI") ;
                break ; 
            } else{
            if(temp != -1){
                temp = vitri ; 
            }
            cout << "VI TRI CUA LOP TINH CHI " << vitri ;
            diemMH(window,vitri) ; 
            return 0 ; 
            }
        }
        if(thoat.isClicked(mousePos)){
            return 0 ; 
        }
    }
    nk.processInput(event) ; 
    hk.processInput(event) ; 
    nhom1.processInput(event) ; 
    ma.processInput(event) ; 
    }
        window.clear(sf::Color::White);
        nienkhoa.draw(window);
        hocki.draw(window);
        nhom.draw(window);
        monhoc.draw(window);
        thoat.draw(window);
        in.draw(window) ; 
        nk.draw(window) ; 
        hk.draw(window) ; 
        nhom1.draw(window) ; 
        ma.draw(window) ; 
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}
int ScreenDiem::diemMH(sf::RenderWindow& window , int vitri) {
    cout << "DA DEN HAM DIEM MON HOC\n" ; 
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    LopTinChi* tc = TinhchiList::getInstance().Nodes[vitri] ; 
    Text title1(497.f, 37.f, 512.f ,39.f ,  "BANG DIEM MON HOC " + tc->MAMH , font, sf::Color::Red, 40);
    Text title2(497.f,77.f, 150.f, 39.f, "NIEN KHOA : " + (tc->NienKhoa) + "  " + "HOC KI : " + std::to_string(tc->HocKy) +"   "  +"NHOM : " + std::to_string(tc->Nhom), font, sf::Color::Red, 15); 
    Button thoat (1485.f , 61.f ,  150.f , 43.f , "THOAT  " , font , sf::Color::Red, 15) ; 
     // Khởi tạo các nút điều hướng
    Button nextPageBtn(876.f, 838.f, 92.f, 50.f, "<=", font, sf::Color(218, 110, 50), 15);
    Button prevPageBtn(728.f, 838.f, 92.f, 50.f, "=>", font, sf::Color(218, 110, 50), 15);

    baocao.clear() ; 
    Data::diemmhtc(diemPath,font,tc->MALOPTC) ; 
    cout << "SO LUONG TEXT HIEN TAI " << baocao.size() ;
    int displayFrom = 0;
    int itemsPerPage = 40;
    while (window.isOpen()) {
        sf::Event event;
        // size_t displayLimit = std::min(displayFrom + itemsPerPage,baocao.size());
         long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(baocao.size()) ? static_cast<int>(baocao.size()) : (displayFrom + itemsPerPage);
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
            if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(baocao.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
        if(thoat.isClicked(mousePos)){
            return 0 ; 
        }
    }
    }
        window.clear(sf::Color::White);
         for (int i = displayFrom; i < displayLimit; i++){
            if (static_cast<int>(baocao.size()) <= i)
                break;
            baocao[i].draw(window);
        }
        title1.draw(window);
        title2.draw(window);
        thoat.draw(window);
        nextPageBtn.draw(window) ; 
        prevPageBtn.draw(window) ; 
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}
int ScreenDiem::baseIn2(sf::RenderWindow& window) {
    cout << "DEN HAM IN DIEM TRUNG BINH KHOA HOC " ;
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
      // Khởi tạo các phần tử giao diện
    Text malop(306.f, 401.f, 150.f ,27.f ,"MALOP", font, sf::Color::Red, 15);
    InputField nk(572.f , 400.f , 150.f , 30.f , font ) ; 
    Button in (572.f , 598.f ,  150.f , 43.f , "IN " , font ,sf::Color(218, 110, 50), 15) ; 
    Button thoat (797.f , 605.f ,  150.f , 43.f , "THOAT  " , font ,sf::Color(218, 110, 50), 15) ; 
    nk.setSelected(true) ; 
    while (window.isOpen()) {
        sf::Event event;
        if (nk.isSelected()) nk.textCursor(nk.getInput());
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
            nk.handleMouseClick(mousePos) ; 
        if(in.isClicked(mousePos)){
            string malop = nk.getInput(); 
            if(DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),malop,DS_LOPSV::getInstance().n) == 0){
                Data::popup("MA LOP KHONG TON TAI ") ;
                break; 
            }else{
                diemTB(window,malop) ; 
                return 0 ; 
            }
           
        }
        if(thoat.isClicked(mousePos)){
            return 0 ; 
        }
        }
        nk.processInput(event) ;
        }
        window.clear(sf::Color::White);
        malop.draw(window);
        thoat.draw(window);
        in.draw(window) ; 
        nk.draw(window) ;
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}
int ScreenDiem::diemTB(sf::RenderWindow& window , string& malop ) {
    cout << "DA DEN HAM DIEM TRUNG BINH KHOA HOC " ;
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
            int vitri ; 
            int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),malop,DS_LOPSV::getInstance().n);
            if(temp != 0){
            if(temp == -1)
            {
                vitri = 0;	
            }else{
                vitri = temp;
            } 
            }
            cout << "VI TRI CUA LOP " << vitri ;
      // Khởi tạo các phần tử giao diện
    Text title1(497.f, 37.f, 512.f ,39.f , "BAMG THONG KE DIEM TRUNG BINH KHOA HOC "  , font, sf::Color::Red, 40);
    Text title2(497.f,77.f, 150.f, 39.f, "LOP : " + malop , font, sf::Color::Red, 15);
    Button thoat (1485.f , 61.f ,  150.f , 43.f , "THOAT  " , font , sf::Color::Red, 15) ; 
    // Khởi tạo các nút điều hướng
    Button nextPageBtn(876.f, 838.f, 92.f, 50.f, "<=", font, sf::Color(218, 110, 50), 15);
    Button prevPageBtn(728.f, 838.f, 92.f, 50.f, "=>", font, sf::Color(218, 110, 50), 15);

    baocao.clear() ; 
    Data::diemtb(diemPath,font,vitri) ; 
    cout <<"SO LUONG TEXT HIEN TAI " << baocao.size() ;
    int displayFrom = 0;
    int itemsPerPage = 40;
    while (window.isOpen()) {
        sf::Event event;
        // size_t displayLimit = std::min(displayFrom + itemsPerPage,baocao.size());
         long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(baocao.size()) ? static_cast<int>(baocao.size()) : (displayFrom + itemsPerPage);
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
             if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(baocao.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
        if(thoat.isClicked(mousePos)){
            return 0 ; 
        }
    }
    }
        window.clear(sf::Color::White);
         for (int i = displayFrom; i < displayLimit; i++){
            if (static_cast<int>(baocao.size()) <= i)
                break;
            baocao[i].draw(window);
        }
        title1.draw(window);
        title2.draw(window);
        thoat.draw(window);
        nextPageBtn.draw(window) ; 
        prevPageBtn.draw(window) ; 
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}
int ScreenDiem::baseIn3(sf::RenderWindow& window) {
    cout << "DEN HAM IN DIEM TONG KET " ; 
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
      // Khởi tạo các phần tử giao diện
    Text malop(306.f, 401.f, 150.f ,27.f ,"MALOP", font, sf::Color::Red, 15);
    InputField nk(572.f , 400.f , 150.f , 30.f , font ) ; 
    Button in (572.f , 598.f ,  150.f , 43.f , "IN " , font , sf::Color(218, 110, 50), 15) ; 
    Button thoat (797.f , 605.f ,  150.f , 43.f , "THOAT  " , font , sf::Color(218, 110, 50), 15) ; 
    nk.setSelected(true) ; 
    while (window.isOpen()) {
        sf::Event event;
        if (nk.isSelected()) nk.textCursor(nk.getInput());
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
            nk.handleMouseClick(mousePos) ; 
        if(in.isClicked(mousePos)){
            string malop = nk.getInput(); 
            if(DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),malop,DS_LOPSV::getInstance().n) == 0){
                Data::popup("MA LOP KHONG TON TAI ") ;
                break  ; 
            }else{
                diemTK(window,malop) ; 
                return 0 ; 
            }
        }
        if(thoat.isClicked(mousePos)){
            return 0 ; 
        }
        }
        nk.processInput(event) ;
        }
        window.clear(sf::Color::White);
        malop.draw(window);
        thoat.draw(window);
        in.draw(window) ; 
        nk.draw(window) ; 
    
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}
int ScreenDiem::diemTK(sf::RenderWindow& window, string& malop) {
    cout <<"DEN HAM IN DIEM TONG KET\n" ; 
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
            int vitri ; 
            int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),malop,DS_LOPSV::getInstance().n);
            if(temp != 0){
            if(temp == -1)
            {
                vitri = 0;	
            }else{
                vitri = temp;
            } 
            }
    cout << "VI TRI CUA LOP " << vitri ;
    int soluongmh = 0 ; 
    for (int i = 0; i < TinhchiList::getInstance().n; i++) {
        bool daTonTai = false;
        // Kiem tra xem ten mon hoc da ton tai trong vector chua
        for (int j = 0; j < i; j++) {
            if (TinhchiList::getInstance().Nodes[i]->MAMH == TinhchiList::getInstance().Nodes[j]->MAMH) {
                daTonTai = true;
                break;
            }
        }
        // Neu chua ton tai, them vao vector
        if (!daTonTai) {
            soluongmh++;
        }
    }
    cout << "SO LUONG MON HOC " << soluongmh ;
    Text title1(497.f, 37.f, 512.f ,39.f ,  "BANG DIEM TONG KET "  , font, sf::Color::Red, 40);
    Text title2(497.f,77.f, 150.f, 39.f, "LOP : " + malop , font, sf::Color::Red, 15);
    Button thoat (1485.f , 61.f ,  150.f , 43.f , "THOAT  " , font , sf::Color::Red, 15) ; 
     // Khởi tạo các nút điều hướng
    Button nextPageBtn(876.f, 838.f, 92.f, 50.f, "<=", font, sf::Color(218, 110, 50), 15);
    Button prevPageBtn(728.f, 838.f, 92.f, 50.f, "=>", font, sf::Color(218, 110, 50), 15);

    baocao.clear() ; 
    Data::diemtk(diemPath,font,vitri) ; 
    cout << "SO LUONG TEXT HIEN TAI " << baocao.size() ;
    int tam = 0 ; 
    if(soluongmh != 0)
    {
        tam = (soluongmh + 3)* 10 ;
    }
    cout << "SO LUONG TRANG HIEN THI " << temp  << endl ;
    int displayFrom = 0;
    int itemsPerPage = tam ; 
    while (window.isOpen()) {
        sf::Event event;
        // size_t displayLimit = std::min(displayFrom + itemsPerPage,baocao.size());
        long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(baocao.size()) ? static_cast<int>(baocao.size()) : (displayFrom + itemsPerPage);
        while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
            if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(baocao.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
        if(thoat.isClicked(mousePos)){
            return 0 ; 
        }
    }
    }
        window.clear(sf::Color::White);
         for (int i = displayFrom; i < displayLimit; i++){
            if (static_cast<int>(baocao.size()) <= i)
                break;
            baocao[i].draw(window);
        }
        title1.draw(window);
        title2.draw(window);
        thoat.draw(window);
         nextPageBtn.draw(window) ; 
        prevPageBtn.draw(window) ; 
        window.display();
    }
    return 0; // Trả về số của màn hình chính hoặc màn hình trước
}


