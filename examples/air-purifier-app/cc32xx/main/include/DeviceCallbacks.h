/*
 *
 *    Copyright (c) 2023 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#pragma once

#include <CHIPDeviceManager.h>
#include <platform/CHIPDeviceLayer.h>

class DeviceCallbacks : public chip::DeviceManager::CHIPDeviceManagerCallbacks
{
public:
    void DeviceEventCallback(const chip::DeviceLayer::ChipDeviceEvent * event, intptr_t arg);
};

class DeviceCallbacksDelegate
{
public:
    static DeviceCallbacksDelegate & Instance()
    {
        static DeviceCallbacksDelegate instance;
        return instance;
    }
    DeviceCallbacksDelegate * mDelegate = nullptr;
    void SetAppDelegate(DeviceCallbacksDelegate * delegate) { mDelegate = delegate; }
    DeviceCallbacksDelegate * GetAppDelegate() { return mDelegate; }
};
