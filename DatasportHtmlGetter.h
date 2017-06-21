#include <QObject>
#include <QIODevice>

class QNetworkAccessManager;

class DatasportHtmlGetter : public QObject
{
    Q_OBJECT
public:
    DatasportHtmlGetter(QObject * parent = nullptr);

    void get(int competitionId);

public slots:
    void onFinished();

private:
    void getChunk();

    QString rawHtml;
    QNetworkAccessManager * networkAccessManager;
    int chunks;
    int competitionId;
};
