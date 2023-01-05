#include "kapal.h"

adr_kapal create_element(kapal k){
	//Fungsi membuat elemen di memori
	adr_kapal pk = new elm_kapal; //buat elemen
	info(pk) = k; //masukkan nilai info nya
	next(pk) = NULL; //atur next element NULL

	return pk; //return ke pemanggil fungsi
}

bool isQueueEmpty(Queue Q){
	//Mengecek apakah Head dari Queue itu NULL?
	return Head(Q) == NULL; //kalau NULL, return TRUE kalau gak ya FALSE
}

void createQueue(Queue &Q){
	//Procedure untuk inisialisasi Queue
	Head(Q) = NULL;
	Tail(Q) = NULL;
}

void enqueue(Queue &Q, kapal k){
	//Memasukkan element ke Queue
	adr_kapal pk = create_element(k); //buat elemen dengan memanggil fungsi create_element
	if(Head(Q) == NULL){
		//Kalau Head dari Queue masih NULL
		//atur Head dan Tail dari Queue adalah element dari pk
		Head(Q) = pk;
		Tail(Q) = pk;
	}else{
		//Head dari Queue tidak kosong
		Stack S; //buat Stack
		createStack(S); //inisialisasi Stack
		while(Head(Q) != NULL && info(Head(Q)).kapasitas > k.kapasitas){
			//Selama Head dari Q tidak NULL dan kapasitas dari Head Queue lebih besar dari element kapasitas yang baru, maka loop

			//di dalam loop, push element dari Head Queue ke Stack dengan memanggil fungsi dequeue(Delete element Queue yang pertama)
			push(S, dequeue(Q));
		}

		if(Head(Q) == NULL){
			//Kalau setelah proses di atas Head dari Queue bernilai NULL, maka Head dan Tail dari Queue sekarang adalah element baru (pk)
			Head(Q) = pk;
			Tail(Q) = pk;
		}else{
			//Selain itu, berarti Head dari Queue sekarang adalah element terbaru (pk) dan NEXT dari pk adalah Head Queue sebelumnya
			next(pk) = Head(Q);
			Head(Q) = pk;
		}

		while(!isStackEmpty(S)){
			//Selama stack tidak kosong, maka loop

			//di dalam loop
			kapal ktemp = pop(S); //pop (delete element Top dari Stack) dan masukkan ke variable ktemp
			adr_kapal pktemp = create_element(ktemp); //buat element baru dan isinya ktemp
			next(pktemp) = Head(Q); //NEXT dari pktemp (element baru) sambungkan ke Head dari Queue
			Head(Q) = pktemp; //Head dari Queue sekarang pindah ke pktemp (element baru)
		}
	}
}

kapal dequeue(Queue &Q){
	//Fungsi untuk menghapus element Queue pertama (Head)
	kapal k;
	if(Head(Q) != NULL){
		//Kalau Head tidak NULL
		adr_kapal del = Head(Q);
		k = info(Head(Q));
		Head(Q) = next(Head(Q));
		delete del; //delete dari memory
	}
	return k;
}

void showQueue(Queue Q){
	//Menampilkan semua element Queue dari Head ke ujung (setelah Tail)
	adr_kapal curr = Head(Q);
	int i = 0;
	cout << "\t\t\tAntrean Kapal :" << endl;
	while(curr != NULL){
		i += 1;
		cout << "\t\t\t";
		cout << i << ". " << info(curr).nama << " (" << info(curr).kapasitas << " penumpang)" << endl;
		curr = next(curr);
	}
}

bool isStackEmpty(Stack S){
	//Fungsi untuk mengecek apakah Stack kosong atau tidak
	return Top(S) == NULL;
}

void createStack(Stack &S){
	//Procedure untuk inisiasi Stack
	Top(S) = NULL;
}

void push(Stack &S, kapal k){
	//Procedure memasukkan element ke Stack sebelum element Top dan Top pindah ke element baru
	adr_kapal pk = create_element(k);
	next(pk) = Top(S);
	Top(S) = pk;
}

kapal pop(Stack &S){
	//Fungsi untuk menghapus element Top dari Stack dan Top pindah ke element selanjutnya dari Top
	kapal k;
	if(!isStackEmpty(S)){
		adr_kapal del = Top(S);
		k = info(Top(S));
		Top(S) = next(Top(S));
		delete del;
	}
	return k;
}
