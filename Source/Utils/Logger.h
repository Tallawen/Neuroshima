#ifndef __UTILS_LOGGER_H__
#define __UTILS_LOGGER_H__

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

#include "Date.h"

#ifndef LOG_INFO
#define LOG_INFO(lmsg) Utils::Date::GetDateTime() << "| " << __FILE__ << "| " << __LINE__ << "| " << lmsg << "| " << __FUNCTION__ << ": "
#endif /*LOG_INFO*/

namespace Utils {

    /**********************************************//**
      @brief Logger
     ************************************************/
    class Logger {
    public:
        /**********************************************//**
          Typ wiadomości
         ************************************************/
        enum class Message {
            Info,
            Warning,
            Error,
            Critical
        };


        /**********************************************//**
          Rodzaj wyjścia na jaki mają zastać wypisywane wiadomości
         ************************************************/
        enum class Stream {
            File,
            Consol
        };


        /**********************************************//**
          Tryb otwarcia pliku. Działa tylko z @b Stream::File
         ************************************************/
        enum class Openmode {
            Append,
            Truncate
        };

    public:
        std::ostream *stream; /**< Wyjście na które zostaną przekazane dane */

    private:
        std::map<Message, const char*> messageMap; /**< Mapa do parsowania enum @see Message na string */

        Stream streamMode; /**< Tryb działania parsera (czy zapisuje do pliku czy na konsole) */

    public:
        /**********************************************//**
          Konstruktor

          @param out      Określa gdzie mają być wypisywanie komunikaty
          @param filename Nazwa pliku do którego mają zostać zapisywane komunikaty przy wybirze wyjścia @b Stream::File
          @param mode     Określa sposób otwarcia pliku. Działą tylko z trybem @b Stream::File
         ************************************************/
        Logger(const Stream &out = Stream::Consol, std::string filename = "", const Openmode &mode = Openmode::Truncate);


        /************************************************/
        ~Logger();

    public:
        /**********************************************//**
          @brief Operator wypisująca na wyjście @b stream

          Operator obsługuje manupulatory które przyjmują i zwracają @b std::ostream&

          @param funPtr Adres do funkcji która ma zostać obsłużona

          @return Referencję na obiekt logger'a
         ************************************************/
        Logger& operator<< (std::ostream& (*funPtr)(std::ostream&));


        /**********************************************//**
          @brief Operator wypisujący na wyjście @b stream

          @param val Wartość do wypisania

          @return Referencję na obiekt logger'a
         ************************************************/
        Logger& operator<< (const int &val) { return write(val); };


        /**********************************************//**
          @copydoc operator<<(const int &val)
         ************************************************/
        Logger& operator<< (const float &val) { return write(val); };


        /**********************************************//**
          @copydoc operator<<(const int &val)
         ************************************************/
        Logger& operator<< (const double &val) { return write(val); };


        /**********************************************//**
          @copydoc operator<<(const int &val)
         ************************************************/
        Logger& operator<< (const char *val) { return write(val); };


        /**********************************************//**
          @copydoc operator<<(const int &val)
         ************************************************/
        Logger& operator<< (const std::string &val) { return write(val); };


        /**********************************************//**
          @copydoc operator<<(const int &val)
         ************************************************/
        Logger& operator<< (const Message &val);


        /**********************************************//**
          @brief Wyłącza/włącza zapis do logu
         ************************************************/
        void enable(bool value = true);


        /**********************************************//**
          @brief Czy logger jest włączony
         ************************************************/
        bool isEnable() const;

    private:
        /**********************************************//**
          @brief Zwraca wiadomość powitalną (przy inicjalizowaniu loggera)
         ************************************************/
        inline void welcomeMsg();


        /**********************************************//**
          Metoda potrzebna do przeciążenia operatorów.
          Teoretycznie można pominąć, ale wystąpi kopiowanie kodu w dużej ilości miejsc.

          @note Ech ta kontrola typów, lubię ją, ale czasami daję popalić.
         ************************************************/
        template<typename T> Logger& write(const T &val) {
            *stream << val;
          return *this;
        }

    };

}

typedef Utils::Logger::Message LMsg; /**< Skrócony dostęp do @link Utils::Logger::Message */

/**********************************************//**
   @class Utils::Logger Logger.h "Utils/Logger.h"
   @ingroup Utils

   Klasa logger'a.
   Klasa nie jest singletonem ponieważ może wystąpić parę loggerów.

   @example
      @code
      Utils::Logger log(Utils::Logger::File, "log.txt");

      log << LOG_INFO(LMsg::Info) << "Test ;)" << std::endl;
      @endcode

   @note Zalecam zawsze używać makra LOG_INFO i utworzyć obiekt globalnie.
 ************************************************/

#endif /*__UTILS_LOGGER_H__*/
