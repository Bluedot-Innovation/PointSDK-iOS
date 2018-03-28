//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "BDPSpatialObjectInfo.h"

/**
@brief Information about a BLE Beacon, as defined in Point Access.

@copyright Bluedot Innovation
*/
@interface BDBeaconInfo : NSObject <BDPSpatialObjectInfo>

/**
 * The name of this Beacon that was entered into Point Access
 */
@property (copy,readonly) NSString *name;

/**
 * The description of this Beacon that was entered into Point Access
 */
@property (copy,readonly) NSString *description;

/**
 * The ID of this Beacon
 */
@property (copy,readonly) NSString *ID;

/**
 * The proximityUUID of this Beacon, as entered into Point Access
 */
@property (copy,readonly) NSString *proximityUuid;

/**
 * The major identifier of this Beacon, as entered into Point Access
 */
@property (readonly) NSUInteger major;

/**
 * The minor identifier of this Beacon, as entered into Point Access
 */
@property (readonly) NSUInteger minor;

/**
 * The approximate location of this Beacon, as entered into Point Access, or NULL if this Beacon has no fixed location.
 */
@property (readonly) CLLocationCoordinate2D location;

/**
 * Returns a BDPoint representation of the approximate location of this Beacon, as entered into Point Access,
 * or nil if this Beacon has no fixed location.
 * This property conforms the spatial aspect of BDBeaconInfo and BDFenceInfo to a common interface BDPSpatialInfo.
 */
@property (readonly) BDGeometry *geometry;

@end
