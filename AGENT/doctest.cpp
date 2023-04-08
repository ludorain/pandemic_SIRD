#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "parameters.hpp"
#include "pandemic.hpp"

#include <vector>
#include <random> 


TEST_CASE("Setters & getters class Parameters.") {

  Parameters ps;
  Parameters ps1;


  SUBCASE("Calling setters with correct values & checking getters."){
  
  ps.set_Beta(0.2);
  CHECK(ps.get_Beta() == doctest::Approx(0.2));

  ps.set_Gamma(0.1);
  CHECK(ps.get_Gamma() == doctest::Approx(0.1));

  ps.set_Mu(0.1);
  CHECK(ps.get_Mu() == doctest::Approx(0.1));
  
  }

  SUBCASE("Checking default constructor."){
  
  CHECK(ps1.get_Alfa() == doctest::Approx(0.001));
  CHECK(ps1.get_Beta() == doctest::Approx(0.85));
  CHECK(ps1.get_Gamma() == doctest::Approx(0.2));
  CHECK(ps1.get_Mu() == doctest::Approx(0.2));
  }
}


TEST_CASE ("Testing class Pandemic.") {

  Pandemic pan;
  Pandemic pan1;
  Pandemic evolving;
  Pandemic evolving2;
  Pandemic neighbours;
  Parameters ps;

  
  SUBCASE("Calling setters with correct values & checking getters."){

  pan.set_I(100);
  CHECK(pan.get_I()==100);

  pan.set_Side(30);
  CHECK(pan.get_Side()==30);
  }
  

  SUBCASE("Checking default constructor."){
  
  CHECK(pan1.get_I() == 50);
  CHECK(pan1.get_Side() == 50);
  }


  SUBCASE("Reading and changing person's state"){ 

  CHECK(evolving.Reading_cell(1,1) == Person::Susceptible);

  evolving.Writing_cell(1,1) = Infected;
  CHECK(evolving.Reading_cell(1,1) == Person::Infected);

  evolving.Writing_cell(1,3) = Person::Recovered;
  CHECK(evolving.Reading_cell(1,3) == Person::Recovered); 

  evolving.Writing_cell(5,1) = Person::Dead;
  CHECK(evolving.Reading_cell(5,1) == Person::Dead);
  }


  SUBCASE("Testing evolution") {

  evolving.Writing_cell(4,6) = Person::Infected;
  evolving.Writing_cell(3,5) = Person::Recovered;
  evolving.Writing_cell(5,3) = Person::Dead;

  evolving = Pandemic::evolve(evolving, ps);

  CHECK(evolving.Reading_cell(4,6) != Person::Susceptible);

  CHECK(evolving.Reading_cell(3,5) != Person::Susceptible);
  CHECK(evolving.Reading_cell(3,5) != Person::Infected);
  CHECK(evolving.Reading_cell(3,5) != Person::Dead);

  CHECK(evolving.Reading_cell(5,3) != Person::Susceptible);
  CHECK(evolving.Reading_cell(5,3) != Person::Recovered);
  CHECK(evolving.Reading_cell(5,3) != Person::Infected);
  }


  SUBCASE("Setting the initial grid by calling the member function start().") {
  
  int l = 50;
  evolving2.set_Side(l);
  int infected = 90;


  evolving2 = Pandemic::start(evolving2, infected);
  
  int check = 0;

  for (int r = 0 ; r < l ; r++ ) {   
  
    for (int c = 0 ; c < l ; c++) {

      if (evolving2.Reading_cell(r,c) == Person::Infected) 
      {check++;}
    }
  }
  
  CHECK(check == 90);
  }
  
  SUBCASE("Setting the initial grid by calling the member function start().") {
  int l = 40;
  evolving2.set_Side(l);
  int infected = 10;


  evolving2 = Pandemic::start(evolving2, infected);
  
  int check = 0;

  for (int r = 0 ; r < l ; r++ ) {   
  
    for (int c = 0 ; c < l ; c++) {

      if (evolving2.Reading_cell(r,c) == Person::Infected) 
      {check++;}
    }
  }
  
  CHECK(check == 10);

  }



}

