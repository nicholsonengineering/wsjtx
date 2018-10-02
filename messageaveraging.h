#ifndef MESSAGEAVERAGING_H
#define MESSAGEAVERAGING_H

#include <QWidget>

class QSettings;
class QFont;

namespace Ui {
  class MessageAveraging;
}

class MessageAveraging : public QWidget
{
public:
  explicit MessageAveraging(QSettings *, QFont const&, QWidget * parent = 0);
  ~MessageAveraging();
  void displayAvg(QString const&);
  void changeFont (QFont const&);
  void foxLogSetup(int nContest);
  void foxLabCallers(int n);
  void foxLabQueued(int n);
  void foxLabRate(int n);
  void foxAddLog(QString logLine);
  void contestAddLog(qint32 nContest, QString logLine);

protected:
  void closeEvent (QCloseEvent *) override;

private:
  void read_settings ();
  void write_settings ();
  void setContentFont (QFont const&);
  QSettings * settings_;
  QString m_title_;
  qint32  m_nLogged_=0;
  qint32  m_mult_=0;
  qint32  m_nContest_;

  QScopedPointer<Ui::MessageAveraging> ui;
};

#endif // MESSAGEAVERAGING_H
