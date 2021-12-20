//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@class BDBeaconInfo;
@class BDFenceInfo;
@class BDZoneInfo;


@protocol BDPSpatialObjectInfo;

@interface MKMapView (BDPointSDK)

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (void)addOverlaysForBeacon:(BDBeaconInfo *)beaconInfo
                   iconImage:(UIImage *)icon
                   iconScale:(CGFloat)scale
    __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (void)addOverlaysForFence:(BDFenceInfo *)fenceInfo __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (void)addOverlaysForZone:(BDZoneInfo *)zoneInfo
       withBeaconIconImage:(UIImage *)beaconIconImage
           beaconIconScale:(CGFloat)beaconIconScale
   __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (void)addOverlaysForZones:(NSSet *)zoneInfos
        withBeaconIconImage:(UIImage *)beaconIconImage
            beaconIconScale:(CGFloat)beaconIconScale
    __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));


/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (void)removeAllSpatialObjectOverlays __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (void)removeOverlaysForSpatialObjectInfo:(id <BDPSpatialObjectInfo>)spatialObject __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (void)setTintColor:(UIColor *)tintColor
    forSpatialObject:(id<BDPSpatialObjectInfo>)spatialObjectInfo __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));


/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (MKMapRect)mapRectForSpatialObject:(id<BDPSpatialObjectInfo>)spatialObjectInfo __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (MKMapRect)mapRectForZone:(BDZoneInfo *)zone __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

/**
 * @deprecated This method has been deprecated since version 1.13. Please implement map overlays in your project.
 */
- (MKMapRect)mapRectForZones:(NSSet *)zones __attribute__((deprecated("MKMapView (BDPointSDK) has been deprecated since version 1.13. Please implement map overlays in your project.")));

@end
