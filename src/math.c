#include <stddef.h>
#include <stdint.h>
#include "math.h"

uint32_t div(uint32_t num, uint32_t denum){
    return num/denum;
}

uint32_t sum(uint32_t num, uint32_t num2){
    return num+num2;
}

uint32_t dif(uint32_t num, uint32_t sub){
    return num-sub;
}

uint32_t mult(uint32_t num, uint32_t mul){
    return num*mul;
}

uint32_t pow(uint32_t num, uint32_t expo){
    if(expo == 0)
        return 1;
    uint32_t res = num;
    expo--;
    while(expo > 0){
        res *= num;
        expo--;
    }
    return res;
}

uint32_t rem(uint32_t num, uint32_t denum){
    return num % denum;
}