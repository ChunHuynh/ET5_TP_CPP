//
// Created by chun on 08/12/2020.
//

#include "class_ex2.h"


template <typename T, std::size_t N>
small_array<T,N>::small_array() {

}

template <typename T, std::size_t N>
small_array<T,N>::small_array(const small_array& other) : small_array<T,N>() {
    for (std::size_t i=0; i<N; i++)
        this->values[i] = other.values[i];
}

template <typename T, std::size_t N>
small_array<T,N>::small_array(small_array&& other) : small_array<T,N>() {
    this->values = other.values;
    other.values = nullptr;
}

template <typename T, std::size_t N>
void small_array<T,N>::operator=(const small_array& other) {
    for (std::size_t i=0; i<N; i++) {
        this->values[i] = other.values[i];
    }
}

template <typename T, std::size_t N>
void small_array<T,N>::operator=(small_array&& other) {
    for (std::size_t i=0; i<N; i++) {
        this->values[i] = other.values[i];
    }
    other = nullptr;
}

template <typename T, std::size_t N>
T& small_array<T,N>::operator[](std::size_t i) {
    assert(i<N && "Index out of bound");
    return this->values[i];
}

template <typename T, std::size_t N>
const T& small_array<T,N>::operator[](std::size_t i) const {
    assert(i<N && "Index out of bound");
    return this->values[i];
}
template <typename T, std::size_t N>
T& small_array<T,N>::at(std::size_t i){
    if(i >= N)
        throw std::runtime_error("Small array out of index\n");
    else
        return this->values[i];
}

template <typename T, std::size_t N>
const T& small_array<T,N>::at(std::size_t i) const{
    if(i >= N)
        throw std::runtime_error("Small array out of index\n");
    else
        return this->values[i];
}

template <typename T, std::size_t N>
small_array<T,N>::~small_array<T, N>() {
}
