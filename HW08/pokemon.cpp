#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class pokemon{  //create object named pokmemon that has health and a name
    private:
       
    public:
     int hp;  //couldve used a getter here now looking at it later as i coded this....
    std::string name;
    pokemon(int health,const std::string&pokemon_name):hp(health),name(pokemon_name){}  //init list so make the object with a name and health
};

std::vector<pokemon> get_pokemons(const std::string& name_input,const std::string&hp_input){  //get mons from the input and store each in a ector
    std::vector<pokemon> poke_mons;
    std::stringstream name_stream(name_input);  //ss are used just so its easier to get each full name out at a time rather than having to parse through each char
    std::stringstream health_stream(hp_input);
    std::string name_string,hp_string,final_names,final_health;

    std::getline(name_stream,final_names,':');  //remoce the prefixes
    std::getline(health_stream,final_health,':');

    while(std::getline(name_stream,name_string,',')&&std::getline(health_stream,hp_string,',')){  //appends the mons data to the vector
        int health_value{std::stoi(hp_string)}; //converts the health string to an int so we can compare later to find larger health
        poke_mons.emplace_back(health_value,name_string);  //like pushback but avoids extra copying of the object pokemon as it constructs directly in the vector
    }

    return poke_mons;
}

int main(){
    std::string names;
    std::string healths;

    std::getline(std::cin,names);
    std::getline(std::cin,healths);

    std::vector<pokemon> pokemons{get_pokemons(names,healths)};  //call the get mons function from the cin's

    std::string stat_name{healths.substr(0,healths.find(':'))};
    std::cout<<"Name,"<<stat_name<<","<<std::endl;  //just print the basic header
    pokemon max_mons{pokemons.at(0)};  //make a max health mon so we can find the mon with the largest health

    for(const auto& mon:pokemons){  //auto beacuse theres both int and string
        std::cout<<mon.name<<","<<mon.hp<<","<<std::endl;  //print mon info
        if(mon.hp>max_mons.hp) max_mons=mon;  //set the new largest health mon
    }
    
    std::cout<<std::endl<<"Max:"<<std::endl<<max_mons.name<<","<<max_mons.hp<<","<<std::endl;  //print largest health mon

    return 0;
}