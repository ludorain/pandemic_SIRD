#include "pandemic.hpp"

#include <iostream>
#include <random>

#include "parameters.hpp"

Pandemic::Pandemic() : Side_{50}, Grid_(50 * 50) {
  S_ = 2450;
  I_ = 50;
  R_ = 0;
  D_ = 0;
}

void Pandemic::set_Side(int s) {
  if (s > 10 && s < 50) {
    Side_ = s;
  }
}

void Pandemic::set_I(int i) {
  if (i > 0 && i <= Side_ * Side_) {
    I_ = i;
  }
}

// Setting initial infected
Pandemic Pandemic::start(Pandemic& clear, int infected) {
  int l = clear.get_Side();
  Pandemic set;
  set.set_Side(l);

  std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist{0, l - 1};

  for (int j = 0; j < infected; j++) {
    int k = dist(eng);
    int h = dist(eng);

    while (set.Reading_cell(k, h) == Person::Infected) {
      k += 2;
      h += 2;
    }
    set.Writing_cell(k, h) = Person::Infected;
  }

  return set;
}

// Getter
int Pandemic::get_Side() { return Side_; }

std::vector<Person> Pandemic::get_Grid() { return Grid_; }

int Pandemic::get_I() { return I_; }

// Creating toroidal structure
Person const& Pandemic::Reading_cell(int r, int c) {
  int rr = (r + Side_) % Side_;
  int cc = (c + Side_) % Side_;
  int index = (rr * Side_) + cc;

  return Grid_[index];
}

Person& Pandemic::Writing_cell(int r, int c) {
  int rr = (r + Side_) % Side_;
  int cc = (c + Side_) % Side_;
  int index = (rr * Side_) + cc;

  return Grid_[index];
}

// Check infected number next to the cell
int Pandemic::infected_neighbours(Pandemic& pandemic, int r, int c) {
  int contacts = 0;
  for (int i : {-1, 0, 1}) {
    for (int j : {-1, 0, 1}) {
      if (pandemic.Reading_cell(r + i, c + j) == Person::Infected) {
        contacts++;
      }
    }
  }

  return contacts;
}

// Day evolution
Pandemic Pandemic::evolve(Pandemic& now, Parameters ps) {
  Pandemic next;
  int l = now.get_Side();
  next.set_Side(l);

  next = now;

  std::default_random_engine eng{std::random_device{}()};
  std::uniform_real_distribution<float> dis(0.0, 1.0);

  for (int r = 0; r < l; r++) {
    for (int c = 0; c < l; c++) {
      if (now.Reading_cell(r, c) == Person::Susceptible) {
        float p1 = dis(eng);
        double b = ps.get_Beta() * now.infected_neighbours(now, r, c);

        if (ps.get_Alfa() != 0 && p1 <= ps.get_Alfa()) {
          next.Writing_cell(r, c) = Person::Recovered;
          next.R_ += 1;
          next.S_ -= 1;

        } else if (p1 <= (ps.get_Alfa() + b)) {
          next.Writing_cell(r, c) = Person::Infected;
          next.I_ += 1;
          next.S_ -= 1;

        } else {
          // It doesn't change states
        }

      } else if (now.Reading_cell(r, c) == Person::Infected) {
        double p2 = dis(eng);

        if (p2 <= (ps.get_Gamma())) {
          next.Writing_cell(r, c) = Person::Recovered;
          next.R_ += 1;
          next.I_ -= 1;

        } else if (p2 <= (ps.get_Gamma() + ps.get_Mu())) {
          next.Writing_cell(r, c) = Person::Dead;
          next.I_ -= 1;
          next.D_ += 1;

        } else {
          // Here it doesn't change state
        }
      }
    }
  }

  return next;
}
