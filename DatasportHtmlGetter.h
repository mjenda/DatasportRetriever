#include <QObject>
#include <QIODevice>

#include <DatasportData.hpp>

class QNetworkAccessManager;

class DatasportHtmlGetter : public QObject
{
    Q_OBJECT
public:
    DatasportHtmlGetter(QObject * parent = nullptr);

    void get(int competitionId);

public slots:
    void onFinished();

signals:
    void finished(const DatasportData & data);

private:
    void getChunk();

    QString rawHtml;
    QNetworkAccessManager * networkAccessManager;
    int chunks;
    int competitionId;
};
