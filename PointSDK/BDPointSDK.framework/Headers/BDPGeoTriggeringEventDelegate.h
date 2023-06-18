//
//  Created by Bluedot Innovation
//  Copyright © 2020 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GeoTriggerEvent;

/**
  Defines the call-backs which Point SDK makes to inform the Application of Geotriggering events.

  Assign your own implementation of this protocol to the `BDLocationManager.geoTriggeringEventDelegate` property of the
  shared ``BDLocationManager`` instance, to handle Geotriggering related callbacks.
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
 * @note To access detail of the latest ``BDZoneInfo`` downloaded to the SDK, access ``BDLocationManager\zoneInfos``
 */
- (void)didUpdateZoneInfo;

/**
 * Implement this method to provide your own implementation when device enters a Zone.
 *
 * @param enterEvent Contains zone entry event information. See ``GeoTriggerEvent`` for more information.
 */
- (void)didEnterZone:(nonnull GeoTriggerEvent *)enterEvent;

/**
 * Implement this method to provide your own implementation when device exits a Zone.
 *
 * @param exitEvent Contains zone exit event information. See `GeoTriggerEvent` for more information.
 */
- (void)didExitZone:(nonnull GeoTriggerEvent *)exitEvent;

@end
