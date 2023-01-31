//
//  BDZoneEntryEvent.h
//  BDPointSDK
//
//  Created by Duncan Lau on 3/8/20.
//  Copyright © 2020 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>


@class BDFenceInfo;
@class BDZoneInfo;
@class BDLocationInfo;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

/**
 * Contains information about a Zone Entry Event
 *
 * A <b>BDZoneEntryEvent</b> objects will be delivered to your application's `BDPGeoTriggeringEventDelegate` when Geotriggering event occurs (for e.g. fence entry and exit events).
 *
*/
@interface BDZoneEntryEvent : NSObject

/**
 * The Fence that was entered into
*/
@property (copy,readonly) BDFenceInfo * _Nonnull fence;

/**
 * The Zone that was entered into
*/
@property (copy,readonly) BDZoneInfo * _Nonnull zone;

/**
 * Location of the Zone Entry event
*/
@property (copy,readonly) BDLocationInfo * _Nonnull location;

/**
 * Indicates whether the Zone is tracking for exit event
*/
@property (readonly) BOOL isExitEnabled;

/**
 * Custom data for the entry event
 */
@property (readonly) NSDictionary* customData;

@end

#pragma clang diagnostic pop
