
#include "PageLopTinChi.h"
#include"DataUtils.h"
#include <fstream>
#include <filesystem>
#include<iostream>
#include<string>

namespace fsys = std::filesystem;
fsys::path creaditclass = "D:\\du an\\SFML\\SFML\\data\\Courses\\creaditclass.csv" ; 

// Định nghĩa hàm showPage8 cho BaseScreenLopTinChi
int BaseScreenLopTinChi::BaseLTC(sf::RenderWindow& window) {
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Handle error if font cannot be loaded
    }
    Text Loptc(0.f, 181.f, 206.f , 35.f ,  "LOP TIN CHI " , font , sf :: Color :: Red ,25) ; 
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
            }
            }
        }
         // Vẽ lại màn hình
        window.clear(sf::Color::White);
        // Vẽ menu chính
        BaseScreen::drawMainMenu(window); 
        // Vẽ các yếu tố lớp học
        Loptc.draw(window) ; 
        window.display();  // Cập nhật màn hình 
    return 0; // Thay thế bằng giá trị hợp lý
}
void BaseScreenLopTinChi::drawMainMenu3(sf::RenderWindow& window) {
    // Khởi tạo font
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return; // Xử lý lỗi nếu không thể tải font
    }

    // Tạo các yếu tố giao diện
       Text Loptc(0.f, 181.f, 206.f , 35.f , "LOP TIN CHI " , font , sf :: Color :: Red ,25) ; 

    // Vẽ các thành phần lên cửa sổ
        window.clear(sf::Color::White);
        BaseScreen::drawMainMenu(window);
        Loptc.draw(window) ; 
}

