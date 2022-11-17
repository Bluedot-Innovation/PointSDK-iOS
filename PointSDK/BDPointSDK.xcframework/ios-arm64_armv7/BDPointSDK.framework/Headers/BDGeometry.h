//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import "BDPGeometry.h"
#import "BDPJSONSerializable.h"

extern const BDGeometryType BDGeometryTypeBoundingBox;
extern const BDGeometryType BDGeometryTypeCircle;
extern const BDGeometryType BDGeometryTypeLineString;
extern const BDGeometryType BDGeometryTypePoint;
extern const BDGeometryType BDGeometryTypePolygon;

/**
  @brief Base class for all geometries.

  <p>Concrete geometries include @ref BDPoint "points", @ref BDBoundingBox "boxes", @ref BDCircle "circles", @ref BDLineString "line-strings" and @ref BDPolygon "polygons".</p>
  <p>A @ref BDGeometry "geometry", in this context, represents an area on the surface of the Earth, expressed in latitude and longitude coordinates.</p>

  @copyright Bluedot Innovation
*/
@interface BDGeometry : NSObject <BDPGeometry, BDPJSONSerializable, BDPJSONDeserializable>

@end
