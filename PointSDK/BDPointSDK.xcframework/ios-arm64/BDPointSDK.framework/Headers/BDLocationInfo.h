//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDGeospatialUnits.h"

/**
 * Information about a location update.
 */
@interface BDLocationInfo : NSObject

/**
 * The time at which this location was determined.
 */
@property (copy,readonly) NSDate *timestamp;

/** 
 * The latitude at which this location was determined.
 */
@property (readonly) BDLocationDegrees latitude;

/** 
 * The longitude at which this location was determined.
 */
@property (readonly) BDLocationDegrees longitude;

/**
 * The bearing of the device at the latitude and longitude of the location.
 */
@property (readonly) BDLocationDirection bearing;

/**
 * The speed of the device at the latitude and longitude of the location.
 */
@property (readonly) BDLocationSpeed speed;

@end

