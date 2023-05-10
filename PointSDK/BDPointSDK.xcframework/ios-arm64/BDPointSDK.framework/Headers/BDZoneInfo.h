//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
 
@class BDFenceInfo, Destination;

/**
 Contains information about a Zone, including the set of `BDFenceInfo` "fences" that comprise it.

 A set of `BDZoneInfo` objects will be delivered to your application's `BDPLocationDelegate` at
 the time of their download from the Bluedot Point web-service.
 
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
 * Whether CheckOuts should be generated for any CheckIns to this Zone.
*/
@property (readonly) BOOL checkOut;

/**
 * Custom Data included in this zone
 */
@property (copy, readonly) NSDictionary<NSString *, NSString *> *customData;

/**
 * The `Destination` (aka Store) that this zone is linked with.
 */
@property (readonly, nullable) Destination *destination;

@end

NS_ASSUME_NONNULL_END
