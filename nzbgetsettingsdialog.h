#ifndef NZBGETSETTINGSDIALOG_H
#define NZBGETSETTINGSDIALOG_H

#include <QDialog>

class SpotLite;

namespace Ui {
class NzbGetSettingsDialog;
}

class NzbGetSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NzbGetSettingsDialog(SpotLite *spotlite, QWidget *parent = nullptr);
    ~NzbGetSettingsDialog();

protected:
    void accept() override;

private slots:
    void on_enableCheckBox_toggled(bool checked);
    void on_testButton_clicked();

private:
    void loadSettings();
    void saveSettings();
    void updateFormState();
    bool testConnection(QString *errorMessage = nullptr);

    Ui::NzbGetSettingsDialog *ui;
    SpotLite *_spotlite;
};

#endif // NZBGETSETTINGSDIALOG_H
