//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@class MKOverlayRenderer;

/**
 * @brief Produces MapKit overlay renderers for @ref BDFenceInfo and @ref BDBeaconInfo overlays.
 *
 * <p>General workflow for using this class is shown in the
 * <a href="https://github.com/Bluedot-Innovation/PointSDK-SampleApp-iOS-ObjC/blob/1.4/BDPoint/EXZoneMapViewController.m#L238-L257">
 * BDPoint example application source-code
 * </a>
 * on GitHub.
 * </p>
 */
@interface BDPointOverlayRendererFactory : NSObject

+ (instancetype)sharedInstance;

/**
 * Produces a renderer for MKMapView overlays that were added by the methods in @ref MKMapView(BDPointSDK).
 * General workflow for acquiring and using this
 */
- (MKOverlayRenderer *)rendererForOverlay:(id<MKOverlay>)pointOverlay;

- (BOOL)isPointOverlay:(id<MKOverlay>)overlay;

@end
