#include <QObject>
#include <QIODevice>

class DatasportHtmlGetter : public QObject
{
    Q_OBJECT
public:
    DatasportHtmlGetter(QObject * parent);

public slots:
    void onFinished();

private:
    QString rawHtml;
};
