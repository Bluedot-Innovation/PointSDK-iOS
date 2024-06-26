//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import <MapKit/MapKit.h>
#import "BDGeometry.h"
#import "BDPValidatable.h"

@class BDPoint;

/**
 * A rectangular coordinate region on the Earth's surface, defined by two latitude / longitude corner ``BDPoint`` "points".
*/
@interface BDBoundingBox : BDGeometry <NSCopying, BDPValidatable, NSSecureCoding>

/**
 * Initializes a BDBoundingBox with individual values for the four bounding edges, in degrees.
 */
- (instancetype)initWithNorth: (BDLocationDegrees)north
                         west: (BDLocationDegrees)west
                        south: (BDLocationDegrees)south
                         east: (BDLocationDegrees)east;

/**
 * Initializes a BDBoundingBox with ``BDPoint`` values for two of the bounding corners.
 */
- (instancetype)initWithNorthEast: (BDPoint *)northEast
                        southWest: (BDPoint*)southWest;

/**
 * Initializes a BDBoundingBox using a <a href="https://developer.apple.com/library/ios/documentation/MapKit/Reference/MapKitDataTypesReference/Reference/reference.html">MapKit coordinate region</a>.
 */
- (instancetype)initWithCoordinateRegion: (MKCoordinateRegion)region;

/**
 * @returns the equivalent <a href="https://developer.apple.com/library/ios/documentation/MapKit/Reference/MapKitDataTypesReference/Reference/reference.html">MapKit coordinate region</a> representation of this rectangular region.
 */
- (MKCoordinateRegion)coordinateRegion;

/**
 * @param west the longitudinal component of the South-West corner point of this rectangular region
 */
- (void)setWest: (BDLocationDegrees)west;

/**
 * @returns the longitudinal component of the South-West corner point of this rectangular region
 */
- (BDLocationDegrees)west;

/**
 * @param north the latitudinal component of the North-East corner point of this rectangular region
 */
- (void)setNorth: (BDLocationDegrees)north;

/**
 * Returns the latitudinal component of the North-East corner point of this rectangular region
 */
- (BDLocationDegrees)north;

/**
 * @param east the longitudinal component of the North-East corner point of this rectangular region
 */
- (void)setEast: (BDLocationDegrees)east;

/**
 * @returns the longitudinal component of the North-East corner point of this rectangular region
 */
- (BDLocationDegrees)east;

/**
 * Sets the latitudinal component of the South-West corner point of this rectangular region
 */
- (void)setSouth: (BDLocationDegrees)south;

/**
 * @returns the latitudinal component of the South-West corner point of this rectangular region
 */
- (BDLocationDegrees)south;

/**
 * @returns the absolute difference between the East and West longitudes, in degrees.
 */
- (BDLocationDegrees)longitudeSpan;

/**
 * @returns the absolute difference between the North and South latitudes, in degrees.
 */
- (BDLocationDegrees)latitudeSpan;

/**
 * The North-East corner of this rectangular region
 */
@property (nonatomic) BDPoint  *northEast;

/**
 * The South-West corner of this rectangular region
 */
@property (nonatomic) BDPoint  *southWest;

/**
* @returns An array of the corner ``BDPoint`` "points" of this ``BDBoundingBox``, ordered: North, East, South, West.
*/
- (NSArray *)vertices;

@end

