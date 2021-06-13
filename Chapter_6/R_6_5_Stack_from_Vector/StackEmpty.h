#ifndef _STACKEMPTY_H_
#define _STACKEMPTY_H_

#include "RuntimeException.h"

class StackEmpty: public RuntimeException
{
public:
    StackEmpty(const std::string err): RuntimeException(err){};
    ~StackEmpty() = default;

};

#endif // _STACKEMPTY_H_