int ScreenLopTinChi::addTC(sf::RenderWindow& window) {
    cout << "DA VAO HAM ADD CLASS " ;
    cout << "DANH SACH LOP TRUOC KHI THEM\n "<< endl ;
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Return error if font can't be loaded
    }
     int MATC = TinhchiList::getInstance().Nodes[TinhchiList::getInstance().n -1 ]->MALOPTC + 1 ;
    // Create Text and InputField objects
    Text hocki(237.f, 358.f, 158.f, 58.f, "HOC KI ", font, sf::Color::Red, 20);
    Text monhoc(237.f, 445.f, 158.f, 58.f, " MA MON HOC", font, sf::Color::Red, 20);
    Text matc1(237.f, 567.f, 158.f, 58.f, "MA LOP TC  ", font, sf::Color::Red, 20);
    Text svmax(237.f, 689.f, 158.f, 58.f, "SO SV MAX ", font, sf::Color::Red, 20);
    Text nienkhoa(813.f, 358.f, 158.f, 58.f, "NIEN KHOA ", font, sf::Color::Red, 20);
    Text nhom(809.f, 445.f, 158.f, 58.f, "NHOM  ", font, sf::Color::Red, 20);
    Text svmin(809.f, 567.f, 158.f, 58.f, "SO SINH VIEN MIN ", font, sf::Color::Red, 20);
    Text huy(809.f, 689.f, 158.f, 58.f, "HUY LOP", font, sf::Color::Red, 20);
    Text canhbao(366.f,772.f ,812.f , 69.f , " CHI CO HAI HOC KI 1 VA 2  || KY TU IN HOA TU A -> Z " , font , sf::Color(255, 182, 193), 15) ;

    // Input fields for each entry
    InputField HocKi(428.f, 358.f, 271.f, 47.f, font);
    InputField MonHoc(424.f, 445.f, 271.f, 47.f, font);
    // InputField Matc(424.f, 569.f, 325.f, 58.f, font);
    Text Matc(424.f, 569.f, 325.f, 58.f, std::to_string(MATC), font, sf::Color::Red, 20);
    InputField SVmax(424.f, 689.f, 271.f, 47.f, font);
    InputField NienKhoa(1032.f, 358.f,271.f, 47.f, font);
    InputField Nhom(1032.f, 445.f,271.f, 47.f, font);
    InputField SVmin(1032.f, 569.f,271.f, 47.f, font);
    // InputField Huy(1032.f, 688.f, 271.f, 47.f, font);
    // Save button
    // Button saveBtn(1094.f, 763.f, 134.f, 78.f, "SAVE", font, sf::Color::Red, 15);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    std::vector<std::string> items = {"CTDL", "TTR", "KTDH", "AV"};
    Dropdown dropdown(22.f, 256.f, 200.f, 47.f, font, items);
    Text dsmh(22.f, 256.f, 158.f, 58.f, "DS MA MON HOC", font, sf::Color(218, 110, 50), 20);

    // Initial selection state
    HocKi.setSelected(true);
    MonHoc.setSelected(true);
    // Matc.setSelected(true);
    SVmax.setSelected(true);
    NienKhoa.setSelected(true);
    Nhom.setSelected(true);
    SVmin.setSelected(true);
    // Huy.setSelected(true);
    // Main loop for handling window events and rendering
    while (window.isOpen()) {
        sf::Event event;
        if (HocKi.isSelected()) HocKi.textCursor(HocKi.getInput());
        if (MonHoc.isSelected()) MonHoc.textCursor(MonHoc.getInput());
        // if (Matc.isSelected()) Matc.textCursor(Matc.getInput());
        if (SVmax.isSelected()) SVmax.textCursor(SVmax.getInput());
        if (NienKhoa.isSelected()) NienKhoa.textCursor(NienKhoa.getInput());
        if (Nhom.isSelected()) Nhom.textCursor(Nhom.getInput());
        if (SVmin.isSelected()) SVmin.textCursor(SVmin.getInput());
        // if (Huy.isSelected()) Huy.textCursor(Huy.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Mouse click handling for input fields and the save button
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                HocKi.handleMouseClick(mousePos);
                MonHoc.handleMouseClick(mousePos);
                // Matc.handleMouseClick(mousePos);
                SVmax.handleMouseClick(mousePos);
                NienKhoa.handleMouseClick(mousePos);
                Nhom.handleMouseClick(mousePos);
                SVmin.handleMouseClick(mousePos);
                // Huy.handleMouseClick(mousePos);
                 dropdown.handleClick(mousePos); // Xử lý nhấp chuột

                 if(thoat.isClicked(mousePos)){
                    return 8 ; 
                }
                // Check if SAVE button is clicked
                if (ghi.isClicked(mousePos)) {
                    std::string hocKi = HocKi.getInput();
                    std::string monHoc = MonHoc.getInput();
                    // std::string matc = Matc.getInput();
                    std::string svMax = SVmax.getInput();
                    std::string nienKhoa = NienKhoa.getInput();
                    std::string nhom = Nhom.getInput();
                    std::string svMin = SVmin.getInput();
                    // std::string huy1 = Huy.getInput();

                    // Check if all fields are filled before saving
                    if (!hocKi.empty() && !monHoc.empty() && !svMax.empty() &&
                        !nienKhoa.empty() && !nhom.empty() && !svMin.empty() ) {
                        int matcInt = MATC ;      // Chuyển `std::string` thành `int`
                        int hocKiInt = std::stoi(hocKi);
                        int nhomInt = std::stoi(nhom);
                        int svMinInt = std::stoi(svMin);
                        int svMaxInt = std::stoi(svMax);
                        bool huy = false ;
                        LopTinChi tc( matcInt,monHoc,nienKhoa,hocKiInt,nhomInt,svMinInt,svMaxInt,huy) ; 
                        TinhchiList::getInstance().addTC(TinhchiList::getInstance(),tc) ; 
                         custom::vector<std::string> newRow = { "1",monHoc,nienKhoa ,hocKi,nhom ,svMax, svMin ,"false","StudentID4"}; 
                          if (Data::add(creaditclass, font, newRow)) {
                        std::cout << "thanh cong " << std::endl;
                        } else {
                        std::cerr << "not load" << std::endl;
                        }
                        cout << "DANH SACH LOP TIN CHI SAU KHI THEM\n "<< endl ;
                        TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance());
                        Data::popup("THEM THANH CONG TINH CHI  ") ;
                    }
                }
            }

            // Process input for each field
            HocKi.processInput(event);
            MonHoc.processInput(event);
            // Matc.processInput(event);
            SVmax.processInput(event);
            NienKhoa.processInput(event);
            Nhom.processInput(event);
            SVmin.processInput(event);
            // Huy.processInput(event);

            //   sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // // Chuyển đổi trạng thái chọn cho các trường nhập liệu
            // HocKi.setSelected(HocKi.isSelected() && !ghi.isClicked(mousePos));
            // MonHoc.setSelected(MonHoc.isSelected() && !ghi.isClicked(mousePos));
            // Matc.setSelected(Matc.isSelected() && !ghi.isClicked(mousePos));
            // SVmax.setSelected(SVmax.isSelected() && !ghi.isClicked(mousePos));
            // NienKhoa.setSelected(NienKhoa.isSelected() && !ghi.isClicked(mousePos));
            // Nhom.setSelected(Nhom.isSelected() && !ghi.isClicked(mousePos));
            // Huy.setSelected(Huy.isSelected() && !ghi.isClicked(mousePos));
        }
        // Render the screen
        window.clear(sf::Color::White);
        BaseScreenLopTinChi::drawMainMenu3(window); // Draw base menu or background
        // Draw the UI elements
       // title.draw(window);
        hocki.draw(window);
        monhoc.draw(window);
        // matc.draw(window);
        svmax.draw(window);
        nienkhoa.draw(window);
        nhom.draw(window);
        svmin.draw(window);
        huy.draw(window);
        
        matc1.draw(window);
        HocKi.draw(window);
        MonHoc.draw(window);
        Matc.draw(window);
        SVmax.draw(window);
        NienKhoa.draw(window);
        Nhom.draw(window);
        SVmin.draw(window);
        dropdown.draw(window); // Vẽ danh sách thả xuống
        dsmh.draw(window);
        // Huy.draw(window);
        // saveBtn.draw(window);
        canhbao.draw(window) ;
        window.display();
    }
    return 0; // Return to previous screen or main menu
}
 int ScreenLopTinChi::showTC(sf::RenderWindow& window){
    cout << "DA VAO HAM SHOW TC\n " ;
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
    TCList.clear() ; 
    buttonTC.clear() ; 
    // Khởi tạo các nút điều hướng
    Button nextPageBtn(901.f, 850.f, 92.f, 50.f, "Next", font, sf::Color::Red, 15);
    Button prevPageBtn(606.f, 850.f, 92.f, 50.f, "Prev", font, sf::Color::Red, 15);
    Button them(264.f, 149.f, 151.f, 28.f, "THEM", font, sf::Color::Red, 15);

    // Khởi tạo các nhãn
    Text matc(22.f, 236.f, 170.f, 59.f, "MA LOP TC  ", font, sf::Color::Red, 20);
    Text mamon(192.f, 236.f, 170.f, 59.f, "MA MON HOC ", font, sf::Color::Red, 20);
    Text nienkhoa(362.f, 236.f, 170.f, 59.f, "NIEN KHOA ", font, sf::Color::Red, 20);
    Text hocki(536.f, 236.f, 170.f, 59.f, "HOC KI ", font, sf::Color::Red, 20);
    Text nhom(706.f, 236.f, 170.f, 59.f, "NHOM  ", font, sf::Color::Red, 20);
    Text svmin(876.f, 236.f, 170.f, 59.f, "SO SV MIN ", font, sf::Color::Red, 20);
    Text svmax(1046.f, 236.f, 170.f, 59.f, "SO SV MAX ", font, sf::Color::Red, 20);
    Text huy(1176.f, 236.f, 170.f, 59.f, "HUY LOP", font, sf::Color::Red, 20);
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 850.f);
    Data::displaytc1(TinhchiList::getInstance(), font ) ;
    cout <<"DANH SACH LOP TIN CHI HIEN TAI " ;
    TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance());
    cout << "SO LUONG BUTTON VA TEXT HIEN TAI " << TCList.size() << " " << buttonTC.size() << endl ;
    int displayFrom = 0;
    int itemsPerPage = 48;

    while (window.isOpen()) {
        sf::Event event;
        // size_t displayLimit = std::min(displayFrom + itemsPerPage,TCList.size());
        long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(TCList.size()) ? static_cast<int>(TCList.size()) : (displayFrom + itemsPerPage);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(TCList.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }

                if (them.isClicked(mousePos)) {
                    addTC(window) ; 
                    return 8 ; 
                }
                // Kiểm tra nếu một trong các nút môn học trong buttonsubject được nhấn
                for (int i = displayFrom; i < displayLimit && i < static_cast<int>(TCList.size()); i++) {
                        if (buttonTC[i].isClicked(mousePos)) {
                            int  matc = std::stoi(buttonTC[i].getText());
                            int vitri = TinhchiList::getInstance().findTC(TinhchiList::getInstance(),matc) ; 
                            cout << " DA NHAN DUOC VITRI LOP TINH CHI  " << vitri << endl ;
                            LopTinChi* tc  = TinhchiList::getInstance().Nodes[vitri] ; 
                            InTC(window,tc);  // Hiển thị thông tin môn học tương ứng
                            cout << "DA RA KHOI HAM IN TINH CHI " ;
                            return 8 ;
                        } 
                        }
                if(thoat.isClicked(mousePos)){
                    return 0 ; 
                }
            }
        }

        //Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (TCList.size() + itemsPerPage - 1) / itemsPerPage;

        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        window.clear(sf::Color::White);
        // Vẽ menu chính  
        BaseScreenLopTinChi::drawMainMenu3(window);
         for (int i = displayFrom; i < displayLimit; i++){
            if (static_cast<int>(TCList.size()) <= i && static_cast<int>(buttonTC.size()) <= i)
                break;
            TCList[i].draw(window);
            buttonTC[i].draw(window) ; 
    }
        //Vẽ các nút và thông tin trang
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        window.draw(pageText);
        matc.draw(window); 
        hocki.draw(window) ;
        mamon.draw(window) ;
        svmax.draw(window) ;
        nienkhoa.draw(window) ;
        nhom.draw(window) ;
        svmin.draw(window) ;
        huy.draw(window) ;
        thoat.draw(window) ; 
        window.display();
    }
    return 0 ; 
 }

