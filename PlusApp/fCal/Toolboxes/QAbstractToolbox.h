/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __QAbstractToolbox_h
#define __QAbstractToolbox_h

#include <QApplication>

class fCalMainWindow;

//-----------------------------------------------------------------------------

enum ToolboxState
{
  ToolboxState_Uninitialized = 0,
  ToolboxState_Idle,
  ToolboxState_InProgress,
  ToolboxState_StartupDelay,
  ToolboxState_Done,
  ToolboxState_Error
};

//-----------------------------------------------------------------------------

/*! \class QAbstractToolbox
 * \brief This class is the super class of all the toolboxes for standard handling
 * \ingroup PlusAppFCal
 */
class QAbstractToolbox
{
public:
  /*! \brief Constructor */
  QAbstractToolbox(fCalMainWindow* aParentMainWindow)
  {
    m_BusyCursorSet = false;
    m_ParentMainWindow = aParentMainWindow;
    m_State = ToolboxState_Uninitialized;
  };

  /*! \brief Destructor */
  virtual ~QAbstractToolbox() { };

  /*! \brief Refresh contents (e.g. GUI elements) of toolbox according to the state in the toolbox controller - pure virtual function */
  virtual void RefreshContent() = 0;

  /*! \brief Load session data and update view when the toolbox is activated - pure virtual function */
  virtual void OnActivated() = 0;

  /*! \brief Close session data when the toolbox is deactivated - pure virtual function */
  virtual void OnDeactivated() = 0;


  /*! \brief Reset toolbox to initial state - virtual function */
  virtual void Reset()
  {
    SetState(ToolboxState_Idle);
  };

  /*! \brief Sets display mode (visibility of actors) according to the current state - pure virtual function */
  virtual void SetDisplayAccordingToState() = 0;

  /*!
  * \brief Properly sets new toolbox state
  * \param aState New state of the toolbox
  */
  void SetState(ToolboxState aState)
  {
    m_State = aState;
    SetDisplayAccordingToState();
  };

  /*!
  * \brief Get toolbox state
  * \return Current state
  */
  ToolboxState GetState()
  {
    return m_State;
  };

  void SetBusyCursor(bool busy)
  {
    if (!busy && m_BusyCursorSet)
    {
      QApplication::restoreOverrideCursor();
      m_BusyCursorSet = false;
    }
    else if (busy && !m_BusyCursorSet)
    {
      QApplication::setOverrideCursor(QCursor(Qt::BusyCursor));
      m_BusyCursorSet = true;
    }
  }

protected:
  //! Main window object
  fCalMainWindow* m_ParentMainWindow;

  //! Toolbox state
  ToolboxState    m_State;

  //! Helper for setting busy cursor instead of push/pop its state
  bool m_BusyCursorSet;
};

#endif