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

QList<BackupData> &App::getBackupData()
{
    return m_backupData;
}

void App::syncSave(int id, QString remark)
{
    if (m_project.empty()) return;
    BackupData backupData;
    backupData.m_flag = id;
    backupData.m_remark = remark;
    QMap<QString, OverAll> overAll;
    for (Channel channel : m_project) {
        OverAll over;
        over.m_channelData = channel.m_channelData;
        over.m_eq = channel.m_eq;
        overAll.insert(channel.channelName, over);
    }
    backupData.m_overAll = overAll;
    for (int i = 0; i < m_backupData.size(); i++) {
        if (m_backupData.at(i).m_flag == id)
            m_backupData.removeAt(i);
    }
    m_backupData.push_back(backupData);
}

void App::syncDelete(int id)
{
    for (int i = 0; i < m_backupData.size(); i++) {
        if (m_backupData.at(i).m_flag == id) {
            m_backupData.removeAt(i);
            break;
        }
    }
}

QDataStream & operator<<(QDataStream &stream, const App &info)
{
    stream<<info.m_project;
    stream<<info.m_backupData;
    return stream;
}

QDataStream & operator>>(QDataStream &stream, App &info)
{
    stream>>info.m_project;
    stream>>info.m_backupData;
    return stream;
}


