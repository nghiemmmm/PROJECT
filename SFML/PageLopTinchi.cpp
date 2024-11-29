
#include "PageLopTinChi.h"
#include"DataUtils.h"
#include <fstream>
#include <filesystem>
#include<iostream>

namespace fsys = std::filesystem;

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
                // Kiểm tra người dùng có dùng chuột hay không
                // sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Lấy vị trí con trỏ chuột trong cửa sổ

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
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Return error if font can't be loaded
    }

    // Create Text and InputField objects
    Text hocki(237.f, 358.f, 158.f, 58.f, "HOC KI ", font, sf::Color::Red, 20);
    Text monhoc(237.f, 445.f, 158.f, 58.f, "MON HOC", font, sf::Color::Red, 20);
    Text matc(237.f, 567.f, 158.f, 58.f, "MA LOP TC  ", font, sf::Color::Red, 20);
    Text svmax(237.f, 689.f, 158.f, 58.f, "SO SV MAX ", font, sf::Color::Red, 20);
    Text nienkhoa(813.f, 358.f, 158.f, 58.f, "NIEN KHOA ", font, sf::Color::Red, 20);
    Text nhom(809.f, 445.f, 158.f, 58.f, "NHOM  ", font, sf::Color::Red, 20);
    Text svmin(809.f, 567.f, 158.f, 58.f, "SO SINH VIEN MIN ", font, sf::Color::Red, 20);
    Text huy(809.f, 689.f, 158.f, 58.f, "HUY LOP", font, sf::Color::Red, 20);
    // Input fields for each entry
    InputField HocKi(428.f, 358.f, 271.f, 47.f, font);
    InputField MonHoc(424.f, 445.f, 271.f, 47.f, font);
    InputField Matc(424.f, 569.f, 325.f, 58.f, font);
    InputField SVmax(424.f, 689.f, 271.f, 47.f, font);
    InputField NienKhoa(1032.f, 358.f,271.f, 47.f, font);
    InputField Nhom(1032.f, 445.f,271.f, 47.f, font);
    InputField SVmin(1032.f, 569.f,271.f, 47.f, font);
    InputField Huy(1032.f, 688.f, 271.f, 47.f, font);

    // Save button
    Button saveBtn(1094.f, 763.f, 134.f, 78.f, "SAVE", font, sf::Color::Red, 15);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    std::vector<std::string> items = {"Item 1", "Item 2", "Item 3"};
    Dropdown dropdown(389.f, 500.f, 200.f, 40.f, font, items, &Matc);

    // Initial selection state
    HocKi.setSelected(true);
    MonHoc.setSelected(true);
    Matc.setSelected(true);
    SVmax.setSelected(true);
    NienKhoa.setSelected(true);
    Nhom.setSelected(true);
    SVmin.setSelected(true);
    Huy.setSelected(true);

    // Main loop for handling window events and rendering
    while (window.isOpen()) {
        sf::Event event;
        if (HocKi.isSelected()) HocKi.textCursor(HocKi.getInput());
        if (MonHoc.isSelected()) MonHoc.textCursor(MonHoc.getInput());
        if (Matc.isSelected()) Matc.textCursor(Matc.getInput());
        if (SVmax.isSelected()) SVmax.textCursor(SVmax.getInput());
        if (NienKhoa.isSelected()) NienKhoa.textCursor(NienKhoa.getInput());
        if (Nhom.isSelected()) Nhom.textCursor(Nhom.getInput());
        if (SVmin.isSelected()) SVmin.textCursor(SVmin.getInput());
        if (Huy.isSelected()) Huy.textCursor(Huy.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Mouse click handling for input fields and the save button
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                HocKi.handleMouseClick(mousePos);
                MonHoc.handleMouseClick(mousePos);
                Matc.handleMouseClick(mousePos);
                SVmax.handleMouseClick(mousePos);
                NienKhoa.handleMouseClick(mousePos);
                Nhom.handleMouseClick(mousePos);
                SVmin.handleMouseClick(mousePos);
                Huy.handleMouseClick(mousePos);

                 if(thoat.isClicked(mousePos)){
                    return 8 ; 
                }
                // Check if SAVE button is clicked
                if (saveBtn.isClicked(mousePos)) {
                    std::string hocKi = HocKi.getInput();
                    std::string monHoc = MonHoc.getInput();
                    std::string matc = Matc.getInput();
                    std::string svMax = SVmax.getInput();
                    std::string nienKhoa = NienKhoa.getInput();
                    std::string nhom = Nhom.getInput();
                    std::string svMin = SVmin.getInput();
                    std::string huy = Huy.getInput();

                    // Check if all fields are filled before saving
                    if (!hocKi.empty() && !monHoc.empty() && !matc.empty() && !svMax.empty() &&
                        !nienKhoa.empty() && !nhom.empty() && !svMin.empty() && !huy.empty()) {
                    //      std::vector<std::string> newRow = {hocKi, , monHoc, matc , svMax , nienKhoa , nhom , SVMin , huy}; 
                    //         Data::addTC(subjectPath, font, newRow) ; 
                    //    // ham goi xu li dua vao cau truc 
                    }
                }
            }

            // Process input for each field
            HocKi.processInput(event);
            MonHoc.processInput(event);
            Matc.processInput(event);
            SVmax.processInput(event);
            NienKhoa.processInput(event);
            Nhom.processInput(event);
            SVmin.processInput(event);
            Huy.processInput(event);


              sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // Chuyển đổi trạng thái chọn cho các trường nhập liệu
            HocKi.setSelected(HocKi.isSelected() && !ghi.isClicked(mousePos));
            MonHoc.setSelected(MonHoc.isSelected() && !ghi.isClicked(mousePos));
            Matc.setSelected(Matc.isSelected() && !ghi.isClicked(mousePos));
            SVmax.setSelected(SVmax.isSelected() && !ghi.isClicked(mousePos));
            NienKhoa.setSelected(NienKhoa.isSelected() && !ghi.isClicked(mousePos));
            Nhom.setSelected(Nhom.isSelected() && !ghi.isClicked(mousePos));
            Huy.setSelected(Huy.isSelected() && !ghi.isClicked(mousePos));
        }

        // Render the screen
        window.clear(sf::Color::White);
        BaseScreenLopTinChi::drawMainMenu3(window); // Draw base menu or background

        // Draw the UI elements
       // title.draw(window);
        hocki.draw(window);
        monhoc.draw(window);
        matc.draw(window);
        svmax.draw(window);
        nienkhoa.draw(window);
        nhom.draw(window);
        svmin.draw(window);
        huy.draw(window);

        HocKi.draw(window);
        MonHoc.draw(window);
        Matc.draw(window);
        SVmax.draw(window);
        NienKhoa.draw(window);
        Nhom.draw(window);
        SVmin.draw(window);
        Huy.draw(window);

        saveBtn.draw(window);

        // Display everything
        window.display();
    }
    
    return 0; // Return to previous screen or main menu
}
 int ScreenLopTinChi::showTC(sf::RenderWindow& window){
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }

    // Khởi tạo các nút điều hướng
    Button nextPageBtn(901.f, 833.f, 92.f, 62.f, "Next", font, sf::Color::Red, 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 62.f, "Prev", font, sf::Color::Red, 15);
    Button them(264.f, 149.f, 151.f, 28.f, "THEM", font, sf::Color::Red, 15);

    // Khởi tạo các nhãn
    Text matc(13.f, 240.f, 165.f, 41.f, "THONG TIN LOP TIN CHI ", font, sf::Color::Red, 20);
    Text hocki(237.f, 358.f, 165.f, 41.f, "HOC KI ", font, sf::Color::Red, 20);
    Text monhoc(351.f, 240.f, 165.f, 41.f, "MON HOC", font, sf::Color::Red, 20);
    Text mamon(512.f, 240.f,165.f, 41.f, "MA MON HOC ", font, sf::Color::Red, 20);
    Text svmax(1011.f, 689.f, 165.f, 41.f, "SO SV MAX ", font, sf::Color::Red, 20);
    Text nienkhoa(190.f, 241.f,165.f, 41.f, "NIEN KHOA ", font, sf::Color::Red, 20);
    Text nhom(681.f, 445.f, 165.f, 41.f, "NHOM  ", font, sf::Color::Red, 20);
    Text svmin(846.f, 567.f,165.f, 41.f, "SO SINH VIEN MIN ", font, sf::Color::Red, 20);
    Text huy(1176.f, 689.f, 94.f, 27.f, "HUY LOP", font, sf::Color::Red, 20);

    
    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f);

    // fsys::path classPath = "D:\\du an\\SFML\\SFML\\lop.csv";
    // Data::getlop(classPath) ;   
    // DS_LOPSV::getInstance().HienThiDanhSachLop();
    // Data::displaylop(classPath , font ) ;
    
    int displayFrom = 0;
    int itemsPerPage = 10;

    while (window.isOpen()) {
        sf::Event event;
        int displayLimit = std::min(displayFrom + itemsPerPage, static_cast<int>(classList.size()));
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(classList.size())) {
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
                }
                // Kiểm tra nếu một trong các nút môn học trong buttonsubject được nhấn
                for (int i = displayFrom; i < displayLimit && i < Buttonclass.size(); i++) {
                        if (Buttonclass[i].isClicked(mousePos)) {
                            cout << 12 ; 
                            // string ma = ButtonTC.getText() ; 
                            // cout << ma ; 
                            // LopTinChi selectedTC = { } ; 
                            // InTC(window,selectedTC);  // Hiển thị thông tin môn học tương ứng
                            // Dừng vòng lặp sau khi tìm thấy môn học được nhấn
                        }
                        return 8 ; 
                        }
            }
        }

        //Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (classList.size() + itemsPerPage - 1) / itemsPerPage;

        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        window.clear(sf::Color::White);

        // Vẽ menu chính  
        BaseScreenLopTinChi::drawMainMenu3(window);

        
         for (int i = displayFrom; i < displayLimit; i++){
            if (classList.size() <= i && Buttonclass.size() <= i)
                break;
            classList[i].draw(window);
            Buttonclass[i].draw(window) ; 
         //window.display();
    }

        //Vẽ các nút và thông tin trang
        
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        window.draw(pageText);
        // ma.draw(window); 
        // lop.draw(window) ;

        //Chỉ gọi window.display() một lần sau khi vẽ xong
        window.display();
    }
    return 0 ; 
 }

