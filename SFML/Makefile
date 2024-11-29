# Tên file thực thi
TARGET = main.exe

# Trình biên dịch
CXX = g++

# Đường dẫn tới các thư viện SFML đã cài đặt
SFML_INCLUDE = C:/Users/ASUS/Documents/libraries/SFML-2.6.1/include
SFML_LIB = C:/Users/ASUS/Documents/libraries/SFML-2.6.1/lib

# Các thư viện cần liên kết
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lfreetype -lwinmm -lgdi32 -static-libgcc -static-libstdc++ -lsfml-main

# Cờ cho trình biên dịch và trình liên kết
CXXFLAGS = -I$(SFML_INCLUDE) -DSFML_STATIC -Wall
LDFLAGS = -L$(SFML_LIB) $(LIBS)

# File nguồn (cập nhật đường dẫn)
SRC = Page.cpp \
      PageLopHoc.cpp \
      PageLopTinchi.cpp \
      PageMonHoc.cpp \
      PageNhapDiem.cpp \
      Components.cpp \
      FileNFoder.cpp\
      globals.cpp\
      DataUtils.cpp\
      MonHoc.cpp\
      Lop.cpp\
      SinhVien.cpp\
      DangKy.cpp\
      app.cpp \
      main.cpp

# File object
OBJ = $(SRC:.cpp=.o)

# Quy tắc biên dịch
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

# Cập nhật quy tắc biên dịch để sử dụng đúng đường dẫn
%.o: SFML/SFML/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc dọn dẹp
clean:
	del /f $(OBJ) $(TARGET) || rm -f $(OBJ) $(TARGET)
