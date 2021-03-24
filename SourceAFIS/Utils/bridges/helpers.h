//
// Created by Junior Trust on 3/5/2020.
//

#ifndef SOURCEAFIS_CPP_HELPERS_H
#define SOURCEAFIS_CPP_HELPERS_H
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}
#endif //SOURCEAFIS_CPP_HELPERS_H
