//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "BDGeometry.h"
#import "BDGeospatialUnits.h"

#define BDPointCoordinateFormat @"%f°"

/**
  A geographic point expressed in latitude and longitude coordinates.
*/
@interface BDPoint : BDGeometry <NSCopying, NSSecureCoding>

/**
  Convenience constructor to create a  ``BDPoint`` "point" with a longitude and latitude, in degrees.
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
  This points location, expressed as a <a href="https://developer.apple.com/documentation/corelocation/cllocationcoordinate2d">BDLocationCoordinate2D</a> structure.
 */
@property (nonatomic,readonly) BDLocationCoordinate2D  coordinate;

/**
  @return A <a href="https://developer.apple.com/documentation/corefoundation/cgpoint/">CGPoint</a> with longitude/latitude in degrees for the x/y coordinates.
 */
-(CGPoint)cgPoint;

/**
 * @return YES if current point and the passing point have the same latitude and longitude.
 */
- (BOOL)isEqualToPoint:(BDPoint *)point;

/**
* @returns YES if the point is at 0 degrees latitude and longitude.  NO otherwise.
*/
- (BOOL)isOrigin;

@end

