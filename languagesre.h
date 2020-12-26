#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <QString>

class language
{
private:
    static const QString languages[2][26];

public:
    language();
    static QString lang(int nomb);

};

#endif // LANGUAGE_H
