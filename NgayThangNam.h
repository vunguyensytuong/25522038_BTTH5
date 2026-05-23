#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H
#include <iostream>
using namespace std;

class NgayThangNam
{
private:
    int Ngay,Thang,Nam;
public:
    friend istream&operator>>(istream&in, NgayThangNam&d);
    friend ostream&operator<<(ostream&out, const NgayThangNam&d);
    static bool NgayHopLe(int d, int m, int y);
    static bool NamNhuan(int y);
    static int NgayTrongThang(int m, int y);
};

#endif // NGAYTHANGNAM_H
