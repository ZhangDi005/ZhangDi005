#ifndef APP_H
#define APP_H
#include <QHash>
#include <QDataStream>
#include "algorithmDesign.h"

class App
{
public:
    static App &instance();
    QList<Channel> &getProject();
    friend QDataStream & operator<<(QDataStream &stream, const App &info);
    friend QDataStream & operator>>(QDataStream &stream, App &info);
private :
    App() = default;
    ~App() = default;
    QList<Channel> m_project;

};

#endif // APP_H
