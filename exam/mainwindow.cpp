#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "promocodeswidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);

    PromoCodesWidget* promoCodesWidget = findChild<PromoCodesWidget*>("promoCodesWidget");
    if (promoCodesWidget) {
        connect(promoCodesWidget->findChild<QPushButton*>("openPromoCodeButton"), &QPushButton::clicked, promoCodesWidget, &PromoCodesWidget::openPromoCode);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginButtonClicked()
{
    if (ui->pinLineEdit->text() == correctPin) {
        ui->stackedWidget->setCurrentIndex(1);
        PromoCodesWidget* promoCodesWidget = findChild<PromoCodesWidget*>("promoCodesWidget");
        if (promoCodesWidget) {
            promoCodesWidget->initializePromoCodes();
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный PIN-код");
    }
}
