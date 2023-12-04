//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "BDGeometry.h"

@class BDPoint;

/**
  A circular region on the Earth's surface, defined by a center ``BDPoint`` "point" and a radius, in meters.
*/
@interface BDCircle : BDGeometry<NSSecureCoding>

/**
 * Center of this Circle as a ``BDPoint`` in latitude/longitude coordinates.
 */
@property (nonatomic) BDPoint  *center;

/***
 * Radius in meters.
 */
@property (nonatomic) BDLocationDistance  radius;

/**
 * Convenience init method with a center point ``BDPoint`` and a radius
 */
- (instancetype)initWithCenter: (BDPoint *)center
                        radius: (BDLocationDistance)radius;

/**
 * Convenience class method to init a circle with a center point ``BDPoint`` and a radius
 */
+ (BDCircle*)circleWithCenter: (BDPoint *)center
                       radius: (BDLocationDistance)radius;

/**
 * Compare the current circle with the passing in `circle`.
 */
- (BOOL)isEqualToCircle: (BDCircle *)circle;

@end

