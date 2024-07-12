#include "../include/render.h"
#include <cstdlib>

#if defined(_WIN32) || defined(_WIN64)
#include <window.h>

int *defineSize() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  int *arr = new int[2];

  arr[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1; // width
  arr[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // height

  return arr;
}

void clearScreen(){
  std::system("cls");
}

#else
#include <sys/ioctl.h>
#include <unistd.h>

int *defineSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  int *arr = new int[2];

  arr[0] = w.ws_col; // width
  arr[1] = w.ws_row; // height

  return arr;
}



void clearScreen(){
  std::system("clear");
}

#endif

void render(int top, int left, std::string content) {
  int *windows_size = defineSize();
  int width = windows_size[0];
  int height = windows_size[1];
  string txt;

  for (int i = 0; i < top - 1; i++)
    cout << "#\n";

  for (int i = 0; i < left - 1; i++)
    cout << "#";

  cout << content;

  for (int i = 0; i < height - top - 1; i++)
    cout << "#\n";

  delete[] windows_size;
}
