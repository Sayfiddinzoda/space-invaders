#include "include/render.h"

int main() {

  while (true) {
    render(5, 5, "hello world\nbye bye");
    clearScreen();
  }

  return 0;
}
