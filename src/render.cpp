#include "../include/render.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

int *defineSize() {
  int *arr = new int[2];
  arr[0] = 80; // width
  arr[1] = 30; // width

  
               

  return arr;
}

void render(int top, int left, std::string content) {
  int *windows_size = defineSize();
  int width = windows_size[0];
  int height = windows_size[1];

  // code goes here

  delete[] windows_size;
}
