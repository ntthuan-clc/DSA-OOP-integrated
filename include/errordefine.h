#pragma once 

class MyErr {
private:
    const char* errMsg;

public:
    bool* err;
    
    MyErr();
    MyErr(const char*);
    
    ~MyErr();

    const char* Error() {
        return errMsg;
    }
};