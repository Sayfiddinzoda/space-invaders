#include "../include/render.h"
#include <ctime>
#include <cstdlib>
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
  string txt;
  srand(time(NULL));
  int top = rand()%height+1;
  srand(time(NULL));
  int left = rand()%weight+1;
  for (int i=0; i<top; i++) cout << "#\n";
  for (int i=0; i<left-(txt.size())*(weight<left+txt.size()); i++) cout << "#";
  cout << txt;
  for (int i=0; i<height-top-1; i++) cout << "#\n";
  delete[] windows_size;
}
