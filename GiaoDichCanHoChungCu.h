#ifndef GIAODICHCANHOCHUNGCU_H
#define GIAODICHCANHOCHUNGCU_H
#include <string>

#include <GiaoDich.h>


class GiaoDichCanHoChungCu : public GiaoDich
{
private:
    std::string MaCan;
    int ViTriTang;
public:
    float TinhThanhTien()override;
    void Nhap(istream& is)override;
    void Xuat(ostream&os) override;
};

#endif // GIAODICHCANHOCHUNGCU_H
