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

          REACT_METHOD(setSize, L"windowSize");
          void WindowSize(float  w, float  h) noexcept
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
