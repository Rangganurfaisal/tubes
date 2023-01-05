#include "Kapal.h"

int main(){
	//Variables
	Queue Q;
	Stack S;
	adr_kapal pk;
	kapal k;
	int menu;

	//Algorithm
	createQueue(Q);
	while(true){
		cout << "\t\t\t********* ANTREAN KAPAL **********" << endl;
		cout << "\t\t\t* 1. ENTRI KAPAL                 *" << endl;
		cout << "\t\t\t* 2. BERANGKATKAN KAPAL PERTAMA  *" << endl;
		cout << "\t\t\t* 3. LIST KAPAL                  *" << endl;
		cout << "\t\t\t* 4. KELUAR DARI PROGRAM         *" << endl;
		cout << "\t\t\t**********************************" << endl;
		cout << endl;
		cout << "\t\t\tPilih >> "; cin >> menu;

		cout << endl;
		if(menu == 1){
			cin.ignore();
			cout << "\t\t\tMasukkan Nama Kapal      : ";
			getline(cin >> ws, k.nama);

			while(true){
				cout << "\t\t\tMasukkan Kapasitas Kapal : ";
				cin >> k.kapasitas;

				cout << endl;
				if(k.kapasitas < 1){
					cout << "\t\t\tKapasitas Kapal Tidak Boleh Kurang dari 1!" << endl;
				}else{
					break;
				}
			}

			enqueue(Q, k);

			cout << "\t\t\tKapal " << k.nama << " dengan Kapasitas " << k.kapasitas << " Penumpang Berhasil Berlabuh" << endl;
		}else if(menu == 2){
			if(!isQueueEmpty(Q)){
				k = dequeue(Q);

				cout << "\t\t\tKapal " << k.nama << " dengan Kapasitas " << k.kapasitas << " Penumpang Siap Berlayar!" << endl;
			}else{
				cout << "\t\t\tTIDAK ADA KAPAL YANG BISA DIBERANGKATKAN" << endl;
			}
		}else if(menu == 3){
			if(!isQueueEmpty(Q)){
				showQueue(Q);
			}else{
				cout << "\t\t\tTIDAK ADA KAPAL YANG BERLABUH" << endl;
			}
		}else if(menu == 4){
			cout << "\t\t\tKeluar dari program..." << endl;

			break;
		}else{
			cout << "\t\t\tMenu " << menu << " Tidak Ditemukan" << endl;
		}

		cout << endl << "\t\t\t";
		system("pause");
		system("cls");
	}

	return 0;
}
