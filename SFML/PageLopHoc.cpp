
// BaseScreenLopHoc.cpp
#include "PageLopHoc.h"
#include"FileNFoder.h" 
#include"DataUtils.h"

fsys::path classPath = "D:\\du an\\SFML\\SFML\\data\\Courses\\course.csv";
fsys::path student1 = "D:\\du an\\SFML\\SFML\\data\\Classes\\23CTT1.csv";
fsys::path classDir = "D:\\du an\\SFML\\SFML\\data\\Classes";

int BaseScreenLopHoc::showBaseLop(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Handle error if font cannot be loaded
    }
    
    Text lop(0.f, 181.f, 206.f , 35.f ,  "Lop" , font , sf :: Color :: Red ,25) ;
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
        lop.draw(window);
        window.display();  // Cập nhật màn hình
    return 0;  // Return value when completed
} 
void BaseScreenLopHoc::drawMainMenu1(sf::RenderWindow& window) {
    // Khởi tạo font
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return; // Xử lý lỗi nếu không thể tải font
    }

    // Tạo các yếu tố giao diện
    Text lop(0.f, 181.f, 206.f , 35.f ,"Lop", font , sf :: Color :: Red ,25) ;

    // Vẽ các thành phần lên cửa sổ
    window.clear(sf::Color::White);
        BaseScreen::drawMainMenu(window);
        lop.draw(window);

}
int ScreenLopHoc::showClass(sf::RenderWindow& window) {
    cout << "DA VAO HAM SHOW CLASS\n" ;
    DS_LOPSV& listclass =  DS_LOPSV::getInstance() ;
    cout << "Called success" ; 
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
     // Xóa dữ liệu cũ trong các vector trước khi thêm dữ liệu mới
    classList.clear();
    Buttonclass.clear();
    // Khởi tạo các nút điều hướng
    Button nextPageBtn(901.f, 833.f, 92.f, 62.f, "Next", font, sf::Color(218, 110, 50), 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 62.f, "Prev", font, sf::Color(218, 110, 50), 15);

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color(255, 182, 193), 15 ) ; 
    // Khởi tạo các nhãn
    Text ma(217.f , 281.f , 539.f , 46.f , "MA LOP " , font , sf :: Color :: Red , 15) ; 
    Text lop(756.f , 281.f , 539.f , 46.f , "TEN LOP " , font , sf :: Color :: Red , 15) ; 

    InputField inputField(264.f, 205.f, 151.f, 43.f, font);
    Text malop(60.f , 205.f , 151.f, 43.f, "MA LOP : "  ,font, sf::Color(255, 182, 193), 15 )  ;
    Button tim(477.f , 205.f ,151.f, 43.f, "TIM "  , font, sf::Color(255, 182, 193), 15) ;

    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f);
    Data::displaylop(font ,listclass) ;// luu co the truyen vao dslop 
    cout << "SO LUONG BUTTON VA TEXT HIEN TAI " << classList.size() << " " << Buttonclass.size() << endl ;
    int  displayFrom = 0;  // Chuyển đổi thành size_t
    int  itemsPerPage = 10; // Chuyển đổi thành size_t
    inputField.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        // int displayLimit = std::min(displayFrom + itemsPerPage, static_cast<int>(classList.size()));
         long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(classList.size()) ? static_cast<int>(classList.size()) : (displayFrom + itemsPerPage);
         if (inputField.isSelected()) inputField.textCursor(inputField.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                inputField.handleMouseClick(mousePos);
                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(classList.size())) {
                        // displayFrom + itemsPerPage < static_cast<int>(classList.size())
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }
                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
                if (them.isClicked(mousePos)) {
                    addClass(window) ; 
                    return 2 ; 
                }
                if(thoat.isClicked(mousePos)){ 
                    return 0 ; 
                }
                if(tim.isClicked(mousePos)){
                    string ma = inputField.getInput() ; 
                    int vitri ; 
                    int temp = listclass.KTMaLop(listclass,ma,listclass.n);
                    if(temp == 0){
                        Data::popup("MA LOP KHONG TON TAI") ;
                        break ; 
                    }else{
                        if(temp == -1)
                        {
                            vitri = 0;	
                        }else{
                            vitri = temp;
                        }
                    cout <<  "DA NHAN DUOC VI TRI " << vitri << endl ; 
                    LopSV& selectedLop = listclass.nodes[vitri] ;  
                    InClass(window,selectedLop,listclass); 
                    cout << "DA XONG HAM IN CLASS " ; 
                    return 2; 
                    } 
                }
                // Kiểm tra nếu một trong các nút môn học trong buttonsubject được nhấn
                for (int i = displayFrom; i < displayLimit && i < static_cast<int>(Buttonclass.size()); i++) {
                    // int i = displayFrom; i < displayLimit && i < Buttonclass.size(); i++
                        if (Buttonclass[i].isClicked(mousePos)) {
                            string ma = Buttonclass[i].getText() ; 
                            int vitri ; 
                            int temp = listclass.KTMaLop(listclass,ma,listclass.n);
                                if(temp != 0){
                                    if(temp == -1)
                                 {
                                    vitri = 0;	
                                }else{
                                     vitri = temp;
                                }
                                } 
                                cout <<  "DA NHAN DUOC VI TRI " << vitri << endl ; 
                            LopSV& selectedLop = listclass.nodes[vitri] ;  
                            InClass(window,selectedLop,listclass); 
                            cout << "DA XONG HAM IN CLASS " ; 
                            return 2; 
                        }
                        }
            }
             inputField.processInput(event);
        }
        //Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (classList.size() + itemsPerPage - 1) / itemsPerPage;
        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        window.clear(sf::Color::White);
        // Vẽ menu chính  
        BaseScreenLopHoc::drawMainMenu1(window);
         for (int i = displayFrom; i < displayLimit; i++){
            if (static_cast<int>(classList.size()) <= i && static_cast<int>(Buttonclass.size()) <= i)
                break;
            classList[i].draw(window);
            Buttonclass[i].draw(window) ; 
    }
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        window.draw(pageText);
        ma.draw(window); 
        lop.draw(window) ;
        inputField.draw(window);
        tim.draw(window) ;
        malop.draw(window) ;
        window.display();
    }
    return 0;
}

