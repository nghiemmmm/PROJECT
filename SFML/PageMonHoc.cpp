#include "PageMonHoc.h" // Bao gồm tệp header ở đây
#include"DataUtils.h"
#include <fstream>
#include <filesystem>
#include<iostream>
namespace fsys = std::filesystem;

// Biến toàn cục
fsys::path subjectPath = "D:\\du an\\SFML\\SFML\\Courses\\subjects.csv";
int BaseScreenMonHoc::showBaseMonHoc(sf::RenderWindow& window) {
   sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Handle error if font cannot be loaded
    }
    Text MonHoc(0.f, 181.f, 206.f , 35.f ,  "MON HOC " , font , sf :: Color :: Red ,25) ; 
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
        MonHoc.draw(window) ; 
        window.display();  // Cập nhật màn hình 
    return 0; // Thay thế bằng giá trị hợp lý
}
void BaseScreenMonHoc::drawMainMenu2(sf::RenderWindow& window) {
    // Khởi tạo font
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return; // Xử lý lỗi nếu không thể tải font
    }

    // Tạo các yếu tố giao diện
      Text MonHoc(0.f, 181.f, 206.f , 35.f ,  "MON HOC " , font , sf :: Color :: Red ,25) ;

    // Vẽ các thành phần lên cửa sổ
        window.clear(sf::Color::White);
        BaseScreen::drawMainMenu(window);
        MonHoc.draw(window) ; 
}

int ScreenMonHoc::showSubject(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
    subjectList.clear();
    buttonsubject.clear();

    // sf::RectangleShape square(sf::Vector2f(1267, 640)); // Tạo ô vuông kích thước `size x size`
    // square.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
    // square.setPosition(50.f, 243.f);     

    // Khởi tạo các nút điều hướng
    Button nextPageBtn(901.f, 833.f, 92.f, 50.f, "Next", font, sf::Color(218, 110, 50), 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 50.f, "Prev", font, sf::Color(218, 110, 50), 15);
   
    // Khởi tạo các nhãn
    Text ma(68.f, 389.f, 234.f, 35.f, "MAMH", font, sf::Color::Red, 15);
    Text ten(302.f, 389.f, 422.f, 35.f, "TENMH", font, sf::Color::Red, 15);
    Text lt(724.f, 389.f, 260.f, 35.f, "STCLT", font, sf::Color::Red, 15);
    Text th(984.f, 389.f, 296.f, 35.f, "STCTH", font, sf::Color::Red, 15);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color(255, 182, 193), 15 ) ; 

    InputField inputField(333.f, 201.f, 158.f, 62.f, font);
    Text mh(138.f , 208.f , 158.f, 62.f, "MON HOC  : "  ,font, sf::Color(255, 182, 193), 15 )  ;
    Button tim(507.f , 224.f ,158.f, 62.f, "TIM "  , font, sf::Color(255, 182, 193), 15) ;

    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f);
   
    cout << "CAY AVL HIEN TAI :\n ";
    AVLTreeMH::getInstance().InOrder(AVLTreeMH::getInstance().root);
    Data::displaymonhoc(AVLTreeMH::getInstance(), font);
    cout << "SO LUONG BUTTON VA TEXT HIEN TAI " << subjectList.size() << " " << buttonsubject.size() << endl;
    int displayFrom = 0;
    int itemsPerPage = 16;
    inputField.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        // long long  displayLimit = std::min(displayFrom + itemsPerPage,subjectList.size());
        long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(subjectList.size()) ? static_cast<int>(subjectList.size()) : (displayFrom + itemsPerPage);
        if (inputField.isSelected()) inputField.textCursor(inputField.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(subjectList.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
                if(tim.isClicked(mousePos)){
                    string ma = inputField.getInput() ; 
                    PTRMH p = AVLTreeMH::getInstance().Search1(AVLTreeMH::getInstance().root,ma) ; 
                    if(p == NULL){
                        Data::popup("MON HOC KHONG TON TAI ") ; 
                        break ;  
                    }else{
                        MonHoc selectedMH = {p->mh.MAMH,p->mh.TENMH,p->mh.STCLT,p->mh.STCTH} ; 
                        InSubject(window, selectedMH) ; 
                        return 3 ; 
                    } 
                }
                if (them.isClicked(mousePos)) {
                    return 4;
                }
                if(thoat.isClicked(mousePos)){
                    return 0 ; 
                }

                        // Kiểm tra nếu một trong các nút môn học trong buttonsubject được nhấn
            for (int i = displayFrom; i < displayLimit && i < static_cast<int>(subjectList.size()); i++) {
                if (buttonsubject[i].isClicked(mousePos)) {
                    cout << subjectList.size()  << endl;  
                    cout << 12 ; 
                    string ma = buttonsubject[i].getText() ;  
                    PTRMH p = AVLTreeMH::getInstance().Search1(AVLTreeMH::getInstance().root,ma) ; 
                    cout << p->mh.MAMH ; 
                    cout << 1 ; 
                     MonHoc selectedMH = {p->mh.MAMH,p->mh.TENMH,p->mh.STCLT,p->mh.STCTH} ; 
                    //  MonHoc selectedMH = Data::displaySubjectInfo(i);
                    InSubject(window, selectedMH); 
                     return 3 ; 
                }
            }
            }
            inputField.processInput(event);
        }

        // Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (subjectList.size() + itemsPerPage - 1) / itemsPerPage;

        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        window.clear(sf::Color::White);

        // Vẽ menu chính  
        BaseScreenMonHoc::drawMainMenu2(window);
        // window.draw(square) ; 

         for (int i = displayFrom; i < displayLimit; i++){
            if (static_cast<int>(subjectList.size()) <= i && static_cast<int>(buttonsubject.size()) <= i)
                break;
            subjectList[i].draw(window);
        buttonsubject[i].draw(window) ; 
         //window.display();
    }

        // Vẽ các nút và thông tin trang
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        window.draw(pageText);
        ma.draw(window);
        ten.draw(window);
        lt.draw(window);
        th.draw(window);  
        inputField.draw(window);
        mh.draw(window) ;   
        tim.draw(window) ;  
        window.display();
    }

    return 0;
}


