#include <stdio.h>

int balance = 150500000;  // Balance in ATM (Jumlah saldo yang tertera dalam ATM)

void login() {
     int pin = 111002;
    int inputPin;
	printf("Selamat Datang di ATM Tengku Bersaudara");
	printf("\nSilahkan Login Terlebih Dahulu\n");
	printf(">>>>>>>*****<<<<<<<\n");
    for (int i = 0; i < 3; i++) {
        printf("\nMasukkan PIN ATM Anda: ");
        scanf("%i", &inputPin);

        if (inputPin == pin) {
            printf("PIN Anda Benar\n");
            menu();
            return 0;
        }
        else {
            printf("PIN Anda Salah\n");
        }
    }

    printf("\nAnda telah Memasukkan PIN yang Salah Sebanyak 3 Kali.\n");
    printf("Anda Tidak Bisa Login Kembali, Silahkan Hubungi CS ATM Tengku Bersaudara\n");
    return 0;
}

void cek_saldo() {
    printf("Anda Memiliki Saldo Sebesar: %d\n", balance);
}

void penarikan() {
    int amount;
    printf("Masukkan Jumlah Penarikan: ");
    scanf("%d", &amount);

    if (amount > balance) {
        printf("Saldo Anda Tidak Mencukupi.\n");
    } else {
        balance -= amount;
        printf("Penarikan Sebesar %d Berhasil.\n", amount);
        printf("Saldo Anda Saat Ini Adalah: %d\n", balance);
    }
}

void transfer() {
    int amount;
    printf("Masukkan Jumlah Transfer: ");
    scanf("%d", &amount);

    if (amount > balance) {
        printf("Saldo Tidak Mencukupi.\n");
    } else {
        balance -= amount;
        printf("Transfer Sebesar %d Berhasil.\n", amount);
        printf("Saldo Anda Saat Ini: %d\n", balance);
    }
}

void topup()
{
	int pilihan;
	printf("\nMenu Top UP");
	printf("\n=====*****=====");
	printf("\n1. Shopee");
	printf("\n2. Dana");
	printf("\n3. Briva");
	printf("\n4. Menu Utama");
	printf("\n Silahkan pilih <1-4> :");
	scanf("%i", &pilihan);
	
	switch (pilihan) 
	{
	
		case 1 :
			shopee();
			break;
		case 2 :
			dana();
			break;
		case 3 :
			briva();
			break;
		case 4 :
			menu();
			break;
	}

}


void shopee()
{
	
	int amount;
	char nomor [16];
	printf("\nTop UP Shopee");
    printf("\nMasukkan Besar Nominal Top Up: ");
    scanf("%i", &amount);

	printf("Masukkan Nomor Tujuan: ");
    scanf("%s", &nomor);
    
    if (amount > balance) {
        printf("Saldo Tidak Mencukupi.\n");
    } else {
        balance -= amount;
        printf("\nTop up sebesar %d berhasil Ke Nomor %s.\n", amount,nomor);
        
		printf("Saldo Anda saat ini: %d\n", balance);
    } 
}


void dana()
{
	
	int amount;
	char nomor [16];
	printf("\nTop UP Dana");
    printf("\nMasukkan besar Nominal Top Up: ");
    scanf("%i", &amount);
	
	printf("Masukkan Nomor Tujuan: ");
    scanf("%s", &nomor);
	
    if (amount > balance) {
        printf("Saldo Tidak Mencukupi.\n");
    } else {
        balance -= amount;
        printf("\nTop up Sebesar %d Berhasil Ke Nomor %s.\n", amount, nomor);
        
		printf("Saldo Anda saat ini: %d\n", balance);
    } 
}


void briva()
{
	
	int amount;
	char nomor [16];
	printf("\nTop UP Briva");
    printf("\nMasukkan Besar Nominal Top Up: ");
    scanf("%i", &amount);
    
    printf("\nMasukkan Nomor Tujuan: ");
    scanf("%s", &nomor);

    if (amount > balance) {
        printf("Saldo Tidak mencukupi.\n");
    } else {
        balance -= amount;
        printf("\nTop up Sebesar %d Berhasil Ke Nomor %s.\n",amount,nomor);
        
		printf("Saldo Anda Saat Ini: %d\n", balance);
    } 
}

void logout() {
    printf("Logout Berhasil.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n=== Menu ATM Tengku Bersaudara ===\n");
        printf("1. Cek Saldo\n");
        printf("2. Penarikan\n");
        printf("3. Transfer\n");
        printf("4. Top up Saldo\n");
        printf("5. Logout\n");
        printf("Pilih menu (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                cek_saldo();
                break;
            case 2:
                penarikan();
                break;
            case 3:
                transfer();
                break;
            case 4:
            	topup();
            	break;
            case 5:
                logout();
                return 0;
            default:
                printf("Pilihan Unvalid.\n");
        }
    }
}

int main() {
    login();
    return 0;
}
