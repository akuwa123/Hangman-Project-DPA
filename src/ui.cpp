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

static void cetakTengah(int baris, const std::string& teks, int warna = WARNA_BIASA) {
    int kolom = (COLS - (int)teks.size()) / 2;
    if (kolom < 0) kolom = 0;
    cetak(baris, kolom, teks, warna);
}

static void cetakItem(int baris, int kolom, const std::string& teks, bool dipilih) {
    if (dipilih) cetak(baris, kolom, "> " + teks, WARNA_PILIH);
    else         cetak(baris, kolom, "  " + teks);
}

enum class Difficulty {
    Mudah,
    Sedang,
    Sulit,
    Hardcore
};

static std::string namaTingkat(Difficulty t) {
    switch (t) {
        case Difficulty::Mudah:    return "Mudah";
        case Difficulty::Sedang:   return "Sedang";
        case Difficulty::Sulit:    return "Sulit";
        case Difficulty::Hardcore: return "Hardcore";
    }
    return "";
}

void uiInit(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    set_escdelay(25);
    curs_set(0);

    start_color ();
    init_pair(WARNA_BIASA, COLOR_WHITE, COLOR_BLACK);
    init_pair(WARNA_PILIH, COLOR_BLACK, COLOR_CYAN);
    init_pair(WARNA_JUDUL, COLOR_CYAN, COLOR_BLACK);
    init_pair(WARNA_BENAR, COLOR_GREEN, COLOR_BLACK);
    init_pair(WARNA_SALAH, COLOR_RED, COLOR_BLACK);
    init_pair(WARNA_INFO, COLOR_YELLOW, COLOR_BLACK);
}

void uiShutdown(){
    endwin();
}
