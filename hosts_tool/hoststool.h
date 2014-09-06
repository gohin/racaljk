#ifndef HOSTSTOOL_H
#define HOSTSTOOL_H

#include <QMainWindow>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QtNetwork/qnetworkreply.h>
#include <qstring.h>
#include <qfile.h>
#include <qtextstream.h>
#include <QMessageBox>

namespace Ui {
class HostsTool;
}

class HostsTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit HostsTool(QWidget *parent = 0);
    ~HostsTool();

private slots:
    void on_pushButton_clicked();
    void readyread();

    void on_actionAbout_A_triggered();

private:
    Ui::HostsTool *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString hosts_source;
};

#endif // HOSTSTOOL_H
