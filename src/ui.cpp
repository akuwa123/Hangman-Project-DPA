#include <ncurses.h>
#include <string>
#include "ui.hpp"

const int WARNA_BIASA = 1;
const int WARNA_PILIH = 2;
const int WARNA_JUDUL = 3;
const int WARNA_BENAR = 4;
const int WARNA_SALAH = 5;
const int WARNA_INFO = 6;

static void cetak(int baris, int kolom, const std::string& teks, int warna = WARNA_BIASA){
    attron(COLOR_PAIR(warna));
    mvprintw(baris, kolom, "%s", teks.c_str());
    attroff(COLOR_PAIR(warna));
}

static void cetakitem(int baris, const std::string& teks, int warna = WARNA_BIASA) {
    int kolom = (COLS - (int)teks.size()) / 2;
    if (kolom < 0) kolom = 0;
    cetak (baris, kolom, teks, warna);
}
