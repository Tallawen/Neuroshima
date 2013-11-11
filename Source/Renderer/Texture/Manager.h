#ifndef __RENDERER_TEXTURE_MANAGER_H__
#define __RENDERER_TEXTURE_MANAGER_H__

#include "../../StdAfx.h"
#include "../../Utils/Identifier.h"

#include "Texture.h"
#include "SubTexture.h"

namespace Renderer {

    namespace Texture {

        /**********************************************//**
          @brief Klasa obslugujaca tekstury
         ************************************************/
        class Manager : protected Utils::Identifier {
        private:
            std::map<int, sf::Texture> textures;

            std::map<int, Texture> texturesResource;
            std::map<std::string/*grupa*/, std::map<std::string/*nazwa*/, int>> texturesIndexName;

            std::list<std::string> _loadGroup;

        public:
            Manager();

            ~Manager();

        public:
            /**********************************************//**
              @brief Podpina informację o texturze do bazy.

              Przy podpinaniu zostaje nadane texturze nowe ID.

              @return Zwraca ID gdy textura zostanie dodana lub wartość < od @b 0 gdy wystąpi bład
             ************************************************/
            int attach(Texture texture);


            /**********************************************//**
              @brief Podpina texturę do pamięci.

              Metoda stworzona w celu przechowywania tworzonych w czasie działania programu textur
              sfml @see sf::Texture . Textury odrazu są przechowywane w pamięci. Po skasowaniu
              nie będzie możliwe ich późniejsze podpięcie z bazy. Textury są dodwane do głównej grupy
              która nie jest nigdy kasowana w czasie działania programu @b "/"

              @param name    Nazwa textury po jakiej można się do niej odwołać
              @param texture Textura do podpięcia

              @return Zwraca ID gdy textura zostanie dodana lub wartość < od @b 0 gdy wystąpi bład
             ************************************************/
            //int attach(sf::Texture texture, const std::string &name); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Podpina informacje o subtexturze do textury

              @param id         ID textury do jakiej zostanie podpięta subtextura
              @param subTexture Subtextura do podpięcia

              @return Zwraca ID gdy subtextura zostanie dodana lub wartość < od @b 0 gdy wystąpi bład
             ************************************************/
            int attachSub(const int &id, SubTexture &subtexture);


            /**********************************************//**
              @brief Podpina informacje o subtexturze do textury

              @param group      Nazwa grupy textury do której zostanie podpięta subtextura
              @param name       Nazwa textury do której zostanie podpięta subtextura
              @param subTexture Subtextura do podpięcia

              @return Zwraca ID gdy subtextura zostanie dodana lub wartość < od @b 0 gdy wystąpi bład
             ************************************************/
            int attachSub(const std::string &group, const std::string &name, SubTexture &subtexture);


            /**********************************************//**
              @brief Podpina informacje o subtexturze do textury

              @param texture    Textura do jakiej ma zostać podpięta subtextura
              @param subTexture Subtextura do podpięcia

              @return Zwraca ID gdy subtextura zostanie dodana lub wartość < od @b 0 gdy wystąpi bład
             ************************************************/
            int attachSub(const Texture &texture, SubTexture &subtexture);


