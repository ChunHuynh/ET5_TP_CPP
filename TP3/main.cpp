#include <iostream>
#include <climits>

#include "class_ex1.h"
//#include "class_ex2.h"
#include "class_ex2.cpp"

/***************    2.3     **********************/
template<typename T, std::size_t N>
using my_array = typename std::conditional< (N>4*sizeof(int)), large_array<T, N>, small_array<T, N>>::type;

int  main() {

    /*******************    Ex 1.1    ******************/
    /*
    number_ptr p = integer (). build (1);
    real (). build(2)->display ();
    p->display ();
    */

    /*******************    Ex 1.2    ******************/
    /*
    number_factory  fact;
    number_ptr q = fact.build("integer", 5);
    if(q)
        q->display ();
    else
        std::cerr << "\"integer\" not defined in dictionary" << std::endl;
    q = fact.build("real", 42);
    if(q)
        q->display ();
    else
        std::cerr << "\"real\" not defined in dictionary" << std::endl;
    q = fact.build("toto", 17);
    if(q)
        q->display();
    else
        std::cerr << "\"toto\" not defined in dictionary" << std::endl;
    */

    /*******************    Ex 2.1    ******************/
    /*
    small_array <int , 4> t;
    t.at(2) = 42;
    small_array <int , 4> const u = t;
    for (std:: size_t i = 0; i < 4; ++i) {
        std::cout  << '[' << i << "] = " << u.at(i) << '\n';
    }
    t.at(4) = 0;//  assertion  failed!
    */

    /*******************    Ex 2.2    ******************/
    //small_array <int , 1000 * 1000 * 10 > t;
    //t[2] = 42;
    //large_array <int , 1000 * 1000 * 10> t;
    //t[2] = 42;
    large_array <int , 1000*1000*10> t;
    t.at(2) = 42;
    large_array <int , 1000*1000*10> const u = t;
    for (std:: size_t i = 0; i < 4; ++i) {
        std::cout  << '[' << i << "] = " << u.at(i) << '\n';
    }
    //t.at(1000*1000*10) = 0;//  assertion  failed!
    large_array<int, 1000*1000*10> a;
    a.at(2) = 69;
    t.swap(a);
    cout << "Après swap():" << endl;
    for (std:: size_t i = 0; i < 4; ++i) {
        std::cout  << '[' << i << "] = " << t.at(i) << '\n';
    }
    my_array<int, 1000*1000*10> large;
    cout << typeid(large).name() << endl;
    my_array<int, 10> small;
    cout << typeid(small).name() << endl;

    return 0;
}