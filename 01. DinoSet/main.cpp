#include <iostream>
#include "dinoset.h"

int main()
{
    DinoSet z;
    z.add(DinoId::stegosaurus);
    z.add(DinoId::pachycephalosaurus);
    z.add(DinoId::pteranodon);
    z.add(DinoId::stegosaurus);
    z.add(DinoId::tyrannosaurus);
    std::cout << "z = " << z.to_string() << "\n";
    std::cout << "z.size() = " << z.size() << "\n";

    DinoSet x;
    x.add(DinoId::procompsognathus);
    x.add(DinoId::stegosaurus);
    std::cout << "x = " << x.to_string() << "\n";
    std::cout << "x.size() = " << x.size() << "\n";

    DinoSet w = x + z;
    std::cout << "w = " << w.to_string() << "\n";
    std::cout << "w.size() = " << w.size() << "\n";

    return 0;
}