            /**********************************************//**
              @brief Odpina textury z bazy

              Gdy textura jest podpięta do pamięci metoda jej nie odepnie.

              @param id ID texutry do odpięcia

              @retval true  Gdy uda się odpiąć texture
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            bool detach(const int &id);


            /**********************************************//**
              @brief Odpina textury z bazy

              Gdy textura jest podpięta do pamięci metoda jej nie odepnie.

              @param group Grupa w której znajduje się textura
              @param name  Nazwa texutry do odpięcia

              @retval true  Gdy uda się odpiąć texture
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            bool detach(const std::string &group, const std::string &name);


            /**********************************************//**
              @brief Odpina textury z pamięci

              Metoda nie zważa na to czy textura jest podpięta do pamięci.
              Należy ją stosować z rozsądkiem...

              @param id ID texutry do odpięcia

              @retval true  Gdy uda się odpiąć texture
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            bool fDetach(const int &id); // TODO: Do poprawy ponieważ nowsza wersja trochę niczej działa


            /**********************************************//**
              @brief Odpina textury z pamięci

              Metoda nie zważa na to czy textura jest podpięta do pamięci.
              Należy ją stosować z rozsądkiem...

              @param group Grupa w której znajduje się textura
              @param name  Nazwa texutry do odpięcia

              @retval true  Gdy uda się odpiąć texture
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool fDetach(const std::string &group, const std::string &name); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Przetwarza textury które należą da danej grupy i ładuję je do pamięci.

              @param group Grupa która ma zostać załadowana

              @retval true  Gdy uda się załadować textury
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool load(const std::string &group); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Przetwarza texturę z bazdy i ładuję ją do pamięci.

              @param id ID textury która ma zostać załadowana

              @retval true  Gdy uda się załadować texture
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool load(const int &id); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Przetwarza texturę z bazdy i ładuję ją do pamięci.

              @param group Grupa do której należy textura
              @param name  Nazwa textury

              @retval true  Gdy uda się załadować texture
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool load(const std::string &group, const std::string &name); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Przetwarza textury które należą da danych grup i ładuję je do pamięci.

              @param groups Lista grup które mają zostać załadowane

              @retval true  Gdy uda się załadować textury
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool load(std::initializer_list<std::string> groups); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Odłącza texutrę z pamięci

              @param id ID textury która ma zostać odłączona z pamięci

              @retval true  Gdy uda się odłączyć
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool unload(const int &id); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Odłącza grupę texutr z pamięci

              @param group Grupa textur które mają zostać odłączone z pamięci

              @retval true  Gdy uda się odłączyć
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool unload(const std::string &group); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Odłącza texutrę z pamięci

              @param group Grupa do której należy textura
              @param name  Nazwa textury

              @retval true  Gdy uda się odłączyć
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool unload(const std::string &group, const std::string &name); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Odłącza textury z pamięci które należą da danych grup

              @param groups Lista grup które mają zostać odłączone z pamięci

              @retval true  Gdy uda się odłączyć textury
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool unload(std::initializer_list<std::string> groups); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Odłącza wszystkie textury z pamięci

              @retval true  Gdy uda się odłączyć textury
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool unlaodAll(); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Odłącza wszystkie textury z wyjątkiem podanych

              @retval true  Gdy uda się odłączyć textury
              @retval false Gdy akcja zakończy się porażką
             ************************************************/
            //bool unlaodAllExcept(std::initializer_list<std::string> groups); TODO: Do zaimplementowania


            /**********************************************//**
              @brief Zwraca listę załadowanych grup
             ************************************************/
            //const std::list<std::string>& loadGroup() const; TODO : Do zaimplementowania


            /**********************************************//**
              @brief Zwraca drzewo załadowanych textur do pamięci
             ************************************************/
            //std::string showTextures() const; TODO: Do zaimplementowania


            /**********************************************//**
              @brief Zwraca drzewo załadowanych textur do bazy
             ************************************************/
            std::string showTexturesResource();

            //sf::Texture& texture();

            //Texture & textureResource();

        private:
            /**********************************************//**
              @brief Sprawdza czy textura o danym @b id jest załadowana do pamięci

              @param id       ID textury
              @param printLog Czy wypisać loga gdy textura nie jestnieje w pamięci
             ************************************************/
            bool textureExists(const int &id, const bool &printLog = true) const;


            /**********************************************//**
              @brief Sprawdza czy textura o danej nazwie jest załadowana do pamięci

              @param group    Grupa do której należy textura
              @param nazwa    Nazwa textury
              @param printLog Czy wypisać loga gdy textura nie jestnieje w pamięci
             ************************************************/
            bool textureExists(const std::string &group, const std::string &name, const bool &printLog = true);


            /**********************************************//**
              @brief Sprawdza czy textura o danym @b id jest załadowana do bazy

              @param id       ID textury
              @param printLog Czy wypisać loga gdy textura nie jestnieje w bazie
             ************************************************/
            bool textureResourceExists(const int &id, const bool &printLog = true) const;


            /**********************************************//**
              @brief Sprawdza czy textura o danej nazwie jest załadowana do bazy

              @param group    Grupa do której należy textura
              @param nazwa    Nazwa textury
              @param printLog Czy wypisać loga gdy textura nie jestnieje w pamięci
             ************************************************/
            bool textureResourceExists(const std::string &group, const std::string &name, const bool &printLog = true);
        };

    }

}

#endif /*__RENDERER_TEXTURE_MANAGER_H__*/

