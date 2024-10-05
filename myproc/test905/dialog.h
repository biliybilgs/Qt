#ifndef DIALOG_H
#define DIALOG_H
#include <qdialog.h>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget* parent);
};

#endif // DIALOG_H
