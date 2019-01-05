#include <iostream>
#include <sstream>
#include "asl.hpp"

#include "openssl/des.h"

std::string ASL::generate_random_key()
{
    DES_cblock myblock;

    if (!DES_random_key(&myblock)) {
        throw std::exception();
    }

    std::stringstream s;
    for(int i=0; i < DES_KEY_SZ; ++i) {
        s << std::hex << (int) myblock[i];
    }

    std::string mystring(s.str());

    return mystring;
}