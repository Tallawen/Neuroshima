#ifndef __UTILS_DATE_H__
#define __UTILS_DATE_H__

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

namespace Utils
{
    class Date
    {
    public:
        tm * currentTime;
        std::stringstream result;

    protected: /* Obiektu nie można stworzyć poza klasą */
        Date();
        //~Date();

    public:
        /**********************************************//**
          Funkcja zwracająca date w podanym formacie
          np: Format("%D.%M.%Y r")
          zwroci : dzien:miesiac:rok r
          nierozpoznane argumenty sa przepisywane
          wszystkie argumenty opisane w ciele metody
         ************************************************/
        static std::string Format(const std::string &format);

        /**********************************************//**
          Data w formacie yyyy-mm-dd
         ************************************************/
        static std::string GetDate();

        /**********************************************//**
          Godzina w formacie hh:mm:ss
         ************************************************/
        static std::string GetTime();

        /**********************************************//**
          Data i godzina w formacie yyyy-mm-dd : hh:mm:ss
         ************************************************/
        static std::string GetDateTime();

        /*********************************************
          Pobiera aktualny czas z systemu
         ********************************************/
        inline void refresh();

        /********************************************/
        inline void day();

        /********************************************/
        inline void month();

        /********************************************/
        inline void year();

        /********************************************/
        inline void hour24();

        /********************************************/
        inline void hour12();

        /********************************************/
        inline void min();

        /********************************************/
        inline void sec();

        /********************************************/
        inline void am_pm();
    };
}

#endif /*__UTILS_DATE_H__*/
