
#include <cmath>
#include <cstring>  //mi serve  per line
#include <ctime>    // ci serve per la funzione time che sta dentro al random
#include <fstream>  //serve per usare ifs
#include <iostream>
#include <typeinfo>
#include <limits>

#include "parameters.hpp"
#include "people.hpp"
#include "pandemic.hpp"
#include "ini.h"

// Function for double random generation 
double fRand(double fMin, double fMax) 
{
  double f = static_cast<double>(std::rand()) / RAND_MAX;
  return fMin + f * (fMax - fMin);
}

//Function for reading integers
bool readInt(int &x) {
  std::cin >> x;
  if(std::cin.fail()||std::cin.peek()!='\n')
  {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return false;
  }
  return true;
}

int main() {
  //Assignment variables
  int s, i, r, d;   
  int num;
  double a, b, g, m;
  int t;

  //Support variables
  char data;
  char vax;
  bool control; 

  //Creating objects
  People p;
  Parameters ps;
  Pandemic simulation;
  

  std::cout << "Would you like to insert data from file, from standard input "
               "or run a random simulation? [F,S,R] \n";
  std::cin >> data;

  while (data != 'F' && data != 'S' && data != 'R') {
    std::cout << "Invalid character, try again. \n";
    std::cin >> data;
  }

  if (data == 'F') {
    std::cout << "You've choosen data from file. \n";
    
    // Create a file instance & create a structure that will hold data
    mINI::INIFile file("data.ini");
    mINI::INIStructure ini;

    // Read the file
    file.read(ini);
    
    // read values ini.get("section").get("key")
    // stoi() = string to int
    // stod() = string to double
    s = std::stoi(ini.get("PEOPLE").get("Susceptibles"));
    i = std::stoi(ini.get("PEOPLE").get("Infected"));
    r = std::stoi(ini.get("PEOPLE").get("Recovered"));
    d = std::stoi(ini.get("PEOPLE").get("Dead"));
    a = std::stod(ini.get("PARAMETERS").get("Alfa"));
    b = std::stod(ini.get("PARAMETERS").get("Beta"));
    g = std::stod(ini.get("PARAMETERS").get("Gamma"));       
    m = std::stod(ini.get("PARAMETERS").get("Mu"));
    t = std::stoi(ini.get("PARAMETERS").get("Time"));      
    
    //Checking and assigning variables values to the People object
    control = p.set_S(s);

    if (control == false) {
      std::cout << "Susceptible value out of range, initialized to default (60000). \n";
    }

    control = p.set_I(i);

    if (control == false) {
      std::cout << "Infected value out of range, initialized to default (40). \n";
    }

    try {
    
    if(p.get_Susceptible()==0 && p.get_Infected()==0){
    throw std::runtime_error("Error");
  }
    }
    catch(std::runtime_error& e) {
    std::cerr<<"The simulation won't do anything. Program interrupted. '\n'";
    exit(0);
    }

    
    control = p.set_R(r);

    if (control == false) {
      std::cout << "Recovered value out of range, initialized to default (0). \n";
    }

    control = p.set_D(d);

    if (control == false) {
      std::cout << "Infected value out of range, initialized to default (0). \n";
    }

    //Checking and assigning variables values to the Parameters object
    if(a==0){
      ps.set_Zero();
    } else {
    control = ps.set_Alfa(a);

      if (control == false){
        std::cout << "Vaccination parameter out of range, initialized to default (0.001). \n";
      } 
    }    

    control = ps.set_Beta(b);

    if (control == false){
      std::cout << "Infectivity parameter out of range, initialized to default (0.85). \n";
    }

    control = ps.set_Gamma(g);

    if (control == false){
      std::cout << "Recovery parameter out of range, initialized to default (0.2). \n";
    }

    control = ps.set_Mu(m);
    
    if (control == false){
      std::cout << "Death parameter out of range, initialized to default (0.2). \n";
    }

    try {
      char e = 'e';
      int er = 2;
      if(ps.get_Gamma()==0.5 && ps.get_Mu()==0.5) {
        throw (e);
      } 

      if (ps.get_Gamma()+ps.get_Mu()>ps.get_Beta()){
        throw (er);
      }

    }

    catch(char e) {
      std::cerr<<"------------. \n";
      exit(0);
    }

    catch(int er) {
      std::cerr<<"The simulation won't do anything. Program interrupted. \n";
      exit(0);
    }


    //Pandemic simulation   
    control = simulation.set_Pandemic(p, ps, t);

    if (control == false){
      std::cout << "Time out of range, initialized to default (50 days). \n";
    }

    simulation.simulate();
    simulation.print();


  //STANDARD INPUT
  } else if (data == 'S') { 
  
    std::cout << "Great, you've choosen Standard Input, please insert: \n";
    std::cout << "The number of initial  \n";
    
  //Checking and assigning variables values to the People object
    std::cout << "Susceptible [range 0-200'000'000]: ";

    if (readInt(s)) {
      
      control = p.set_S(s);

      if (control == false) {
        std::cout << "Susceptible value out of range, initialized to default (60000). \n";
      } 
    } else {
      std::cout << "You entered a non-integer value, susceptible value initialized to default (60000). \n";
    }
          
    std::cout << "Infected [range 0-200'000'000]: ";
    
    if (readInt(i)) {
        control = p.set_I(i);

        if (control == false) {
          std::cout << "Infected value out of range, initialized to default (40). \n";
        } 
      } else {
        std::cout << "You entered a non-integer value, susceptible value initialized to default (40). \n";
      }
  

    try {
    
    if(p.get_Susceptible()==0 && p.get_Infected()==0){
    throw std::runtime_error("Error");
  }
    }
    catch(std::runtime_error& e) {
    std::cerr<<"The simulation won't do anything. Program interrupted. '\n'";
    exit(0);
    }

    std::cout << "Recovered [range 0-200'000'000]: ";

    if (readInt(r)) {
        control = p.set_R(r);

        if (control == false) {
          std::cout << "Recovered value out of range, initialized to default (0). \n";
        } 
      } else {
        std::cout << "You entered a non-integer value, susceptible value initialized to default (0). \n";
      }
   

    std::cout << "Deaths [range 0-200'000'000]: ";

    if (readInt(d)) {
        control = p.set_D(d);

        if (control == false) {
          std::cout << "Deaths value out of range, initialized to default (0). \n";
        } 
      } else {
        std::cout << "You entered a non-integer value, susceptible value initialized to default (0). \n";
      }

    //Checking and assigning variables values to the Parameters object
    std::cout << "Do you want vaccination? [y/n] \n";
    std::cin >> vax;

    while (vax != 'y' && vax != 'n') {
    std::cout << "Invalid char, try again. \n";
    std::cin >> vax;  }

    if (vax == 'y') {
      std::cout << "Rate vaccination [range 0.001-0.01]: ";
      std::cin >> a;
      
      control = ps.set_Alfa(a);
      if (control == false){
        std::cout << "Vaccination parameter out of range, initialized to default (0.001). \n";
      } 
    } else { ps.set_Zero();}

    std::cout << "Infection probability [range 0-1]: ";
    std::cin >> b;
    control = ps.set_Beta(b);
    if (control == false){
      std::cout << "Infection parameter out of range, initialized to default (0.85). \n";
    }

    std::cout << "Recovery probability [range 0-0.5]: ";
    std::cin >> g;
    control = ps.set_Gamma(g);
    if (control == false){
      std::cout << "Recovery parameter out of range, initialized to default (0.2). \n";
    }

    std::cout << "Death probability [range 0-0.5]: ";
    std::cin >> m;
    control = ps.set_Mu(m);
    if (control == false){
      std::cout << "Death parameter out of range, initialized to default (0.2). \n";
    }

    try {
    char e = 'e';
    int er = 2;
    if(ps.get_Gamma()==0.5 && ps.get_Mu()==0.5){
    throw (e);
    } 

    if (ps.get_Gamma()+ps.get_Mu()>ps.get_Beta()){
    throw (er);
    }
    }
    catch(char e) {
    std::cerr<<"The simulation won't do anything. Program interrupted. \n";
    exit(0);
    }
    catch(int er) {
    std::cerr<<"The simulation won't do anything. Program interrupted. \n";
    exit(0);
    }

    std::cout << "Simulation time \n";
    std::cin >> t;

   
    control = simulation.set_Pandemic(p, ps, t);

    if (control == false){
      std::cout << "Time out of range, initialized to default (50 days). \n";
    }
    simulation.simulate();
    simulation.print();


  } else if (data == 'R') {
    
    People p;
    Parameters ps;
    std::cout
        << "Great, you've choosen Random generation, here's your datas: \n ";

    // Generate random seed for rand()
    std::srand(time(NULL));

    // Time elapse
    t = 30 + (std::rand() % 101);

    // Generate people for simulation
    s = 400000 + (std::rand() % 400000);  
    i = std::rand() % 400000;         
    r = std::rand() % 200000;         
    d = std::rand() % 200000;         

    // Generate parameters for simulation    
    a = fRand(0.000, 0.01);  
    b = fRand(0.400, 0.900);  
    g = fRand(0.001, 0.200);  
    m = fRand(0.001, 0.100);

    // Assign random values to class object and print them
    p.set_People(s, i, r, d);    
    ps.set_Parameters(a, b, g, m);
    num = p.get_Total();

    std::cout << "The initial persons are: \n";
    std::cout << "Susceptible = " << s << '\n' << "Infected = " << i << '\n';
    std::cout << "Recovered = " << r << '\n' << "Dead = " << d << '\n';
    std::cout << "Total people =" << num << '\n';

    std::cout << "The initial parameters are: \n";
    std::cout << "alfa = " << a << '\n' << "beta = " << b << '\n';
    std::cout << "gamma = " << g << '\n' << "mu = " << m << '\n';
    std::cout << "Simulation time= " << t << '\n';

    // Starting proper simulation
    
    control = simulation.set_Pandemic(p, ps, t);

    simulation.simulate();
    simulation.print();
  }
}



