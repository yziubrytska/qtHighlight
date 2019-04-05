#include "Headers/highlight.h"

#include <QTextCharFormat>

SearchHighLight::SearchHighLight(QTextDocument* parent) : BaseClass(parent)
{
    mFormat.setBackground(Qt::green);
}

void SearchHighLight::highlightBlock(const QString& text)
{
    QRegularExpressionMatchIterator matchIterator = mPattern.globalMatch(text);
    if (matchIterator.hasNext())
    {
        mHighlight = true;
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), mFormat);

     }
}
bool SearchHighLight::compareLength(const QString&first, const QString& second) {

    if (first.length()>second.length())
    {
        return true;
    }
    else
    {
        return false;
    }

}

void SearchHighLight::searchText(const QString& text)
{
    mHighlight = false;
    QRegExp rx("(\\ |\\,|\\.|\\:|\\t)");
    QStringList strList = text.split(rx);
    qSort(strList.begin(), strList.end(),compareLength);

    for ( auto& i : strList)
    {
         mPattern = QRegularExpression(i);
         rehighlight();
         if (mHighlight)
         {
             break;
         }
    }

}

