#include "highlight.h"

#include <QTextCharFormat>
#include <iostream>

SearchHighLight::SearchHighLight(QTextDocument* parent) : BaseClass(parent)
{
    mFormat.setBackground(Qt::green);
}

void SearchHighLight::highlightBlock(const QString& text)
{
    std::cout<<"highlightBlock " << text.toStdString() << std::endl;
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
    std::cout << "Whole Text "<<text.toStdString() << std::endl;
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

