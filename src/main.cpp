#include <iostream>
#include "../include/background.h"
#include "../include/file.h"


using namespace art;

int main(){

     // Read file
     File file("scene.json");
     std::unique_ptr<Background>  b = file.read();

     file.save_ppm(*b.get());
}