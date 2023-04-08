#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "people.hpp"
#include "parameters.hpp"
#include "pandemic.hpp"
#include <vector>

TEST_CASE("Setters class Parameters."){

  Parameters ps;
  
  SUBCASE("Calling setters with correct values & checking getters."){
 
  CHECK(ps.set_Alfa(0.001)== true); 
  CHECK(ps.set_Alfa(0.01) == true);
  CHECK(ps.set_Alfa(0.002) == true);

  CHECK(ps.set_Beta(0.4) == true);
  CHECK(ps.set_Beta(0.5) == true);
  CHECK(ps.set_Beta(0.7) == true);
  
  CHECK(ps.set_Gamma(0.1) == true);
  CHECK(ps.set_Gamma(0.3) == true);
  CHECK(ps.set_Gamma(0.5) == true);

  CHECK(ps.set_Mu(0.1) == true);
  CHECK(ps.set_Mu(0.3) == true);
  CHECK(ps.set_Mu(0.5) == true);


  CHECK(ps.get_Alfa() == 0.002);
  CHECK(ps.get_Beta() == 0.7);
  CHECK(ps.get_Gamma() == 0.5);
  CHECK(ps.get_Mu() == 0.5);

  ps.set_Parameters(0.003,0.3,0.4,0.6);
  CHECK(ps.get_Alfa() == 0.003);
  CHECK(ps.get_Beta() == 0.3);
  CHECK(ps.get_Gamma() == 0.4);
  CHECK(ps.get_Mu() == 0.6);
  }


  SUBCASE("Calling setter with wrong values"){ 
  CHECK(ps.set_Alfa(1) == false);
  CHECK(ps.set_Alfa(-3) == false);
  CHECK(ps.set_Alfa(0.02) == false);

  CHECK(ps.set_Beta(0) == false);
  CHECK(ps.set_Beta(1) == false);
  CHECK(ps.set_Beta(-0.2) == false);

  CHECK(ps.set_Gamma(0) == false);
  CHECK(ps.set_Gamma(-0.2) == false);
  CHECK(ps.set_Gamma(1) == false);

  CHECK(ps.set_Mu(0) == false);
  CHECK(ps.set_Mu(-0.2) == false);
  CHECK(ps.set_Mu(1) == false);
  }
}


TEST_CASE("Setters & getters class People."){

  People p;
  
  SUBCASE("Calling setters with correct values & checking getters."){
  
 
  CHECK(p.set_S(0)== true); 
  CHECK(p.set_S(200000000) == true);
  CHECK(p.set_S(450) == true);

  CHECK(p.set_I(0) == true);
  CHECK(p.set_I(200000000) == true);
  CHECK(p.set_I(120) == true);
  
  CHECK(p.set_R(0) == true);
  CHECK(p.set_R(200000000) == true);
  CHECK(p.set_R(1) == true);

  CHECK(p.set_D(0) == true);
  CHECK(p.set_D(200000000) == true);
  CHECK(p.set_D(453) == true);


  CHECK(p.get_Susceptible()==450);
  CHECK(p.get_Infected()==120);
  CHECK(p.get_Recovered()==1);
  CHECK(p.get_Deads()==453);

  CHECK(p.get_Total()==1024);

  p.set_People(1,2,3,4);
  CHECK(p.get_Susceptible()==1);
  CHECK(p.get_Infected()==2);
  CHECK(p.get_Recovered()==3);
  CHECK(p.get_Deads()==4);
  }


  SUBCASE("Calling setter with wrong values"){
 
  CHECK(p.set_S(-1)== false); 
  CHECK(p.set_S(900000000) == false);
  CHECK(p.set_S(-4) == false);

  CHECK(p.set_I(-1) == false);
  CHECK(p.set_I(900000000) == false);
  CHECK(p.set_I(-700) == false);

  CHECK(p.set_R(-1) == false);
  CHECK(p.set_R(900000000) == false);
  CHECK(p.set_R(400000000) == false);

  CHECK(p.set_D(-1) == false);
  CHECK(p.set_D(900000000) == false);
  CHECK(p.set_D(4000000000) == false);
  }
}


TEST_CASE("Testing the pandemic default constructor.") {

  People p;
  Parameters ps;
  Pandemic oggetto;

  CHECK(p.get_Susceptible() == 60000); 
  CHECK(p.get_Infected() == 40);
  CHECK(p.get_Recovered() == 0);
  CHECK(p.get_Deads() == 0);
  
  CHECK(ps.get_Alfa() == 0.001);
  CHECK(ps.get_Beta() == 0.85);
  CHECK(ps.get_Gamma() == 0.2);
  CHECK(ps.get_Mu() == 0.2);

  CHECK(oggetto.get_Time()==50);
}


TEST_CASE("Testing the pandemic constructor.") {

  People p;
  Parameters ps;
  Pandemic oggetto;

  p.set_People(300,4,5,6);
  ps.set_Parameters(0.003,0.3,0.4,0.6);
  
  CHECK(oggetto.set_Pandemic(p,ps,60)==true);
  CHECK(oggetto.set_Pandemic(p,ps,-40)==false);


  CHECK(oggetto.get_Par().get_Alfa()==0.003);
  CHECK(oggetto.get_Par().get_Beta()==0.3);
  CHECK(oggetto.get_Par().get_Gamma()==0.4);
  CHECK(oggetto.get_Par().get_Mu()==0.6);

  CHECK(oggetto.get_Population()[0].get_Susceptible()==300);
  CHECK(oggetto.get_Population()[0].get_Infected()==4);
  CHECK(oggetto.get_Population()[0].get_Recovered()==5);
  CHECK(oggetto.get_Population()[0].get_Deads()==6);

  CHECK(oggetto.get_Time()==60);

}


TEST_CASE("Testing method simulate.") {

  People p;
  Parameters ps;
  Pandemic population;

  p.set_People(5502,60,148,67);
  ps.set_Parameters(0.00362329,0.48215,0.164518,0.0183258);
  population.set_Pandemic(p, ps, 85);

  population.simulate();

  auto it=population.get_Population().begin();
  int Size=population.get_Population().size();

  bool s, i, r, d;

  for (int j=0; j<Size-1; j++){

    if ((*it).get_Susceptible() >= 0 ) {
      s = true;
    } else { s = false; }

    if ((*it).get_Infected() >= 0 ) {
      i = true;
    } else { i = false; }

    if ((*it).get_Recovered() >= 0 ) {
      r = true;
    } else { r = false; }

    if ((*it).get_Deads() >= 0 ) {
      d = true;
    } else { d = false; }
    

    CHECK (s == true);
    CHECK (i == true);
    CHECK (r == true);
    CHECK (d == true);

    it++;
  }
  
}