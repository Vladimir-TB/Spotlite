#ifndef SPOTLITE_H
#define SPOTLITE_H

#define SPOTLITE_VERSION   "SpotLite v3.1.0"

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QList>
#include <QMap>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QSettings>
#include <QSet>
#include <QByteArray>
#include <QUrl>
#include <QVector>
#include <QJsonArray>
#include <QJsonValue>

class SpotNNTP;

struct NzbGetConfig
{
    bool enabled{false};
    QString host{QStringLiteral("127.0.0.1")};
    int port{6789};
    bool ssl{false};
    QString username;
    QString password;
    QString category;
    bool addPaused{false};
    int priority{0};
};

struct NzbGetQueueEntry
{
    int id{0};
    QString name;
    QString status;
    QString category;
    int priority{0};
    int sizeMB{0};
    int remainingMB{0};
    int downloadedMB{0};
    double health{0.0};
    double progress{0.0};
    double avgRateKB{0.0};
    bool paused{false};
};

struct NzbGetHistoryEntry
{
    int id{0};
    QString name;
    QString status;
    QString category;
    int sizeMB{0};
    QDateTime completedAt;
};

class SpotLite : public QObject
{
    Q_OBJECT
public:
    explicit SpotLite(QString datadir, bool portable = false, QObject *parent = 0);
    virtual ~SpotLite();
    QSqlDatabase *spotDatabase();
//    QSqlDatabase *cacheDatabase();
    void downloadArticle(const QByteArray &msgid, bool topofqueue = false);
    void downloadArticle(qint64 nr);
    int numNewPosts() const;
    int numNewEPosts() const;
    void reconnect();
    bool vacuumDB();
    void emptyCommentsList();
    QList<int> getCommentMsgNrs(const QByteArray &msgid);
    QSet<int> getCommentMsgIDnrs(const QByteArray &msgid);
    bool emptyDatabases();
    bool isOnWatchlist(int spotid);
    void addToWatchlist(int spotid);
    void removeFromWatchlist(int spotid);
    QSettings *settings();
    QByteArray bwListScript();
    bool inTransaction();
    void reloadFriendsAndFoes();
    bool isFriend(const QByteArray &userid) const;
    bool isFoe(const QByteArray &userid) const;
    void addFriend(const QByteArray &userid, const QByteArray &username);
    void banUser(const QByteArray &userid, const QByteArray &username, const QByteArray &reason = "");
    void exportDatabase(const QString &filename);
    bool importDatabase(const QString &filename);
    void deleteSpot(int spotid, const QString &reason = "", const QString &moderator = "", bool emitnewSpots = true);
    void deleteSpot(const QByteArray &msgid);
    void undeleteSpot(int spotid);
    void emptyTrash();
    void processNewSpots();
    SpotNNTP *nntp();
    void deleteSpam(int minid = -1, int mineid = -1);

signals:
    void articleData(const QByteArray &msgid, QByteArray data);
    void articleNotFound(const QByteArray &msgid);
    void error(int code, const QString &msg);
    void notice(int code, const QString &msg);
    void newSpots();
    void processingQueuedSpots();
    void nzbGetConfigChanged();

public slots:
    void onArticleData(const QByteArray &msgid, QByteArray data);
    void onHeaderLine(const QByteArray &line);
    void onGroupResponse(const QByteArray &group, qint64 min, qint64 max);
    void onXrover(qint64 nr, const QByteArray &references);
    void onXroverLine(qint64 nr, const QByteArray &references);
    void onXroverSpamLine(qint64 nr, const QByteArray &references);
    void onError(int error, const QString &msg, const QByteArray &msgid);
    void onArticleNotFound(const QByteArray &msgid);
    void onLoggedIn();
    void onRefreshTimer();
    void connectToServer();
    void onFilterDone();
    void announceBwListStatus();
    QString bwListStatusMessage(bool includeTimestamp = true) const;
    bool nzbGetConfigured() const;
    NzbGetConfig nzbGetConfig() const;
    void setNzbGetConfig(const NzbGetConfig &config);
    bool sendNzbToNzbGet(const QString &title, const QByteArray &nzbData, QString *errorMessage = nullptr) const;
    QVector<NzbGetQueueEntry> fetchNzbGetQueue(QString *errorMessage = nullptr) const;
    QVector<NzbGetHistoryEntry> fetchNzbGetHistory(QString *errorMessage = nullptr) const;
    bool editNzbGetQueue(const QString &command, const QList<int> &ids, const QString &param = QString(), QString *errorMessage = nullptr) const;

protected:
    QSqlDatabase _spotDatabase, _cacheDatabase, _commlistDatabase;
    QSqlQuery    _checkDuplicatesQuery, _insertQuery, _checkCommlistQuery, _echeckDuplicatesQuery, _einsertQuery, _checkSpotter, _insertSpotter;
    bool _tableExists(QSqlDatabase &db, const char *table);
    bool _indexExists(QSqlDatabase &db, const char *index);
    void _openDatabases();
    void _downloadQueue();
    void _cleanWatchlist();
    void _initDBsettings(QSqlDatabase &db);
    void _ensureBwListTables();
    void _refreshBwListsIfNeeded(bool force = false);
    bool _downloadAndStoreBwList(const QUrl &url, const QString &list);
    QByteArray _downloadUrl(const QUrl &url) const;
    bool _storeBwList(const QByteArray &data, const QString &list);
    int _bwListCount(const QString &list) const;
    QByteArray _serializeBwList(const QString &list) const;
    qint64 _bwListLastRefresh() const;
    QByteArray _generateBwListScript() const;
    void _loadNzbGetConfig() const;
    bool _nzbGetRequest(const QString &method, const QJsonArray &params, QJsonValue *result, QString *errorMessage = nullptr) const;
    void _writeNzbGetDebugDump(const QJsonObject &payload) const;
    void _prepareInsertQueries();
    QString _decodeUtf8(const QByteArray &s);
    QByteArray _fetchFromCache(const QByteArray &id);
    void _saveWatchlist();
    void _restoreWatchlist();
    int _getSpotterID(const QByteArray &pubkey, const QByteArray &name = "");

    QString _datadir;
    QList<QByteArray> _queue;
    SpotNNTP *_nntp;
    qint64 maxOnServer, xoverSentForMax, xoverLastReceived, startid;
    QTime _lastStatusUpdate;
    QTimer _refreshHeaderTimer;
    int _newposts, _neweposts;
    bool _transaction, _commlistTransaction, _nntpSwitch, _updateKnop, _uptodate, _filterhc, _filtermanycat;

    QMap<QByteArray, QList<int> > _commlist;
    QMap<QByteArray, int> _spamcountlist;
    QSettings _settings;
    qint64 cmaxOnServer, cxroverSentForMax, cxroverLastReceived;
    qint64 smaxOnServer, sxroverSentForMax, sxroverLastReceived;
    QString _filterHook;

    QSet<QByteArray> _friends, _foes;
    QList<QByteArray> watchlist_msgids, ewatchlist_msgids;
    QByteArray _bwListScriptCache;
    mutable qint64 _bwListCacheStamp{0};
    QTimer _bwListRefreshTimer;
    mutable NzbGetConfig _nzbGetConfig;
    mutable bool _nzbGetConfigLoaded{false};

    bool _portable;
};

#endif // SPOTLITE_H
