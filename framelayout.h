#ifndef FRAMELAYOUT_H
#define FRAMELAYOUT_H
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLayout>
class FrameLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    FrameLayout();
    void setFrameText(QString &FrameText);
    void setFrameLayout(QLayout *layout);
private slots:
    void showHide();
private:
    QFrame *Frame;
    QPushButton *FrameButton;
    bool flag=true;
};

#endif // FRAMELAYOUT_H