int ScreenLopTinChi::InTC(sf::RenderWindow& window, LopTinChi& selectedTC) {
    cout << 1;

    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Return -1 if the font can't be loaded
    }

    // Interface components
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
    Text HocKi(428.f, 358.f, 271.f, 47.f, std::to_string(selectedTC.HocKy), font, sf::Color::Red, 15);
    Text Matc(424.f, 445.f, 271.f, 47.f, std::to_string(selectedTC.MALOPTC), font, sf::Color::Red, 15);
    Text Mamh(424.f, 569.f, 325.f, 58.f, selectedTC.MAMH, font, sf::Color::Red, 15);
    Text SVmax(424.f, 689.f, 271.f, 47.f, std::to_string(selectedTC.soSvMax), font, sf::Color::Red, 15);
    Text NienKhoa(1032.f, 358.f, 271.f, 47.f, selectedTC.NienKhoa, font, sf::Color::Red, 15);
    Text Nhom(1032.f, 445.f, 271.f, 47.f, std::to_string(selectedTC.Nhom), font, sf::Color::Red, 15);
    Text SVmin(1032.f, 569.f, 271.f, 47.f, std::to_string(selectedTC.soSvMin), font, sf::Color::Red, 15);
    Text Huy(1032.f, 688.f, 271.f, 47.f, selectedTC.HuyLop ? "YES" : "NO", font, sf::Color::Red, 15);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Check if any buttons are clicked
                if (sua.isClicked(mousePos)) {
                    // Handle "SUA" button click
                   
                   fixTC(window , selectedTC) ; 
                }
                if (thoat.isClicked(mousePos)) {
                    window.close();  // Close the window when "THOAT" is clicked
                }

                if (xoa.isClicked(mousePos)) {
                    // Handle "XOA" button click (delete functionality)
                    // Ensure proper deletion logic is implemented
                    window.close();  // Close the window when "XOA" is clicked
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

        // Draw buttons
        them.draw(window);
        xoa.draw(window);
        thoat.draw(window);
        sua.draw(window);

        window.display();
    }
    return 0;
}

