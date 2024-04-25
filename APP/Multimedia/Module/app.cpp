#include "app.h"

App &App::instance()
{
    static App app;
    return app;
}

QList<Channel> &App::getProject()
{
    return m_project;
}

QDataStream & operator<<(QDataStream &stream, const App &info)
{
    stream<<info.m_project;
    return stream;
}

QDataStream & operator>>(QDataStream &stream, App &info)
{
    stream>>info.m_project;
    return stream;
}


