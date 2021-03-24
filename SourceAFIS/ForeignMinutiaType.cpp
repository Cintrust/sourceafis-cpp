//
// Created by Junior Trust on 3/5/2020.
//

#include "ForeignMinutiaType.h"

const  Logger  ForeignMinutiaType::logger(typeid(ForeignMinutiaType).name());


ForeignMinutiaType::ForeignMinutiaType(const InnerEnum & anEnum) noexcept :enum_value(anEnum) {

}

 const ForeignMinutiaType ForeignMinutiaType::ENDING(InnerEnum::ENDING);
 const ForeignMinutiaType ForeignMinutiaType::BIFURCATION(InnerEnum::BIFURCATION);
 const ForeignMinutiaType ForeignMinutiaType::EITHER(InnerEnum::EITHER);
 const ForeignMinutiaType ForeignMinutiaType::OTHER(InnerEnum::OTHER);