#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void GetBeverage(std::string& _return, const BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "GetBeverage"

void BeveragePreferenceServiceHandler::GetBeverage(std::string& _return, const BeverageType::type btype) {
    // Your implementation goes here
    printf("GetBeverage\n");

    // if BeverageType is HOT, return one of:
    // {“cappuccino”,  “latte”,  “espresso”} selected at random

    // if BeverateType is COLD, return one of:
    // {“lemonade”,  “ice tea”,  “soda”} selected at random

    // 3. business logic
    int rem = rand()%3;

    if(btype == BeverageType::type::HOT)

      if (rem == 0)
        _return = "cappuccino";
      else if (rem == 1)
        _return = "latte";
      else
        _return = "espresso";

    else
     
      if (rem == 0)
        _return = "lemonade";
      else if (rem == 1)
        _return = "ice tea";
      else
        _return = "soda";
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

