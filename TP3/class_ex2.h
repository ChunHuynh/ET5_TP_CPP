//
// Created by chun on 08/12/2020.
//

#ifndef CLASS_EX2_H
#define CLASS_EX2_H

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <assert.h>
#include <stdexcept>

using namespace std;

template<typename T, std::size_t N>
    class small_array{
    private:
        T values[N];

    public:

        small_array(); // constructeur par défaut
        small_array(const small_array&); // constructeur par copie
        small_array(small_array&&); // constructeur par transfert
        void operator=(const small_array&); // affectation par copie
        void operator=(small_array&&); // affectation par transfert
        T& operator[](std::size_t i); // indexation par transfert
        const T& operator[](std::size_t i) const; // indexation par copie
        T& at(std::size_t i);
        const T& at(std::size_t i)const;
        ~small_array(); // destructeur par défaut

    };

template <typename T, std::size_t N>
    class large_array{
    private:
        std::unique_ptr<small_array<T,N>> values;

    public:
        large_array(){ // constructeur par défaut
            values = make_unique<small_array<T, N>>();
        }

        large_array(large_array const & other) : large_array<T,N>() {
            *this->values = *other.values;
        }

        ~large_array() = default; //destructeur

        void operator=(large_array const& other){ // affectation
            unique_ptr<small_array<T,N>> tmp = *this->values;
            *tmp = *other.values;
            *this->values = tmp;
        }

        T& operator [](std::size_t i) {
            assert(i<N && "Index out of bound");
            return values.get()->operator[](i);
        }

        const T& operator[](std::size_t i) const {
            assert(i<N && "Index out of bound");
            return values.get()->operator[](i);
        }

        T& at(std::size_t i){
            if(i >= N)
                throw std::runtime_error("Index out of bound\n");
            else
                return values.get()->operator[](i);
        }

        const T& at(std::size_t i) const{
            if(i >= N)
                throw std::runtime_error("Index out of bound\n");
            else
                return values.get()->operator[](i);
        }

        void swap(large_array &first){
            std::unique_ptr<small_array<T,N>> tmp(make_unique<small_array<T, N>>(*first.values));
            *first.values = *values;
            *values = *tmp;
        }
    };

#endif //CLASS_EX2_H
