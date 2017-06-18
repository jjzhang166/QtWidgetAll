#include "treewidget.h"
#include <QHeaderView>
TreeWidget::TreeWidget(QWidget *parent)
    :QTreeWidget(parent)
{
    this->setFont(QFont("arial",10,QFont::Black));  //设置字体
    this->setStyleSheet("QTreeWidget{border:0px;margin-left:-20px;margin-bottom:-10px;}"
                        "QTreeView::branch {image:none;background:#F3F3F3;}"
                        "QTreeView::item{background:#F3F3F3;height:27px;color:#000000;padding:0px 0px 0px 40px}"
                        "QTreeView::item:hover{background:#ECEFE0}"
                        "QTreeView::item:selected{background:#14922D}"

                        "QScrollArea{background:transparent;}"
                        "QScrollBar::vertical{border:0px solid grey;width:10px;margin-bottom:5px;}"
                        "QScrollBar::handle:vertical{border-radius:4px;background:#DADADA;}"
                        "QScrollBar::handle:vertical:hover{background:#D0D0D0}"
                        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:#F2F2F2;}"

                        "QLabel,QRadioButton{background:transparent;color:#000000;font-family:arial;font-size:13px;}"
                        "QCheckBox{font-family:arial;font-size:13px;border-radius:2px;color:#000000;}"
                        "QCheckBox::indicator:checked{color:#FF0000}"
                        );
    this->setRootIsDecorated(false);
    this->header()->setVisible(false);
    this->setWindowTitle("QTreeWidget");

    this->setHeaderLabels(QStringList()<<"Key"<<"Value");
       //设定各个项
    QTreeWidgetItem* A = new QTreeWidgetItem(QStringList()<<"A");
    A->setIcon(0, QIcon("images/data.png"));
    A->setCheckState(0, Qt::Checked);
    QTreeWidgetItem* B = new QTreeWidgetItem(QStringList()<<"B");
    B->setIcon(0, QIcon("images/decision.png"));
    B->setCheckState(0, Qt::Checked);
    QTreeWidgetItem* C = new QTreeWidgetItem(QStringList()<<"C");
    C->setIcon(0, QIcon("images/process.png"));
    C->setCheckState(0, Qt::Checked);
    this->addTopLevelItem(A);
    this->addTopLevelItem(B);
    this->addTopLevelItem(C);

    for(int i=0; i<3; ++i)
        {
            QStringList columItemList;
            QTreeWidgetItem *child;
            QString key, value;
            key += "a" + QString::number(i);
            value += QString::number(i);
            columItemList<<key<<value;
            child = new QTreeWidgetItem(columItemList);
            A->addChild(child);
        }
        for(int i=0; i<3; ++i)
        {
            QStringList columItemList;
            QTreeWidgetItem *child;
            QString key, value;
            key += "b" + QString::number(i);
            value += QString::number(i);
            columItemList<<key<<value;
            child = new QTreeWidgetItem(columItemList);
            B->addChild(child);
        }
        for(int i=0; i<3; ++i)
        {
            QStringList columItemList;
            QTreeWidgetItem *child;
            QString key, value;
            key += "c" + QString::number(i);
            value += QString::number(i);
            columItemList<<key<<value;
            child = new QTreeWidgetItem(columItemList);
            C->addChild(child);
        }
}
void TreeWidget::initQTreeWidget()
{
    QTreeWidgetItem *settingItem = new QTreeWidgetItem(this);
    settingItem->setIcon(0, QIcon(QPixmap (":/setting.png")));
    settingItem->setText(0, tr("settings"));
    QTreeWidgetItem *settingItem_one = new QTreeWidgetItem(settingItem);
    settingItem_one->setIcon(0, QIcon(QPixmap (":/point.png")));
    settingItem_one->setText(0, tr("function"));
    QTreeWidgetItem *settingItem_two = new QTreeWidgetItem(settingItem);
    settingItem_two->setIcon(0, QIcon(QPixmap (":/point.png")));
    settingItem_two->setText(0, tr("rightmenu"));
    QTreeWidgetItem *settingItem_three = new QTreeWidgetItem(settingItem);
    settingItem_three->setIcon(0, QIcon(QPixmap (":/point.png")));
    settingItem_three->setText(0, tr("updatesetup"));
    QTreeWidgetItem *settingItem_four = new QTreeWidgetItem(settingItem);
    settingItem_four->setIcon(0, QIcon(QPixmap (":/point.png")));
    settingItem_four->setText(0, tr("startmunu"));
    QTreeWidgetItem *settingItem_five = new QTreeWidgetItem(settingItem);
    settingItem_five->setIcon(0, QIcon(QPixmap (":/point.png")));
    settingItem_five->setText(0, tr("userexperience"));
    QTreeWidgetItem *settingItem_six = new QTreeWidgetItem(settingItem);
    settingItem_six->setIcon(0, QIcon(QPixmap (":/point.png")));
    settingItem_six->setText(0, tr("cloundplan"));
    QTreeWidgetItem *settingItem_seven = new QTreeWidgetItem(settingItem);
    settingItem_seven->setIcon(0, QIcon(QPixmap (":/point.png")));
    settingItem_seven->setText(0, tr("netcloudplan"));

    QTreeWidgetItem *popupItem = new QTreeWidgetItem(this);
    popupItem->setIcon(0, QIcon(QPixmap (":/popwindow.png")));
    popupItem->setText(0, tr("popup"));
    QTreeWidgetItem *popupItem_one = new QTreeWidgetItem(popupItem);
    popupItem_one->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_one->setText(0, tr("defendpop"));
    QTreeWidgetItem *popupItem_two = new QTreeWidgetItem(popupItem);
    popupItem_two->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_two->setText(0, tr("onlinebuysafe"));
    QTreeWidgetItem *popupItem_three = new QTreeWidgetItem(popupItem);
    popupItem_three->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_three->setText(0, tr("mailsafe"));
    QTreeWidgetItem *popupItem_four = new QTreeWidgetItem(popupItem);
    popupItem_four->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_four->setText(0, tr("chatsafe"));
    QTreeWidgetItem *popupItem_five = new QTreeWidgetItem(popupItem);
    popupItem_five->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_five->setText(0, tr("downloadsafe"));
    QTreeWidgetItem *popupItem_six = new QTreeWidgetItem(popupItem);
    popupItem_six->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_six->setText(0, tr("repairsafe"));
    QTreeWidgetItem *popupItem_seven = new QTreeWidgetItem(popupItem);
    popupItem_seven->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_seven->setText(0, tr("accounttask"));
    QTreeWidgetItem *popupItem_eigth = new QTreeWidgetItem(popupItem);
    popupItem_eigth->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_eigth->setText(0, tr("clearrubish"));
    QTreeWidgetItem *popupItem_nine = new QTreeWidgetItem(popupItem);
    popupItem_nine->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_nine->setText(0, tr("autostartinfo"));
    QTreeWidgetItem *popupItem_ten = new QTreeWidgetItem(popupItem);
    popupItem_ten->setIcon(0, QIcon(QPixmap (":/point.png")));
    popupItem_ten->setText(0, tr("drivertips"));

    QTreeWidgetItem *startItem = new QTreeWidgetItem(this);
    startItem->setIcon(0, QIcon(QPixmap (":/start.png")));
    startItem->setText(0, tr("start"));

    QTreeWidgetItem *defendItem = new QTreeWidgetItem(this);
    defendItem->setIcon(0, QIcon(QPixmap (":/defend.png")));
    defendItem->setText(0, tr("defend"));
    QTreeWidgetItem *defendItem_one = new QTreeWidgetItem(defendItem);
    defendItem_one->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_one->setText(0, tr("htmldefend"));
    QTreeWidgetItem *defendItem_two = new QTreeWidgetItem(defendItem);
    defendItem_two->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_two->setText(0, tr("videodefend"));
    QTreeWidgetItem *defendItem_three = new QTreeWidgetItem(defendItem);
    defendItem_three->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_three->setText(0, tr("searchdefend"));
    QTreeWidgetItem *defendItem_four = new QTreeWidgetItem(defendItem);
    defendItem_four->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_four->setText(0, tr("networkdefend"));
    QTreeWidgetItem *defendItem_five = new QTreeWidgetItem(defendItem);
    defendItem_five->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_five->setText(0, tr("cameradefend"));
    QTreeWidgetItem *defendItem_six = new QTreeWidgetItem(defendItem);
    defendItem_six->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_six->setText(0, tr("driverdefend"));
    QTreeWidgetItem *defendItem_seven = new QTreeWidgetItem(defendItem);
    defendItem_seven->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_seven->setText(0, tr("chatdefend"));
    QTreeWidgetItem *defendItem_eigth = new QTreeWidgetItem(defendItem);
    defendItem_eigth->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_eigth->setText(0, tr("downloaddefend"));
    QTreeWidgetItem *defendItem_nine = new QTreeWidgetItem(defendItem);
    defendItem_nine->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_nine->setText(0, tr("udiskdefend"));
    QTreeWidgetItem *defendItem_ten = new QTreeWidgetItem(defendItem);
    defendItem_ten->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_ten->setText(0, tr("unsafedefend"));
    QTreeWidgetItem *defendItem_eleven = new QTreeWidgetItem(defendItem);
    defendItem_eleven->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_eleven->setText(0, tr("applydefend"));
    QTreeWidgetItem *defendItem_twelve = new QTreeWidgetItem(defendItem);
    defendItem_twelve->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_twelve->setText(0, tr("ieadsdefend"));
    QTreeWidgetItem *defendItem_thirteen = new QTreeWidgetItem(defendItem);
    defendItem_thirteen->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_thirteen->setText(0, tr("developmode"));
    QTreeWidgetItem *defendItem_fourteen = new QTreeWidgetItem(defendItem);
    defendItem_fourteen->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_fourteen->setText(0, tr("selfdefend"));
    QTreeWidgetItem *defendItem_fifteen = new QTreeWidgetItem(defendItem);
    defendItem_fifteen->setIcon(0, QIcon(QPixmap (":/point.png")));
    defendItem_fifteen->setText(0, tr("autodefend"));

    QTreeWidgetItem *repairItem = new QTreeWidgetItem(this);
    repairItem->setIcon(0, QIcon(QPixmap (":/repair.png")));
    repairItem->setText(0, tr("repair"));
    QTreeWidgetItem *repairItem_one = new QTreeWidgetItem(repairItem);
    repairItem_one->setIcon(0, QIcon(QPixmap (":/point.png")));
    repairItem_one->setText(0, tr("patchpath"));
    QTreeWidgetItem *repairItem_two = new QTreeWidgetItem(repairItem);
    repairItem_two->setIcon(0, QIcon(QPixmap (":/point.png")));
    repairItem_two->setText(0, tr("patchinstall"));
    QTreeWidgetItem *repairItem_three = new QTreeWidgetItem(repairItem);
    repairItem_three->setIcon(0, QIcon(QPixmap (":/point.png")));
    repairItem_three->setText(0, tr("othersetup"));
}