int ScreenLopHoc::InClass(sf::RenderWindow& window , LopSV& selectedLop , DS_LOPSV& listclass ){
   cout << "DA VAO HAM IN CLASS " ; 
   cout << "DANH SACH LOP TRUOC KHI IN\n "<< endl ;
    listclass.HienThiDanhSachLop() ; 
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
      // Các thành phần giao diện
    Text title(541.f, 225.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
    Text malop(371.f, 315.f, 158.f, 47.f, "MA LOP", font, sf::Color::Red, 12);
    Text tenlop(371.f, 384.f, 158.f, 47.f, "TEN LOP", font, sf::Color::Red, 12);
    
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    Text Malop(541.f, 315.f, 618.f, 47.f,selectedLop.MALOP , font , sf :: Color :: Red , 15);
    Text Tenlop(541.f, 384.f, 618.f, 47.f,selectedLop.TENLOP ,  font , sf :: Color :: Red , 15);
    fsys::path studentFile = classDir / (selectedLop.TENLOP + ".csv"); 
     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // Kiểm tra các nút được nhấn
                if (sua.isClicked(mousePos)) {
                    if(listclass.KiemTraLopCoSinhVien(listclass,selectedLop.MALOP)){
                        Data::popup("   LOP NAY DA CO SINH VIEN KHONG DUOC THAO TAC ") ;
                    }else{
                    fixClass(window,selectedLop);
                    return 1 ; 
                }
                }
                if (thoat.isClicked(mousePos)) {
                    std::cout << "Thoat button is clicked \n";
                   return 1 ; 
                }
                 if (xoa.isClicked(mousePos)) {
                        if(listclass.KiemTraLopCoSinhVien(listclass,selectedLop.MALOP)){
                            cout << "    LOP NAY DA CO SINH VIEN KHONG DUOC THAO TAC " << endl ;
                            Data::popup("LOP NAY DA CO SINH VIEN KHONG DUOC THAO TAC ") ;
                        }else{
                        if(Data::confirm("BAN CO CHAC CHAN XOA LOP NAY KHONG ")){
                           listclass.XoaLop(listclass,selectedLop.MALOP) ; 
                             // xoa trong trong file 
                            Data::deletefile(classPath ,selectedLop.MALOP ) ; 
                            // Thực hiện xóa file CSV
                            if (fsys::exists(studentFile)) { // Kiểm tra file có tồn tại không
                                fsys::remove(studentFile);   // Xóa file
                                std::cout << "Tệp CSV đã được xóa: " << studentFile << std::endl;
                            }
                            cout << "DANH SACH LOP SAU KHI XOA\n "<< endl ;
                            listclass.HienThiDanhSachLop() ;
                            Data::popup("DA XOA LOP THANH CONG ") ; 
                        }
                 }
                 }
        }
        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);
        // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window);
        // Vẽ các yếu tố lớp học
        title.draw(window);
        malop.draw(window);
        tenlop.draw(window);
        Malop.draw(window);
        Tenlop.draw(window);
        them.draw(window);
        xoa.draw(window);
        thoat.draw(window);
        sua.draw(window); 
        window.display();
    }
    }
    return 0;
}
int ScreenLopHoc::addClass(sf::RenderWindow& window) {
    cout << "DA VAO HAM ADD CLASS " ; 
    cout << "DANH SACH LOP TRUOC KHI THEM\n "<< endl ;
    DS_LOPSV::getInstance().HienThiDanhSachLop() ;
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
    // Các thành phần giao diện

    Text title(541.f, 225.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
    Text malop(371.f, 315.f, 158.f, 47.f, "MA LOP", font, sf::Color::Red, 12);
    Text canhbao(366.f,772.f ,812.f , 69.f , " CHU Y MA LOP KHONG QUA 15 KY TU || KY TU IN HOA TU A -> Z " , font , sf::Color(255, 182, 193), 15) ;
    Text tenlop(371.f, 384.f, 158.f, 47.f, "TEN LOP", font, sf::Color::Red, 12);
    InputField Malop(541.f, 315.f, 618.f, 47.f, font);
    InputField Tenlop(541.f, 384.f, 618.f, 47.f, font);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    Malop.setSelected(true); 
    while (window.isOpen()) {
        sf::Event event;
        if (Malop.isSelected()) Malop.textCursor(Malop.getInput());
        if (Tenlop.isSelected()) Tenlop.textCursor(Tenlop.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Đóng cửa sổ
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                Malop.handleMouseClick(mousePos);
                Tenlop.handleMouseClick(mousePos);
                if(thoat.isClicked(mousePos)){
                    return 2 ; 
                }
                // Kiểm tra nếu nhấn nút SAVE
                if (ghi.isClicked(mousePos)) {
                    std::string malopInput = Malop.getInput();
                    std::string tenlopInput = Tenlop.getInput();
                    // Kiểm tra độ dài tên môn học
                    if (malopInput.length() > 15) {
                        Data::popup(" Ma lop không được quá 15 ký tự!");
                        continue;  // Quay lại nhập lại mà không tiến hành thêm
                    }
                    if(DS_LOPSV::getInstance().KTMaLopVaTenLop(DS_LOPSV::getInstance(),malopInput,tenlopInput)){
                        Data::popup("MA LOP VA TEN LOP NAY DA TON TAI ") ; 
                        continue ; 
                    }
                     if (!malopInput.empty() && !tenlopInput.empty() ) {
                        DS_LOPSV::getInstance().ThemLop(DS_LOPSV::getInstance(),LopSV(malopInput, tenlopInput)); 
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        custom::vector<std::string> newRow = {malopInput, tenlopInput}; 
                    if (Data::add(classPath, font, newRow)) {
                        std::cout << "thanh cong " << std::endl;
                    } else {
                        std::cerr << "not load" << std::endl;
                     }
                fsys::path studentFile = classDir / (tenlopInput + ".csv");  // Tên file là MALOP.csv
                csvFile SVFile(studentFile); // Tạo đối tượng csvFile
                if (SVFile.isCreate()) {
                    std::cout << "Tệp CSV lớp đã được tạo: " << studentFile << std::endl;
                    // Khởi tạo tiêu đề cột (ví dụ: MASV, HO, TEN, PHAI, SODT)
                    custom::vector<std::string> row = {"MASV", "HO", "TEN", "PHAI", "SODT"};
                    // SVFile.cnt.push_back({"MASV", "HO", "TEN", "PHAI", "SODT"});
                    SVFile.cnt.push_back(row);
                    SVFile.writeFile();
                } else {
                    std::cout << "Tệp CSV lớp đã tồn tại: " << studentFile << std::endl;
                }
                    cout << "DANH SACH LOP SAU KHI THEM\n "<< endl ;
                    DS_LOPSV::getInstance().HienThiDanhSachLop() ; 
                    Data::popup("THEM THANH CONG ") ; 
                    }
                }
            }
            // Xử lý nhập liệu cho các input field
            Malop.processInput(event);
            if (Malop.chooseNextField()) {
                Tenlop.setSelected(true);
            }
            Tenlop.processInput(event);
            if (Tenlop.chooseNextField()) {
            }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        Malop.setSelected(Malop.isSelected() && !ghi.isClicked(mousePos));
        Tenlop.setSelected(Tenlop.isSelected() && !ghi.isClicked(mousePos));
        window.clear(sf::Color::White);
        // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window) ; 
        title.draw(window);
        malop.draw(window);
        tenlop.draw(window);
        Malop.draw(window);
        Tenlop.draw(window);
        canhbao.draw(window) ;
        window.display();
    }
    }
        return 0 ; 
    }
