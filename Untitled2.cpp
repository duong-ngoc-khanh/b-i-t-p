#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class Sach {
private:
    int MAS, NXB;
    string TENS;
    string TACGIA;
    string CHUYENNGANH;

public:
    Sach() {}

    void setThongTin(int mas, string tens, string tacGia, string chuyenNganh, int nxb) {
        MAS = mas;
        TENS = tens;
        TACGIA = tacGia;
        CHUYENNGANH = chuyenNganh;
        NXB = nxb;
    }

    int getMaSach () const{
        return MAS;
    }

    string getTenSach() const{
        return TENS;
    }

    string getTacGia(){
        return TACGIA;
    }

    void hienThiThongTin(){
        cout << "Ma sach: " << MAS << endl;
        cout << "Ten sach: " << TENS << endl;
        cout << "Tac gia: " << TACGIA << endl;
        cout << "Chuyen nganh: " << CHUYENNGANH << endl;
        cout << "Nam xuat ban: " << NXB << endl;
    }
};

class BanDoc {
private:
    int MABD, SDT;
    string HOTEN;
    string DIACHI;
    string LOAIBD;

public:
    BanDoc() {}

    void setThongTin(int maBD, string hoTen, string diaChi, int sdt, string loaiBD) {
        MABD = maBD;
        HOTEN = hoTen;
        DIACHI = diaChi;
        SDT = sdt;
        LOAIBD = loaiBD;
    }

    int getMaBanDoc() {
        return MABD;
    }

    string getHoTen(){
        return HOTEN;
    }

    string getDiaChi(){
        return DIACHI;
    }

    int getSDT(){
        return SDT;
    }

    string getLoaiBanDoc() {
        return LOAIBD;
    }

    void hienThiThongTin() const {
        cout << "Ma ban doc: " << MABD << endl;
        cout << "Ho ten: " << HOTEN << endl;
        cout << "Dia chi: " << DIACHI << endl;
        cout << "So dien thoai: " << SDT << endl;
        cout << "Loai ban doc: " << LOAIBD << endl;
    }
};
class QuanLyMuonSach {
private:
    int maBanDoc;
    vector<int> danhSachMaSach;

public:
    QuanLyMuonSach() {}

    void setThongTin(int maBD, vector<int> dsMaSach) {
        maBanDoc = maBD;
        danhSachMaSach = dsMaSach;
    }

    int getMaBanDoc() {
        return maBanDoc;
    }

    vector<int> getDanhSachMaSach () const {
        return danhSachMaSach;
    }

    void hienThiThongTin(const vector<Sach>& danhSachSach) const {
        cout << "Ma ban doc: " << maBanDoc << endl;
        cout << "Danh sach muon sach:" << endl;

        for (int i = 0; i < danhSachMaSach.size(); ++i) {
            int maSach = danhSachMaSach[i];
            bool found = false;

            for (int j = 0; j < danhSachSach.size(); ++j) {
                if (danhSachSach[j].getMaSach() == maSach) {
                    cout << "  - " << danhSachSach[j].getTenSach() << " (Ma sach: " << maSach << ")" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "  - Ma sach " << maSach << " khong ton tai trong danh sach." << endl;
            }
        }

        cout << endl;
    }
};
bool compareSoLuongMuon(const QuanLyMuonSach& q1, const QuanLyMuonSach& q2) {
    return q1.getDanhSachMaSach().size() > q2.getDanhSachMaSach().size();
}

int main() {
	int n, m; cout <<"Nhap so dau sach moi: "; cin >> n;
	//1
    vector<Sach> danhSachSach(n);
    for (int i = 0; i < n; ++i) {
        int maSach, namXuatBan;
        string tenSach, tacGia, chuyenNganh;

        cout << "Nhap thong tin sach thu " << i + 1 << ":" << endl;
        cout << "Ma sach: ";
        cin >> maSach;
        cout << "Ten sach: ";
        cin.ignore(); 
        getline(cin, tenSach);
        cout << "Tac gia: ";
        getline(cin, tacGia);
        cout << "Chuyen nganh: ";
        getline(cin, chuyenNganh);
        cout << "Nam xuat ban: ";
        cin >> namXuatBan;

        danhSachSach[i].setThongTin(maSach, tenSach, tacGia, chuyenNganh, namXuatBan);
    }
    cout <<endl;
   	cout << "Danh sach sach:" << endl;
	for (int i = 0; i < danhSachSach.size(); ++i) {
    	danhSachSach[i].hienThiThongTin();
    	cout <<endl;
}	
//2
	cout <<"Nhap so ban doc moi: "; cin >> m;
    vector<BanDoc> danhSachBanDoc(m);
    for (int i = 0; i < m; ++i) {
        int maBD, sdt;
        string hoTen, diaChi, loaiBD;

        cout << "Nhap thong tin ban doc thu " << i + 1 << ":" << endl;
        cout << "Ma ban doc: ";
        cin >> maBD;
         cout << "Ho ten: ";
        cin.ignore(); 
        getline(cin, hoTen);
        cout << "Dia chi: ";
        getline(cin, diaChi);
        cout << "So dien thoai: ";
        cin >> sdt;
        cout << "Loai ban doc: ";
        cin.ignore();
        getline(cin, loaiBD);

        danhSachBanDoc[i].setThongTin(maBD, hoTen, diaChi, sdt, loaiBD);
    }
	cout <<endl;
    cout << "Danh sach ban doc:" << endl<<endl;
for (int i = 0; i < danhSachBanDoc.size(); ++i) {
    danhSachBanDoc[i].hienThiThongTin();
    cout <<endl;
}
//3
vector<QuanLyMuonSach> danhSachMuonSach;

    for (int i = 0; i < m; ++i) {
        int maBanDoc;
        vector<int> dsMaSach;

        cout << "Nhap thong tin muon sach cho ban doc thu " << i + 1 << ":" << endl;
        cout << "Ma ban doc: ";
        cin >> maBanDoc;

        cout << "Nhap so luong sach muon (khong qua 5): ";
        int soLuong;
        cin >> soLuong;

        for (int j = 0; j < soLuong; ++j) {
            int maSach;
            cout << "Nhap ma sach thu " << j + 1 << ": ";
            cin >> maSach;
            dsMaSach.push_back(maSach);
        }

        danhSachMuonSach.push_back(QuanLyMuonSach());
        danhSachMuonSach[i].setThongTin(maBanDoc, dsMaSach);
    }
    cout << "Danh sach muon sach:" << endl;
    for (int i = 0; i < danhSachMuonSach.size(); ++i) {
        danhSachMuonSach[i].hienThiThongTin(danhSachSach);
    }
//4a

//4b
	sort(danhSachMuonSach.begin(), danhSachMuonSach.end(), compareSoLuongMuon);
    cout << "Danh sach sau khi sap xep theo so luong sach muon giam dan:" << endl;
    for (int i = 0; i < danhSachMuonSach.size(); ++i) {
        danhSachMuonSach[i].hienThiThongTin(danhSachSach);
    }
//5


    return 0;
}