int ScreenLopTinChi::InTC(sf::RenderWindow& window, LopTinChi* tc) {
    cout << "DA VAO HAM IN TINH CHI " ;
    cout <<"CAC LOP TINH CHI HIEN TAI\n " ; 
    TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance());
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Return -1 if the font can't be loaded
    }
    int vitri ; 
    int temp = TinhchiList::getInstance().findTC(TinhchiList::getInstance(),tc->MALOPTC) ;
    if(temp != -1){
        vitri = temp ; 
    }
    string maloptc = std::to_string(tc->MALOPTC) ; 
    Text title(259.f, 291.f, 618.f, 39.f, "THONG TIN LOP TC ", font, sf::Color::Red, 15);
    Text hocki(237.f, 358.f, 158.f, 58.f, "HOC KI ", font, sf::Color::Red, 20);
    Text matc(237.f, 445.f, 158.f, 58.f, "MA LOP TC ", font, sf::Color::Red, 20);
    Text mamon(237.f, 567.f, 158.f, 58.f, "MA MON HOC ", font, sf::Color::Red, 20);
    Text svmax(237.f, 689.f, 158.f, 58.f, "SO SV MAX ", font, sf::Color::Red, 20);
    Text nienkhoa(813.f, 358.f, 158.f, 58.f, "NIEN KHOA ", font, sf::Color::Red, 20);
    Text nhom(809.f, 445.f, 158.f, 58.f, "NHOM  ", font, sf::Color::Red, 20);
    Text svmin(809.f, 567.f, 158.f, 58.f, "SO SINH VIEN MIN ", font, sf::Color::Red, 20);
    Text huy(809.f, 689.f, 158.f, 58.f, "HUY LOP", font, sf::Color::Red, 20);

    Button them(264.f, 149.f, 151.f, 28.f, "THEM", font, sf::Color::Red, 15);
    Button xoa(477.f, 149.f, 151.f, 28.f, "XOA", font, sf::Color::Red, 15);
    Button ghi(944.f, 149.f, 151.f, 28.f, "GHI", font, sf::Color::Red, 15);
    Button thoat(1202.f, 149.f, 84.f, 28.f, "THOAT", font, sf::Color::Red, 15);
    Button sua(722.f, 149.f, 151.f, 28.f, "SUA", font, sf::Color::Red, 15);

    // Input fields for each entry
    Text HocKi(428.f, 358.f, 271.f, 47.f, std::to_string(tc->HocKy), font, sf::Color::Red, 15);
    Text Matc(424.f, 445.f, 271.f, 47.f, std::to_string(tc->MALOPTC), font, sf::Color::Red, 15);
    Text Mamh(424.f, 569.f, 325.f, 58.f, tc->MAMH, font, sf::Color::Red, 15);
    Text SVmax(424.f, 689.f, 271.f, 47.f, std::to_string(tc->soSvMax), font, sf::Color::Red, 15);
    Text NienKhoa(1032.f, 358.f, 271.f, 47.f, tc->NienKhoa, font, sf::Color::Red, 15);
    Text Nhom(1032.f, 445.f, 271.f, 47.f, std::to_string(tc->Nhom), font, sf::Color::Red, 15);
    Text SVmin(1032.f, 569.f, 271.f, 47.f, std::to_string(tc->soSvMin), font, sf::Color::Red, 15);
    Text Huy(1032.f, 688.f, 271.f, 47.f, tc->HuyLop ? "" : "HUY", font, sf::Color::Red, 15);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // Check if any buttons are clicked
                if (sua.isClicked(mousePos)) {
                    if(tc->Dssvdk.size(tc->Dssvdk) > 0){
                        Data::popup("LOP TINH CHI NAY DA CO SINH VIEN DANG KY KHONG DUOC SUA ") ;
                    }else{
                        fixTC(window,tc) ; 
                        return 8 ;
                    } 
                }
                if (thoat.isClicked(mousePos)) {
                    return 8;
                }

                if (xoa.isClicked(mousePos)) {
                    if(tc->Dssvdk.size(tc->Dssvdk) > 0){
                        Data::popup("LOP TINH CHI NAY DA CO SINH VIEN DANG KY KHONG DUOC XOA ") ;
                    }else if(Data::confirm("BAN CO CHAN CHAN HUY LOP TINH CHI NAY KHONG "))
                    {
                        TinhchiList::getInstance().removeTC(TinhchiList::getInstance(),vitri) ;
                        Data::deletefile(creaditclass , maloptc) ; 
                        cout << "LOP TINH CHI SAU KHI XAO " ; 
                        TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance());
                        Data::popup("DA HUY THANH CONG LOP TIN CHI " ) ; 
                        return 8 ; 
                    }
                }
            }
        }

        // Draw the interface components
        window.clear(sf::Color::White);

        // Draw the base screen and menu
        BaseScreenLopTinChi::drawMainMenu3(window);

        // Draw text components
        title.draw(window);
        hocki.draw(window);
        matc.draw(window);
        mamon.draw(window);
        svmax.draw(window);
        nienkhoa.draw(window);
        nhom.draw(window);
        svmin.draw(window);
        huy.draw(window);

        HocKi.draw(window) ; 
        Matc.draw(window) ; 
        Mamh.draw(window) ; 
        SVmax.draw(window) ; 
        SVmin.draw(window) ; 
        Nhom.draw(window) ; 
        Huy.draw(window) ; 
        NienKhoa.draw(window) ; 

        // Draw buttons
        them.draw(window);
        xoa.draw(window);
        thoat.draw(window);
        sua.draw(window);

        window.display();
    }
    return 0;
}

