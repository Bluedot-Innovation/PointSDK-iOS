//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDPolygonal.h"

@class BDPoint;

/**
  @brief Open-ended geometry consisting of two or more @ref BDPoint "points" connected by straight-line segments.

  Unlike a @ref BDPolygon "polygon" this geometry is open-ended and has no area.

  When used as a @ref BDFence "fence" geometry, @ref BDLineString is typically used to represent a geographic boundary or
  check-point along a road or other travel path.

  @copyright Bluedot Innovation
*/
@interface BDLineString : BDPolygonal

+ (instancetype)lineStringWithVertices:(NSArray*)vertices copy:(BOOL)copy;

+ (instancetype)lineWithStart:(BDPoint *)start
                          end:(BDPoint *)end;

- (instancetype)initWithVertices:(NSArray*)vertices copy:(BOOL)copy;

- (instancetype)initWithStart:(BDPoint *)start
                          end:(BDPoint *)end;

@property (nonatomic) BDPoint *start;
@property (nonatomic) BDPoint *end;

@end
