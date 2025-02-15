//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "BDGeospatialUnits.h"
#import "BDPDeepCopy.h"

@class BDPoint;

@class CLLocation;

/**
*  Represents a recorded, geographic location; combining a geographic ``BDPointSDK`` "point" with an altitude, as well as a known
*  accuracy in metres.
*/
@interface BDLocation : NSObject <BDPDeepCopy>

/**
 *  Initialisation methods for to creation a location.
 */
- (instancetype)initWithCLLocation: (CLLocation*)coreLocation;

/**
 *  Initialisation methods for to creation a location.
 */
- (instancetype)initWithLatitude: (BDLocationDegrees)latitude
                       longitude: (BDLocationDegrees)longitude
                        altitude: (BDLocationDistance)altitude
                        accuracy: (BDLocationAccuracy)accuracy
                altitudeAccuracy: (BDLocationAccuracy)altitudeAccuracy
                           speed: (BDLocationSpeed)speed
                         bearing: (BDLocationDirection)bearing;

/**
 * The accuracy, in metres, to which this location is known.  Sometimes referred to as the 'horizontal accuracy' or just 'error'.
 */
@property (nonatomic) BDLocationAccuracy accuracy;

/**
 * The altitude accuracy, in metres, to which this location is known.  Sometimes referred to as the 'vertical accuracy' or just 'error'.
 */
@property (nonatomic) BDLocationAccuracy altitudeAccuracy;

/**
 * The geographic location of this location, over the surface of the earth, independent of it's altitude.
 */
@property (nonatomic) BDPoint *point;

/**
 * The altitude of this geographic location in metres.
 */
@property (nonatomic) BDLocationDistance altitude;

/**
 * The speed of the device at the point of the location.
 */
@property (nonatomic) BDLocationSpeed speed;

/**
 * The bearing of the device at the point of the location.
 */
@property (nonatomic) BDLocationDirection bearing;

/**
 * The location method provider of the device at the point of the location
 */
@property (nonatomic, readonly) NSString *provider;

/**
 * GPS time of the location
 */
@property (nonatomic) NSDate *timestamp;

/**
 * Publicly available methods for evaluating locations.
 */
- (BOOL)isEqualToLocation: (BDLocation *)location;

@end

