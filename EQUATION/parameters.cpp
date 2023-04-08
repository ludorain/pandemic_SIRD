#include "parameters.hpp"
#include <iostream>

// Default constructor
Parameters::Parameters() {
  this->Alfa_ = 0.001;
  this->Beta_ = 0.85;
  this->Gamma_= 0.2;
  this->Mu_ = 0.2;
}

// Parameters class Setters
//Setter with control
bool Parameters::set_Alfa(double a) {
    
   if (a >= 0.001 && a <= 0.01) {
      Alfa_ = a;
      return true;
    } else {return false;}   
}

void Parameters::set_Zero(){
  Alfa_=0;
}

bool Parameters::set_Beta(double b) {
  if(b>0 && b<1){
    Beta_ = b;
    return true;
  } else {return false;}
  }

bool Parameters::set_Gamma(double g) {
  
  if (g > 0 && g <= 0.5) {
    Gamma_=g;
    return true;
  } else {return false;}
}

bool Parameters::set_Mu(double m) {
  if (m > 0 && m <= 0.5) {
    Mu_=m;
    return true;
  } else {return false;}
}  
 

//Setter without control
void Parameters::set_Parameters(double a, double b, double g, double u) {
  Alfa_ = a;
  Beta_ = b;
  Gamma_ = g;
  Mu_ = u;
}

// class Parameters getters
double Parameters::get_Alfa() { return Alfa_; };
double Parameters::get_Beta() { return Beta_; };
double Parameters::get_Gamma() { return Gamma_; };
double Parameters::get_Mu() { return Mu_; };