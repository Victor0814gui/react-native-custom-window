#pragma once

#include "pch.h"
#include "NativeModules.h"

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



namespace WindowRN {
    REACT_MODULE(WindowRNModule, L"window");
    struct WindowRNModule final {  
      
        winrt::Microsoft::ReactNative::ReactContext context;

        REACT_INIT(Initialize,L"init");
        void Initialize(const winrt::Microsoft::ReactNative::ReactContext& reactContext) noexcept
        {
        context = reactContext;
        }     

        REACT_METHOD(Full, L"fullscreen");
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

        REACT_METHOD(SetSize, L"setSize");
        void SetSize(float  w, float  h) noexcept
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
