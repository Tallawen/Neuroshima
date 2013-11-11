#ifndef __RENDERER_TEXTURE_BASE_TEXTURE_H__
#define __RENDERER_TEXTURE_BASE_TEXTURE_H__

#include "../../StdAfx.h"

namespace Renderer {

    namespace Texture {

        /**********************************************//**
          @brief Podstawowa klasa tekstur do dziedziczenia
         ************************************************/
        class BaseTexture {
        private:
            std::string _alias;
            std::string _group;
            std::string _title;

            sf::Vector2f _size;
            int _id;

        public:
            /************************************************/
            BaseTexture() : _size() {
                _alias = "";
                _group  = "";
                _title  = "";

                _id     = -1;
            }


            /*BaseTexture(std::string alians, std::string group, std::string title, sf::Vector2f size, int id) :
                _alians(alians), _group(group), _title(title), _size(size), _id(id)
            {}*/


            /************************************************/
            virtual ~BaseTexture() { }

        public:
            /************************************************/
            void setAlias(const std::string &alias) {
                _alias = alias;
            }


            /************************************************/
            std::string alias() const {
                return _alias;
            }


            /************************************************/
            void setGroup(const std::string &group) {
                _group = group;
            }


            /************************************************/
            std::string group() const {
                return _group;
            }


            /************************************************/
            void setTitle(const std::string &title) {
                _title = title;
            }


            /************************************************/
            std::string title() const {
                return _title;
            }


            /************************************************/
            void setSize(const sf::Vector2f &size) {
                if(size.x >= 0  && size.y >= 0)
                    _size = size;
            }


            /************************************************/
            sf::Vector2f size() const {
                return _size;
            }


            /************************************************/
            void setID(const int &id) {
                if(id >=0 )
                    _id = id;
            }


            /************************************************/
            int id() const {
                return _id;
            }


            /**********************************************//**
              @brief Metoda virutalna odnośnie sprawdzania poprawności texutry
             ************************************************/
            virtual bool valid() const{
                if(group().length() <= 0) {
                    LOG << LOG_INFO(LMsg::Error) << "Textura: group = \"" << group() << "\", alias = \"" << alias()
                                                 << "\", title = \"" << title() << "\" musi przynależeć do grupy" << std::endl;
                  return false;
                }

                if(name().length() <= 0) {
                    LOG << LOG_INFO(LMsg::Error) << "Nie można utwożyć nazwy dla textury!!!" << std::endl;
                  return false;
                }

              return true;
            }


            /**********************************************//**
              @brief Metoda virutalna zwracająca nazwę textury (po jakiej następuje odwołanie do niej)
             ************************************************/
            virtual std::string name() const{
                if(alias().length() > 0)
                    return alias();

                if(title().length() > 0)
                    return title();

              return "";
            }


        }; /* class BaseTexture */

    } /* namespace Texture */

} /* namespace Renderer */

#endif /* __RENDERER_TEXTURE_BASE_TEXTURE_H__ */
