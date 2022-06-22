//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BDGeospatialUnits.h"

@class BDZoneInfo;
@class BDFenceInfo;
@class BDBeaconInfo;
@class BDLocationInfo;

/**
  Defines the call-backs which <b>Point SDK</b> makes to inform the Application of location-related events.

  Assign your own implementation of this protocol to the @ref BDLocationManager#locationDelegate "locationDelegate" property of the
  shared `BDLocationManager` instance, to handle location related callbacks.

  Callbacks inform the application when:
  - ...new Zones have been received from <b>Canvas</b>
  - ...the user has triggered a <b>Custom Notification</b> action
*/
__attribute__((deprecated("First deprecated in 15.4.0. Please refer to each deprecated methods for more information")))
@protocol BDPLocationDelegate <NSObject>

@optional

/**
 * Called whenever new `BDZoneInfo` "zone info" is received from <b>Canvas</b>.
 *
 * This occurs immediately after the <b>Point SDK</b> successfully authenticates, and repeats when the rule download
 * time interval is reached or significant distance has been travelled.
 *
 * This is a value that you set when creating the Application in the Canvas web-interface, and determines how often the Zone data
 * will be refreshed on the device.
 *
 * @param zoneInfos A collection of `BDZoneInfo` objects, corresponding to the Zones you created for this application, in the
 * <b>Canvas</b> web-interface.
 */
- (void)didUpdateZoneInfo: (NSSet *)zoneInfos
__attribute__((deprecated("First deprecated in 15.4.0 - Features migrated to `-[BDPGeoTriggeringEventDelegate onZoneInfoUpdate:]` method")));

/**
 * Implement this method to provide your own <b>Custom Action</b> when a Zone is triggered by entering a Fence.
 *
 * This method and `-[BDPLocationDelegate didCheckIntoBeacon:inZone:atLocation:withProximity:willCheckOut:withCustomData:]` are both optional.<br/>
 * Implement them according to whether you have Custom Actions in your geo-location scenario, and whether those actions
 * may be triggered by entering Fences, Beacon proximities, or both.
 *
 * <b>For clarity</b>: When a user's device checks into a `BDZoneInfo` "Zone", this method is called only if
 * <b>Custom Action</b> is chosen as one of the `BDZoneInfo` "Zone"'s Actions in the <b>Canvas</b> web-interface.
 *
 * @param fence The fence that the user entered in order to trigger this custom action.
 * @param zoneInfo The zone containing the entered fence.
 * @param location The location relevant information of the device when the custom action was triggered.
 * @param willCheckOut Whether a subsequent Check Out callback is expected when the device moves a significant distance away from the Fence.
 * @param customData The custom fields setup from "Dashboard" in the <b>Canvas</b> web-interface.
 */
- (void)didCheckIntoFence: (BDFenceInfo *)fence
                   inZone: (BDZoneInfo *)zoneInfo
               atLocation: (BDLocationInfo *)location
             willCheckOut: (BOOL)willCheckOut
           withCustomData: (NSDictionary *)customData
__attribute__((deprecated("First deprecated in 15.4.0 - Feature migrated to `-[BDPGeoTriggeringEventDelegate didEnterZone:]`")));

/// This method has been deprecated as of version 1.9.4; it will be removed in a future version.
- (void)didCheckIntoFence: (BDFenceInfo *)fence
                   inZone: (BDZoneInfo *)zoneInfo
             atCoordinate: (BDLocationCoordinate2D)coordinate
                   onDate: (NSDate *)date
             willCheckOut: (BOOL)willCheckOut
           withCustomData: (NSDictionary *)customData
__attribute__((deprecated("First deprecated in 1.9.4 - Feature migrated to `-[BDPGeoTriggeringEventDelegate didEnterZone:]`")));

