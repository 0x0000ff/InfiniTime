#pragma once
#include <lvgl/lvgl.h>
#include <components/settings/Settings.h>

namespace Pinetime {
  namespace Applications {
    namespace Widgets {
      class Counter {
      public:
        Counter(int min, int max, Controllers::Settings& settingsController);

        void Create(uint8_t (Controllers::Settings::* getRefrnce)(), void (Controllers::Settings::* setRefrnce)(uint8_t));
        void Increment();
        void Decrement();
        void SetValue(uint8_t newValue);
        void HideControls();
        void ShowControls();

        int GetValue() const {
          return value;
        }

        lv_obj_t* GetObject() const {
          return counterContainer;
        };

      private:
        void UpdateLabel();

        lv_obj_t* counterContainer;
        lv_obj_t* upBtn;
        lv_obj_t* downBtn;
        lv_obj_t* number;
        lv_obj_t* upperLine;
        lv_obj_t* lowerLine;
        lv_point_t linePoints[2];
        uint8_t value = 0;
        int min;
        int max;

        Controllers::Settings& settingsController;
        uint8_t (Controllers::Settings::* getPtr)() = nullptr;
        void (Controllers::Settings::* setPtr)(uint8_t) = nullptr;
      };
    }
  }
}
