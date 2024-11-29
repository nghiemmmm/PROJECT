#ifndef FILENFODER_H
#define FILENFODER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <SFML/Graphics.hpp> // Bao gồm tiêu đề SFML cho Text

namespace fsys = std::filesystem;
using ll = long long;

class csvFile {
public :
    fsys::path filePath;

public:
    std::vector<std::vector<std::string>> cnt; // Thêm std:: để rõ ràng hơn

    csvFile() {}

    csvFile(fsys::path path) {
        std::string sPath = path.generic_string();
        for (char& c : sPath) { // Thay đổi char thành char& để thay đổi ký tự
            if (c == '\\') c = '/'; // Sửa ký tự escape cho đúng
        }
        fsys::path fPath(sPath);
        this->filePath = fPath;
        isCreate(); // Gọi hàm để kiểm tra và tạo tệp
    }

    bool isCreate(); // Trả về false nếu tệp đã tồn tại, true nếu tệp không tồn tại và tạo tệp mới

    void clearSavedContent() {
        cnt.clear();
    }

    void readFile();
    
    bool writeFile(); 

    bool addCellOnFirstRow();
    
    bool addRow();
    
    bool addCol();
    
    bool deleteRow(ll index);
    
    bool deleteCol(ll index);

    csvFile& operator=(const csvFile& b) {
        if (this == &b) return *this;
        this->filePath = b.filePath;
        this->cnt = b.cnt;
        return *this;
    }
};

#endif // FILENFODER_H
