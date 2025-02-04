#include <random>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>
#include <iostream>

void read_inputs(std::vector<int> & input){
    std::string line;
    std::getline(std::cin,line);
    std::stringstream ss(line);
    int num;
    while(ss>>num){
        input.push_back(num);
    }
}

void generate(std::mt19937_64 & engine, std::uniform_int_distribution<int> & distributor, std::vector<int> & generated_values, int values){
    std::generate_n(std::back_inserter(generated_values), values, [&engine,&distributor](){
        return distributor(engine);
    });
}

int main(){
    std::vector<int> input;
    read_inputs(input);

    for(int i{0}; i <= 1000; ++i){  //For each seed 0-1000
        std::mt19937_64 engine(i);  //Set the seed for the i value
        std::uniform_int_distribution<int> distributor(10,99);  //Dis for values 10-99
        std::vector<int> generated_values;
        generate(engine,distributor,generated_values,10);  //Generate first 10

        if(std::equal(generated_values.begin(),generated_values.end(),input.begin())){  //If first 10 match
            std::vector<int> result;
            generate(engine,distributor,result,10);  //Now generate all 20
            std::cout<< "Seed: "<< i << std::endl;  //Now print 
            for(int number : generated_values){
                std::cout<< number << " ";
            }
            for(int number : result){
                std::cout<< number << " ";
            }
            return 0;
        }
    }
    return 0;
}