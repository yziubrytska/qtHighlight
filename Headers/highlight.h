#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class SearchHighLight : public QSyntaxHighlighter
{
    Q_OBJECT
    using BaseClass = QSyntaxHighlighter;

public:
    explicit SearchHighLight(QTextDocument* parent = nullptr);
    static bool compareLength(const QString&first, const QString& second);
    void searchText(const QString& text);

protected:
    virtual void highlightBlock(const QString &text) override;

private:
    QRegularExpression mPattern;
    QTextCharFormat mFormat;
    bool mHighlight = false;
};

#endif // HIGHLIGHT_H
