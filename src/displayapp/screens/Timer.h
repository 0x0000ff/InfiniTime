#pragma once

#include "displayapp/screens/Screen.h"
#include "components/datetime/DateTimeController.h"
#include "systemtask/SystemTask.h"
#include "displayapp/LittleVgl.h"
#include "displayapp/widgets/Counter.h"
#include <lvgl/lvgl.h>

#include "components/timer/TimerController.h"

namespace Pinetime::Applications::Screens {
  class Timer : public Screen {
  public:
    Timer(DisplayApp* app, Controllers::TimerController& timerController, 
      Controllers::Settings& settingsController);
    ~Timer() override;
    void Refresh() override;
    void Reset();
    void ToggleRunning();
    void ButtonPressed();
    void MaskReset();

  private:
    void SetTimerRunning();
    void SetTimerStopped();
    void UpdateMask();
    Controllers::TimerController& timerController;
    Controllers::Settings& settingsController;

    lv_obj_t* msecTime;
    lv_obj_t* btnPlayPause;
    lv_obj_t* txtPlayPause;

    lv_obj_t* btnObjectMask;
    lv_obj_t* highlightObjectMask;
    lv_objmask_mask_t* btnMask;
    lv_objmask_mask_t* highlightMask;

    lv_task_t* taskRefresh;

    Widgets::Counter minuteCounter = Widgets::Counter(0, 59, settingsController);
    Widgets::Counter secondCounter = Widgets::Counter(0, 59, settingsController);

    bool buttonPressing = false;
    int maskPosition = 0;
    TickType_t pressTime;
  };
}