int  ScreenLopTinChi::fixTC(sf::RenderWindow& window, LopTinChi& selectedTC) {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1 ; // Trả về lỗi nếu không tải được font
    }

    LopTinChi a = selectedTC;

    // Các thành phần giao diện
    Text title(259.f, 291.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
    Text hocki1(259.f, 291.f, 158.f, 58.f, "HOC KI ", font, sf::Color::Red, 20);
    Text matc1(259.f, 424.f, 158.f, 58.f, "MA LOP TC ", font, sf::Color::Red, 20);
    Text mamon1(259.f, 560.f, 158.f, 58.f, "MA MON HOC ", font, sf::Color::Red, 20);
    Text svmax1(259.f, 688.f, 158.f, 58.f, "SO SV MAX ", font, sf::Color::Red, 20);
    Text nienkhoa1(259.f, 361.f, 158.f, 58.f, "NIEN KHOA ", font, sf::Color::Red, 20);
    Text nhom1(259.f, 502.f, 158.f, 58.f, "NHOM  ", font, sf::Color::Red, 20);
    Text svmin1(259.f, 617.f, 158.f, 58.f, "SO SINH VIEN MIN ", font, sf::Color::Red, 20);
    Text huy1(259.f, 768.f, 158.f, 58.f, "HUY LOP", font, sf::Color::Red, 20);

    // InputFields
    std::vector<InputField> inputFields = {
        InputField(757.f, 291.f, 271.f, 47.f, font),
        // InputField(514.f, 370.f, 271.f, 47.f, font),
        InputField(541.f, 429.f, 271.f, 47.f, font),
        InputField(514.f, 502.f, 271.f, 47.f, font),
        InputField(541.f, 567.f, 271.f, 47.f, font),
        InputField(514.f, 623.f, 271.f, 47.f, font),
        InputField(541.f, 699.f, 271.f, 47.f, font),
        InputField(514.f, 772.f, 271.f, 47.f, font)
    };

    // Các text components của lớp học
    EditableText hocki2(428.f, 291.f, std::to_string(a.HocKy), font, &inputFields[0]);
    // EditableText matc2(428.f, 424.f, 158.f, 58.f, std::to_string(a.MALOPTC), font, sf::Color::Red, 20);
    EditableText mamon2(428.f, 560.f,  a.MAMH, font,&inputFields[1]); // Đã là string
    EditableText svmax2(428.f, 688.f, std::to_string(a.soSvMax), font,&inputFields[2]);
    EditableText nienkhoa2(428.f, 363.f, a.NienKhoa, font,&inputFields[3]); // Đã là string
    EditableText nhom2(428.f, 502.f, std::to_string(a.Nhom), font,&inputFields[4]);
    EditableText svmin2(428.f, 617.f, std::to_string(a.soSvMin), font, &inputFields[5]);
    EditableText huy2(428.f, 768.f, a.HuyLop ? "YES" : "NO", font, &inputFields[6]); // Convert bool to "YES" or "NO"

    // // InputFields
    // std::vector<InputField> inputFields = {
    //     InputField(757.f, 291.f, 271.f, 47.f, font),
    //     InputField(514.f, 370.f, 271.f, 47.f, font),
    //     InputField(541.f, 429.f, 271.f, 47.f, font),
    //     InputField(514.f, 502.f, 271.f, 47.f, font),
    //     InputField(541.f, 567.f, 271.f, 47.f, font),
    //     InputField(514.f, 623.f, 271.f, 47.f, font),
    //     InputField(541.f, 699.f, 271.f, 47.f, font),
    //     InputField(514.f, 772.f, 271.f, 47.f, font)
    // };

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
                    if (hocki != std::to_string(a.HocKy) || nienkhoa != a.NienKhoa || 
                        nhom != std::to_string(a.Nhom) ||
                        mamon != a.MAMH || svmin != std::to_string(a.soSvMin) ||
                        svmax != std::to_string(a.soSvMax) || huy != std::to_string(a.HuyLop)) {
                        
                        // // Cập nhật dữ liệu vào CSV
                        // std::vector<std::string> newRow = {
                        //     a.MALOPTC,hocki, mamon, nhom, 
                        //     svmax, svmin, nienkhoa, huy
                        // };
                        //Data::update(classPath, a.MALOPTC, newRow);

                        // selectedtc = {a.MALOPTC,hocki, mamon, nhom, 
                        //     svmax, svmin, nienkhoa, huy};
                        // xu li logic trong ham 
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
            for (auto& field : inputFields) {
                field.processInput(event);
            }
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


        window.display();
}
    return 0 ; 
}

