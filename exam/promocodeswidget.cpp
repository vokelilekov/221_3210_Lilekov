#include "promocodeswidget.h"
#include "ui_promocodeswidget.h"
#include <QRandomGenerator>
#include <QPushButton>

PromoCodesWidget::PromoCodesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PromoCodesWidget)
{
    ui->setupUi(this);
}

PromoCodesWidget::~PromoCodesWidget()
{
    delete ui;
}

void PromoCodesWidget::initializePromoCodes()
{
    promoCodes.clear();
    for (auto card : cards) {
        delete card;
    }
    cards.clear();

    QLayoutItem *child;
    while ((child = ui->gridLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    for (int i = 0; i < 9; ++i) {
        addNewCard();
    }
}

void PromoCodesWidget::openPromoCode()
{
    if (cards.isEmpty()) return;

    int randomIndex = QRandomGenerator::global()->bounded(cards.size());
    QPushButton *card = cards[randomIndex];
    card->setText(promoCodes[randomIndex]);
    card->setEnabled(false);

    addNewCard();
}

QString PromoCodesWidget::generateRandomPromoCode()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 4;
    QString randomString;
    for (int i = 0; i < randomStringLength; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.size());
        randomString.append(possibleCharacters.at(index));
    }
    return randomString;
}

void PromoCodesWidget::addNewCard()
{
    QString newPromoCode = generateRandomPromoCode();
    promoCodes.append(newPromoCode);

    QPushButton *newCard = new QPushButton("???");
    newCard->setFixedSize(100, 50);
    ui->gridLayout->addWidget(newCard, cards.size() / 2, cards.size() % 2);
    cards.append(newCard);
}
