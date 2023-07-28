#pragma once

#include "pch.h"
//#include "NativeModules.h"

#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.UI.ViewManagement.h"
#include "winrt/Windows.UI.h"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Core.h"
#include "winrt/Windows.UI.Xaml.Navigation.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include "winrt/Windows.ApplicationModel.Core.h"


using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::ApplicationModel::Core;



namespace WindowModule {
    REACT_MODULE(FullscreenModule, L"fullscreen");
    struct FullscreenModule final {  
      
          winrt::Microsoft::ReactNative::ReactContext context;

          REACT_INIT(Initialize,L"init");
          void Initialize(const winrt::Microsoft::ReactNative::ReactContext& reactContext) noexcept
          {
            context = reactContext;
          }

          REACT_METHOD(RestoreExtendView_Click, L"disableExtend");
          void RestoreExtendView_Click() noexcept
          {
              context.UIDispatcher().Post([] {

                  CoreApplication::GetCurrentView().TitleBar().ExtendViewIntoTitleBar(false);

              });
          }


          REACT_METHOD(ExtendView_Click, L"enableExtend");
          void ExtendView_Click() noexcept
          {
              context.UIDispatcher().Post([] {
                  CoreApplication::GetCurrentView().TitleBar().ExtendViewIntoTitleBar(true);

              });
          }

          REACT_METHOD(TitlebarColor, L"TitlebarColor");
          void TitlebarColor(
              std::string background,
              std::string inativeBackground,
              std::string backgroundButton,
              std::string backgroundButtonInative
          ) noexcept
          {             

              context.UIDispatcher().Post([background, inativeBackground, backgroundButton, backgroundButtonInative] {
                  auto titleBar = ApplicationView::GetForCurrentView().TitleBar();

                  Color Bg = ParseColor(background);
                  Color BgInative = ParseColor(inativeBackground);
                  Color BgButton = ParseColor(backgroundButton);

                  Color BgButtonInative = ParseColor(backgroundButtonInative);

                  if (background.size() != 0) {
                      titleBar.BackgroundColor(ColorHelper::FromArgb(Bg.A, Bg.R, Bg.G, Bg.B));
                  }

                  if (inativeBackground.size() != 0) {
                      titleBar.InactiveBackgroundColor(ColorHelper::FromArgb(BgInative.A, BgInative.R, BgInative.G, BgInative.B));
                  }

                  if (backgroundButtonInative.size() != 0) {
                      titleBar.ButtonInactiveBackgroundColor(ColorHelper::FromArgb(BgButtonInative.A, BgButtonInative.R, BgButtonInative.G, BgButtonInative.B));
                  }
                    //titleBar.ForegroundColor(ColorHelper::FromArgb(a, r, g, b));
                    titleBar.InactiveBackgroundColor(ColorHelper::FromArgb(BgInative.A, BgInative.R, BgInative.G, BgInative.B));
                    //titleBar.InactiveForegroundColor(ColorHelper::FromArgb(a, r, g, b));
                    titleBar.ButtonBackgroundColor(ColorHelper::FromArgb(BgButton.A, BgButton.R, BgButton.G, BgButton.B));
                    // titleBar.ButtonHoverBackgroundColor(Colors::Transparent);
                    // titleBar.ButtonPressedBackgroundColor(Colors::Transparent);
                    titleBar.ButtonInactiveBackgroundColor(ColorHelper::FromArgb(BgButtonInative.A, BgButtonInative.R, BgButtonInative.G, BgButtonInative.B));

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
                auto currentView = winrt::Windows::UI::Core::SystemNavigationManager::GetForCurrentView();
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

           static Windows::UI::Color ParseColor(std::string color)
          {
             
                  Color result;
                  result.R = std::stoi(color.substr(1, 2), 0, 16);
                  result.G = std::stoi(color.substr(3, 2), 0, 16);
                  result.B = std::stoi(color.substr(5, 2), 0, 16);
                  result.A = 0xff;
                  return result;           
                 
          }          

    };
}
