#include "header.hpp"

void CopyStockPrices(const double * old_pointer, double * new_pointer){
    int size{static_cast<int>(*old_pointer)};
    for(int i{0};i<=size;++i){
        *new_pointer=*old_pointer;
        ++new_pointer;
        ++old_pointer;
    }
}