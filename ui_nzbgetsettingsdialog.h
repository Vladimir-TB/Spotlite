/********************************************************************************
** Form generated from reading UI file 'nzbgetsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NZBGETSETTINGSDIALOG_H
#define UI_NZBGETSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NzbGetSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *enableCheckBox;
    QGroupBox *settingsGroup;
    QFormLayout *formLayout;
    QLabel *hostLabel;
    QLineEdit *hostEdit;
    QLabel *portLabel;
    QSpinBox *portSpin;
    QCheckBox *sslCheckBox;
    QLabel *userLabel;
    QLineEdit *usernameEdit;
    QLabel *passLabel;
    QLineEdit *passwordEdit;
    QLabel *categoryLabel;
    QLineEdit *categoryEdit;
    QLabel *priorityLabel;
    QSpinBox *prioritySpin;
    QCheckBox *pausedCheckBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *testButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NzbGetSettingsDialog)
    {
        if (NzbGetSettingsDialog->objectName().isEmpty())
            NzbGetSettingsDialog->setObjectName(QString::fromUtf8("NzbGetSettingsDialog"));
        NzbGetSettingsDialog->resize(420, 360);
        verticalLayout = new QVBoxLayout(NzbGetSettingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        enableCheckBox = new QCheckBox(NzbGetSettingsDialog);
        enableCheckBox->setObjectName(QString::fromUtf8("enableCheckBox"));

        verticalLayout->addWidget(enableCheckBox);

        settingsGroup = new QGroupBox(NzbGetSettingsDialog);
        settingsGroup->setObjectName(QString::fromUtf8("settingsGroup"));
        formLayout = new QFormLayout(settingsGroup);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        hostLabel = new QLabel(settingsGroup);
        hostLabel->setObjectName(QString::fromUtf8("hostLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, hostLabel);

        hostEdit = new QLineEdit(settingsGroup);
        hostEdit->setObjectName(QString::fromUtf8("hostEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, hostEdit);

        portLabel = new QLabel(settingsGroup);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, portLabel);

        portSpin = new QSpinBox(settingsGroup);
        portSpin->setObjectName(QString::fromUtf8("portSpin"));
        portSpin->setMaximum(65535);
        portSpin->setValue(6789);

        formLayout->setWidget(1, QFormLayout::FieldRole, portSpin);

        sslCheckBox = new QCheckBox(settingsGroup);
        sslCheckBox->setObjectName(QString::fromUtf8("sslCheckBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sslCheckBox);

        userLabel = new QLabel(settingsGroup);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, userLabel);

        usernameEdit = new QLineEdit(settingsGroup);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, usernameEdit);

        passLabel = new QLabel(settingsGroup);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, passLabel);

        passwordEdit = new QLineEdit(settingsGroup);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(4, QFormLayout::FieldRole, passwordEdit);

        categoryLabel = new QLabel(settingsGroup);
        categoryLabel->setObjectName(QString::fromUtf8("categoryLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, categoryLabel);

        categoryEdit = new QLineEdit(settingsGroup);
        categoryEdit->setObjectName(QString::fromUtf8("categoryEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, categoryEdit);

        priorityLabel = new QLabel(settingsGroup);
        priorityLabel->setObjectName(QString::fromUtf8("priorityLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, priorityLabel);

        prioritySpin = new QSpinBox(settingsGroup);
        prioritySpin->setObjectName(QString::fromUtf8("prioritySpin"));
        prioritySpin->setMinimum(-1000);
        prioritySpin->setMaximum(1000);

        formLayout->setWidget(6, QFormLayout::FieldRole, prioritySpin);

        pausedCheckBox = new QCheckBox(settingsGroup);
        pausedCheckBox->setObjectName(QString::fromUtf8("pausedCheckBox"));

        formLayout->setWidget(7, QFormLayout::FieldRole, pausedCheckBox);


        verticalLayout->addWidget(settingsGroup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        testButton = new QPushButton(NzbGetSettingsDialog);
        testButton->setObjectName(QString::fromUtf8("testButton"));

        horizontalLayout->addWidget(testButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(NzbGetSettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NzbGetSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NzbGetSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NzbGetSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NzbGetSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *NzbGetSettingsDialog)
    {
        NzbGetSettingsDialog->setWindowTitle(QCoreApplication::translate("NzbGetSettingsDialog", "NZBGet-instellingen", nullptr));
        enableCheckBox->setText(QCoreApplication::translate("NzbGetSettingsDialog", "NZBGet integratie inschakelen", nullptr));
        settingsGroup->setTitle(QCoreApplication::translate("NzbGetSettingsDialog", "Serverinstellingen", nullptr));
        hostLabel->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Host", nullptr));
        portLabel->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Poort", nullptr));
        sslCheckBox->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Gebruik SSL (https)", nullptr));
        userLabel->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Gebruikersnaam", nullptr));
        passLabel->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Wachtwoord", nullptr));
        categoryLabel->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Categorie", nullptr));
        priorityLabel->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Prioriteit", nullptr));
        pausedCheckBox->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Toevoegen als pauze", nullptr));
        testButton->setText(QCoreApplication::translate("NzbGetSettingsDialog", "Test verbinding", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NzbGetSettingsDialog: public Ui_NzbGetSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NZBGETSETTINGSDIALOG_H
