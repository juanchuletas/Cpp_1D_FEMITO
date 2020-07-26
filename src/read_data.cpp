
#include <iostream>
#include <fstream>

int read_data(char *input_name[],std::string &potential,std::string &atom, int &angular,int &Ne, double &r0, double &rc,int &order, std::string &mesh)
{
    std::ifstream inputfile;
    std::string filename="input.dat";
    inputfile.open(input_name[1]);

    if(!inputfile.is_open())
    {
        return 1;
    }
    std::string line;
    
    getline(inputfile,line,':');
    inputfile >> potential;
    
    inputfile>>std::ws;
    getline(inputfile,line,':');
    inputfile >> atom;
   
    inputfile>>std::ws;
    getline(inputfile,line,':');
    inputfile >> angular;
   
    inputfile>>std::ws;
    getline(inputfile,line,':');
    inputfile >> Ne;
   
    inputfile>>std::ws;
    getline(inputfile,line,':');
    inputfile >> r0;
    
    inputfile>>std::ws;
    getline(inputfile,line,':');
    inputfile >> rc;
    
    inputfile>>std::ws;
    getline(inputfile,line,':');
    inputfile >> order;
    
    inputfile>>std::ws;
    getline(inputfile,line,':');
    inputfile >> mesh;
    

    inputfile.close();

    return 0;
}