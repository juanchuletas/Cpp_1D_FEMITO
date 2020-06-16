#include <iostream>
#include <iomanip>
#include "Node.hpp"
#include "Element.hpp"
#include "Mesh.hpp"

int main()
{

    int order = 1;
    int poly = order+1;
    int Ne = 3;
    Mesh mymesh;
    mymesh.createMesh("Equal",Ne, poly);
    mymesh.displayGrid();

    return 0;
}