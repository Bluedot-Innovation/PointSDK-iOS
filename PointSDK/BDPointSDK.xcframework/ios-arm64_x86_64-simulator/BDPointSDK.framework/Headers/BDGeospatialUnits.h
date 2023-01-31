//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>


typedef CLLocationDegrees      BDLocationDegrees;
typedef CLLocationDistance     BDLocationDistance;
typedef CLLocationAccuracy     BDLocationAccuracy;
typedef CLLocationSpeed        BDLocationSpeed;
typedef CLLocationDirection    BDLocationDirection;

/**
@brief Alias of CLLocationCoordinate2D
*/
typedef CLLocationCoordinate2D BDLocationCoordinate2D;

#define BDLocationCoordinate2DMake CLLocationCoordinate2DMake

#define kBDLocationAccuracyBestForNavigation kCLLocationAccuracyBestForNavigation
#define kBDLocationAccuracyBest              kCLLocationAccuracyBest
#define kBDLocationAccuracyNearestTenMeters  kCLLocationAccuracyNearestTenMeters
#define kBDLocationAccuracyHundredMeters     kCLLocationAccuracyHundredMeters
#define kBDLocationAccuracyKilometer         kCLLocationAccuracyKilometer
#define kBDLocationAccuracyThreeKilometers   kCLLocationAccuracyThreeKilometers


#define kBDLocationAccuracyGPS       kBDLocationAccuracyNearestTenMeters
#define kBDLocationAccuracyWifi      kBDLocationAccuracyHundredMeters
#define kBDLocationAccuracyCellTower kBDLocationAccuracyThreeKilometers

#define kBDLocationInvalidDegrees   -1.0
#define kBDLocationInvalidDistance  -1.0
#define kBDLocationInvalidAccuracy   0.0
#define kBDLocationInvalidSpeed     -1.0
#define kBDLocationInvalidDirection -1.0