// int ScreenLopTinChi::fixTC(sf::RenderWindow& window, LopTinChi& selectedTC) {
//     sf::Font font;
//     if (!font.loadFromFile("Font/arial.ttf")) {
//         return; // Trả về lỗi nếu không tải được font
//     }
//     LopTinChi a = selectedTC;

//     // Tạo các thành phần giao diện với các thuộc tính đã cập nhật
//     //Các thành phần giao diện
//         Text title(259.f, 291.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
//         Text hocki1(259.f, 291.f, 158.f, 58.f, "HOC KI ", font, sf::Color::Red, 20);
//         Text matc1(259.f, 424.f, 158.f, 58.f, "MA LOP TC ", font, sf::Color::Red, 20);
//         Text mamon1(259.f, 560.f, 158.f, 58.f, "MA MON HOC ", font, sf::Color::Red, 20);
//         Text svmax1(259.f, 688.f, 158.f, 58.f, "SO SV MAX ", font, sf::Color::Red, 20);
//         Text nienkhoa1(259.f, 361.f, 158.f, 58.f, "NIEN KHOA ", font, sf::Color::Red, 20);
//         Text nhom1(259.f, 502.f, 158.f, 58.f, "NHOM  ", font, sf::Color::Red, 20);
//         Text svmin1(259.f, 617.f, 158.f, 58.f, "SO SINH VIEN MIN ", font, sf::Color::Red, 20);
//         Text huy1(259.f, 768.f, 158.f, 58.f, "HUY LOP", font, sf::Color::Red, 20);