int  ScreenLopHoc::fixClass(sf :: RenderWindow& window, LopSV& selectedlophoc){
    cout << "DA VAO HAM FIX CLASS " ; 
    cout << "DANH SACH LOP TRUOC KHI FIX\n "<< endl ;
    DS_LOPSV::getInstance().HienThiDanhSachLop() ; 
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1 ; // Trả về lỗi nếu không tải được font
    }
      // Các thành phần giao diện
    Text title(541.f, 225.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
    Text malop(371.f, 315.f, 158.f, 47.f, "MA LOP", font, sf::Color::Red, 12);
    Text tenlop(371.f, 584.f, 158.f, 47.f, "TEN LOP", font, sf::Color::Red, 12); 
    InputField lop(700.f, 584.f, 618.f , 47.f  , font ) ; 
    Text Malop(541.f, 315.f, 618.f, 47.f, selectedlophoc.MALOP,  font , sf :: Color :: Red , 15);
    EditableText Tenlop(800.f, 584.f, selectedlophoc.TENLOP ,  font  , &lop);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 

    // ma.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        // if (ma.isSelected()) ma.textCursor(ma.getInput());
        if (lop.isSelected()) lop.textCursor(lop.getInput());

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Đóng cửa sổ
            }
            Tenlop.update(event) ; 
             if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // ma.handleMouseClick(mousePos);
                Tenlop.handleMouseClick(mousePos);
                if(thoat.isClicked(mousePos)){
                    return  3 ; 
                }
                // Kiểm tra nếu nhấn nút SAVE
                if (ghi.isClicked(mousePos)) {
                    std::string tenlopInput = Tenlop.getText();
                     // Kiểm tra dữ liệu nhập vào bằng cách in ra console
                       
                        std::cout << "ten lop : " << tenlopInput << std::endl;
                    
                    // Kiểm tra thay đổi ở các trường
                    if (tenlopInput != selectedlophoc.TENLOP ) {
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        custom::vector<std::string> newRow = {selectedlophoc.MALOP,tenlopInput};
                        Data::update(classPath,selectedlophoc.MALOP , newRow);
                         LopSV selectedLop = {selectedlophoc.MALOP, tenlopInput };
                        DS_LOPSV::getInstance().SuaLop(selectedLop.MALOP , selectedLop ) ; 
                        cout << "DANH SACH LOP SAU KHI FIX\n "<< endl ;
                        DS_LOPSV::getInstance().HienThiDanhSachLop() ;
                        Data::popup("HIEU CHINH THANH CONG ") ;
                    }
                }
            }
            lop.updateCursor() ; 
            // lop.processInput(event);
            // if (lop.chooseNextField()) {
            // }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // ma.setSelected(ma.isSelected() && !ghi.isClicked(mousePos));
        lop.setSelected(lop.isSelected() && !ghi.isClicked(mousePos));
        window.clear(sf::Color::White);
         // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window) ; 
        // Vẽ các yếu tố lớp học
        title.draw(window);
        malop.draw(window);
        tenlop.draw(window);
        Malop.draw(window);
        Tenlop.draw(window);
        window.display();
    }
    }
    return 0 ;
 } 
