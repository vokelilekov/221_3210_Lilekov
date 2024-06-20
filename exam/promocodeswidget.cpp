#include "promocodeswidget.h"
#include "ui_promocodeswidget.h"
#include <QLabel>
#include <random>

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

    for (int i = 0; i < 10; ++i) {
        addNewCard();
    }
}

void PromoCodesWidget::openPromoCode()
{
    if (cards.isEmpty()) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, cards.size() - 1);
    int randomIndex = dist(gen);

    QLabel *card = cards[randomIndex];
    card->setText(promoCodes[randomIndex]);
    card->setEnabled(false);

    addNewCard();
}

QString PromoCodesWidget::generateRandomPromoCode()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 4;
    QString randomString;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, possibleCharacters.size() - 1);

    for (int i = 0; i < randomStringLength; ++i) {
        int index = dist(gen);
        randomString.append(possibleCharacters.at(index));
    }

    return randomString;
}

void PromoCodesWidget::addNewCard()
{
    QString newPromoCode = generateRandomPromoCode();
    promoCodes.append(newPromoCode);

    QLabel *newCard = new QLabel("???");
    newCard->setFixedSize(100, 50);
    newCard->setAlignment(Qt::AlignCenter);
    newCard->setFrameShape(QFrame::Box);
    newCard->setStyleSheet("background-color: lightgray; border: 1px solid black;");

    ui->gridLayout->addWidget(newCard, cards.size() / 2, cards.size() % 2);
    cards.append(newCard);
}
