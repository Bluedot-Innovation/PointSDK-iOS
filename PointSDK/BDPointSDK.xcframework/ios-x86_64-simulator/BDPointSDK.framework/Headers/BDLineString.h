//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDPolygonal.h"

@class BDPoint;

/**
 * Open-ended geometry consisting of two or more ``BDPoint`` "points" connected by straight-line segments.
 *
 * Unlike a ``BDPolygon`` "polygon" this geometry is open-ended and has no area.
 * When used as a ``BDFence`` "fence" geometry, ``BDLineString`` is typically used to represent a geographic boundary or
 * check-point along a road or other travel path.
 */
@interface BDLineString : BDPolygonal<NSSecureCoding>

/**
 * Convenience init method with a list of ``BDPoint`` vertices
 */
+ (instancetype)lineStringWithVertices:(NSArray*)vertices copy:(BOOL)copy;

/**
 * Convenience class method to init a ``BDLineString`` with a `start` ``BDPoint`` and an `end` ``BDPoint``
 */
+ (instancetype)lineWithStart:(BDPoint *)start
                          end:(BDPoint *)end;

/**
 * Convenience init method with a list of  ``BDPoint``  vertices
 */
- (instancetype)initWithVertices:(NSArray*)vertices copy:(BOOL)copy;

/**
 * Convenience method to init a ``BDLineString`` with a `start` ``BDPoint`` and an `end` ``BDPoint``
 */
- (instancetype)initWithStart:(BDPoint *)start
                          end:(BDPoint *)end;

/// Quick access to the start ``BDPoint`` of the LineString
@property (nonatomic) BDPoint *start;
/// Quick access to the end ``BDPoint`` of the LineString
@property (nonatomic) BDPoint *end;

@end
