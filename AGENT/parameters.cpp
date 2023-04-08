#include "parameters.hpp"

#include <iostream>

// Default constructor
Parameters::Parameters() {
  this->Alfa_ = 0.001;
  this->Beta_ = 0.85;
  this->Gamma_ = 0.2;
  this->Mu_ = 0.2;
}

// Parameters class Setters
// Setter

void Parameters::set_Beta(float b) {
  if (b > 0 && b < 0.999) {
    Beta_ = b;
  }
}

void Parameters::set_Gamma(float g) {
  if (g > 0 && g <= 0.5) {
    Gamma_ = g;
  }
}

void Parameters::set_Mu(float m) {
  if (m > 0 && m <= 0.5) {
    Mu_ = m;
  }
}

// class Parameters getters
float Parameters::get_Alfa() { return Alfa_; };
float Parameters::get_Beta() { return Beta_; };
float Parameters::get_Gamma() { return Gamma_; };
float Parameters::get_Mu() { return Mu_; };