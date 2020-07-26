#include <iostream>
#include <iomanip>
#include "Node.hpp"
#include "Element.hpp"
#include "Mesh.hpp"
#include "read_data.hpp"

int main(int argc, char **argv)
{
    std::string atom,potential,mesh;
    int angular,Ne,order;
    double r0,rc;
    int good = read_data(argv,potential,atom,angular,Ne,r0,rc,order,mesh);
    std::cout<<"Your initial data:"<<std::endl;
    std::cout<<"Atom: "<<atom<<std::endl;
    std::cout<<"Angular Momentum (l): "<<angular<<std::endl;
    std::cout<<"Mesh: "<<mesh<<std::endl;
    //Mesh mymesh;
    //mymesh.createMesh("Equal",Ne, );
    //mymesh.displayGrid();


    return 0;
}