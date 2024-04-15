PointSDK v16.0.0 (204)
# SDK Version 16.0.0

We are excited to announce the release of Point SDK v16.0.0. This major update provides better architecture support with our migration to `XCFramework` for CocoaPods and Carthage and significantly enhances the data available in the `BDPGeoTriggeringEventDelegate` callbacks and new Tempo `tempoTrackingDidUpdate` callback. Here are the key highlights:

## New Features

- **Improved Architecture Support:** Migrated to `XCFramework` for both CocoaPods and Carthage, significantly improving support for multiple architectures.
- **Enhanced Geo-Triggering Data:** The `BDPGeoTriggeringEventDelegate` callbacks have been updated with more useful information to enhance your use cases.
- **New Tempo Tracking Callback:** Added a new callback `tempoTrackingDidUpdate` to `BDPTempoTrackingDelegate` with customer’s ETA data.
- **New Destination Information:** Each `BDZoneInfo` now contains destination information accessible via `BDLocationManager.instance().zoneInfos`.
- **Support iOS 17 SDK:** Xcode 15 and iOS 17 SDK

## Changes

- The `fences` property of `BDZoneInfo` is now non-optional in Swift.
- Return a new structure `GeoTriggerEvent` in the `didEnterZone` and `didExitZone` callbacks that replaces `BDZoneEntryEvent` and `BDZoneExitEvent`.
- Replaced the `onZoneInfoUpdate(zoneInfos)` callback with `didUpdateZoneInfo()`. The `zoneInfos` is no longer returned as part of this callback, access it via `BDLocationManager.instance().zoneInfos` instead.
- Custom Event Meta Data is cleared when the SDK resets.

## Deprecated Features

- **iOS 11 Support Discontinued:** The minimum deployment target is now iOS 12.
- **Feature Removals:**
  - Real-time Data Sync feature
  - URL Action and Message Action
  - The `BDPointBackgroundLocationEnabledForWhenInUseKey` key in `Info.plist` (to set enable the Background Location Indicator)
- **Deprecated Classes and Functions Removed:** Several deprecated classes and functions have been removed, providing a cleaner API.

Please refer to the detailed release notes and our updated documentation for more information. We appreciate your feedback and are here to assist you with any questions.
