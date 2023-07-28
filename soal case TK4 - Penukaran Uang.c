//
// Created by masad on 7/26/2023.
//
// test cases are available in "./soal case TK4 - Penukaran Uang testing inputs.txt"

#include <stdio.h>
#include <conio.h>

typedef union QtyUangAsal_u {
  int qty_100K;
  int qty_50K;
} UA_Qty;

typedef union QtyUangKembalian_u {
  int qty_1000;
  int qty_500;
  int qty_100;
  int qty_50;
} UK_Qty;

typedef enum TipeUangAsal_e {
  NOMINAL_100K = 1,
  NOMINAL_50K,
} TIPE_UANG_ASAL;

typedef enum TipeUangKembalian_e {
  NOMINAL_1000 = 1,
  NOMINAL_500,
  NOMINAL_100,
  NOMINAL_50,
} TIPE_UANG_KEMBALIAN;

typedef struct UangAsal_u {
  TIPE_UANG_ASAL tipe;
  UA_Qty qty;
} UA;

typedef struct UangKembali_u {
  TIPE_UANG_KEMBALIAN tipe;
  UK_Qty qty;
} UK;

int get_nominal_uang_asal(TIPE_UANG_ASAL asal);
int get_nominal_uang_kembalian(TIPE_UANG_KEMBALIAN kembalian);
int hitung_qty_kembalian(float jumlah_kembalian, int tipe);
int get_asal_qty(UA asal);
int get_kembalian_qty(UK kembalian);

int main() {
  printf("\n\n");
  printf("\t===== TIPE NOMINAL UANG ASAL =====\n");
  printf("\t\t[1] Rp. 100.0000 \n");
  printf("\t\t[2] Rp. 50.0000 \n");
  
  UA uang_asal;
  
  printf("\tMohon pilih tipe uang asal anda: ");
  scanf("%d", &uang_asal.tipe);
  
  printf("\tJumlah lembar uang anda: ");
  
  switch (uang_asal.tipe) {
    case NOMINAL_100K:
      scanf("%d", &uang_asal.qty.qty_100K);
      break;
    case NOMINAL_50K:
      scanf("%d", &uang_asal.qty.qty_50K);
      break;
    default:
      printf("\n\tMohon maaf, pilihan tidak dikenal. Mohon untuk ulangi transaksi\n\nTekan apa saja untuk keluar...\n");
      getch();
      
      return 0;
  }
  
  UK uang_kembalian;
  
  printf("\n\t===== TIPE NOMINAL UANG KEMBALIAN =====\n");
  printf("\t\t[1] Rp. 1.000 \n");
  printf("\t\t[2] Rp. 500 \n");
  printf("\t\t[3] Rp. 100 \n");
  printf("\t\t[4] Rp. 50 \n");
  printf("\tIngin dikembalikan dalam nominal apa? ");
  
  scanf("%d", &uang_kembalian.tipe);
  
  
  float jumlah_uang_asal = (float) (get_nominal_uang_asal(uang_asal.tipe) * get_asal_qty(uang_asal));
  float potongan_komisi_10p = jumlah_uang_asal * .1;
  float jumlah_uang_kembalian = jumlah_uang_asal - potongan_komisi_10p;
  
  switch (uang_kembalian.tipe) {
    case NOMINAL_1000:
      uang_kembalian.qty.qty_1000 = hitung_qty_kembalian(jumlah_uang_kembalian, uang_kembalian.tipe);
      break;
    case NOMINAL_500:
      uang_kembalian.qty.qty_500 = hitung_qty_kembalian(jumlah_uang_kembalian, uang_kembalian.tipe);
      break;
    case NOMINAL_100:
      uang_kembalian.qty.qty_100 = hitung_qty_kembalian(jumlah_uang_kembalian, uang_kembalian.tipe);
      break;
    case NOMINAL_50:
      uang_kembalian.qty.qty_50 = hitung_qty_kembalian(jumlah_uang_kembalian, uang_kembalian.tipe);
      break;
    default:
      printf("\n\tMohon maaf, pilihan tidak dikenal. Mohon untuk ulangi transaksi\n\nTekan apa saja untuk keluar...\n");
      getch();
      
      return 0;
  }
  
  printf("\n\t======================================================================\n\n");
  
  printf("\t%-27s = Rp. %24d x %d\n\n", "Uang asal", get_nominal_uang_asal(uang_asal.tipe), get_asal_qty(uang_asal));
  
  printf("\t%-27s = Rp. %24.2f\n", "Total asal", jumlah_uang_asal);
  printf("\t%-27s = Rp. %24.2f\n", "Komisi jasa penukaran (10%)", potongan_komisi_10p);
  printf("\t%-27s   ------------------------------------ -\n", "");
  printf("\t%-27s = Rp. %24.2f\n", "Total kembalian", jumlah_uang_kembalian);
  
  printf("\n\t======================================================================\n\n");
  
  printf(
    "\tUang dikembalikan dalam bentuk Rp.%d -an sebanyak %d lembar\n\n\n",
    get_nominal_uang_kembalian(uang_kembalian.tipe),
    get_kembalian_qty(uang_kembalian)
  );
  
  
  getch();
  
  return 0;
}


int get_nominal_uang_asal(TIPE_UANG_ASAL asal) {
  switch (asal) {
    case NOMINAL_100K:
      return 100000;
    case NOMINAL_50K:
      return 50000;
    default:
      return 0;
  }
}

int get_nominal_uang_kembalian(TIPE_UANG_KEMBALIAN kembalian) {
  switch (kembalian) {
    case NOMINAL_1000:
      return 1000;
    case NOMINAL_500:
      return 500;
    case NOMINAL_100:
      return 100;
    case NOMINAL_50:
      return 50;
    default:
      return 0;
  }
}

int hitung_qty_kembalian(float jumlah_kembalian, int tipe){
  return (int) (jumlah_kembalian / get_nominal_uang_kembalian(tipe));
}

int get_asal_qty(UA asal){
  switch (asal.tipe) {
    case NOMINAL_100K:
      return asal.qty.qty_100K;
    case NOMINAL_50K:
      return asal.qty.qty_50K;
    default:
      return 0;
  }
}

int get_kembalian_qty(UK kembalian){
  switch (kembalian.tipe) {
    case NOMINAL_1000:
      return kembalian.qty.qty_1000;
    case NOMINAL_500:
      return kembalian.qty.qty_500;
    case NOMINAL_100:
      return kembalian.qty.qty_100;
    case NOMINAL_50:
      return kembalian.qty.qty_50;
    default:
      return 0;
  }
}

