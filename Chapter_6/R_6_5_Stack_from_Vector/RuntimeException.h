#ifndef _RUNTIMEEXCEPTION_H_
#define _RUNTIMEEXCEPTION_H_

#include <string>

class RuntimeException
{
public:
    RuntimeException(const std::string& err) {errMsg = err;}
    ~RuntimeException() = default;
    
    std::string getMessage() const {return errMsg;}
    
private:
    std::string errMsg;

};

#endif // _RUNTIMEEXCEPTION_H_
