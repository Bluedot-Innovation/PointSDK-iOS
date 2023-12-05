//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

@import Foundation;

@class BDGeometry;

///
/// Objects having an inherent ``BDGeometry`` "geometry".
///
@protocol BDPSpatialObject <NSObject>

/**
  @return The geometry inherent to this object.
 */
- (BDGeometry *)geometry;

@end

