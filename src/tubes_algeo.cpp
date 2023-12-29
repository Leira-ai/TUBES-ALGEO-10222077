#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

void printMatrix(double mat[][4], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(10) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int findLeadingOneColumn(double mat[][4], int row, int currentRow) {
    for (int j = 0; j < 3; j++) {
        if (mat[currentRow][j] != 0) {
            return j;
        }
    }
    return -1;
}

void gaussElimination(double mat[][4], int row, int col) {
    cout << "\nLangkah-langkah eliminasi Gauss:\n";
    for (int i = 0; i < row - 1; i++) {
        cout << "\nLangkah " << i + 1 << ":\n";
        cout << "Matriks sebelum eliminasi Gauss:\n";
        printMatrix(mat, row, col);

        int leadCol = findLeadingOneColumn(mat, row, i);
        if (leadCol == -1) {
            cout << "Tidak ada leading one di baris ini.\n";
            continue;
        }

        for (int k = i + 1; k < row; k++) {
            double factor = mat[k][leadCol] / mat[i][leadCol];
            cout << "Baris " << k + 1 << " - (" << factor << " * Baris " << i + 1 << ")\n";
            for (int j = 0; j <= col; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
        cout << "Matriks setelah eliminasi Gauss:\n";
        printMatrix(mat, row, col);
    }
}

void gaussJordanElimination(double mat[][4], int row, int col) {
    cout << "\nLangkah-langkah eliminasi Gauss-Jordan:\n";
    for (int i = 0; i < row; i++) {
        cout << "\nLangkah " << i + 1 << ":\n";
        cout << "Matriks sebelum eliminasi Gauss-Jordan:\n";
        printMatrix(mat, row, col);

        int leadCol = findLeadingOneColumn(mat, row, i);
        if (leadCol == -1) {
            cout << "Tidak ada leading one di baris ini.\n";
            continue;
        }

        cout << "Baris " << i + 1 << " dibagi dengan " << mat[i][leadCol] << " agar leading one menjadi 1\n";
        double divisor = mat[i][leadCol];
        for (int j = 0; j <= col; j++) {
            mat[i][j] /= divisor;
        }

        for (int j = 0; j < row; j++) {
            if (j != i) {
                double factor = mat[j][leadCol];
                cout << "Baris " << j + 1 << " - (" << factor << " * Baris " << i + 1 << ")\n";
                for (int k = 0; k <= col; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
        cout << "Matriks setelah eliminasi Gauss-Jordan:\n";
        printMatrix(mat, row, col);
    }
}

float hitungDeterminan(float a, float b, float c, float d) {
    return (a * d - b * c);
}

void inversMatriks(float a, float b, float c, float d) {
    // Hitung determinan
    float det = hitungDeterminan(a, b, c, d);

    if (det == 0) {
        cout << "Matriks tidak memiliki invers karena determinannya nol." << endl;
        return;
    }

    float invDet = 1.0 / det;
    float invA = d * invDet;
    float invB = -b * invDet;
    float invC = -c * invDet;
    float invD = a * invDet;

    cout << "Matriks Invers:" << endl;
    cout << invA << "  " << invB << endl;
    cout << invC << "  " << invD << endl;
}

float a1,b1,c1,d1,e1,f1,g1,h1,i1;
float hasil,hasil2,hasil3,hasil4;
string ulang;
string pilih1,pilih2,pilih3;
string pilih;


int main(){
	cout<<endl;
	x : cout<<"\t Menu"<<endl;
	cout<<endl;
	cout<<"1.Penjumlahan dan pengurangan matriks"<<endl;
	cout<<"2.Matriks transpose"<<endl;
	cout<<"3.Matriks Balikan"<<endl;
	cout<<"4.Determinan"<<endl;
	cout<<"5.Sistem persamaan linier"<<endl;
	cout<<"6.Keluar"<<endl;
	cout<<endl;
	cout<<"Ingin menghitung apa?"<<endl;
	cin>>pilih;
	
	if(pilih=="1"){
		cout<<"1.Penjumlahan Matriks"<<endl;
		cout<<"2.Pengurangan Matriks"<<endl;
		cout<<"Ingin menghitung apa?"<<endl;
		cin>>pilih1;
		if(pilih1=="1"){
			system("cls");
			cout<<"Masukan bilangan matriks pertama!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a21 = ";
			cin>>c1;
			cout<<"a22 = ";
			cin>>d1;
			cout<<"Masukan bilangan matriks kedua!"<<endl;
			cout<<"b11 = "; 
			cin>>e1;
			cout<<"b12 = ";
			cin>>f1;
			cout<<"b21 = ";
			cin>>g1;
			cout<<"b22 = ";
			cin>>h1;
			cout<<"Matriks Asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<"]"<<"["<<e1<<" "<<f1<<"]"<<endl;
			cout<<"["<<c1<<" "<<d1<<"]"<<"["<<g1<<" "<<h1<<"]"<<endl;
			cout<<"Hasil penjumlahan matriks = "<<endl;
			hasil = a1+e1;
			hasil2 = b1+f1;
			hasil3 = c1+g1;
			hasil4 = d1+h1;
			cout<<"["<<hasil<<" "<<hasil2<<"]"<<endl;
			cout<<"["<<hasil3<<" "<<hasil4<<"]"<<endl;
			cout<<endl;
			cout<<"Apakah ingin menghitung yang lain ?(y/n)"<<endl;
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
		}else if(pilih1 == "2"){
			system("cls");
			cout<<"Masukan bilangan matriks pertama!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a21 = ";
			cin>>c1;
			cout<<"a22 = ";
			cin>>d1;
			cout<<"Masukan bilangan matriks kedua!"<<endl;
			cout<<"b11 = ";
			cin>>e1;
			cout<<"b12 = ";
			cin>>f1;
			cout<<"b21 = ";
			cin>>g1;
			cout<<"b22 = ";
			cin>>h1;
			cout<<"Matriks Asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<"]"<<"["<<e1<<" "<<f1<<"]"<<endl;
			cout<<"["<<c1<<" "<<d1<<"]"<<"["<<g1<<" "<<h1<<"]"<<endl;
			cout<<"Hasil pengurangan matriks = "<<endl;
			hasil = a1-e1;
			hasil2 = b1-f1;
			hasil3 = c1-g1;
			hasil4 = d1-h1;
			cout<<"["<<hasil<<" "<<hasil2<<"]"<<endl;
			cout<<"["<<hasil3<<" "<<hasil4<<"]"<<endl;
			cout<<endl;
			cout<<"Apakah ingin menghitung yang lain ?(y/n)"<<endl;
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
		}
	}else if(pilih == "2"){
		cout<<"1.Matriks 2x2"<<endl;
		cout<<"2.Matriks 3x3"<<endl;
		cin>>pilih1;
		if(pilih1=="1"){
			system("cls");
			cout<<"Masukan bilangan matriks!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a21 = ";
			cin>>c1;
			cout<<"a22 = ";
			cin>>d1;
			cout<<endl;
			cout<<"Matriks asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<"]"<<endl;
			cout<<"["<<c1<<" "<<d1<<"]"<<endl;
			cout<<endl;
			cout<<"Matriks transpose"<<endl;
			cout<<"["<<a1<<" "<<c1<<"]"<<endl;
			cout<<"["<<b1<<" "<<d1<<"]"<<endl;
			cout<<endl;
			cout<<"Apakah ingin menghitung yang lain ?(y/n)"<<endl;
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
		}else if(pilih1 == "2"){
			system("cls");
			cout<<"Masukan bilangan matriks!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a13 = ";
			cin>>c1;
			cout<<"a21 = ";
			cin>>d1;
			cout<<"a22 = ";
			cin>>e1;
			cout<<"a23 = ";
			cin>>f1;
			cout<<"a31 = ";
			cin>>g1;
			cout<<"a32 = ";
			cin>>h1;
			cout<<"a33 = ";
			cin>>i1;
			cout<<endl;
			cout<<"Matriks asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<" "<<c1<<"]"<<endl;
			cout<<"["<<d1<<" "<<e1<<" "<<f1<<"]"<<endl;
			cout<<"["<<g1<<" "<<h1<<" "<<i1<<"]"<<endl;
			cout<<endl;
			cout<<"Matriks transpose"<<endl;
			cout<<"["<<a1<<" "<<d1<<" "<<g1<<"]"<<endl;
			cout<<"["<<b1<<" "<<e1<<" "<<h1<<"]"<<endl;
			cout<<"["<<c1<<" "<<f1<<" "<<i1<<"]"<<endl;
			cout<<endl;
			cout<<"Apakah ingin menghitung yang lain ?(y/n)"<<endl;
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
		}
	}else if(pilih == "3"){
		system("cls");
//		float a, b, c, d;
//
//    cout << "Masukkan elemen matriks 2x2:" << endl;
//    cout << "a: "; cin >> a;
//    cout << "b: "; cin >> b;
//    cout << "c: "; cin >> c;
//    cout << "d: "; cin >> d;
//
//    inversMatriks(a, b, c, d);
			cout<<"Masukan bilangan matriks!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a21 = ";
			cin>>c1;
			cout<<"a22 = ";
			cin>>d1;
			cout<<endl;
			float Det = (a1*d1)-(b1*c1);
			if(Det == 0){
			cout<<"Matriks tidak memiliki invers karena determinannya nol \n"<<endl;
			cout<<"Apakah ingin menghitung yang lain?(y/n)";
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
			}else{
			cout<<"Matriks asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<"]"<<endl;
			cout<<"["<<c1<<" "<<d1<<"]"<<endl;
			cout<<endl;
			cout<<"Matriks Invers = "<<endl;
			cout<<"["<<d1<<" "<<b1*(-1)<<"]"<<endl;
			cout<<"["<<c1*(-1)<<" "<<a1<<"]"<<endl;
			cout<<endl;
			cout<<"Apakah ingin menghitung yang lain?(y/n)";
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
			}
			
			
	}else if(pilih == "4"){
		system("cls");
		cout<<"1.Matriks 2x2"<<endl;
		cout<<"2.Matriks 3x3"<<endl;
		cin>>pilih1;
		if(pilih1 == "1"){
			system("cls");
			cout<<"Masukan bilangan matriks!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a21 = ";
			cin>>c1;
			cout<<"a22 = ";
			cin>>d1;
			cout<<endl;
			cout<<"Matriks asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<"]"<<endl;
			cout<<"["<<c1<<" "<<d1<<"]"<<endl;
			cout<<endl;
			cout<<"Determinan = "<<endl;
			cout<<"("<<a1<<" x "<<d1<<")"<<" - "<<"("<<c1<<" x "<<b1<<")"<<endl;
			cout<<" = "<<a1*d1<<" - "<<c1*b1<<endl;
			int det;
			det = (a1*d1)-(c1*b1);
			cout<<" = "<<det<<endl;
			cout<<endl;
			cout<<"Apakah ingin menghitung yang lain ?(y/n)"<<endl;
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
		}else if(pilih1 == "2"){
			system("cls");
			cout<<"1.Metode kofaktor"<<endl;
			cout<<"2.Aturan sarrus"<<endl;
			cin>>pilih2;
			if(pilih2=="1"){
			system("cls");
			cout<<"Masukan bilangan matriks!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a13 = ";
			cin>>c1;
			cout<<"a21 = ";
			cin>>d1;
			cout<<"a22 = ";
			cin>>e1;
			cout<<"a23 = ";
			cin>>f1;
			cout<<"a31 = ";
			cin>>g1;
			cout<<"a32 = ";
			cin>>h1;
			cout<<"a33 = ";
			cin>>i1;
			cout<<endl;
			cout<<"Matriks asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<" "<<c1<<"]"<<endl;
			cout<<"["<<d1<<" "<<e1<<" "<<f1<<"]"<<endl;
			cout<<"["<<g1<<" "<<h1<<" "<<i1<<"]"<<endl;
			cout<<endl;
			cout<<"1.Hitung baris pertama"<<endl;
			cout<<"2.Hitung baris kedua"<<endl;
			cout<<"3.Hitung baris ketiga"<<endl;
			cin>>pilih3;
			if(pilih3 == "1"){
				cout<<"Penyelesaian : "<<endl;
				cout<<"Det = ";
				cout<<"("<<a1<<" x "<<"(-1(pangkat 2))"<<" |"<<e1<<" "<<f1<<"|"<<") + ("<<b1<<" x "<<"(-1(pangkat 3))"<<" |"<<d1<<" "<<f1<<"|"<<") + ("<<c1<<" x "<<"(-1(pangkat 4))"<<"|"<<d1<<" "<<e1<<"|"<<")"<<endl;
				cout<<"\t\t\t\   |"<<h1<<" "<<i1<<"|"<<"\t\t\t\ |"<<g1<<" "<<i1<<"|"<<"\t\t\t\      |"<<g1<<" "<<h1<<"|"<<endl;
				cout<<" = "<<a1<<" x "<<(-1*-1)<<"("<<e1*i1<<"-"<<h1*f1<<")"<<" + "<<b1<<" x "<<(-1*-1*-1)<<"("<<d1*i1<<"-"<<g1*f1<<")"<<" + "<<c1<<" x "<<(-1*-1*-1*-1)<<"("<<d1*h1<<"-"<<e1*g1<<")"<<endl;
				cout<<" = "<<a1<<" x "<<(-1*-1)*((e1*i1)-(h1*f1))<<" + "<<b1<<" x "<<(-1*-1*-1)*((d1*i1)-(g1*f1))<<" + "<<c1<<" x "<<(-1*-1*-1*-1)*((d1*h1)-(e1*g1))<<endl;
				cout<<" = "<<a1*((-1*-1)*((e1*i1)-(h1*f1)))<<" + "<<b1*((-1*-1*-1)*((d1*i1)-(g1*f1)))<<" + "<<c1*((-1*-1*-1*-1)*((d1*h1)-(e1*g1)))<<endl;
				cout<<" = "<<(a1*((-1*-1)*((e1*i1)-(h1*f1))))+(b1*((-1*-1*-1)*((d1*i1)-(g1*f1))))+(c1*((-1*-1*-1*-1)*((d1*h1)-(e1*g1))))<<endl;
				cout<<"Apakah ingin menghitung yang lain ? (y/n)"<<endl;
				cin>>ulang;
				if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
			}else if(pilih3 == "2"){
				cout<<"Penyelesaian : "<<endl;
				cout<<"Det = ";
				cout<<"("<<d1<<" x "<<"(-1(pangkat 2))"<<" |"<<b1<<" "<<c1<<"|"<<") + ("<<e1<<" x "<<"(-1(pangkat 3))"<<" |"<<a1<<" "<<c1<<"|"<<") + ("<<f1<<" x "<<"(-1(pangkat 4))"<<"|"<<a1<<" "<<b1<<"|"<<")"<<endl;
				cout<<"\t\t\t\   |"<<h1<<" "<<i1<<"|"<<"\t\t\t\ |"<<g1<<" "<<i1<<"|"<<"\t\t\t\      |"<<g1<<" "<<h1<<"|"<<endl;
				cout<<" = "<<d1<<" x "<<(-1*-1)<<"("<<b1*i1<<"-"<<h1*c1<<")"<<" + "<<e1<<" x "<<(-1*-1*-1)<<"("<<a1*i1<<"-"<<g1*c1<<")"<<" + "<<f1<<" x "<<(-1*-1*-1*-1)<<"("<<a1*h1<<"-"<<g1*b1<<")"<<endl;
				cout<<" = "<<d1<<" x "<<(-1*-1)*((b1*i1)-(h1*c1))<<" + "<<e1<<" x "<<(-1*-1*-1)*((a1*i1)-(g1*c1))<<" + "<<f1<<" x "<<(-1*-1*-1*-1)*((a1*h1)-(g1*b1))<<endl;
				cout<<" = "<<d1*((-1*-1)*((b1*i1)-(h1*c1)))<<" + "<<e1*((-1*-1*-1)*((a1*i1)-(g1*c1)))<<" + "<<f1*((-1*-1*-1*-1)*((a1*h1)-(g1*b1)))<<endl;
				cout<<" = "<<(d1*((-1*-1)*((b1*i1)-(h1*c1))))+(e1*((-1*-1*-1)*((a1*i1)-(g1*c1))))+(f1*((-1*-1*-1*-1)*((a1*h1)-(g1*b1))))<<endl;
				cout<<"Apakah ingin menghitung yang lain ? (y/n)"<<endl;
				cin>>ulang;
				if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
			}else if(pilih3 == "3"){
				cout<<"Penyelesaian : "<<endl;
				cout<<"Det = ";
				cout<<"("<<g1<<" x "<<"(-1(pangkat 2))"<<" |"<<b1<<" "<<c1<<"|"<<") + ("<<h1<<" x "<<"(-1(pangkat 3))"<<" |"<<a1<<" "<<c1<<"|"<<") + ("<<i1<<" x "<<"(-1(pangkat 4))"<<"|"<<a1<<" "<<b1<<"|"<<")"<<endl;
				cout<<"\t\t\t\   |"<<e1<<" "<<f1<<"|"<<"\t\t\t\ |"<<d1<<" "<<f1<<"|"<<"\t\t\t\      |"<<d1<<" "<<e1<<"|"<<endl;
				cout<<" = "<<g1<<" x "<<(-1*-1)<<"("<<b1*f1<<"-"<<e1*c1<<")"<<" + "<<h1<<" x "<<(-1*-1*-1)<<"("<<a1*f1<<"-"<<d1*c1<<")"<<" + "<<i1<<" x "<<(-1*-1*-1*-1)<<"("<<a1*e1<<"-"<<d1*b1<<")"<<endl;
				cout<<" = "<<g1<<" x "<<(-1*-1)*((b1*f1)-(e1*c1))<<" + "<<h1<<" x "<<(-1*-1*-1)*((a1*f1)-(d1*c1))<<" + "<<i1<<" x "<<(-1*-1*-1*-1)*((a1*e1)-(d1*b1))<<endl;
				cout<<" = "<<g1*((-1*-1)*((b1*f1)-(e1*c1)))<<" + "<<h1*((-1*-1*-1)*((a1*f1)-(d1*c1)))<<" + "<<i1*((-1*-1*-1*-1)*((a1*e1)-(d1*b1)))<<endl;
				cout<<" = "<<(g1*((-1*-1)*((b1*f1)-(e1*c1))))+(h1*((-1*-1*-1)*((a1*f1)-(d1*c1))))+(i1*((-1*-1*-1*-1)*((a1*e1)-(d1*b1))))<<endl;	
				cout<<"Apakah ingin menghitung yang lain ? (y/n)"<<endl;
				cin>>ulang;
				if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
			}
			}else if(pilih2 == "2"){
			system("cls");
			cout<<"Masukan bilangan matriks!"<<endl;
			cout<<"a11 = ";
			cin>>a1;
			cout<<"a12 = ";
			cin>>b1;
			cout<<"a13 = ";
			cin>>c1;
			cout<<"a21 = ";
			cin>>d1;
			cout<<"a22 = ";
			cin>>e1;
			cout<<"a23 = ";
			cin>>f1;
			cout<<"a31 = ";
			cin>>g1;
			cout<<"a32 = ";
			cin>>h1;
			cout<<"a33 = ";
			cin>>i1;
			cout<<endl;
			cout<<"Matriks asli"<<endl;
			cout<<"["<<a1<<" "<<b1<<" "<<c1<<"]"<<endl;
			cout<<"["<<d1<<" "<<e1<<" "<<f1<<"]"<<endl;
			cout<<"["<<g1<<" "<<h1<<" "<<i1<<"]"<<endl;
			cout<<endl;
			cout<<"Penyelesaian dengan aturan Sarrus : "<<endl;
			cout<<"Det = ";
			cout<<a1<<"x"<<e1<<"x"<<i1<<" + "<<b1<<"x"<<f1<<"x"<<g1<<" + "<<c1<<"x"<<d1<<"x"<<h1<<" - "<<c1<<"x"<<e1<<"x"<<g1<<" - "<<a1<<"x"<<f1<<"x"<<h1<<" - "<<b1<<"x"<<d1<<"x"<<i1<<endl;
			cout<<" = "<<a1*e1*i1<<" + "<<b1*f1*g1<<" + "<<c1*d1*h1<<" - "<<c1*e1*g1<<" - "<<a1*f1*h1<<" - "<<b1*d1*i1<<endl;
			cout<<" = "<<(a1*e1*i1)+(b1*f1*g1)+(c1*d1*h1)-(c1*e1*g1)-(a1*f1*h1)-(b1*d1*i1)<<endl;
			cout<<"Apakah ingin menghitung yang lain ? (y/n)"<<endl;
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
			}
		}
	}else if(pilih == "5"){
		
	int row = 2, col = 3;
    double mat[2][4];


    cout << "Masukkan matriks augmented 2x3:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Matriks[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat[i][j];
        }
    }


    cout << "\nMatriks awal:\n";
    printMatrix(mat, row, col);


    gaussElimination(mat, row, col);


    cout << "\nMatriks setelah eliminasi Gauss:\n";
    printMatrix(mat, row, col);


    gaussJordanElimination(mat, row, col);


    cout << "\nSolusi dari SPL:\n";
	for (int i = 0; i < row; i++) {
    cout << "x" << i + 1 << " = " << mat[i][col - 1] << endl;
    }
			cout<<"Apakah ingin menghitung yang lain ?(y/n)"<<endl;
			cin>>ulang;
			if(ulang =="y" || ulang =="Y"){
				system("cls");
				goto x;
			}
	}else if(pilih == "6"){
		return 0;
	}
}
