#include <QtWidgets>
#include "Login.h"
//#include <QSpacerItem>

Login::Login()
{

    QLabel *StateLabel=new QLabel(tr(u8"登录状态:"));
    Namelabel=new QLabel(tr(u8"用户名:"));
    passlabel=new QLabel(tr(u8"密码:"));

    NamelineEdit=new QLineEdit;
    passlineEdit=new QLineEdit;

    buttonlogin=new QPushButton;

    NamelineEdit->setText("DENGTAO");
    passlineEdit->setText("654321");

    passlineEdit->setEchoMode(QLineEdit::Password);
    //passlineEdit->setText("password");

    buttonlogin->setText(tr(u8"登录"));

    this->addWidget(StateLabel);
    this->addStretch();
    this->addWidget(Namelabel);
    this->addWidget(NamelineEdit);
    this->addWidget(passlabel);
    this->addWidget(passlineEdit);
    this->addWidget(buttonlogin);

    //connect(buttonlogin,SIGNAL(clicked(bool)),this,()
}

Login::~Login()
{
    delete buttonlogin;
    delete passlabel;
    delete NamelineEdit;
    delete Namelabel;
    delete passlineEdit;
}

QString Login::getUserName()
{
   return this->NamelineEdit->text();
}

QString Login::getPassword()
{
   return this->passlineEdit->text();
}
