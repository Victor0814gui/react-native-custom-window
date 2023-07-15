#pragma once

#include <hstring.h>
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.ApplicationModel.Activation.h"
#include "winrt/Windows.UI.Core.h"
#include "winrt/Windows.UI.ViewManagement.h"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Navigation.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "winrt/Windows.ApplicationModel.Core.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::ApplicationModel::Core;



namespace Fullscreen {
    REACT_MODULE(FullscreenModule, L"fullscreen");
    struct FullscreenModule final {  
      
      winrt::Microsoft::ReactNative::ReactContext context;

      REACT_INIT(Initialize,L"init");
      void Initialize(const winrt::Microsoft::ReactNative::ReactContext& reactContext) noexcept
      {
        context = reactContext;
      }



      REACT_METHOD(ExtendView_Click, L"enableExtend");
      void ExtendView_Click() noexcept
      {
          context.UIDispatcher().Post([] {

              auto titleBar = CoreApplication::GetCurrentView().TitleBar();

              titleBar.ExtendViewIntoTitleBar(true);

          });
      }

      REACT_METHOD(TitlebarColor, L"TitlebarColor");
      void TitlebarColor(
          uint8_t a ,
          uint8_t r ,
          uint8_t g,
          uint8_t b
      ) noexcept
      {
          context.UIDispatcher().Post([a, r, g, b] {
              //uint8_t a = 255;
              //uint8_t r = 46; 
              //uint8_t g = 46;
              //uint8_t b = 46;

              auto titleBar = ApplicationView::GetForCurrentView().TitleBar();
              titleBar.BackgroundColor(ColorHelper::FromArgb(a, r, g, b));
              titleBar.ForegroundColor(ColorHelper::FromArgb(a, r, g, b));
              titleBar.InactiveBackgroundColor(ColorHelper::FromArgb(a, r, g, b));
              titleBar.InactiveForegroundColor(ColorHelper::FromArgb(a, r, g, b));
              uint8_t buttonAlpha = 255;
              titleBar.ButtonBackgroundColor(ColorHelper::FromArgb(a, r, g, b));
              // titleBar.ButtonHoverBackgroundColor(Colors::Transparent);
              // titleBar.ButtonPressedBackgroundColor(Colors::Transparent);
              // titleBar.ButtonInactiveBackgroundColor(Colors::Transparent);

              // // Title bar button foreground colors. Alpha must be 255.
              // titleBar.ButtonForegroundColor(ColorHelper::FromArgb(255, 232, 211, 162));
              // titleBar.ButtonHoverForegroundColor(ColorHelper::FromArgb(0, 0, 0, 255));
              // titleBar.ButtonPressedForegroundColor(ColorHelper::FromArgb(255, 54, 60, 116));
              // titleBar.ButtonInactiveForegroundColor(ColorHelper::FromArgb(255, 232, 211, 162));

          });
      }



    REACT_METHOD(AddBackButton, L"addBackButton");
    void AddBackButton() noexcept
    {
        context.UIDispatcher().Post([] {
            auto currentView = SystemNavigationManager::GetForCurrentView();
            currentView.AppViewBackButtonVisibility(AppViewBackButtonVisibility::Visible);
        });
    }

    REACT_METHOD(RemoveBackButton, L"removeBackButton");
    void RemoveBackButton() noexcept
    {
        context.UIDispatcher().Post([] {
        auto currentView = SystemNavigationManager::GetForCurrentView();
        currentView.AppViewBackButtonVisibility(AppViewBackButtonVisibility::Collapsed);
        });
    }

    REACT_METHOD(RemoveBackButton, L"disabledBackButton");
      void DisabledBackButton() noexcept
      {
          context.UIDispatcher().Post([] {
            auto currentView = SystemNavigationManager::GetForCurrentView();
            currentView.AppViewBackButtonVisibility(AppViewBackButtonVisibility::Disabled);
          });
      }

      REACT_METHOD(RestoreExtendView_Click, L"disableExtend");
      void RestoreExtendView_Click() noexcept
      {
          context.UIDispatcher().Post([] {

              auto titleBar = CoreApplication::GetCurrentView().TitleBar();

              titleBar.ExtendViewIntoTitleBar(false);

          });
      }



      REACT_METHOD(Full, L"full");
      void Full() noexcept
      {
        context.UIDispatcher().Post([] {

          ApplicationView view = ApplicationView::GetForCurrentView();
          if (view.IsFullScreenMode())
          {
              view.ExitFullScreenMode();
              // The SizeChanged event will be raised when the exit from full screen mode is complete.
          }
          else
          {
            if (view.TryEnterFullScreenMode())
            {
                // The SizeChanged event will be raised when the entry to full screen mode is complete.
            }
            else
            {
            }
          }
        });
      }

      REACT_METHOD(setSize, L"setSize");
      void setSize(float  w, float  h) noexcept
      {

          context.UIDispatcher().Post([w,h] {

              

              ApplicationView view = ApplicationView::GetForCurrentView();
                  if (view.TryResizeView({ w,h }))
                  {
                  }
                  else
                  {
                  }
              });
      }
    };
}