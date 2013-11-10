#include "Date.h"

namespace Utils
{

    //********************************************
    Date::Date()
    {
        refresh();
    }

    //********************************************
    void Date::refresh()
    {
        time_t getTime;
        time(&getTime);
        currentTime = localtime(&getTime);
    }

    //********************************************
    std::string Date::GetDate()
    {
        return Format("%Y-%M-%D");
    }

    //********************************************
    std::string Date::GetTime()
    {
        return Format("%h:%m:%s");
    }

    //********************************************
    std::string Date::GetDateTime()
    {
        return Format("%Y-%M-%D : %h:%m:%s");
    }

    //********************************************
    std::string Date::Format(const std::string &format)
    {
        Date date;
        for (unsigned int i = 0; i < format.length(); i++)
        {
            if (format[i] == '%' && i + 1 < format.length())
            {
                switch (format[i+1])
                {
                    case 'D'://dzien
                             date.day();
                             i++; break;
                    case 'M'://miesiac
                             date.month();
                             i++; break;
                    case 'Y'://rok
                             date.year();
                             i++; break;
                    case 'h'://godzina 24-h
                             date.hour24();
                             i++; break;
                    case 'm'://minuty
                             date.min();
                             i++; break;
                    case 's'://sekundy
                             date.sec();
                             i++; break;
                    case 't'://godzina w formacie 12-godzinnym
                             date.hour12();
                             i++; break;
                    case 'p':// AM/PM
                             date.am_pm();
                             i++; break;
                    default:// gdy zadna opcja nie pasuje - wypisuje znak %
                             date.result << "%"; break;
                }
            }
            else
            {
                date.result << format[i];
            }
        }
        return date.result.str();
    }

    //********************************************
    inline void Date::day()
    {
        if (currentTime->tm_mday < 10)
            result << '0';
        result << currentTime->tm_mday;
    }

    //********************************************
    inline void Date::month()
    {
        if (currentTime->tm_mon < 9)
            result << '0';
        result << currentTime->tm_mon + 1;
    }

    //********************************************
    inline void Date::year()
    {
        result << currentTime->tm_year + 1900;
    }

    //********************************************
    inline void Date::hour24()
    {
        result << currentTime->tm_hour;
    }

    //********************************************
    inline void Date::hour12()
    {
        if (currentTime->tm_hour < 13)
        {
            if (currentTime->tm_hour == 0)
                result << "12";
            else
                result << currentTime->tm_hour;
        }
        else
            result << currentTime->tm_hour - 12;
    }

    //********************************************
    inline void Date::min()
    {
        if (currentTime->tm_min < 10)
            result << '0';
        result << currentTime->tm_min;
    }

    //********************************************
    inline void Date::sec()
    {
        if (currentTime->tm_sec < 10)
            result << '0';
        result << currentTime->tm_sec;
    }


    //********************************************
    inline void Date::am_pm()
    {
        if (currentTime->tm_hour < 12)
            result << "AM";
        else
            result << "PM";
    }
}