int ScreenLopHoc::choiseclass(sf::RenderWindow& window ){
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
    InputField inputField(333.f, 201.f, 158.f, 62.f, font);
    Text lop(138.f , 208.f , 158.f, 62.f, "LOP : "  ,font, sf::Color(255, 182, 193), 15 )  ;
    Button tim(507.f , 224.f ,158.f, 62.f, "TIM "  , font, sf::Color(255, 182, 193), 15) ;
    // Khởi tạo các nút điều hướng
    Button nextPageBtn(901.f, 833.f, 92.f, 62.f, "Next", font, sf::Color::Red, 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 62.f, "Prev", font, sf::Color::Red, 15);

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color(255, 182, 193), 15 ) ; 

    // Khởi tạo các nhãn
    // Text ma(217.f , 281.f , 539.f , 46.f , "MA LOP " , font , sf :: Color :: Red , 15) ; 
    // Text lop(756.f , 281.f , 539.f , 46.f , "TEN LOP " , font , sf :: Color :: Red , 15) ; 
    // Xóa dữ liệu cũ trong các vector trước khi thêm dữ liệu mới
    classList.clear();
    Buttonclass.clear();
    //Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f);
    Data::displaylop(font , DS_LOPSV::getInstance()) ;// luu co the truyen vao dslop
    
    int displayFrom = 0;
    int itemsPerPage = 10;
    inputField.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        // int displayLimit = std::min(displayFrom + itemsPerPage, static_cast<int>(classList.size()));
        long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(classList.size()) ? static_cast<int>(classList.size()) : (displayFrom + itemsPerPage);
        if (inputField.isSelected()) inputField.textCursor(inputField.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                inputField.handleMouseClick(mousePos);
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
                if(tim.isClicked(mousePos)){
                    string ma = inputField.getInput() ; 
                     int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),ma,DS_LOPSV::getInstance().n);
                        cout << temp ; 
                        cout << "KIEM TRA VI TRI \n " ; 
                        if(temp == 0 ){
                            Data::popup("MA LOP KHONG TON TAI VUI LONG NHAP LAI ") ; 
                        }else{
                             showStudent(window,ma) ; 
                             return 0 ; 
                        }
                    // showStudent(window,ma) ; 
                    // return 1 ; 
                    return 1 ; 
                }
                if(thoat.isClicked(mousePos)){
                    return 0 ; 
                }
                //Kiểm tra nếu một trong các nút môn học trong buttonsubject được nhấn
                for (int i = displayFrom; i < displayLimit && i < static_cast<int>(Buttonclass.size()); i++) {
                        if (Buttonclass[i].isClicked(mousePos)) {
                            cout << "da nhan duoc nut " ;  
                            string ma = Buttonclass[i].getText() ; 
                            showStudent(window , ma) ;  
                            // Dừng vòng lặp sau khi tìm thấy môn học được nhấn
                            cout << "KET THUC SHOW STUDENT " ; 
                        return 1 ; 
                        }
                        }
            }

        //Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (classList.size() + itemsPerPage - 1) / itemsPerPage;

        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        inputField.processInput(event);
            }       
        window.clear(sf::Color::White);
        // Vẽ menu chính  
        BaseScreenLopHoc::drawMainMenu1(window);
         for (int i = displayFrom; i < displayLimit; i++){
            if (static_cast<int>(classList.size()) <= i && static_cast<int>(Buttonclass.size()) <= i)
                break;
            classList[i].draw(window);
            Buttonclass[i].draw(window) ; 
    }
        //Vẽ các nút và thông tin trang
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        window.draw(pageText);
        // ma.draw(window);
        tim.draw(window) ; 
        lop.draw(window) ;
        inputField.draw(window) ; 
        window.display();
    }
    return 0;
} 

