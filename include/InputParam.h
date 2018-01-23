//
// Created by ryan on 1/22/18.
//

#ifndef OCEANIO_CLIENT_INPUTOUTPUT_H
#define OCEANIO_CLIENT_INPUTOUTPUT_H

enum Types{ int_t, double_t, string_t, unknown_t};
class any;
class InputParam {
public:
public:
    InputParam();
    template<typename T>
    InputParam(const T& val) : value{val}{

    }

    ~InputParam();

    Types type;
    bool required;
    any value;
};



#endif //OCEANIO_CLIENT_INPUTOUTPUT_H
