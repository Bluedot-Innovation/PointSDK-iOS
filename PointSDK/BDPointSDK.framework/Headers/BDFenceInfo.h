//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BDPSpatialObjectInfo.h"

@class BDLocation;
@class BDGeometry;

/// Information about a geofence, as defined in Canvas.
@interface BDFenceInfo : NSObject <BDPSpatialObjectInfo, NSCoding>

/// The name of this Fence that was entered into Canvas
@property (copy,readonly) NSString  *name;

/// The description of this Fence that was entered into Canvas
@property (copy,readonly) NSString *description;

/// The description of this ID of the fence
@property (copy,readonly) NSString *ID;

/// The geometry of this Fence that was defined in Canvas
/// This property conforms the spatial aspect of `BDBeaconInfo` and `BDFenceInfo` to a common interface  `BDPSpatialObjectInfo`.
@property (readonly) BDGeometry *geometry;

@end
