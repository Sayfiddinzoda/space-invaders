#include "../include/render.h"
#include <cstdlib>
#include <ctime>

int *defineSize() {
  int *arr = new int[2];
  arr[0] = 40; // width
  arr[1] = 20; // width

  return arr;
}

void render(int top, int left, std::string content) {
  int *windows_size = defineSize();
  int width = windows_size[0];
  int height = windows_size[1];
  string txt;

  for (int i = 0; i < top - 1; i++)
    cout << "#\n";

  for (int i = 0; i < left - 1; i++)
    cout << "#";

  cout << txt;

  for (int i = 0; i < height - top - 1; i++)
    cout << "#\n";

  delete[] windows_size;
}
