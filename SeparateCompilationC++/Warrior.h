//
//  Warrior.h
//  hw07
//
//  Created by Victoria Spann-Burton on 3/29/16.
//  Copyright © 2016 Victoria Spann-Burton. All rights reserved.
//

#ifndef Warrior_h
#define Warrior_h
#include <string>

namespace WarriorCraft {
    
    class Noble;   //declares Noble class
    
    class Warrior {         //Warrior class method prototypes
    public:
        Warrior(const std::string& wName, double wStrength);
        double getStrength()const;
        void setStrength(double theStrength);
        std::string getName() const;
        bool getStatus() const;
        void setStatus(const bool& status);
        void setBoss(Noble* theBoss);
        std::string getBoss();
        void runaway();
    private:
        std::string name;
        double strength;
        bool hired;
        Noble* boss;
    };
}

#endif /* Warrior_h */
