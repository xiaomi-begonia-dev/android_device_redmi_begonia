/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/sysinfo.h>
#include <libinit_utils.h>
#include <libinit_safety_props.h>

/* From Magisk@jni/magiskhide/hide_utils.c */
static const char *props[] = {
    "ro.oem_unlock_supported",
    "ro.boot.flash.locked",
    "ro.boot.verifiedbootstate",
    "ro.boot.veritymode",
    "ro.boot.vbmeta.device_state",
    "ro.boot.warranty_bit",
    "ro.warranty_bit",
    "ro.debuggable",
    "ro.secure",
    "ro.adb.secure",
    "ro.build.type",
    "ro.build.flavor",
    "ro.build.keys",
    "ro.build.tags",
    "ro.system.build.tags",
    "ro.vendor.boot.warranty_bit",
    "ro.vendor.warranty_bit",
    "vendor.boot.vbmeta.device_state",
    "vendor.boot.verifiedbootstate",
    NULL
};

static const char *values[] = {
    "0",
    "1",
    "green",
    "enforcing",
    "locked",
    "0",
    "0",
    "0",
    "1",
    "1",
    "user",
    "begonia-user",
    "release-keys",
    "release-keys",
    "release-keys",
    "0",
    "0",
    "locked",
    "green",
    NULL
};

void workaround_safety_properties() {
    // Hide all sensitive props
    for (int i = 0; props[i]; ++i) {
        property_override(props[i], values[i]);
    }
}
