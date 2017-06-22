#include <QObject>
#include <QIODevice>

#include <vector>

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
    void finished(const std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> & data);

private:
    void getChunk();

    QString rawHtml;
    QNetworkAccessManager * networkAccessManager;
    int chunks;
    int competitionId;
};
