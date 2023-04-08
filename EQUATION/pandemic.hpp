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
        void print();

        //Getter
        Parameters get_Par();
        std::vector<People> get_Population();
        int get_Time();

    private:

        Parameters Par_;
        std::vector<People> Population_;  //vector containing pandemic evolution
        int Time_;

};

#endif