int ScreenMonHoc::addSubject(sf::RenderWindow& window){
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
     // Tạo các đối tượng Text và InputField
    Text title(371.f, 259.f, 828.f, 61.f, "THONG TIN MON HOC ", font, sf::Color::Red, 20);
    Text ma(206.f, 432.f, 165.f, 34.f, "MA MON HOC ", font, sf::Color::Red, 20);
    Text solt(206.f, 546.f, 165.f, 34.f,"SO TIET LI THUYET", font, sf::Color::Red, 20);
    Text monhoc1(760.f, 418.f, 165.f, 34.f,  "TEN MON HOC ", font, sf::Color::Red, 20);
    Text soth(760.f, 546.f, 165.f, 34.f, "SO TIET THUC HANH ", font, sf::Color::Red, 20);
    Text canhbao(366.f,772.f ,812.f , 69.f , " CHU Y MA MON HOC < 10 KY TU VA TEN MON HOC < 50 || KY TU IN HOA TU A -> Z " , font , sf::Color(255, 182, 193), 15) ;

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    
    InputField Ma(389.f, 432.f, 281.f, 34.f, font);
    InputField MonHoc2(997.f, 432.f, 327.f, 34.f, font);
    InputField SoLt(389.f, 546.f, 281.f, 43.f, font);
    InputField SoTh(1001.f, 546.f, 327.f, 43.f, font);

    
    Ma.setSelected(true);
    MonHoc2.setSelected(true);
    SoLt.setSelected(true);
    SoTh.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        if (Ma.isSelected()) Ma.textCursor(Ma.getInput());
        if (MonHoc2.isSelected()) MonHoc2.textCursor(MonHoc2.getInput());
        if (SoLt.isSelected()) SoLt.textCursor(SoLt.getInput());
        if (SoTh.isSelected()) SoTh.textCursor(SoTh.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();

            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
               
                Ma.handleMouseClick(mousePos);
                MonHoc2.handleMouseClick(mousePos);
                SoLt.handleMouseClick(mousePos);
                SoTh.handleMouseClick(mousePos);

                if(thoat.isClicked(mousePos)){
                    return 3 ; 
                }
                // Kiểm tra nút "SAVE" được nhấn
                if (ghi.isClicked(mousePos)) {
                    std::string mamh = Ma.getInput();
                    std::string tenmh = MonHoc2.getInput();
                    std::string solt = SoLt.getInput();
                    std::string soth = SoTh.getInput();

                      // Kiểm tra độ dài tên môn học
                    if (tenmh.length() > 50) {
                        Data::popup("TEN MON HOC KHONG QUA 50 KI TU ");
                        continue;  // Quay lại nhập lại mà không tiến hành thêm
                    }
                    if(mamh.length() > 10){
                        Data::popup("MA MON HOC KHONG QUA 10 KI TU ");
                        continue;  // Quay lại nhập lại mà không tiến hành thêm
                    }
                    if(AVLTreeMH::getInstance().KTMonHoc(AVLTreeMH::getInstance().root,mamh)){
                        Data::popup("MA MON HOC DA TON TAI ");
                        continue;  // Quay lại nhập lại mà không tiến hành thêm
                    }
                    if (!mamh.empty() && !tenmh.empty() && !solt.empty() && !soth.empty() ) {
                        MonHoc mh ;
                        mh.MAMH = mamh ; 
                        mh.TENMH = tenmh ; 
                        mh.STCLT = std::stoi(solt) ;
                        mh.STCTH = std::stoi(soth) ; 
                        AVLTreeMH::getInstance().Insert(AVLTreeMH::getInstance().root,mh) ;
                        cout << "CAY AVL MONHOC SAU KHI THEM :" ; 
                        AVLTreeMH::getInstance().InOrder(AVLTreeMH::getInstance().root) ;
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        custom::vector<std::string> newRow = {mamh, tenmh, solt, soth}; 
                // Gọi hàm addmonhoc để thêm dòng dữ liệu mới vào CSV
                if (Data::add(subjectPath, font, newRow)) {
                    std::cout << "thanh cong " << std::endl;
                } else {
                    std::cerr << "not load" << std::endl;
                }
                    } 
                    Data::popup("THEM THANH CONG MON HOC ") ; 
                }
            }

            Ma.processInput(event);
            if (Ma.chooseNextField()) {
                MonHoc2.setSelected(true);
            }
            MonHoc2.processInput(event);
            if (MonHoc2.chooseNextField()) {
                SoLt.setSelected(true);
            }
            SoLt.processInput(event);
            if (SoLt.chooseNextField()) {
                SoTh.setSelected(true);
            }
            SoTh.processInput(event);

            // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // // Chuyển đổi trạng thái chọn cho các trường nhập liệu
            // Ma.setSelected(Ma.isSelected() && !ghi.isClicked(mousePos));
            // MonHoc.setSelected(MonHoc.isSelected() && !ghi.isClicked(mousePos));
            // SoLt.setSelected(SoLt.isSelected() && !ghi.isClicked(mousePos));
            // SoTh.setSelected(SoTh.isSelected() && !ghi.isClicked(mousePos));

        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);
         // Vẽ menu chính
        BaseScreenMonHoc::drawMainMenu2(window) ; 
         //Vẽ các yếu tố lớp học
        title.draw(window);
        ma.draw(window);
        monhoc1.draw(window);
        solt.draw(window);
        soth.draw(window);
      

        Ma.draw(window);
        MonHoc2.draw(window);
        SoLt.draw(window);
        SoTh.draw(window);
        canhbao.draw(window) ;
    
        // saveBtn.draw(window);
        window.display();
    }
    }
    return  0 ; 
}
int ScreenMonHoc::InSubject(sf::RenderWindow& window, MonHoc& selectedMH ) {
    cout << "DA DI DEN HAM IN SUBJECT\n " ;
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    // Tạo các đối tượng Text và InputField
    Text title(371.f, 259.f, 828.f, 61.f, "THONG TIN MON HOC", font, sf::Color::Red, 20);
    Text ma(206.f, 432.f, 165.f, 34.f, "MA MON HOC", font, sf::Color::Red, 20);
    Text monhoc(206.f, 546.f, 165.f, 34.f, "TEN MON HOC", font, sf::Color::Red, 20);
    Text solt(760.f, 418.f, 165.f, 34.f, "SO TIET LI THUYET", font, sf::Color::Red, 20);
    Text soth(760.f, 546.f, 165.f, 34.f, "SO TIET THUC HANH", font, sf::Color::Red, 20);

    Button them(264.f, 149.f, 151.f, 28.f, "THEM", font, sf::Color::Red, 15);
    Button xoa(477.f, 149.f, 151.f, 28.f, "XOA", font, sf::Color::Red, 15);
    Button ghi(944.f, 149.f, 151.f, 28.f, "GHI", font, sf::Color::Red, 15);
    Button thoat(1202.f, 149.f, 84.f, 28.f, "THOAT", font, sf::Color::Red, 15);
    Button sua(722.f, 149.f, 151.f, 28.f, "SUA", font, sf::Color::Red, 15);
   
    // Khai báo các Text để hiển thị thông tin môn học
    Text maText(389.f, 432.f, 281.f, 34.f, selectedMH.MAMH ,  font , sf :: Color:: Red , 15);
    Text soltText(997.f, 432.f, 327.f, 34.f,std::to_string(selectedMH.STCLT) , font ,  sf :: Color :: Red , 15 );
    Text monhocText(389.f, 546.f, 281.f, 43.f,selectedMH.TENMH , font , sf :: Color :: Red , 15 );
    Text sothText(1001.f, 546.f, 327.f, 43.f, std::to_string(selectedMH.STCTH) ,  font , sf :: Color :: Red , 15 );
    //std::to_string(selectedMH.STCLT)
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Kiểm tra các nút được nhấn
                if (sua.isClicked(mousePos)) {
                    if(TinhchiList::getInstance().checkMH(TinhchiList::getInstance(),selectedMH.MAMH)){
                        Data::popup("MON HOC DA DUOC DANG KY TINH CHI KHONG THE XOA ") ; 
                    }else{
                    fixSubject(window , selectedMH );
                    return 3 ;
                    } 
                }
                if (thoat.isClicked(mousePos)) {
                    return 3 ;  // Đóng cửa sổ khi nhấn nút "THOAT"
                }

                 if (xoa.isClicked(mousePos)) {
                        if(TinhchiList::getInstance().checkMH(TinhchiList::getInstance(),selectedMH.MAMH)){
                            Data::popup("MON HOC DA DUOC DANG KY TINH CHI KHONG THE XOA ") ; 
                        }else{
                        if(Data::confirm("BAN CO CHAC XOA MON HOC NAY KHONG ")){
                        AVLTreeMH::getInstance().Remove(AVLTreeMH::getInstance().root,selectedMH) ; 
                        cout << "CAY AVL MONHOC SAU KHI XOA :" ;
                        AVLTreeMH::getInstance().InOrder(AVLTreeMH::getInstance().root) ;
                        // xoa trong trong file 
                        Data::deletefile(subjectPath ,selectedMH.MAMH ) ; 
                        Data::popup("DA XOA MON HOC THANH CONG ") ; 
                    return 3 ;  // Đóng cửa sổ khi nhấn nút "THOAT"
                 }
                 }
                 }
        }

        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);

        // Vẽ menu chính
        BaseScreenMonHoc::drawMainMenu2(window);

        // Vẽ các yếu tố lớp học
        title.draw(window);
        ma.draw(window);
        monhoc.draw(window);
        solt.draw(window);
        soth.draw(window);

        // Vẽ thông tin môn học
        maText.draw(window);
        monhocText.draw(window);
        soltText.draw(window);
        sothText.draw(window);

        // Vẽ các nút
        them.draw(window);
        xoa.draw(window);
        thoat.draw(window);
        sua.draw(window);

        window.display();
    }
    }
    return 0;
}
int   ScreenMonHoc::fixSubject(sf::RenderWindow& window , MonHoc& selectedMH) {
    cout << "DA DI DEN HAM FIX SUBJECT\n " ;
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1  ; // Trả về lỗi nếu không tải được font
    }
    // Tạo các đối tượng Text và InputField
    Text title(371.f, 259.f, 828.f, 61.f, "THEM THONG TIN MON HOC   ", font, sf::Color::Red, 20);
    Text ma(206.f, 418.f, 165.f, 34.f, "MA MON HOC ", font, sf::Color::Red, 20);
    Text solt(206.f, 546.f, 165.f, 34.f, " SO TIET LI THUYET", font, sf::Color::Red, 20);
    Text monhoc(760.f, 418.f, 165.f, 34.f, "TEN MON HOC", font, sf::Color::Red, 20);
    Text soth(760.f, 546.f, 165.f, 34.f, "SO TIET THUC HANH ", font, sf::Color::Red, 20);

      //InputField Ma(385.f, 485.f, 281.f, 34.f, font);
    InputField MonHoc(997.f, 432.f, 327.f, 34.f, font);
    InputField SoLt(389.f, 546.f, 281.f, 43.f, font);
    InputField SoTh(1001.f, 546.f, 327.f, 43.f, font);

    // Text maText(389.f, 432.f, 281.f, 34.f, a.MAMH, font, sf::Color::Red, 15);
    // Text monhocText(997.f, 432.f, 327.f, 34.f, a.TENMH, font, sf::Color::Red, 15);
    // Text soltText(389.f, 546.f, 281.f, 43.f, std::to_string(a.STCLT), font, sf::Color::Red, 15);
    // Text sothText(1001.f, 546.f, 327.f, 43.f, std::to_string(a.STCLT), font, sf::Color::Red, 15);

    Text maText(389.f, 432.f, 281.f, 34.f, selectedMH.MAMH, font, sf::Color::Red, 15);
    EditableText monhocText(997.f, 432.f,selectedMH.TENMH , font, &MonHoc);
    EditableText soltText(389.f, 546.f,  std::to_string(selectedMH.STCLT), font, &SoLt );
    EditableText sothText(1001.f, 546.f,std::to_string(selectedMH.STCTH), font, &SoTh ); 

    

    Button them(264.f, 149.f, 151.f, 28.f, "THEM", font, sf::Color::Red, 15);
    Button xoa(477.f, 149.f, 151.f, 28.f, "XOA", font, sf::Color::Red, 15);
    Button ghi(944.f, 149.f, 151.f, 28.f, "GHI", font, sf::Color::Red, 15);
    Button thoat(1202.f, 149.f, 84.f, 28.f, "THOAT", font, sf::Color::Red, 15);
    Button sua(722.f, 149.f, 151.f, 28.f, "SUA", font, sf::Color::Red, 15);
      // Chuyển subject Text thành MonHoc
    // fsys::path subjectPath = "D:\\du an\\SFML\\SFML\\subjects.csv";
    // Khai báo các Text để hiển thị thông tin môn học

  

   
    // Set selected fields for input
    //Ma.setSelected(true);
    // MonHoc.setSelected(true);
    // SoLt.setSelected(true);
    // SoTh.setSelected(true);

    while (window.isOpen()) {
        sf::Event event;
        //if (Ma.isSelected()) Ma.textCursor(Ma.getInput());
        if (MonHoc.isSelected()) MonHoc.textCursor(MonHoc.getInput());
        if (SoLt.isSelected()) SoLt.textCursor(SoLt.getInput());
        if (SoTh.isSelected()) SoTh.textCursor(SoTh.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }  
              // Cập nhật sự kiện cho EditableText
            monhocText.update(event);
            soltText.update(event);
            sothText.update(event);
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                //Ma.handleMouseClick(mousePos);
                // MonHoc.handleMouseClick(mousePos);
                // Cập nhật sự kiện cho EditableText
                monhocText.handleMouseClick(sf::Mouse::getPosition(window));
                soltText.handleMouseClick(sf::Mouse::getPosition(window));
                sothText.handleMouseClick(sf::Mouse::getPosition(window));

                // Kiểm tra nút "GHI" được nhấn
                if (ghi.isClicked(mousePos)) {
                    //std::string mamh = Ma.getInput();
                    // std::string mamh = monhocText.getText();
                    cout << 1 << endl; 
                    // cout << mamh ; 
                    cout << 2 ; 
                    std::string tenmh = monhocText.getText();
                    std::string solt = soltText.getText();
                    std::string soth = sothText.getText();
                  
                    // // Kiểm tra dữ liệu nhập vào bằng cách in ra console
                    //     std::cout << "Ten mon hoc: " << tenmh << std::endl;
                    //     std::cout << "So tiet li thuyet (solt): " << solt << std::endl;
                    //     std::cout << "So tiet thuc hanh (soth): " << soth << std::endl;
                    // Kiểm tra thay đổi ở các trường
                    if ( tenmh != selectedMH.TENMH || solt != std::to_string(selectedMH.STCLT) || soth != std::to_string(selectedMH.STCLT)) {
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        cout << tenmh  << endl ;
                        cout << solt << endl ; 
                        cout << soth << endl ; 
                        custom::vector<std::string> newRow = {selectedMH.MAMH, tenmh, solt, soth};
                        Data::update(subjectPath, selectedMH.MAMH, newRow);
                        selectedMH = {selectedMH.MAMH, tenmh, std::stoi(solt), std::stoi(soth)};
                        AVLTreeMH::getInstance().Search(AVLTreeMH::getInstance().root, selectedMH);
                        AVLTreeMH::getInstance().InOrder(AVLTreeMH::getInstance().root); 
                    }
                     Data::popup("DA THAY DOI THANH CONG ") ; 
                }
                if(thoat.isClicked(mousePos)){
                    return 3  ;
                }
            }

             // Cập nhật giao diện
            MonHoc.updateCursor();
            // Xử lý sự kiện các trường nhập liệu
            //Ma.processInput(event);
            //if (Ma.chooseNextField()) {
                //MonHoc.setSelected(true);
            //}
            // MonHoc.processInput(event);
            // if (MonHoc.chooseNextField()) {
            //     SoLt.setSelected(true);
            // }
            // SoLt.processInput(event);
            // if (SoLt.chooseNextField()) {
            //     SoTh.setSelected(true);
            // }
            // SoTh.processInput(event);
        }

        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);
        BaseScreenMonHoc::drawMainMenu2(window);
        title.draw(window);
        ma.draw(window);
        monhoc.draw(window);
        solt.draw(window);
        soth.draw(window);

        maText.draw(window) ; 
        monhocText.draw(window) ; 
        soltText.draw(window) ; 
        sothText.draw(window) ; 

        //Ma.draw(window);
        // MonHoc.draw(window);
        // SoLt.draw(window);
        // SoTh.draw(window);

        window.display();
    }
    return 0  ;
}