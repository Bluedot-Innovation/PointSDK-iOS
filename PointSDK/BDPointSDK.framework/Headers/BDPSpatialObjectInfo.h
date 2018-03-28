//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BDPSpatialObject.h"

@class BDGeometry;

@protocol BDPSpatialObjectInfo <BDPSpatialObject>

/** The name of this object that was entered into Point Access */
@property (copy,readonly) NSString  *name;

/** The description of this object that was entered into Point Access */
@property (copy,readonly) NSString *description;

/** The description of this ID of the object */
@property (copy,readonly) NSString *ID;

/** The geometry of this object that was defined in Point Access */
@property (readonly) BDGeometry *geometry;

@end