//         // New text components for the second part of the interface
//        // New text components for the second part of the interface
//         Text hocki2(428.f, 291.f, 158.f, 58.f, std::to_string(a.HocKy), font, sf::Color::Red, 20);
//         Text matc2(428.f, 424.f, 158.f, 58.f, std::to_string(a.MALOPTC), font, sf::Color::Red, 20);
//         Text mamon2(428.f, 560.f, 158.f, 58.f, a.MAMH, font, sf::Color::Red, 20); // Already a string
//         Text svmax2(428.f, 688.f, 158.f, 58.f, std::to_string(a.soSvMax), font, sf::Color::Red, 20);
//         Text nienkhoa2(428.f, 363.f, 158.f, 58.f, a.NienKhoa, font, sf::Color::Red, 20); // Already a string
//         Text nhom2(428.f, 486.f, 158.f, 58.f, std::to_string(a.Nhom), font, sf::Color::Red, 20);
//         Text svmin2(428.f, 617.f, 158.f, 58.f, std::to_string(a.soSvMin), font, sf::Color::Red, 20);
//         Text huy2(428.f, 762.f, 158.f, 58.f, a.HuyLop ? "YES" : "NO", font, sf::Color::Red, 20); // Convert bool to "YES" or "NO"

//             // InputFields for các thuộc tính
//     InputField hockiField(757.f, 291.f, 271.f, 47.f, font);
//     InputField nienKhoaField(514.f, 370.f, 271.f, 47.f, font);
//     InputField matcField(541.f, 429.f, 271.f, 47.f, font);
//     InputField nhomField(514.f, 502.f, 271.f, 47.f, font);
//     InputField mamonField(541.f, 567.f, 271.f, 47.f, font);
//     InputField svminField(514.f, 623.f, 271.f, 47.f, font);
//     InputField svmaxField(541.f, 699.f, 271.f, 47.f, font);
//     InputField huyField(514.f, 772.f, 271.f, 47.f, font);

