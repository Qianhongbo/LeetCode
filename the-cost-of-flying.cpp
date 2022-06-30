/**
Each airline contains its own cost requirements. Ultimately, the airline is only
interested in two major components: the space you take on the plane, and the
distance you fly. You must generate ticket costs using this gathered data:

Airlines: United, Delta, Southwest, LuigiAir


1.Operating Costs:
- Economy:  No charge
- Premium:  $25
- Business: $50 + $0.25/mile

2.Per-Airline Prices:
- Delta charges $0.50/mile
   + OperatingCost
- United charges $0.75/mile
   + OperatingCost
   + $0.10/mile for Premium seats
- Southwest charges $1.00/mile

-------------------------------------------
Example Input:
United 150.0 Premium
Delta 60.0 Business
Southwest 1000.0 Economy

-------------------------------------------
Example Output:
-------------------------------------------
152.50
95.00
1000.00
125.00
-------------------------------------------
*/

#include <functional>
#include <iostream>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class Airline { United = 1, Delta, Southwest };

enum class Seat { economy, premium, business };

struct Ticket {
  Airline airline;
  double miles;
  Seat seat;
};

std::map<std::string, Airline> airlineMap{
    {"United", Airline::United},
    {"Delta", Airline::Delta},
    {"Southwest", Airline::Southwest},
};

std::map<std::string, Seat> seatMap{{"Economy", Seat::economy},
                                    {"Premium", Seat::premium},
                                    {"Business", Seat::business}};

class TicketProcessor {
 public:
  static TicketProcessor* create(Airline anAirline);
  virtual double calculate(const Ticket& aTicket) const = 0;
  virtual ~TicketProcessor() = default;

 protected:
  double getEconomyOpCost(double aMiles) const { return 0.0; }

  double getPremiumOpCost(double aMiles) const { return 25.0; }

  double getBusinessOpCost(double aMiles) const { return 50.0 + 0.25 * aMiles; }

  using OpCost = double (TicketProcessor::*)(double aDouble) const;
  virtual double getOpCost(const Ticket& aTicket) const {
    std::map<Seat, OpCost> opCostFactory{
        {Seat::economy, &TicketProcessor::getEconomyOpCost},
        {Seat::premium, &TicketProcessor::getPremiumOpCost},
        {Seat::business, &TicketProcessor::getBusinessOpCost},

    };

    if (opCostFactory.find(aTicket.seat) != opCostFactory.end()) {
      return (this->*(opCostFactory.at(aTicket.seat)))(aTicket.miles);
    }
    // ask interviewer
    return -1;
  }
};

class UnitedProcessor : public TicketProcessor {
 public:
  virtual ~UnitedProcessor() = default;
  UnitedProcessor(const UnitedProcessor&) = delete;

  static UnitedProcessor* getInstance();

  double calculate(const Ticket& aTicket) const override {
    double theCost = 0.75 * aTicket.miles + getOpCost(aTicket);
    return (Seat::premium == aTicket.seat) ? 0.1 * aTicket.miles + theCost
                                           : theCost;
  }

 protected:
  UnitedProcessor() = default;
  static UnitedProcessor* instance;
  static std::mutex mutex;
};

UnitedProcessor* UnitedProcessor::instance{};
std::mutex UnitedProcessor::mutex;

UnitedProcessor* UnitedProcessor::getInstance() {
  std::lock_guard<std::mutex> lock(mutex);
  if (nullptr == instance) {
    instance = new UnitedProcessor();
  }
  return instance;
}

class DeltaProcessor : public TicketProcessor {
 public:
  virtual ~DeltaProcessor() = default;
  double calculate(const Ticket& aTicket) const override {
    return 0.5 * aTicket.miles + getOpCost(aTicket);
  }

 protected:
};

class SouthwestProcessor : public TicketProcessor {
 public:
  virtual ~SouthwestProcessor() = default;
  double calculate(const Ticket& aTicket) const override {
    return 1.0 * aTicket.miles;
  }

 protected:
};

TicketProcessor* TicketProcessor::create(Airline anAirline) {
  switch (anAirline) {
    case Airline::United:
      return UnitedProcessor::getInstance();
    case Airline::Delta:
      return new DeltaProcessor();
    case Airline::Southwest:
      return new SouthwestProcessor();
    default:
      return nullptr;
  }
}

using StringList = std::vector<std::string>;

Ticket parseTicket(const std::string& aTicketStr) {
  std::stringstream ss{aTicketStr};
  StringList theTokenList;
  while (!(ss >> std::ws).eof()) {
    std::string theToken;
    ss >> theToken;
    theTokenList.push_back(theToken);
  }
  Ticket theTicket;
  theTicket.airline = airlineMap.at(theTokenList[0]);
  theTicket.miles = std::stod(theTokenList[1]);
  theTicket.seat = seatMap.at(theTokenList[2]);
  return theTicket;
}

std::vector<double> getTicketCosts(StringList aTicketList) {
  std::vector<double> theCostList;
  for (const string& theTicketStr : aTicketList) {
    Ticket theTicket = parseTicket(theTicketStr);
    // factory
    TicketProcessor* theProcessor = TicketProcessor::create(theTicket.airline);
    double theCost = theProcessor->calculate(theTicket);
    std::cout << theCost << '\n';
    theCostList.push_back(theCost);
  }
  return theCostList;
}

int main() {
  std::vector<std::string> input{
      "United 150.0 Premium",
      "Delta 60.0 Business",
      "Southwest 1000.0 Economy",
  };
  auto res = getTicketCosts(input);
  // parse input (split by whitespace)
}