//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "BDGeometry.h"

@class BDPoint;

/**
  @brief A circular region on the Earth's surface, defined by a center @ref BDPoint "point" and a radius, in meters.

  \image html circle.gif

  @copyright Bluedot Innovation
*/
@interface BDCircle : BDGeometry

/**
 * Center of this Circle as a @ref BDPoint in latitude/longitude coordinates.
 */
@property (nonatomic) BDPoint  *center;

/***
 * Radius in meters.
 */
@property (nonatomic) BDLocationDistance  radius;

- (instancetype)initWithCenter: (BDPoint *)center
                        radius: (BDLocationDistance)radius;

+ (BDCircle*)circleWithCenter: (BDPoint *)center
                       radius: (BDLocationDistance)radius;

- (BOOL)isEqual: (id)other;
- (BOOL)isEqualToCircle: (BDCircle *)circle;
- (NSUInteger)hash;

@end