//     // Các nút chức năng
//     Button them(264.f, 149.f, 151.f, 28.f, "THEM", font, sf::Color::Red, 15);
//     Button xoa(477.f, 149.f, 151.f, 28.f, "XOA", font, sf::Color::Red, 15);
//     Button ghi(944.f, 149.f, 151.f, 28.f, "GHI", font, sf::Color::Red, 15);
//     Button thoat(1202.f, 149.f, 84.f, 28.f, "THOAT", font, sf::Color::Red, 15);
//     Button sua(722.f, 149.f, 151.f, 28.f, "SUA", font, sf::Color::Red, 15);

//     // Set các trường đã chọn
//     hockiField.setSelected(true);
//     nienKhoaField.setSelected(true);
//     matcField.setSelected(true);
//     nhomField.setSelected(true);
//     mamonField.setSelected(true);
//     svminField.setSelected(true);
//     svmaxField.setSelected(true);
//     huyField.setSelected(true);

//     while (window.isOpen()) {
//         sf::Event event;

//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             } else if (event.type == sf::Event::MouseButtonPressed) {
//                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);

//                 if (ghi.isClicked(mousePos)) {
//                     // Lấy dữ liệu từ input fields
//                     std::string hockiInput = hockiField.getInput();
//                     std::string nienKhoaInput = nienKhoaField.getInput();
//                     std::string matcInput = matcField.getInput();
//                     std::string nhomInput = nhomField.getInput();
//                     std::string mamonInput = mamonField.getInput();
//                     std::string svminInput = svminField.getInput();
//                     std::string svmaxInput = svmaxField.getInput();
//                     std::string huyInput = huyField.getInput();
//                     // Kiểm tra thay đổi ở các trường

//                         // Kiểm tra thay đổi ở các trường
//                     if (hockiInput != std::to_string(a.HocKy) || 
//                         nienKhoaInput != a.NienKhoa || 
//                         matcInput != a.MALOPTC || 
//                         nhomInput != std::to_string(a.Nhom) || 
//                         mamonInput != a.MAMH || 
//                         svminInput != std::to_string(a.soSvMin) || 
//                         svmaxInput != std::to_string(a.soSvMax) || 
//                         huyInput != std::to_string(a.HuyLop)) {

//                         // Tạo một vector chứa các giá trị cần thêm vào CSV
//                         std::vector<std::string> newRow = {
//                             matcInput, mamonInput, hockiInput, nhomInput, 
//                             svminInput, svmaxInput, huyInput, nienKhoaInput
//                         };
//                          // Cập nhật dữ liệu vào CSV
//                             Data::update(classPath, a.MALOPTC, newRow);
                       
