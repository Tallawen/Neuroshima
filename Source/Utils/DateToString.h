#ifndef __UTILS_DATE_TO_STRING__
#define __UTILS_DATE_TO_STRING__

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

/************************************************
 * funkcja zwraca aktualna date jako string
 * w formacie zaleznym od argumentu
 * np: dateToString("%D.%M.%Yr); zwroci nam odpowiedznio:
 * dzin.miesiac.rokr
 * wszystkie argumenty opisane ponizej
 ************************************************/
std::string dateToString(std::string argument)
{
	const char * dzienTygodnia[] = { "Niedziela", "Poniedzialek",
		"Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota" };
	tm * newTime;
	time_t getTime;
	time(&getTime);
	newTime = localtime(&getTime);
	std::stringstream wynik;
	for (unsigned int i = 0; i < argument.length(); i++)
	{
		if (argument[i] == '%' && i + 1 < argument.length())
		{
			switch (argument[i+1])
			{
				case 'C'://data rrrr-mm-dd
						  wynik << newTime->tm_year+1900<<'-';
						  if (newTime->tm_mon < 9)
						  	  wynik << "0" << newTime->tm_mon + 1;
						  else
						  	  wynik << newTime->tm_mon+1;
						  wynik<<'-';
						  if (newTime->tm_mday < 10)
						  	  wynik << "0" << newTime->tm_mday;
						  else
						  	  wynik << newTime->tm_mday;
						  i++; break;
				case 'c':// rrrr-mm-dd : hh:mm:ss
						  wynik << newTime->tm_year+1900<<'-';
						  if (newTime->tm_mon < 9)
							  wynik << "0" << newTime->tm_mon + 1;
						  else
							  wynik << newTime->tm_mon+1;
						  wynik<<'-';
						  if (newTime->tm_mday < 10)
							  wynik << "0" << newTime->tm_mday;
						  else
							  wynik << newTime->tm_mday;
						  wynik << " : ";
						  wynik << newTime->tm_hour;
						  wynik << ':';
						  if (newTime->tm_min < 10)
							  wynik << "0" << newTime->tm_min;
						  else
							  wynik << newTime->tm_min;
						  wynik << ':';
						  if (newTime->tm_sec < 10)
							  wynik << "0" << newTime->tm_sec;
						  else
							  wynik << (newTime->tm_sec);
						  i++; break;
				case 'D'://dzien
						  if (newTime->tm_mday < 10)
							  wynik << "0" << newTime->tm_mday;
						  else
							  wynik << newTime->tm_mday;
						  i++; break;
				case 'M'://miesiac
						  if (newTime->tm_mon < 9)
							  wynik << "0" << newTime->tm_mon + 1;
						  else
							  wynik << newTime->tm_mon+1;
						  i++; break;
				case 'Y'://rok
						  wynik << newTime->tm_year+1900; i++; break;
				case 'h'://godzina 24-h
						  wynik << newTime->tm_hour; i++; break;
				case 'm'://minuty
						  if (newTime->tm_min < 10)
							  wynik << "0" << newTime->tm_min;
						  else
							  wynik << newTime->tm_min;
						  i++; break;
				case 's'://sekundy
						  if (newTime->tm_sec < 10)
							  wynik << "0" << newTime->tm_sec;
						  else
							  wynik << (newTime->tm_sec);
						  i++; break;
				case 't'://godzina w formacie 12-godzinnym
						  if (newTime->tm_hour < 13)
						  {
							  if (newTime->tm_hour == 0)
								  wynik << "12";
							  else
								  wynik << newTime->tm_hour;
						  }
						  else wynik << newTime->tm_hour - 12;
						  i++; break;
				case 'p':// AM/PM
						  if (newTime->tm_hour < 12)
							  wynik << "AM";
						  else
							  wynik << "PM";
						  i++; break;
				case 'W'://dzien tygodnia
						  wynik << dzienTygodnia[newTime->tm_wday]; i++; break;
				default:// gdy zadna opcja nie pasuje - wypisuje znak %
						  wynik << "%"; break;
			}
		}
		else
		{
			wynik << argument[i];
		}
	}
	return wynik.str();
}

#endif /*__UTILS_DATE_TO_STRING__*/