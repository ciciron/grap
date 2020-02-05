#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

int main(int argc, char *argv[])
{
    Display *ourDisplay;
    ourDisplay = XOpenDisplay(NULL);
    /* Получим предварительные сведения */
    auto ourScreen = DefaultScreen(ourDisplay);          // Экран по-умолчанию
    auto rootWindow = RootWindow(ourDisplay, ourScreen); // Корневое окно
    auto bgcolor = WhitePixel(ourDisplay, ourScreen);    // Белый цвет экрана

    /* Открываем окно */
    auto myWindow = XCreateSimpleWindow(ourDisplay, rootWindow, 100, 100, 320, 200, 0, 0, bgcolor);

    /* Делаем окно видимым */
    XMapWindow(ourDisplay, myWindow);

    /* Все сформированные команды принудительно сбрасываем на сервер */
    XFlush(ourDisplay);

    /* Спим 5 секунд */
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(13s);

    /* Уничтожаем окно */
    XDestroyWindow(ourDisplay, myWindow);

    /* Закрываем соединение с сервером */
    XCloseDisplay(ourDisplay);

    return 0;
}