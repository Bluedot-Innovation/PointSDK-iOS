//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BDPSpatialObjectInfo.h"

@class BDLocation;
@class BDGeometry;

/**
@brief Information about a geofence, as defined in Point Access.

@copyright Bluedot Innovation
*/
@interface BDFenceInfo : NSObject <BDPSpatialObjectInfo>

/** The name of this Fence that was entered into Point Access */
@property (copy,readonly) NSString  *name;

/** The description of this Fence that was entered into Point Access */
@property (copy,readonly) NSString *description;

/** The description of this ID of the fence */
@property (copy,readonly) NSString *ID;

/** The geometry of this Fence that was defined in Point Access */
@property (readonly) BDGeometry *geometry;

@end
