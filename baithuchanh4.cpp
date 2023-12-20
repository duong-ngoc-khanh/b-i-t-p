#include <iostream>
#include <vector>

class NGUOI {
public:
    std::string HoTen;
    int Tuoi;

    NGUOI() : HoTen(""), Tuoi(0) {}
    NGUOI(std::string hoTen, int tuoi) : HoTen(hoTen), Tuoi(tuoi) {}

    virtual void Nhap() {
        std::cout << "Nhap ho ten: ";
        std::cin.ignore();
        std::getline(std::cin, HoTen);

        std::cout << "Nhap tuoi: ";
        std::cin >> Tuoi;
    }

    virtual void Xuat() const {
        std::cout << "Ho ten: " << HoTen << ", Tuoi: " << Tuoi;
    }
};

class BAC_SI : public NGUOI {
private:
    std::string MaBS;
    double SoNgayLamViec;
    double TienCongNgay;

public:
    BAC_SI() : NGUOI(), MaBS(""), SoNgayLamViec(0), TienCongNgay(0) {}
    BAC_SI(std::string hoTen, int tuoi, std::string maBS, double soNgayLamViec, double tienCongNgay)
        : NGUOI(hoTen, tuoi), MaBS(maBS), SoNgayLamViec(soNgayLamViec), TienCongNgay(tienCongNgay) {}

    void Nhap() override {
        NGUOI::Nhap();

        std::cout << "Nhap Ma bac si: ";
        std::cin.ignore();
        std::getline(std::cin, MaBS);

        std::cout << "Nhap so ngay lam viec: ";
        std::cin >> SoNgayLamViec;

        std::cout << "Nhap tien cong ngay: ";
        std::cin >> TienCongNgay;
    }

    void Xuat() const override {
        NGUOI::Xuat();
        std::cout << ", Ma BS: " << MaBS << ", So ngay lam viec: " << SoNgayLamViec
                  << ", Tien cong thang: " << SoNgayLamViec * TienCongNgay;
    }

    double GetSoNgayLamViec() const {
        return SoNgayLamViec;
    }
};

int main() {
    int n;
    std::cout << "Nhap so luong nguoi: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "So luong nguoi khong hop le." << std::endl;
        return 1;
    }

    std::vector<NGUOI*> danhSachNguoi;

    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap thong tin nguoi thu " << i + 1 << ":\n";
        BAC_SI* bacSi = new BAC_SI();
        bacSi->Nhap();
        danhSachNguoi.push_back(bacSi);
    }

    // Hiển thị danh sách NGUOI nhập vào
    std::cout << "\nDanh sach nguoi:\n";
    for (const auto& nguoi : danhSachNguoi) {
        nguoi->Xuat();
        std::cout << std::endl;
    }

    // Tìm BAC_SI có số ngày làm việc nhiều nhất
    BAC_SI* bacSiMaxNgay = nullptr;
    double maxNgay = 0;

    for (const auto& nguoi : danhSachNguoi) {
        const BAC_SI* bacSi = dynamic_cast<const BAC_SI*>(nguoi);
        if (bacSi && bacSi->GetSoNgayLamViec() > maxNgay) {
            maxNgay = bacSi->GetSoNgayLamViec();
            bacSiMaxNgay = const_cast<BAC_SI*>(bacSi);
        }
    }

    if (bacSiMaxNgay) {
        std::cout << "\nBAC_SI co so ngay lam viec nhieu nhat:\n";
        bacSiMaxNgay->Xuat();
        std::cout << std::endl;
    } else {
        std::cout << "\nKhong co BAC_SI trong danh sach.\n";
    }

    // Giải phóng bộ nhớ
    for (auto& nguoi : danhSachNguoi) {
        delete nguoi;
    }

    return 0;
}