//                             selectedtc = {
//                             a.MAMH,                    // Mã môn học giữ nguyên từ đối tượng `a`
//                             mamonInput,                // Môn học từ input
//                             std::stoi(hockiInput),     // Học kỳ
//                             std::stoi(nhomInput),      // Nhóm
//                             std::stoi(svminInput),     // Số sinh viên tối thiểu
//                             std::stoi(svmaxInput),     // Số sinh viên tối đa
//                             huyInput == "1",           // Hủy lớp (giả sử "1" là hủy, còn lại là không hủy)
//                             std::stoi(nienKhoaInput)   // Niên khóa
//                         };
//                         //AVLTreeMH::getInstance().Search(AVLTreeMH::getInstance().root, selectedMH);
//                     // Xử lý cập nhật thông tin lớp
//                 }
//             }

//             // Xử lý nhập liệu cho các input field
//             hockiField.processInput(event);
//             nienKhoaField.processInput(event);
//             matcField.processInput(event);
//             nhomField.processInput(event);
//             mamonField.processInput(event);
//             svminField.processInput(event);
//             svmaxField.processInput(event);
//             huyField.processInput(event);
//         }

//         window.clear(sf::Color::White);

//         // Vẽ các yếu tố lớp học
//         title.draw(window);
//         hocki.draw(window);
//         matc.draw(window);
//         mamon.draw(window);
//         svmax.draw(window);
//         nienkhoa.draw(window);
//         nhom.draw(window);
//         svmin.draw(window);
//         huy.draw(window);

//         // Vẽ các input fields
//         hockiField.draw(window);
//         nienKhoaField.draw(window);
//         matcField.draw(window);
//         nhomField.draw(window);
//         mamonField.draw(window);
//         svminField.draw(window);
//         svmaxField.draw(window);
//         huyField.draw(window);

//         // Vẽ các nút
//         them.draw(window);
//         xoa.draw(window);
//         ghi.draw(window);
//         thoat.draw(window);
//         sua.draw(window);

//         window.display();
//     }
// }

// Định nghĩa hàm showPage10 cho ScreenLopHoc_NhapSV
// Định nghĩa hàm showPage10 cho ScreenLopHoc_NhapSV
// int ScreenLopTinChi::showPage10(sf::RenderWindow& window) {
//     sf::Font font;
//     if (!font.loadFromFile("Font/arial.ttf")) {
//         return -1; // Return error if font can't be loaded
//     }

//     // Tạo các đối tượng Text
//     Text info(602.f, 223.f, 342.f, 45.f, "THONG TIN SINH VIEN ", font, sf::Color::Red, 20);
//     Text nienkhoa(705.f, 451.f, 149.f, 31.f, "NIEN KHOA  ", font, sf::Color::Red, 20);
//     Text hocki(705.f, 511.f, 149.f, 31.f, "HOC KI ", font, sf::Color::Red, 20);

//     // Tạo các InputField
//     InputField HocKi(871.f, 513.f, 225.f, 34.f, font);
//     InputField masv(569.f, 304.f, 243.f, 40.f, font);
//     InputField NienKhoa(871.f, 446.f, 225.f, 34.f, font);

