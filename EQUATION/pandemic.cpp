#include "people.hpp"
#include "parameters.hpp"
#include "pandemic.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

//Default constructor
Pandemic::Pandemic() {

  People p;
  Parameters ps;

  Population_.push_back(p);
  this->Par_ = ps;
  this->Time_ = 50;
  
}

//Class setter
bool Pandemic::set_Pandemic(People p, Parameters ps, int t){
  
  Population_[0] = p;
  this->Par_ = ps;
  if(t<0){
    return false;
  } else { 
    Time_ = t;
    return true;
  }
}

//Class getter
Parameters Pandemic::get_Par()
{
  return Par_;
}

std::vector<People> Pandemic::get_Population()
{
  return Population_;
}

int Pandemic::get_Time()
{
  return Time_;
}

//Evolution
void Pandemic::simulate(){

  People now = Population_[0];
  People next = now; 
  double S0= now.S_;
  double a = Par_.get_Alfa();
  double b = Par_.get_Beta();
  double g = Par_.get_Gamma();
  double m = Par_.get_Mu();

  double t = Time_;
  int const N = now.get_Total();

  double s = now.S_;
  double i = now.I_;
  double r = now.R_;
  double d = now.D_;
  
  for (int j = 0; j < t; j++) {

    s += ((-now.S_ * now.I_ * b) / N - a * S0); 
    next.S_ = s;

    if(next.S_>0) {

      i += ((b * now.S_ * now.I_ )/ N - g * now.I_ - m * now.I_);
      next.I_ = i;

      r += (g * now.I_ + a * S0);
      next.R_ = r;

      d += m * now.I_;
      next.D_ = d; 

      if (i<1) {
        i=0;
      }

    } else {

      s = 0;
      next.S_ = 0;
      
      r += now.S_ + g * now.I_;
      next.R_ = r;

      i += - g * now.I_ - m * now.I_;
      next.I_ = i;

      d += m * now.I_;
      next.D_ = d;

      if (i<1) {
        i=0;
      }

    }
  
    double dice;
    double fract_s, int_s;
    fract_s = std::modf(s, &int_s);
    double fract_i, int_i;
    fract_i = std::modf(i, &int_i);
    double fract_r, int_r;
    fract_r = std::modf(r, &int_r);
    double fract_d, int_d;
    fract_d = std::modf(d, &int_d);
    double sum = fract_s + fract_i + fract_r + fract_d;


    int ghost = N-next.get_Total();
    
    std::srand(time(NULL));

    for (int i = 0; i<ghost; i++) {

      dice = static_cast<double>(std::rand()) / RAND_MAX;

      if (dice>=0 && dice<fract_s/sum){
        next.S_+=1 ; 
      } else if (dice<(fract_s+ fract_i)/sum) {
        next.I_+=1 ; 
      } else if (dice<(fract_s+ fract_i+fract_r)/sum) { 
        next.R_+=1 ;
      } else { 
        next.D_+=1 ; 
      }

    }

    Population_.push_back(next);
    now=next;

    if(next.S_ == 0 && next.I_ == 0){ 
      break;
    }    

  }
} 

void Pandemic::print(){
    auto it=Population_.begin();
    int Size=Population_.size();
    
    std::cout << "Time    " << "S       " << "I     " << "R     " << "D   " << "Total \n" ;
    for (int j=0; j<Size; j++){
      std::cout<< "Day " << j << ": " << (*it).S_ << " || " << (*it).I_ << " || " << (*it).R_ << " || " << (*it).D_ << " || " << (*it).S_ + (*it).I_ + (*it).R_ + (*it).D_ <<'\n';
      it++;
    }

    if (Size<Time_) {
      std:: cout << "The simulation ended after " << Size << " days. \n";
    }
}