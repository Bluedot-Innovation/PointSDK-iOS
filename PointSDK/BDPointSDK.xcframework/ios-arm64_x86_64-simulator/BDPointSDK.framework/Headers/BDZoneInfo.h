//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BDFenceInfo;
@class BDBeaconInfo;

/**
 Contains information about a Zone, including the set of `BDFenceInfo` "fences" that comprise it.

 A set of `BDZoneInfo` objects will be delivered to your application's `BDPLocationDelegate` at
 the time of their download from the Bluedot Point web-service.
 
 This usually occurs immediately after the authentication process is complete.
*/
@interface BDZoneInfo : NSObject

/**
 * The name of this Zone that was entered into Canvas
*/
@property (copy,readonly) NSString *name;

/**
 * The description of this Zone that was entered into Canvas
*/
@property (copy,readonly) NSString *description;

/**
 * A unique <a href="http://en.wikipedia.org/wiki/Globally_unique_identifier">GUID</a> to identify this Zone by.
 *
 * This is permanent and may be used to identify specific Zones created in the Canvas web-interface,
 from your client application.
*/
@property (copy,readonly) NSString  *ID;

/**
 * The set of `BDFenceInfo` fences included in this Zone.
*/
@property (copy,readonly) NSSet<BDFenceInfo *>  *fences;

/**
 * The set of `BDBeaconInfo` beacons included in this Zone.
*/
@property (copy,readonly) NSSet<BDBeaconInfo *>  *beacons
__attribute__((deprecated("First deprecated in 15.4.0 - It will be removed in a future version")));

/**
 * Whether CheckOuts should be generated for any CheckIns to this Zone.
*/
@property (readonly) BOOL checkOut;

/**
 * Custom Data included in this zone
 */
@property (copy, readonly) NSDictionary<NSString *, NSString *> *customData;

- (BOOL)isEqual:(id)other;

- (BOOL)isEqualToInfo:(BDZoneInfo *)info;

- (NSUInteger)hash;

@end
