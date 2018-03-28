//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "BDGeometry.h"
#import "BDGeospatialUnits.h"

#define BDPointCoordinateFormat @"%f°"

/**
  @brief A geographic point expressed in latitude and longitude coordinates.
*/
@interface BDPoint : BDGeometry <NSCopying>

/**
  Convenience constructor to create a @ref BDPointSDK "point" with a longitude and latitude, in degrees.
  @param longitude The longitude in degrees.  Values should be in the range <b>-180 < 0 <= 180</b>.
  @param latitude The latitude in degrees.  Values should be in the range <b>-90 < 0 <= 90</b>.
*/
+ (instancetype)pointWithLongitude: (BDLocationDegrees)longitude
                          latitude: (BDLocationDegrees)latitude;

/**
  Initializes a point with values for for longitude and latitude, in degrees.
  @param longitude The longitude in degrees.  Values should be in the range <b>-180 < 0 <= 180</b>.
  @param latitude The latitude in degrees.  Values should be in the range <b>-90 < 0 <= 90</b>.
 */
- (instancetype)initWithLongitude: (BDLocationDegrees)longitude
                         latitude: (BDLocationDegrees)latitude;

/**
  Initializes a point with longitude and latitude in degrees.
  @param coordinate The coordinate as a Core Location structure.
 */
- (instancetype)initWithCoordinate: (BDLocationCoordinate2D)coordinate;

/**
  @returns a string representation of this points' degrees latitude, e.g. "12.34°"
 */
- (NSString *)latitudeString;

/**
  @returns a string representation of this points' degrees longitude, e.g. "359.99°"
 */
- (NSString *)longitudeString;

/**
  The longitudinal component of this points location, in the range <b>-180 < 0 <= 180 degrees</b>.
 */
@property (nonatomic) BDLocationDegrees  longitude;

/**
  The latitudinal component of this points location, in the range <b>-90 < 0 <= 90 degrees</b>.
 */
@property (nonatomic) BDLocationDegrees  latitude;

/**
  This points location, expressed as a <a href="https://developer.apple.com/library/prerelease/ios/documentation/CoreLocation/Reference/CoreLocationDataTypesRef/index.html#//apple_ref/c/tdef/BDLocationCoordinate2D">BDLocationCoordinate2D</a> structure.
 */
@property (nonatomic,readonly) BDLocationCoordinate2D  coordinate;

/**
  @returns A <a href="https://developer.apple.com/library/prerelease/ios/documentation/GraphicsImaging/Reference/CGGeometry/index.html#//apple_ref/c/tdef/CGPoint">CGPoint</a> with longitude/latitude in degrees for the x/y coordinates.
 */
-(CGPoint)cgPoint;

- (BOOL)isEqual: (id)other;
- (BOOL)isEqualToPoint: (BDPoint *)point;
- (NSUInteger)hash;

/**
* @returns YES if the point is at 0 degrees latitude and longitude.  NO otherwise.
*/
- (BOOL)isOrigin;

@end

