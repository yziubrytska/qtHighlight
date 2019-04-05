
#include "Headers/highlight.h"
#include "Headers/widget.h"
#include "ui_widget.h"



Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    mSearchHighLight = new SearchHighLight(ui->textEdit->document());
    connect(ui->pushButton, &QPushButton::clicked, this, &Form::searchText);
}

Form::~Form()
{
    delete ui;
}

void Form::searchText()
{
    mSearchHighLight->searchText(ui->findTextEdit->toPlainText());
}
