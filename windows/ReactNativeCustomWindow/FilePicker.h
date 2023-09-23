#pragma once

#include "NativeModules.h"

#include "pch.h"
#include "FilePicker.h"
#include <filesystem>
#include <windows.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Pickers.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.System.h>
#include <windows.h>

using namespace winrt;
using namespace winrt::Windows::Storage;
using namespace winrt::Windows::Foundation;
using namespace Windows::Storage::Pickers;
using namespace Windows::System;
using namespace Windows::UI::Xaml;

namespace FilePicker {
    REACT_MODULE(FilePickerModule, L"FilePicker");
    struct FilePickerModule final {
        winrt::Microsoft::ReactNative::ReactContext context;

        REACT_INIT(Initialize,L"init");
        void Initialize(const winrt::Microsoft::ReactNative::ReactContext& reactContext) noexcept
        {
            context = reactContext;
        }

        REACT_METHOD(pickFile, L"pickFile");
        void pickFile(winrt::Microsoft::ReactNative::ReactPromise<std::string> promise) noexcept
        {

                  auto jsDispatcher = context.JSDispatcher();

                  context.UIDispatcher().Post([promise, jsDispatcher] {
                        FileOpenPicker filePicker;
                        filePicker.ViewMode(PickerViewMode::Thumbnail);
                        filePicker.FileTypeFilter().ReplaceAll({ L".jpg", L".jpeg", L".png" }); // Allowed File types
                        filePicker.SuggestedStartLocation(PickerLocationId::Downloads);

                    //StorageFile


                            auto asyncOperation = filePicker.PickSingleFileAsync();
                            asyncOperation.Completed([jsDispatcher, promise](const IAsyncOperation<StorageFile>& asyncOp, AsyncStatus status) {
                                switch (status) {
                                case AsyncStatus::Completed: {
                                    StorageFile text = asyncOp.GetResults();

                                    jsDispatcher.Post(
                                        [promise, text] { promise.Resolve(winrt::to_string(text.Path())); });
                                    break;
                                }
                                case AsyncStatus::Canceled: {
                                    jsDispatcher.Post([promise] { promise.Reject(React::ReactError()); });
                                    break;
                                }
                                case AsyncStatus::Error: {
                                    auto message = std::wstring(winrt::hresult_error(asyncOp.ErrorCode()).message());
                                    jsDispatcher.Post([promise, message] { promise.Reject(message.c_str()); });
                                    break;
                                }
                                case AsyncStatus::Started: {
                                    assert(false); // should never happen
                                }
                                }
                            });

                 });
        }
    };
}