/**
 * Implement this method to provide your own <b>Custom Action</b> when checking out of fence.
 *
 * This method and `-[BDPLocationDelegate didCheckOutFromBeacon:inZone:withProximity:onDate:withDuration:withCustomData:]` are both optional.
 * Implement them according to whether you have a fence that has been configured with Check Out set.
 *
 * @param fence The fence that the user checked out of in order to trigger this custom action.
 * @param zoneInfo The zone containing the entered fence.
 * @param date The date and time when the custom action was triggered.
 * @param checkedInDuration The dwell time minutes of the device within a fence.
 * @param customData The custom fields setup from "Dashboard" in the <b>Canvas</b> web-interface.
 */
- (void)didCheckOutFromFence: (BDFenceInfo *)fence
                      inZone: (BDZoneInfo *)zoneInfo
                      onDate: (NSDate *)date
                withDuration: (NSUInteger)checkedInDuration
              withCustomData: (NSDictionary *)customData
__attribute__((deprecated("First deprecated in 15.4.0 - Feature migrated to `-[BDPGeoTriggeringEventDelegate didExitZone:]`")));

/**
 * Implement this method to provide your own <b>Custom Action</b> when a Zone is triggered by entering the configured proximity of a Beacon.
 *
 * This configuration can be made in the Management section of each Zone in the <b>Canvas</b> web-interface.
 *
 * This method and `-[BDPLocationDelegate didCheckIntoFence:inZone:atLocation:willCheckOut:withCustomData:]` are both optional.
 * Implement them according to whether you have Custom Actions in your geo-location scenario, and whether those actions
 * may be triggered by entering Fences, Beacon proximities or both.
 *
 * <b>For clarity</b>: When a user's device checks into a `BDZoneInfo` "Zone", this method is called only if
 * <b>Custom Action</b> is chosen as one of the `BDZoneInfo` "Zone"'s Actions in the <b>Canvas</b> web-interface.
 *
 * @param beacon The beacon that the user entered the required proximity of, in order to trigger this custom action.
 * @param zoneInfo The zone containing the beacon in proximity.
 * @param locationInfo The location of beacon when the custom action was triggered.
 * @param proximity The proximity of the beacon when the custom action was triggered.
 * @param willCheckOut Whether a subsequent Check Out callback is expected when the device moves outside of the Beacon's range.
 * @param customData The custom fields setup from "Dashboard" in the <b>Canvas</b> web-interface.
 */
- (void)didCheckIntoBeacon: (BDBeaconInfo *)beacon
                    inZone: (BDZoneInfo *)zoneInfo
                atLocation: (BDLocationInfo *)locationInfo
             withProximity: (CLProximity)proximity
              willCheckOut: (BOOL)willCheckOut
            withCustomData: (NSDictionary *)customData
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

- (void)didCheckIntoBeacon: (BDBeaconInfo *)beacon
                    inZone: (BDZoneInfo *)zoneInfo
             withProximity: (CLProximity)proximity
                    onDate: (NSDate *)date
              willCheckOut: (BOOL)willCheckOut
            withCustomData: (NSDictionary *)customData
__attribute__((deprecated("First deprecated in 1.9.4 - It will be removed in a future version")));

/**
 * Implement this method to provide your own <b>Custom Action</b> when checking out of beacon.
 *
 * This method and  `-[BDPLocationDelegate didCheckOutFromFence:inZone:onDate:withDuration:withCustomData:]` are both optional.
 * Implement them according to whether you have a beacon that has been configured with Check Out set.
 *
 * @param beacon The beacon that the user checked out of in order to trigger this custom action.
 * @param zoneInfo The zone containing the entered fence.
 * @param proximity The proximity of the beacon when the check-in was triggered.
 * @param date The date and time when the custom action was triggered.
 * @param checkedInDuration The dwell time minutes of the device within the range of a beacon.
 * @param customData The custom fields setup from "Dashboard" in the <b>Canvas</b> web-interface.
 */
