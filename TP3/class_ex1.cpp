//
// Created by chun on 08/12/2020.
//

#include "class_ex1.h"

using namespace std;

// class integer
number_ptr integer::build(int val) {
    this->value = val;
    number_ptr res = make_unique<integer>(*this);
    return res;
}

void integer::display() {
    cout<< "(integer) " << this->value << endl;
}

// class real
number_ptr real::build(int val){
    this->value = val;
    number_ptr res = make_unique<real>(*this);
    return res;
}

void real::display(){
    cout<< "(real) " << this->value << endl;
}

// class number_factory
number_factory::number_factory() {
    dict["real"] = real().build(0);
    dict["integer"] = integer().build(0);
}

number_ptr number_factory::build(const std::string &t, int x) {
    if(this->dict.count(t) == 0)
        return nullptr;
    else
        return this->dict[t]->build(x);
}

