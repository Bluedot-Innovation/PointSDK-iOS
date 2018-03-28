//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import "BDGeometry.h"
#import "BDPolygonal.h"

/**
  @brief Arbitrary region on the Earth's surface, comprised of two or more @ref BDPoint "points" connected by straight-line segments.

  @image html polygon.gif

  <p>Unlike a @ref BDLineString "line-string" this geometry forms an enclosed area.</p>

  @copyright Bluedot Innovation
*/
@interface BDPolygon : BDPolygonal

/**
  Convenience method to create a BDPolygon with an array of @ref BDPointSDK vertices.

  Vertices is an array containing 1 or more BDPointSDK objects describing the intended polygon.
  If the array is empty, or if the array contains any non-BDPointSDK elements, an <b>NSInvalidArgumentException</b> will be thrown.
  Copy is if YES, then the BDPointSDK elements will be copied before inclusion in the new BDPolygon.
 */
+ (instancetype)polygonWithVertices: (NSArray *)vertices
                               copy: (BOOL)copy;

/**
 * Convenience method to construct an ad-hoc polygon using variable length lat/long variable arguments.
 */
+ (instancetype)polygonWithLatLongCoordinates: (NSNumber *)scalar, ...;


@end
