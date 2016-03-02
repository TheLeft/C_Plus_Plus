#include "cduree.h"
#include <iostream>
#include <iomanip>           // setw()//setfill

using namespace std;
    typedef unsigned long long ULLong_t;
    Duree::CDuree::CDuree (const ULLong_t Duree) noexcept
        : m_Duree    (Duree),
          m_Secondes (Duree % 60),
          m_Minutes  (Duree / 60 % 60),
          m_Heures   (Duree / 3600 % 24),
          m_Jours    (Duree / 86400) {}

    void Duree::CDuree::Afficher (void) const
    {
        cout <<'['<<setfill(' ')<< setw (5) << m_Jours<< ":"
             <<setfill('0')<< setw ( 2) << m_Heures<< ":"
             << setw ( 2) << m_Minutes<< ":"
             << setw ( 2) << m_Secondes<<']'<<endl;




    } // Afficher()

    ULLong_t Duree::CDuree::GetDuree (void) const noexcept
    {
        return m_Duree;

    } // GetDuree()

    void Duree::CDuree::Incr (const ULLong_t Delta) noexcept
    {
        m_Duree += Delta;
        Normaliser ();

    } // Incr()

    void Duree::CDuree::Decr (const ULLong_t Delta) noexcept
    {
        m_Duree = Delta < m_Duree ? m_Duree - Delta : 0 ;
        Normaliser ();

    } // Decr()

    void Duree::CDuree::Normaliser (void) noexcept
    {
          m_Secondes = m_Duree % 60;
          m_Minutes  = m_Duree / 60 % 60;
          m_Heures   = m_Duree / 3600 % 24;
          m_Jours    = m_Duree / 86400;

    } // Normaliser()

    Duree::CDuree::~CDuree(void)
    {
        Afficher();
    }















