//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "BDPSpatialObjectInfo.h"

/// Information about a BLE Beacon, as defined in Canvas.
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")))
@interface BDBeaconInfo : NSObject <BDPSpatialObjectInfo, NSCoding>

/// The name of this Beacon that was entered into Canvas
@property (copy,readonly) NSString *name
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/// The description of this Beacon that was entered into Canvas
@property (copy,readonly) NSString *description
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/// The ID of this Beacon
@property (copy,readonly) NSString *ID
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/// The proximityUUID of this Beacon, as entered into Canvas
@property (copy,readonly) NSString *proximityUuid
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/// The major identifier of this Beacon, as entered into Canvas
@property (readonly) NSUInteger major
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/// The minor identifier of this Beacon, as entered into Canvas
@property (readonly) NSUInteger minor
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/// The approximate location of this Beacon, as entered into Canvas, or NULL if this Beacon has no fixed location.
@property (readonly) CLLocationCoordinate2D location
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/// Returns a BDPoint representation of the approximate location of this Beacon, as entered into Canvas, or nil if this Beacon has no fixed location.
/// This property conforms the spatial aspect of `BDBeaconInfo` and `BDFenceInfo` to a common interface  `BDPSpatialObjectInfo`.
@property (readonly) BDGeometry *geometry
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

@end
