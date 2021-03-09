/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __QCustomAction_h
#define __QCustomAction_h

// PlusLib includes
#include <PlusConfigure.h>
#include <vtkPlusChannel.h>

// Qt includes
#include <QAction>

class QPlusChannelAction : public QAction
{
  Q_OBJECT

public:
  QPlusChannelAction(const QString& text, QObject* parent, bool aIsSeparator = false, vtkPlusChannel* ownerChannel = NULL);
  bool IsSeparator()
  {
    return m_IsSeparator;
  }

public slots:
  void activated();

signals:
  void channelSelected(vtkPlusChannel* aChannel);

private:
  bool m_IsSeparator;
  vtkPlusChannel* m_OwnerChannel;
};

#endif // __QCustomAction_h