int  ScreenLopTinChi::fixTC(sf::RenderWindow& window, LopTinChi* tc) {
    cout << "DA VAO HAM FIX TINH CHI " ;
    cout << "CAC LOP TINH CHI HIEN TAI\n " ;
    TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance());
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1 ; // Trả về lỗi nếu không tải được font
    }
    // Các thành phần giao diện
    Text title(259.f, 291.f, 618.f, 39.f, "THONG TIN LOP TINH CHI ", font, sf::Color::Red, 15);
    Text hocki1(237.f, 358.f, 158.f, 58.f, "HOC KI ", font, sf::Color::Red, 20);
    Text matc1(237.f, 445.f, 158.f, 58.f, "MA LOP TC ", font, sf::Color::Red, 20);
    Text mamon1(237.f, 567.f, 158.f, 58.f, "MA MON HOC ", font, sf::Color::Red, 20);
    Text svmax1(237.f, 689.f, 158.f, 58.f, "SO SV MAX ", font, sf::Color::Red, 20);
    Text nienkhoa1(813.f, 358.f, 158.f, 58.f, "NIEN KHOA ", font, sf::Color::Red, 20);
    Text nhom1(809.f, 445.f, 158.f, 58.f, "NHOM  ", font, sf::Color::Red, 20);
    Text svmin1(809.f, 567.f, 158.f, 58.f, "SO SINH VIEN MIN ", font, sf::Color::Red, 20);
    Text huy1(809.f, 689.f, 158.f, 58.f, "HUY LOP", font, sf::Color::Red, 20);
    // InputFields
    std::vector<InputField> inputFields = {
        InputField(428.f, 358.f, 271.f, 47.f, font),
        // InputField(514.f, 370.f, 271.f, 47.f, font),
        InputField(424.f, 569.f, 271.f, 47.f, font),
        InputField(424.f, 689.f, 271.f, 47.f, font),
        InputField(1032.f, 358.f, 271.f, 47.f, font),
        InputField(1032.f, 445.f, 271.f, 47.f, font),
        InputField(1032.f, 569.f, 271.f, 47.f, font),
        InputField(1032.f, 688.f, 271.f, 47.f, font)
    };
    // Các text components của lớp học
    EditableText hocki2(428.f, 358.f, std::to_string(tc->HocKy), font, &inputFields[0]);
    Text matc2(424.f, 445.f, 158.f, 58.f, std::to_string(tc->MALOPTC), font, sf::Color::Red, 20);
    EditableText mamon2(424.f, 569.f, tc->MAMH, font,&inputFields[1]); // Đã là string
    EditableText svmax2(424.f, 689.f, std::to_string(tc->soSvMax), font,&inputFields[2]);
    EditableText nienkhoa2(1032.f, 358.f, tc->NienKhoa, font,&inputFields[3]); // Đã là string
    EditableText nhom2(1032.f, 445.f, std::to_string(tc->Nhom), font,&inputFields[4]);
    EditableText svmin2(1032.f, 569.f, std::to_string(tc->soSvMin), font, &inputFields[5]);
    EditableText huy2(1032.f, 688.f, tc->HuyLop ? "YES" : "NO", font, &inputFields[6]); // Convert bool to "YES" or "NO"
    string maloptc = std::to_string(tc->MALOPTC) ; 
    // Các nút chức năng
    Button them(264.f, 149.f, 151.f, 28.f, "THEM", font, sf::Color::Red, 15);
    Button xoa(477.f, 149.f, 151.f, 28.f, "XOA", font, sf::Color::Red, 15);
    Button ghi(944.f, 149.f, 151.f, 28.f, "GHI", font, sf::Color::Red, 15);
    Button thoat(1202.f, 149.f, 84.f, 28.f, "THOAT", font, sf::Color::Red, 15);
    Button sua(722.f, 149.f, 151.f, 28.f, "SUA", font, sf::Color::Red, 15);
    // // Set các trường đã chọn
    // for (auto& field : inputFields) {
    //     field.setSelected(true);
    // }

    while (window.isOpen()) {
        sf::Event event;
         // Set các trường đã chọn
    for (auto& field : inputFields) {
         if (field.isSelected()) field.textCursor(field.getInput());
    }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            hocki2.update(event);
            mamon2.update(event);
            svmax2.update(event);
            nienkhoa2.update(event);
            nhom2.update(event);  
            svmin2.update(event);
            huy2.update(event);
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                hocki2.handleMouseClick(mousePos);
                mamon2.handleMouseClick(mousePos);
                svmax2.handleMouseClick(mousePos);
                nienkhoa2.handleMouseClick(mousePos);
                nhom2.handleMouseClick(mousePos);
                svmin2.handleMouseClick(mousePos);
                huy2.handleMouseClick(mousePos);
                // Kiểm tra nếu nút "GHI" được nhấn
                if (ghi.isClicked(mousePos)) {
                    string hocki = hocki2.getText() ; 
                    string mamon = mamon2.getText() ; 
                    string svmax = svmax2.getText() ; 
                    string nienkhoa = nienkhoa2.getText() ; 
                    string nhom = nhom2.getText() ; 
                    string svmin = svmin2.getText() ; 
                    string huy = huy2.getText() ; 
                    
                    // Kiểm tra thay đổi ở các trường
                    if (hocki != std::to_string(tc->HocKy) || nienkhoa != tc->NienKhoa || 
                        nhom != std::to_string(tc->Nhom) ||
                        mamon != tc->MAMH || svmin != std::to_string(tc->soSvMin) ||
                        svmax != std::to_string(tc->soSvMax) || huy != std::to_string(tc->HuyLop)) {       // Chuyển `std::string` thành `int`
                        int hocKiInt = std::stoi(hocki);
                        int nhomInt = std::stoi(nhom);
                        int svMinInt = std::stoi(svmin);
                        int svMaxInt = std::stoi(svmax);
                        bool huy1 = false ;
                        // // Cập nhật dữ liệu vào CSV
                        custom::vector<std::string> newRow = {maloptc,hocki, mamon, nhom,svmax, svmin, nienkhoa, huy };
                        Data::update(creaditclass,maloptc, newRow);
                        int matcInt = tc->MALOPTC ;
                        LopTinChi tc( matcInt,mamon,nienkhoa,hocKiInt,nhomInt,svMinInt,svMaxInt,huy1) ; 
                        // xu li logic trong ham 
                        TinhchiList::getInstance().updateTC(TinhchiList::getInstance(),tc) ;
                        cout << "LOP TINH CHI SAU KHI DA HIEU CHINH :\n " ; 
                        TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance());
                        Data::popup("HIEU CHINH THANH CONG ") ; 
                    }
                }
                 if(thoat.isClicked(mousePos)){
                    return 8  ;
                }
            }
            // Xử lý nhập liệu cho các input field
            for (auto& field : inputFields) {
                field.updateCursor();
            }

            // Xử lý nhập liệu cho các input field
            // for (auto& field : inputFields) {
            //     field.processInput(event);
            // }
    }
        window.clear(sf::Color::White);
         // Draw the base screen and menu
        BaseScreenLopTinChi::drawMainMenu3(window);

        // Vẽ các yếu tố lớp học
        title.draw(window);
        hocki1.draw(window);
        matc1.draw(window);
        mamon1.draw(window);
        svmax1.draw(window);
        nienkhoa1.draw(window);
        nhom1.draw(window);
        svmin1.draw(window);
        huy1.draw(window);
        matc2.draw(window) ; 
    hocki2.draw(window) ; 
    mamon2.draw(window) ; 
    svmax2.draw(window) ; 
    nienkhoa2.draw(window) ; 
    nhom2.draw(window) ; 
    svmin2.draw(window) ; 
    huy2.draw(window) ; 
        window.display();
}
    return 0 ; 
}