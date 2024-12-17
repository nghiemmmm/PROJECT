#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <string>
#include "Lop.h" // Đảm bảo rằng Lop.h chứa định nghĩa cho LopSV
#include<fstream>
#include<sstream>
#include<iostream>
#include"Components.h"
#include <filesystem>
#include"Properties.h"
namespace fsys = std::filesystem;
using namespace std;

// Khai báo hàm toàn cục để lấy danh sách các lớp học
   extern std::vector<Text> classList;
   extern std::vector<Button>  Buttonclass;
// khai báo lấy môn học 
    extern std::vector<Text> subjectList;
    extern std::vector<Button> buttonsubject;
// khai bao lop tin chi 
    extern std::vector<Text> TCList;
    extern std::vector<Button> buttonTC;
    extern std::vector<Button> buttonTC1;

    extern std::vector<Text> TCList1;
    extern std::vector<Text> TCList2;
    extern std::vector<Text> TCList3;

    extern std::vector<Text> StudentList ; 
    extern std::vector<Button> ButtonStudent ;

    extern std::vector<Text> baocao ;
//khai báo mang kiem tra các file các lớp  kiểu filefath có so luong bang so lop 
 #endif // GLOBALS_H


