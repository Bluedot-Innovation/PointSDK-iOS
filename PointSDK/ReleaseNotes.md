PointSDK v16.0.0 (178)
# SDK Version 16.0.0 - RC4

## RC4
- Update CI to trigger both master + staging workflows in downstream Demo App + Host App
- Fix issue localEventTime can be produced in a wrong format due to device locale, e.g. `2023-06-09T2:23:41.764 PM` where it should be `2023-06-09T14:23:41.764`, causing failure in Rainbow requests.
- Fix bug properties of TempoTrackingUpdate are not accessible from Objective-C

## RC3
- Fix bug PercentageFilter not working 

## RC2
- Remove UniversalFramework and use XCFramework for all integrations (Cocoapods, Carthage, SPM)
- Update TestApp minimum deployment target to iOS 11
- Fix bug crossedFences includes duplicate crossings of the same fence
- Refactor Bluebar mode, expose a new flag `backgroundLocationAccessForWhileUsing: boolean` to enable/disable Bluebar mode for While Using permission.
- Override `setShowsBackgroundLocationIndicator:` so even if the main app sets this value to `true` for Always permission, the visual Bluebar will not show.
- Show current Location permission level (denied, always, while using...) in Test App -> Operations -> BG Location Access For While Using screen.

## RC1
- Added method `toJson()` to `GeoTriggerEvent` class to convert to Json String.
- Updated dev docs + Swift headers
- Added Helper function for quick access to entryEvent and exitEvent in GeoTriggerEvent in didEnterZone: and didExitZone: callbacks.

## Alpha 2
- Fixed an UI bug in Test App CEMD Configuration screen when the buttons Random, Add, Clear can appear clustered on some devices
- Fixed a crash bug in Test App CEMD Configuration screen when adding more than 20 items to SDK's CEMD 
- Fixed an error when the SDK fails to parse response from TempoStop event

## Alpha 1
- Fixed all warnings in Xcode project + Xcode Static Analyzer issues. Compiling the Xcode project should have no warnings now.
- Renamed `onZoneInfoUpdate` to `didUpdateZoneInfo` to be more inline with other callbacks: `didEnterZone` and `didExitZone`.
- Use SDK method to `sdkVersion` to determine SDK Upgrade scenario instead of Info.plist key ShortVersion as it can be replaced by the main app's version upon Appstore submission
- `didEnterZone:` and `didExitZone:` callbacks are now returning a new model `GeoTriggerEvent`, using (almost) the same structure sent to Rainbow. During this refactoring, ZoneCheckInOutAction will now handle both performing check in/out AND notifying callbacks to the application. Previously the latter task was done by applicationNotificationAction.
- `onZoneInfoUpdate` callback now will not include any data. Go to BDLocationManager.zoneInfos to access the latest downloaded zone infos.
- New `crossedFences` field in FenceEntered triggerEvent in the Rainbow EntryNotification when checkin happens. Each CrossFence includes: fenceId, fenceName, location, crossTime.
- New `tempoTrackingDidUpdate:` callback providing TempoTrackingUpdate to the application
- Change to show toast message instead of Alert dialog in Test App when receiving GeoTriggering/Tempo callbacks
- New `advertisingId` field in Rule request and Rainbow notification requests, also a new `AdvertisingID` field in Test App UI
- Report `didStopTrackingWithError:` with error `tempoNotEnabled` if Tempo requests receive 403 from Rainbow
- New CustomEventMetaData Configuration screen in Test App
- Clear customEventMetaData when SDK resets
- Replace mentioning of apiKey by projectId
- Remove deprecated code
- Delete Firebase Sync feature
- Delete all traces of beacon in source code. (except in old DataModel)
- Add new field `destination` in Ruleset download
- Delete some leftover legacy code
- Save `notificationPermission` in AppState
- Replace AppCenter Crashlytics by Firebase Crashlytics
- Replace GitHub Unit Test action by Bitrise
