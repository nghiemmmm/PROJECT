#include "FileNFoder.h"
// #include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

bool csvFile::isCreate() {
    if (fsys::exists(filePath)) {
        std::cerr << filePath << " already exists.\n";
        return false;
    }
    return true;
}

void csvFile::readFile() {
    cnt.clear();
    std::ifstream fin;
    std::string stringPath = filePath.generic_string();

    fin.open(stringPath);
    if (!fin.is_open()) {
        std::cerr << "Error opening input file " << stringPath << ".\n";
        return;
    }

    std::string rowS;
    std::string cell;

    while (std::getline(fin, rowS)) {
        custom::vector<std::string> rowContent; // Đảm bảo sử dụng std::vector
        std::stringstream rowSS(rowS);
        while (std::getline(rowSS, cell, ',')) {
            rowContent.push_back(cell);
        }
        cnt.push_back(rowContent);
    }
    fin.close();
}

bool csvFile::writeFile() {
    std::ofstream fout;
    std::string stringPath = filePath.generic_string();

    fout.open(stringPath);
    if (!fout.is_open()) {
        std::cerr << "Cannot open " << stringPath << " to write.\n";
        return false;
    }

    for (const auto& row : cnt) {
        for (size_t j = 0; j < static_cast<size_t>(row.size()); ++j) {
            fout << row[j];
            if (j < static_cast<size_t>(row.size()) - 1) fout << ",";
        }
        fout << std::endl;
    }
    std::cout << "File " << stringPath << " written.\n";
    return true;
}

bool csvFile::addCellOnFirstRow() {
    if (this->cnt.empty()) { // Nếu cnt trống, thêm hàng mới
        custom::vector<std::string> row(1, " ");
        this->cnt.push_back(row);
    } else {
        this->cnt[0].push_back(" ");
    }
    return true;
}

bool csvFile::addRow() {
    if (this->cnt.empty())
        addCellOnFirstRow();
    custom::vector<std::string> row(this->cnt[0].size(), " ");
    this->cnt.push_back(row);
    return true;
}

bool csvFile::addCol() {
    ll contentSize = this->cnt.size();
    if (contentSize == 0)
        addCellOnFirstRow();
    else {
        for (ll i = 0; i < contentSize; i++)
            this->cnt[i].push_back(" ");
    }
    return true;
}

bool csvFile::deleteRow(ll index) {
    // if (static_cast<custom::vector<custom::vector<std::string>>::size_type>(index) >= this->cnt.size()) return false; // Kiểm tra chỉ số
    // cnt.erase(cnt.begin() + index); // Xóa hàng theo chỉ số
    // return true;
    ll contentSize = this->cnt.size();
    if (index >= contentSize) return false;
    if (cnt[index].size() > 0) cnt[index].clear();
    for (ll i = index; i < contentSize - 1; i++)
        cnt[index] = cnt[index + 1];
    cnt.pop_back();
    return true;
}

bool csvFile::deleteCol(ll index) {
    // for (auto& row : cnt) {
    //    if (static_cast<std::vector<std::string>::size_type>(index) >= row.size()) return false; // Kiểm tra chỉ số
    //     row.erase(row.begin() + index); // Xóa ô theo chỉ số
    // }
    // return true;
     ll contentSize = this->cnt.size();
    for (ll i = 0; i < contentSize; i++) {
        if (index >= cnt[i].size()) return false;
        for (ll j = index; j < cnt[i].size() - 1; j++)
            cnt[i][j] = cnt[i][j + 1];
        cnt[i].pop_back();
    }
    return true;
}
