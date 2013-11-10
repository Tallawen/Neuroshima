#ifndef __UTILS_DATE_TO_STRING__
#define __UTILS_DATE_TO_STRING__

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

 namespace Utils
{
    namespace DateToString
    {
        class Date
        {
        private:
            tm * currentTime;
            std::stringstream result;

        public:
            Date();
            //~Date();

        public:
            std::string Format(const std::string &format);
            std::string GetDate();
            std::string GetTime();
            std::string GetDateTime();
            void Refresh();
        private:
            inline void day();
            inline void month();
            inline void year();
            inline void hour24();
            inline void hour12();
            inline void min();
            inline void sec();
            inline void am_pm();
        };

        //*********************************************
        Date::Date()
        {
            Refresh();
        }

        /*********************************************
         *  Pobiera aktualny czas z systemu
         ********************************************/
        void Date::Refresh()
        {
            time_t getTime;
            time(&getTime);
            currentTime = localtime(&getTime);
        }

        /*********************************************
         * Data w formacie yyyy-mm-dd
         ********************************************/
        std::string Date::GetDate()
        {
            result.str(std::string());
            year();
            result << '-';
            month();
            result << '-';
            day();
            return result.str();
        }

        /********************************************
         * Godzina w formacie hh:mm:ss
         ********************************************/
        std::string Date::GetTime()
        {
            result.str(std::string());
            hour24();
            result << ':';
            min();
            result << ':';
            sec();
            return result.str();
        }

        /******************************************
         * Data i godzina w formacie yyyy-mm-dd : hh:mm:ss
         ******************************************/
        std::string Date::GetDateTime()
        {
            result.str(std::string());
            year();
            result << '-';
            month();
            result << '-';
            day();
            result << " : ";
            hour24();
            result << ':';
            min();
            result << ':';
            sec();
            return result.str();
        }

        /********************************************
         * Funkcja zwracaj¹ca date w podanym formacie
         * np: Format("%D.%M.%Y r")
         * zwroci : dzien:miesiac:rok r
         * nierozpoznane argumenty sa przepisywane
         * wszystkie argumenty opisane ponizej
         *******************************************/
        std::string Date::Format(const std::string &format)
        {
            result.str(std::string());
            for (unsigned int i = 0; i < format.length(); i++)
                {
                    if (format[i] == '%' && i + 1 < format.length())
                    {
                        switch (format[i+1])
                        {
                            case 'D'://dzien
                                      day();
                                      i++; break;
                            case 'M'://miesiac
                                      month();
                                      i++; break;
                            case 'Y'://rok
                                      year();
                                      i++; break;
                            case 'h'://godzina 24-h
                                      hour24();
                                      i++; break;
                            case 'm'://minuty
                                      min();
                                      i++; break;
                            case 's'://sekundy
                                      sec();
                                      i++; break;
                            case 't'://godzina w formacie 12-godzinnym
                                      hour12();
                                      i++; break;
                            case 'p':// AM/PM
                                      am_pm();
                                      i++; break;
                            default:// gdy zadna opcja nie pasuje - wypisuje znak %
                                      result << "%"; break;
                        }
                    }
                    else
                    {
                        result << format[i];
                    }
                }
            return result.str();
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
}

#endif /*__UTILS_DATE_TO_STRING__*/
