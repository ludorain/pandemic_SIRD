#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP
#include "parameters.hpp"

#include <iostream>
#include <vector>

//Possible states
enum Person {Susceptible = 0, Infected, Recovered, Dead};

class Pandemic
{
   public:

   //Default constructor
   Pandemic();

   //Setting the grid 
   void set_I (int);
   void set_Side (int);

   static Pandemic start (Pandemic&, int);

   //Getter
   int get_Side();
   std::vector<Person> get_Grid();
   int get_I();
   


   //Reading and modifying cell
   Person const& Reading_cell(int r , int c);
   Person& Writing_cell(int r, int c);


   //Operator overloading
   friend bool operator== (Pandemic const& left, Pandemic const& right){
      return left.Grid_ == right.Grid_;
   }

   friend bool operator!= (Pandemic const& left, Pandemic const& right){
      return left.Grid_ != right.Grid_;
   }

   friend std::ostream& operator<< (std::ostream& output,  Pandemic& pan){ 

      for( int r = 0; r != pan.Side_; r++ ){

         for(int c = 0; c != pan.Side_; c++ ) {

            std::cout<< pan.Writing_cell(r,c)<< " " ;
            
         }

         std::cout << '\n';
      }

      return output;
   }


   //Check number of infected next to the cell
   int infected_neighbours(Pandemic& pandemic, int r, int c);

   //Day evolution 
   static Pandemic evolve(Pandemic& now, Parameters ps); 


   private: 

   int Side_;  
   std::vector<Person> Grid_;
   
   int S_;
   int I_;
   int R_;
   int D_;

};


#endif