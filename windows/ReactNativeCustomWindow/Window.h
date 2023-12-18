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


namespace RN = winrt::Microsoft::ReactNative;

namespace WindowRN {
    REACT_MODULE(WindowRNModule, L"window");
    struct WindowRNModule final {

        RN::ReactContext context;

        REACT_INIT(Initialize, L"init");
        void Initialize(const RN::ReactContext& reactContext) noexcept
        {
            context = reactContext;
        }

        REACT_METHOD(Fullscreen, L"fullscreen")
        void Fullscreen(RN::ReactPromise<void> promise) noexcept
        {
            try {
                auto jsDispatcher = context.JSDispatcher();

                context.UIDispatcher().Post([promise, jsDispatcher] {
                    ApplicationView view = ApplicationView::GetForCurrentView();
                    bool isFullScreen = view.IsFullScreenMode();
                    if (isFullScreen)
                    {
                        view.ExitFullScreenMode();
                        jsDispatcher.Post([promise] { promise.Resolve(); });
                    }
                    else
                    {
                        view.TryEnterFullScreenMode();
                        jsDispatcher.Post([promise] { promise.Resolve(); });
                    }
                });
            }
            catch (const hresult_error& ex) {
                promise.Reject(RN::ReactError{ winrt::to_string(ex.message()).c_str() });
            }
        }

        REACT_METHOD(IsFullScreen, L"isFullScreen")
        void IsFullScreen(RN::ReactPromise<bool> promise) noexcept
        {
            try {
                auto jsDispatcher = context.JSDispatcher();
                context.UIDispatcher().Post([jsDispatcher,promise] {
                    ApplicationView view = ApplicationView::GetForCurrentView();
                    bool isFullScreen = view.IsFullScreenMode();
                    jsDispatcher.Post([promise, isFullScreen] { promise.Resolve(isFullScreen); });
                });
            }
            catch (const hresult_error& ex) {
                promise.Reject(RN::ReactError{ winrt::to_string(ex.message()).c_str() });
            }
        }

        REACT_METHOD(EnterFullscreen, L"enterFullscreen")
        void EnterFullscreen(RN::ReactPromise<void> promise) noexcept
        {
            try {
                auto jsDispatcher = context.JSDispatcher();

                context.UIDispatcher().Post([jsDispatcher, promise] {
                    ApplicationView view = ApplicationView::GetForCurrentView();
                    view.TryEnterFullScreenMode();
                    jsDispatcher.Post([promise] { promise.Resolve(); });
                });
            }
            catch (const hresult_error& ex) {
                promise.Reject(RN::ReactError{ winrt::to_string(ex.message()).c_str() });
            }
        }

        REACT_METHOD(LeaveFullscreen, L"leaveFullscreen")
        void LeaveFullscreen(RN::ReactPromise<void> promise) noexcept
        {
            try {
                auto jsDispatcher = context.JSDispatcher();
                context.UIDispatcher().Post([jsDispatcher, promise] {
                    ApplicationView view = ApplicationView::GetForCurrentView();
                    view.ExitFullScreenMode();
                    jsDispatcher.Post([promise] { promise.Resolve(); });
                });
            }
            catch (const hresult_error& ex) {
                promise.Reject(RN::ReactError{ winrt::to_string(ex.message()).c_str() });
            }
        }

        REACT_METHOD(SetSize, L"setSize")
        void SetSize(JSValueObject size, RN::ReactPromise<void> promise) noexcept
        {
            try {
                auto jsDispatcher = context.JSDispatcher();

                float width = size["width"].AsSingle();
                float height = size["height"].AsSingle();
                context.UIDispatcher().Post([jsDispatcher, width, height, promise] {

                    ApplicationView view = ApplicationView::GetForCurrentView();
                    view.TryResizeView({ width,height });
                    jsDispatcher.Post([promise] { promise.Resolve(); });
                });
            }
            catch (const hresult_error& ex) {
                promise.Reject(RN::ReactError{ winrt::to_string(ex.message()).c_str() });
            }
        };
    };
}
