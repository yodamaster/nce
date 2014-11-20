#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "ui_mainwindow.h"
#include "nce.hxx"
#include "classinfo.hxx"
#include <QTextEdit>
#include "ui_import.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "shanbay.hxx"
#include "ui_wordinfo.h"
#include "ui_sentence.h"

#include <phonon>
class QWebView;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Nce nce;
    void init();
public slots:
    void showInfo(int row,int col);
    void showRead();
    void import();
    void sentence();
    void parseSentence();
    void indent();
    void selectedWord();
    void getWordDescription(const QString & text);
    void showDescription();
    void readReply(QNetworkReply*);

    void authSuccess();
    void urlChanged(QUrl);
    void getToken();
    void getWord(const QString & text);
    void showWord(const QString & text);
    void playMp3(const QString & text);
    void addWord();
    void searchWord();
private:

    Ui::MainWindow ui;
    ClassInfo classInfo_;
    QWidget import_;
    Ui::ImportUi importUi;
    QString path_;
    QNetworkAccessManager netManager_;
    QWebView* webview_;
    Shanbay * shanbay_;
    QPushButton *infoButton_;
    Ui::WordInfo wordui;
    Phonon::MediaObject mediaObj_;
    Phonon::AudioOutput output_;
    Phonon::MediaSource source_;

    QString lastSelectWord_;
    QTextCursor lastTextCursor_;
    QWidget* sentence_;
    Ui::Sentence* sentenceUi_;
};
class Parse
{
public:
    Parse();
    ~Parse();

};
#endif // MAINWINDOW_HXX