- (void)didCheckOutFromBeacon: (BDBeaconInfo *)beacon
                       inZone: (BDZoneInfo *)zoneInfo
                withProximity: (CLProximity)proximity
                       onDate: (NSDate *)date
                 withDuration: (NSUInteger)checkedInDuration
               withCustomData: (NSDictionary *)customData
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/**
 * These methods can be implemented to monitor whether the Bluetooth
 * capabilities of the device are in a valid state when utilising the SDK's beacon functionality.
 *
 * If the configured location of a beacon is near the device, then `-[BDPLocationDelegate didStartRequiringUserInterventionForBluetooth]` will be called.
 *
 * From the version 15.0.0 the SDK does not maintain Bluetooth enablement state. The boolean `isBluetoothEnabled` is removed from the SDK.
 *
 * Since then, it is an app responsibility to check the Bluetooth state and require user interraction in the most appropriate way.
 *
 * Thereafter, if the device leaves proximity of the beacon, then  `-[BDPLocationDelegate didStopRequiringUserInterventionForBluetooth is called.
 */
- (void)didStartRequiringUserInterventionForBluetooth
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/**
 * To preserve the energy and minimise the battery impact, it is recommended to turn off Bluetooth if the application is not using it.
 *
 * However, there might be other apps or peripheral using the Bluetooth. Thus the user  decides whenever to keep it enabled or disabled.
 *
 * Please refer to  `-[BDPLocationDelegate didStartRequiringUserInterventionForBluetooth]`.
 */
- (void)didStopRequiringUserInterventionForBluetooth
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/**
 * These methods can be implemented to monitor whether iOS Location Services are in a valid state while the SDK is authenticated with Canvas.
 *
 * If Point SDK is authenticated with Canvas and Location Services have not been enabled or set to "Never" or "While Using"
 * then  `didStartRequiringUserInterventionForLocationServicesAuthorizationStatus:` will be called.
 *
 * Thereafter, if Location Services have been set to "Always Allow", or if Point SDK logs out from the authenticated state, then  `-[BDPLocationDelegate didStopRequiringUserInterventionForLocationServicesAuthorizationStatus:]` is called.
 *
 * If Location Services are both required and enabled, then these callbacks will not be invoked.
 *
 * @param authorizationStatus The current authorization status of the calling application.
 */
- (void)didStartRequiringUserInterventionForLocationServicesAuthorizationStatus: (CLAuthorizationStatus)authorizationStatus
__attribute__((deprecated("First deprecated in 15.4.0 - Feature replaced by `-[BDPBluedotServiceDelegate locationAuthorizationDidChangeFromPreviousStatus:toNewStatus:]`")));

/// Please refer to  `-[BDPLocationDelegate didStartRequiringUserInterventionForLocationServicesAuthorizationStatus:]`.
- (void)didStopRequiringUserInterventionForLocationServicesAuthorizationStatus: (CLAuthorizationStatus)authorizationStatus
__attribute__((deprecated("First deprecated in 15.4.0 - Feature replaced by `-[BDPBluedotServiceDelegate locationAuthorizationDidChangeFromPreviousStatus:toNewStatus:]`")));

/**
 * These methods can be implemented to monitor whether the iOS 'Low Power Mode' has been enabled while the SDK is authenticated with Canvas.
 *
 * The callback is required because Low Power mode negatively impacts the timeliness and precision of Point SDK, which your Application may need to communicate to the user.
 *
 * If Point SDK is authenticated with Canvas and iOS has been switched to 'Low Power mode', then  `didStartRequiringUserInterventionForPowerMode` will be called.
 *
 * Thereafter, if the user switches off 'Low Power mode', then  `-[BDPLocationDelegate didStopRequiringUserInterventionForPowerMode]` is called.
 */
- (void)didStartRequiringUserInterventionForPowerMode
__attribute__((deprecated("First deprecated in 15.4.0 - Feature replaced by `-[BDPBluedotServiceDelegate lowPowerModeDidChange:]`")));

/// Please refer to  `-[BDPLocationDelegate didStartRequiringUserInterventionForPowerMode]`.
- (void)didStopRequiringUserInterventionForPowerMode
__attribute__((deprecated("First deprecated in 15.4.0 - Feature replaced by `-[BDPBluedotServiceDelegate lowPowerModeDidChange:]`")));

@end
