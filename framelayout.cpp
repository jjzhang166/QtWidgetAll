#include "framelayout.h"

FrameLayout::FrameLayout()
{
    this->setSpacing(0);    //间隔

    FrameButton = new QPushButton;
    FrameButton->setStyleSheet("QPushButton{"
                               "height:20px;"
                               "border-style:inset;"
                               "border-width:1px;"
                               "border-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ffffff, stop:0.5 #ffffff stop:1 #ffffff);"
                               "font-size: 12px;"
                               "text-align: left;"
                               "font-weight:900;"
                               "}");
    if(flag)
    {
        FrameButton->setIcon(QIcon(":icon/sort37.png"));
    }else{
        FrameButton->setIcon(QIcon(":icon/sort33.png"));
    }
    Frame = new QFrame;
    Frame->setFrameShape(QFrame::Panel);
    Frame->setFrameShadow(QFrame::Raised);

    this->addWidget(FrameButton);
    this->addWidget(Frame);
    //this->addStretch();

    connect(FrameButton,SIGNAL(clicked()),this,SLOT(showHide()));   //连接显示隐藏
}
void FrameLayout::setFrameLayout(QLayout *layout)
{
    Frame->setLayout(layout);
}

void FrameLayout::setFrameText(QString &FrameText)
{
    FrameButton->setText(FrameText);
}

void FrameLayout::showHide()
{
    if(flag)
    {
        Frame->hide();
        FrameButton->setIcon(QIcon(":/icon/sort33.png"));
        flag=false;
    }else{
        Frame->show();
        FrameButton->setIcon(QIcon(":icon/sort37.png"));
        flag=true;
    }
}
