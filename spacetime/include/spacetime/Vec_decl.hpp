#include <cmath>
#include "type.hpp"

namespace spacetime
{

template<size_t NDIM>
class Vector 
{
public:
    Vector() { for (auto &ele : data) ele = 0; }
    
    Vector(const Vector &other) {
        for (int i = 0; i < NDIM; ++i) {
            data[i] = other.data[i]; 
        }
    }
    
    Vector(Vector &&other) {
        delete [] this->data;
        this->data = other.data;
        other.data = nullptr;
    }
    
    Vector& operator=(const Vector &other) {
        for (int i = 0; i < NDIM; ++i) {
            data[i] = other.data[i];
        }
        return *this; 
    }

    Vector& operator=(Vector &&other) {
        delete [] this->data;
        this->data = other.data;
        other.data = nullptr;
    }

    ~Vector() { delete [] data; }

private:
    real_type data[NDIM];
}; /* end class Vector */

} 
