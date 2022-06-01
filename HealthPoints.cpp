#ifndef EX3_HEALTH
#define EX3_HEALTH

#include "HealthPoints.h"

HealthPoints::HealthPoints(int healthPoints)
{
    if(healthPoints<=0)
    {
        throw HealthPoints::InvalidArgument();
        
    }
    else{
        m_maxHP = healthPoints;
        m_healthPoints = healthPoints;
    }
}

HealthPoints& HealthPoints::operator +=(int adding){
    m_healthPoints =m_healthPoints + adding;
    if(m_healthPoints>m_maxHP){
        m_healthPoints = m_maxHP;
        return *this;
    }
    return *this;
}
HealthPoints HealthPoints::operator +(int adding) const{
    HealthPoints result(*this); 
    return(result += adding);
}
HealthPoints operator+(const int value, const HealthPoints& hp) 
{
    return (hp+value);
}
HealthPoints& HealthPoints::operator -=(int deducting){
    if(m_healthPoints<deducting){
        m_healthPoints = 0;
        return *this;
    }
    m_healthPoints = m_healthPoints - deducting;
    return *this;
}

HealthPoints HealthPoints::operator -(int deducting) const{
    return HealthPoints(*this) -= deducting;
}
HealthPoints operator-(const int value, const HealthPoints& hp) 
{
    return (hp-value);
}
HealthPoints HealthPoints::operator = (const HealthPoints& value){
    if(this==&value){
        return *this;
    }
    this->m_maxHP = value.m_maxHP;
    this->m_healthPoints = value.m_healthPoints;
    //TODO: check if we have to change also m_maxHP
    return (*this);
}

bool operator == (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints == hp2.m_healthPoints);
}

bool operator != (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints != hp2.m_healthPoints);
}

bool operator <= (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints <= hp2.m_healthPoints);
}

bool operator >= (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints >= hp2.m_healthPoints);
}

bool operator < (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints < hp2.m_healthPoints);
}

bool operator > (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints > hp2.m_healthPoints);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os<<hp.m_healthPoints << "(" << hp.m_maxHP << ")";
    return os;
}

#endif