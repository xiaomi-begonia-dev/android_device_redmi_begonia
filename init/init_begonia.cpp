/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>
#include <android-base/logging.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::GetProperty;
int property_set(const char *key, const char *value) {
    return __system_property_set(key, value);
}

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void load_device_properties() {
    // Override build fingerprint
    property_override("ro.build.fingerprint", "google/raven/raven:13/TP1A.220905.004/8927612:user/release-keys");

    // Override safety props
    property_override("ro.oem_unlock_supported", "0");
    property_override("ro.boot.flash.locked", "1");
    property_override("ro.boot.verifiedbootstate", "green");
    property_override("ro.boot.veritymode", "enforcing");
    property_override("ro.boot.vbmeta.device_state", "locked");
    property_override("ro.boot.warranty_bit", "0");
    property_override("ro.warranty_bit", "0");
    property_override("ro.debuggable", "0");
    property_override("ro.secure", "1");
    property_override("ro.adb.secure", "1");
    property_override("ro.build.type", "user");
    property_override("ro.build.flavor", "begonia-user");
    property_override("ro.build.keys", "release-keys");
    property_override("ro.build.tags", "release-keys");
    property_override("ro.system.build.tags", "release-keys");
    property_override("ro.vendor.boot.warranty_bit", "0");
    property_override("ro.vendor.warranty_bit", "0");
    property_override("vendor.boot.vbmeta.device_state", "locked");
    property_override("vendor.boot.verifiedbootstate", "green");
}

void vendor_load_properties() {
    load_device_properties();
}
