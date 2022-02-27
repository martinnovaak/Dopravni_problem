#pragma once
#include <exception>
#include <string>
#include <QString>

class TPException : public std::exception
{
private:
    QString message;
public:
    TPException(QString msg) : message(msg) {};
    virtual const char* what() const noexcept
    {
        return message.toStdString().c_str(); // c_str() prevede string na pole charu
	}
};
