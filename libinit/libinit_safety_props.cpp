/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/sysinfo.h>
#include <libinit_utils.h>

#include <libinit_safety_props.h>

void load_device_properties() {
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
