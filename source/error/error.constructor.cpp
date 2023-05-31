#include "../../include/stdafx.h"

MyErr::MyErr() {
    this->err = nullptr;
    this->errMsg = "";
}

MyErr::MyErr(const char* errMsg) {
    this->err = new bool(true);
    this->errMsg = errMsg;
}

MyErr::~MyErr() {
    if (this->err != nullptr) {
        delete this->err;
        this->err = nullptr;
    }

    if (this->errMsg != nullptr) {
        delete this->errMsg;
        this->errMsg = nullptr;
    }
}
