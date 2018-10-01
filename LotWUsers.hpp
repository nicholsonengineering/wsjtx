#ifndef LOTW_USERS_HPP_
#define LOTW_USERS_HPP_

#include <boost/core/noncopyable.hpp>
#include <QObject>
#include "pimpl_h.hpp"

class QString;
class QDate;
class Configuration;
class QNetworkAccessManager;

//
// LotWUsers - Lookup Logbook of the World users
//
class LotWUsers final
  : public QObject
{
  Q_OBJECT

public:
  LotWUsers (Configuration const * configuration, QNetworkAccessManager *, QObject * parent = 0);
  ~LotWUsers ();

  void download_new_file ();

  // returns true if the specified call sign 'call' has uploaded their
  // log to LotW in the last 'uploaded_since_days' days
  Q_SLOT bool user (QString const& call, qint64 uploaded_since_days) const;

  Q_SIGNAL void LotW_users_error (QString const& reason) const;

private:
  class impl;
  pimpl<impl> m_;
};

#endif