//     // Tạo các nút Button
//     Button tim(1170.f, 468.f, 111.f, 76.f, "TIM", font, sf::Color::Red, 15);
//     Button tracuu(940.f, 310.f, 148.f, 40.f, "TRA CUU ", font, sf::Color::Red, 15);
//     Button them(940.f, 360.f, 148.f, 40.f, "THEM", font, sf::Color::Red, 15);  // Assuming you want a "THEM" button
//     Button xoa(940.f, 410.f, 148.f, 40.f, "XOA", font, sf::Color::Red, 15);   // Assuming you want a "XOA" button

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             } else if (event.type == sf::Event::MouseButtonPressed) {
//                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);

//                 // Kiểm tra các nút được nhấn
//                 if (tim.isClicked(mousePos)) {
//                     // Thực hiện hành động khi nút "TIM" được nhấn
//                     std::string studentId = masv.getInput();
//                     std::string semester = HocKi.getInput();
//                     std::string year = NienKhoa.getInput();
//                     // Process the search action based on inputs
//                     std::cout << "Searching for student ID: " << studentId << " in semester: " << semester << " and year: " << year << std::endl;
//                 }
//                 if (tracuu.isClicked(mousePos)) {
//                     window.close();  // Đóng cửa sổ khi nhấn nút "TRA CUU"
//                 }
//                 if (them.isClicked(mousePos)) {
//                     // Handle add action
//                     std::cout << "Add new student" << std::endl;
//                     // Add logic here
//                 }
//                 if (xoa.isClicked(mousePos)) {
//                     // Handle delete action
//                     std::cout << "Delete student" << std::endl;
//                     // Delete logic here
//                 }
//             }
//         }

//         // Vẽ các thành phần lên màn hình
//         window.clear(sf::Color::White);
//         info.draw(window);
//         nienkhoa.draw(window);
//         hocki.draw(window);

//         masv.draw(window);
//         HocKi.draw(window);
//         NienKhoa.draw(window);

//         tim.draw(window);
//         tracuu.draw(window);
//         them.draw(window);
//         xoa.draw(window);

//         window.display();
//     }

//     return 0; // Trả về số của màn hình chính hoặc màn hình trước
// }


// // Định nghĩa hàm showPage11 cho ScreenLopHoc_NhapSV_Edit
// int ScreenLopTinChi::showPage11(sf::RenderWindow& window) {
//     sf::Font font;
//     if (!font.loadFromFile("Font/arial.ttf")) {
//         return -1; // Return error if font can't be loaded
//     }

//     // Tạo các đối tượng Text
//     Text ma(533.f, 270.f, 342.f, 45.f, "MA LOP TIN CHI  ", font, sf::Color::Red, 20);
//     Text mh(541.f, 318.f, 342.f, 45.f, "MON HOC ", font, sf::Color::Red, 20);

//     // Tạo các ô văn bản hiển thị thông tin
//     // Text Ma(711.f, 270.f, 369.f, 40.f, font);  // Text hiển thị mã lớp
//     // Text HocKi(715.f, 318.f, 369.f, 40.f, font);  // Text hiển thị môn học

//     // Tạo các nút Button
//     Button huy(593.f, 396.f, 129.f, 40.f, "HUY DANG KY", font, sf::Color::Red, 15);
//     Button dang(831.f, 396.f, 129.f, 40.f, "DANG KY", font, sf::Color::Red, 15);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             } else if (event.type == sf::Event::MouseButtonPressed) {
//                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);

//                 // Kiểm tra các nút được nhấn
//                 if (huy.isClicked(mousePos)) {
//                     std::cout << "Huỷ đăng ký" << std::endl;
//                     // Thêm logic huỷ đăng ký tại đây
//                 }
//                 if (dang.isClicked(mousePos)) {
//                     std::cout << "Đăng ký mới" << std::endl;
//                     // Thêm logic đăng ký mới tại đây
//                 }
//             }
//         }

//         // Vẽ các thành phần lên màn hình
//         window.clear(sf::Color::White);
//         ma.draw(window);
//         mh.draw(window);
//         // Ma.draw(window);
//         // HocKi.draw(window);

//         huy.draw(window);
//         dang.draw(window);

//         window.display();
//     }

//     return 0; // Trả về số của màn hình chính hoặc màn hình trước
// }


// // Định nghĩa hàm showPage12 cho ScreenLopHoc_InSV
// int ScreenLopTinChi::showPage12(sf::RenderWindow& window) {
//     // Logic cho màn hình in danh sách sinh viên
//     // Vẽ các thành phần cần thiết và xử lý sự kiện
//     // Có thể thêm điều kiện vào màn hình con
//     // return 13; 
//     return 0; // Trả về số của màn hình chính hoặc màn hình trước
// }