int ScreenLopHoc::showStudent(sf::RenderWindow& window , string ma ){
    cout << "DI DEN HAM SHOW STUDENT\n " ;
    StudentList.clear() ;
    ButtonStudent.clear() ; 
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    } 
    Text lop1(120.f , 235.f ,158.f , 62.f , "LOP  : " , font , sf :: Color :: Red , 15 ) ;
    // InputField inputField(330.f, 210.f, 158.f, 62.f, font);
    // Tạo dropdown với các mục
    // std::vector<std::string> items = {"Item 1", "Item 2", "Item 3"};
    // Dropdown dropdown(537.f, 201.f, 200.f, 40.f, font, items, &inputField);
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ;
    int vitri = 0  ; 
    int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),ma,DS_LOPSV::getInstance().n);
        if(temp != 0){
            if(temp == -1)
                {
                vitri = 0;	
            }else{
                vitri = temp;
                }
            } 
    cout << "DANH SACH LOP HIEN TAI " ; 
    DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance(),DS_LOPSV::getInstance().nodes[vitri].MALOP) ;
    cout << endl; 
    // Tạo đối tượng Text để hiển thị thông tin lớp
    Text lop(362.f, 235.f, 158.f, 62.f, DS_LOPSV::getInstance().nodes[vitri].TENLOP , font, sf::Color::Red, 15);
    Button nextPageBtn(901.f, 833.f, 92.f, 62.f, "Next", font, sf :: Color :: Red , 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 62.f, "Prev", font, sf :: Color :: Red , 15 );
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 

    InputField inputField(264.f, 205.f, 151.f, 43.f, font);
    Text masv(60.f , 205.f , 1510011.f, 43.f, "MA SV : "  ,font, sf::Color(255, 182, 193), 15 )  ;
    Button tim(477.f , 205.f ,151.f, 43.f, "TIM "  , font, sf::Color(255, 182, 193), 15) ;

    fsys::path studentFile = classDir / (DS_LOPSV::getInstance().nodes[vitri].TENLOP + ".csv"); 
    cout << "file fath cua lop la" << studentFile ; 
    cout << endl; 
    Data::displaystudent(vitri, font);  
     // Khởi tạo các nhãn
    Text Ma(8.f, 355.f, 272.f, 61.f, "MA SINH VIEN ", font, sf::Color::Red, 15);
    Text ho(273.f, 355.f, 272.f, 61.f, "HO", font, sf::Color::Red, 15);
    Text ten(543.f, 355.f, 272.f, 61.f, "TEN", font, sf::Color::Red, 15);
    Text phai(820.f, 355.f, 272.f, 61.f, "PHAI", font, sf::Color::Red, 15);
    Text sdt(1089.f, 355.f, 272.f, 61.f, "SDT", font, sf::Color::Red, 15);
   
    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f); // Vị trí giữa nút Next và Prev
    cout << "SO LUONG NUT BUTTON VA TEXT HIEN TAI : " << ButtonStudent.size() << StudentList.size() <<  endl ;
    int displayFrom = 0;
    int itemsPerPage = 20;
    
    while (window.isOpen()) {
        sf::Event event;
        // if (inputField.isSelected()) inputField.textCursor(inputField.getInput());
        // size_t displayLimit = std::min(displayFrom + itemsPerPage, StudentList.size());
        long long displayLimit = (displayFrom + itemsPerPage) > static_cast<int>(StudentList.size()) ? static_cast<int>(StudentList.size()) : (displayFrom + itemsPerPage);
        if (inputField.isSelected()) inputField.textCursor(inputField.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // dropdown.handleClick(sf::Mouse::getPosition(window)); // Xử lý nhấp chuột
                inputField.handleMouseClick(mousePos);
                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(StudentList.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }

                if (them.isClicked(mousePos)) {
                    addStudent(window ,vitri ); 
                    return 0 ; 
                }
                if(thoat.isClicked(mousePos)){
                    return 1  ; 
                }
                if(tim.isClicked(mousePos)){
                    string ma = inputField.getInput() ; 
                    cout << "MA SINH VIEN NHAP VAO LA : " << ma << endl ; 
                    if(DS_LOPSV::getInstance().nodes[vitri].FIRST.KTSV(DS_LOPSV::getInstance().nodes[vitri].FIRST,ma)){
                        SinhVien selectedsv = DS_LOPSV::getInstance().nodes[vitri].FIRST.findStudentByMASV(ma) ;
                        InStudent(window,selectedsv ,vitri);  // Hiển thị thông tin môn học tương ứng
                        cout << "KET THUC HAM IN STUDENT" ;
                        return 1 ; 
                    }else{
                        Data::popup("MA SINH VIEN KHONG TON TAI ") ; 
                        break ; 
                    }
                }
                for (int i = displayFrom; i < displayLimit && i < static_cast<int>(ButtonStudent.size()); i++) {
                        if (ButtonStudent[i].isClicked(mousePos)) {
                            string ma = ButtonStudent[i].getText() ;
                            cout << ma ; 
                            cout << "DA NHAN DC MA SINH VIEN " ;
                             SinhVien selectedsv = DS_LOPSV::getInstance().nodes[vitri].FIRST.findStudentByMASV(ma) ;
                            InStudent(window,selectedsv ,vitri);  // Hiển thị thông tin môn học tương ứng
                            cout << "KET THUC HAM IN STUDENT" ;
                            return 1 ;  
                            //  break ; 
                        }
                        }
            }
        // Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (StudentList.size() + itemsPerPage - 1) / itemsPerPage;
        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        inputField.processInput(event);
        }
       window.clear(sf::Color::White);
        // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window) ; 
            // Hiển thị các sinh viên trong trang hiện tại
            for (int i = displayFrom; i < displayLimit; i++) {
                 if (static_cast<int>(StudentList.size()) <= i && static_cast<int>(ButtonStudent.size()) <= i)
                break;
                    StudentList[i].draw(window);
                ButtonStudent[i].draw(window) ; 

            }
            // Hiển thị các nút và thông tin trang
            nextPageBtn.draw(window);
            prevPageBtn.draw(window);
            window.draw(pageText);
            Ma.draw(window) ; 
            ho.draw(window); 
            ten.draw(window) ; 
            phai.draw(window) ; 
            sdt.draw(window) ; 
            lop.draw(window) ; 
            lop1.draw(window) ;
            inputField.draw(window);
            tim.draw(window) ;
            masv.draw(window) ;

            // dropdown.draw(window); // Vẽ danh sách thả xuống
            window.display(); // Hiển thị toàn bộ nội dung vừa vẽ lên cửa sổ
                }
    return 0;
 } 
    int ScreenLopHoc::InStudent(sf::RenderWindow& window , SinhVien& selectedsv , int& vitri){
    cout << "DA VAO HAM IN STUDENT\n " ; 
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
      // Các thành phần giao diện
    Text title(366.f, 216.f, 485.f, 122.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 20);
    Text ma(132.f, 390.f, 158.f, 58.f, "MA LOP", font, sf::Color::Red, 20);
    Text ten(132.f, 515.f, 158.f, 58.f, "TEN", font, sf::Color::Red, 20);
    Text ho(694.f, 390.f, 158.f, 58.f, "HO", font, sf::Color::Red, 20);
    Text phai(694.f, 491.f, 158.f, 58.f, "PHAI", font, sf::Color::Red, 20);
    Text sdt(356.f, 619.f, 158.f, 58.f, "SDT", font, sf::Color::Red, 20);

    Text Ma(356.f, 390.f, 286.f, 58.f,selectedsv.MASV, font ,  sf :: Color :: Red , 15);
    Text Ten(356.f, 506.f, 286.f, 58.f, selectedsv.HO ,  font , sf :: Color :: Red , 15)  ;
    Text Ho(964.f, 399.f, 325.f, 58.f,  selectedsv.TEN , font , sf :: Color :: Red , 15);
    Text Phai(964.f, 491.f, 120.f, 58.f, selectedsv.PHAI ,  font , sf :: Color :: Red , 15);
    Text SDT(694.f, 610.f, 411.f, 58.f, selectedsv.SODT ,  font , sf :: Color:: Red , 15 );

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    fsys::path studentFile = classDir / (DS_LOPSV::getInstance().nodes[vitri].TENLOP + ".csv");
    cout<< "file path cua sinh vien la " << studentFile << endl ;
     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Kiểm tra các nút được nhấn
                if (sua.isClicked(mousePos)) {
                     if(TinhchiList::getInstance().Ktsvdk(TinhchiList::getInstance() , selectedsv.MASV) == 1){
                        Data::popup("      SINH VIEN DA THAM GIA DANG KY  KHONG THE XOA ") ;
                    }else{
                    fixStudent(window , selectedsv , vitri ) ;
                    return 5 ; 
                    }
                }
                if (thoat.isClicked(mousePos)) {
                   return 5 ; 
                }

                 if (xoa.isClicked(mousePos)) {
                    if(TinhchiList::getInstance().Ktsvdk(TinhchiList::getInstance() , selectedsv.MASV) == 1){
                        Data::popup("       SINH VIEN DA THAM GIA DANG KY  KHONG THE XOA ") ; 
                    }else if(Data::confirm("BAN CO CHAC CHAN XOA SINH VIEN NAY KHONG ")){
                        DS_LOPSV::getInstance().deleteSV(DS_LOPSV::getInstance(), DS_LOPSV::getInstance().nodes[vitri].MALOP , selectedsv.MASV ) ; 
                        Data::deletefile(studentFile ,selectedsv.MASV ) ; 
                        cout << "DANH SACH SINH VIEN SAU KHI XOA  " << endl ;
                        // DS_LOPSV::getInstance().nodes[vitri].FIRST.In3() ;
                        DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance(),DS_LOPSV::getInstance().nodes[vitri].MALOP) ;
                        Data::popup("DA XOA THANH CONG ") ;
                        return 5  ;
                        // ham dung dc 
                 }
        }
        }
        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);

        // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window);

        // Vẽ các yếu tố lớp học
        title.draw(window);
        Ma.draw(window);
        Ten.draw(window);
        Ho.draw(window);
        Phai.draw(window);
        SDT.draw(window);
        ma.draw(window);
        ho.draw(window);
        ten.draw(window);
        phai.draw(window);
        sdt.draw(window);

        // Vẽ các nút
        them.draw(window);
        xoa.draw(window);
        thoat.draw(window);
        sua.draw(window);

        window.display();
    }
    }
    return 0 ; 
}
    int ScreenLopHoc::addStudent(sf::RenderWindow& window , int& vitri ) {
    cout << "DI DEN HAM ADD STUDENT" ;  
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
     // Tạo các đối tượng Text và InputField
    Text canhbao(366.f,772.f ,812.f , 69.f , " CHU Y MA SINH VIEN KHONG QUA 15 KY TU || KY TU IN HOA TU A -> Z " , font , sf::Color(255, 182, 193), 15) ;
    Text title(366.f, 216.f, 485.f, 122.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 20);
    Text ma(132.f, 390.f, 158.f, 58.f, "MA SINH VIEN ", font, sf::Color::Red, 20);
    Text ten(132.f, 515.f, 158.f, 58.f, "TEN", font, sf::Color::Red, 20);
    Text ho(694.f, 390.f, 158.f, 58.f, "HO", font, sf::Color::Red, 20);
    Text phai(694.f, 491.f, 158.f, 58.f, "PHAI", font, sf::Color::Red, 20);
    Text sdt(356.f, 619.f, 158.f, 58.f, "SDT", font, sf::Color::Red, 20);

    InputField Ma(356.f, 390.f, 286.f, 58.f, font);
    InputField Ten(356.f, 506.f, 286.f, 58.f, font);
    InputField Ho(964.f, 399.f, 325.f, 58.f, font);
    InputField Phai(964.f, 491.f, 120.f, 58.f, font);
    InputField SDT(694.f, 610.f, 411.f, 58.f, font);
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    // Button saveBtn(1094.f, 763.f, 134.f, 78.f, "SAVE", font, sf::Color::Red, 15);
    fsys::path studentFile = classDir / (DS_LOPSV::getInstance().nodes[vitri].TENLOP + ".csv");
    cout << "file fath cua lop la" << studentFile << endl  ; 
    Ma.setSelected(true);
    Ten.setSelected(true);
    Ho.setSelected(true);
    Phai.setSelected(true);
    SDT.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        if (Ma.isSelected()) Ma.textCursor(Ma.getInput());
        if (Ten.isSelected()) Ten.textCursor(Ten.getInput());
        if (Ho.isSelected()) Ho.textCursor(Ho.getInput());
        if (Phai.isSelected()) Phai.textCursor(Phai.getInput());
        if (SDT.isSelected()) SDT.textCursor(SDT.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();

            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                Ma.handleMouseClick(mousePos);
                Ten.handleMouseClick(mousePos);
                Ho.handleMouseClick(mousePos);
                Phai.handleMouseClick(mousePos);
                SDT.handleMouseClick(mousePos);

                // Kiểm tra nút "SAVE" được nhấn
                if (ghi.isClicked(mousePos)) {
                    std::string masv = Ma.getInput();
                    std::string tenSV = Ten.getInput();
                    std::string hoSV = Ho.getInput();
                    std::string phaiSV = Phai.getInput();
                    std::string sdtSV = SDT.getInput();
                    if(masv.length() > 15){
                        Data::popup("MA SINH VIEN KHONG DUOC QUA 15 KY TU ") ;
                        continue;
                    }
                    if(DS_LOPSV::getInstance().nodes[vitri].FIRST.KTSV(DS_LOPSV::getInstance().nodes[vitri].FIRST,masv)){
                        Data::popup("MA SINH VIEN DA TON TAI ") ;
                        continue;
                    }
                    if (!masv.empty() && !tenSV.empty() && !hoSV.empty() && !phaiSV.empty() && !sdtSV.empty()) { 
                        SinhVien a ={masv,hoSV,tenSV,phaiSV,sdtSV} ; 
                        DS_LOPSV::getInstance().themSV( DS_LOPSV::getInstance(), DS_LOPSV::getInstance().nodes[vitri].MALOP , a) ;
                        cout << "DANH SACH SINH VIEN SAU KHI THEM " << endl ;
                        // DS_LOPSV::getInstance().nodes[vitri].FIRST.In34() ;
                        DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance(),DS_LOPSV::getInstance().nodes[vitri].MALOP) ;
                        std::cout << "Succesfull add a student !!!!!!!!!! \n";
                        custom::vector<std::string> newRow = { masv,tenSV,hoSV,phaiSV,sdtSV}; 
                    // Gọi hàm addmonhoc để thêm dòng dữ liệu mới vào CSV
                    if (Data::add(studentFile, font, newRow)) {
                        std::cout << "thanh cong " << std::endl;
                    } else {
                        std::cerr << "not load" << std::endl;
                        }
                    }
                    Data::popup("THEM SINH VIEN THANH CONG ") ; 
                }
                if(thoat.isClicked(mousePos)){
                    return 5 ; 
                }
            }

            Ma.processInput(event);
            Ten.processInput(event);
            Ho.processInput(event);
            Phai.processInput(event);
            SDT.processInput(event);

            // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // Chuyển đổi trạng thái chọn cho các trường nhập liệu
            // Ma.setSelected(Ma.isSelected() && !saveBtn.isClicked(mousePos));
            // Ten.setSelected(Ten.isSelected() && !saveBtn.isClicked(mousePos));
            // Ho.setSelected(Ho.isSelected() && !saveBtn.isClicked(mousePos));
            // Phai.setSelected(Phai.isSelected() && !saveBtn.isClicked(mousePos));
            // SDT.setSelected(SDT.isSelected() && !saveBtn.isClicked(mousePos));
        }

        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);
         // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window) ; 
         //Vẽ các yếu tố lớp học
        title.draw(window);
        ma.draw(window);
        ten.draw(window);
        ho.draw(window);
        phai.draw(window);
        sdt.draw(window);

        Ma.draw(window);
        Ten.draw(window);
        Ho.draw(window);
        Phai.draw(window);
        SDT.draw(window);
        
        ghi.draw(window);
        window.display();
    }

    return 0;
}
int ScreenLopHoc::fixStudent(sf :: RenderWindow& window, SinhVien& selectedsv , int& vitri)  {
    cout  << "DEN HAM SUA SINH VIEN " ; 
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1  ; // Trả về lỗi nếu không tải được font
    } 
      // Các thành phần giao diện
    Text title(366.f, 216.f, 485.f, 122.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 20);
    Text ma(132.f, 390.f, 158.f, 58.f, "MA SINH VIEN ", font, sf::Color::Red, 20);
    Text ten(132.f, 515.f, 158.f, 58.f, "TEN", font, sf::Color::Red, 20);
    Text ho(694.f, 390.f, 158.f, 58.f,  "HO", font, sf::Color::Red, 20);
    Text phai(694.f, 491.f, 158.f, 58.f, "PHAI", font, sf::Color::Red, 20);
    Text sdt(356.f, 619.f, 158.f, 58.f, "SDT", font, sf::Color::Red, 20);
     // InputField Ma (900.f , 359.f ,286.f, 58.f , font ) ; 
    InputField Ten(356.f, 506.f, 286.f, 58.f,font ) ; 
    InputField Ho(964.f, 399.f, 325.f, 58.f,font ) ; 
    InputField Phai(964.f, 491.f, 120.f, 58.f,font ) ; 
    InputField SDT(694.f, 610.f, 411.f, 58.f,font ) ; 

    Text Ma1(356.f, 390.f, 286.f, 58.f,selectedsv.MASV , font ,  sf :: Color :: Red , 15);
    EditableText Ten1(356.f, 506.f, selectedsv.HO ,  font , &Ten)  ;
    EditableText Ho1(964.f, 399.f,  selectedsv.TEN , font , &Ho);
    EditableText Phai1(964.f, 491.f, selectedsv.PHAI ,  font , &Phai);
    EditableText SDT1(694.f, 610.f,  selectedsv.SODT ,  font , &SDT);

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    fsys::path studentFile = classDir / (DS_LOPSV::getInstance().nodes[vitri].TENLOP + ".csv");
    cout<< "file path cua sinh vien la " << studentFile << endl ;
    // Ma.setSelected(true);
    // Ten.setSelected(true);
    // Ho.setSelected(true);
    // Phai.setSelected(true);
    // SDT.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        // if (Ma.isSelected()) Ma.textCursor(Ma.getInput());
        if (Ten.isSelected()) Ten.textCursor(Ten.getInput());
        if (Ho.isSelected()) Ho.textCursor(Ho.getInput());
        if (Phai.isSelected()) Phai.textCursor(Phai.getInput());
        if (SDT.isSelected()) SDT.textCursor(SDT.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
              // Cập nhật sự kiện cho EditableText
            Ten1.update(event);
            Ho1.update(event);
            Phai1.update(event);
            SDT1.update(event);
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // Ma.handleMouseClick(mousePos);
                Ten1.handleMouseClick(mousePos);
                Ho1.handleMouseClick(mousePos);
                Phai1.handleMouseClick(mousePos);
                SDT1.handleMouseClick(mousePos);

                if (ghi.isClicked(mousePos)) {
                    // std::string maSV = Ma1.getInput();
                    std::string tenSV = Ten1.getText();
                    std::string hoSV = Ho1.getText();
                    std::string phaiSV = Phai1.getText();
                    std::string sdtSV = SDT1.getText();

                      // Kiểm tra thay đổi ở các trường
                    if (  tenSV != selectedsv.TEN || hoSV != selectedsv.HO || phaiSV != selectedsv.PHAI || sdtSV != selectedsv.SODT) {
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        custom::vector<std::string> newRow = {selectedsv.MASV, tenSV, hoSV,phaiSV , sdtSV};
                        Data::update(studentFile, selectedsv.MASV, newRow);
                        selectedsv = {selectedsv.MASV, tenSV, hoSV,phaiSV , sdtSV};
                       DS_LOPSV::getInstance().SuaSinhVien(DS_LOPSV::getInstance(), DS_LOPSV::getInstance().nodes[vitri].MALOP , selectedsv.MASV ,selectedsv ) ;
                       cout << "DANH SACH SINH VIEN SAU KHI SUA " << endl ;
                       DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance(),DS_LOPSV::getInstance().nodes[vitri].MALOP) ;
                    }
                    Data::popup("CHINH SUA THANH CONG ") ;
                }
                 if(thoat.isClicked(mousePos)){
                    return 5  ;
                }
            }
            Ten.updateCursor();
            Ho.updateCursor();
            Phai.updateCursor();
            SDT.updateCursor();

            // // Ma.processInput(event);
            // if (Ma.chooseNextField()) {
            //     Ten.setSelected(true);
            // }
            // Ten.processInput(event);
            // Ho.processInput(event);
            // Phai.processInput(event);
            // SDT.processInput(event);
        }
        window.clear(sf::Color::White);
        title.draw(window);

        ma.draw(window);
        ten.draw(window);
        phai.draw(window);
        sdt.draw(window);

        ho.draw(window);
        Ma1.draw(window);
        Ten1.draw(window);
        Phai1.draw(window);
        SDT1.draw(window);
        Ho1.draw(window);
        // Ma.draw(window);
        // Ten.draw(window);
        // Ho.draw(window);
        // Phai.draw(window);
        // SDT.draw(window);

        them.draw(window);
        xoa.draw(window);
        ghi.draw(window);  
        thoat.draw(window); 
        sua.draw(window); 
        window.display();
    }
    return 0   ;
 } 


