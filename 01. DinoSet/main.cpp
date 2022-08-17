#include <iostream>
#include "dinoset.h"

int main()
{
    DinoSet z;
    z.add(DinoId::stegosaurus);
    z.add(DinoId::pachycephalosaurus);
    z.add(DinoId::pteranodon);
    z.add(DinoId::tyrannosaurus);
    std::cout << z.to_string() << "\n";
    return 0;
}
