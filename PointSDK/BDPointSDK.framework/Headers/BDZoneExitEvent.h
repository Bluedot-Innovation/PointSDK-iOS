//
//  BDZoneExitEvent.h
//  BDPointSDK
//
//  Created by Duncan Lau on 3/8/20.
//  Copyright © 2020 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BDFenceInfo;
@class BDZoneInfo;

/**
 * Contains information about a Zone Exit Event
 *
 * A <b>BDZoneExitEvent</b> objects will be delivered to your application's `BDPGeoTriggeringEventDelegate` when Geotriggering event occurs (for e.g. fence entry and exit events).
 *
*/
@interface BDZoneExitEvent : NSObject

/**
 * The Fence that was entered into
*/
@property (copy,readonly) BDFenceInfo * _Nonnull fence;

/**
 * The Zone that was entered into
*/
@property (copy,readonly) BDZoneInfo * _Nonnull zone;

/**
 * The date and time of the Zone exit event.
*/
@property (copy,readonly) NSDate * _Nonnull date;

/**
 * The dwell time in minutes of the device within the fence.
*/
@property (readonly) NSUInteger duration;

@end
