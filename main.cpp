#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <fstream>
#include <chrono>
#include <ctime>
#include "Classes/BufferPool.h"
#include "Classes/Block.h"
#include "Classes/Page.h"
#include "Classes/Frame.h"
#include "Classes/BufferManager.h"


int main() {
    BufferManager buffer_manager(3);

    // Solicitar páginas
    Frame* frame1 = buffer_manager.requestPage(1 );
    Frame* frame2 = buffer_manager.requestPage(2);
    Frame* frame3 = buffer_manager.requestPage(3);
    std::cout << "------------------------------------------>primero\n";
    buffer_manager.showFrames();

    // Liberar páginas
    buffer_manager.releasePage(1, true);  // Página 1 marcada como sucia
    buffer_manager.releasePage(2, false); // Página 2 no marcada como sucia
    std::cout << "------------------------------------------>primero\n";
    buffer_manager.showFrames();

    // Solicitar otra página para provocar un reemplazo
    Frame* frame4 = buffer_manager.requestPage(4);
    std::cout << "------------------------------------------>primero\n";
    buffer_manager.showFrames();

    // Liberar más páginas y hacer más reemplazos
    buffer_manager.releasePage(3, true);  // Página 3 marcada como sucia
    buffer_manager.releasePage(4, false); // Página 4 no marcada como sucia
    std::cout << "------------------------------------------>primero\n";
    buffer_manager.showFrames();

    Frame* frame5 = buffer_manager.requestPage(5);
    std::cout << "------------------------------------------>primero\n";
    buffer_manager.showFrames();
    frame5->showPage();

    buffer_manager.requestPage(6);
    buffer_manager.requestPage(2);
    buffer_manager.requestPage(5);
    buffer_manager.requestPage(9);
    Frame* mainFrame;
    // menú para solicitar páginas, liberar páginas, mostrar páginas y salir



    return 0;
}