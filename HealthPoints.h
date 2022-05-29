#define DEFAULT_MAX_HP 100
#include <iostream>

class HealthPoints
{
private:
    int m_maxHP;
    int m_healthPoints;
public:
    HealthPoints(int healthPoints=DEFAULT_MAX_HP);
    HealthPoints(const HealthPoints&)=default;
    ~HealthPoints()=default;
    HealthPoints operator = (const HealthPoints&);
    HealthPoints operator +(int adding) const;
    HealthPoints operator -(int deducting) const;
    HealthPoints& operator +=(int adding);
    HealthPoints& operator -=(int deducting);
    friend bool operator == (const HealthPoints& hp1,const HealthPoints& hp2);
    friend bool operator != (const HealthPoints& hp1,const HealthPoints& hp2);
    friend bool operator <= (const HealthPoints& hp1,const HealthPoints& hp2);
    friend bool operator >= (const HealthPoints& hp1,const HealthPoints& hp2);
    friend bool operator < (const HealthPoints& hp1,const HealthPoints& hp2);
    friend bool operator > (const HealthPoints& hp1,const HealthPoints& hp2);
    friend std::ostream& operator<<(Std::ostream& os, const HealthPoints& hp);
    class InvalidArgument{};
};
