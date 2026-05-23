#ifndef GIAODICHDAT_H
#define GIAODICHDAT_H

#include <GiaoDich.h>


class GiaoDichDat : public GiaoDich
{
private:
    char LoaiDat;
public:
    void Nhap(istream&is) override;
    void Xuat(ostream&os) override;
    float TinhThanhTien() override;
};

#endif // GIAODICHDAT_H
