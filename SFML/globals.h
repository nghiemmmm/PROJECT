#ifndef GLOBALS_H
#define GLOBALS_H

// #include <vector>
#include"vector.h"  
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

// // Khai báo hàm toàn cục để lấy danh sách các lớp học
//    extern std::vector<Text> classList;
//    extern std::vector<Button>  Buttonclass;
// // khai báo lấy môn học 
//     extern std::vector<Text> subjectList;
//     extern std::vector<Button> buttonsubject;
// // khai bao lop tin chi 
//     extern std::vector<Text> TCList;
//     extern std::vector<Button> buttonTC;
//     extern std::vector<Button> buttonTC1;

//     extern std::vector<Text> TCList1;
//     extern std::vector<Text> TCList2;
//     extern std::vector<Text> TCList3;

//     extern std::vector<Text> StudentList ; 
//     extern std::vector<Button> ButtonStudent ;

//     extern std::vector<Text> baocao ;


// Khai báo hàm toàn cục để lấy danh sách các lớp học
   extern custom::vector<Text> classList;
   extern custom::vector<Button>  Buttonclass;
// khai báo lấy môn học 
    extern custom::vector<Text> subjectList;
    extern custom::vector<Button> buttonsubject;
// khai bao lop tin chi 
    extern custom::vector<Text> TCList;
    extern custom::vector<Button> buttonTC;
    extern custom::vector<Button> buttonTC1;

    extern custom::vector<Text> TCList1;
    extern custom::vector<Text> TCList2;
    extern custom::vector<Text> TCList3;

    extern custom::vector<Text> StudentList ; 
    extern custom::vector<Button> ButtonStudent ;

    extern custom::vector<Text> baocao ;
 #endif // GLOBALS_H


