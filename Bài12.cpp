#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <conio.h>

using namespace std;

class LaiXe
{
private:
	static int MaLX_BD;
	int MaLaiXe;
	string TenLaiXe;
	string DiaChi;
	string SoDienThoai;
	string TrinhDo;
public:
	LaiXe()
	{
		MaLaiXe = MaLX_BD++;
		TenLaiXe = "Unkown";
		DiaChi = "Unkown";
		SoDienThoai = "Unkown";
		TrinhDo = "Unkown";
	}
	void NhapLaiXe()
	{
		cout << "	Ten lai xe: "; getline(cin, TenLaiXe);
		cout << "	Dia chi: "; getline(cin, DiaChi);
		cout << "	So dien thoai: "; getline(cin, SoDienThoai);
		cout << "	Trinh do: "; getline(cin, TrinhDo);
	}
	void XuatLaiXe() const 
	{
		cout << setw(20) << left << MaLaiXe << setw(20) << left << TenLaiXe;
		cout << setw(20) << left << DiaChi << setw(20) << left << SoDienThoai;
		cout << setw(20) << left << TrinhDo << endl;
	}
	int getMaLaiXe()
	{
		return MaLaiXe;
	}
	string getTenLaiXe()
	{
		return TenLaiXe;
	}

};
int LaiXe::MaLX_BD = 10000;

class Tuyen
{
private:
	static int MaT_BD;
	int MaTuyen;
	float KhoangCach;
	int SoDiemDung;
public:
	Tuyen()
	{
		MaTuyen = MaT_BD++;
		KhoangCach = 0;
		SoDiemDung = 0;
	}
	void NhapTuyen() 
	{
		cout << "	Nhap khoang cach: "; cin >> KhoangCach;
		cout << "	Nhap so diem dung: "; cin >> SoDiemDung;
	}
	void XuatTuyen() const
	{
		cout << setw(20) << left << MaTuyen;
		cout << setw(20) << left << KhoangCach;
		cout << setw(20) << left << SoDiemDung;
		cout << endl;
	}
	int getMaTuyen()
	{
		return MaTuyen;
	}
};
int Tuyen::MaT_BD = 100;

class PhanCong
{
private:
	LaiXe PhanCongLaiXe;
	Tuyen PhanCongTuyen;
	int SoLuot;
public:
	void setPhanCong(LaiXe a, Tuyen b)
	{
		PhanCongLaiXe = a;
		PhanCongTuyen = b;
	}
	void NhapSoLuot()
	{
		cout << "Nhap so luot: "; cin >> SoLuot;
	}
	void XuatPhanCong()
	{
		cout << setw(20) << left << PhanCongLaiXe.getMaLaiXe();
		cout << setw(20) << left << PhanCongLaiXe.getTenLaiXe();
		cout << setw(20) << left << PhanCongTuyen.getMaTuyen();
		cout << setw(20) << left << SoLuot;
		cout << endl;
	}
	LaiXe getPhanCongLaiXe()
	{
		return PhanCongLaiXe;
	}
	int getSoLuot()
	{
		return SoLuot;
	}
	void setSoLuot(int a)
	{
		SoLuot = a;
	}
};

static void KhungTuyen()
{
	cout << setfill('-') << setw(60) << '-' << endl;
	cout << setfill(' ');
	cout << setw(35) << right << "DANH SACH TUYEN" << endl;
	cout << setfill('-') << setw(60) << '-' << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma Tuyen";
	cout << setw(20) << left << "Khoang Cach";
	cout << setw(20) << left << "So diem dung" << endl;
	cout << setfill('-') << setw(60) << '-' << endl;
	cout << setfill(' ');
}

static void KhungLaiXe()
{
	cout << setfill('-') << setw(100) << '-' << endl;
	cout << setfill(' ');
	cout << setw(55) << right << "DANH SACH LAI XE" << endl;
	cout << setfill('-') << setw(100) << '-' << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma lai xe" << setw(20) << left << "Ten lai xe";
	cout << setw(20) << left << "Dia chi" << setw(20) << left << "So dien thoai";
	cout << setw(20) << left << "Trinh do" << endl;
	cout << setfill('-') << setw(100) << '-' << endl;
	cout << setfill(' ');
}

static void KhungPhanCong()
{
	cout << setfill('-') << setw(80) << '-' << endl;
	cout << setfill(' ');
	cout << setw(45) << right << "DANH SACH PHAN CONG" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma Lai Xe";
	cout << setw(20) << left << "Ten Lai Xe";
	cout << setw(20) << left << "Ma Tuyen";
	cout << setw(20) << left << "So Luot";
	cout << endl;
	cout << setfill('-') << setw(80) << '-' << endl;
	cout << setfill(' ');
}

int main()
{
	// 1. Nhap xuat DANH SACH LAI XE
	vector<LaiXe> ListLaiXe;
	int SLLX;
	cout << "Nhap so luong lai xe: "; cin >> SLLX; cin.ignore();
	ListLaiXe.resize(SLLX);
	for (int i = 0; i < SLLX; i++)
	{
		cout << "Nhap lai xe thu " << i + 1 << ": " << endl;
		ListLaiXe[i].NhapLaiXe();
	}
	KhungLaiXe();
	for (int i = 0; i < SLLX; i++)
	{
		ListLaiXe[i].XuatLaiXe();
	}
	
	system("pause");
	system("cls");
	// 2. Nhap xuat DANH SACH TUYEN
	vector<Tuyen> ListTuyen;
	int SLT;
	cout << "Nhap so luong tuyen: "; cin >> SLT;
	ListTuyen.resize(SLT);
	for (int i = 0; i < SLT; i++)
	{
		cout << "Nhap tuyen thu " << i + 1 << ": " << endl;
		ListTuyen[i].NhapTuyen();
	}
	KhungTuyen();
	for (int i = 0; i < SLT; i++)
	{
		ListTuyen[i].XuatTuyen();
	}
	system("pause");
	system("cls");

	// 3. Nhap xuat DANH SACH PHAN CONG
	vector<PhanCong> ListPhanCong;
	vector<int> SoLuotNgay;
	for (int i = 0; i < SLLX; i++)
	{
		SoLuotNgay.push_back(0);
		cout << "Phan cong cho lai xe " << ListLaiXe[i].getTenLaiXe() << ":" << endl;
		for (int j = 0; j < SLT; j++)
		{
			cout << "Tuyen: " << ListTuyen[j].getMaTuyen() << endl;
			int chon;
			cout << "Neu phan cong chon 1, huy chon 2: "; cin >> chon;
			if (chon == 1)
			{
				PhanCong PC;
				PC.setPhanCong(ListLaiXe[i], ListTuyen[j]);
				PC.NhapSoLuot();
				if (PC.getSoLuot() + SoLuotNgay[i] <= 15)
				{ 
					ListPhanCong.push_back(PC);
				}
				else
				{
					if (SoLuotNgay[i] < 15)
					{
						PC.setSoLuot(15 - SoLuotNgay[i]);
						ListPhanCong.push_back(PC);
					}
				}
				
			}
		}
	}
	KhungPhanCong();
	for (int i = 0; i < ListPhanCong.size(); i++)
	{
		ListPhanCong[i].XuatPhanCong();
	}
	return 0;
}
