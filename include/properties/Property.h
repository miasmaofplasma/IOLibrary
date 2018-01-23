//
// Created by ryan on 1/22/18.
//

#ifndef OCEANIO_CLIENT_SPECTROMETERPROPERTY_H
#define OCEANIO_CLIENT_SPECTROMETERPROPERTY_H
#include <vector>
#include <string>


class Property {
    Property();
    ~Property();


    virtual std::string formatted_message() = 0;

protected:
    bool setable; //required
    bool getable; //required
    std::string get_message_template; //depends on gettable
    std::string set_message_template; //depends on settable



};


#endif //OCEANIO_CLIENT_SPECTROMETERPROPERTY_H
