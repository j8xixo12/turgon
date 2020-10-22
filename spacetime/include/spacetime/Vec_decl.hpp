#include <cmath>
#include "type.hpp"

namespace spacetime
{

template<size_t NDIM>
class Vector 
{
public:
    Vector() { for (auto &ele : data_) ele = 0; }
    
    Vector(const Vector &other) {
        for (int i = 0; i < NDIM; ++i) {
            data_[i] = other.data_[i]; 
        }
    }
    
    Vector(Vector &&other) {
        delete [] this->data_;
        this->data_ = other.data_;
        other.data_ = nullptr;
    }
    
    Vector& operator=(const Vector &other) {
        for (int i = 0; i < NDIM; ++i) {
            data_[i] = other.data_[i];
        }
        return *this; 
    }

    Vector& operator=(Vector &&other) {
        delete [] this->data_;
        this->data_ = other.data_;
        other.data_ = nullptr;
    }

    ~Vector() { delete [] data_; }

private:
    real_type data_[NDIM];
}; /* end class Vector */

} 
