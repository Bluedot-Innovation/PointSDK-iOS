//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import "BDPGeometry.h"
#import "BDPJSONSerializable.h"

/// GeometryType: BoundingBox. See ``BDBoundingBox``.
extern const BDGeometryType BDGeometryTypeBoundingBox;
/// GeometryType: Circle. See ``BDCircle``.
extern const BDGeometryType BDGeometryTypeCircle;
/// GeometryType: LineString. See ``BDLineString``.
extern const BDGeometryType BDGeometryTypeLineString;
/// GeometryType: Point. See ``BDPoint``.
extern const BDGeometryType BDGeometryTypePoint;
/// GeometryType: Polygon. See ``BDPolygon``.
extern const BDGeometryType BDGeometryTypePolygon;

/**
 * Base class for all geometries.
 *
 * Concrete geometries include ``BDPoint`` "points", ``BDBoundingBox`` "boxes", ``BDCircle`` "circles", ``BDLineString`` "line-strings" and ``BDPolygon`` "polygons".
 * A BDGeometry "geometry", in this context, represents an area on the surface of the Earth, expressed in latitude and longitude coordinates.
*/
@interface BDGeometry : NSObject <BDPGeometry, BDPJSONSerializable, BDPJSONDeserializable>

@end
