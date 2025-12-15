#include "nzbgetsettingsdialog.h"
#include "ui_nzbgetsettingsdialog.h"
#include "spotlite.h"
#include <QMessageBox>

NzbGetSettingsDialog::NzbGetSettingsDialog(SpotLite *spotlite, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NzbGetSettingsDialog),
    _spotlite(spotlite)
{
    ui->setupUi(this);
    loadSettings();
    updateFormState();
}

NzbGetSettingsDialog::~NzbGetSettingsDialog()
{
    delete ui;
}

void NzbGetSettingsDialog::loadSettings()
{
    if (!_spotlite)
        return;
    const NzbGetConfig cfg = _spotlite->nzbGetConfig();
    ui->enableCheckBox->setChecked(cfg.enabled);
    ui->hostEdit->setText(cfg.host);
    ui->portSpin->setValue(cfg.port);
    ui->sslCheckBox->setChecked(cfg.ssl);
    ui->usernameEdit->setText(cfg.username);
    ui->passwordEdit->setText(cfg.password);
    ui->categoryEdit->setText(cfg.category);
    ui->pausedCheckBox->setChecked(cfg.addPaused);
    ui->prioritySpin->setValue(cfg.priority);
}

void NzbGetSettingsDialog::saveSettings()
{
    if (!_spotlite)
        return;
    NzbGetConfig cfg = _spotlite->nzbGetConfig();
    cfg.enabled = ui->enableCheckBox->isChecked();
    cfg.host = ui->hostEdit->text().trimmed();
    cfg.port = ui->portSpin->value();
    cfg.ssl = ui->sslCheckBox->isChecked();
    cfg.username = ui->usernameEdit->text().trimmed();
    cfg.password = ui->passwordEdit->text();
    cfg.category = ui->categoryEdit->text().trimmed();
    cfg.addPaused = ui->pausedCheckBox->isChecked();
    cfg.priority = ui->prioritySpin->value();
    _spotlite->setNzbGetConfig(cfg);
}

void NzbGetSettingsDialog::updateFormState()
{
    const bool enabled = ui->enableCheckBox->isChecked();
    ui->settingsGroup->setEnabled(enabled);
    ui->testButton->setEnabled(enabled);
}

void NzbGetSettingsDialog::accept()
{
    saveSettings();
    QDialog::accept();
}

void NzbGetSettingsDialog::on_enableCheckBox_toggled(bool checked)
{
    Q_UNUSED(checked);
    updateFormState();
}

bool NzbGetSettingsDialog::testConnection(QString *errorMessage)
{
    if (!_spotlite)
        return false;
    saveSettings();
    const QVector<NzbGetQueueEntry> queue = _spotlite->fetchNzbGetQueue(errorMessage);
    return !_spotlite->nzbGetConfigured() ? false : (!queue.isEmpty() || errorMessage == nullptr || errorMessage->isEmpty());
}

void NzbGetSettingsDialog::on_testButton_clicked()
{
    QString err;
    if (testConnection(&err))
        QMessageBox::information(this, tr("NZBGet-test"), tr("Verbinding met NZBGet gelukt."));
    else
        QMessageBox::warning(this, tr("NZBGet-test"), err.isEmpty() ? tr("Verbinding met NZBGet mislukt.") : err);
}
