//
//  BDPGeoTriggeringEventDelegate.h
//  BDPointSDK
//
//  Created by Duncan Lau on 31/7/20.
//  Copyright © 2020 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class BDZoneEntryEvent;
@class BDZoneExitEvent;
@class BDZoneInfo;

/**
  Defines the call-backs which Point SDK makes to inform the Application of Geotriggering events.

  Assign your own implementation of this protocol to the `BDLocationManager.geoTriggeringEventDelegate`  property of the
  shared `BDLocationManager` instance, to handle Geotriggering related callbacks.
*/
@protocol BDPGeoTriggeringEventDelegate <NSObject>

@optional
/**
 * Called whenever new `BDZoneInfo` "zone info" is received from <b>Canvas</b>.
 *
 * This occurs a short while after Start Geotriggering is called, and repeats when the rule download time interval is reached or significant distance has been travelled.
 *
 * This is a value that you set when creating the Application in the Canvas web-interface, and determines how often the Zone data will be refreshed on the device.
 *
 * @param zoneInfos A collection of `BDZoneInfo` objects, corresponding to the Zones you created for this application, in the <b>Canvas</b> web-interface.
 */
- (void)onZoneInfoUpdate: (nonnull NSSet<BDZoneInfo *> *)zoneInfos;

/**
 * Implement this method to provide your own implementation when device enters a Zone.
 *
 * @param enterEvent Contains zone entry event information, please refer to `BDZoneEntryEvent` for more information.
 */
- (void)didEnterZone: (nonnull BDZoneEntryEvent *) enterEvent;

/**
 * Implement this method to provide your own implementation when device exits a Zone.
 *
 * @param exitEvent Contains zone exit event information, please refer to `BDZoneExitEvent` for more information.
 */
- (void)didExitZone: (nonnull BDZoneExitEvent *) exitEvent;

@end
