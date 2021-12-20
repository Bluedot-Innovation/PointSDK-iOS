//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BDPDeepCopy.h"
#import "BDGeospatialUnits.h"

@class BDGeometry;
@class BDPoint;
@class BDBoundingBox;

/**
  @brief Geometrical methods required for implementation of a concrete geometry class.
  @copyright Bluedot Innovation
*/
@protocol BDPGeometry <BDPDeepCopy>

/**
  <p>Sometimes referred to as 'hit test' or '<a href="http://en.wikipedia.org/wiki/Point_in_polygon">Point in polygon test</a>',
  this method determines whether the given @ref BDPoint "point" falls on, or inside the bounds of this geometry.</p>

  @returns YES if the point falls on or inside the bounds, NO if the point falls outside the bounds
 */
- (BOOL)intersects: (BDGeometry *)geometry;

/**
 * <p>Currently, only Circles may receive this message; other shapes will throw an assertion error in DEBUG or return NO in RELEASE.</p>
  @returns YES if this shape fully encloses the specified shape, NO otherwise.
 */
- (BOOL)isEnclosedBy:(BDGeometry *)geometry;

/**
  <p>Calculates the minimum @ref BDBoundingBox "bounding-box" that encloses this geometry.</p>
  <p>Notably, for @ref BDBoundingBox instances, this will simply return a `self` reference.</p>
  <p>For @ref BDPoint instances, this will return a zero-sized box positioned at the point.</p>

  @returns the minimum @ref BDBoundingBox "bounding-box" that encloses this geometry.
 */
-(BDBoundingBox*)boundingBox;

/**
  @returns The centre of a geometrical shape.
 */
-(BDPoint*)centroid;

/**
  @returns the distance to another geometric shape.
 */
-(BDLocationDistance)distanceTo:(BDGeometry *)geometry;

@end
