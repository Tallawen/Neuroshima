#include "Logger.h"
#include "DateToString.h"

#include <cassert>

#define ADD_ENUM_TO_MAP(map, name, txt) map[name] = txt

#define ENUM_STR(map, name) map[name]

namespace Utils {

    /************************************************/
    Logger::Logger(const Stream &outType, std::string filename, const Openmode &mode) {
        ADD_ENUM_TO_MAP(messageMap, Message::Info,     "Info");
        ADD_ENUM_TO_MAP(messageMap, Message::Warning,  "Warning");
        ADD_ENUM_TO_MAP(messageMap, Message::Error,    "Error");
        ADD_ENUM_TO_MAP(messageMap, Message::Critical, "Critical");

        streamMode = outType;

        if(outType == Stream::Consol)
            stream = &std::cout;

        else if(outType == Stream::File) {
            if(filename.empty()) {
                std::cerr << "Logger: Nieprawidlowa nazwa pliku" << std::endl;
              return;
            }

            std::ios_base::openmode openmode = std::ios::out;

            switch(mode) {
                case Openmode::Append:   openmode |= std::ios::app;   break;
                case Openmode::Truncate: openmode |= std::ios::trunc; break;
                default: assert(false); break;
            }

            stream = new std::fstream(filename, openmode);

            if(!dynamic_cast<std::fstream*>(stream)->is_open()) {
                std::cerr << "Logger: Nie można otworzyć pliku: " << filename << std::endl;
              return;
            }
        }

        welcomeMsg();
    }


    /************************************************/
    Logger::~Logger() {
        if(streamMode == Stream::File) {
            std::fstream *fstream = dynamic_cast<std::fstream*>(stream);

            fstream->close();
            delete fstream;
        }
    }


    /************************************************/
    Logger& Logger::operator<< (std::ostream& (*funPtr)(std::ostream&)) {
        funPtr(*stream);
      return *this;
    }


    /************************************************/
    Logger& Logger::operator<< (const Message &val) {
      return *this << ENUM_STR(messageMap, val);
    }


    /************************************************/
    void Logger::enable(bool value) {
        static std::streambuf *buff = nullptr; /* Zmienna przechowująca buffor na czas wyłączenia */

        if(buff == nullptr && value == false) {
            buff = stream->rdbuf();
            stream->rdbuf(nullptr);

        } else if(buff != nullptr && value == true) {
            stream->rdbuf(buff);
            buff = nullptr;
        }
    }


    /************************************************/
    bool Logger::isEnable() const {
      return stream->rdbuf() != nullptr;
    }


    /************************************************/
    void Logger::welcomeMsg() {
        Utils::DateToString::Date date;
        *stream << std::endl
                << "--- Log utworzony " << date.GetDateTime() << std::endl //data w formacie rrrr-mm-dd : hh:mm:ss
                << std::endl << std::endl;
    }

}
