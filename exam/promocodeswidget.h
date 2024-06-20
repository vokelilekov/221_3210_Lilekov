#ifndef PROMOCODESWIDGET_H
#define PROMOCODESWIDGET_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QGridLayout>

namespace Ui {
class PromoCodesWidget;
}

class PromoCodesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PromoCodesWidget(QWidget *parent = nullptr);
    ~PromoCodesWidget();
    void initializePromoCodes();
    void openPromoCode();

private:
    Ui::PromoCodesWidget *ui;
    QVector<QString> promoCodes;
    QVector<QLabel*> cards;

    QString generateRandomPromoCode();
    void addNewCard();
};

#endif // PROMOCODESWIDGET_H
