#ifndef PROMOCODESWIDGET_H
#define PROMOCODESWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
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

public slots:
    void openPromoCode();

private:
    Ui::PromoCodesWidget *ui;
    QVector<QString> promoCodes;
    QVector<QPushButton*> cards;

    QString generateRandomPromoCode();
    void addNewCard();
};

#endif // PROMOCODESWIDGET_H
