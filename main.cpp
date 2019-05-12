#include <iostream>

#include "Main.h"
#include <string>
#include <vector>

using namespace std ;

int main(int argc, char *argv[]) {
    boot::Main().main(stoi(argv[1])) ;
    return 0;
}
