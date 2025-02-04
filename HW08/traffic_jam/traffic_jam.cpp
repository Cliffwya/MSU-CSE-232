#include "traffic_jam.h"


bool AreRoadsBalanced(const std::vector<std::vector<bool>>& road_map){

    for(size_t i{0};i<road_map.size();++i){
        int out_road{0};
        int in_road{0};
        for(size_t j{0};j<road_map.size();++j){
            if(road_map.at(i).at(j)==true) ++out_road;
            if(road_map.at(j).at(i)==true)  ++in_road;
        }
        if (out_road!=in_road) return false;
    }
    return true;
}