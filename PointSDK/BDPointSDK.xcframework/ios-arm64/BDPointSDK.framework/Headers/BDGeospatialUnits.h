//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

/// Alias for ``CLLocationDegrees``
typedef CLLocationDegrees      BDLocationDegrees;

/// Alias for ``CLLocationDistance``
typedef CLLocationDistance     BDLocationDistance;

/// Alias for ``CLLocationAccuracy``
typedef CLLocationAccuracy     BDLocationAccuracy;

/// Alias for ``CLLocationSpeed``
typedef CLLocationSpeed        BDLocationSpeed;

/// Alias for ``CLLocationDirection``
typedef CLLocationDirection    BDLocationDirection;

/// Alias for ``CLLocationCoordinate2D``
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
