

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

friend bool operator == (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints == hp2.m_healthPoints);
}

friend bool operator != (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints != hp2.m_healthPoints);
}

friend bool operator <= (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints <= hp2.m_healthPoints);
}

friend bool operator >= (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints >= hp2.m_healthPoints);
}

friend bool operator < (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints < hp2.m_healthPoints);
}

friend bool operator > (const HealthPoints& hp1,const HealthPoints& hp2){
    return (hp1.m_healthPoints > hp2.m_healthPoints);
}

std::ostream& operator<<(Std::ostream& os, const HealthPoints& hp)
{
    os<<hp.m_healthPoints << "(" << hp.m_maxHP << ")";
    return os;
}