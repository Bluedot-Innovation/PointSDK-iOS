//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BDGeometry.h"

/**
 * Base-class for ``BDGeometry`` "geometries" defined by an ordered series of ``BDPoint`` "points".
 *
 * <p>``BDPolygonal`` is an abstract type and cannot be instantiated directly.</p>
 * <p>Instead, instantiate one of its concrete sub-classes.</p>
 *
 * @see details in ``BDPolygon``
 * @see details in ``BDLineString``
*/
@interface BDPolygonal : BDGeometry

/**
  @returns The number of vertices (``BDPoint`` "point"s) that define this polygonal geometry.
*/
- (NSUInteger)vertexCount;

/**
  Convenience method to add a new vertex to this BDPolygons vertices array.
*/
- (void)addVertex: (BDPoint *)vertex;

/**
  An ordered series of ``BDPoint`` "point" vertices which, when joined by straight-line segments, describe this polygonal geometry.
*/
@property (nonatomic) NSMutableArray  *vertices;

/**
* @returns YES if this geometry is closed and has an area.  NO if the geometry is open-ended and has no area.
*/
-(BOOL)isClosed;

@end
