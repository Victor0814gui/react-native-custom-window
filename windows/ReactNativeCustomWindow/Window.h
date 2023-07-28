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

namespace Window {
    REACT_MODULE(FullscreenModule, L"fullscreen");
    struct FullscreenModule final {  
      
        winrt::Microsoft::ReactNative::ReactContext context;

        REACT_INIT(Initialize,L"init");
        void Initialize(const winrt::Microsoft::ReactNative::ReactContext& reactContext) noexcept;

        REACT_METHOD(ExtendView_Click, L"enableExtend");
        void ExtendView_Click() noexcept;
        

        REACT_METHOD(TitlebarColor, L"TitlebarColor");
        void TitlebarColor( uint8_t a , uint8_t r ,uint8_t g, uint8_t b) noexcept;

        REACT_METHOD(AddBackButton, L"addBackButton");
        void AddBackButton() noexcept;

        REACT_METHOD(RemoveBackButton, L"removeBackButton");
        void RemoveBackButton() noexcept;

        REACT_METHOD(RemoveBackButton, L"disabledBackButton");
        void DisabledBackButton() noexcept;

        REACT_METHOD(RestoreExtendView_Click, L"disableExtend");
        void RestoreExtendView_Click() noexcept;



        REACT_METHOD(Full, L"full");
        void Full() noexcept;

        REACT_METHOD(setSize, L"setWindowSize");
        void setWindowSize(float  width, float  height) noexcept;

        static std::optional<Windows::UI::Color> ParseColor(std::string color);
    }
}