#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class SearchHighLight;

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT


public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:

    void searchText();
    Ui::Form *ui;
    SearchHighLight*mSearchHighLight;

};

#endif // WIDGET_H
