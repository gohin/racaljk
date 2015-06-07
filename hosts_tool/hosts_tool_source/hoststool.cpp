#include "hoststool.h"
#include "ui_hoststool.h"

HostsTool::HostsTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HostsTool)
{
    ui->setupUi(this);
    manager =new QNetworkAccessManager(this);
    ui->textEdit->append(">>Initialization success!");
    hosts_source = ui->comboBox->currentText();
    if(!hosts_source.isEmpty())
    {
        ui->textEdit->append("<p style=\"color:green\">>>读取hosts源地址成功</p>");
    }else{
        ui->textEdit->append("<body style=\" font-family;'微软雅黑\'; font-size:10pt; font-weight:72; font-style:normal;\"><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">&gt;&gt;读取hosts失败，请执行：</span></p><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">·重启软件</span></p><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">·重新下载</span></p></body>");
    }
}

HostsTool::~HostsTool()
{
    delete ui;
}

void HostsTool::on_pushButton_clicked()
{
     ui->textEdit->append("<p style=\"color:green\">>>开始配置hosts</p>");
     QNetworkRequest request ;
     request.setUrl(QUrl(hosts_source));
     reply = manager->get(request);
     connect(reply, SIGNAL(finished()), this, SLOT(readyread()));
}
void HostsTool::readyread()
{
    QString get = QString::fromUtf8( reply->readAll());
    if(!get.isEmpty())
    {
        ui->textEdit->append("<p style=\"color:green\">>>服务器获取hosts成功</p>");
#ifdef Q_OS_WIND32
        QFile hosts("C:\\Windows\\System32\\drivers\\etc\\hosts");
        if(hosts.exists())
        {
            if(hosts.setPermissions(QFile::WriteGroup)&&hosts.setPermissions(QFile::WriteOwner)&&hosts.setPermissions(QFile::WriteUser))
            {
                ui->textEdit->append("<p style=\"color:green\">>>设置权限成功</p>");
                hosts.remove();
                QFile file("C:\\Windows\\System32\\drivers\\etc\\hosts");
                file.open( QIODevice::WriteOnly|QFile::Text);
                QTextStream stream(&file);
                stream<<get;
                file.close();
                ui->textEdit->append("<p style=\"color:green\">>>配置hosts完成！</p>");
            }else {
                ui->textEdit->append("<body style=\" font-family;'微软雅黑\'; font-size:10pt; font-weight:72; font-style:normal;\"><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">&gt;&gt;设置权限失败，请执行：</span></p><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">·使用管理员账号登陆</span></p></body>");
            }
        }else{
            QFile file("C:\\Windows\\System32\\drivers\\etc\\hosts");
            file.open( QIODevice::WriteOnly|QFile::Text);
            QTextStream stream(&file);
            stream<<get;
            file.close();
        }
#endif
#ifdef Q_OS_LINUX
        QFile hosts("/etc/hosts");
        if(hosts.setPermissions(QFile::WriteGroup)&&hosts.setPermissions(QFile::WriteOwner)&&hosts.setPermissions(QFile::WriteUser))
        {
            ui->textEdit->append("<p style=\"color:green\">>>设置权限成功</p>");
            hosts.remove();
            QFile file("/etc/hosts");
            file.open( QIODevice::WriteOnly|QFile::Text);
            QTextStream stream(&file);
            stream<<get;
            file.close();
            ui->textEdit->append("<p style=\"color:green\">>>配置hosts完成！</p>");
        }else {
            ui->textEdit->append("<body style=\" font-family;'微软雅黑\'; font-size:10pt; font-weight:72; font-style:normal;\"><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">&gt;&gt;设置权限失败，请执行：</span></p><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">·使用管理员账号登陆</span></p></body>");
        }
#endif
    }else{
        ui->textEdit->append("<body style=\" font-family;'微软雅黑\'; font-size:10pt; font-weight:72; font-style:normal;\"><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">&gt;&gt;从服务器获取hosts失败，请执行：</span></p><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">·打开网络连接</span></p><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">·检查hosts源是否存在</span></p><p style=\"margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">·更换hosts源</span></p></body>");
    }
}

void HostsTool::on_actionAbout_A_triggered()
{
    QMessageBox::about(NULL, "About", "Copyright © 2014, racal, All Rights Reserved");
}


