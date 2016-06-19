#include "about.h"

#include <QCoreApplication>
#include <QString>

#include "revision_utils.hpp"

#include "ui_about.h"
#include "moc_about.cpp"

CAboutDlg::CAboutDlg(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CAboutDlg)
{
  ui->setupUi(this);

  ui->labelTxt->setText ("<html><h2>"
                         + QString {"WSJT-X v"
                             + QCoreApplication::applicationVersion ()
                             + " " + revision ()}.simplified ()
                         + "</h2>\n\n"
                         "WSJT-X implements a number of digital modes designed for <br>"
                         "weak-signal Amateur Radio communication.  <br><br>"
                         "&copy; 2001-2016 by Joe Taylor, K1JT, with grateful <br>"
                         "acknowledgment for contributions from AC6SL, AE4JY, <br>"
                         "DJ0OT, G4KLA, G4WJS, IW3RAB, K3WYC, K9AN, KA6MAL, <br>"
                         "KA9Q, KB1ZMX, KD6EKQ, KI7MT, KK1D, ND0B, PY2SDR, <br>"
                         "VK3ACF, VK4BDJ, W4TI, W4TV, and W9MDB.<br><br>"
                         "WSJT-X is licensed under the terms of Version 3 <br>"
                         "of the GNU General Public License (GPL) <br>"
                         "https://www.gnu.org/licenses/gpl-3.0.txt");
}

CAboutDlg::~CAboutDlg()
{
}