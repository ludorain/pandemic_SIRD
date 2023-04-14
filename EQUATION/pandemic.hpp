#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP
#include "people.hpp"
#include "parameters.hpp"
#include <vector>

class Pandemic {

    public:

        //default constructor
        Pandemic();

        //Class setter
        bool set_Pandemic(People, Parameters, int);

        //Function for simulation
        void simulate();

        //Standard output function
        void print() const;

        //Getter
        Parameters get_Par() const;
        std::vector<People> const& get_Population() const;
        int get_Time() const;

    private:

        Parameters Par_;
        std::vector<People> Population_;  //vector containing pandemic evolution
        int Time_;

};

#endif

